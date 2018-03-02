// ====================================================================
//
// Copyright (C) 2010, Hewlett-Packard Development Company, L.P.
// All Rights Reserved.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of version 2 of the GNU General Public License as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it would be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//
// Further, this software is distributed without any warranty that it
// is free of the rightful claim of any third person regarding
// infringement  or the like.  Any license provided herein, whether
// implied or otherwise, applies only to this software file.  Patent
// licenses, if any, provided herein do not apply to combinations of
// this program with other software, or any other product whatsoever.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write the Free Software Foundation,
// Inc., 59 Temple Place - Suite 330, Boston MA 02111-1307, USA.
//
// ====================================================================
// Module: slp_early_exit.cxx
//
// Description:
// This file is a collection of the support methods for Early Exits in
// in SLP. The top-level method in this file is vectorize_SwitchBrRet(),
// where it packs scalar operands in the scalar Early Exits intrinsics
// and replace the packs with vector operands if they are available.
// When the operands are vectorized, it also replaces the scalar
// intrinsics with the vector counterparts.
// 
// ====================================================================

#include "slp.h"

using namespace slp;

// a collection of Early-Exit supporting routines

// --------------------------------------------------------------------
// SwitchBranch and SwitchReturn:
// --------------------------------------------------------------------

bool Transform::is_SwitchBrRet(Statement_ID id){
  WN* wn = stmts[id]->whirl_node();
  return WN_is_SwitchReturn(wn) || WN_is_SwitchBranch(wn);
}





void Transform::vectorize_SwitchBrRet(Statement_ID id)
{
  // Do not vectorize if the statement has multiple typesizes.
  if (stmts[id]->typesize() == 0) {
    gen_scalar_statement(id);
    return;
  }

  SwitchBrRet s_br(stmts[id], SIMD_register_width, wssa, sym_packs, 
		   _TraceKind);
  s_br.pack_operands();

  WN* switch_bret = s_br.wn();
  int num_vectors = s_br.num_vectors();
  int total_lanes = 0;
  for (int i=0; i<num_vectors; i++){
    WN* cond_def = make_LDID(s_br.ith_cond_vsym(i), wssa);
    int num_lanes= s_br.ith_num_lanes(i);

    if (s_br.is_switch_ret()){
      WN* ret_def  = make_LDID(s_br.ith_ret_vsym(i), wssa);
      insert_VSwitchReturn(cond_def, ret_def, num_lanes);
    }
    else
      insert_VSwitchBranch(switch_bret, cond_def, total_lanes, num_lanes);
    total_lanes += num_lanes;
  }

  // if not vectorized at all, just move it
  if (s_br.is_none_vectorized()) gen_scalar_statement(id);
  // if all are vectorized, just delete it
  else if (s_br.is_fully_vectorized()) trash_bin.push_back(switch_bret);
  // if partially vectorized, adjust the remaining scalar SwitchBrRet
  else {
    if (s_br.is_switch_ret())
      adjust_SwitchRet(s_br.num_vec_srcs(), switch_bret);
    else
      adjust_SwitchBr(s_br.num_vec_srcs(), switch_bret);
    gen_scalar_statement(id);
  }
}






// 'count' is necessary for partial vector lanes when 'VSwitchBrRet' 
// is lowered. For example, if the vector argument is used in 'movemask',
// the 32-bit result should be filtered with this 'count' infomation.
void Transform::insert_VSwitchReturn(WN* cond_def, WN* ret_def, int count)
{
  WN* cond = make_LDID(cond_def, wssa);
  WN* ret  = make_LDID(ret_def, wssa);
  WN* num_ele = WN_CreateIntconst(OPR_INTCONST, MTYPE_I4, MTYPE_V, count);
  TY_IDX ty_idx_I4 = ST_type(MTYPE_To_PREG(MTYPE_I4));

  WN* kid[3];
  kid[0] = WN_CreateParm(WN_rtype(cond), cond, WN_ty(cond_def), 
			 WN_PARM_BY_VALUE);
  kid[1] = WN_CreateParm(WN_rtype(ret), ret, WN_ty(ret_def), 
			 WN_PARM_BY_VALUE);
  kid[2] = WN_CreateParm(MTYPE_I4, num_ele, ty_idx_I4, WN_PARM_BY_VALUE);
  WN* vswitch_ret = WN_Create_Intrinsic(OPR_INTRINSIC_CALL, MTYPE_V, 
			       MTYPE_V, INTRN_VSWITCH_RETURN, 3, kid);
  WN_insert(vswitch_ret);
}






