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
// Module: slp_main_pack.cxx
//
// Description:
// This file is a collection of methods used to pack statements. It 
// starts from 'pack_statements()' where next level methods are called
// in sequence. It uses dependence analysis to pack statements only 
// when they are independent, and distance analysis to pack 'adjacent'
// memory accesses. This is the core of the algorithm described in 
// Sam Larsen and Saman Amarasinghe's PLDI 2000 paper. Yet, there are 
// some differences from their algorithm. First, we do not use 
// alignment analysis and generate unaligned memory accesses if 
// necessary. This decision is to simplify the initial implementation
// and implementing alignment analysis is left as a future enhancement.
// Partially related to lack of alignment analysis, we pack beyond 
// the SIMD register width. And then, the long statement packs are
// chopped into SIMD register width pieces in 'chop_packs()'.
// 
// ====================================================================

#include "slp.h"

using namespace slp;

void SLP_Main::pack_statements(Dependence_Matrix& deps, 
			       Distance_Analysis& dists)
{
  pack_adjacent_mem_refs(deps, dists);
  if (_TraceKind >= TRACE_maximal) {
    fprintf(TFile, "\n\tAfter pack_adjacent_mem_refs:");
    print_stmt_packs();
  }

  pack_UD_chains(deps);
  if (_TraceKind >= TRACE_maximal) {
    fprintf(TFile, "\n\tAfter pack_UD_chains:");
    print_stmt_packs();
  }

  pack_DU_chains(deps);
  if (_TraceKind >= TRACE_maximal) {
    fprintf(TFile, "\n\tAfter pack_DU_chains:");
    print_stmt_packs();
  }

  merge_packs();
  if (_TraceKind >= TRACE_maximal) {
    fprintf(TFile, "\n\tAfter merge_packs:");
    print_stmt_packs();
  }

  chop_packs();
  if (_TraceKind >= TRACE_maximal) {
    fprintf(TFile, "\n\tAfter chop_packs:");
    print_stmt_packs();
  }
}






void SLP_Main::pack_adjacent_mem_refs(Dependence_Matrix& deps, 
				      Distance_Analysis& dists)
{
  int num_stmts = stmts.size();
  for(Statement_ID i=0; i<num_stmts; i++){
    for(Statement_ID j=i+1; j<num_stmts; j++){
      if (deps.is_dependent(i, j)) {
	if (_TraceKind >= TRACE_maximal)
	  fprintf(TFile, ">>> deps.is_dependent(%d, %d) failed.\n", i, j);
	continue;
      }
      if (!good_to_pack(i, j)) {
	if (_TraceKind >= TRACE_maximal)
	  fprintf(TFile, ">>> !good_to_pack(%d, %d) failed.\n", i, j);
	continue;
      }

      if (dists.are_adjacent_mem_refs(i, j)) // true if stmt_j is higher side 
	add_to_pack_set(i, j);               // of stmt_i
      if (dists.are_adjacent_mem_refs(j, i))
	add_to_pack_set(j, i);
    }
  }
}






// pack the definitions that are used in the current pack list
void SLP_Main::pack_UD_chains(Dependence_Matrix& deps)
{
  std::list<Statement_Pack*>::iterator i = stmt_packs.begin();
  for(; i != stmt_packs.end(); i++){
    Statement_Pack* spack = *i;
    Is_True(spack->size() == 2, ("SLP_Main::pack_UD_chains: size should be 2."));

    Statement* stmt1 = stmts[spack->first()];
    Statement* stmt2 = stmts[spack->last()];
    WN* wn1 = stmt1->whirl_node();
    WN* wn2 = stmt2->whirl_node();

    for(int i=0; i<WN_kid_count(wn1); i++)
      follow_UD(WN_kid(wn1, i), WN_kid(wn2, i), deps);
  }
}






void SLP_Main::pack_DU_chains(Dependence_Matrix& deps)
{
  std::list<Statement_Pack*>::iterator i = stmt_packs.begin();
  for(; i != stmt_packs.end(); i++){
    Statement_Pack* spack = *i;
    Is_True(spack->size() == 2, ("SLP_Main::pack_DU_chains: size should be 2."));

    Statement* stmt1 = stmts[spack->first()];
    Statement* stmt2 = stmts[spack->last()];
    WN* wn1 = stmt1->whirl_node();
    WN* wn2 = stmt2->whirl_node();

    follow_DU(wn1, wn2, deps);
  }
}





