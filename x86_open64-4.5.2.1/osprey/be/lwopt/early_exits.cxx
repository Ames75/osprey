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
// Module: early_exits.cxx
//
// Description:
// This file contains all implementations that detect and transform 
// code for Early Exits. A typical example is found in a function, 
// mainGtU() between line 406 and 453 of blocksort.c of 401.bzip2, 
// SPECint2006. An Early Exits chain consists of a chain of basic blocks
// starting with a 'head block' and a set of 'exit blocks', each of 
// which has a CFG edge from one of the chain blocks as shown below.
//                         212
//                        / |
//                       v  v
//                     213  214
//                        / |
//                       v  v
//                     215  216
//                        ...
//                        / |
//                       v  v
//                     233  234
//                        / |
//                       v  v
//                     235  236
// In this example, the chain contains 12 basic blocks from 212 to 234,
// and there are 12 exit blocks from 213 to 235. Block 236 is the first
// block outside the chain. The above scalar chain is transformed to 
// the following vector chain. 
//                         212
//                         (vector comparison)
//                        / |
//                       v  v
//                     236 (new block)
//                        / |
//                       v  v
//                     213  214
//                        / |
//                       v  v
//                     215  216
//                        ...
//                        / |
//                       v  v
//                     233  234
//                        / 
//                       v  
//                     235  
// There are two main factors that can improve performance in this 
// transformation. The first is SIMD parallelism. Instructions that
// are scattered in chain blocks are speculatively moved to the head
// block and executed in vector mode. The other is vector comparison
// that reduces multiple (12 in this particular case) conditional
// branches into one. Thus, performance is expected to improve if
// control usually goes through the entire chain.
//
// 'build_chains()' identifies all such chains in a given function, 
// and 'chain::transform()' transforms code for the identified
// chains. Transformed code include either Switch Return or Switch 
// Branch intrinsic, which is newly defined in this implementation. 
// These intrinsics and their vectorized versions are translated to
// plain code for CG by the functions in early_exits_lower.cxx.
// 
// ====================================================================

#include "early_exits.h"
#include "wssa_update.h"

// This routine checks if any subtree of wn has a call.

static bool
has_calls(WN *wn) {
  OPERATOR opr = WN_operator(wn);
  Is_True(opr != OPR_BLOCK, ("unexpected BLOCK"));

  if (opr == OPR_ASM_STMT)
    return true;

  if (opr == OPR_CALL ||
      opr == OPR_ICALL ||
      opr == OPR_INTRINSIC_CALL)
    return true;
  for (int i = 0; i < WN_kid_count(wn); i++) {
    if (has_calls(WN_kid(wn, i))) 
      return true;
  } 
  return false;
}

// complement operator for comparison
// NE => EQ
// EQ => NE
// GT => LEQ
// LT => GEQ
// LE => GT
// GE => LT

static OPERATOR
complement_operator(OPERATOR opr) {
  switch (opr) {
  case OPR_EQ:
    return OPR_NE;
  case OPR_NE:
    return OPR_EQ;
  case OPR_GT:
    return OPR_LE;
  case OPR_GE:
    return OPR_LT;
  case OPR_LT:
    return OPR_GE;
  case OPR_LE:
    return OPR_GT;
  case OPR_LDID:
  case OPR_ILOAD:
    return OPR_LNOT;  // x ==> !x
  default:
    Is_True(FALSE, ("invalid opr for complement_operator"));
    return OPERATOR_UNKNOWN;
  } 
}

// change the operator to its complement operator

static WN*
complement_cond(WN *exit_cond) {
  OPERATOR opr = complement_operator(WN_operator(exit_cond));
  if (opr == OPR_LNOT) {
    WN* ret = WN_CreateExp1(OPR_LNOT, WN_rtype(exit_cond), MTYPE_V, exit_cond);
    return ret;
  }
  else if (opr != OPERATOR_UNKNOWN) {
    WN_set_operator(exit_cond, opr);
    return exit_cond;
  }
  FmtAssert(FALSE, ("unexpected complement operator"));
  return NULL;
} 

// public interface for early exits transformtion

void 
LWOPT_PerformEarlyExitTransform() {
  LWOPT_EARLYEXITS lwopt_early;
}

// Description for early exits transformation component

const O64_ComponentDescriptor LWOPT_EARLYEXITS::ComponentDescriptor = {
  O64_COMPONENT_DESC("early exit transformation for slp", "EARLYEXITS", OptionDescriptors)
};

// Option description for early exits transformation component

const O64_OptionDescriptor LWOPT_EARLYEXITS::OptionDescriptors[] = {
  O64_OPTION_DESC(LWOPT_early_exits_last, "end marker", 0, 0, OVK_INVALID, OV_INTERNAL, false, 0, 0, 0)
};

// Initializer for early exits transformation component

static O64_ComponentInitializer 
lwopt_early_exits_init(COMPONENT_lwopt_earlyexits, 
		       &LWOPT_EARLYEXITS::ComponentDescriptor);

// Constructor for LWOPT_EARLYEXITS

LWOPT_EARLYEXITS::LWOPT_EARLYEXITS()
  : O64_Component(COMPONENT_lwopt_earlyexits) {
  if (!_enable) return;
  _CurrentWN = _Driver->GetCurrentWN();
  _CurrentWCFG = _Driver->GetCurrentWCFG();
  _CurrentWSSA = _Driver->GetCurrentWSSA();

  MEM_POOL_Initialize(&_mem_pool,"EARLY_EXIT POOL",FALSE);
  Perform_();
  MEM_POOL_Delete(&_mem_pool);
}

// Destructor for LWOPT_EARLYEXITS

LWOPT_EARLYEXITS::~LWOPT_EARLYEXITS() {
}

// Perform early exit transformation

void 
LWOPT_EARLYEXITS::Perform_() {
  build_chains();
  if (_chains.size() > 0) {
    // if we have more than one chain
    // then let us apply the early-exit transformation.
    // This requires building the SSA du-chains
    _CurrentWSSA_DU = CXX_NEW(WSSA::WSSA_DU_MANAGER(_CurrentWSSA, _CurrentWN),&_mem_pool);  
    _CurrentWSSA_DU->Build();

    CHAIN_LIST::iterator i;
    for (i = _chains.begin(); i != _chains.end(); i++) {
      transform(*i);
    } 
  }
}

// Traverse the CFG in depth-first order and build the chains
// for early exits transformation

void
LWOPT_EARLYEXITS::build_chains() {
  // allocate an array of size of the cfg.
  UINT32 size = _CurrentWCFG->Get_max_id() + 1;

  // initialize the visited array.
  if (_visited.size() > 0)
      _visited.clear();
  _visited.resize(size, false);

  // go through control flow graph and build chains
  CFG_UTIL::WN_CFG::dfs_fwd_iterator fit;
  for(fit = _CurrentWCFG->Dfs_fwd_begin(); fit != _CurrentWCFG->Dfs_fwd_end(); ++fit) {
    BB_NODE* bb = &(*fit);
    UINT32 id = bb->Get_id();
    if (bb == _CurrentWCFG->Get_dummy_entry() ||
        bb == _CurrentWCFG->Get_dummy_exit())
      continue;
    if (_visited[id])
      continue;
    _visited[id] = true;
    build_single_chain(id);
  }
}

// A block is eligible for early exit transformation if it doesn't 
// contain call or istore. 

