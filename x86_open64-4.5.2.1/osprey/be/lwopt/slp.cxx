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
// Module: slp.cxx
//
// Description:
// This file contains LWOPT_SLP object, which processes command line
// options for SLP and calls the top-level function SLP_Main::perform()
// for each basic block in the given program unit.
// 
// ====================================================================

#include "slp.h"

using namespace slp;



void 
LWOPT_PerformSLP()
{
    LWOPT_SLP lwopt_slp;
}



const O64_ComponentDescriptor LWOPT_SLP::ComponentDescriptor =
{
    O64_COMPONENT_DESC("Superword-Level Parallelization", "SLP", OptionDescriptors)
};



const O64_OptionDescriptor LWOPT_SLP::OptionDescriptors[] =
{
    O64_OPTION_DESC(LWOPT_slp_skip_BB_before, "skip the basic blocks before",
                "skip_bb_b", "sbb", OVK_UINT32, OV_INTERNAL, false, 0, 0, UINT32_MAX),
    O64_OPTION_DESC(LWOPT_slp_skip_BB_after, "skip the basic blocks after",
                "skip_bb_a", "sba", OVK_UINT32, OV_INTERNAL, false, UINT32_MAX, 0, UINT32_MAX),
    O64_OPTION_DESC(LWOPT_slp_last, "end marker", 0, 0, OVK_INVALID, OV_INTERNAL, false, 0, 0, 0)
};




static O64_ComponentInitializer lwopt_slp_init(
    COMPONENT_lwopt_slp, &LWOPT_SLP::ComponentDescriptor);
    



LWOPT_SLP::LWOPT_SLP()
    :O64_Component(COMPONENT_lwopt_slp)
{
    if (!_enable) return;
    _skip_BB_before = _CurrentOption->GetUIntOption(_CurrentComponent, LWOPT_slp_skip_BB_before);
    _skip_BB_after  = _CurrentOption->GetUIntOption(_CurrentComponent, LWOPT_slp_skip_BB_after);

    MEM_POOL slp_pool;
    MEM_POOL_Initialize(&slp_pool, "SLP POOL", FALSE);
    mem_pool = &slp_pool;
    
    CurrentWN_   = _Driver->GetCurrentWN();
    CurrentWCFG_ = _Driver->GetCurrentWCFG();
    CurrentWSSA_ = _Driver->GetCurrentWSSA();
    Current_Alias= _Driver->GetAliasMgr();

    Current_DU_  = CXX_NEW(WSSA_DU_MANAGER(CurrentWSSA_, CurrentWN_),mem_pool);  
    Current_DU_->Build();

    if (_TraceKind >= TRACE_maximal) dump_tree_ssa(CurrentWN_);
    Perform_();
    MEM_POOL_Delete(&slp_pool);
    if (_TraceKind >= TRACE_maximal) dump_tree_ssa(CurrentWN_);
}




LWOPT_SLP::~LWOPT_SLP()
{
}




void 
LWOPT_SLP::Perform_()
{
  if (_TraceKind >= TRACE_info) {
    fprintf(TFile, "\n============================================================\n");
    print_PU_name("SLP: PU_name(%s)\n");
    fprintf(TFile, "\n============================================================\n");
  }
  
  WSSA_UPDATER updater(CurrentWN_, CurrentWCFG_, CurrentWSSA_); 
  updater.Enable_update_cfg();
//   updater.Enable_update_ssa();
  WN_CFG::dfs_fwd_iterator fit = CurrentWCFG_->Dfs_fwd_begin();

  // call SLP once per basic block
  for(; fit != CurrentWCFG_->Dfs_fwd_end(); ++fit) {
    WN_CFG::BB_NODE* bb = &(*fit);
    if (bb == CurrentWCFG_->Get_dummy_entry()) continue;

    // skip the basic blocks specified in the command line
    UINT32 bb_ID = bb->Get_id();
    if (_TraceKind >= TRACE_info) { fprintf(TFile, "bb_ID(%d):\n", bb_ID); }
    if (bb_ID < _skip_BB_before || bb_ID > _skip_BB_after) continue;

    SLP_Main slp_mgr(CurrentWSSA_, CurrentWCFG_, Current_DU_, Current_Alias, 
		     bb, mem_pool, updater, _TraceKind);
    bool success = slp_mgr.perform();
    if (!success) continue;

    if (_TraceKind >= TRACE_info) { 
      fprintf(TFile, "bb_ID(%d): vectorized\n", bb_ID); }

    WSSA_UPDATER ssa_upd(CurrentWN_, CurrentWCFG_, CurrentWSSA_);
//     ssa_upd.Rename_BB(bb);
  }
  
}