// Two statement packs can be merged if they share a common statement.
void SLP_Main::merge_packs()
{
  bool merged;
  std::list<Statement_Pack*>::iterator i = stmt_packs.begin();
  for(; i != stmt_packs.end(); merged?i:++i){
    merged=false;
    Statement_Pack* pack_i = *i;
    if (_TraceKind >= TRACE_maximal) {
      fprintf(TFile, "merge_packs: pack_i"); pack_i->print(); fprintf(TFile, "\n");}

    // look for all other packs that can be merged on the 
    // higher address side of pack_i
    std::list<Statement_Pack*>::iterator j = stmt_packs.begin();
    for(; j != stmt_packs.end(); j++){
      if (i == j) continue;
      Statement_Pack* pack_j = *j;
      if (pack_i->last() != pack_j->first()) continue;
      if (pack_i->num_common_stmts(pack_j) != 1) continue;
	
      // attach pack_j to the higher address side of pack_i
      if (_TraceKind >= TRACE_maximal) {
	fprintf(TFile, "merge_packs: deleting pack_i");pack_i->print();fprintf(TFile, "\n");
	fprintf(TFile, "merge_packs: deleting pack_j");pack_j->print();fprintf(TFile, "\n");
      }
      pack_i->merge(pack_j);
      if (_TraceKind >= TRACE_maximal) {
	fprintf(TFile, "merge_packs: inserting pack_ij");pack_i->print();fprintf(TFile, "\n");}
      stmt_packs.erase(j);

      merged = true;
      break;
    }
  }
}






// --------------------------------------------------------------------
// low-level routines
// --------------------------------------------------------------------

// true if the two statements can be packed
bool SLP_Main::good_to_pack(Statement_ID s1, Statement_ID s2)
{
  Statement* stmt1 = stmts[s1];
  Statement* stmt2 = stmts[s2];
  if (!stmt1->is_simd_op()) {
    if (_TraceKind >= TRACE_maximal)
      fprintf(TFile, ">>> good_to_pack: bad: %d is not SIMD op.\n", s1);
    return false;
  }
  if (!stmt2->is_simd_op()) {
    if (_TraceKind >= TRACE_maximal)
      fprintf(TFile, ">>> good_to_pack: bad: %d is not SIMD op.\n", s2);
    return false;
  }

  if (stmt1->typesize() == 0) {
    if (_TraceKind >= TRACE_maximal)
      fprintf(TFile, ">>> good_to_pack: bad: %d has multiple type sizes.\n", s1);
    return false;
  }
  if (stmt2->typesize() == 0) {
    if (_TraceKind >= TRACE_maximal)
      fprintf(TFile, ">>> good_to_pack: bad: %d has multiple type sizes.\n", s2);
    return false;
  }
  if (stmt1->typesize() != stmt2->typesize()) {
    if (_TraceKind >= TRACE_maximal)
      fprintf(TFile, ">>> good_to_pack: bad: type sizes don't match: stmt1(%d) vs. stmt2(%d)\n", stmt1->typesize(), stmt2->typesize());
    return false;
  }

  if (!stmt1->are_isomorphic(stmt2)) {
    if (_TraceKind >= TRACE_maximal)
      fprintf(TFile, ">>> good_to_pack: bad: (%d, %d): not isomorphic.\n", s1, s2);
    return false;
  }
  if (stmt1->is_packed_higher()) {
    if (_TraceKind >= TRACE_maximal)
      fprintf(TFile, ">>> good_to_pack: bad: %d is is_packed_higher.\n", s1);
    return false;
  }
  if (stmt2->is_packed_lower()) {
    if (_TraceKind >= TRACE_maximal)
      fprintf(TFile, ">>> good_to_pack: bad: %d is is_packed_lower.\n", s2);
    return false;
  }

  if (_TraceKind >= TRACE_maximal)
    fprintf(TFile, ">>> good_to_pack: %d and %d are good to pack.\n", s1, s2);
  return true;
}






