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
// Module: slp_transform.cxx
//
// Description:
// Transform is an abstraction of all code transformations in the SLP
// vectorization. Before this, no code transformations are performed
// and the original code remains intact. Thus, a profitability model
// (which is not implemented in this implementation) can be implemented 
// immediately before Transform. 
// Transform::transform() is the top level method and goes through
// the given schedule in order. If the statement is packed, a SIMD
// statement is scheduled by changing the types and replacing the 
// packs of scalar operands with the corresponding vector operands
// in gen_SIMD_statement(). Otherwise, the scalar statement is 
// scheduled as is in gen_scalar_statement(). Early Exit constructs
// are vectorized in vectorize_SwitchBrRet().
// ====================================================================

#include "slp.h"

using namespace slp;

Transform::Transform(WN_CFG*                  curr_cfg, 
		     WN_CFG::BB_NODE*         nd,
		     WHIRL_SSA_MANAGER*       wssa_mgr,
		     WSSA_DU_MANAGER*         wssa_du_mgr,
		     std::vector<Statement*>& st, 
		     Scheduler&               sc,
		     MEM_POOL*                mpool,
		     WSSA_UPDATER&            updater,
		     int                      simd_width,
		     TRACE_OPTION_KIND        trace_kind,
		     bool                     early_exit) : 
  cfg(curr_cfg), bb_node(nd), wssa(wssa_mgr), slp_du_mgr(wssa_du_mgr), 
  stmts(st), sched(sc), slp_mem_pool(mpool), wssa_updater(updater), 
  SIMD_register_width(simd_width), _TraceKind(trace_kind), 
  _early_exit(early_exit)

{
  block     = cfg->Get_parent_block(stmts[0]->whirl_node());
  last_stmt = &(*bb_node->Stmt_rbegin());
}





Transform::~Transform()
{
}




// --------------------------------------------------------------------
// high-level routines
// --------------------------------------------------------------------

void Transform::transform() 
{
  bool is_vectorized = false;
  std::list<Statement_ID>::iterator i = sched.begin();
  for (; i != sched.end(); i++){
    Statement_ID id = *i;

    // for early-exits...
    if (is_SwitchBrRet(id)) {
      vectorize_SwitchBrRet(id);
      continue;
    }

    // scalar statements
    if (!sched.is_packed(id)){
      gen_scalar_statement(id);
      continue;
    }

    // vector statements
    is_vectorized = true;
    gen_SIMD_statement(sched.get_pack(id));
  }
  unpack_live_variables();

  empty_trash_bin();
  if (is_vectorized) wssa->Set_stat(STAT_INIT);
}





// copy a scalar statement which cannot be vectorized
void Transform::gen_scalar_statement(Statement_ID sid) 
{
  WN* stmt_wn = stmts[sid]->whirl_node();
  unpack_packed_srcs(stmt_wn);

  // do not move the last statement in the basic block
  if (stmt_wn == last_stmt) return;

  if (WN_operator(stmt_wn) == OPR_LABEL){
    Is_True(sid == 0, ("Transform::gen_scalar_statement: unexpected non-first LABEL"));
    return;
  }

  wssa_updater.Extract_stmt(block, stmt_wn);
  WN_insert(stmt_wn);
}




// for a vectorizable pack of scalar statements, 
// - turn the first one into a vector and
// - delete the others
void Transform::gen_SIMD_statement(Statement_Pack* pack) 
{
  // collect scalar source and destination operands
  int pack_size    = pack->size();
  WN* first_stmt   = stmts[pack->first()]->whirl_node();
  int num_operands = WN_count_versions_constants(first_stmt);

  std::vector<Symbol_Pack> operand_packs(num_operands);
  if (num_operands > 0) {
    pack_operands(operand_packs, pack);

    // generate 'pack' statements that move scalar operands into a vector 
    // operand so that it can be used in this vector statement
    gen_PACK_statements(operand_packs); 
  
    // print the current imformation for debugging
    if (_TraceKind >= TRACE_maximal) 
      print_stmt_sym_pack(pack, operand_packs);
  }

  // turn the first scalar statement into a vector statement
  transform_to_SIMD(first_stmt, operand_packs, pack);

  // put the remaining scalar statements into the trash bin
  trash_the_rest(pack);
}






// Those scalar variables live at the end of the basic block have to
// be unpacked if they are packed and defined.
void Transform::unpack_live_variables() 
{
  // unpacking of live ones on exit should be inserted before 
  // the first SwitchBrRet. So, update the insertion point
  if (_early_exit) last_stmt = find_first_SwitchBrRet();

  std::set<Symbol_Pack*, lt_sym_pack>::iterator i = sym_packs.begin();
  for (; i != sym_packs.end(); i++){
    Symbol_Pack* sym_pack = *i;
    // packed uses need not be unpacked
    if (!sym_pack->is_modified()) continue;

    // contiguous STIDs need not be unpacked
    if (sym_pack->are_contiguous_STIDs()) continue;

    if (_TraceKind >= TRACE_maximal) {
      fprintf(TFile, "Transform::unpack_live_variables: modified: ");
      sym_pack->print_long(wssa, this); fprintf(TFile, "\n");
    }

    for (int j=0; j<sym_pack->size(); j++){
      VER_IDX vidx = sym_pack->i_th(j);
      WN* use_block=NULL, *use=NULL;
      if (!is_live_on_exit(vidx, use_block, use)) continue;
      if (!is_only_in_packed_form(vidx))          continue;
      if (_TraceKind >= TRACE_maximal)
	fprintf(TFile, "Transform::unpack_live_variables: %d is live on exit.\n", vidx);
      gen_an_UNPACK_intrinsic(vidx, use_block, use);
    }
  }

}






