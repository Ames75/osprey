
/*
 * Copyright (C) 2008-2011 Advanced Micro Devices, Inc.  All Rights Reserved.
 */

/*
 *  Copyright (C) 2007, 2008 PathScale, LLC.  All Rights Reserved.
 */

/*
 *  Copyright (C) 2006, 2007.  QLogic Corporation. All Rights Reserved.
 */

/*
 * Copyright 2003, 2004, 2005, 2006 PathScale, Inc.  All Rights Reserved.
 */

/*

  Copyright (C) 2000, 2001 Silicon Graphics, Inc.  All Rights Reserved.

  This program is free software; you can redistribute it and/or modify it
  under the terms of version 2 of the GNU General Public License as
  published by the Free Software Foundation.

  This program is distributed in the hope that it would be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

  Further, this software is distributed without any warranty that it is
  free of the rightful claim of any third person regarding infringement 
  or the like.  Any license provided herein, whether implied or 
  otherwise, applies only to this software file.  Patent licenses, if 
  any, provided herein do not apply to combinations of this program with 
  other software, or any other product whatsoever.  

  You should have received a copy of the GNU General Public License along
  with this program; if not, write the Free Software Foundation, Inc., 59
  Temple Place - Suite 330, Boston MA 02111-1307, USA.

  Contact information:  Silicon Graphics, Inc., 1600 Amphitheatre Pky,
  Mountain View, CA 94043, or:

  http://www.sgi.com

  For further information regarding this notice, see:

  http://oss.sgi.com/projects/GenInfo/NoticeExplan

*/

//
// 	LNO aggressive factorization (Loop Idiom Recognition and Optimization)
//      -----------------------------------------------------------------------
//
//
//      Identify the following loop idiom and remove redundant computations 
//      by hoisting them outside.
//         do i = lb, ub
//           do j=lb,ub
//           .
//           . { any number of such do-statements }
//             do n=lb,ub
//               array[i,j] = array[i,j] + <i,j invariant array expression 1> 
//                                              * <i,j variant array expression>
//                                       + <i,j invariant array expression 2> 
//                                              * <i,j variant array expression>
//             enddo
//           .
//         enddo
//      replace with
//          // partial array loop
//           .
//             do n=lb,ub
//           . { any number of such do-statements }
//               p_array[m1,n1,.. = p_array[m1,n1,.. 
//                                       + <i,j invariant array expression 1> 
//                                       + <i,j invariant array expression 2> 
//             enddo
//         .
//         do i = lb, ub
//           do j=lb,ub
//           .
//           .
//             do m1=lb,ub
//              do n1=lb,ub
//           .
//           .
//               array[i,j] = array[i,j] + p_array[m1,n1,...] 
//                                * <i,j variant array expression>
//
//      We use a option LNO:aggressive_invar_factor=[0,1] to control 
//      the optimization
//

#include "defs.h"
#include "glob.h"
#include "wn.h"
#include "wn_map.h"
#include "lwn_util.h"
#include "ff_utils.h"
#include "lnoutils.h"
#include "lnopt_main.h"
#include "opt_du.h"
#include "dep_graph.h"
#include "ir_reader.h"             // for fdump_tree
#include "const.h"
#include "snl_utils.h"
#include "wn_simp.h"

#define MAX_FACTORIZE_LOOP_DEPTH 10
#define GOOD_FACTORS 2

typedef STACK<WN*> STACK_OF_WN;
typedef STACK<SYMBOL> STACK_OF_SYMBOL;

static MEM_POOL AG_FACT_default_pool;	// private mem pool
static int partial_array_index=0;  
static BOOL pool_initialized = FALSE;

// External functions  used in this file.
extern ST* Create_Local_Array_ST(char* array_name, TY_IDX ty, INT num);
extern WN* WN_Array_Symbol(WN* wn_ref);
extern INT64 Iterations(WN* loop, MEM_POOL* pool);
extern void Delete_Def_Use(WN *wn_tree);
extern void Simd_Update_Loop_Info(WN *, WN *,DO_LOOP_INFO *, BOOL );
extern void Do_DU_Update(WN *);
extern void Initialize_Invar_Factorization();
extern void Finalize_Invar_Factorization();
extern BOOL Loop_Invariant_Access(WN* wn_array, const WN* loop);
extern INT Statement_Invariant_Factors(WN *stmt, WN *innerloop, bool aggressive);

/* 
 * function to print debug messages
 */
static void dump_verbose_msg(WN *stmt, const char *msg)
{
     if (LNO_Invar_Factor_Verbose && stmt && msg) {
        printf("%s at line (%d)\n", 
	       msg, Srcpos_To_Line(WN_Get_Linenum(stmt)));
     }
}
/*
 * function to create a partial array symbol with given dimension
 */
ST* Create_PartialArray_Symbol(TYPE_ID mtype, int num_dim)
{
  TY_IDX ty = Be_Type_Tbl(mtype); 
  char partial_array_sym[256];
  sprintf(partial_array_sym,"partial_array_%d", partial_array_index++);
  return Create_Local_Array_ST (partial_array_sym, ty, num_dim);
}

/*
 * function returns an array base to be used for array load and
 * array store statements.
 */
