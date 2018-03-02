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
// Module: slp_main.cxx
//
// Description:
// This is the main file that calls all other functions of SLP at the highest 
// level. SLP_Main is the object that performs all sub-tasks of SLP. For each
// basic block, an SLP_Main object is created and all next level functions
// are called from inside SLP_Main::perform(), which returns 'true' if the
// basic block is vectorized.
// 
// ====================================================================

#include "slp.h"

using namespace slp;

SLP_Main::SLP_Main(WHIRL_SSA_MANAGER*         wssa_mgr, 
		   WN_CFG*                    wssa_cfg,
		   WSSA_DU_MANAGER*           wssa_du,
		   ALIAS_MANAGER*             alias,
		   WN_CFG::BB_NODE*           nd, 
		   MEM_POOL*                  mpool,
		   WSSA_UPDATER&              updater,
		   TRACE_OPTION_KIND          trace_kind): 
  _early_exit(false), wssa(wssa_mgr), wcfg(wssa_cfg), slp_du_mgr(wssa_du), 
  slp_alias(alias), bb(nd), bb_ID(nd->Get_id()), slp_mem_pool(mpool), 
  wssa_updater(updater), _TraceKind(trace_kind), SIMD_register_width(16) // fix this
{
}

SLP_Main::~SLP_Main()
{
}




// --------------------------------------------------------------------
// high-level routines
// --------------------------------------------------------------------

// main routine:
// true if some code modification is made
bool SLP_Main::perform()
{
  collect_info();
  if (stmts.size() == 0) return false;

  // initially, only for the basic blocks with 'early-exits'
  if (!has_early_exit()) return false;

  if (_TraceKind >= TRACE_maximal) 
    slp_trace_title(TRACE_maximal, "Distance analysis");
  Distance_Analysis dists(stmts, lin_eqs, wssa, _TraceKind);
  if (_TraceKind >= TRACE_minimal) dists.print();


  if (_TraceKind >= TRACE_maximal) 
    slp_trace_title(TRACE_maximal, "Dependence analysis");
  Dependence_Matrix deps(stmts.size(), stmts, wssa, dists, slp_alias, 
			 _TraceKind);
  if (_TraceKind >= TRACE_minimal) deps.print();


  if (_TraceKind >= TRACE_maximal) 
    slp_trace_title(TRACE_maximal, "Pack statements");
  pack_statements(deps, dists); // slp_main_pack.cxx
  if (stmt_packs.empty()) return false;
  if (_TraceKind >= TRACE_minimal) print_stmt_packs();


  if (_TraceKind >= TRACE_maximal) 
    slp_trace_title(TRACE_maximal, "Schedule statements");
  Scheduler sched(stmts, stmt_packs, deps);
  sched.schedule_main();
  if (_TraceKind >= TRACE_minimal) sched.print();


  if (_TraceKind >= TRACE_maximal) 
    slp_trace_title(TRACE_maximal, "Transformation");
  Transform trans(wcfg, bb, wssa, slp_du_mgr, stmts, sched, slp_mem_pool,
		  wssa_updater, SIMD_register_width, _TraceKind, _early_exit);
  trans.transform();

  return true;
}




// collect some basic information useful for later passes such as
// building dependence matrix and distance analysis
// 
// This function goes through each instruction in the current basic block 
// to collect necessary information for the subsequent passes.
// 1.	Statement ID: Statement_ID
//      Each true statement is assigned an integer ID starting from zero. 
//      This ID is used in the later passes for packing and scheduling. 
// 2.	Mapping from a destination operand (operand being defined in
//      the LHS, represented in VER_IDX) to source operands (operands 
//      being referenced in the RHS): Statement::map_dst_srcs()
//      This mapping is used in distance analysis.
// 3.	Collect address symbols: Statement::collect_address_syms()
//      'Address symbols' are the VER_IDX's used in computing address 
//      expressions. They are collected for use in the distance analysis.
// 4.	_early_exit is set to true if one of the Early_Exits intrinsics is 
//      found. Initially, SLP is activated only for the basic blocks with 
//      Early_Exits intrinsics.
void SLP_Main::collect_info()
{
  if (_TraceKind >= TRACE_minimal)
    slp_trace_title(TRACE_minimal, "SLP_Main::collect_info");

  WN_CFG::BB_NODE::stmt_iterator sit;
  Statement_ID stmt_id = 0;
  for (sit = bb->Stmt_begin(); sit != bb->Stmt_end(); ++sit) {
    WN* wn = &(*sit);

    // filter out non-real statements
    if (!WN_is_true_statement(wn)) {
      if (_TraceKind >= TRACE_maximal) 
	slp_dump_tree(TRACE_maximal, 
		      "collect_info: skipping a non-true statement.\n", wn);
      continue;
    }

    Statement* stmt = CXX_NEW(Statement(stmt_id, wn, wssa), slp_mem_pool);
    stmts.push_back(stmt);
    stmt_ID[wn] = stmt_id++;
    stmt->set_stmt_typesize(get_stmt_typesize(wn));

    // set up the mapping from a dst to its srcs
    stmt->map_dst_srcs(ds_map);

    stmt->collect_address_syms(lin_eqs, ds_map);
    if (WN_is_SwitchReturn(wn) || WN_is_SwitchBranch(wn)) 
      _early_exit = true;
  }
  
  if (_TraceKind >= TRACE_minimal) print_collected_info();
}