// --------------------------------------------------------------------
// low-level routines
// --------------------------------------------------------------------


// convert the given scalar statement 'wn' into a vector statement
// by replacing the operands
void Transform::transform_to_SIMD(WN* wn, 
				  std::vector<Symbol_Pack>& operand_packs,
				  Statement_Pack* stmt_pack)
{
  TYPE_ID scalar_type = MTYPE_UNKNOWN;
  if (WN_operator(wn) == OPR_ISTORE) 
    scalar_type = WN_rtype(WN_kid0(wn));

  // vectorize the internal nodes
  int j_th_operand = WN_def_ver(wn)?1:0;
  for (int i=0; i<WN_kid_count(wn); i++)
    if (!WN_is_address_operand(wn, i)) {// don't vectorize address symbols
      transform_to_SIMD_operand(wn, i, WN_kid(wn, i), 
				operand_packs, j_th_operand);
      // change the type for internal nodes.
      transform_to_SIMD_operator(WN_kid(wn, i));
    }

  // for vector compares, generate intrinsics
  // (CG should be extended to nullify this.)
  if (WN_has_INT_CMP(wn)) gen_compare_intrinsics(wn, NULL, 0);

  if (WN_def_ver(wn))
    // if wn defines a symbol (STID), vectorize it
    transform_to_SIMD_STID(wn, operand_packs[0]);
  else
    // otherwise (ISTORE), just move it
    transform_to_SIMD_ISTORE(wn, stmt_pack, scalar_type);
}







// CG currently does not generate proper SIMD instructions for 
// vector typed operations. Thus, transform to SIMD intrinsics here.
void Transform::gen_compare_intrinsics(WN* wn, WN* parent, int ith)
{
  if (!wn) return;

  for (int i=0; i<WN_kid_count(wn); i++)
    if (!WN_is_address_operand(wn, i)) // don't search address operands
      gen_compare_intrinsics(WN_kid(wn, i), wn, i);

  if (is_comparison_op(WN_operator(wn)) && MTYPE_is_integral(WN_rtype(wn))) 
    transform_to_SIMD_compares(wn, parent, ith);
}






// convert the given scalar STID 'wn' into a vector statement
// by replacing the operands
void Transform::transform_to_SIMD_STID(WN* wn, Symbol_Pack& sym_pack)
{
  Is_True(WN_operator(wn)==OPR_STID, 
	  ("Transform::transform_to_SIMD: STID is expected"));

  // This is to convert vector comparison results from -1's to 1's
  // when extracted into scalar variable. This should be fixed if 
  // conditional operators are vectorized in an internal node.
  if (is_comparison_op(WN_operator(WN_kid0(wn))))
    sym_pack.set_conditional();

  // For STIDs that store into memory directly, just change types
  if (sym_pack.are_contiguous_STIDs()){
    transform_to_SIMD_operator(wn);
    if (wn != last_stmt) {
      wssa_updater.Extract_stmt(block, wn);
      WN_insert(wn);
    }
    return;
  }

  TYPE_ID vector_type = WN_get_vector_type(wn);
  PREG_NUM vpreg_num = Create_Preg(vector_type, "_slp_");
  WN* value = WN_COPY_Tree(WN_kid0(wn));
  WN* new_stid = WN_StidIntoPreg(vector_type, vpreg_num, 
				 MTYPE_To_PREG(vector_type), value);
  wssa->Copy_tree_ssa(new_stid, wn);
  WN_insert(new_stid);

  // 'modified' is set from pack_operands_stmt
  Is_True(sym_pack.is_modified(), 
	  ("Transform::transform_to_SIMD: def_ver(T) vs. is_modified(F)"));
  // generate a Symbol_Pack for the pseudo register being defined
  Symbol_Pack* new_sym_pack = CXX_NEW(Symbol_Pack(sym_pack), slp_mem_pool);
  new_sym_pack->set_def(new_stid);
  set_only_in_packed_form(new_sym_pack);
  sym_packs.insert(new_sym_pack);
  trash_bin.push_back(wn);
}







// convert the given scalar ISTORE into a vector statement
// by replacing the operands
void Transform::transform_to_SIMD_ISTORE(WN* wn, Statement_Pack* stmt_pack,
					 TYPE_ID scalar_type)
{
  const OPERATOR op = WN_operator(wn);
  Is_True(op == OPR_ISTORE, 
	  ("Transform::transform_to_SIMD: unexpected operator: %d", op));

  if (is_full_pack(stmt_pack)){
    if (wn != last_stmt){
      wssa_updater.Extract_stmt(block, wn);
      WN_insert(wn);
    }

    TYPE_ID desc_type = WN_desc(wn);  // type of the object being stored
    WN_set_desc(wn, get_vector_type(desc_type));
  }

  // for partial stores, 
  else{
    // use the UNPACK intrinsics for partial memory stores
    for (int i=0; i<stmt_pack->size(); i++){
      unpack_to_memory(wn, i, scalar_type);
    }
    trash_bin.push_back(wn);
  }
}