bool
LWOPT_EARLYEXITS::eligible_for_early_exits(BB_NODE *bb) {
  BB_NODE::stmt_iterator sit;
  for (sit = bb->Stmt_begin() ; sit != bb->Stmt_end(); ++sit) {
    WN* stmt = &(*sit);
    if (OPERATOR_is_scalar_istore(WN_operator(stmt))) return false;
    if (WN_operator(stmt) == OPR_COMPGOTO) return false;
    if (has_calls(stmt)) return false;
  } 
  return true;
} 

// A "best" successor for given bb means:
//   has two successors
//   doesn't contain istore or call
//   not early exit block
//   all iloads in the block is safe to speculate the loads

CFG_UTIL::WN_CFG::BB_NODE *
LWOPT_EARLYEXITS::find_best_successor(EARLY_EXITS_CHAIN* c, BB_NODE* bb) {
  FmtAssert(bb->Get_succs_count() == 2, ("bb on chain must have 2 successors."));
  BB_NODE::const_bb_iterator it; 
  int best_speculative_load_count = 0;
  BB_NODE* candidate = NULL;
  INT32 count = 0; 
  for (it = bb->Succ_begin(); it != bb->Succ_end(); ++it) {
    BB_NODE* succ1 = *(it);
    count ++;
    if (_visited[succ1->Get_id()]) continue;
    if (succ1->Get_preds_count() != 1) return NULL;
    if (!eligible_for_early_exits(succ1)) {
      _visited[succ1->Get_id()]=true;
      continue;
    }
    if (c->is_return_block(succ1)) {
      continue; 
    }
    int load_count =0;
    if (!c->safe_to_speculate_loads(_CurrentWSSA, succ1, &load_count))
      continue;
    if (load_count > best_speculative_load_count || candidate == NULL) {
      candidate = succ1;
      best_speculative_load_count = load_count;
    } 
  } 
  if (best_speculative_load_count > 0)
    c->incr_spec_loads(best_speculative_load_count);
  return candidate;
} 

// Given a block, get its unique successor not on the chain. 
// This function is never called with the tail block. So, the 
// implementation is to find a successor which is not on_chain().

UINT32 
EARLY_EXITS_CHAIN::off_chain_succ(BB_NODE *bb) {
  FmtAssert((bb->Get_succs_count() == 2), ("bb on chain must have 2 successors."));

  BB_NODE::const_bb_iterator it = bb->Succ_begin();
  BB_NODE* succ1 = *it;
  UINT32 id = succ1->Get_id();
  if (!on_chain(bb->Get_id(), id)) return id;
  it ++;
  BB_NODE* succ2 = *it;
  return succ2->Get_id();
} 

// Basic algorithm to build a single chain that becomes a region
// for speculation. 
// Notes: later we can extend it to more general regions than 
// chains.

void
LWOPT_EARLYEXITS::build_single_chain(INT32 id)
{ 
  // A basic block starting a chain must meet the 
  // following conditions.

  // 1. Must have exactly 2 successors terminated
  //    by a true or false branch.
  // 2. There should not be any operations such as
  //    calls and istores.
  // 3. safe speculation condition must be satisfied
  //    for all the iloads in the block. 

  BB_NODE *bb = _CurrentWCFG->Get_node(id);
  if ((bb->Get_succs_count() != 2) ||
      (!eligible_for_early_exits(bb))) return; 

  EARLY_EXITS_CHAIN* c = CXX_NEW(EARLY_EXITS_CHAIN(_CurrentWCFG,
                                                   &_mem_pool,
                                                   _TraceKind),
                                 &_mem_pool);

  // if there are no iloads in the head block, we can 
  // ignore the chain. 
  if (c->collect_iloads(bb) == 0) return;

  // let us extend the chain as much as we can.
  while (true) {
    _visited[bb->Get_id()]=true;
    WN *br = _CurrentWCFG->Get_branch_stmt(bb);
    OPERATOR opr = WN_operator(br);
    if (opr != OPR_TRUEBR && opr != OPR_FALSEBR)
      break;

    c->add_to_chain(bb->Get_id());

    BB_NODE *best = find_best_successor(c,bb);
    if (best == NULL ||
        best->Get_succs_count() != 2 ||
        best->Get_preds_count() != 1)
      break;

    bb = best;
  }

  if (c->trivial()) 
    return;

  if (!c->beneficial_to_slp())
    return;

  // add to chain for later transformation
  _chains.push_back(c);
}

// Do real transformation on single chain in the list
// The transformation is done by two steps:
//  normalization: normalize the comparison, branch
//  transformation: move loads to head bb and generate the intrinsic

void
LWOPT_EARLYEXITS::transform(EARLY_EXITS_CHAIN *c) {
  if (c->has_live_uses(_CurrentWSSA, _CurrentWSSA_DU)) {
    if (_TraceKind >= TRACE_maximal)
      fprintf(TFile, "Chain has live outs, so early exit transformation can't be applied\n");
    return;
  }

  if (c->need_variable_renaming()) {
    if (_TraceKind >= TRACE_maximal)
      fprintf(TFile, "More than one definition for the same variable in chain\n");
    return;
  }

  if (_TraceKind >= TRACE_maximal) {
    fprintf(TFile, "Chain is eligibile for early exit transformation\n");
    fprintf(TFile, "Chain before transformation ***\n");
    c->dump();
  }

  c->normalize_chain();
  c->transform(_CurrentWSSA, _CurrentWSSA_DU, _CurrentWN);

  if (_TraceKind >= TRACE_maximal) {
    fprintf(TFile, "Chain After transformation\n");
    c->dump();
  }
} 

// Check if the version is used in any PHI node
// The uses in PHI node means the def will live out of its
// dominated BBs

static bool 
WN_has_phi_uses(WN *stmt,
                WSSA::WHIRL_SSA_MANAGER* ssa_mgr,
                WSSA::WSSA_DU_MANAGER* du_mgr) {
  WSSA::VER_IDX  ssa_ver = ssa_mgr->Get_wn_ver(stmt);

  if (!du_mgr->Ver_has_use(ssa_ver))
    return false;

  /* get direct def node/use list of given symbol/version */
  WSSA::WSSA_DU_MANAGER::const_iterator uses = du_mgr->begin(ssa_ver);
  for (; uses != du_mgr->end(ssa_ver); ++uses) {
    if (uses->Get_use_type() == WSSA::WSSA_PHI)
      return true;
  }
  return false; 
} 

// Walk through all statements in the bb and check if there are
// versions defined in the bb is used by any PHI node

static bool
BB_has_live_uses(CFG_UTIL::WN_CFG::BB_NODE *bb,     
                 WSSA::WHIRL_SSA_MANAGER* ssa_mgr, 
                 WSSA::WSSA_DU_MANAGER* du_mgr) {
  CFG_UTIL::WN_CFG::BB_NODE::stmt_iterator sit;
  for (sit = bb->Stmt_begin() ; sit != bb->Stmt_end(); ++sit) {
    WN* stmt = &(*sit);
    if (OPCODE_operator(WN_opcode(stmt)) != OPR_STID) continue;
    if (WN_has_phi_uses(stmt, ssa_mgr, du_mgr)) {
      return true;
    } 
  } 
  return false;
}

// Code in the 'source' block is hoisted to the 'dest' block, which is
// the 'head' block of the chain. Since this function is called for
// Switch Return cases where all exit blocks have a 'return' at the 
// end, liveness of variables is not checked.

