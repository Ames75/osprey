
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
// 	LNO memset optimization (Loop Idiom Recognition and Optimization)
//      -----------------------------------------------------------------------
//
//
//      Identify the following loop idiom and replace the initialization with
//      memset operation
//         do i = lb, ub
//           do j=lb,ub
//           .
//           array[i,j,..] = 0
//           .
//           enddo
//         enddo
//      replace with
//          memset(array,0,ub1*ub2*sizeof(typeof(array)));
//
//      We use a option LNO:use_memset=[0,1] to control 
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
#include "stab.h"

typedef STACK<WN*> STACK_OF_WN;
static MEM_POOL MEMSET_default_pool;
static int pool_initialized = 0;
extern BOOL Fixed_Size_Array_Is_Stride_One(ST* array_st);

extern ST* Declare_Func_Three_Arg (const char* ty_name, const char* st_name,
                                   TY_IDX ret_ty, TY_IDX arg1_ty, 
                                   TY_IDX arg2_ty, TY_IDX arg3_ty);

static const int memset_conversion_threshold = 32768;

static void 
dump_verbose_msg(WN *stmt, const char *msg)
{
     if (LNO_Verbose && stmt && msg) {
        printf("Memset Opt: %s at line (%d)\n", 
	       msg, Srcpos_To_Line(WN_Get_Linenum(stmt)));
     }
}
/*
 * Function returns the size of array.
 * If size could not be found at compile time, the function returns FALSE.
 * array size is terurned through "total_size" argument.
 * returns TRUE if tial_size could be set correectly. 
 */
static
BOOL Is_Known_Size_Array(const SYMBOL* array, int *total_size)
{
  ST* st = array->St();
  TY_IDX ty = ST_type(st);
  INT tsize=1;

  if (ST_class(st) == CLASS_PREG) 
    return TRUE;

  if (TY_kind(ty) == KIND_POINTER) {
    ty = TY_pointed(ty);
    if (ST_sclass(st) != SCLASS_FORMAL && TY_size(ty) != 0) 
      return TRUE; 
  }

  if (TY_kind(ty) != KIND_ARRAY) 
    return TRUE;
  
  INT ndims = TY_AR_ndims(ty);
  for (INT i = 0; i < ndims; i++) {
    if (!TY_AR_const_lbnd(ty, i)) 
      return TRUE; 
    if (!TY_AR_const_ubnd(ty,i))
      return TRUE; 
    if (!TY_AR_const_stride(ty,i))
      return TRUE; 
    INT diff = TY_AR_ubnd_val(ty,i) - TY_AR_lbnd_val(ty,i) + 1;
    if (diff <= 1) 
      return FALSE;
    tsize=tsize*diff;
  }

  if (Fixed_Size_Array_Is_Stride_One(st) == FALSE) 
      return FALSE;
  *total_size = tsize;
  return TRUE;
}
/*
 * Function returns the number of iterations of the loop
 * If number of iterations could not be found at compile
 * time, the function returns FALSE.
 * Number of iterations are returned through iterations
 * argument.
 */
static BOOL
Is_Known_Iterations(STACK_OF_WN *wn_loops, INT *iterations)
{
 INT total_iters = 1;

 for (int i=0; i<wn_loops->Elements(); i++) {
    WN *wn_loop = wn_loops->Top_nth(i);

    WN *lb = WN_kid0(WN_start(wn_loop));
    WN *ub = WN_kid1(WN_end(wn_loop));
    WN *step = Loop_Step(wn_loop);
    if ((WN_operator(lb) != OPR_INTCONST) ||
        (WN_operator(ub) != OPR_INTCONST) ||
        (WN_operator(step) != OPR_INTCONST))
    return FALSE;
    INT lbval = WN_const_val(lb);
    INT ubval = WN_const_val(ub);
    INT stepval = WN_const_val(step);
    if (stepval != 1) return FALSE;
    total_iters *= (ubval-lbval+1);
 }

 *iterations = total_iters;
 return TRUE;
}
/*
 * The function checks if loop is perfectly nested  in the num_outer DO loops 
 * that surround this
 */