static WN* 
Create_Array_Base(ST* st_array,
                             TYPE_ID mtype,   
                             int num_indices,
                             int element_size,
                             WN *loops[])
{
  
  DU_MANAGER* du = Du_Mgr;
  TY_IDX ty = Be_Type_Tbl(mtype); 
  TY_IDX ty_ptr = Make_Pointer_Type(Be_Type_Tbl(mtype));
  TY_IDX arr_ty_ptr = Make_Pointer_Type(ST_type(st_array));
  TY_IDX ty_i8_ptr = Make_Pointer_Type(Be_Type_Tbl(MTYPE_I8));
  OPCODE op_lda = OPCODE_make_op(OPR_LDA, Pointer_type, MTYPE_V);
  WN* wn_lda = WN_CreateLda(op_lda, 0, ty_i8_ptr, st_array);
  OPCODE op_array = OPCODE_make_op(OPR_ARRAY, Pointer_type, MTYPE_V);
  WN* array_wn = WN_Create(op_array, 2*num_indices+1);
  WN_element_size(array_wn) = element_size;
  OPCODE  opldid = OPCODE_make_op(OPR_LDID, MTYPE_U8, MTYPE_U8);
  WN_array_base(array_wn) = wn_lda;
  for (int k=0; k<num_indices; k++) {
      WN *loop_start = WN_start(loops[k]);
      WN *loop_bound = WN_kid1(WN_end(loops[k]));
      WN *loop_step =  WN_step(loops[k]);
      OPCODE  opldid = OPCODE_make_op(OPR_LDID,WN_desc(loop_start),
                                               WN_desc(loop_start));
      WN *const_wn = WN_CreateIntconst(OPC_I4INTCONST,-1);
      WN *ldindex  = LWN_CreateLdid(opldid, loop_start);
      WN_array_index(array_wn, k) =  ldindex;
      WN_array_dim(array_wn, k) = LWN_Copy_Tree(loop_bound,TRUE,LNO_Info_Map);
      LWN_Copy_Def_Use(loop_bound, WN_array_dim(array_wn, k), du);

      Du_Mgr->Add_Def_Use(loop_start,WN_array_index(array_wn,k));
      Du_Mgr->Add_Def_Use(loop_step,WN_array_index(array_wn,k));
      Du_Mgr->Add_Def_Use(loop_bound,WN_array_index(array_wn,k));
      Du_Mgr->Add_Def_Use(loop_start,array_wn);
      DEF_LIST *deflist = Du_Mgr->Ud_Get_Def(WN_array_index(array_wn,k));
      deflist->Set_loop_stmt(loops[k]);

      LWN_Set_Parent(WN_array_index(array_wn, k), array_wn);
      LWN_Set_Parent(WN_array_dim(array_wn,k), array_wn);
  }
   for (int i=0; i<WN_kid_count(array_wn); i++) {
    LWN_Set_Parent(WN_kid(array_wn,i),array_wn);
  }

  LWN_Parentize(array_wn); 
  return array_wn;
}

/* 
 * This function is to create a array store statement of type a[i][j][k] = rhs
 * It Calls Create_Array_Base function to create the array base.
 * "wn_value" is used as the rhs expression
 */
static WN* 
Create_Array_Store(ST* st_array,
                             TYPE_ID mtype,   
                             int num_indices,
                             int esize,
                             WN *loops[],
                             WN *wn_value)
{
  TY_IDX ty = Be_Type_Tbl(mtype); 
  TY_IDX ty_ptr = Make_Pointer_Type(Be_Type_Tbl(mtype));

  WN *wn_array = Create_Array_Base(st_array, mtype,
                             num_indices, esize, loops);

  OPCODE op_istore = OPCODE_make_op(OPR_ISTORE, MTYPE_V, mtype);
  WN* wn_istore = LWN_CreateIstore(op_istore, 0, ty_ptr, wn_value, wn_array);
  LWN_Parentize(wn_istore);
  return wn_istore;
}

/* 
 * This function is to create an array load expression of type a[i][j][k]
 * The function Calls Create_Array_Base function to create the array base.
 */
static WN* 
Create_Array_Load(ST* st_array,
		             TYPE_ID mtype,  
                             int num_indices,
                             int esize,
                             WN *loops[])
{
  DU_MANAGER* du = Du_Mgr;
  TY_IDX ty = Be_Type_Tbl(mtype); 
  TY_IDX ty_ptr = Make_Pointer_Type(Be_Type_Tbl(mtype));

  OPCODE op_iload = OPCODE_make_op(OPR_ILOAD, mtype, mtype);
  WN *wn_array = Create_Array_Base(st_array, mtype,
                         num_indices, esize, loops);
  WN* wn_iload = LWN_CreateIload(op_iload, 0, ty, ty_ptr, wn_array);
  LWN_Parentize(wn_iload); 
  return wn_iload;
} 


/*
 * function returns list of array symbols which are variant
 * within the loop
 * loopVariantSyms will have list of loop variant array symbols
 */
static void 
Get_Loopvariant_Array_Syms(WN *wn_loop, STACK_OF_SYMBOL *loopVariantSyms)
{
  LWN_ITER* itr = LWN_WALK_TreeIter(wn_loop);
  for (; itr != NULL; itr = LWN_WALK_TreeNext(itr)) {
    WN* wn = itr->wn;
    if ((WN_operator(wn) == OPR_ISTORE)
        && (WN_operator(WN_kid1(wn)) == OPR_ARRAY)
        && (WN_operator((WN_kid0(WN_kid1(wn)))) == OPR_LDID 
            || WN_operator((WN_kid0(WN_kid1(wn)))) == OPR_LDA))
          loopVariantSyms->Push(SYMBOL(WN_kid0(WN_kid1(wn))));
  }
}

/*
 * This Function checks if the array in the given load expression is
 * a loop variant symbol. The loopVariantSyms stack is used for 
 * this purpose.
 */

static BOOL 
Is_LoopVariant_Array_Sym(WN *expr, STACK_OF_SYMBOL *loopVariantSyms, WN *loop)
{
   if((WN_operator(expr) == OPR_ILOAD) 
            && (WN_operator(WN_kid0(expr)) == OPR_ARRAY)
            && (WN_operator((WN_kid0(WN_kid0(expr)))) == OPR_LDID 
            || WN_operator((WN_kid0(WN_kid0(expr)))) == OPR_LDA)) {
     SYMBOL sym = SYMBOL(WN_kid0(WN_kid0(expr)));
     for (int i=0; i<loopVariantSyms->Elements(); i++)
       if (loopVariantSyms->Bottom_nth(i) == sym) return TRUE;
   }
   
   return FALSE;
}

/* This function checks if given expression is loopVariant by searching through
 * list of loopVariantExpression given as argument
 */
static BOOL 
Is_LoopVariant_Expr(WN *expr, STACK_OF_WN *loopVariantExprs)
{
   for (int i=0; i<loopVariantExprs->Elements(); i++)
     if (WN_Simp_Compare_Trees(loopVariantExprs->Bottom_nth(i), expr) == 0) 
        return TRUE;

   return FALSE;
}

/*
 * This function Determines if same array is being stored by
 * given two statements.
 */