void
EARLY_EXITS_CHAIN::move_code(UINT32 source, UINT32 dest) {
  BB_NODE *srcbb = _cfg->Get_node(source);
  BB_NODE *dstbb = _cfg->Get_node(dest);
  WN *srcbr  = _cfg->Get_branch_stmt(srcbb);
  WN *dstbr  = _cfg->Get_branch_stmt(dstbb);
  WN *parent = _cfg->Get_parent_block(dstbr);
  WN *curblk = _cfg->Get_parent_block(srcbr);
  BB_NODE::stmt_iterator sit;
  sit = srcbb->Stmt_begin();
  while (sit != srcbb->Stmt_end()) {
    WN* stmt = &(*sit);
    ++sit;   
    if (WN_operator(stmt) == OPR_LABEL) continue;
    if (stmt == srcbr) break;
    _cfg->Remove_stmt(stmt);
    WN_EXTRACT_FromBlock(curblk,stmt);
    WN_INSERT_BlockBefore(parent,dstbr,stmt);
    _cfg->Insert_before(dstbr, stmt);
  } 
} 

// Check if there is another definition in bb to the same variable
// defined by new_def

bool
EARLY_EXITS_CHAIN::defined_in_bb(BB_NODE *bb, WN *new_def) {
  BB_NODE::stmt_iterator sit;
  for (sit = bb->Stmt_begin(); sit != bb->Stmt_end(); ++sit) {
    WN* stmt = &(*sit);
    if (WN_operator(stmt) != OPR_STID) continue;
    if (WN_offset(stmt) == WN_offset(new_def) &&
        WN_st(stmt) == WN_st(new_def))
      return true;
  } 
  return false;
} 

// Code in the 'source' block is hoisted to the 'dest' block, which is
// the 'head' block of the chain. Since this function is called for
// Switch Branch cases where all exit blocks have a branch at the 
// end, liveness of variables should be checked.

void
EARLY_EXITS_CHAIN::move_code_if_not_live(WSSA::WHIRL_SSA_MANAGER* ssa_mgr,
                                         WSSA::WSSA_DU_MANAGER* du_mgr,
                                         UINT32 source,
                                         UINT32 dest) {
  BB_NODE *srcbb = _cfg->Get_node(source);
  BB_NODE *dstbb = _cfg->Get_node(dest);
  BB_NODE::stmt_iterator sit;
  WN *srcbr  = _cfg->Get_branch_stmt(srcbb);
  WN *dstbr  = _cfg->Get_branch_stmt(dstbb);
  WN *parent = _cfg->Get_parent_block(dstbb->Last_stmt());
  WN *curblk = _cfg->Get_parent_block(srcbb->Last_stmt());
  sit = srcbb->Stmt_begin();
  while (sit != srcbb->Stmt_end()) {
    WN* stmt = &(*sit);
    ++ sit;   
    if (WN_operator(stmt) != OPR_STID) continue;
    if (stmt == srcbr) break;
    if (!WN_has_phi_uses(stmt, ssa_mgr, du_mgr)) {
      if (defined_in_bb(_cfg->Get_node(head()), stmt)) {
        // we have to rename before we can move the code.
        FmtAssert(false, ("must rename stid target before hoisting"));
      }
      _cfg->Remove_stmt(stmt);
      WN_EXTRACT_FromBlock(curblk,stmt);
      if (dstbr != NULL) {
        WN_INSERT_BlockBefore(parent,dstbr,stmt);
        _cfg->Insert_before(dstbr, stmt);
      }
      else {
        WN* insert_point = dstbb->Last_stmt();
        WN_INSERT_BlockAfter(parent,insert_point,stmt);
        _cfg->Insert_after(insert_point, stmt);
      }
    }
  }   
} 

// Check if there is live uses of variables defined in the BBs 
// on chain other than the head by walking through all statements
// in the BB

bool
EARLY_EXITS_CHAIN::has_live_uses(WSSA::WHIRL_SSA_MANAGER* ssa_mgr, 
                                 WSSA::WSSA_DU_MANAGER* du_mgr) {
  list<UINT32>::iterator i;
  for (i = _nodes.begin(); i != _nodes.end(); i++) {
    if (*i == head()) continue;
    BB_NODE *bb = _cfg->Get_node(*i);
    if (BB_has_live_uses(bb, ssa_mgr, du_mgr)) return true;
  } 
  return false; 
} 

// Collects into 'var_set' the variables defined in 'bb'.
// Returns true if there is a variable defined more than once
// in the BB. 

bool
EARLY_EXITS_CHAIN::collect_defined_vars(set<pair<ST*, WN_OFFSET> >& var_set,
					BB_NODE* bb) {
  bool duplicate = false;
  BB_NODE::stmt_iterator sit;
  for (sit = bb->Stmt_begin() ; sit != bb->Stmt_end(); ++sit) {
    WN* stmt = &(*sit);
    if (WN_operator(stmt) != OPR_STID) continue;
    pair<ST*, WN_OFFSET> var(WN_st(stmt), WN_offset(stmt));
    if (var_set.find(var) != var_set.end())
      duplicate = true;
    else
      var_set.insert(var);
  } 
  return duplicate;
} 

// Returns true if there is a variable defined more than once
// in the BBs on chain. This is used to prevent the Early Exits
// transformation for such chains. Later, if desired, we can rename
// such variables to apply the transformation.

bool
EARLY_EXITS_CHAIN::need_variable_renaming() {
  set<pair<ST*, WN_OFFSET> > var_set;
  list<UINT32>::iterator i;
  for (i = _nodes.begin(); i != _nodes.end(); i++) {
    BB_NODE *bb = _cfg->Get_node(*i);
    bool duplicate = collect_defined_vars(var_set, bb);
    if (*i == head()) continue;
    if (duplicate) return true;
  } 
  return false; 
} 

// Check the chain to see if it's beneficial to SLP
// the nodes on chain must have the same comparison and jump operator

bool
EARLY_EXITS_CHAIN::beneficial_to_slp() {
  list<UINT32>::iterator i;
  OPCODE br_opc = OPCODE_UNKNOWN;
  OPCODE cmp_opc = OPCODE_UNKNOWN;
  BOOL br_to_chain = FALSE;
  for (i = _nodes.begin(); i != _nodes.end(); ++i) {
    BB_NODE *bb = _cfg->Get_node(*i);
    WN *br = _cfg->Get_branch_stmt(bb);
    if (*i == head()) {
      br_opc = WN_opcode(br);
      cmp_opc = WN_opcode(WN_kid0(br));
      INT32 label_number = WN_label_number(br);
      BB_NODE *exit_bb = _cfg->Get_label_node(label_number);
      if (on_chain(bb->Get_id(), exit_bb->Get_id()))
        br_to_chain = TRUE;
    }
    else if (*i == tail()) {
      OPCODE br_cmp_opc = WN_opcode(WN_kid0(br));
      if (br_cmp_opc != cmp_opc) {
        OPERATOR alt_cmp_opr = complement_operator(WN_operator(WN_kid0(br)));
        if (alt_cmp_opr != OPCODE_operator(cmp_opc) ||
            OPCODE_rtype(br_cmp_opc) != OPCODE_rtype(cmp_opc) ||
            OPCODE_desc(br_cmp_opc) != OPCODE_desc(cmp_opc)) {
          return false;
        }
      }
    }
    else {
      INT32 label_number = WN_label_number(br);
      BB_NODE *exit_bb = _cfg->Get_label_node(label_number);
      if (on_chain(bb->Get_id(), exit_bb->Get_id()) != br_to_chain ||
          WN_opcode(br) != br_opc ||
          WN_opcode(WN_kid0(br)) != cmp_opc) {
        return false;
      }
    }
  }
  return true;
}