static BOOL Perfectly_Nested(WN *loop, INT num_outer,
                             STACK_OF_WN *wn_loops )
{
  wn_loops->Push(loop);
  if (num_outer == 0) return TRUE;
  if (WN_next(loop) || WN_prev(loop)) return FALSE;
  WN *new_loop = LWN_Get_Parent(LWN_Get_Parent(loop));
  OPCODE opc = WN_opcode(new_loop);
  if (opc != OPC_DO_LOOP) return FALSE;
  return Perfectly_Nested(new_loop,num_outer-1,wn_loops);
}

/* Function checks if the array access is contiguous for
 * all loop indices. returns FALSE for non contiguous
 * accsesses.
 */
static BOOL 
Is_Contiguous_Access(STACK_OF_WN* wn_loops, WN* wn_array)
{
  ACCESS_ARRAY *aa = (ACCESS_ARRAY *) WN_MAP_Get(LNO_Info_Map, wn_array);
  if (aa == NULL || aa->Too_Messy)
    return FALSE;
  for (int i = 0; i < aa->Num_Vec(); i++)
    if (aa->Dim(i)->Delinearized_Symbol != NULL)
      return FALSE;
  for (int i = 0; i < aa->Num_Vec(); i++) {
    ACCESS_VECTOR* av = aa->Dim(i);
    if (av->Too_Messy)
      return FALSE;
    WN* wn_index = WN_array_index(wn_array, i);
    WN* wn_loop = wn_loops->Top_nth(i);
    for (int l=0; l<wn_loops->Elements(); l++) {
      if (l!=i && av->Loop_Coeff(l) != 0)
       return FALSE;
      if (l==i && av->Loop_Coeff(l) != 1) 
       return FALSE;
    }
  }
  return TRUE;
}


/* The function checks if given loop is a memset conversion
 * candidate. 
 *  1. checks if 9 is stored to array
 *  2. Checks if loop is perfectly nested.
 *  3. Checks if array access is contiguous
 *  4. Checks if loop iterations are constant
 *  5. Check if size of array is constant
 *  6. Checks if array size and iterations are same.
 *  returns TRUE if all conditions are satisfied.
 */
BOOL 
Is_Memset_Candidate (WN *innerloop, STACK_OF_WN *wn_stmts, 
                                    STACK_OF_WN *wn_loops,
                                    INT *iterations)
{
WN* stmt;
UINT assign_stmt_count=0;
UINT do_stmt_count=0;
WN *hoistingoutloop = 0;
WN* body=WN_do_body(innerloop);

  for (stmt = WN_first(body); stmt; stmt = WN_next(stmt)) {
    OPCODE opc=WN_opcode(stmt);
    if (WN_operator(stmt)!=OPR_ISTORE) return FALSE;
    WN *wn = WN_kid1(stmt);
    if ((WN_operator(wn) != OPR_ARRAY)      ||
       !(WN_has_sym(WN_array_base(wn)))   ||
        (WN_operator(WN_array_base(wn)) == OPR_LDID) ||
        (ST_sclass(WN_st(WN_array_base(wn))) == SCLASS_FORMAL)) {
          return FALSE;
    }

    if (WN_operator(WN_kid0(stmt)) == OPR_INTCONST) {
       int const_value = WN_const_val(WN_kid0(stmt));
       if (const_value != 0) return FALSE;
    }
    else if ((WN_operator(WN_kid0(stmt)) == OPR_CONST)) {
       TYPE_ID mtype = WN_rtype(WN_kid0(stmt));
       if (mtype != MTYPE_F4 && mtype != MTYPE_F8 && mtype != MTYPE_F10)
         return FALSE;
//       if (!MTYPE_is_float(WN_rtype(WN_kid0(stmt))))
//         return FALSE;
       if (Targ_To_Host_Float(Const_Val(WN_kid0(stmt))) != 0.0)
          return FALSE;
    } else 
       return FALSE;


    WN *wn_array = WN_kid1(stmt);
    ACCESS_ARRAY *aa = (ACCESS_ARRAY *) WN_MAP_Get(LNO_Info_Map, wn_array);
    int num_outer = aa->Num_Vec();
    wn_loops->Clear();
    if (Perfectly_Nested(innerloop, num_outer-1 ,wn_loops) == 0) {
             dump_verbose_msg(innerloop,
               "Loop can not be converted due to imperfect nesting ");
             return FALSE;
    }
    if (Is_Contiguous_Access(wn_loops,wn_array) == 0) {
             dump_verbose_msg(innerloop,
               "Loop can not be converted due to non-contiguous  access ");
             return FALSE;
    }
    wn_stmts->Push(stmt);
  }
  // If wn)stmts stack or wn_loops stack is empty return from here
  if (!wn_stmts->Elements() || !wn_loops->Elements())
     return FALSE;
  // Get total number of interations in the loop. The check will make sure
  // that the lower, upper and strides are constants.
  
  int num_iterations;
  if (Is_Known_Iterations(wn_loops, &num_iterations) == FALSE) {
     dump_verbose_msg(wn_loops->Top_nth(0), \
           "loop bounds are not constants and can not converted to memset");
     return FALSE;
  }
  if (num_iterations < memset_conversion_threshold) {
     char msg[256]; 
     sprintf(msg,"Total loop iterations (%d) are lesser than threshold (%d) " \
       "and not converting to memset",num_iterations,memset_conversion_threshold);

     dump_verbose_msg(wn_loops->Top_nth(0), msg);
     return FALSE;
  }
  
  // Get the size of array that are initializaed. The size of the 
  // array should match with the num_iterations. Otherwise, we are 
  // initializing too many or too less elements than the 
  // iterations and the loop can not be replaced with memset.
  for (int i=0; i<wn_stmts->Elements(); i++) {
      WN *stmt = wn_stmts->Top_nth(i);
      WN *array = WN_kid1(stmt);
      WN *array_lda = WN_array_base(array);
      SYMBOL array_sym = SYMBOL(array_lda);
      INT array_size=0;
      if (Is_Known_Size_Array(&array_sym,&array_size) == FALSE) {
         dump_verbose_msg(stmt, \
             "array bounds are not constants and can not converted to memset");
         return FALSE;
      }
      if (array_size != num_iterations)  {
         dump_verbose_msg(stmt, \
             "array bounds are not matching with loop bounds." \
             "can not convert to memset");
         return FALSE;
      }
  }

  *iterations = num_iterations;
  dump_verbose_msg(wn_loops->Top_nth(0), 
             "loop is a candidate for memset conversion");
  return TRUE;
}