// finds and converts the given scalar operand 'wn' into a vector operand
void 
Transform::transform_to_SIMD_operand(WN* parent, int i_th_kid, WN* wn, 
				     std::vector<Symbol_Pack>& operand_packs,
				     int& j_th_operand)
{
  if(!wn) return;

  // for leaf nodes such as LDID, replace a pack of scalar symbols
  // with a vector symbol.
  if (WN_use_ver(wn) || WN_is_constant_expr(wn)) {
    Symbol_Pack* pck = &operand_packs[j_th_operand++];

    // if the pack consists of contiguous LDIDs from memory, do nothing yet
    if (pck->are_contiguous_LDIDs()) return;

    // otherwise, there must be a SIMD operand ready for use
    std::set<Symbol_Pack*, lt_sym_pack>::iterator iter = sym_packs.find(pck);
    Is_True(iter!=sym_packs.end(), 
	    ("Transform::transform_to_SIMD_operand: sym_pack not found."));
    Symbol_Pack* sym_pack = *iter;
    Is_True(*sym_pack==operand_packs[j_th_operand-1], ("transform_to_SIMD_operand: different sym_pack's"));
    WN* def = sym_pack->definition();
    Is_True(def!=NULL, ("Transform::transform_to_SIMD_operand: no def found."));
    WN_kid(parent, i_th_kid) = make_LDID(def, wssa);
    return;
  }

  // do the same for the kids
  for (int i=0; i<WN_kid_count(wn); i++)
    if (!WN_is_address_operand(wn, i)) // don't vectorize address symbols
      transform_to_SIMD_operand(wn, i, WN_kid(wn, i), 
				operand_packs, j_th_operand);
}







// finds and converts the type of 'wn' from scalar to vector
void Transform::transform_to_SIMD_operator(WN* wn)
{
  if (!wn) return;

  // do it for the kids before the current node
  for (int i=0; i<WN_kid_count(wn); i++)
    if (!WN_is_address_operand(wn, i)) // not for address symbols
      transform_to_SIMD_operator(WN_kid(wn, i));

  TYPE_ID vec_type = WN_get_vector_type(wn);
  OPERATOR opr     = WN_operator(wn);
  if (!has_void_desc(opr)) WN_set_desc (wn, vec_type);
  if (opr != OPR_STID) {
    if (is_comparison_op(opr)){
      vec_type = get_vector_comparison_type(vec_type);
    }
    WN_set_rtype(wn, vec_type);
  }
  WN_set_ty   (wn, MTYPE_To_TY(vec_type));
}






  
// generate 'pack' statements for the source operands that are not yet packed
void Transform::gen_PACK_statements(std::vector<Symbol_Pack>& operand_packs)
{
  int num_operands = operand_packs.size();
  int pack_size    = operand_packs[0].size();
  Is_True(pack_size>0, ("Transform::gen_PACK_statements: zero pack size"));

  for (int i=0; i<num_operands; i++){
    Symbol_Pack& sym_pack = operand_packs[i];

    // do not generate a 'pack' statement for destination operands
    if (sym_pack.is_modified()) continue;

    if (_TraceKind >= TRACE_maximal) {
      print_current_sym_packs();
      sym_pack.print_long(wssa, this);
    }

    // generate a PACK if the operands are not already packed
    if (sym_packs.find(&sym_pack) == sym_packs.end()){
      if (_TraceKind >= TRACE_maximal) fprintf(TFile, " ---> Not found\n");
      
      if (!sym_pack.are_contiguous_LDIDs())
	gen_a_PACK_statement(sym_pack);
    }
    else
      if (_TraceKind >= TRACE_maximal) fprintf(TFile, " ---> found\n");
  }
}





  
  