// Normalize the chain
// make sure the target of internal branch is not on the chain:
//    CMP
//  FALSEBR L1
//  L2:
//    code off the chain
//  L1:
//    CMP
//  FALSEBR L3
// into:
//    CMP
//  TRUEBR L2
//    CMP
//  TRUEBR L4
//  L2:
//    code off the chain
//
// change the false br to true br:
//    EQ
//  FALSEBR L1
// into:
//    NE
//  TRUEBR L1
// determine the default target for the last node

void
EARLY_EXITS_CHAIN::normalize_chain() {
  list<UINT32>::iterator i;
  OPERATOR cmp_opr = OPERATOR_UNKNOWN;
  for (i = _nodes.begin(); i != _nodes.end(); ++i) {
    BB_NODE *bb = _cfg->Get_node(*i);
    WN *br = _cfg->Get_branch_stmt(bb);
    if (*i == head())
      cmp_opr = WN_operator(WN_kid0(br));
    INT32 label_number = WN_label_number(br);
    BB_NODE *exit_bb = _cfg->Get_label_node(label_number);
    const BB_NODE *fallthr_bb = bb->Get_succ(0);
    if (exit_bb == fallthr_bb) {
      fallthr_bb = bb->Get_succ(1);
    }
    bool switch_target = false;
    if (*i != tail()) {
      if (on_chain(bb->Get_id(), exit_bb->Get_id())) {
        switch_target = true;
        _exit_nodes.push_back(fallthr_bb->Get_id());
      }
      else {
        _exit_nodes.push_back(exit_bb->Get_id());
      }
    }
    else {
      OPERATOR br_opr = WN_operator(br);
      if (WN_operator(WN_kid0(br)) != cmp_opr) {
        WN_kid0(br) = complement_cond(WN_kid0(br));
        if (br_opr == OPR_FALSEBR) {
          WN_set_operator(br, OPR_TRUEBR);
        }
        else {
          WN_set_operator(br, OPR_FALSEBR);
          switch_target = true;
        }
      }
      else {
        if (br_opr == OPR_FALSEBR) {
          switch_target = true;
        }
      }
      if (switch_target) {
        _default_target_id = exit_bb->Get_id();
        _exit_nodes.push_back(fallthr_bb->Get_id());
      }
      else {
        _default_target_id = fallthr_bb->Get_id();
        _exit_nodes.push_back(exit_bb->Get_id());
      }
    }

    if (switch_target) {
      WN* first_stmt = fallthr_bb->First_stmt();
      Is_True(first_stmt != NULL, ("first stmt is NULL"));
      if (WN_operator(first_stmt) != OPR_LABEL) {
        LABEL_IDX lbl;
        New_LABEL(CURRENT_SYMTAB, lbl);
        WN* label_wn = WN_CreateLabel(lbl, 0, NULL);
        WN* label_parent = _cfg->Get_parent_block(first_stmt);
        Is_True(label_parent != NULL, ("label_parent is NULL"));
        WN_INSERT_BlockBefore(label_parent, first_stmt, label_wn);
        _cfg->Insert_before(first_stmt,label_wn);
        first_stmt = label_wn;
      }
      WN_label_number(br) = WN_label_number(first_stmt);
      if (WN_operator(br) == OPR_FALSEBR)
        WN_set_operator(br, OPR_TRUEBR);
      else
        WN_set_operator(br, OPR_FALSEBR);
    }

    if (WN_operator(br) != OPR_TRUEBR) {
      WN_kid0(br) = complement_cond(WN_kid0(br));
      WN_set_operator(br, OPR_TRUEBR);
    }
    Is_True(WN_operator(br) == OPR_TRUEBR,
            ("inconsistent branch operator"));
    if ((*i) == head())
      cmp_opr =  WN_operator(WN_kid0(br));
    else
      Is_True(cmp_opr == WN_operator(WN_kid0(br)),
              ("inconsistent comparison operator"));
  }
}

// This is the top function for the Early Exits transformation of
// the given 'chain'. If the 'exit blocks' have return statements, 
// it generates a SWITCH_RETURN intrinsic. Otherwise, a SwitchBranch
// is generated as follows, for example.
//
//  COMPGOTO
//    kid0 FIRST_TRUE_INDEX(t1, t2, t3)
//    Kid1
//      GOTO L1;
//      GOTO L2;
//      GOTO L3;
//    kid2  GOTO L4;
//  END COMPGOTO

void
EARLY_EXITS_CHAIN::transform(WSSA::WHIRL_SSA_MANAGER* ssa, 
                             WSSA::WSSA_DU_MANAGER* du_mgr,
                             WN* root) {
  if (exits_are_returns()) {
    list<UINT32>::iterator i;
    for (i = _nodes.begin(); i != _nodes.end(); i++) {
      UINT32 bb_id = *i;
      if (bb_id == _head_id) continue;
      BB_NODE *bb = _cfg->Get_node(bb_id);
      move_code(bb_id, _head_id);
    } 
    gen_switch_intrinsic(ssa, root); 
  }
  else {
    // we can speculate instructions from the chain
    // into the head block, provided these are not 
    // live outside the chain. If these are live
    // on exits, we can speculate by inserting 
    // copies. 

    list<UINT32>::iterator i;
    for (i = _nodes.begin(); i != _nodes.end(); i++) {
      UINT32 bb_id = *i;
      if (bb_id == _head_id) continue;
      BB_NODE *bb = _cfg->Get_node(bb_id);
      move_code_if_not_live(ssa, du_mgr, bb_id, _head_id);
    } 
    gen_switch_branch_intrinsic(ssa, root); 
  } 
} 

// This method checks if each exit out of the chain is into
// a block that returns.
// The initial early exit transformation will be done only 
// for such chains.

bool 
EARLY_EXITS_CHAIN::exits_are_returns() {
  list<UINT32>::iterator i;
  if (_TraceKind >= TRACE_maximal) 
    fprintf(TFile, "Determine if chain exits are returns\n");
  for (i = _nodes.begin(); i != _nodes.end(); i++) {
    UINT32 bb_id = *i;
    BB_NODE *bb= _cfg->Get_node(bb_id);
    BB_NODE *exit_bb = _cfg->Get_node(off_chain_succ(bb)); 
    if (!is_return_block(exit_bb)) return false;
  }
  return true;
}

// Check the condition to exit the chain
// If needed, change the condition to make conditions and branch
// on the chain to be consistent

WN*
EARLY_EXITS_CHAIN::determine_chain_exit_cond(BB_NODE* bb) {
  FmtAssert((bb->Get_succs_count() == 2), ("bb on chain must have 2 successors."));
  WN* br = _cfg->Get_branch_stmt(bb);
  if (br == NULL) return NULL;
  WN* exit_cond = WN_kid0(br);
  INT32 target_label = WN_label_number(br);
  BB_NODE *target_bb = _cfg->Get_label_node(target_label);
  if (WN_operator(br) == OPR_FALSEBR &&
      !on_chain(bb->Get_id(), target_bb->Get_id())) {
    exit_cond = complement_cond(exit_cond);
    return exit_cond;
  }
  if (WN_operator(br) == OPR_TRUEBR &&
      on_chain(bb->Get_id(), target_bb->Get_id())) {
    exit_cond = complement_cond(exit_cond);
    return exit_cond;
  }
  return exit_cond;
} 