/*Function which creates the memset construct for the given
 * array initialization. The original loop will be replaced
 * with memset statemetn. The array to initialize and its
 * size expressions are passed as the arguments.
 */
static WN*
Create_Memset_Stmt(WN *array_lda, WN* size_exp)
{
   WN *parm1_wn;
   WN *parm2_wn;
   WN *parm3_wn;
   DU_MANAGER* du = Du_Mgr;

   TY_IDX voidpty = Make_Pointer_Type (Be_Type_Tbl(MTYPE_V));

   ST *memsetFunc = Declare_Func_Three_Arg ("._memset", "memset",
                            Be_Type_Tbl(MTYPE_V),
                            voidpty,                    /* start address */
                            Be_Type_Tbl(MTYPE_I8),     /* value     */
                            Be_Type_Tbl(MTYPE_I8));      /* size in bytes */

    /* create the "sizeof" call first */

    /* Create the memset call */
    OPCODE callop = OPCODE_make_op (OPR_CALL, MTYPE_V, MTYPE_V);
    WN* memset_call_wn = WN_Create (callop, 3);
    WN_st_idx(memset_call_wn) = ST_st_idx(memsetFunc);

    TY_IDX ptr_ty = Make_Pointer_Type (Be_Type_Tbl(Pointer_type));
    parm1_wn = LWN_Copy_Tree(array_lda);
    parm1_wn = WN_CreateParm (Pointer_type,
			     parm1_wn,
			     ptr_ty,
			     WN_PARM_BY_VALUE);
    WN_kid0(memset_call_wn) = parm1_wn;

    // parm 2, initialization value 0
    OPCODE const_op = OPCODE_make_op(OPR_INTCONST, MTYPE_I8, MTYPE_V);
    parm2_wn = WN_CreateIntconst (const_op, 0);
    parm2_wn = WN_CreateParm (Pointer_type,
			     parm2_wn,
			     ptr_ty,
			     WN_PARM_BY_VALUE);
    WN_kid1(memset_call_wn) = parm2_wn;

    // parm 3: size of array
    parm3_wn = WN_CreateParm (Pointer_type,
			     size_exp,
			     ptr_ty,
			     WN_PARM_BY_VALUE);
    WN_kid2(memset_call_wn) = parm3_wn;

    LWN_Parentize(memset_call_wn);
    return memset_call_wn;

}

 /* Array initialization to Memset convertion function
  *
  * Checks if it is a zero initialization loop
  * - Checks if it's a perfectly nested loop
  * - having contiguous block initialization
  * - constant sized arrray 
  * - constant loop bounds
  * - loop iterations and array sizes are same
  *
  * If above conditions are satified, it replaces
  * the loop with memset call
  *
  */
