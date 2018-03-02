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
// Module: slp_dependence.cxx
//
// Description:
// This file implements Dependence_Matrix class, which finds dependence 
// among statements in the given basic block. The dependence information
// is used later in packing statements (statements are packed together
// only if there is no dependence among them) and scheduling, possibly
// packed statements. To find dependence between two statements (in 
// 'find_dependence()'), we look at WST_IDX's that are referenced or
// defined by the two statements. For memory accesses, we consult 
// an existing alias analysis (Dependence_Matrix::are_aliased()). If 
// the two memory accesses are aliased, the distance analysis (See 
// slp_distance.cxx) result is checked. The dependence analysis may 
// provide information on whether the two memory accesses always access 
// different offsets from the same base address. If so, they are 
// independent.
// 
// ====================================================================

#include "slp.h"

using namespace slp;



// ====================================================================
// dependence builder routines
// ====================================================================

Dependence_Matrix::Dependence_Matrix(int                      num_stmts,
				     std::vector<Statement*>& s, 
				     WHIRL_SSA_MANAGER*       w,
				     Distance_Analysis&       d,
				     ALIAS_MANAGER*           alias,
				     TRACE_OPTION_KIND        trace_kind): 
  stmts(s), wssa(w), dep_mat(num_stmts, std::vector<bool>(num_stmts)), 
  uses(num_stmts), defs(num_stmts), dists(d), slp_alias(alias),
  _TraceKind(trace_kind)
{

  // collect definitions and uses for each statement
  collect_defs_uses();

  // build an upper triangular matrix of dependences
  // dep_mat[i][j] represents dependence from stmt_i to stmt_j,
  // where i < j.
  for (int j=0; j<num_stmts; j++){
    dep_mat[j][j] = true;  // dependence to itself

    // set dependence for j with earlier statements i
    for (int i=0; i<j; i++){
      if (find_dependence(i, j)){
	for(int k=0; k<=i; k++){
          dep_mat[k][j] = dep_mat[k][j] || dep_mat[k][i];
	}
      }
    }
  }
}



Dependence_Matrix::~Dependence_Matrix()
{
}




// --------------------------------------------------------------------
// Step 1.
// Collect all definitions and uses for each statement
// --------------------------------------------------------------------

// collect definitions and uses for each statement
void Dependence_Matrix::collect_defs_uses()
{
  int num_stmts = stmts.size();
  for (Statement_ID i=0; i<num_stmts; i++) {

    WN* wn = stmts[i]->whirl_node();

    if (WN_def_ver(wn)) defs[i].insert(get_wst_idx(wn, wssa));
    if (WN_has_phi(wn)) Phi_collect_defs_uses(i, wn);
    if (WN_has_chi(wn)) Chi_collect_defs_uses(i, wn);

    Mu_collect_defs_uses (i, wn);
    WN_collect_uses(i, wn);
  }
}




// collect definitions and uses for PHIs
void Dependence_Matrix::Phi_collect_defs_uses(Statement_ID i, WN* wn)
{
  if (!wssa->WN_has_phi(wn)) return;

  WHIRL_SSA_MANAGER::phi_iterator pit = wssa->WN_phi_begin(wn);
  for(; pit != wssa->WN_phi_end(wn); ++pit) {
    defs[i].insert(wssa->Get_ver_wst(pit->Res()));

    for (int j=0; j<pit->Opnd_count(); ++j) {
      uses[i].insert(wssa->Get_ver_wst(pit->Opnd(j)));
    }
  }
}




// collect definitions and uses for CHIs
void Dependence_Matrix::Chi_collect_defs_uses(Statement_ID i, WN* wn)
{
  if (!wssa->WN_has_chi(wn)) return;

  WHIRL_SSA_MANAGER::chi_iterator cit = wssa->WN_chi_begin(wn);
  for(; cit != wssa->WN_chi_end(wn); ++cit) {
    // ignore if it takes and defines the same VER_IDX
    if (cit->Res() == cit->Opnd()) continue;

    defs[i].insert(wssa->Get_ver_wst(cit->Res()));
    uses[i].insert(wssa->Get_ver_wst(cit->Opnd()));
  }
}