// This method converts a chain whose exits are return blocks and 
// introduces a switchreturn intrinsic.
// The form is
//              SwitchReturnOp < c1,e1,c2,e2,..cn,en>
//
// The semantics are 
// if c1 == true return e1
// if c2 == true return e2
// if cn == true return e2
// goto next statement. 
// There is a implied ordering on the conditions. 
// 
// In the first loop, after the intrinsic is created, the exit condition
// results and 'return' values are stored into pseudo registers. At the
// same time, the pseudo registers are set as the arguments of the 
// intrinsic just created. In the second loop, these STID's are inserted
// right before the branch instruction of the 'head' block.
//
// Then, a GOTO statement is inserted at the end of the 'head' block
// that jumps to the first statement of the successor block of the 
// 'tail' block, which is not the exit block. This is necessary because
// the SWITCH_RETURN intrinsic is not recognized as a branch statement
// by the current CFG implementation.
// 
// Next, the branches are deleted from each 'chain block' in the 
// subsequent 'while' loop and the basic blocks, now empty, are 
// deleted. In the following loop nest, all 'exit block' are removed.

WN*
EARLY_EXITS_CHAIN::gen_switch_intrinsic(WSSA::WHIRL_SSA_MANAGER* ssa, WN* root) {
  WSSA::WSSA_UPDATER updater(root, _cfg, ssa);
  updater.Enable_update_cfg();
 
  list<WN *> intrisic_args; 
  if (_TraceKind >= TRACE_maximal) 
    fprintf(TFile, "Building the switch intrinsic operation...\n");

  INT32 count = 2 * size();
  WN *wn_intrinsic = WN_Create(OPR_INTRINSIC_CALL, MTYPE_V, MTYPE_V, count);
  WN_intrinsic(wn_intrinsic) = INTRN_SWITCH_RETURN;
  WN_MAP_Set_ID(Current_Map_Tab,wn_intrinsic);
  UINT32 parm_pos = 0;
  WN* insert_point = NULL;
  list<WN*> stid_block;
  for (list<UINT32>::iterator i = _nodes.begin(); i != _nodes.end(); i++) {
    UINT32 bb_id = *i;
    BB_NODE *bb= _cfg->Get_node(bb_id);
    WN *br = _cfg->Get_branch_stmt(bb);
    BB_NODE *exit_bb = _cfg->Get_node(off_chain_succ(bb)); 
    WN *return_stmt = get_return_stmt(exit_bb);
    WN *return_val  = WN_kid0(return_stmt);
    updater.Extract_stmt(_cfg->Get_parent_block(return_stmt), return_stmt); 
    WN_Delete(return_stmt);
    WN *exit_cond = determine_chain_exit_cond(bb);
    if (bb_id == head()) {
       insert_point = br;
    } 
    // store both cond_wn and retval to PREG and reload them 
    // in order to vectorize them
    TYPE_ID cond_type = WN_rtype(exit_cond);
    PREG_NUM cond_preg = Create_Preg(cond_type, "_exit_cond_");
    ST* cond_st = MTYPE_To_PREG(cond_type);
    WN* cond_stid = WN_CreateStid(OPR_STID, MTYPE_V, cond_type, cond_preg,
                                  cond_st, ST_type(cond_st), exit_cond);
    WN_linenum(cond_stid) = WN_linenum(br);
    stid_block.push_back(cond_stid);
    WN *cond_ldid = WN_CreateLdid(OPR_LDID, cond_type, cond_type, cond_preg, 
                                  cond_st, Be_Type_Tbl(cond_type));

    TYPE_ID retval_type = WN_rtype(return_val);
    PREG_NUM retval_preg = Create_Preg(retval_type, "_return_value_");
    ST* retval_st = MTYPE_To_PREG(retval_type);
    WN* retval_stid = WN_CreateStid(OPR_STID, MTYPE_V, retval_type, retval_preg, 
                                    retval_st, ST_type(retval_st), return_val);
    WN_linenum(retval_stid) = WN_linenum(return_stmt);
    stid_block.push_back(retval_stid);
    WN *retval_ldid = WN_CreateLdid(OPR_LDID, retval_type, retval_type, retval_preg, 
                                    retval_st, Be_Type_Tbl(retval_type));

    WN *cond_wn = WN_CreateParm(cond_type, cond_ldid, cond_type, WN_PARM_BY_VALUE);
    WN *retval_wn = WN_CreateParm(retval_type, retval_ldid, retval_type, WN_PARM_BY_VALUE);
    WN_kid(wn_intrinsic,parm_pos) = cond_wn;
    WN_kid(wn_intrinsic,parm_pos+1) = retval_wn;
    WN_MAP_Set_ID(Current_Map_Tab,cond_wn);
    WN_MAP_Set_ID(Current_Map_Tab,retval_wn);
    parm_pos +=2;
  }

  // insert the intrinsic
  Is_True(insert_point != NULL, ("chain::gen_switch_intrinsic: can not find insert point"));
  WN *parent = _cfg->Get_parent_block(insert_point);
  list<WN*>::iterator it;
  for (it = stid_block.begin(); it != stid_block.end(); ++it) {
    WN_INSERT_BlockBefore(parent, insert_point, *it);
    _cfg->Insert_before(insert_point, *it);
  }
  stid_block.clear();
  WN_INSERT_BlockBefore(parent, insert_point, wn_intrinsic);
  _cfg->Insert_before(insert_point, wn_intrinsic);
  updater.Rename_BB_new_preg(_cfg->Get_stmt_node(insert_point));

  BB_NODE *dt = _cfg->Get_node(default_target());
  BB_NODE *hd = _cfg->Get_node(head());
  BB_NODE::stmt_iterator dt_sit = dt->Stmt_begin();
  WN *first = &(*dt_sit);
  if (WN_operator(first) != OPR_LABEL) {
    // create a new label and attach it at the end of block
    LABEL_IDX dt_label;
    New_LABEL(CURRENT_SYMTAB, dt_label);
    WN *dt_label_wn = WN_CreateLabel(dt_label, 0, NULL);
    WN_MAP_Set_ID(Current_Map_Tab, dt_label_wn);
    WN *parent = _cfg->Get_parent_block(first);
    WN_INSERT_BlockBefore(parent, first, dt_label_wn);
    _cfg->Insert_before(first, dt_label_wn);
    first = dt_label_wn;
  } 
  WN *goto_wn  = WN_CreateGoto(WN_label_number(first));
  WN_MAP_Set_ID(Current_Map_Tab, goto_wn);
  WN_INSERT_BlockBefore(parent, insert_point, goto_wn);
  _cfg->Insert_before(insert_point, goto_wn);

  for (list<UINT32>::iterator i = _nodes.begin(); i != _nodes.end(); ) {
    UINT32 bb_id = *i;
    i++; // i++ here to avoid invalid iterator
    BB_NODE *bb = _cfg->Get_node(bb_id);
    // delete the original branch. 
    WN *br = _cfg->Get_branch_stmt(bb);
    WN *parent = _cfg->Get_parent_block(br);
    updater.Extract_stmt(parent, br); 
    WN_Delete(br);
    if  (bb_id != head()) {
      updater.Delete_BB(bb);
    }
  }

  // delete all the statements in the exit blocks.
  for (list<UINT32>::iterator i = _exit_nodes.begin(); i!= _exit_nodes.end(); i++) {
    UINT32 bb_id = *i;
    BB_NODE *exit_bb = _cfg->Get_node(bb_id);
    // delete all the statements from the exit_bb;
    BB_NODE::stmt_iterator sit =  exit_bb->Stmt_begin() ; 
    for (sit = exit_bb->Stmt_begin(); sit != exit_bb->Stmt_end(); ++sit) {
      WN* stmt = &(*sit);
      if (WN_operator(stmt) == OPR_LABEL) continue;
      WN *parent_wn = _cfg->Get_parent_block(stmt);
      updater.Extract_stmt(parent_wn, stmt); 
      WN_Delete(stmt);
    } 
    updater.Delete_BB(exit_bb);
  }
  _cfg->Connect_predsucc(hd, dt);
  return wn_intrinsic;
}


