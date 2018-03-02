/*
 * Copyright (C) 2008-2011 Advanced Micro Devices, Inc.  All Rights Reserved.
 */

/*
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
*/

#include "cmov_conv.h"

CMOV_Converter :: CMOV_Converter():min_branch_prob_diff(0.5){
    Trace_CMOV = Get_Trace(TKIND_IR,TP_CMOVE);
}

CMOV_Converter :: ~CMOV_Converter(){
}

TOP CMOV_Converter::Determine_Cmov_From_Cond_Branch(TOP top,bool choose_fall) {
    if(!choose_fall){
	// if successor is branch target use the same condition as in branch instruction
        switch(top){
            case TOP_jae:return(TOP_cmovae);
   	    case TOP_jb:return(TOP_cmovb);
	    case TOP_jnp:return(TOP_cmovnp);
	    case TOP_jp:return(TOP_cmovp);
	    case TOP_jne:return(TOP_cmovne);
	    case TOP_je:return(TOP_cmove);
	    case TOP_ja:return(TOP_cmova);
	    case TOP_jbe:return(TOP_cmovbe);
	    case TOP_jge:return(TOP_cmovge);
	    case TOP_jl:return(TOP_cmovl);
	    case TOP_jg:return(TOP_cmovg);
	    case TOP_jle:return(TOP_cmovle);
	    case TOP_jns:return(TOP_cmovns);
	    case TOP_js:return(TOP_cmovs);
	    default:return(TOP_UNDEFINED);
        }
    }	
    else{
// if successor is fall thru use the inverted condition code of branch instruction
        switch(top){
            case TOP_jae:return(TOP_cmovb);
            case TOP_jb:return(TOP_cmovae);
            case TOP_jnp:return(TOP_cmovp);
            case TOP_jp:return(TOP_cmovnp);
            case TOP_jne:return(TOP_cmove);
            case TOP_je:return(TOP_cmovne);
            case TOP_ja:return(TOP_cmovbe);
            case TOP_jbe:return(TOP_cmova);
            case TOP_jge:return(TOP_cmovl);
            case TOP_jl:return(TOP_cmovge);
            case TOP_jg:return(TOP_cmovle);
            case TOP_jle:return(TOP_cmovg);
            case TOP_jns:return(TOP_cmovs);
            case TOP_js:return(TOP_cmovns);
	    default:return(TOP_UNDEFINED);
        }
    }	
}

convert_mode CMOV_Converter::Test_Criteria(BB *bb){
    bool choose_fall = false, choose_hammock = false;
    BB *fall_thru,*target;

    if(!Is_Parent_Suitable(bb))
        return NOCMOV;	
    
    fall_thru = BB_Fall_Thru_Successor(bb);
    // ijmpx instruction renders 2 successors to bb and undefined fall thru
    if(!fall_thru)	
        return NOCMOV;
    target = BB_Other_Successor(bb,fall_thru);

    BBLIST *bb_succs = BB_succs(bb);
    float target_prob = BBLIST_prob(BBlist_Find_BB(bb_succs,target));
    float fall_prob = BBLIST_prob(BBlist_Find_BB(bb_succs,fall_thru));
    if(abs(target_prob - fall_prob) >= min_branch_prob_diff)
        return NOCMOV;

    if(choose_fall = Is_Fall_Thru_Suitable(bb,fall_thru))
        return FALL_THRU; 
    else if(choose_hammock = Is_Hammock(bb,fall_thru,target))
        return HAMMOCK;  
    else   
        return NOCMOV;
}

bool CMOV_Converter::Is_Parent_Suitable(BB *bb){
  // parent should have only 2 successors
    if(BB_succs_len(bb) != 2)
        return false;
    if(BB_asm(bb)) 
        return false;
// bb is in cold region
    if(BB_Is_Cold(bb))
        return false;
    if(BB_handler(bb))
	return false;
    if(BB_Has_Exc_Label(bb)) 
	return false;
    if(BB_call(bb))
	return false;
// address to go to is computed at run time
    if(BB_last_OP_computes_got(bb) ||		
        BB_first_OP_computes_got(bb)){
        return false;
    }
      return true;
}