// generate a 'pack' statement for the given pack of scalar symbols
// A 'pack' statement consists of several intrinsics that together
// perform as one 'pack' statement.
void Transform::gen_a_PACK_statement(Symbol_Pack& sym_pack)
{
  // find a vector type
  TYPE_ID scalar_type;
  if (sym_pack.are_constants())
    scalar_type = WN_rtype(sym_pack.first_constant());
  else
    scalar_type = get_scalar_type_from_VER_IDX(sym_pack.first(), wssa);
  TYPE_ID vector_type = get_vector_type(scalar_type);

  // create a new pseudo register for this pack of scalar operands, sym_pack
  PREG_NUM vec_preg = Create_Preg(vector_type, "_slp_");
  VER_IDX new_ver = wssa->Create_entry_chi(MTYPE_To_PREG(vector_type), vec_preg);

  // create a PACK intrinsic for each source operand
  int num_elements = sym_pack.size();
  for (int i=0; i<num_elements; i++){
    WN* pack_stmt = gen_a_PACK_intrinsic(sym_pack, vector_type, 
					 scalar_type, vec_preg, i, new_ver);
    sym_pack.set_def(pack_stmt);
  }

  // insert into the set for future reference
  Symbol_Pack* new_sym_pack = CXX_NEW(Symbol_Pack(sym_pack), slp_mem_pool);
  sym_packs.insert(new_sym_pack);
}





  
// create a pack intrinsic for each scalar element being packed
WN* Transform::gen_a_PACK_intrinsic(Symbol_Pack& sym_pack, 
				     TYPE_ID vector_type, 
				     TYPE_ID scalar_type,
				     PREG_NUM vec_preg,
				     int i_th, VER_IDX new_ver) 
{
  bool are_constants = sym_pack.are_constants();
  INTRINSIC intrn = get_PACK_intrinsic(scalar_type);

  // generate an UNPACK if scalar_vidx exists only in a packed form
  WN* ref;
  TYPE_ID ref_type;
  if (are_constants) {
    ref      = sym_pack.i_th_constant(i_th);
    ref_type = WN_rtype(ref);
  }
  else {
    VER_IDX scalar_vidx=sym_pack.i_th(i_th);
    if (is_only_in_packed_form(scalar_vidx))
      gen_an_UNPACK_intrinsic(scalar_vidx);

    ref      = get_WN(scalar_vidx);
    ref_type = TY_mtype(ST_type(WN_st(ref)));
  }
  Is_True(scalar_type == ref_type,
	  ("Transform::gen_a_PACK_intrinsic: unmatching scalar types: scalar_type(%d) vs. WN_ty(ref)(%d)", scalar_type, TY_mtype(ST_type(WN_st(ref)))));

  WN* kid[3];TY_IDX typ[3];
  // kid 0: vector type
  kid[0] = WN_LdidPreg(vector_type, vec_preg);
  typ[0] = MTYPE_To_TY(vector_type);
  // kid 1: scalar type
  kid[1] = are_constants ? WN_COPY_Tree(ref) : make_LDID(ref, wssa);
  typ[1] = MTYPE_To_TY(scalar_type);
  // kid 2: index into the packing position
  int sel = intrn == INTRN_INSRPS ? i_th<<4 : i_th;
  kid[2] = WN_CreateIntconst(OPR_INTCONST, MTYPE_I4, MTYPE_V, sel);
  typ[2] = MTYPE_To_TY(MTYPE_I4);

  // for the first PACK, a CHI node is inserted at the function entry
  // WSSA does not like it if any variable is used before being defined first.
  if (i_th == 0) {
    WN_MAP_Set_ID(Current_Map_Tab, kid[0]);
    wssa->Set_wn_ver(kid[0], new_ver);
  }

  WN* new_stid = gen_an_intrinsic(intrn, vec_preg, 
				  MTYPE_To_PREG(vector_type), kid, 3, typ);

  return new_stid;
}





  
// create a 'shift right' statement that converts -1's to 1's
// in the vector register.
void Transform::gen_cvted_cond(Symbol_Pack* sym_pack) 
{
  // create destination pseudo register
  WN*      vec_cond = sym_pack->definition();
  TYPE_ID  vec_type = WN_rtype(WN_kid0(vec_cond));
  PREG_NUM vec_preg = Create_Preg(vec_type, "_slp_");
  ST*      preg     = MTYPE_To_PREG(vec_type);

  // create SHR
  int nbits    = MTYPE_bit_size(get_scalar_type(vec_type));
  WN* shr      = WN_Create(OPR_LSHR, vec_type, MTYPE_V, 2);
  WN_kid0(shr) = make_LDID(vec_cond, wssa);
  WN_kid1(shr) = WN_CreateIntconst(OPR_INTCONST, MTYPE_I4, MTYPE_V, nbits-1);

  // create STID
  WN* cvted_cond = WN_StidIntoPreg(vec_type, vec_preg, preg, shr);
  WN_insert(cvted_cond);

  sym_pack->set_cvted_cond(cvted_cond);
}




  
// insert wn into the end of the block
void Transform::WN_insert(WN* wn, WN* use_block, WN* use) 
{
  set_map_id(wn);
  if (use_block && use)
    wssa_updater.Insert_before(use_block, use, wn);
  else
    wssa_updater.Insert_before(block, last_stmt, wn);
}





  
// set map_id for wn
void Transform::set_map_id(WN* wn) 
{
  if (!wn) return;
  WN_MAP_Set_ID(Current_Map_Tab, wn);

  for (int i=0; i<WN_kid_count(wn); i++)
    set_map_id(WN_kid(wn, i));
}





  
// trash the remaining scalar statements but the first one
void Transform::trash_the_rest(Statement_Pack* pack) 
{
  int pack_size = pack->size();
  for (int i=1; i<pack_size; i++) {
    Statement_ID id = pack->i_th(i);
    trash_bin.push_back(stmts[id]->whirl_node());
  }
}





  
// empty the trash bin of WNs when it's all done
void Transform::empty_trash_bin() 
{
  std::list<WN*>::iterator i = trash_bin.begin();
  for (;i != trash_bin.end(); i++) 
//     WN_DELETE_FromBlock(block, *i);
    // both 'WN_DELETE_FromBlock' and 'ssa_remove_stmt' have to be done
  wssa_updater.Delete_stmt(block, *i);
}





// pack source operands from each statement in the same order
void Transform::pack_operands(std::vector<Symbol_Pack>& operand_packs,
			      Statement_Pack* pack) 
{
  int pack_size = pack->size();
  int num_operands = operand_packs.size();

  for (int i=0; i<pack_size; i++) {
    int j_th_operand = 0;
    WN* wn = stmts[pack->i_th(i)]->whirl_node();
    pack_operands_stmt(operand_packs, i, wn, j_th_operand);
    Is_True(num_operands==j_th_operand, 
	    ("Transform::pack_operands: number of operands does not match: %d th stmt: num_operand(%d) vs. j_th_operand(%d)", pack->i_th(i), num_operands, j_th_operand));
  }

  // set 'contiguous LD/STIDs'
  for (int i=0; i<num_operands; i++) {
    Symbol_Pack& sym_pack = operand_packs[i];
    OPERATOR opr = are_contiguous_LD_STIDs(sym_pack);
    if (opr != OPERATOR_UNKNOWN) {
      sym_pack.set_contiguous_LD_STIDs(opr);
    }
  }
}





