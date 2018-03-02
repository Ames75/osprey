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
// Module: slp_distance.cxx
//
// Description:
// Distance analysis finds the distance in number of bytes between two
// memory accesses. The basic algorithm is taken from the original SLP
// implementation by Sam Larsen and Saman Amarasinghe at MIT. Each
// variable used in address computation is expressed as a linear 
// equation of other variables used in computing it. The result of 
// this analysis can also be used in checking dependence between two
// memory accesses as implemented in Distance_Analysis::are_independent().
// If any address variable is a non-linear function of other variables, 
// it is redefined as a linear function of itself. Distance is represented
// as a tuple of 'group' and 'offset'. All memory accesses that have a 
// common base address form a group and are assigned the same group ID. 
// For two memory accesses in a group, the difference in 'offset's is 
// the distance in bytes.
// 
// ====================================================================

#include "slp.h"

using namespace slp;


// for real WHIRL Nodes
Distance_Analysis::Distance_Analysis(
		   std::vector<Statement*>&  s, 
		   std::map<VER_IDX, LinEq>& l,
		   WHIRL_SSA_MANAGER*        w,
		   TRACE_OPTION_KIND         trace_kind): 
  stmts(s), lin_eqs(l), wssa(w), _TraceKind(trace_kind)
{
  // evaluate linear equations for address symbols
  eval_linear_equations();

  // evaluate linear equations for address computing WHIRL nodes
  eval_address_nodes();

  assign_distance();
}



Distance_Analysis::~Distance_Analysis()
{
}



// --------------------------------------------------------------------
// Step 1. 
// compute a linear equation for each variable used in address 
// computation
// --------------------------------------------------------------------

// 1. initialize linear eq. for all address variables used
//    in this stmt unless they are initialized already
// 2. evaluate the whole RHS and assign to LHS
void Distance_Analysis::eval_linear_equations()
{
  int num_stmts = stmts.size();
  for(int i=0; i<num_stmts; i++){
    Statement* stmt = stmts[i];
    if (stmt->has_def() && is_addr_sym(stmt->def())){
      VER_IDX vidx = stmt->def();

      LinEq leq = eval(stmt->whirl_node());

      // for non-linear eq, make a linear of itself.
      if (leq.is_non_linear()) leq = LinEq(vidx, 0);

      Is_True(lin_eqs.find(vidx) != lin_eqs.end(), 
	      ("Distance_Analysis::eval_linear_equations: none in lin_eqs"));
      lin_eqs[vidx] = leq;
    }
  }
}



LinEq Distance_Analysis::eval(WN* wn)
{
  // use ST_IDX for array symbols in place of VER_IDX
  if (WN_is_LDID_from_array(wn) || WN_is_STID_into_array(wn))
    return LinEq(st2ver_idx(WN_st_idx(wn)),WN_offset(wn));

  const OPERATOR op = WN_operator(wn);
  switch(op)
    {
    case OPR_LDID: 
      {
	Is_True(WN_has_ver(wn), ("LinEq: LDID/STID with no VER"));
	VER_IDX vidx = wssa->Get_wn_ver(wn);
	Is_True (lin_eqs.find(vidx) != lin_eqs.end(), 
		 ("Distance_Analysis::eval: addr sym not found in lin_eqs"));

	if (lin_eqs[vidx].is_non_linear()) lin_eqs[vidx] = LinEq(vidx, 0);
	return lin_eqs[vidx];
      }
    case OPR_ADD: return eval(WN_kid0(wn)) + eval(WN_kid1(wn));
    case OPR_SUB: return eval(WN_kid0(wn)) - eval(WN_kid1(wn));
    case OPR_MPY: return eval(WN_kid0(wn)) * eval(WN_kid1(wn));
    case OPR_NEG: return-eval(WN_kid0(wn));
    case OPR_STID:
    case OPR_CVT:
    case OPR_CVTL:return eval(WN_kid0(wn));
    case OPR_INTCONST: return LinEq(WN_const_val(wn));
    case OPR_LDA: return LinEq(st2ver_idx(WN_st_idx(wn)),WN_offset(wn));
    default:;
    }

  return LinEq();
}