static BOOL
Same_Array_Store_Stmts(WN *stmt1, WN *stmt2)
{
    if (stmt1 == NULL || stmt2 == NULL)
      return FALSE;

    if ((WN_operator(stmt1) != OPR_ISTORE) ||
        (WN_operator(stmt2) != OPR_ISTORE))
      return FALSE;

    WN *first_array = WN_kid1(stmt1);
    if(WN_operator(first_array) != OPR_ARRAY)
      return 0;

    WN *second_array = WN_kid1(stmt2);
    if(WN_operator(second_array) != OPR_ARRAY)
      return 0;

    if(!Tree_Equiv(first_array, second_array))
      return 0;

  return TRUE;
}

/*
 * The function checks if the  expression `wn' depends on 
 * loop indices of wn_loop.
 * The symbol lhs_array_sym is excluded in the dependency
 * analysis
 */
static BOOL 
Has_Loop_Variant_Array_Accesses(WN *term, WN *lhs_load_expr, WN *wn_loop)
{
   if ((WN_operator(term) == OPR_ILOAD)
         && (WN_operator(WN_kid0(term)) == OPR_ARRAY )) {
       if (lhs_load_expr && WN_Simp_Compare_Trees(term,lhs_load_expr) == 0)
          return FALSE;
       return  (Loop_Invariant_Access(WN_kid0(term),wn_loop) == 0);
   }
   for (INT i = 0; i < WN_kid_count(term); i++) {
     if (Has_Loop_Variant_Array_Accesses(WN_kid(term, i),lhs_load_expr,wn_loop))
        return TRUE;
   }
  return FALSE;
}

/*
 * Function to check if lhs of `wn' is variant/modified in
 * wn_loop
 */
static BOOL
Loop_Variant_Lhs(WN *wn, WN *wn_loop)
{
     return Has_Loop_Variant_Array_Accesses(WN_kid1(wn),NULL,wn_loop);
}

/*
 * Function to check if rhs expression of `wn' is variant/modified in
 * wn_loop. This is done by checking the references to loop  indices.
 */
static BOOL
Loop_Variant_Rhs(WN *stmt, WN *wn_loop)
{
  WN *lhs_load_expr = WN_kid0(stmt);
  while (lhs_load_expr && (WN_operator(lhs_load_expr)!=OPR_ILOAD))
    lhs_load_expr = WN_kid0(lhs_load_expr);

   return Has_Loop_Variant_Array_Accesses(WN_kid0(stmt),lhs_load_expr,wn_loop);
}


/*
 * The function returns the outer/parent do loop of
 * current loop by traversing the parents.
 */
static WN *
Get_Parent_Loop(WN *curloop)
{
   WN *parentLoop = curloop;

   if (parentLoop) {
     parentLoop = LWN_Get_Parent(parentLoop);
     while (WN_opcode(parentLoop) == OPC_BLOCK 
            || WN_opcode(parentLoop) == OPC_IF )
          parentLoop = LWN_Get_Parent(parentLoop);
   }
   if (!parentLoop || WN_opcode(parentLoop) != OPC_DO_LOOP) return NULL;
   return parentLoop;
}

/*
 * The function returns outermost do loop in the nested do
 * loops. This is done by traversing the parent loops until
 * the outer do loop/region.
 */
static WN *
Get_OuterMost_Parent_Loop(WN *curloop)
{
   WN *outerLoop = curloop;
   WN *parentLoop = curloop;

   while (parentLoop) {
     outerLoop = parentLoop;
     parentLoop = Get_Parent_Loop(outerLoop);
   }

   return outerLoop;
}

/*
 * The function returns the intersection of stacks "one" and "two".
 * Returns empty stack when there is no intersection 
 */
static STACK_OF_WN *
Stack_Intersection(STACK_OF_WN *one, STACK_OF_WN *two)
{
 STACK_OF_WN *tmp_stack=CXX_NEW(STACK_OF_WN(&AG_FACT_default_pool),
                                &AG_FACT_default_pool);
 for(INT i=0; i<one->Elements(); i++){
   WN *ele1 = one->Top_nth(i);
   for(INT j=0; j<two->Elements();j++){
     WN *ele2 = two->Top_nth(j);
     if(WN_Simp_Compare_Trees(ele1,ele2) == 0)
      tmp_stack->Push(ele1);
    }
 }
 return tmp_stack;
}

/*
 * The function returns loop variant load expressions in the "term" 
 * expression through "var_stack".
 */
static BOOL 
Gather_Term_Variants(WN *term, STACK_OF_WN *var_stack,
                     WN *loop, STACK_OF_SYMBOL *loopVariantSyms)
{
  if (WN_operator(term) == OPR_ILOAD &&
     WN_operator(WN_kid0(term)) == OPR_ARRAY &&
     Is_LoopVariant_Array_Sym(term,loopVariantSyms,loop)) {
       for(INT ii=0; ii<var_stack->Elements(); ii++)
        if(WN_Simp_Compare_Trees(var_stack->Bottom_nth(ii), term) == 0)
          return FALSE;
       var_stack->Push(term);
  }
  else if((WN_operator(term)==OPR_LDID)) {
     BOOL variant = FALSE;
     variant = !(Is_Loop_Invariant_Exp(term, loop));
     if (variant) {
       for(INT ii=0; ii<var_stack->Elements(); ii++)
        if(Tree_Equiv(var_stack->Bottom_nth(ii), term))
          return FALSE;
       var_stack->Push(term);
     }
  }
  else if (WN_operator(term)==OPR_MPY) {
      if(!Gather_Term_Variants(WN_kid0(term), var_stack, loop,loopVariantSyms))
        return FALSE;
      if(!Gather_Term_Variants(WN_kid1(term), var_stack, loop,loopVariantSyms))
        return FALSE;
 }
 return TRUE;
}

/* 
 * The function builds the stack of terminal expressions in the term and
 * returns through "term_stack"
 */
static BOOL 
Build_Term_Stack(WN *term,WN *lhs_load_expr, STACK_OF_WN *term_stack)
{
  if(WN_operator(term)==OPR_MPY){
    term_stack->Push(term);
  }else if(WN_operator(term)==OPR_ADD ||
           WN_operator(term)==OPR_SUB){
    if(!Build_Term_Stack(WN_kid0(term), lhs_load_expr,term_stack))
      return FALSE;
    if(!Build_Term_Stack(WN_kid1(term), lhs_load_expr,term_stack))
      return FALSE;
  }else if (WN_Simp_Compare_Trees(term,lhs_load_expr))
      return FALSE;
  return TRUE;
}