bool CMOV_Converter::Is_Fall_Thru_Suitable(BB *bb,BB *fall_thru){
    BB *uniq_pred_fall = BB_Unique_Predecessor(fall_thru);
  // Make sure fall thru can be reached only by parent bb
    if(!(uniq_pred_fall && uniq_pred_fall == bb))  
        return false;
  // Make sure fall thru has only moves
  // NOTE: first cut we are handling only reg moves
    OP* op_next = NULL; 
    for(OP* op = BB_first_op(fall_thru); op; op = op_next){
        op_next = OP_next(op);
        TOP opcode = OP_code(op);
        switch(opcode){
            case TOP_mov32:
            case TOP_mov64:continue;
	    default: return false;
        }
    }
    BB *uniq_succ_fall = BB_Unique_Successor(fall_thru);
    BB *target = BB_Other_Successor(bb,fall_thru);
    if(!(uniq_succ_fall && target && uniq_succ_fall == target))
        return false;		
    if(!(BB_preds_len(target) == 2 &&
	BB_Fall_Thru_Predecessor(target) == fall_thru &&
        BB_Other_Predecessor(target,fall_thru) == bb)){
	return false;
    }

/* We now know its a simple if pattern with reg movs convertible to cmovs, make further
 * checks to see that the cmovs can be safely mergerd with parent's instrutions
 */
    if(!Test_Merge_Criteria(bb,fall_thru))
	return false;
    if(!Test_Merge_Criteria(bb,target))
	return false;
    return true;
}

bool CMOV_Converter::Is_Hammock(BB *bb,BB *fall_thru,BB *target){
    BB *uniq_pred_fall = BB_Unique_Predecessor(fall_thru);
    BB *uniq_pred_target = BB_Unique_Predecessor(target) ;
  // Make sure target and fall thru can be reached only by parent bb
    if(!(uniq_pred_fall && uniq_pred_fall == bb))  
        return false;
    if(!(uniq_pred_target && uniq_pred_target == bb))  
	return false;
  // Make sure both fall thru and target reach the same block
    if(!(BB_succs_len(fall_thru) == 1 &&
       BB_succs_len(target) == 1 &&
       BB_Unique_Successor(fall_thru) == BB_Unique_Successor(target))){
        return false;		
    }

  // Make sure fall thru and branch target have only moves
  // NOTE: One of fall thru and branch target will have jmp to imm post dom
  // NOTE: first cut we are handling only reg moves
    OP* op_next = NULL; 
    for(OP* op = BB_first_op(fall_thru); op; op = op_next){
        op_next = OP_next(op);
        TOP opcode = OP_code(op);
        switch(opcode){ 
            case TOP_mov32:
            case TOP_mov64:continue;
	    case TOP_jmp:if(!op_next)continue;
	    default: return false;
        }
    }
    op_next = NULL; 
    for(OP* op = BB_first_op(target); op; op = op_next){
        op_next = OP_next(op);
        TOP opcode = OP_code(op);
        switch(opcode){
            case TOP_mov32:
            case TOP_mov64:continue;
	    case TOP_jmp:if(!op_next)continue;
	    default: return false;
        }
    }
/* We now know its a hammock with reg movs convertible to cmovs, make further
 * checks to see that the cmovs can be safely mergerd with parent's instrutions
 */
    if(!Test_Merge_Criteria(bb,fall_thru))
        return false;
    if(!Test_Merge_Criteria(bb,target))
	return false;
    return true;
}