#define MAX_VECTOR_LEN 16

// We say a load is safe to speculate if there is a load 
// in the head basic block and the current load address 
// differs by max vector length.

static bool
wn_equal(WSSA::WHIRL_SSA_MANAGER* ssa, WN* wn1, WN* wn2)
{ 
  // o constant nodes are equal if their constant values are
  //   equal
  // o two ldid's are equal if their variables are the same
  //   and the ssa-versions are the same
  // o two lda are equal if the base addresses are the same. 
  //
  // for all others, opcodes must be equal and the kids must be
  // equal. 
  OPERATOR opr1 = WN_operator(wn1);
  OPERATOR opr2 = WN_operator(wn2);

  if (opr1 != opr2) return false;

  switch (opr1) {
  case OPR_INTCONST:
    return (WN_const_val(wn1) == WN_const_val(wn2));
  case OPR_LDID:
    return (WN_offset(wn1) == WN_offset(wn2) &&
            WN_st(wn1)  == WN_st(wn2) &&
            ssa->Get_wn_ver(wn1) == ssa->Get_wn_ver(wn2));
  case OPR_LDA:
    return (WN_offset(wn1) == WN_offset(wn2) &&
            WN_st(wn1)  == WN_st(wn2));
  default:
    for (UINT32 i = 0; i < WN_kid_count(wn1); i++) {
      if (!wn_equal(ssa, WN_kid(wn1,i), WN_kid(wn2,i)))
        return false; 
    } 
    return true;
  }
  return false;
} 

static void
flatten(WN* node1, list<WN*>* sum_terms) {
  OPERATOR opr1 = WN_operator(node1);
  if (opr1 == OPR_CVT) {
    flatten(WN_kid0(node1),sum_terms);
    return;
  }
  if (opr1 != OPR_ADD) {
    sum_terms->push_back(node1);
    return;
  } 
  flatten(WN_kid0(node1),sum_terms);
  flatten(WN_kid1(node1),sum_terms);
} 

static bool
remove_equal_from(WSSA::WHIRL_SSA_MANAGER* ssa, WN* wn, list<WN*>& term_list) {
  list<WN*>::iterator i1;
  i1 = term_list.begin();
  while ( i1 != term_list.end()) {
    WN* term = *i1;
    i1 ++;
    if (wn_equal(ssa, term, wn)) {
      term_list.remove(term);
      return true;
    }
  } 
} 

static bool
compare_wn(WSSA::WHIRL_SSA_MANAGER* ssa,
           WN *node1,
           WN *node2,
           UINT32 length);

static bool
compare_terms(WSSA::WHIRL_SSA_MANAGER* ssa, 
              list<WN*>& add_terms_wn1, 
              list<WN*>& add_terms_wn2, 
              UINT32 length) {
  list<WN*>::iterator i1;
  i1 = add_terms_wn1.begin();

  // first remove terms that are equal. 
  while ( i1 != add_terms_wn1.end()) {
    WN *term = *i1;
    i1++;
    if (remove_equal_from(ssa, term, add_terms_wn2)) {
      add_terms_wn1.remove(term);
    }
  } 

  if (add_terms_wn1.size() == 0 &&
      add_terms_wn2.size() == 0)
    return true;

  // case1
  if (add_terms_wn1.size() == 0) {
    // we only expect to see a constant in add_terms_wn2.
    if (add_terms_wn2.size() > 1)
      return false;
    if (add_terms_wn2.size() ==1 ) {
      WN *wn = add_terms_wn2.front();
      OPERATOR opr1 = WN_operator(wn);
      if (opr1 != OPR_INTCONST) return false;
      return WN_const_val(wn) <= length;
    } 
  } 

  // case2
  if (add_terms_wn2.size() == 0) {
    // we only expect to see a constant in add_terms_wn2.
    if (add_terms_wn1.size() > 1)
      return false;
    if (add_terms_wn1.size() == 1) {
      WN *wn = add_terms_wn1.front();
      OPERATOR opr1 = WN_operator(wn);
      if (opr1 != OPR_INTCONST) return false;
      return (WN_const_val(wn) <= length);
    } 
  } 

  // case3
  if (add_terms_wn2.size() > 1 &&
      add_terms_wn1.size() > 1)
    return false;

  // case4: only allow multiplicative terms here. 
  WN *term1 = add_terms_wn1.front();
  WN *term2 = add_terms_wn2.front();

  if (!WN_operator_is(term1, OPR_MPY) ||
      !WN_operator_is(term2, OPR_MPY)) 
    return false;

  WN *kid0_wn1 = WN_kid0(term1);
  WN *kid1_wn1 = WN_kid1(term2);
  WN *kid0_wn2 = WN_kid0(term1);
  WN *kid1_wn2 = WN_kid1(term2);
  WN *const_wn1 = NULL;
  WN *other_wn1 = NULL;
  WN *const_wn2 = NULL;
  WN *other_wn2 = NULL;

  // allowing for commutativity
  if (WN_operator_is(kid0_wn1, OPR_INTCONST)) {
    const_wn1 = kid0_wn1;
    other_wn1 = kid1_wn1;
  }
  if (WN_operator_is(kid1_wn1, OPR_INTCONST)) {
    const_wn1 = kid1_wn1;
    other_wn1 = kid0_wn1;
  }
  if (WN_operator_is(kid0_wn2, OPR_INTCONST)) {
     const_wn2 = kid0_wn2;
     other_wn2 = kid1_wn2;
  }
  if (WN_operator_is(kid1_wn2, OPR_INTCONST)) {
    const_wn2 = kid1_wn2;
    other_wn2 = kid0_wn2;
  }

  if (!const_wn1 || !const_wn2)
    return false;
  if (WN_const_val(const_wn1) != WN_const_val(const_wn2))
    return false;

  return compare_wn(ssa, other_wn1, other_wn2,
                    length/WN_const_val(const_wn1));
}

static bool
compare_wn(WSSA::WHIRL_SSA_MANAGER* ssa, 
           WN *node1, WN *node2, UINT32 length) {
  list<WN*> add_terms_wn1;
  list<WN*> add_terms_wn2;

  flatten(node1, &add_terms_wn1);
  flatten(node2, &add_terms_wn2);
  return compare_terms(ssa, add_terms_wn1, add_terms_wn2, length);
}  

static bool
load_within_distance(WSSA::WHIRL_SSA_MANAGER* ssa, 
                     WN *root, WN *cur, UINT32 veclength) {
  return compare_wn(ssa, WN_kid0(root), WN_kid0(cur), veclength);
} 

// Check if iload is within the vecter length of existing iloads
// in the BBs on the chain