/*
 * The function returns loop variant load expressions in the "stmt" 
 * statement through "var_stack".
 */
extern BOOL 
Gather_Stmt_Common_Variants(WN *stmt, STACK_OF_WN *common_var, 
                            WN *loop, STACK_OF_SYMBOL *loopVariantSyms)
{
 
 FmtAssert(common_var && common_var->Elements()==0, 
           ("Expect an initialized but empty stack!"));
 STACK_OF_WN *term_stack = CXX_NEW(STACK_OF_WN(&AG_FACT_default_pool),
                                 &AG_FACT_default_pool);
  /* Build the stack of expressions which are factors of expressions */
 WN *lhs_load_expr = WN_kid0(stmt);
 while (lhs_load_expr && (WN_operator(lhs_load_expr)!=OPR_ILOAD))
    lhs_load_expr = WN_kid0(lhs_load_expr);

  if(!Build_Term_Stack(WN_kid0(stmt),lhs_load_expr,term_stack))
   return FALSE;
 if(term_stack->Elements()==0) //no terms? 
    return FALSE;
 STACK_OF_WN *ret_var; 
 for(INT ii=0; ii< term_stack->Elements(); ii++){
   WN *term = term_stack->Bottom_nth(ii);
   STACK_OF_WN *tmp_var = CXX_NEW(STACK_OF_WN(&AG_FACT_default_pool),
                                     &AG_FACT_default_pool);
   if(!Gather_Term_Variants(term, tmp_var, loop,loopVariantSyms))
      return FALSE;
   if(ii==0)
      ret_var = tmp_var;
   else
      ret_var = Stack_Intersection(ret_var, tmp_var);
   if(ret_var->Elements() != tmp_var->Elements())
      return FALSE;
 }

 while(ret_var->Elements()>0) {
   WN *commonvar = ret_var->Pop();
   common_var->Push(commonvar);
 }

 return TRUE;
}

/*
 * The function returns true if rhe statements in "current_stmt_group" are
 * factorizable inside the "loop". This is done by checking the common
 * variant expressions in each statement. The common variant expressions
 * should be same in all statements.
 */
static BOOL 
Factorizable_Statements(STACK_OF_WN *current_stmt_group, WN *loop,
                        STACK_OF_WN *loopVariantExprs)
{
  STACK_OF_WN *common_var;
  STACK_OF_SYMBOL loopVariantSyms(&AG_FACT_default_pool);
  Get_Loopvariant_Array_Syms(loop, &loopVariantSyms);
  // check MPY common variants
  for(INT ii=0; ii<current_stmt_group->Elements(); ii++){
    WN * stmt=current_stmt_group->Bottom_nth(ii);
    STACK_OF_WN *tmp_var = CXX_NEW(STACK_OF_WN(&AG_FACT_default_pool),
                                     &AG_FACT_default_pool);

    if(!Gather_Stmt_Common_Variants(stmt, tmp_var, loop,&loopVariantSyms))
      return FALSE;
    if(tmp_var->Elements()==0)
        return FALSE; //no invar in this statement
    if(ii == 0) //the first
        common_var = tmp_var;
    else
        common_var = Stack_Intersection(common_var, tmp_var);
    if(common_var->Elements()==0)
        return FALSE; //no common invar
  }
  for (int vars=0; vars<common_var->Elements(); vars++) {
      WN *wn = common_var->Bottom_nth(vars);
//      if (WN_operator(WN_kid0(wn)) == OPR_ARRAY)
      loopVariantExprs->Push(wn);
  }
  return (loopVariantExprs->Elements() >0); 
}

//whether the loop is possible to be aggressively factorized
static BOOL Invar_Aggressive_Factor_Candidate(WN *innerloop )
{
  INT invar_factors = 0;
  INT stmt_invar_factors;
  WN *body = WN_do_body(innerloop);
  for(WN *stmt=WN_first(body); stmt; stmt=WN_next(stmt)){
      stmt_invar_factors = Statement_Invariant_Factors(stmt, innerloop,true);
      if(stmt_invar_factors > invar_factors)
       invar_factors = stmt_invar_factors;
  }
  return (invar_factors >= GOOD_FACTORS);
}

/*
 * Main function which checks if the loop is a candidate for hoisting
 * out. The following conditions are checked.
 *  Lhs should be same in all assignment statements.
 *  Only array store statements are allowed.
 *  Only + and * expressions.
 *  Single assignment statements.
 *  Lhs statement is variant of outermost loop.
 *  Rhs expression is invariant of outermost loop indices.
 *  Loop variants of rhs expression should be part of all * expressions.
 * 
 */

BOOL 
Is_Aggressive_Factorization_Amenable(WN *innerloop, STACK_OF_WN *loop_stmts, 
                              WN_MAP &Loops_Used_In_Rhs)
{
WN* stmt;
UINT assign_stmt_count=0;
UINT do_stmt_count=0;
WN *hoistingoutloop = 0;
WN* body=WN_do_body(innerloop);

  if (!Invar_Aggressive_Factor_Candidate(innerloop)) {
    return FALSE;
  }
  dump_verbose_msg(innerloop, "Loop is a candidate for factorization");
  for (stmt = WN_first(body); stmt; stmt = WN_next(stmt)) {
     OPCODE opc=WN_opcode(stmt);
     if (opc==OPC_DO_LOOP) { 
        do_stmt_count++; 
        continue; 
     }
     else if (WN_operator(stmt) == OPR_ISTORE) {
        assign_stmt_count++;
        if (loop_stmts->Elements()) {
          // check if lhs is same as the earlier assignment expression
          WN *prev_stmt = loop_stmts->Bottom_nth(0);
          if (!Same_Array_Store_Stmts(stmt,prev_stmt)) {
             dump_verbose_msg(innerloop,
                    "Loop can not be factorized due to different stores");
             return FALSE;
          }
          if (Loop_Variant_Lhs(stmt,innerloop)) {
           dump_verbose_msg(innerloop,
             "Loop can not be factorized due to store dependency on innerloop");
           return FALSE;
          }
        } 
        hoistingoutloop = Get_OuterMost_Parent_Loop(innerloop);
        if (hoistingoutloop == 0) {
          dump_verbose_msg(innerloop,
                 "Loop can not be factorized due to imperfect nested loops");
          return FALSE;
        }
        if (Loop_Variant_Rhs(stmt,hoistingoutloop)) {
          dump_verbose_msg(innerloop,
             "Loop can not be factorized due to load dependecy on outer loops");
            return FALSE;
        }
        WN *outerLoop = innerloop;
        while (outerLoop != hoistingoutloop) {
          if (Loop_Variant_Rhs(stmt,outerLoop)) {
            int iterations = Iterations(outerLoop, &AG_FACT_default_pool);
            if (iterations == -1) {
              dump_verbose_msg(outerLoop,
                     "Loop can not be factorized due to non constant bound");
              return FALSE;
            }
            WN_MAP32_Set(Loops_Used_In_Rhs, outerLoop, iterations);
          } 
          outerLoop = Get_Parent_Loop(outerLoop);
       }
     }
     else  {
        dump_verbose_msg(innerloop,
               "Loop can not be factorized due to non assignment statements");
        return FALSE;
     }
     if (do_stmt_count > 1)  {
        dump_verbose_msg(innerloop,
               "Loop can not be factorized due to many DO statements");
        return FALSE;
      }
      loop_stmts->Push(stmt);
  }
  return TRUE;
}