bool CMOV_Converter::Test_Merge_Criteria(BB *bb,BB *succ){
  // Reject if BB has an asm.
    if(BB_asm(succ))
        return false;
    if( BB_kind(succ)== BBKIND_REGION_EXIT)
        return false;
  // Exit info wil be lost
    if(BB_exit(succ))
        return false;
  // Call annotations will be lost
    if(BB_call(succ))
        return false;
    if(BB_length(succ) == 0)
	return false;
    if(BB_handler(succ))
        return false;
  // Reject if suc has an exception label.
    if(BB_Has_Exc_Label(succ)) 
        return false;
  // Reject if crossing region boundaries.
    if(BB_rid(bb) != BB_rid(succ))
        return false;
  /* Reject if removing the succ would cause the RID of the region's
   * first BB to change.
   */
    if(succ == REGION_First_BB){
        BB *suc_next = BB_next(succ);
        if(suc_next && BB_rid(succ) != BB_rid(suc_next)){
    	    return false;
        }
    }
  // address to go to is computed at run time
    if (BB_first_OP_computes_got(succ) ||
    BB_last_OP_computes_got(succ)) {
        return false;
    }
    return true;
}

void CMOV_Converter::Convert_Movs_To_Cmovs(BB *bb,BB *succ,TOP new_cmov){
    OP* op_next = NULL;
    TOP old_op;
    for(OP* op = BB_first_op(succ); op; op = op_next){// for all ops in the chosen succ
        op_next = OP_next(op);
	old_op = OP_code(op);
	// if cond kept to skip the unconditional jmp instr
        if(old_op == TOP_mov64 || old_op ==TOP_mov32 ){ 
	     OPS *bb_ops =&((bb)->ops);
	     TN* src = OP_opnd(op,0);	
	     TN* res = OP_result(op,op->results-1);
	   // remove the mov from succ
	     BB_Remove_Op(succ,op); 
	   // build new cmov op,append to parent
	     Build_OP(new_cmov, res, src,Rflags_TN(),bb_ops); 
	     BB_last_op(bb)->bb = bb; 
	     BB_last_op(bb)->map_idx = BB_New_Op_Map_Idx(bb);
	     Set_OP_cond_def_kind(BB_last_op(bb), OP_ALWAYS_COND_DEF);
        }
    }
}
 
bool CMOV_Converter:: Merge_Hammock(BB *bb){
     OP* branch = BB_branch_op(bb);
     if(!branch)
         return false;
     TOP top = OP_code(branch);
     //determine opcode for cmov from the conditional branch in parent
     TOP fall_cmov = Determine_Cmov_From_Cond_Branch(top,true);
     TOP target_cmov = Determine_Cmov_From_Cond_Branch(top,false);
     if(fall_cmov == TOP_UNDEFINED)
         return false;
     if(target_cmov == TOP_UNDEFINED)
         return false; 

     BB *fall_thru = BB_Fall_Thru_Successor(bb);  
     BB *target = BB_Other_Successor(bb,fall_thru);
     BB *imm_post_dom = BB_Unique_Successor(fall_thru);
     FmtAssert(fall_thru,("BB parent doesnt have a fall thru"));
     FmtAssert(target,("BB parent doesnt have a branch target"));
     FmtAssert(imm_post_dom,("BB parent has no dominating block"));

     if(Trace_CMOV){ 
         Trace_BB(bb,"BB parent before change");
	 Trace_BB(fall_thru,"Fall Through before change");
	 Trace_BB(target,"Branch Target before change");
	 Trace_BB(imm_post_dom,"Imm Post dominator before change");
     }

     //remove movs from fall thru,append cmovs to parent
    Convert_Movs_To_Cmovs(bb,fall_thru,fall_cmov);
    //remove movs from target,append cmovs to parent
    Convert_Movs_To_Cmovs(bb,target,target_cmov);
    //remove the conditional branch from parent bb
    BB_Remove_Op(bb,branch);
    //find the jump to the immediate post dominator, append it
    if(BB_length(fall_thru) == 1)
        BB_Append_Op(bb,BB_last_op(fall_thru));	
    else if(BB_length(target) == 1)
 	BB_Append_Op(bb,BB_last_op(target));
    else 
        FmtAssert(false,("Neither br target or fall thru have jmp to imm dominator!"));
    Link_Pred_Succ_with_Prob(bb,imm_post_dom,1);

   //clean up (unlink bb's to update succ/pred list)
    Unlink_Pred_Succ(bb,target);
    Unlink_Pred_Succ(bb,fall_thru);
    Unlink_Pred_Succ(fall_thru,imm_post_dom);
    Unlink_Pred_Succ(target,imm_post_dom);

   //clean up(remove old branch target fall thru )
    Remove_BB(target);
    Remove_BB(fall_thru);
    if(Trace_CMOV){
        Trace_BB(bb,"BB parent after change");
        Trace_BB(imm_post_dom,"Imm post dominator after change");
    }
    return true;
}