// collect definitions and uses for MUs
void Dependence_Matrix::Mu_collect_defs_uses(Statement_ID i, WN* wn)
{
  if (wssa->WN_has_mu(wn)) {

    WHIRL_SSA_MANAGER::mu_iterator mit = wssa->WN_mu_begin(wn);
    for(; mit != wssa->WN_mu_end(wn); ++mit) {
      uses[i].insert(wssa->Get_ver_wst(mit->Opnd()));
    }
  }

  for(INT j=0; j<WN_kid_count(wn); j++) 
    Mu_collect_defs_uses(i, WN_kid(wn, j));
}




// collect uses in WHIRL nodes
void Dependence_Matrix::WN_collect_uses(Statement_ID i, WN* wn)
{
  if (WN_use_ver(wn)) uses[i].insert(get_wst_idx(wn, wssa));

  for(INT j=0; j<WN_kid_count(wn); j++) 
    WN_collect_uses(i, WN_kid(wn, j));
}




// --------------------------------------------------------------------
// Step 2.
// find dependence between the two given statements
// --------------------------------------------------------------------

// finds dependence from statement i to statement j
bool Dependence_Matrix::find_dependence(Statement_ID i, Statement_ID j)
{
  Is_True(i<j, ("Dependence_Matrix::find_dependence: only for i<j"));

  Statement* stmt_i = stmts[i];
  Statement* stmt_j = stmts[j];
  if (stmt_i->has_side_effects()) return true;
  if (stmt_j->has_side_effects()) return true;

  if (output_dependence(i, j)) return true;
  if (true_dependence  (i, j)) return true;
  if (anti_dependence  (i, j)) return true;

  return false;
}




// output dependence from statement i to statement j
bool Dependence_Matrix::output_dependence(Statement_ID i, Statement_ID j)
{
  std::set<WST_IDX>& defs_i = defs[i];
  std::set<WST_IDX>& defs_j = defs[j];
  std::set<WST_IDX> result;

  set_intersection(defs_i.begin(), defs_i.end(), defs_j.begin(), defs_j.end(),
                   inserter(result, result.begin()));
  // ignore these two vsyms
  result.erase(wssa->Return_vsym());result.erase(wssa->Default_vsym());
  if (result.empty()) return false;

  if (is_dependent_set(result, i, j, SLP_DEP_output)) return true;

  return false;
}




// true dependence from statement i to statement j
bool Dependence_Matrix::true_dependence(Statement_ID i, Statement_ID j)
{
  std::set<WST_IDX>& defs_i = defs[i];
  std::set<WST_IDX>& uses_j = uses[j];
  std::set<WST_IDX> result;

  set_intersection(defs_i.begin(), defs_i.end(), uses_j.begin(), uses_j.end(),
                   inserter(result, result.begin()));
  // ignore these two vsyms
  result.erase(wssa->Return_vsym());result.erase(wssa->Default_vsym());
  if (result.empty()) return false;

  if (is_dependent_set(result, i, j, SLP_DEP_true)) return true;

  return false;
}






// anti dependence from statement i to statement j
bool Dependence_Matrix::anti_dependence(Statement_ID i, Statement_ID j)
{
  std::set<WST_IDX>& uses_i = uses[i];
  std::set<WST_IDX>& defs_j = defs[j];
  std::set<WST_IDX> result;

  set_intersection(uses_i.begin(), uses_i.end(), defs_j.begin(), defs_j.end(),
                   inserter(result, result.begin()));
  // ignore these two vsyms
  result.erase(wssa->Return_vsym());result.erase(wssa->Default_vsym());
  if (result.empty()) return false;

  if (is_dependent_set(result, i, j, SLP_DEP_anti)) return true;

  return false;
}




// - true if any of the nodes in v1 is aliased with any of the nodes in v2
// - v1 and v2 are all memory references
// - osprey/be/com/opt_alias_mgr.cxx:ALIAS_RESULT 
//   Aliased(const ALIAS_MANAGER *am, WN *wn1, WN *wn2, BOOL ignore_loop_carried)
bool Dependence_Matrix::are_aliased(std::vector<WN*>& v1, std::vector<WN*>& v2)
{
  int size1 = v1.size();
  int size2 = v2.size();

  for (int i=0; i<size1; i++) {
    WN* wn1 = v1[i];
    for (int j=0; j<size2; j++) {
      WN* wn2 = v2[j];
      if (Aliased(slp_alias, wn1, wn2, true) != NOT_ALIASED){

	// two statements are independent if they access different offsets
	// from the same starting address.
	// * This check is done after the other two checks.
	//   Two memory accesses are ...
	// 1. dependent if not all common access points are virtual symbols,
	// 2. independent if the alias analysis says NOT_ALIASED,
	// 3. independent if they access distinct point within the same object,
	// 4. otherwise, dependent
	if (!dists.are_independent(wn1, wn2)) {
	  if (_TraceKind >= TRACE_maximal) {
	    fprintf(TFile, "---------- Dependence by distance analysis between ----------\n");
	    dump_tree_ssa(wn1); 
	    fprintf(TFile, "\t---------- and\n");
	    dump_tree_ssa(wn2); 
	  }
	  return true;
	}
      }
    }
  }
  return false;
}