// pack source operands of one statement (wn) which is i_th statement 
// in operand_pack in the same order as the 
// other packed statement, except for those used in address computations
void Transform::pack_operands_stmt(std::vector<Symbol_Pack>& operand_packs,
				   int i_th_stmt,
				   WN* wn, 
				   int& j_th_operand) 
{
  if (!wn) return;

  if (WN_has_ver(wn)) {
    VER_IDX vidx = wssa->Get_wn_ver(wn);
    Symbol_Pack& sym_pack = operand_packs[j_th_operand++];
    sym_pack.set_i_th(i_th_stmt, vidx, wssa);
    if (WN_def_ver(wn)) sym_pack.set_modified();

    // set the map to get the offset of this WN
    VER_IDX_to_WN[vidx] = wn;
  }

  if (WN_is_constant_expr(wn)) {
    Is_True(!WN_has_ver(wn), ("Transform::pack_operands_stmt: unexpected"));
    operand_packs[j_th_operand++].set_i_th_constant(i_th_stmt, wn);
  }

  for (int i=0; i<WN_kid_count(wn); i++)
    if (!WN_is_address_operand(wn, i)) // don't pack address symbols
      pack_operands_stmt(operand_packs, i_th_stmt, WN_kid(wn, i), j_th_operand);
}






// true if a variable is live on exit of the basic block
// If there's only one use outside the current block, the use and its
// block are set as well.
bool Transform::is_live_on_exit(VER_IDX vidx, WN*& use_block, WN*& use)
{
  if (_TraceKind >= TRACE_maximal) {
    fprintf(TFile, "Transform::is_live_on_exit: ");
    print_VER_IDX(vidx, wssa);fprintf(TFile, "\n");
  }

  WN* last_use_block = NULL, *last_use = NULL;
  int num_external_uses = 0;
  /* get direct def node/use list of given symbol/version */
  WSSA_DU_MANAGER::const_iterator i = slp_du_mgr->begin(vidx);
  for (; i != slp_du_mgr->end(vidx); ++i) { 
    WN* use = const_cast<WN*>(i->Get_use_wn());
    if (_TraceKind >= TRACE_maximal) {
      dump_wn(use);
      fprintf(TFile, "-------------------- Get_wn_node(use: %p) vs. bb_node(%p)\n", cfg->Get_wn_node(use), bb_node);
    }

    // uses outside the current basic block
    if (cfg->Get_wn_node(use) != bb_node) {
      num_external_uses++;
      last_use       = use;
      last_use_block = cfg->Get_parent_block(use);
    }

    // return immediately for uses outside the current PU
    if (WN_operator(use) == OPR_RETURN) return true;
  }

  // to generate UNPACK before the use when there's only one use
  if (num_external_uses == 1) {
    use = cfg->Get_parent_stmt(last_use);
    use_block = last_use_block;
    return true;
  }
  return num_external_uses == 0 ? false : true; 
}






// true if the number of statements in stmt_pack is same as the vector length
bool Transform::is_full_pack(Statement_Pack* stmt_pack)
{
  Statement* stmt = stmts[stmt_pack->first()];
  int typesize = stmt->typesize();
  int vector_length = SIMD_register_width / typesize;
  return stmt_pack->size() == vector_length;
}





// create an unpack intrinsic for each scalar element being unpacked
void Transform::gen_an_UNPACK_intrinsic(VER_IDX vidx, WN* use_block, WN* use)
{
  Symbol_Pack* sym_pack = get_Symbol_Pack(vidx);
  Is_True(sym_pack != NULL, 
	  ("Transform::gen_an_UNPACK_intrinsic: NULL sym_pack"));

  WN* vector_def;
  if (sym_pack->is_conditional()) {
    if (!sym_pack->is_cvted_cond_defined())
      gen_cvted_cond(sym_pack);
    vector_def = sym_pack->get_cvted_cond();
  }
  else
    vector_def = sym_pack->definition();
  Is_True(vector_def, ("Transform::gen_an_UNPACK_intrinsic: vector_def is NULL"));
  int i_th = sym_pack->get_lane_number(vidx);
  gen_an_UNPACK_intrinsic(vidx, vector_def, i_th, use_block, use);
}





// create an unpack intrinsic for each scalar element being unpacked
void Transform::gen_an_UNPACK_intrinsic(VER_IDX vidx, WN* vector_def, 
					int i_th, WN* use_block, WN* use)
{
  // find scalar and vector types
  ST*       dst_st = get_ST_from_VER_IDX(vidx, wssa);
  WN_OFFSET offset = WN_offset(get_WN(vidx));
  TY_IDX    src_ty = WN_ty((vector_def));
  TYPE_ID src_type = TY_mtype(src_ty);
  // Warning: The below line ignores signedness.
  TYPE_ID dst_type = get_scalar_type(src_type);

  WN* kid[2];TY_IDX typ[2];
  // kid 0: vector type
  kid[0] = make_LDID(vector_def, wssa);
  typ[0] = src_ty;
  if (_TraceKind >= TRACE_maximal) 
    fprintf(TFile, "Transform::gen_an_UNPACK_intrinsic: typ[0]: %s(%d)\n", 
	    MTYPE_name(src_type), src_type);

  // use a different function for unpacking 8-byte scalar types
  WN* unpack_stmt;
  if (MTYPE_byte_size(dst_type) == 8) {
    unpack_stmt = gen_an_UNPACK_8byte_scalar(dst_st, offset, kid[0], 
					     dst_type, i_th, use_block, use);
  }
  else {
    // kid 1: index into the packed position
    kid[1] = WN_CreateIntconst(OPR_INTCONST, MTYPE_I4, MTYPE_V, i_th);
    typ[1] = MTYPE_To_TY(MTYPE_I4);

    // create an UNPACK intrinsic
    INTRINSIC unpack = get_UNPACK_intrinsic(dst_type);
    unpack_stmt = gen_an_intrinsic(unpack, offset, dst_st, kid, 2, 
				   typ, use_block, use);
  }
  wssa->Set_wn_ver(unpack_stmt, vidx);

  // keep this unpack information
  set_also_in_scalar_form(vidx);
}





