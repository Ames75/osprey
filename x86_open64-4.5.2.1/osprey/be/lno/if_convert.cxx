/*
 * Copyright (C) 2008-2012 Advanced Micro Devices, Inc.  All Rights Reserved.
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
#include "if_convert.h"

MEM_POOL If_Convert_pool;
static BOOL If_Convert_mempool_initialized = FALSE;
static void If_Convert_Walk_Helper(WN* ,If_Conversion *);

extern void If_Convert_Walk(WN *wn){
    if (!If_Convert_mempool_initialized) {
        MEM_POOL_Initialize(&If_Convert_pool, "If_Convert_pool", FALSE);
        If_Convert_mempool_initialized = TRUE;
    }
    MEM_POOL_Push(&If_Convert_pool);
    If_Conversion *conv_obj = CXX_NEW(If_Conversion(&If_Convert_pool),&If_Convert_pool);
    LWN_Parentize(wn);
    If_Convert_Walk_Helper(wn,conv_obj);
    FmtAssert(LWN_Check_Parentize(wn),("If Convert:Parentize went wrong"));
    FmtAssert(Du_Mgr->Verify(),("If Convert:DU Chain Update went wrong"));
    MEM_POOL_Pop(&If_Convert_pool);
    MEM_POOL_Delete(&If_Convert_pool);
    If_Convert_mempool_initialized = FALSE;
}

/* Walk through the pu's whirl nodes  looking for a suitable candidate for if conversion
 * A simple if within a loop body is chosen for if conversion
 */  
static void If_Convert_Walk_Helper(WN* wn,If_Conversion *conv_obj) {
    if(OPCODE_is_leaf(WN_opcode(wn))){
        return;
    }  
    else if(WN_operator(wn) == OPR_IF && conv_obj->If_Convertible(wn)){
        WN *parent = LWN_Get_Parent(wn);
        WN *grand_parent;
        if(parent != NULL){
            grand_parent = LWN_Get_Parent(parent);
           if(grand_parent != NULL && (WN_operator(grand_parent) == OPR_DO_LOOP ||
                  WN_operator(grand_parent) == OPR_DO_WHILE ||
                  WN_operator(grand_parent) == OPR_WHILE_DO)){
              conv_obj->If_Convert(wn);
           }
        }   
        return;
    }
    else if(WN_operator(wn) == OPR_BLOCK){ 
        WN *wn_temp = WN_first(wn);
        while(wn_temp) {
            If_Convert_Walk_Helper(wn_temp,conv_obj);
            wn_temp = WN_next(wn_temp);
        } 
    }  
    else {
        for(INT kidno=0;kidno<WN_kid_count(wn);kidno++){  
            If_Convert_Walk_Helper(WN_kid(wn,kidno),conv_obj); 
        }
    }    
}
/* Walk through the if's body checking criteria for if conversion
 * A simple if with assignment statements is chosen for if conversion
 */
bool
If_Conversion::If_Convertible(WN *wn){

    FmtAssert(WN_operator(wn) == OPR_IF, ("If_Convert:Not an if"));
    WN *then_wn = WN_then(wn);
    WN *else_wn = WN_else(wn);
    BOOL empty_then = !then_wn || !WN_first(then_wn);
    BOOL empty_else = !else_wn || !WN_first(else_wn);
  
    if(empty_then || !empty_else)
        return false;    

    LWN_ITER* itr = LWN_WALK_StmtIter(then_wn);
    itr = LWN_WALK_StmtNext(itr);
    for (; itr != NULL; itr = LWN_WALK_StmtNext(itr)) {
        WN *wn_temp = itr->wn; 
        if(!(OPERATOR_is_store(WN_operator(wn_temp)) && If_Convertible_Store(wn_temp))){
           return false;   
        }    
    } 
    return true;
}
// Check the assignments statements within the if body are suitable for if conversion
bool
If_Conversion::If_Convertible_Store(WN *wn){
    if (WN_operator(wn) == OPR_MSTORE)
      return false;

    if (WN_operator(wn) == OPR_STBITS || WN_operator(wn)== OPR_ISTBITS) {
        return false;
    }

    if (WN_operator(wn) == OPR_STID ) {
        if (TY_is_volatile(WN_ty(wn)))
          return false;
        if (ST_sclass(WN_st_idx(wn)) == SCLASS_FORMAL_REF)
          return false;    
        MTYPE dsctyp = WN_desc(wn);
        if (dsctyp == MTYPE_M || dsctyp == MTYPE_BS || MTYPE_is_float(dsctyp)) {
            // don't generate select for MTYPE_M because there is no register for
            // MTYPE_M
            // don't generate select for float stores,as there are no float cmovs
          return false;
        }
    }
    
    return(If_Convertible_Store_Rhs(WN_kid0(wn)));
}
/* unconditionally executing a division operation  within the if may result in
 * division by zero faults, avoid if converting such simple ifs
 */