// --------------------------------------------------------------------
// Step 2. 
// compute a linear equation for each address computing WN
// --------------------------------------------------------------------

// evaluate the address computations
void Distance_Analysis::eval_address_nodes()
{
  int num_stmts = stmts.size();
  for(int i=0; i<num_stmts; i++){
    Statement* stmt = stmts[i];
    eval_address_nodes(stmt->whirl_node());
  }
}



// evaluate the address computations
void Distance_Analysis::eval_address_nodes(WN* wn)
{
  const OPERATOR op = WN_operator(wn);
  switch(op)
    {
      // store the LOAD or STORE node instead of the address operand
    case OPR_LDID: 
    case OPR_STID: 
      if (WN_is_LDID_from_array(wn) || WN_is_STID_into_array(wn))
	addr_lin_eqs[wn] = eval(wn); break;
    case OPR_ILOADX: 
      addr_lin_eqs[wn] = eval(WN_kid0(wn)) + eval(WN_kid1(wn)); break;
    case OPR_ILOAD:
    case OPR_MLOAD:
      addr_lin_eqs[wn] = eval(WN_kid0(wn)) + LinEq(WN_offset(wn)); 
      break;
    case OPR_ISTOREX:
      addr_lin_eqs[wn] = eval(WN_kid1(wn)) + eval(WN_kid2(wn)); break;
    case OPR_ISTORE: 
    case OPR_MSTORE: 
      addr_lin_eqs[wn] = eval(WN_kid1(wn)) + LinEq(WN_offset(wn)); 
      break;
    default: ;
    }
  for(INT i=0; i<WN_kid_count(wn); i++) 
    eval_address_nodes(WN_kid(wn, i));
}




// --------------------------------------------------------------------
// Step 3. 
// assign to each address node a pair of group number and offset
// based on the linear equation
// --------------------------------------------------------------------

void Distance_Analysis::assign_distance()
{
  // distance group: memory accesses with constance distances
  int distance_group_num = 1;
  std::map<WN*, LinEq>::iterator i = addr_lin_eqs.begin();
  for (; i != addr_lin_eqs.end(); i++){
    WN* mem_node1 = i->first;
    if (is_dist_assigned(mem_node1)) continue;

    // create a new group
    set_distance(mem_node1, distance_group_num);

    // now, look for memory accesses in the same group
    std::map<WN*, LinEq>::iterator j = i;
    for (j++; j != addr_lin_eqs.end(); j++){
      WN* mem_node2 = j->first;
      if (is_dist_assigned(mem_node2)) continue;
    
      // compute the difference between mem_node1 and mem_node2
      LinEq diff = addr_lin_eqs[mem_node1] - addr_lin_eqs[mem_node2];

      // put this in the same group if the difference is constant 
      if (diff.is_constant())
	       set_distance(mem_node2, distance_group_num);
    }
    distance_group_num++;
  }
}


void Distance_Analysis::set_distance(WN* wn, int group_num)
{
  int offset;

  LinEq& leq = addr_lin_eqs[wn];
  if (leq.is_non_linear()) offset = 0;
  else offset = leq.constant();

  distances[wn] = Distance(group_num, offset);
}


bool Distance_Analysis::is_dist_assigned(WN* wn)
{
  return distances.find(wn) != distances.end();
}




// --------------------------------------------------------------------
// for external queries
// --------------------------------------------------------------------

// true if the two statements, i and j are independent
// statements i and j are independent if 
// - they belong to the same distance group, and
// - they access different offsets in the group
bool Distance_Analysis::are_independent(WN* mem_i, WN* mem_j)
{
  Distance d_i = get_distance(mem_i);
  Distance d_j = get_distance(mem_j);

  if (!are_same_group(d_i, d_j)) {
    if (_TraceKind >= TRACE_maximal) 
      fprintf(TFile, "Distance_Analysis::are_independent: false from are_same_group(%d, %d)\n", d_i.first, d_j.first);
    return false;
  }
  if (are_same_offset(d_i, d_j)) {
    if (_TraceKind >= TRACE_maximal) 
      fprintf(TFile, "Distance_Analysis::are_independent: false from are_same_offset(%d, %d)\n", d_i.second, d_j.second);
    return false;
  }

  return true;
}