// create an intrinsic for PACK and UNPACK
WN* Transform::gen_an_intrinsic(INTRINSIC intrinsic, 
				WN_OFFSET offset, // offset or preg_num of dst
				ST* dst_st, WN** kid, int num_kids, 
				TY_IDX typ[], WN* use_block, WN* use)
{
  for (int i=0; i<num_kids; i++)
    kid[i] = WN_CreateParm(WN_rtype(kid[i]), kid[i], typ[i], WN_PARM_BY_VALUE);

  TY_IDX ty_idx = ST_type(dst_st);
  if (TY_kind(ty_idx) == KIND_ARRAY) ty_idx = TY_etype(ty_idx);
  TYPE_ID rtype = TY_mtype(ty_idx);
  WN* wn = WN_Create_Intrinsic(OPR_INTRINSIC_OP, rtype, 
			       MTYPE_V, intrinsic, num_kids, kid);
  // new STID into the scalar
  WN* new_stid = WN_StidIntoPreg(rtype, offset, dst_st, wn);

  // insert the UNPACK intrinsic
  WN_insert(new_stid, use_block, use);

  return new_stid;
}




// create an UNPACK intrinsic that is stored into memory using ISTORE
void Transform::unpack_to_memory(WN* istore, int i_th_lane,
				 TYPE_ID scalar_type)
{
  WN* to_be_stored = WN_kid0(istore);
  WN* addr         = WN_kid1(istore);
  TYPE_ID vector_type = WN_rtype(to_be_stored);
  WN* kid[2];TY_IDX typ[2];
  // kid 0: vector type
  kid[0] = WN_COPY_Tree(to_be_stored);
  typ[0] = MTYPE_To_TY(vector_type);
  // kid 1: index into the packed position
  kid[1] = WN_CreateIntconst(OPR_INTCONST, MTYPE_I4, MTYPE_V, i_th_lane);
  typ[1] = MTYPE_To_TY(MTYPE_I4);
  
  for (int i=0; i<2; i++)
    kid[i] = WN_CreateParm(WN_rtype(kid[i]), kid[i], typ[i], WN_PARM_BY_VALUE);

  INTRINSIC intrinsic = get_UNPACK_intrinsic(scalar_type);
  WN* unpack = WN_Create_Intrinsic(OPR_INTRINSIC_OP, scalar_type, 
				   MTYPE_V, intrinsic, 2, kid);
  // new ISTORE into memory
  WN* new_istore = WN_COPY_Tree(istore);
  wssa->Copy_tree_ssa(new_istore, istore);

  WN_DELETE_Tree(WN_kid0(new_istore));
  WN_kid0(new_istore) = unpack;
  WN_offset(new_istore) = i_th_lane*MTYPE_byte_size(scalar_type) + 
                          WN_offset(new_istore);
  WN_insert(new_istore);
}





// true if the given VER_IDX exists only in packed form
bool Transform::is_only_in_packed_form(VER_IDX vi)
{
  return only_in_packed_form.find(vi) != only_in_packed_form.end();
}





void Transform::set_only_in_packed_form(VER_IDX vi, Symbol_Pack* sym_pack)
{
  only_in_packed_form[vi] = sym_pack;
}





void Transform::set_only_in_packed_form(Symbol_Pack* sym_pack)
{
  int size = sym_pack->size();
  for (int i=0; i<size; i++)
    only_in_packed_form[sym_pack->i_th(i)] = sym_pack;
}





void Transform::set_also_in_scalar_form(VER_IDX vi)
{
  only_in_packed_form.erase(vi);
}





Symbol_Pack* Transform::get_Symbol_Pack(VER_IDX vi)
{
  return only_in_packed_form[vi];
}





// generate an UNPACK statement for each of wn and its kids
void Transform::unpack_packed_srcs(WN* wn)
{
  if (!wn) return;

  if (WN_use_ver(wn)){
    VER_IDX vidx = wssa->Get_wn_ver(wn);
    if (is_only_in_packed_form(vidx))
      gen_an_UNPACK_intrinsic(vidx);
  }

  for (int i=0; i<WN_kid_count(wn); i++)
    if (!WN_is_address_operand(wn, i)) // address symbols are not packed
      unpack_packed_srcs(WN_kid(wn, i));
}





// returns WN where vidx is used or defined. This is necessary to get
// offset for the variables that are not defined in this basic block.
WN* Transform::get_WN(VER_IDX vidx)
{
  WN* wn = VER_IDX_to_WN[vidx];
  Is_True(wn!=NULL, ("Transform::get_WN: NULL WN for VER_IDX(%d)", vidx));
  return wn;
}



  