bool
If_Conversion::If_Convertible_Store_Rhs(WN *wn) {

    OPERATOR opr = WN_operator(wn);
    if(opr == OPR_ILOAD || opr == OPR_DIV)
        return false;
    if(!OPERATOR_is_leaf(WN_operator(wn))){
        for (INT kidno = 0; kidno < WN_kid_count(wn); kidno++)
        {
            WN* kid = WN_kid(wn, kidno);
            if(!If_Convertible_Store_Rhs(kid))
                return false;
        }
    }  
  return true;
}

/* Main module that performs if conversion
 *        if(cond){                     
 *         x = x - y;        -->        x = SELECT(cond,x-y,x);   
 *        }
 *        if(cond){
 *        *p = x - y;       -->       *(SELECT(cond,p,dummy_var)) = x - y;     
 *        }
 */  

void 
If_Conversion::If_Convert(WN *wn){

    FmtAssert(WN_operator(wn) == OPR_IF, ("If_Convert:Not an if"));

    WN *then_wn = WN_then(wn);
    WN *else_wn = WN_else(wn);
    BOOL empty_then = !then_wn || !WN_first(then_wn);
    BOOL empty_else = !else_wn || !WN_first(else_wn);
    FmtAssert(!empty_then,("If_Convert:then block is empty,what to if-convert?!"));
    FmtAssert(empty_else,("If_Convert:else block is non empty,we handle only simple-if's"));
    
    WN *parent_block = LWN_Get_Parent(wn);
    FmtAssert(WN_operator(parent_block) == OPR_BLOCK,
            ("If_Convert:parent of if not a block"));
    WN *if_test = WN_if_test(wn);
   
    if (LNO_Verbose) {
        printf("If Conversion Candidate found at (%s:%d)...\n", 
  	   Src_File_Name, 
  	   Srcpos_To_Line(WN_Get_Linenum(wn)));
    }  
    SYMBOL if_cond = Create_Preg_Symbol("if_cond",WN_rtype(if_test));
    WN *copy_if_test = LWN_Copy_Tree(if_test);
    LWN_Copy_Def_Use(if_test,copy_if_test,Du_Mgr);
    WN *cond_stid = WN_StidIntoPreg(if_cond.Type,
                      if_cond.WN_Offset(),if_cond.St(),
                        copy_if_test);
    Create_alias(Alias_Mgr, cond_stid);
    WN *cond_ldid = WN_LdidPreg(if_cond.Type,
                      if_cond.WN_Offset());
    Create_alias(Alias_Mgr, cond_ldid);
    LWN_Insert_Block_Before(parent_block,wn,cond_stid);
    
    WN *stmt = WN_first(then_wn);  
    WN *stmt_next = NULL;    
   
    while(stmt){
        stmt_next = WN_next(stmt);
            
        WN *copy_cond_ldid = LWN_Copy_Tree(cond_ldid);
        LWN_Copy_Def_Use(cond_ldid,copy_cond_ldid,Du_Mgr);
        Du_Mgr->Add_Def_Use(cond_stid,copy_cond_ldid);
        /* Convert an unsafe istore to a safe istore
         * ISTORE(rhs_store,addr_store) -->  
         * ISTORE(rhs_store,SELECT(cond,addr_store,LDA(dummy_var)))
         * Call Convert_To_Safe_Expr on  addr_store which will
         * replace all occurences of unsafe iloads within their whirl trees to safe iloads
         * by converting a ILOAD(addr) to ILOAD(SELECT(cond,addr,LDA(dummy_var)))
         */
        if(WN_operator(stmt) == OPR_ISTORE || WN_operator(stmt) == OPR_ISTBITS){
            WN *rhs_store = WN_kid0(stmt); 
            WN *addr_store = WN_kid1(stmt);
            TYPE_ID addr_type = WN_rtype(addr_store);
        /* Look up the dummy variable map for the PU,
         * to see if a dummy var of the istore's addr type is already created 
         * if not found create a dummy_var of istore's addr type for the PU 
         */
            SYMBOL *dummy_var = FindDummyVarInMap(addr_type);
            if(!dummy_var){
                CreateDummyVarInMap(addr_type);
                dummy_var = FindDummyVarInMap(addr_type);
                FmtAssert(dummy_var,
               ("Compiler Internal Error: If_Conversion temporary variable creation error"));
             }
        /* NOTE: while generating LDA of the dummy_var,
         *  we set the LDA offset to -ve offset of ISTORE stmt so that,
         *  we store to the right addr of dummy_var in case the cond was false     
         */  
            WN *dummy_lda=WN_CreateLda(OPCODE_make_op(OPR_LDA,Pointer_type,MTYPE_V),
                              -WN_offset(stmt),WN_ty(stmt),ST_st_idx(dummy_var->St()));
  
            WN *sel = WN_Select(addr_type,copy_cond_ldid,
                        Convert_To_Safe_Expr(addr_store,cond_ldid,cond_stid),dummy_lda);
            WN_kid1(stmt) = sel;
        } 
        /* STIDs are safe operations,they can be unconditionally executed,
         * however the original value of the ST*  has to be retained if 
         * condition was not taken
         *      (rhs_store)     -->             cond
         *    STID <st x>                      (rhs_store)            
         *                                      LDID <st x>
         *                                     SELECT 
         *                                    STID <st x>       
         */
        else {
            WN *rhs_store = WN_kid0(stmt); 
            TYPE_ID dsctyp = WN_desc(stmt);
            WN *load = LWN_CreateLdid(OPCODE_make_op(OPR_LDID,Mtype_comparison(dsctyp),
                        dsctyp),stmt);
            Du_Mgr->Add_Def_Use(stmt,load);
            WN *sel = WN_Select(Mtype_comparison(dsctyp),copy_cond_ldid,rhs_store,load);
            WN_kid0(stmt) = sel;
        }    
     
        LWN_Extract_From_Block(then_wn,stmt);
        LWN_Insert_Block_Before(parent_block,wn,stmt);
        stmt = stmt_next;
    }

    LWN_Update_Def_Use_Delete_Tree(wn);
    LWN_Delete_Tree(wn);
    LWN_Parentize(parent_block);
    
    if (LNO_Verbose) {
      printf(" If Converted\n"); 
    }  
}
/* Walk through the whirl tree of the input expr looking for iloads
 * convert all unsafe iloads to safe iloads by generating a
 * SELECT btw addr of dummy_var and iloads original addr expr
 * ILOAD(addr)  --> ILOAD(SELECT(cond,addr,LDA(dummy_var)))
 */