bool CMOV_Converter:: Merge_Parent_Fall_Thru(BB *bb){
     OP* branch = BB_branch_op(bb);
     if(!branch)
         return false;
     TOP top = OP_code(branch);
     //determine opcode for cmov from the conditional branch in parent
     TOP new_cmov = Determine_Cmov_From_Cond_Branch(top,true);
     if(new_cmov == TOP_UNDEFINED)
          return false;

     BB *fall_thru = BB_Fall_Thru_Successor(bb);
     BB *target = BB_Other_Successor(bb,fall_thru);
     FmtAssert(fall_thru,("BB parent doesnt have a fall thru"));
     FmtAssert(target,("BB parent doesnt have a branch target"));

     if(Trace_CMOV){
         Trace_BB(bb,"BB parent before change");
	 Trace_BB(fall_thru,"Fall Through before change");
	 Trace_BB(target,"Branch Target before change");
     }	

   //remove movs from target,append cmovs to parent
    Convert_Movs_To_Cmovs(bb,fall_thru,new_cmov);
   //remove the conditional branch from parent bb
    BB_Remove_Op(bb,branch);
   //Append all the ops in the branch target to parent bb
    BB_Append_All(bb,target);

   //clean up (unlink bb's to update succ/pred list)
    Unlink_Pred_Succ(bb,target);
    Unlink_Pred_Succ(fall_thru,target);
    Unlink_Pred_Succ(bb,fall_thru);

   //Link the old branch target's successor's to parent bb
    BB *succ_succ;
    BBLIST *bl=BB_succs(target);    
    while (bl){
        succ_succ = bl->item;
	Link_Pred_Succ_with_Prob(bb,succ_succ,BBLIST_prob(bl));
   	bl = bl->next;
    }
  //unlink the old branch target from its successors
    int len = BB_succs_len(target);
    while (len--){
        bl=BB_succs(target);    
        succ_succ = bl->item;
	Unlink_Pred_Succ(target,succ_succ);
    }

   //clean up(remove old branch target and fall thru)
    Remove_BB(target);
    Remove_BB(fall_thru);
    if(Trace_CMOV){
        Trace_BB(bb,"BB parent after change");
    }
    return true;
}

int CMOV_Converter::cmov_convert(){
    BB *bb;
    int convert = NOCMOV;
    int num_jmps_eliminated = 0;
    bool did_convert = false;
        
    bb = REGION_First_BB;
    for(;bb;){	//for every bb in the region
          while(convert = Test_Criteria(bb)){ //Repeat as long as the bb qualifies 
					 // cmov conversion criteria
	     if(convert == HAMMOCK)	
	         did_convert = Merge_Hammock(bb);	
	     else if(convert == FALL_THRU)
	         did_convert = Merge_Parent_Fall_Thru(bb);
	// if merge failed, we need not check this bb's criteria again
	     if(!did_convert)
	         break;
             num_jmps_eliminated++;
          }
          bb = BB_next(bb);	
    }
    return num_jmps_eliminated;
}

static inline bool BB_last_OP_computes_got (BB* bb){
    OP *last_op = BB_last_op(bb);
    return ((last_op != NULL) && OP_computes_got(last_op));
}

static inline bool BB_first_OP_computes_got (BB* bb){
    OP *first_op = BB_first_op(bb);
    return ((first_op != NULL) && OP_computes_got(first_op));
}

