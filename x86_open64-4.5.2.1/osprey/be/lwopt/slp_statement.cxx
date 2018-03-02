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
// Module: slp_statement.cxx
//
// Description:
// This file describes Statement, an object that abstracts a statement.
// Basically, it collects various statement information necessary for
// later passes and answers inquiries by them.
// ====================================================================

#include "slp.h"

using namespace slp;


// for real WHIRL Nodes
Statement::Statement(Statement_ID id, WN* node, WHIRL_SSA_MANAGER* wssa): 
  _id(id), packed_lower(false), packed_higher(false), wn(node)
{
  dst           = WN_get_dst_sym(node, wssa);
  collect_loads_stores(wn);
  _num_loads    = loads.size();
  _num_stores   = stores.size();

  // collects all source operands
  find_sources(srcs, wn, wssa);

  find_addr_syms(addrs, wn, wssa);

  simd_op = WN_is_vectorizable_stmt(wn);
}




Statement::~Statement()
{
}


// fill 'loads' and 'stores'
void Statement::collect_loads_stores(WN* wn)
{
  const OPERATOR op = WN_operator(wn);
  switch(op)
    {
    case OPR_ILOADX:  
    case OPR_ILOAD:
    case OPR_MLOAD: loads.push_back(wn); break;
    case OPR_LDID:  
      if(WN_is_LDID_from_array(wn))
	loads.push_back(wn); break;
    case OPR_ISTOREX: 
    case OPR_ISTORE: 
    case OPR_MSTORE:stores.push_back(wn); break;
    case OPR_STID:  
      if(WN_is_STID_into_array(wn))
	stores.push_back(wn); break;
    default: ;
    }

  for(INT i=0; i<WN_kid_count(wn); i++)
    collect_loads_stores(WN_kid(wn, i));
}





// ds_map: map from a dst to a set of source symbols
void Statement::map_dst_srcs(
		       std::map<VER_IDX,std::set<VER_IDX> >& ds_map)
{
  if (has_def()) ds_map[dst] = srcs;
}



// collect address symbols for all address syms of 'this'
// ds_map: map from a dst to a set of source symbols
void Statement::collect_address_syms(
		       std::map<VER_IDX, LinEq>& lin_eqs, 
		       std::map<VER_IDX, std::set<VER_IDX> >& ds_map)
{
  if (!has_addr_syms()) return;

  std::set<VER_IDX>::iterator ait = addrs.begin();
  for (; ait != addrs.end(); ait++)
    collect_address_syms_onesym(lin_eqs, ds_map, *ait);
}



// collect address symbols for the given symbol by following 
// dependence chains.
//
// ds_map: map from a dst to a set of source symbols
void Statement::collect_address_syms_onesym(
		       std::map<VER_IDX, LinEq>& lin_eqs,
		       std::map<VER_IDX,std::set<VER_IDX> >& ds_map,
		       VER_IDX addr_sym)
{
  // do nothing if the given symbol is already in 'lin_eqs'.
  // Here, we assume that all symbols are defined only once
  // following the definition of SSA.
  if (lin_eqs.find(addr_sym) != lin_eqs.end()) return;

  // otherwise, put it in 'lin_eqs' and 
  lin_eqs.insert(std::pair<VER_IDX, LinEq>(addr_sym, LinEq()));

  // do nothing if 'addr_sym' does not have source operands
  if (ds_map.find(addr_sym) == ds_map.end()) return;

  // do the same for its dependent variables
  std::set<VER_IDX>& dependent_syms = ds_map[addr_sym];
  std::set<VER_IDX>::iterator sit = dependent_syms.begin();
  for (; sit != dependent_syms.end(); sit++)
    collect_address_syms_onesym(lin_eqs, ds_map, *sit);
}





bool Statement::are_isomorphic(Statement* stmt1)
{
  WN* wn1 = stmt1->whirl_node();
  return WN_are_isomorphic_nodes(wn, wn1);
}





bool Statement::has_side_effects()
{
  const OPERATOR op = WN_operator(wn);
  switch(op)
    {
    case OPR_GOTO:
    case OPR_COMPGOTO:
    case OPR_LABEL:
    case OPR_RETURN:
    case OPR_RETURN_VAL:
    case OPR_CALL:  
    case OPR_ICALL:
    case OPR_INTRINSIC_CALL: return true;
    default: ;
    }
  return false;
}





void Statement::print(WHIRL_SSA_MANAGER* wssa)
{
  fprintf(TFile, "   ++++++++++++++++++++ Statement(%d) typesize(%d) begin:\n", _id, _stmt_typesize);
  const OPERATOR op = WN_operator(wn);

  dump_tree_ssa(wn);
  if (WN_has_ver(wn)) {
    VER_IDX stmt_vidx = wssa->Get_wn_ver(wn);
    fprintf(TFile, "   VER_IDX(%d): ", (unsigned)stmt_vidx);

    print_VER_IDX(dst, wssa);
    // wssa->Print_ver(stmt_vidx, stdout);
  }
  else{
    fprintf(TFile, "   No VER_IDX(%s): ", OPERATOR_name(op));
  }

  fprintf(TFile, "\n   -------------------- Statement(%d) end.\n", _id);
}