// - returns the statement's type size in bytes
// - used in determining vector length of statements
// - 0 for two different type sizes
int SLP_Main::get_stmt_typesize(WN* wn)
{
  if (!wn) return -1; // ignore this node if -1 is returned
  int typesize = -1;
  if (!WN_is_SwitchReturn(wn) && !WN_is_SwitchBranch(wn)) {
    for (int i=0; i<WN_kid_count(wn); i++)
      if (!WN_is_address_operand(wn, i)) {
	int temp = get_stmt_typesize(WN_kid(wn, i));
	if (temp == -1) continue;
	if (typesize == -1)
	  typesize = temp;
	else
	  if (typesize != temp) return 0; // 0 for more than two type sizes
      }
  }

  switch(WN_operator(wn))
    {
    case OPR_CVTL:
    case OPR_CVT: return 0;
    case OPR_LDA:
    case OPR_CONST:
    case OPR_INTCONST: return MTYPE_byte_size(WN_rtype(wn));
    case OPR_ILOADX:  
    case OPR_ILOAD:
    case OPR_MLOAD:return TY_size(WN_object_ty(wn)); 
    case OPR_ISTOREX: 
    case OPR_ISTORE: 
    case OPR_MSTORE: 
      return TY_size(WN_object_ty(wn)); 
    case OPR_LDID: {
      if (WN_is_LDID_from_array(wn)) 
	return TY_size(TY_etype(ST_type(WN_st_idx(wn))));
      
      VER_IDX vidx = wssa->Get_wn_ver(wn);
      if (ver_typesize.find(vidx) != ver_typesize.end())
	return ver_typesize[vidx];

      ST_IDX st_idx = WN_st_idx(wn);
      ST_CLASS st_class = ST_class(st_idx);
      if (st_class == CLASS_VAR  || st_class == CLASS_CONST ||
	  st_class == CLASS_PREG || st_class == CLASS_NAME)
	return TY_size(ST_type(st_idx));
      else
	return MTYPE_byte_size(WN_desc(wn));
    }
    case OPR_STID: 
      if (typesize != 0) {
	VER_IDX vidx = wssa->Get_wn_ver(wn);
	ver_typesize[vidx] = typesize;
      }
      break;
    case OPR_INTRINSIC_CALL: 
      if (WN_is_SwitchReturn(wn)) {
	WN* arg1 = WN_kid0(WN_kid0(wn));
	VER_IDX vidx = wssa->Get_wn_ver(arg1);
	if (ver_typesize.find(vidx) != ver_typesize.end())
	  return ver_typesize[vidx];
	return MTYPE_byte_size(WN_rtype(arg1));
      }
      else return 0;
      break;
    case OPR_COMPGOTO:
      if (WN_is_SwitchBranch(wn)) {
	WN* arg1 = WN_kid0(WN_kid0(WN_kid0(wn)));
	VER_IDX vidx = wssa->Get_wn_ver(arg1);
	if (ver_typesize.find(vidx) != ver_typesize.end())
	  return ver_typesize[vidx];
	return MTYPE_byte_size(WN_rtype(arg1));
      }
      break;

      // All other leaf nodes will not be vectorized.
    default: 
      if (typesize == -1)
	return 0; 
    }

  Is_True(typesize!=-1, ("SLP_Main::get_stmt_typesize: unknown typesize"));
  return typesize;
}







// --------------------------------------------------------------------
// debug/trace routines
// --------------------------------------------------------------------
void SLP_Main::print_addr_syms()
{
  // print address variables
  fprintf(TFile, "\n========================================\n");
  fprintf(TFile, "address variables:\n");
  fprintf(TFile, "========================================\n");

  std::map<VER_IDX, LinEq>::iterator ait = lin_eqs.begin();
  for (; ait != lin_eqs.end(); ait++){
    print_VER_IDX(ait->first, wssa);
    fprintf(TFile, "\n");
  }
  fprintf(TFile, "\n\n");
}



void SLP_Main::print_dstsrc_map()
{
  // print address variables
  fprintf(TFile, "\n========================================\n");
  fprintf(TFile, "dst -> src mapping:\n");
  fprintf(TFile, "========================================\n");

  std::map<VER_IDX, std::set<VER_IDX> >::iterator mit = ds_map.begin();
  for (; mit != ds_map.end(); mit++){
    print_VER_IDX(mit->first, wssa);
    fprintf(TFile, " -> ");

    std::set<VER_IDX>& src_set = mit->second;
    std::set<VER_IDX>::iterator sit = src_set.begin();
    for (bool first=true; sit != src_set.end(); sit++, first=false){
      if (!first) fprintf(TFile, ", ");
      print_VER_IDX(*sit, wssa);
    }
    fprintf(TFile, "\n");
  }
  fprintf(TFile, "\n\n");
}




void SLP_Main::print_stmt_packs()
{
  if (stmt_packs.empty()) {
    fprintf(TFile, " (empty)\n");
    return;
  }

  fprintf(TFile, "\n	--------------------\n");
  std::list<Statement_Pack*>::iterator lit = stmt_packs.begin();
  for (; lit != stmt_packs.end(); lit++){
    (*lit)->print();fprintf(TFile, ", ");
  }
  fprintf(TFile, "\n	--------------------\n");
}




void SLP_Main::print_collected_info()
{
  int num_statements = stmts.size();
  if (num_statements == 0) return;
  for (int i=0; i<num_statements; i++){
    stmts[i]->print(wssa);
  }

  print_addr_syms();
  print_dstsrc_map();
}