static BOOL 
Do_InitLoopReplace_With_Memset(WN *loop) 
{
STACK_OF_WN wn_loops(&MEMSET_default_pool);
STACK_OF_WN wn_stmts(&MEMSET_default_pool);
INT iterations;

    BOOL canreplace = Is_Memset_Candidate(loop,&wn_stmts,&wn_loops,&iterations);
    if (canreplace) {
       WN *outerloop = wn_loops.Top_nth(0);
       INT array_size=0;
       OPCODE const_op = OPCODE_make_op(OPR_INTCONST, MTYPE_I8, MTYPE_V);
       for (int i=0; i<wn_stmts.Elements(); i++) {
         WN *array = WN_kid1(wn_stmts.Bottom_nth(i));
         WN *array_lda = LWN_Copy_Tree(WN_array_base(array));
         LWN_Parentize(array_lda);
         WN *size_exp = 
            WN_CreateIntconst(const_op,iterations*WN_element_size(array));
         WN *memsetStmt = Create_Memset_Stmt(array_lda, size_exp);
         LWN_Copy_Linenumber(outerloop, memsetStmt);

         LWN_Parentize(memsetStmt);
         dump_verbose_msg(wn_stmts.Top_nth(i),"Replaced with memset statement");
         LWN_Insert_Block_Before(LWN_Get_Parent(outerloop),outerloop,
                                                           memsetStmt);
       }
      /* Delete the original stamtent and loops */
      for (int i=0; i<wn_stmts.Elements(); i++) {
          WN *cur_wn = wn_stmts.Top_nth(i);
          LWN_Update_Def_Use_Delete_Tree(cur_wn);
          LWN_Delete_Tree(LWN_Extract_From_Block(cur_wn));
      }
      WN *cur_wn = wn_loops.Top_nth(0);
      LWN_Update_Def_Use_Delete_Tree(cur_wn);
      LWN_Delete_Tree(LWN_Extract_From_Block(cur_wn));
      return TRUE;
    }
    return FALSE;
}


/* 
 * Memory pool Initialization function
 */
extern void 
Initialize_Memset_Conversion()
{
 if(!pool_initialized){
   MEM_POOL_Initialize(&MEMSET_default_pool,"MEMSET_default_pool",FALSE);
   MEM_POOL_Push(&MEMSET_default_pool);
   pool_initialized = TRUE;
 }
}

/* 
 * Memory pool cleanup  function
 */
extern void 
Finalize_Memset_Conversion()
{
 if(pool_initialized){
   MEM_POOL_Pop(&MEMSET_default_pool);
   MEM_POOL_Delete(&MEMSET_default_pool);  //memory to be cleaned
   pool_initialized = FALSE;
 }
}

/* 
 * Function which is called by lno optimizer for
 * array initialization to memset conversion. The
 * function is called for each function.
 */
extern int 
Replace_InitLoops_With_Memset(WN *func_nd)
{ 
  if (!LNO_Initialize_With_Memset) 
     return FALSE;

  // initialize the memory pool
  Initialize_Memset_Conversion();

  INT converted_loops = 0;
  STACK_OF_WN *inner_do_stack = CXX_NEW
          (STACK_OF_WN(&MEMSET_default_pool),&MEMSET_default_pool);
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
  // try to replace the loops with memset

  for(INT ii=0; ii<inner_do_stack->Elements(); ii++){
     WN *loop = inner_do_stack->Bottom_nth(ii);
     INT Src_Line_Num = Srcpos_To_Line(WN_Get_Linenum(loop));
     if(Do_InitLoopReplace_With_Memset(loop)){    
      converted_loops++;
     }
  }
  // cleanup the used memory pool

  Finalize_Memset_Conversion();
  return converted_loops;
}