void SLP_Main::add_to_pack_set(Statement_ID s1, Statement_ID s2)
{
  if (_TraceKind >= TRACE_maximal)
    std::cout << ">>> in add_to_pack_set:" << s1 << " -> " << s2 << std::endl;
  stmt_packs.push_back(CXX_NEW(Statement_Pack(s1, s2), slp_mem_pool));
  stmts[s1]->set_packed_higher();
  stmts[s2]->set_packed_lower();
  stmt_packed_right.insert(std::pair<Statement_ID, Statement_ID>(s1, s2));
}





// - pack the definitions by following the UD chains recursively
// - the two WHIRL nodes are statement nodes
// - if the current statements are not packed, stop here
// - otherwise, pack them and chase the definitions for all uses
void SLP_Main::pack_statements_UD(WN* wn1, WN* wn2, 
				  Dependence_Matrix& deps)
{
  if (are_packed(wn1, wn2)) return;
  if (WN_operator(wn1) == OPERATOR_UNKNOWN || 
      WN_operator(wn2) == OPERATOR_UNKNOWN ) return;

  Is_True(stmt_ID.find(wn1) != stmt_ID.end() &&
	  stmt_ID.find(wn2) != stmt_ID.end(), 
	  ("pack_statements_UD: no statement ID"));
  Statement_ID s1 = stmt_ID[wn1];
  Statement_ID s2 = stmt_ID[wn2];

  if (outside_BB(wn1) || outside_BB(wn2)){
    if (_TraceKind >= TRACE_maximal) 
      fprintf(TFile, "pack_statements_UD: cannot pack: outside_BB(%d, %d)\n", s1, s2);
    return;
  }
  if (!good_to_pack    (s1, s2)){
    if (_TraceKind >= TRACE_maximal) 
      fprintf(TFile, "pack_statements_UD: cannot pack: NOT good_to_pack(%d, %d)\n", s1, s2);
    return;
  }
  if (deps.is_dependent(s1, s2)){
    if (_TraceKind >= TRACE_maximal) 
      fprintf(TFile, "pack_statements_UD: cannot pack: is_dependent(%d, %d)\n", s1, s2);
    return;
  }

  add_to_pack_set(s1, s2);

  for(int i=0; i<WN_kid_count(wn1); i++)
    follow_UD(WN_kid(wn1, i), WN_kid(wn2, i), deps);
}





// - wn1 and wn2 are internal WHIRL nodes
void SLP_Main::follow_UD(WN* wn1, WN* wn2, Dependence_Matrix& deps)
{
  // we ignore MU nodes
  if (WN_use_ver(wn1) && WN_use_ver(wn2)) {
    VER_IDX vidx1 = wssa->Get_wn_ver(wn1);
    VER_IDX vidx2 = wssa->Get_wn_ver(wn2);
    WN* def1 = get_def_wn(vidx1, wssa);
    WN* def2 = get_def_wn(vidx2, wssa);
    pack_statements_UD(def1, def2, deps);
  }

  for(int i=0; i<WN_kid_count(wn1); i++)
    follow_UD(WN_kid(wn1, i), WN_kid(wn2, i), deps);
}