Distance Distance_Analysis::get_distance(WN* addr)
{
  if (_TraceKind >= TRACE_maximal && 
      distances.find(addr) == distances.end())
    fdump_tree(TFile, addr);
  Is_True(distances.find(addr) != distances.end(),
	  ("Distance_Analysis::get_distance: addrress not found"));

  return distances[addr];
}


bool Distance_Analysis::are_same_group(Distance d1, Distance d2)
{
  return d1.first == d2.first;
}



bool Distance_Analysis::are_same_offset(Distance d1, Distance d2)
{
  return d1.second == d2.second;
}



// true if s2 is adjacent to the right of s1
// i.e., s1 references a higher address than s1 by the type size
// So, this is NOT commutative.
bool Distance_Analysis::are_adjacent_mem_refs(Statement_ID s1, Statement_ID s2)
{
  if (_TraceKind >= TRACE_maximal) 
    fprintf(TFile, ">>> %d -> %d: in are_adjacent\n", s1, s2);
  Statement* stmt1 = stmts[s1];
  Statement* stmt2 = stmts[s2];

  // both should have at least one memory reference
  if (stmt1->num_loads() == 0 && stmt1->num_stores() == 0) {
    if (_TraceKind >= TRACE_maximal)
      fprintf(TFile, ">>> %d -> %d: no memory accesses\n", s1, s2);
    return false;
  }

  if (stmt1->num_loads()  != stmt2->num_loads()   || 
      stmt1->num_stores() != stmt2->num_stores()) {
    if (_TraceKind >= TRACE_maximal) {
      if (stmt1->num_loads()  != stmt2->num_loads())
	fprintf(TFile, ">>> %d -> %d: # loads are different\n", s1, s2);
      if (stmt1->num_stores() != stmt2->num_stores())
	fprintf(TFile, ">>> %d -> %d: # stores are different\n", s1, s2);
    }
    return false;
  }

  WN* node1 = stmt1->whirl_node();
  WN* node2 = stmt2->whirl_node();

  bool adjacent = are_adjacent_mem_refs(node1, node2);
  
  if (_TraceKind >= TRACE_maximal) {
    if (adjacent) { fprintf(TFile, ">>> %d -> %d: adjacent\n", s1, s2);}
    else { fprintf(TFile, ">>> %d -> %d: NOT adjacent\n", s1, s2);}
  }
  return adjacent;
}