/* The function will replace the loop variants with constant value
 * multiplication operands are replaced with constant `1'
 * addition operands are replaced with constant 0
 */
static WN* 
Replace_LoopVariants_WithConstants(WN *expr,WN* outerloop, 
                                   WN* wn_store, int replace_val, 
                                   STACK_OF_WN *loopVariantExprs)
{
     switch (WN_operator(expr)) {
        case OPR_ADD: 
            {
             WN_kid0(expr) = Replace_LoopVariants_WithConstants(WN_kid0(expr),
                                 outerloop,wn_store,0,loopVariantExprs);
             WN_kid1(expr) = Replace_LoopVariants_WithConstants(WN_kid1(expr),
                                 outerloop,wn_store,0,loopVariantExprs);
             LWN_Parentize(expr);
             return expr;
             }
             break;
        case OPR_MPY:
            {
             WN_kid0(expr) = Replace_LoopVariants_WithConstants(WN_kid0(expr),
                                 outerloop,wn_store,1,loopVariantExprs);
             WN_kid1(expr) = Replace_LoopVariants_WithConstants(WN_kid1(expr),
                                 outerloop,wn_store,1,loopVariantExprs);
             LWN_Parentize(expr);
             return expr;
             }
             break;

        case OPR_ILOAD:
        case OPR_LDID:
             if (Is_LoopVariant_Expr(expr,loopVariantExprs)) {
                   TCON tcon; ST* st;
                   TYPE_ID type = WN_rtype(expr);
                   if (replace_val) {
                     if (MTYPE_is_float(type))
                       tcon = Host_To_Targ_Float (type, 1.0);
                     else
                       tcon = Host_To_Targ(type, 1);
                   } else {
                     if (MTYPE_is_float(type))
                       tcon = Host_To_Targ_Float (type, 0.0);
                     else
                       tcon = Host_To_Targ(type, 0);
                   }
                   st = New_Const_Sym (Enter_tcon(tcon), Be_Type_Tbl(type));
                   WN *const_wn = WN_CreateConst(OPR_CONST, type, MTYPE_V, st);
                   return (const_wn);
             } 
             return expr;
        default:
            return expr;
            break;
    }
    return expr;
}
/*
 * The function will create the rhs expression for the factorized loop
 * statement. 
 */
static WN* 
Create_RhsOf_FactorizedLoop(WN *expr,WN* outerloop, WN* wn_store,
                          WN *partialArrayLoad,BOOL *replace_with_parray, 
                          int replace_val,STACK_OF_WN *loopVariantExprs)
{
     switch (WN_operator(expr)) {
        case OPR_ADD: 
           {
            WN_kid0(expr) = Create_RhsOf_FactorizedLoop(WN_kid0(expr),outerloop,
                                wn_store,partialArrayLoad,replace_with_parray, 
                                0,loopVariantExprs);
            WN_kid1(expr) = Create_RhsOf_FactorizedLoop(WN_kid1(expr),outerloop,
                                wn_store,partialArrayLoad,replace_with_parray,
                                0, loopVariantExprs);
            LWN_Parentize(expr);
            return expr;
           }
           break;
        case OPR_MPY:
           {
            WN_kid0(expr) = Create_RhsOf_FactorizedLoop(WN_kid0(expr),outerloop,
                                wn_store,partialArrayLoad,replace_with_parray,
                                1,loopVariantExprs);
            WN_kid1(expr) = Create_RhsOf_FactorizedLoop(WN_kid1(expr),outerloop,
                                wn_store,partialArrayLoad,replace_with_parray,
                                1,loopVariantExprs);
            LWN_Parentize(expr);
            return expr;
           }
           break;

        case OPR_ILOAD:
           if (WN_operator(wn_store) == OPR_ISTORE) {
              if ((WN_load_offset(expr) == WN_store_offset(wn_store)) &&
                  (WN_field_id(expr) == WN_field_id(wn_store)) &&
                  (WN_desc(expr) == WN_desc(wn_store)) &&
                  (WN_Simp_Compare_Trees(WN_kid0(expr),WN_kid1(wn_store))==0)) {
                       return expr;
              }
              if (Is_LoopVariant_Expr(expr,loopVariantExprs) == 0) {
                 Delete_Def_Use(expr);
                 if (*replace_with_parray) {
                   *replace_with_parray=FALSE;
                   return (partialArrayLoad);
                 } else {
                   TCON tcon; ST* st;
                   TYPE_ID type = WN_rtype(expr);
                   tcon = Host_To_Targ_Float (type, replace_val);
                   st = New_Const_Sym (Enter_tcon(tcon), Be_Type_Tbl(type));
                   WN *const_wn = WN_CreateConst(OPR_CONST, type, MTYPE_V, st);
                   return (const_wn);
                 }
              } 
           }
           return expr;
        case OPR_LDID: 
           if (Is_LoopVariant_Expr(expr,loopVariantExprs) == 0) {
              TCON tcon; ST* st;
              TYPE_ID type = WN_rtype(expr);
              tcon = Host_To_Targ_Float (type, replace_val);
              st = New_Const_Sym (Enter_tcon(tcon), Be_Type_Tbl(type));
              WN *const_wn = WN_CreateConst(OPR_CONST, type, MTYPE_V, st);
              return (const_wn);
            }
            return expr;
        case OPR_CONST: 
            {
              TCON tcon; ST* st;
              TYPE_ID type = WN_rtype(expr);
              tcon = Host_To_Targ_Float (type, replace_val);
              st = New_Const_Sym (Enter_tcon(tcon), Be_Type_Tbl(type));
              WN *const_wn = WN_CreateConst(OPR_CONST, type, MTYPE_V, st);
              return (const_wn);
            }
        default:
            return expr;
            break;
    }
    return expr;
}