WN*
If_Conversion::
Convert_To_Safe_Expr(WN *expr,WN *cond_ldid,WN *cond_stid){
    
    if(OPCODE_is_leaf(WN_opcode(expr)))
        return expr;

    else if(WN_operator(expr) == OPR_ILOAD){
        TYPE_ID dummy_type = WN_rtype(WN_kid0(expr));
        /* Look up the dummy variable map for the PU,
         * to see if a dummy var of the iload's addr type is already created 
         * if not found create a dummy_var of iload's addr type for the PU
         */
        SYMBOL *dummy_var = FindDummyVarInMap(dummy_type);
        if(!dummy_var){
            CreateDummyVarInMap(dummy_type);
            dummy_var = FindDummyVarInMap(dummy_type);
            FmtAssert(dummy_var,
            ("Compiler Internal Error: If_Conversion temporary variable creation error"));
        }
        WN *dummy_lda=WN_CreateLda(OPCODE_make_op(OPR_LDA,Pointer_type,MTYPE_V),
                        -WN_load_offset(expr),WN_load_addr_ty(expr),
                        ST_st_idx(dummy_var->St()));
        WN *copy_cond_ldid = LWN_Copy_Tree(cond_ldid);
        LWN_Copy_Def_Use(cond_ldid,copy_cond_ldid,Du_Mgr);
        Du_Mgr->Add_Def_Use(cond_stid,copy_cond_ldid);
        WN *sel = WN_Select(dummy_type,copy_cond_ldid,
                    Convert_To_Safe_Expr(WN_kid0(expr),cond_ldid,cond_stid),
                      dummy_lda);
        WN_kid0(expr) = sel;
        return expr;
    }    
    else{
        for(INT kidno=0;kidno<WN_kid_count(expr);kidno++){  
            WN_kid(expr,kidno) = 
            Convert_To_Safe_Expr(WN_kid(expr,kidno),cond_ldid,cond_stid); 
        }
        return expr;
    }
}   