// true if wn2 is adjacent to the right of wn1
// i.e., wn2 references a higher address than wn1 by the type size
// So, this is NOT commutative.
bool Distance_Analysis::are_adjacent_mem_refs(WN* wn1, WN* wn2)
{
  if (wn1 == NULL && wn2 == NULL) return true;
  if (wn1 == NULL || wn2 == NULL) {
    if (_TraceKind >= TRACE_maximal) 
      fprintf(TFile, ">>> are_adjacent_mem_refs(WN*): false <- a WN is NULL\n");
    return false;
  }

  OPERATOR op1 = WN_operator(wn1);
  OPERATOR op2 = WN_operator(wn2);
  if (op1 != op2) {
    if (_TraceKind >= TRACE_maximal) 
      fprintf(TFile, ">>> are_adjacent_mem_refs(WN*): false <- op is not same\n");
    return false;
  }
  if (WN_is_mem_opr(wn1)){
    int typesize1, typesize2;
    switch(op1)
      {
      case OPR_LDID:  
      case OPR_ILOADX:  
      case OPR_ILOAD:
      case OPR_MLOAD: 
	typesize1 = TY_size(WN_ty(wn1)); 
	typesize2 = TY_size(WN_ty(wn2)); break;
      case OPR_STID: 
      case OPR_ISTOREX: 
      case OPR_ISTORE: 
      case OPR_MSTORE:
	typesize1 = TY_size(WN_object_ty(wn1)); 
	typesize2 = TY_size(WN_object_ty(wn2)); break;
      default: Is_True(0, ("Distance_Analysis::are_adjacent_mem_refs: unexpected"));
      }
    if (typesize1 != typesize2) {
      if (_TraceKind >= TRACE_maximal) 
	fprintf(TFile, ">>> are_adjacent_mem_refs(WN*): false <- typesize not same\n");
      return false;
    }
    Distance d1 = get_distance(wn1);
    Distance d2 = get_distance(wn2);
    if (!are_same_group(d1, d2)) {
      if (_TraceKind >= TRACE_maximal) 
	fprintf(TFile, ">>> are_adjacent_mem_refs(WN*): false <- group not same\n");
      return false;
    }
    if (d1.second + typesize1 != d2.second) {
      if (_TraceKind >= TRACE_maximal) 
	fprintf(TFile, ">>> are_adjacent_mem_refs(WN*): false <- d1.second(%d) + typesize1(%d) != d2.second(%d)\n", d1.second, typesize1, d2.second);
      return false;
    }
  }

  if (WN_kid_count(wn1) != WN_kid_count(wn2)) {
    if (_TraceKind >= TRACE_maximal) 
      fprintf(TFile, ">>> are_adjacent_mem_refs(WN*): false <- kid_count\n");
    return false;
  }
  for(INT i=0; i<WN_kid_count(wn1); i++)
    if (!WN_is_address_operand(wn1, i)) // don't check address computations
      if (!are_adjacent_mem_refs(WN_kid(wn1, i), WN_kid(wn2, i))){
	if (_TraceKind >= TRACE_maximal) 
	  fprintf(TFile, ">>> are_adjacent_mem_refs(WN*): false <- %d-th kid\n", i);
	return false;
      }
  return true;
}
  





// --------------------------------------------------------------------
// Debug routines
// --------------------------------------------------------------------

void Distance_Analysis::print()
{
  fprintf(TFile, "\n\nDistance Analysis\n");
  fprintf(TFile, "stmts.size: %d\n", stmts.size());
  fprintf(TFile, "lin_eqs(address variables).size: %d\n", lin_eqs.size());
  fprintf(TFile, "addr_lin_eqs(address nodes).size: %d\n", addr_lin_eqs.size());
  fprintf(TFile, "distances.size: %d\n", distances.size());
  fprintf(TFile, "==============================\n");
  print_distances();
  print_addr_leqs();
  print_lin_eqs();
  fprintf(TFile, "==============================\n\n");
}


void Distance_Analysis::print_distances()
{
  std::map<WN*, Distance>::iterator i = distances.begin();
  fprintf(TFile, "\n\n--- distances:\n");
  for (; i != distances.end(); i++){
    print_distance(i->first, i->second);
  }
}


void Distance_Analysis::print_distance(WN* wn, Distance d)
{
  fprintf(TFile, "%s: group(%d), offset(%d)\n", 
	        OPCODE_name(WN_opcode(wn))+4, d.first, d.second);
}


void Distance_Analysis::print_addr_leqs()
{
  std::map<WN*, LinEq>::iterator i = addr_lin_eqs.begin();
  fprintf(TFile, "\n\n--- addr_lin_eqs:\n");
  for (; i != addr_lin_eqs.end(); i++){
    print_addr_leq(i->first, i->second);
  }
}


void Distance_Analysis::print_addr_leq(WN* wn, LinEq leq)
{
  fprintf(TFile, "%s: ", OPCODE_name(WN_opcode(wn))+4);
  leq.print(wssa, 0);
}


void Distance_Analysis::print_lin_eqs()
{
  std::map<VER_IDX, LinEq>::iterator i = lin_eqs.begin();
  fprintf(TFile, "\n\n--- lin_eqs for address symbols:\n");
  for (; i != lin_eqs.end(); i++){
    print_lin_eq(i->first, i->second);
  }
}


void Distance_Analysis::print_lin_eq(VER_IDX vi, LinEq leq)
{
  print_VER_IDX(vi, wssa);
  fprintf(TFile, " ---> ");
  leq.print(wssa, 0);
}