/* The function creates the rhs expression of partial array
 * loop statements
 * The loop variants are replaced with constant value "0"
 * The rhs is replaced with partial_array[index] + actual rhs
 */
static WN* 
Create_RhsOf_PartialArray_Store(WN *wn_store, WN *partialArrayLoad, 
                                WN *outerloop,STACK_OF_WN *loopVariantExprs)
{
  WN *wn_store_rhs = WN_kid0(wn_store);
  MTYPE mtype = WN_desc (wn_store);
  WN *kid0 = wn_store_rhs;
  while (kid0 && (WN_operator(kid0)!=OPR_ILOAD))
    kid0 = WN_kid0(kid0);
  if (kid0)  loopVariantExprs->Push(kid0);
  WN *new_rhs = Replace_LoopVariants_WithConstants(wn_store_rhs,outerloop,
                                                   wn_store,0,loopVariantExprs);
  loopVariantExprs->Pop();
  OPCODE op_add = OPCODE_make_op(OPR_ADD, WN_rtype(new_rhs), MTYPE_V);
  new_rhs = LWN_CreateExp2(op_add,partialArrayLoad,new_rhs);
  LWN_Parentize(new_rhs);
  return new_rhs;
}

/*
 * Helper function that returns the loop statement and the store
 * statements within the loop.
 * Loop statements are added to `loopStmts'.
 * Store statements are added to `storeStmts'.
 */
static void 
Get_Loop_And_Store_Stmts(WN *wn, STACK_OF_WN *loopStmts, 
                                 STACK_OF_WN *storeStmts)
{
  OPCODE opc=WN_opcode(wn);

  if (opc==OPC_DO_LOOP) {
     loopStmts->Push(wn);
     WN* body=WN_do_body(wn);
     WN* stmt;
     for (stmt = WN_first(body); stmt; stmt = WN_next(stmt)) {
      Get_Loop_And_Store_Stmts(stmt,loopStmts,storeStmts);
     }
  } else if (opc==OPC_BLOCK) {
    for (WN* stmt=WN_first(wn); stmt;) {
      WN* next_stmt=WN_next(stmt);
      Get_Loop_And_Store_Stmts(next_stmt,loopStmts,storeStmts);
      stmt=next_stmt;
    }
  } else {
      FmtAssert(WN_operator(wn) == OPR_ISTORE,
              ("Get_Loop_And_Store_Stmts: expects a store"));
      storeStmts->Push(wn);
  }
}

/* 
 * The function creates the partial array loop.The original loop
 * is copied over. The variants in the copied loop are replaced with
 * constants. The lhs expressions are replaced with partial array
 * stores.
 */
static WN* 
Create_PartialArray_Loop(WN *hoistingLoop, 
                         WN *loops[],
                         int num_indices,
                         ST *partialArraySym,
                         STACK_OF_WN *loopVariantExprs,
                         STACK_OF_WN *alias_wns)
{
   // helper veriables
   STACK_OF_WN partialArrayStoreStmts(&AG_FACT_default_pool);
   STACK_OF_WN newPartialArrayStoreStmts(&AG_FACT_default_pool);
   STACK_OF_WN partialArrayLoopStmts(&AG_FACT_default_pool);
   STACK_OF_WN origStoreStmts(&AG_FACT_default_pool);
   STACK_OF_WN origLoopStmts(&AG_FACT_default_pool);
   WN *ploops[MAX_FACTORIZE_LOOP_DEPTH];

   WN *outerloop = loops[num_indices-1];
   WN *partialArrayLoop = LWN_Copy_Tree(outerloop, TRUE, LNO_Info_Map);

   Get_Loop_And_Store_Stmts(partialArrayLoop,&partialArrayLoopStmts, 
                                                  &partialArrayStoreStmts);
   Get_Loop_And_Store_Stmts(outerloop,&origLoopStmts, &origStoreStmts);

   for (int i=0; i<num_indices; i++) {
      ploops[num_indices-1-i] = partialArrayLoopStmts.Bottom_nth(i);  
   }

   WN *wn_store = partialArrayStoreStmts.Top_nth(0);
   MTYPE mtype = WN_desc (wn_store);
   // assert if wn_store is not of type WN_ISTORE
   INT64 esize = MTYPE_size_min(mtype) >> 3;

   // replace the stores in the new loop with partial array stores.
   for (int i=0; i<partialArrayStoreStmts.Elements(); i++) {
     WN *new_store=partialArrayStoreStmts.Top_nth(i);
     WN *copyPartialArrayLoad = Create_Array_Load(partialArraySym, mtype, 
                                                    num_indices, esize, ploops);
     WN *partialArrayRhs = Create_RhsOf_PartialArray_Store(new_store,
                            copyPartialArrayLoad,hoistingLoop,loopVariantExprs);
     WN *partialArrayStoreBase = Create_Array_Base(partialArraySym, mtype,
                                                    num_indices, esize, ploops);
     WN_kid1(new_store) = partialArrayStoreBase;
     WN_kid0(new_store) = partialArrayRhs;
     alias_wns->Push(new_store);
     alias_wns->Push(copyPartialArrayLoad);
     LWN_Parentize(new_store);
   }

   TCON tcon; ST* st;
   WN *orig_store=partialArrayStoreStmts.Bottom_nth(0);
   TYPE_ID type = WN_rtype(WN_kid0(orig_store));
   if (MTYPE_is_float(type))
      tcon = Host_To_Targ_Float (type, 0.0);
   else
      tcon = Host_To_Targ(type, 0);
   st = New_Const_Sym (Enter_tcon(tcon), Be_Type_Tbl(type));

   // Initializing partial array element to zero
   // partial_array(i,j,k,l) = 0
   WN *const_wn = WN_CreateConst(OPR_CONST, type, MTYPE_V, st);
   WN *partialArrayStoreInit = Create_Array_Store(partialArraySym, mtype,
                             num_indices, esize, ploops,const_wn);
   LWN_Parentize(partialArrayStoreInit);
   LWN_Insert_Block_Before(LWN_Get_Parent(orig_store),orig_store, 
                                                       partialArrayStoreInit);
   alias_wns->Push(partialArrayStoreInit);

   LWN_Parentize(partialArrayLoop);
   DO_LOOP_INFO* dli1 = Get_Do_Loop_Info(hoistingLoop);
   DO_LOOP_INFO* dli2 = Get_Do_Loop_Info(origLoopStmts.Bottom_nth(0));
   // adjust the depth as we are moving the loop out of hoisting loop
   int offsetdepth = dli2->Depth - dli1->Depth;

   for (int i=0; i<partialArrayLoopStmts.Elements(); i++) {
      WN *innerloop = partialArrayLoopStmts.Bottom_nth(i);
      DO_LOOP_INFO *dli = Get_Do_Loop_Info(innerloop);
      dli->Depth -= offsetdepth;
   }
   return partialArrayLoop;
}