// returns OPR_LDID (or OPR_STID) if the elements are OPR_LDIDs 
// (or OPR_STIDs) contiguous in memory in ascending order
// OPERATOR_UNKNOWN otherwise
OPERATOR Transform::are_contiguous_LD_STIDs(Symbol_Pack& sym_pack)
{
  if (sym_pack.are_constants()) return OPERATOR_UNKNOWN;

  OPERATOR opr = OPERATOR_UNKNOWN;
  int size = sym_pack.size();
  for (int i=0; i<size-1; i++){
    VER_IDX vidx1 = sym_pack.i_th(i);
    VER_IDX vidx2 = sym_pack.i_th(i+1);
    WN*     wn1   = get_WN(vidx1);
    WN*     wn2   = get_WN(vidx2);
    OPERATOR op1  = WN_operator(wn1);
    OPERATOR op2  = WN_operator(wn2);
    if (opr == OPERATOR_UNKNOWN) opr = op1;
    if (op1 != opr || op2 != opr) {
      if (_TraceKind >= TRACE_maximal) 
	fprintf(TFile, "Transform::are_contiguous_LD_STIDs: not equal operators: op1(%s) vs. op2(%s)\n", OPERATOR_name(op1), OPERATOR_name(op2));
      return OPERATOR_UNKNOWN;
    }

    TY_KIND kind1 = TY_kind(ST_type(WN_st(wn1)));
    TY_KIND kind2 = TY_kind(ST_type(WN_st(wn2)));
    if (kind1 != KIND_ARRAY || kind2 != KIND_ARRAY) {
      if (_TraceKind >= TRACE_maximal) 
	fprintf(TFile, "Transform::are_contiguous_LD_STIDs: not KIND_ARRAY: kind1(%d) vs. kind2(%d)\n", kind1, kind2);
      return OPERATOR_UNKNOWN;
    }

    int typesize1 = TY_size(WN_ty(wn1));
    int typesize2 = TY_size(WN_ty(wn2));
    if (typesize1 != typesize2) {
      if (_TraceKind >= TRACE_maximal) 
	fprintf(TFile, "Transform::are_contiguous_LD_STIDs: different typesizes: typesize1(%d) vs. typesize2(%d)\n", typesize1, typesize2);
      return OPERATOR_UNKNOWN;
    }

    int offset1   = WN_offset(wn1);
    int offset2   = WN_offset(wn2);
    if (offset1 + typesize1 != offset2) return OPERATOR_UNKNOWN;
  }

  return opr;
}







// --------------------------------------------------------------------
// SIMD integer comparisons
// --------------------------------------------------------------------

// Transform integer type SIMD comparisons
// EQ: PCMPEQ
// NE: (NOT) PCMPEQ
// GT: PCMPGT
// LT: (swap operands) PCMPGT
// GE: (NOT) (swap operands) PCMPGT
// LE: (NOT) PCMPGT
void Transform::transform_to_SIMD_compares(WN* wn, WN* parent, int ith)
{
  OPERATOR op = WN_operator(wn);
  switch (op)
    {
    case OPR_EQ: 
      WN_kid(parent, ith) = gen_PCMPEQ(WN_kid0(wn), WN_kid1(wn));
      break;

    case OPR_NE: {
      WN* pcmpeq = gen_PCMPEQ(WN_kid0(wn), WN_kid1(wn));
      WN_kid(parent, ith) = gen_NOT(pcmpeq); break;
    }

    case OPR_GT:
      WN_kid(parent, ith) = gen_PCMPGT(WN_kid0(wn), WN_kid1(wn));
      break;

    case OPR_LT:
      WN_kid(parent, ith) = gen_PCMPGT(WN_kid1(wn), WN_kid0(wn));
      break;

    case OPR_GE:{
      WN* pcmplt = gen_PCMPGT(WN_kid1(wn), WN_kid0(wn));
      WN_kid(parent, ith) = gen_NOT(pcmplt); break;
    }

    case OPR_LE:{
      WN* pcmpgt = gen_PCMPGT(WN_kid0(wn), WN_kid1(wn));
      WN_kid(parent, ith) = gen_NOT(pcmpgt); break;
    }
    }
  WN_Delete(wn); 
}





WN* Transform::gen_NOT(WN* kid0)
{
  TYPE_ID vec_type = WN_rtype(kid0);
  WN* an_ldid = get_vec_PREG(kid0);
  WN* minus_1;
  if (an_ldid) 
    minus_1 = gen_PCMPEQ(WN_COPY_Tree(an_ldid), WN_COPY_Tree(an_ldid));
  else
    // This is inefficient but hopefully it's not used very often.
    minus_1 = gen_PCMPEQ(WN_COPY_Tree(kid0), WN_COPY_Tree(kid0));

  WN *wn_not = WN_Create (OPR_BXOR, vec_type, MTYPE_V, 2);
  WN_kid0(wn_not) = kid0;
  WN_kid1(wn_not) = minus_1;
  
  return wn_not;
}




// not used. 
// I don't know how to generate constant integers of all types
WN* Transform::gen_REPLICATE(TYPE_ID vec_type, int val)
{
  WN *wn_repl = WN_Create (OPR_REPLICATE, vec_type, MTYPE_I4, 1);
  WN_kid0(wn_repl) = WN_CreateIntconst(OPR_INTCONST, MTYPE_I4, MTYPE_V, val);
  return wn_repl;
}