// Generate a vector SwitchBranch for a scalar switch branch 'switch_br'
// and a vector condition variable 'cond_def'
void Transform::insert_VSwitchBranch(WN* switch_br, WN* cond_def, 
				     int from, int count)
{
  WN* vswitch_br = WN_COPY_Tree(switch_br);
  int num_entries = WN_num_entries(switch_br);

  // kid0: FIRST_TRUE_INDEX
  WN_DELETE_Tree(WN_kid0(vswitch_br));
  WN* kid[1];
  kid[0] = WN_CreateParm(WN_rtype(cond_def), cond_def, WN_ty(cond_def), 
			 WN_PARM_BY_VALUE);
  WN_kid0(vswitch_br) = WN_Create_Intrinsic(OPR_INTRINSIC_OP, MTYPE_I1, 
					    MTYPE_V, INTRN_VEC_FIRST_TRUE_INDEX, 
					    1, kid);

  // kid1: GOTOs
  WN* blk = WN_kid1(vswitch_br);
  WN* goto_stmt = WN_first(blk);
  for (int i=0; i<from; i++) {
    WN_DELETE_FromBlock(blk, goto_stmt);
    goto_stmt = WN_next(goto_stmt);
  }
  for (int i=0; i<count; i++) goto_stmt = WN_next(goto_stmt);
  bool next_SwitchBr = goto_stmt ? true : false;
  while (goto_stmt) {
    WN* temp = WN_next(goto_stmt);
    WN_DELETE_FromBlock(blk, goto_stmt);
    goto_stmt = temp;
  }
  WN_num_entries(vswitch_br) = count;

  // kid2: default label
  WN* dflt_label = NULL;
  if (next_SwitchBr) {
    LABEL_IDX label_idx;
    New_LABEL(CURRENT_SYMTAB, label_idx);
    dflt_label = WN_CreateLabel(label_idx, 0, NULL);
    WN* dflt_goto = WN_CreateGoto((ST_IDX)NULL, WN_label_number(dflt_label));
    WN_kid2(vswitch_br) = dflt_goto;
  }

  WN_insert(vswitch_br);
  if (next_SwitchBr) WN_insert(dflt_label);
}




// The first 'from' kids of the given scalar 'switch_br' is deleted
// (because they are previously vectorized into Vector Switch Branches),
// and the remaining kids are pulled up to the front in kids' positions.
void Transform::adjust_SwitchBr(int from, WN* switch_br)
{
  WN* intrn = WN_kid0(switch_br);
  int num_srcs = WN_kid_count(intrn);

  WN* blk = WN_kid1(switch_br);
  WN* goto_stmt = WN_first(blk);

  for (int i=0; i<from; i++) {
    WN_DELETE_Tree(WN_kid(intrn, i));

    Is_True(WN_operator(goto_stmt) == OPR_GOTO, ("not goto stmt"));
    WN* temp = WN_next(goto_stmt);
    WN_DELETE_FromBlock(blk, goto_stmt);
    goto_stmt = temp;
  }

  for (int i=from; i<num_srcs; i++)
    WN_kid(intrn, i-from) = WN_kid(intrn, i);

  WN_set_kid_count(switch_br, num_srcs-from);
  WN_num_entries(switch_br) = num_srcs-from;
}





// The first 'from' kids of the given scalar 'switch_ret' is deleted
// (because they are previously vectorized into Vector Switch Returns),
// and the remaining kids are pulled up to the front in kids' positions.
void Transform::adjust_SwitchRet(int from, WN* switch_ret)
{
  int num_srcs = WN_kid_count(switch_ret);

  for (int i=0; i<from; i++)
    WN_DELETE_Tree(WN_kid(switch_ret, i));

  for (int i=from; i<num_srcs; i++)
    WN_kid(WN_kid0(switch_ret), i-from) = WN_kid(WN_kid0(switch_ret), i);

  WN_set_kid_count(switch_ret, num_srcs-from);
}





WN* Transform::find_first_SwitchBrRet()
{
  WN* the_first = WN_prev(last_stmt);

  while(WN_is_Early_Exits(the_first))
    the_first = WN_prev(the_first);

  return WN_next(the_first);
}