/*
 * Function creates the factorized loop after hoisting out the partial
 * array loop.
 * loop invariants are replaced with constants.
 */
WN* Create_Factorized_Loop(WN *simplifyLoop,STACK_OF_WN *loop_stmts, 
                         WN* partialArrayLoad, WN* hoistingLoop, 
                         STACK_OF_WN *loopVariantExprs)
{
  BOOL replace_with_parray=TRUE;
  ARRAY_DIRECTED_GRAPH16* adg = Array_Dependence_Graph;
  WN *simplifyLoopStmt = loop_stmts->Top_nth(0);
  WN *rhs= WN_kid0(simplifyLoopStmt);
  WN_kid0(simplifyLoopStmt) = Create_RhsOf_FactorizedLoop(rhs,hoistingLoop, 
                                simplifyLoopStmt,partialArrayLoad,
                                &replace_with_parray,1,loopVariantExprs);
  LWN_Parentize(simplifyLoopStmt);
  WN *wn_parent = LWN_Get_Parent(loop_stmts->Top_nth(0));
  for (int i=1; i<loop_stmts->Elements(); i++)   
  {
        WN *cur_wn = loop_stmts->Top_nth(i);
        LWN_Update_Def_Use_Delete_Tree(cur_wn);
        LWN_Delete_Tree(LWN_Extract_From_Block(cur_wn));
  }
  WN *wn = WN_first(wn_parent);

  while (wn) {
    WN *cur_wn = wn;
    wn = WN_next(wn);
    if (cur_wn != simplifyLoopStmt) {
        LWN_Update_Def_Use_Delete_Tree(cur_wn);
        LWN_Delete_Tree(LWN_Extract_From_Block(cur_wn));
    }
  }

  DO_LOOP_INFO* dli = Get_Do_Loop_Info(simplifyLoop);
  dli->Is_Inner = TRUE;
  return simplifyLoop;
}


/*
 * Simplifyloop is the candidate for factorization optimization.
 * Extracts the variants and invariants in the loop and creates the 
 * factorized and partial array loop.
 */
WN* Factorize_Loop_Statements(WN *simplifyloop, 
                          STACK_OF_WN *loop_stmts,  
                          STACK_OF_WN  *rhsDependent_loops,
                          STACK_OF_WN *loopVariantExprs)
{
   WN* loops[MAX_FACTORIZE_LOOP_DEPTH];
   STACK_OF_WN     alias_wns(&AG_FACT_default_pool);
    // dont simplify too deep loops
   int num_indices = rhsDependent_loops->Elements();
   if (num_indices > MAX_FACTORIZE_LOOP_DEPTH) {
      dump_verbose_msg(simplifyloop,
             "loop not factorizable due to the depth of loop");
      return 0;
   }
   // get the size of partial array loop on each dimension
   int max_iter_loop = 0;
   int partial_array_size = 8;
   for (int i=0; i<num_indices; i++)
   {
     partial_array_size *= 
           Iterations(rhsDependent_loops->Bottom_nth(i), &AG_FACT_default_pool);
     loops[i] = rhsDependent_loops->Bottom_nth(i);
   }

   WN *wn_store = loop_stmts->Top_nth(0);
   MTYPE mtype = WN_desc (wn_store);
   INT64 esize = MTYPE_size_min(mtype) >> 3;
   ST* partialArraySym = Create_PartialArray_Symbol(mtype,partial_array_size);

   // create the partial array loop and isert it above the hositing loop
   WN *hoistingOutLoop = Get_OuterMost_Parent_Loop(simplifyloop);

   WN *partialArrayLoop = Create_PartialArray_Loop(hoistingOutLoop,
                                 loops, num_indices,partialArraySym,
                                 loopVariantExprs,&alias_wns);


   LWN_Parentize(partialArrayLoop);
   WN *wn_parent = LWN_Get_Parent(hoistingOutLoop);
   LWN_Insert_Block_Before(wn_parent, hoistingOutLoop, partialArrayLoop);
   LWN_Copy_Linenumber(simplifyloop, partialArrayLoop);
   LWN_Set_Parent(partialArrayLoop, wn_parent);

   WN *partialArrayLoad = Create_Array_Load(partialArraySym, mtype, 
                                             num_indices, esize, loops);
   alias_wns.Push(partialArrayLoad);
  // factorize the current loop using partial arrays
   WN *simplifiedLoop = Create_Factorized_Loop(simplifyloop,loop_stmts,
                             partialArrayLoad,hoistingOutLoop,loopVariantExprs);
   WN *alias_wn=0;

   for (int i=0; i<alias_wns.Elements(); i++) {
     if (alias_wn)  Copy_alias_info(Alias_Mgr,alias_wn,alias_wns.Bottom_nth(i));
     else {
        alias_wn = alias_wns.Bottom_nth(i);
        if (WN_operator(alias_wn) == OPR_ISTORE)
          Create_lda_array_alias(Alias_Mgr, WN_array_base(WN_kid1(alias_wn)), 
                                            alias_wn);
        else if (WN_operator(alias_wn) == OPR_ILOAD)
          Create_lda_array_alias(Alias_Mgr, WN_array_base(WN_kid0(alias_wn)), 
                                            alias_wn);
     }
   }

   // update the do loop informations
   DOLOOP_STACK *loop_stack = 
            CXX_NEW(DOLOOP_STACK(&LNO_local_pool), &LNO_local_pool);
   Build_Doloop_Stack(LWN_Get_Parent(partialArrayLoop), loop_stack);
   LNO_Build_Access(partialArrayLoop, loop_stack, &LNO_default_pool);
   LNO_Build_Do_Access(partialArrayLoop, loop_stack);
   Do_DU_Update(partialArrayLoop);

   return simplifiedLoop;
}