WN* Transform::gen_PCMPEQ(WN* kid0, WN* kid1)
{
  INTRINSIC intrn;
  TYPE_ID vec_type = WN_rtype(kid0);
  switch(vec_type)
    {
    case MTYPE_V16I1: intrn = INTRN_PCMPEQB128; break;
    case MTYPE_V16I2: intrn = INTRN_PCMPEQW128; break;
    case MTYPE_V16I4: intrn = INTRN_PCMPEQD128; break;
    default:
      Is_True(0, ("Transform::gen_PCMPEQ: unsupported SIMD type: %d", vec_type));
    }

  WN* kid[2];
  TY_IDX ty = MTYPE_To_TY(vec_type);
  kid[0] = WN_CreateParm(vec_type, kid0, ty, WN_PARM_BY_VALUE);
  kid[1] = WN_CreateParm(vec_type, kid1, ty, WN_PARM_BY_VALUE);

  return WN_Create_Intrinsic(OPR_INTRINSIC_OP, vec_type, MTYPE_V,
			     intrn, 2, kid);
}





WN* Transform::gen_PCMPGT(WN* kid0, WN* kid1)
{
  INTRINSIC intrn;
  TYPE_ID vec_type = WN_rtype(kid0);
  switch(vec_type)
    {
    case MTYPE_V16I1: intrn = INTRN_PCMPGTB128; break;
    case MTYPE_V16I2: intrn = INTRN_PCMPGTW128; break;
    case MTYPE_V16I4: intrn = INTRN_PCMPGTD128; break;
    default:
      Is_True(0, ("Transform::gen_PCMPGT: unsupported SIMD type: %d", vec_type));
    }

  WN* kid[2];
  TY_IDX ty = MTYPE_To_TY(vec_type);
  kid[0] = WN_CreateParm(vec_type, kid0, ty, WN_PARM_BY_VALUE);
  kid[1] = WN_CreateParm(vec_type, kid1, ty, WN_PARM_BY_VALUE);

  return WN_Create_Intrinsic(OPR_INTRINSIC_OP, vec_type, MTYPE_V,
			     intrn, 2, kid);
}





// finds and returns LDID from vector PREG
WN* Transform::get_vec_PREG(WN* wn)
{
  if (!wn) return NULL;

  for (int i=0; i<WN_kid_count(wn); i++)
    if (!WN_is_address_operand(wn, i)) {// don't search address operands
      WN* preg = get_vec_PREG(WN_kid(wn, i));
      if (preg) return preg;
    }

  if (WN_operator(wn) != OPR_LDID) return NULL;
  if (!is_vector_type(WN_rtype(wn))) return NULL;
  if (ST_class(WN_st(wn)) != CLASS_PREG) return NULL;

  return wn;
}






// generates statements for an unpack of a 64-bit operand
WN* Transform::gen_an_UNPACK_8byte_scalar(ST* dst_st, WN_OFFSET offset, 
					  WN* vector_def, TYPE_ID scalar_type,
					  int i_th, WN* use_block, WN* use)
{
  TYPE_ID vector_type = get_vector_type(scalar_type);
  if (i_th != 0) {
    WN* args[2];
    TY_IDX arg_ty_idx = MTYPE_TO_TY_array[vector_type];
    args[0] = WN_CreateParm (vector_type, vector_def,
			     arg_ty_idx, WN_PARM_BY_VALUE);

    WN* num_bits = WN_Intconst(MTYPE_I4, i_th*8*8);
    arg_ty_idx = MTYPE_TO_TY_array[MTYPE_I4];
    args[1] = WN_CreateParm (MTYPE_I4, num_bits,
			     arg_ty_idx, WN_PARM_BY_VALUE);
    vector_def = WN_Create_Intrinsic (OPR_INTRINSIC_OP, vector_type, 
				      MTYPE_V, INTRN_PSRLDQ, 2, args);
  }

  // new STID into the scalar
  WN* wn = WN_Tas(scalar_type, MTYPE_To_TY(vector_type), vector_def);
  WN* new_stid = WN_StidIntoPreg(scalar_type, offset, dst_st, wn);
  WN_insert(new_stid, use_block, use);

  return new_stid;
}





// --------------------------------------------------------------------
// debug routines
// --------------------------------------------------------------------

void Transform::print_stmt_sym_pack(Statement_Pack* stmt_pack, 
				    std::vector<Symbol_Pack>& operand_packs)
{
  fprintf(TFile, "\n---------- Transform:: operand packs ----------\n");
  fprintf(TFile, "stmt pack: ");stmt_pack->print();fprintf(TFile, "\n");
  fprintf(TFile, "operand packs:\n");
  for (int i=0; i<operand_packs.size(); i++){
    Symbol_Pack& sym_pack = operand_packs[i];
    sym_pack.print_long(wssa, this);fprintf(TFile, "\n");
  }
}




void Transform::print_current_sym_packs()
{
  fprintf(TFile, "\n--- Transform:: current sym_packs:\n");
  std::set<Symbol_Pack*, lt_sym_pack>::iterator i = sym_packs.begin();
  for (; i!=sym_packs.end(); i++){
    (*i)->print_long(wssa, this);fprintf(TFile, "\n");
  }
  fprintf(TFile, "---\n");
}