// true if the given 'result' set represent real dependences
bool Dependence_Matrix::is_dependent_set(std::set<WST_IDX>& result, 
					 Statement_ID i, Statement_ID j,
					 SLP_DEPENDENCE dep)
{
  bool all_vsyms = are_all_vsyms(result, wssa);
  bool aliased;
  switch(dep)
    {
    case SLP_DEP_true:   aliased = are_aliased(stmts[i]->stores, 
					       stmts[j]->loads); break;
    case SLP_DEP_anti:   aliased = are_aliased(stmts[i]->loads, 
					       stmts[j]->stores); break;
    case SLP_DEP_output: aliased = are_aliased(stmts[i]->stores, 
					       stmts[j]->stores); break;
    default: Is_True(0, ("Dependence_Matrix::is_dependent_set: unexpected"));
    }

  if (!all_vsyms || aliased) {
    if (_TraceKind >= TRACE_maximal) {
      fprintf(TFile, "\n\n%s dependence from %d to %d: ", get_dep_str(dep), i, j);
      print_wst_set(result);
      if (!all_vsyms) fprintf(TFile, "(Not all symbols are virtual.)");
      if (aliased) fprintf(TFile, "(Aliased)");
    }
    return true;
  }

  return false;
}





// --------------------------------------------------------------------
// debug routines
// --------------------------------------------------------------------
void Dependence_Matrix::print()
{
  fprintf(TFile, "\n\n\n\nDependence Matrix\n");
  fprintf(TFile, "stmts.size: %d\n", stmts.size());
  fprintf(TFile, "dependences.size: %d\n", dep_mat.size());
  fprintf(TFile, "==============================\n");
  print_defs_uses();
  print_dependence_matrix();
  fprintf(TFile, "==============================\n\n");
}


void Dependence_Matrix::print_defs_uses()
{
  int size = stmts.size();
  fprintf(TFile, "\n\n--- defs & uses:\n");
  for (int j=0; j < size; j++){
    fprintf(TFile, "statement %d: \n", j);
    print_statement_uses(j);
    print_statement_defs(j);
    fprintf(TFile, "\n");
  }
}


void Dependence_Matrix::print_statement_defs(int stmt_num)
{
  fprintf(TFile, "\tdefinitions: ");
  print_wst_set(defs[stmt_num]);
}


void Dependence_Matrix::print_statement_uses(int stmt_num)
{
  fprintf(TFile, "\tuses: ");
  print_wst_set(uses[stmt_num]);
}


void Dependence_Matrix::print_wst_set(std::set<WST_IDX>& wst_set)
{
  if (wst_set.empty()) {
    fprintf(TFile, "(empty)\n");
    return;
  }

  std::set<WST_IDX>::iterator i = wst_set.begin();
  for (; i != wst_set.end(); i++){
    print_wst_short(*i, wssa, ", ");
  }
  fprintf(TFile, "\n");
}


void Dependence_Matrix::print_dependence_matrix()
{
  int size = dep_mat.size();
  fprintf(TFile, "\n\n--- dependences:\n");
  for (int j=0; j < size; j++){
    print_dependence_vector(j);
  }
}


void Dependence_Matrix::print_dependence_vector(int j)
{
  bool first    = true;
  bool linefeed = false;
  for (int i=0; i < j; i++){
    if (dep_mat[i][j]){

      if (!first) fprintf(TFile, ",");
      fprintf(TFile, " (%d -> %d)", i, j);
      first    = false;
      linefeed = true;
    }
  }
  if (linefeed) fprintf(TFile, "\n");
}



// --------------------------------------------------------------------
// public routines for users
// --------------------------------------------------------------------

// true if there a dependence between i and j
bool Dependence_Matrix::is_dependent(int i, int j)
{
  return dep_mat[i][j] || dep_mat[j][i];
}