// - pack the uses by following the DU chains recursively
// - the two WHIRL nodes are statement nodes
// - if the current statements are not packed, stop here
// - otherwise, pack them and chase the uses for the definition
void SLP_Main::pack_statements_DU(WN* wn1, WN* wn2, Dependence_Matrix& deps)
{
  // to prevent the explosion of recursive calls
  if (are_packed(wn1, wn2)) return;

  // do not pack unpackable statements such as RETURN
  if (stmt_ID.find(wn1) == stmt_ID.end()) return;
  if (stmt_ID.find(wn2) == stmt_ID.end()) return;

  Statement_ID s1 = stmt_ID[wn1];
  Statement_ID s2 = stmt_ID[wn2];
  if (_TraceKind >= TRACE_maximal) 
    fprintf(TFile, "--> pack_statements_DU: (%d, %d)\n", s1, s2);

  if (outside_BB(wn1) || outside_BB(wn2)){
    if (_TraceKind >= TRACE_maximal) 
      fprintf(TFile, "pack_statements_DU: cannot pack: outside_BB(%d, %d)\n", s1, s2);
    return;
  }
  if (!good_to_pack    (s1, s2)){
    if (_TraceKind >= TRACE_maximal) 
      fprintf(TFile, "pack_statements_DU: cannot pack: NOT good_to_pack(%d, %d)\n", s1, s2);
    return;
  }
  if (deps.is_dependent(s1, s2)){
    if (_TraceKind >= TRACE_maximal) 
      fprintf(TFile, "pack_statements_DU: cannot pack: is_dependent(%d, %d)\n", s1, s2);
    return;
  }

  add_to_pack_set(s1, s2);

  // follow DU
  follow_DU(wn1, wn2, deps);
  if (_TraceKind >= TRACE_maximal) 
    fprintf(TFile, "<-- pack_statements_DU: exiting for (%d, %d)\n", s1, s2);
}






void SLP_Main::follow_DU(WN* wn1, WN* wn2, Dependence_Matrix& deps)
{
  // do not follow virtual nodes
  if (!WN_def_ver(wn1) || !WN_def_ver(wn2)) return;
  VER_IDX def1 = wssa->Get_wn_ver(wn1);
  VER_IDX def2 = wssa->Get_wn_ver(wn2);

  // WN_begin for 'MUST-use' and WN_du_begin for 'MAY-use'
  typedef WSSA_NODE_ITERATOR<const WSSA_DU_MANAGER, const USE_NODE> const_iterator;
  const_iterator it1 = slp_du_mgr->begin(def1);
  const_iterator it2 = slp_du_mgr->begin(def2);

  for(;it1 != slp_du_mgr->end(def1) && it2 != slp_du_mgr->end(def2); 
      ++it1, ++it2) {
    WN* use_nd1 = const_cast<WN*>(it1->Get_use_wn());
    WN* use_nd2 = const_cast<WN*>(it2->Get_use_wn());
    WN* use1 = wcfg->Get_parent_stmt(use_nd1);
    WN* use2 = wcfg->Get_parent_stmt(use_nd2);

    pack_statements_DU(use1, use2, deps);
  }
}





// true if 'wn' is outside the current basic block
bool SLP_Main::outside_BB(WN* wn)
{
  if (wcfg->Get_wn_node(wn) != bb)   return true;
  if (WN_operator(wn) == OPR_RETURN) return true;
  return false;
}





// true if wn2 is packed to the right side(higher address) of wn1
bool SLP_Main::are_packed(WN* wn1, WN* wn2)
{
  Statement_ID s1 = stmt_ID[wn1];
  Statement_ID s2 = stmt_ID[wn2];

  if (stmt_packed_right.find(s1) == stmt_packed_right.end()) return false;
  return stmt_packed_right[s1] == s2;
}











// --------------------------------------------------------------------
// chop_packs routines
// --------------------------------------------------------------------

// chop the packs if they are longer than the vector length
void SLP_Main::chop_packs()
{
  std::list<Statement_Pack*>::iterator i = stmt_packs.begin();
  for(; i != stmt_packs.end(); i++){
    Statement_Pack* spack = *i;
    int typesize = stmts[spack->first()]->typesize();
    int vector_length = SIMD_register_width / typesize;

    chop_a_pack(spack, vector_length);
  }
}



// chop a pack if it is longer than the vector length
void SLP_Main::chop_a_pack(Statement_Pack* spack, int vector_length)
{
  if (spack->size() <= vector_length) return;

  for (int i=vector_length; i<spack->size(); i+=vector_length){
    int size = spack->size()<i+vector_length ? spack->size()-i : vector_length;
    std::vector<Statement_ID> temp_pack(size);

    for (int j=0; j<size; j++)
      temp_pack[j] = spack->i_th(i+j);

    stmt_packs.push_back(CXX_NEW(Statement_Pack(temp_pack), slp_mem_pool));
  }
  spack->resize(vector_length);
}


