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
//
// ====================================================================
//
// Module: early_exits.h
//
// Description:
//
// ====================================================================


#ifndef lwopt_early_exits_INCLUDED
#define lwopt_early_exits_INCLUDED

#include "comp_decl.h"
#include "wn_cfg.h"
#include "cfg_base.h"
#include "cfg_util.h"
#include "ir_reader.h"
#include "wssa_mgr.h"
#include "wssa_du.h"
#include "wn.h"
#include "wn_map.h"
#include "wn_util.h"
#include "targ_sim.h"
#include "opcode.h"
#include "symtab_utils.h"
#include <set>

class EARLY_EXITS_CHAIN;

class LWOPT_EARLYEXITS : public O64_Component {
public:
  enum OPTION {
    LWOPT_early_exits_first = OPT_component_first,
    LWOPT_early_exits_last = LWOPT_early_exits_first
  };

  static const O64_ComponentDescriptor ComponentDescriptor; 
  static const O64_OptionDescriptor
         OptionDescriptors[LWOPT_early_exits_last - LWOPT_early_exits_first + 1];

  LWOPT_EARLYEXITS() ;
  ~LWOPT_EARLYEXITS();

private:
  typedef std::list<EARLY_EXITS_CHAIN*> CHAIN_LIST;
  typedef CFG_UTIL::WN_CFG::BB_NODE BB_NODE;

  WN* _CurrentWN;
  WSSA::WHIRL_SSA_MANAGER* _CurrentWSSA;
  WSSA::WSSA_DU_MANAGER* _CurrentWSSA_DU;
  CFG_UTIL::WN_CFG* _CurrentWCFG;
  CHAIN_LIST _chains;
  std::vector<bool> _visited;
  MEM_POOL _mem_pool;

  void build_chains();
  void build_single_chain(INT32 id);
  bool eligible_for_early_exits(BB_NODE* bb);
  BB_NODE* find_best_successor(EARLY_EXITS_CHAIN* c, BB_NODE* bb);
  void transform(EARLY_EXITS_CHAIN* c); 

  void Perform_();
};

class EARLY_EXITS_CHAIN {
private:
  typedef CFG_UTIL::WN_CFG::BB_NODE BB_NODE;

  CFG_UTIL::WN_CFG* _cfg;
  MEM_POOL* _mem_pool;
  TRACE_OPTION_KIND _TraceKind;

  std::list<UINT32> _nodes;
  std::list<UINT32> _exit_nodes;
  INT32 _head_id;
  INT32 _tail_id;
  INT32 _default_target_id;

  std::list<WN*> _head_loads;
  INT32 _num_spec_loads; 

public:
  EARLY_EXITS_CHAIN(CFG_UTIL::WN_CFG* cfg, MEM_POOL* pool, TRACE_OPTION_KIND top) 
    : _cfg(cfg), _mem_pool(pool), _TraceKind(top) {
    _head_id = 0;
    _tail_id = 0;
    _default_target_id = 0;
    _num_spec_loads = 0;
  }
 
public:
  void add_to_chain(UINT32 bb_id) {
    if (_head_id == 0)
      _head_id = bb_id;
    _nodes.push_back(bb_id);  
    _tail_id=bb_id; 
  }
  bool trivial() {
    return (_nodes.size() < 4) || (_num_spec_loads == 0);
  }
  INT32 size() {
    return _nodes.size();
  } 
  INT32 head() {
    return _head_id;
  } 
  INT32 tail() {
    return _tail_id;
  } 
  INT32 default_target() {
    return _default_target_id;
  } 
  void incr_spec_loads(INT32 spec_loads) {
    _num_spec_loads += spec_loads;
  }

  UINT32 off_chain_succ(BB_NODE* bb);
  INT32  collect_iloads(BB_NODE* bb); 
  bool is_return_block(BB_NODE* bb);
  bool safe_to_speculate_loads(WSSA::WHIRL_SSA_MANAGER* ssa,
                               BB_NODE* bb, 
                               int* load_count);
  bool on_chain(UINT32 par_id, INT32 kid_id); 
  WN*  get_return_stmt(BB_NODE* bb); 
  WN*  determine_chain_exit_cond(BB_NODE* bb);
  WN*  determine_chain_branch_cond(BB_NODE* bb);
  bool beneficial_to_slp();
  void normalize_chain();
  void transform(WSSA::WHIRL_SSA_MANAGER* ssa,
                 WSSA::WSSA_DU_MANAGER* ssa_du_mgr,
                 WN* root); 
  bool has_live_uses(WSSA::WHIRL_SSA_MANAGER* ssa_mgr, 
                     WSSA::WSSA_DU_MANAGER* ssa_du_mgr);
  bool collect_defined_vars(std::set<std::pair<ST*, WN_OFFSET> >&, BB_NODE*);
  bool need_variable_renaming();
  bool exits_are_returns() ;
  WN * gen_switch_intrinsic(WSSA::WHIRL_SSA_MANAGER* ssa,
                            WN* root);
  WN * gen_switch_branch_intrinsic(WSSA::WHIRL_SSA_MANAGER* ssa,
                                   WN* root);
  bool has_load_within_distance(WSSA::WHIRL_SSA_MANAGER* ssa,
                                WN* iload, 
                                UINT32 veclength); 
  void move_code(UINT32 source, UINT32 dest);
  bool defined_in_bb(BB_NODE *bb, WN *new_def);
  void move_code_if_not_live(WSSA::WHIRL_SSA_MANAGER* ssa_mgr,
                             WSSA::WSSA_DU_MANAGER*  du_mgr,
                             UINT32 source,
                             UINT32 dest);
  void dump(); 
};

#endif /* lwopt_early_exits_INCLUDED */