/*
 * This function is to analyze and aggressively factorize the given loop.
 * It is called by "LNO_optimize"  function for each of the inner loops,
 * The inner loop is checked for invariant code motion if any and
 * if useful aggressively factorized.
 */
 
extern BOOL 
Do_Aggresive_Loop_Factorization(WN* loop)
{  
  STACK_OF_WN loop_stmts(&AG_FACT_default_pool);
  STACK_OF_WN rhsDependent_loops(&AG_FACT_default_pool);
  STACK_OF_WN loopVariantExprs(&AG_FACT_default_pool);

   if(WN_operator(loop) != OPR_DO_LOOP  ||
           Do_Loop_Has_Calls(loop)    ||
           Do_Loop_Has_Exits(loop)    ||
           Do_Loop_Has_Gotos(loop)    ||
           Do_Loop_Is_Mp(loop))
   return FALSE;

  // check the amenability of inner loop and its parent loops
  // for loop hoisting
  WN *simplifyloop = loop;
  WN *testloop = loop;
  WN_MAP Loops_Used_In_Rhs = WN_MAP32_Create(&AG_FACT_default_pool);
  while (Is_Aggressive_Factorization_Amenable(testloop,&loop_stmts,
                                                   Loops_Used_In_Rhs)) {
     simplifyloop = testloop;
     WN* parent_loop = LWN_Get_Parent(testloop);
     if (WN_opcode(parent_loop) == OPC_BLOCK)
	  parent_loop = LWN_Get_Parent(parent_loop);
     testloop = parent_loop;
     if (WN_opcode(testloop) != OPC_DO_LOOP) break;
  }
  // not a good candidate for loop hoisting
  if (simplifyloop == loop) {
     WN_MAP_Delete(Loops_Used_In_Rhs);
     return FALSE;
  }
  
  WN *outerLoop = simplifyloop;
  while (outerLoop) {
     if (WN_MAP32_Get(Loops_Used_In_Rhs, outerLoop)) {
        rhsDependent_loops.Push(outerLoop);
     }
     outerLoop = Get_Parent_Loop(outerLoop);
  }

  WN_MAP_Delete(Loops_Used_In_Rhs);
  WN *hoistingOutLoop = Get_OuterMost_Parent_Loop(simplifyloop);
  if (Factorizable_Statements(&loop_stmts,hoistingOutLoop,
                                       &loopVariantExprs) == 0) {
     dump_verbose_msg(simplifyloop,
            "Variants could not be factorized for loop");
     return FALSE;
  }

  // Do the factorization
  int Src_Line_Num = Srcpos_To_Line(WN_Get_Linenum(simplifyloop));
  WN* transformLoop = Factorize_Loop_Statements(simplifyloop,&loop_stmts,
                                     &rhsDependent_loops,&loopVariantExprs);
  if (transformLoop) {
    dump_verbose_msg(simplifyloop,"Loop aggressively factorized");
    return TRUE;
  } else {
    dump_verbose_msg(simplifyloop,
           "Loop aggressive factorization unsuccesful on a good loop");
    return FALSE;
  } 
}

/* 
 * Memory Initialization function
 */
extern void 
Initialize_Aggressive_Factorization()
{
 if(!pool_initialized){
   MEM_POOL_Initialize(&AG_FACT_default_pool,"AG_FACT_default_pool",FALSE);
   MEM_POOL_Push(&AG_FACT_default_pool);
   pool_initialized = TRUE;
 }
}

/* 
 * Memory finalization function
 */
extern void 
Finalize_Aggressive_Factorization()
{
 if(pool_initialized){
   MEM_POOL_Pop(&AG_FACT_default_pool);
   MEM_POOL_Delete(&AG_FACT_default_pool);  //memory to be cleaned
   pool_initialized = FALSE;
 }
}

/* 
 * Function which is called by lno optimizer for each functions to do
 * aggressive factorization.
 */
extern BOOL 
Aggressive_Invariant_Factorization(WN *func_nd)
{ 
  if (!LNO_Aggressive_Invariant_Factorization) 
     return FALSE;

  Initialize_Aggressive_Factorization();

  INT factorized_loops = 0;
  STACK_OF_WN *inner_do_stack = CXX_NEW
          (STACK_OF_WN(&AG_FACT_default_pool),&AG_FACT_default_pool);
  //collecting inner do loops
  for (LWN_ITER* itr = LWN_WALK_TreeIter(func_nd);
       itr;
       itr = LWN_WALK_TreeNext(itr)){
     WN* wn = itr->wn;
     if (WN_operator(wn) == OPR_DO_LOOP){
       DO_LOOP_INFO *dli = Get_Do_Loop_Info(wn);
     if(dli && dli->Is_Inner)
       inner_do_stack->Push(wn);
     }
  }
  for(INT ii=0; ii<inner_do_stack->Elements(); ii++){
     WN *loop = inner_do_stack->Bottom_nth(ii);
     INT Src_Line_Num = Srcpos_To_Line(WN_Get_Linenum(loop));
     if(Do_Aggresive_Loop_Factorization(loop)){    
      factorized_loops++;
     }
  }
  // recreate the inner loop stack  if loops are modified

  Finalize_Aggressive_Factorization();
  return factorized_loops?TRUE:FALSE;
}