bool
EARLY_EXITS_CHAIN::has_load_within_distance(WSSA::WHIRL_SSA_MANAGER* ssa, WN *iload, UINT32 veclength) {
  list<WN *>::iterator ld_iter;
  for (ld_iter = _head_loads.begin(); ld_iter != _head_loads.end(); ++ld_iter) {
    WN *root = *ld_iter;
    if (load_within_distance(ssa, root, iload, veclength))
      return true;
  } 
  return false;
} 

// Walk through the BB and collect the iloads into the _head_loads

INT32
EARLY_EXITS_CHAIN::collect_iloads(BB_NODE *bb) {
  BB_NODE::stmt_iterator sit;
  for (sit = bb->Stmt_begin() ; sit != bb->Stmt_end(); ++sit) {
    WN* stmt = &(*sit);
    WN_collect_iloads(&_head_loads, stmt);
  } 
  return _head_loads.size();
} 

// Check if the bb only contains RETURN related statements
// "RETURN related statements" include STIDs to return locations and
// a return statement.
// We also ignore the LABEL in the bb.

bool
EARLY_EXITS_CHAIN::is_return_block (BB_NODE *exit_bb) {
  WN *br = _cfg->Get_branch_stmt(exit_bb);
  if (!br) return false;
  OPERATOR opr = WN_operator(br);
  if (opr == OPR_RETURN || opr == OPR_RETURN_VAL) {
    // make sure that the return block has only 2 statements, 
    // one is the return and the other is stdid computing 
    // the return value into return register. 
    UINT32 count = 0;
    BB_NODE::stmt_iterator sit;
    for (sit = exit_bb->Stmt_begin() ; sit != exit_bb->Stmt_end(); ++sit) {
      // ignore labels
      WN* stmt = &(*sit);
      if (WN_operator(stmt) == OPR_LABEL) continue;
      if (WN_operator(stmt) == OPR_STID) {
        if (ST_class(WN_st(stmt)) != CLASS_PREG)
          return false;
        TY_IDX ret_ty = TY_ret_type(PU_prototype(Get_Current_PU()));
        RETURN_INFO ret_info = Get_Return_Info(ret_ty,
                                               No_Simulated,
                                               PU_ff2c_abi(Get_Current_PU()));
        if (WN_offset(stmt) != RETURN_INFO_preg(ret_info, 0))
          return false;
      }
      if (WN_operator(stmt) != OPR_STID &&
          WN_operator(stmt) != OPR_RETURN)
        return false;
      if (count > 1) return false; 
      count++;
    } 
  }
  else
    return false;
  return true;
} 

// Check if the iloads in the BB is safe to speculate into the head
// bb
// For head bb, always return true

bool
EARLY_EXITS_CHAIN::safe_to_speculate_loads(WSSA::WHIRL_SSA_MANAGER *ssa,
                                           BB_NODE *bb, 
                                           int *num_loads) {
  // loads appearing in the head block are not speculative, 
  // so it is always safe.
  if (bb->Get_id() == head())
    return true;

  int count = 0;
  BB_NODE::stmt_iterator sit;
  for (sit = bb->Stmt_begin() ; sit != bb->Stmt_end(); ++sit) {
    WN* stmt = &(*sit);
    list<WN *> loads;
    WN_collect_iloads(&loads, stmt);
    list<WN *>::iterator ld_iter;
    for (ld_iter = loads.begin(); ld_iter != loads.end(); ++ld_iter) {
      WN *iload = *ld_iter;
      if (!has_load_within_distance(ssa, iload, MAX_VECTOR_LEN))
        return false;
      count++;
    } 
  } 
  *num_loads = count;
  return true;
} 

// for given par_id, determine if kid_id is on chain
// if par_id is tail, return true if kid_id is default_target_id
// otherwise, return true if kid_id is in chain list

bool 
EARLY_EXITS_CHAIN::on_chain(UINT32 par_id, INT32 kid_id) {
  if (par_id == _tail_id) {
    if (kid_id == _default_target_id)
      return true;
    else
      return false;
  }
    
  list<UINT32>::iterator i;
  for (i = _nodes.begin(); i != _nodes.end(); i++) {
    if (*i == kid_id)
      return true;
  } 
  return false;
}

// Return the statement to set the return value

WN *
EARLY_EXITS_CHAIN::get_return_stmt(BB_NODE *exit_bb) {
  WN *br = _cfg->Get_branch_stmt(exit_bb);
  OPERATOR opr = WN_operator(br);
  FmtAssert((opr == OPR_RETURN || opr == OPR_RETURN_VAL), ("bb must terminate with a return."));
  UINT32 count = 0;
  BB_NODE::stmt_iterator sit;
  for (sit = exit_bb->Stmt_begin() ; sit != exit_bb->Stmt_end(); ++sit) {
    // ignore labels
    WN* stmt = &(*sit);
    if (WN_operator(stmt) == OPR_LABEL) continue;
    FmtAssert(WN_operator(stmt) == OPR_STID, ("return value must be set using stid"));
    return stmt;
  }
  return NULL;
}

// Check the condition to jump off the chain
// If needed, change the condition to make conditions and branch
// on the chain to be consistent

WN *
EARLY_EXITS_CHAIN::determine_chain_branch_cond(BB_NODE *bb) {
  FmtAssert((bb->Get_succs_count() == 2), ("bb on chain must have 2 successors."));
  WN *br = _cfg->Get_branch_stmt(bb);
  if (br == NULL) return NULL;
  WN *exit_cond = WN_kid0(br);
  INT32 target_label = WN_label_number(br);
  const BB_NODE *target_bb = _cfg->Get_label_node(target_label);
  if (on_chain(bb->Get_id(), target_bb->Get_id())) {
    const BB_NODE *exit_bb = bb->Get_succ(0);
    if (exit_bb == target_bb)
      exit_bb = bb->Get_succ(1);
    WN* first_stmt = exit_bb->First_stmt();
    Is_True(first_stmt != NULL, ("first stmt is NULL"));
    if (WN_operator(first_stmt) != OPR_LABEL) {
      LABEL_IDX lbl;
      New_LABEL(CURRENT_SYMTAB, lbl);
      WN* label_wn = WN_CreateLabel(lbl, 0, NULL);
      WN* label_parent = _cfg->Get_parent_block(first_stmt);
      Is_True(label_parent != NULL, ("label_parent is NULL"));
      WN_INSERT_BlockBefore(label_parent, first_stmt, label_wn);
      _cfg->Insert_before(first_stmt,label_wn);
      first_stmt = label_wn;
    }
    if (WN_operator(br) == OPR_FALSEBR) {
      WN_set_operator(br, OPR_TRUEBR);
    }
    else {
      Is_True(WN_operator(br) == OPR_TRUEBR, ("invalid br operator"));
      WN_set_operator(br, OPR_FALSEBR);
    }
    WN_label_number(br) = WN_label_number(first_stmt);
    target_bb = exit_bb;
  }

  if (WN_operator(br) == OPR_FALSEBR &&
      !on_chain(bb->Get_id(), target_bb->Get_id())) {
    exit_cond = complement_cond(exit_cond);
    return exit_cond;
  }

  Is_True(WN_operator(br) == OPR_TRUEBR,
          ("branch is still falsebr"));

  return exit_cond;
} 

// This method converts a chain whose exits are jumping off the chain
// and generate COMPGOTO with a FIRST_TRUE_INDEX intrinsic
// The form is
//   COMPGOTO
//     INTRINSIC_OP FIRST_TRUE_INDEX(c1, c2, ...cn)
//     BLOCK
//       GOTO L1
//       GOTO L2
//       GOTO ...
//       GOTO Ln
//     END BLOCK
//     GOTO label_of_next_statement
//   END COMPGOTO
//
// The semantics are 
// if c1 == true goto L1
// if c2 == true goto L2
// if cn == true goto Ln
// goto next statement. 
// There is a implied ordering on the conditions. 
//
// The FIRST_TRUE_INDEX intrinsic takes n parameters and return the
// index of the first non-zero one. In general, the ISA support such
// kind of operation directly. On x86, it's bsr/bsf

WN*
EARLY_EXITS_CHAIN::gen_switch_branch_intrinsic(WSSA::WHIRL_SSA_MANAGER* ssa, WN* root) {
  WSSA::WSSA_UPDATER updater(root, _cfg, ssa);
  updater.Enable_update_cfg();
 
  list<WN*> intrisic_args; 
  if (_TraceKind >= TRACE_maximal) 
    fprintf(TFile, "Building the switch intrinsic operation...\n");

  INT32 count = size();
  WN *wn_intrinsic  = WN_Create(OPR_INTRINSIC_OP, MTYPE_I1, MTYPE_V, count);
  WN_intrinsic(wn_intrinsic) = INTRN_FIRST_TRUE_INDEX;
  WN_MAP_Set_ID(Current_Map_Tab,wn_intrinsic);
  UINT32 parm_pos = 0;
  WN* insert_point = NULL;
  list<WN*> stid_list;
  list<WN*> jump_list;
  for (list<UINT32>::iterator i = _nodes.begin(); i != _nodes.end(); i++) {
    UINT32 bb_id = *i;
    BB_NODE *bb= _cfg->Get_node(bb_id);
    WN *br = _cfg->Get_branch_stmt(bb);
    if (bb_id == head()) {
       insert_point = br;
    }
    WN *exit_cond = determine_chain_branch_cond(bb);
    INT32 exit_label = WN_label_number(br);
    WN* jump_stmt = WN_CreateGoto(exit_label);
    jump_list.push_back(jump_stmt);

    // store both cond_wn and retval to PREG and reload them 
    // in order to vectorize them
    TYPE_ID cond_type = WN_rtype(exit_cond);
    PREG_NUM cond_preg = Create_Preg(cond_type, "_exit_cond_");
    ST* cond_st = MTYPE_To_PREG(cond_type);
    WN* cond_stid = WN_CreateStid(OPR_STID, MTYPE_V, cond_type, cond_preg,
                                  cond_st, ST_type(cond_st), exit_cond);
    WN_linenum(cond_stid) = WN_linenum(br);
    stid_list.push_back(cond_stid);
    WN *cond_ldid = WN_CreateLdid(OPR_LDID, cond_type, cond_type, cond_preg, 
                                  cond_st, Be_Type_Tbl(cond_type));

    WN *cond_wn = WN_CreateParm(cond_type, cond_ldid, cond_type, WN_PARM_BY_VALUE);
    WN_kid(wn_intrinsic,parm_pos) = cond_wn;
    WN_MAP_Set_ID(Current_Map_Tab,cond_wn);
    ++parm_pos;
  }

  BB_NODE *dt = _cfg->Get_node(default_target());
  BB_NODE *hd = _cfg->Get_node(head());

  // insert the intrinsic
  Is_True(insert_point != NULL, ("can not find insert point"));
  WN *parent = _cfg->Get_parent_block(insert_point);
  for (list<WN*>::iterator it = stid_list.begin(); it != stid_list.end(); ++it) {
    WN_INSERT_BlockBefore(parent, insert_point, *it);
    _cfg->Insert_before(insert_point, *it);
  }
  stid_list.clear();

  // create COMPGOTO
  WN* jump_block = WN_CreateBlock();
  for (list<WN*>::iterator it = jump_list.begin(); it != jump_list.end(); ++it) {
    WN_INSERT_BlockLast(jump_block, *it);
  }
  jump_list.clear();
  
  WN* jump_default;
  WN* tb_first_stmt = dt->First_stmt();
  Is_True(tb_first_stmt != NULL, ("invalid tail first stmt"));
  if (WN_operator(tb_first_stmt) == OPR_LABEL) {
    INT32 default_label = WN_label_number(tb_first_stmt);
    jump_default = WN_CreateGoto(default_label);
  }
  else {
    LABEL_IDX lbl;
    New_LABEL(CURRENT_SYMTAB, lbl);
    WN* label_wn = WN_CreateLabel(lbl, 0, NULL);
    WN* label_parent = _cfg->Get_parent_block(tb_first_stmt);
    Is_True(label_parent != NULL, ("label_parent is NULL"));
    WN_INSERT_BlockBefore(label_parent, tb_first_stmt, label_wn);
    _cfg->Insert_before(tb_first_stmt, label_wn);
    INT32 default_label = WN_label_number(label_wn);
    jump_default = WN_CreateGoto(default_label);
  }
  WN* compgoto = WN_CreateCompgoto(size(), wn_intrinsic, jump_block, jump_default, 0);
  WN_INSERT_BlockBefore(parent, insert_point, compgoto);
  _cfg->Insert_before(insert_point, compgoto);
  updater.Rename_BB_new_preg(_cfg->Get_stmt_node(insert_point));

  for (list<UINT32>::iterator i = _nodes.begin(); i != _nodes.end(); ) {
    UINT32 bb_id = *i;
    i++;  // i++ here to avoid invalid iterator
    BB_NODE *bb = _cfg->Get_node(bb_id);
    // delete the original branch. 
    WN *br = _cfg->Get_branch_stmt(bb);
    WN *parent = _cfg->Get_parent_block(br);
    updater.Extract_stmt(parent, br); 
    WN_Delete(br);
    if (bb_id != head()) {
      updater.Delete_BB(bb);
    }
  }

  // connect all the exit blocks to head.
  for (list<UINT32>::iterator i = _exit_nodes.begin(); i != _exit_nodes.end(); i++) {
    UINT32 bb_id = *i;
    BB_NODE *exit_bb = _cfg->Get_node(bb_id);
    _cfg->Connect_predsucc(hd, exit_bb);
  }
  // connect detault target to head
  _cfg->Connect_predsucc(hd, dt);

  return wn_intrinsic;
}

// Helper routine to dump the chain for debug purpose

void
EARLY_EXITS_CHAIN::dump() {
  fprintf(TFile, "EARLY EXITS CHAIN DUMP BEGIN:\n");
  fprintf(TFile, "head: %d, tail %d, def target %d\n", _head_id, _tail_id, _default_target_id);

  for (list<UINT32>::iterator i = _nodes.begin(); i != _nodes.end(); ++i) {
    fprintf(TFile, "Block %d ", *i);
    BB_NODE *bb = _cfg->Get_node(*i);
    BB_NODE::stmt_iterator sit;
    for (sit = bb->Stmt_begin() ; sit != bb->Stmt_end(); ++sit) {
      WN* stmt = &(*sit);
      dump_tree(stmt);
    } 
  }
  for (list<UINT32>::iterator i = _exit_nodes.begin(); i != _exit_nodes.end(); ++i) {
    fprintf(TFile, "Exit block %d\n", *i);
  } 
  fprintf(TFile, "EARLY EXITS CHAIN DUMP END\n");
} 


