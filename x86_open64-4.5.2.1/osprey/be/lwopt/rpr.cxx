/*

  Open64 is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  Open64 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
  MA  02110-1301, USA.

*/

// ====================================================================
// Module: rpr.cxx
//
// Description:
//  The goal of this work is to implement an infrastructure to relieve 
// the register pressure by moving the definition as close as possible 
// to its uses. It models the register pressure by liveness analysis.
// If the register pressure of a block is larger than thredshold, it 
// will select legal and profitable stmts to move to their dominating
// uses. In some sense, this transformation will undo the adverse effect
// of other optimizations (e.g., PRE) on register pressure. 
//
// ====================================================================

#include "rpr.h"
#include "wn.h"
#include "wn_util.h"
#include "targ_sim.h"
#include "bitset.h"

void 
LWOPT_PerformRPR()
{
    LWOPT_RPR lwopt_rpr;
}

const O64_ComponentDescriptor LWOPT_RPR::ComponentDescriptor =
{
    O64_COMPONENT_DESC("register pressure relief optimization", "RPR", OptionDescriptors)
};

// options for RPR component 
const O64_OptionDescriptor LWOPT_RPR::OptionDescriptors[] =
{
    O64_OPTION_DESC(LWOPT_rpr_gp_limit, "limit for general purpose register",
                    "gplimit", "gplimit", OVK_UINT32, OV_INTERNAL, false, 16, 0, UINT32_MAX),
    O64_OPTION_DESC(LWOPT_rpr_fp_limit, "limit for floating point register",
                    "fplimit", "fplimit", OVK_UINT32, OV_INTERNAL, false, 16, 0, UINT32_MAX),
    O64_OPTION_DESC(LWOPT_rpr_avoid_bb, "do not perform rpr on bb",
                    "avoid_bb", "abb", OVK_UINT32, OV_INTERNAL, false, 0, 0, UINT32_MAX),  
    O64_OPTION_DESC(LWOPT_rpr_expr_limit, "limit for expressions",
                   "exprlimit", "exprlimit", OVK_UINT32, OV_INTERNAL, false, UINT32_MAX, 
                    0, UINT32_MAX),
    O64_OPTION_DESC(LWOPT_rpr_comp_cost, "computation cost heuristics", 
                    "comp_cost", "comp_cost", OVK_UINT32, OV_INTERNAL, false, 10,
                    0, UINT32_MAX),
    O64_OPTION_DESC(LWOPT_rpr_memory_limit, "out of memory limit",
                    "memory_limit", "memory", OVK_UINT32, OV_INTERNAL, false, 10000000,
                    0, UINT32_MAX),
    O64_OPTION_DESC(LWOPT_rpr_last, "end marker", 0, 0, 
                    OVK_INVALID, OV_INTERNAL, false, 0, 0, 0)
};

static O64_ComponentInitializer lwopt_rpr_init(
    COMPONENT_lwopt_rpr, &LWOPT_RPR::ComponentDescriptor);
    
LWOPT_RPR::LWOPT_RPR()
    :O64_Component(COMPONENT_lwopt_rpr),
    _NumExprMoved(0)
{
    // disable by default
    if (!_enable) return;

    _CurrentWN = _Driver->GetCurrentWN();
    _CurrentWCFG = _Driver->GetCurrentWCFG();
    _CurrentWSSA = _Driver->GetCurrentWSSA();

    _CurrentUpdate = CXX_NEW(WSSA_UPDATER(_CurrentWN, _CurrentWCFG, _CurrentWSSA,false), 
        _LocalMemPool);
    
    // build the du manger
    _CurrentDU  = CXX_NEW(WSSA_DU_MANAGER(_CurrentWSSA, _CurrentWN),_LocalMemPool);
    _CurrentDU->Build();

    // build the dominator/post-dominator
    _Driver->BuildWCFGDOM();

    _RegGPLimit = _CurrentOption->GetUIntOption(_CurrentComponent, LWOPT_rpr_gp_limit);
    _RegFPLimit = _CurrentOption->GetUIntOption(_CurrentComponent, LWOPT_rpr_fp_limit);
    _ExprLimit = _CurrentOption->GetUIntOption(_CurrentComponent, LWOPT_rpr_expr_limit);
    _AvoidBB = _CurrentOption->GetUIntOption(_CurrentComponent, LWOPT_rpr_avoid_bb);
    _CompCostLimit = _CurrentOption->GetUIntOption(_CurrentComponent, LWOPT_rpr_comp_cost);
    _OutofMemoryLimit = _CurrentOption->GetUIntOption(_CurrentComponent, LWOPT_rpr_memory_limit);

    _RegClassNum[REG_GP] = 0;
    _RegClassNum[REG_FP] = 0;

    Perform_();
}

LWOPT_RPR::~LWOPT_RPR()
{
    if (!_enable) return;

    WN_MAP_Delete(_StmtOrderMap);
    _invalidCFG = true;
    _invalidSSA = true;

}


void 
LWOPT_RPR::Perform_()
{
    // assign a regclass for each SSAname 
    InitRPR_();

    // dataflow analysis to compute the liveness analysis
    if (!ComputeRegPressure_()) return;

    // perform code motion to relieve register pressure
    RelieveRegPressure_();
}

void
LWOPT_RPR::InitRPR_()
{
    _StmtOrderMap = WN_MAP32_Create(_LocalMemPool);
    FmtAssert(_StmtOrderMap != -1, ("Ran out of mappings"));

    _RegTable.clear();
    _LiveTable.clear();
    _DeletedStmt.clear();
    _SSARegMap.clear();
    
    WN_CFG::dfs_fwd_iterator bb_it;
    for (bb_it = _CurrentWCFG->Dfs_fwd_begin();
        bb_it != _CurrentWCFG->Dfs_fwd_end(); ++bb_it) {

        WN_CFG::BB_NODE * bb = &(*bb_it);
        AssignRegClass_(bb);
    }

    if (_TraceKind == TRACE_maximal)
        DumpRegClass_();
}

// assign a reg_class for each preg ssa idx 
void
LWOPT_RPR::AssignRegClass_(WN_CFG::BB_NODE * bb)
{
    INT32 order = 1;
    WN_CFG::BB_NODE::stmt_iterator stmt_it;
    for (stmt_it = bb->Stmt_begin() ; stmt_it != bb->Stmt_end(); ++stmt_it) {
        WN* stmt = &(*stmt_it);
        // order the stmts inside the block
        // for determining the domination relationship inside BB
        WN_MAP32_Set(_StmtOrderMap, stmt, order++);
        
        // go through the defs to assign regclass
        // go through the uses to verify it has a def regclass
        CollectDefUseExpr_(stmt);
     }       
}

// collect def and use for each stmt
// when forward scanning, just assign a new reg_class for each def and 
// verify each use has a def (i.e., reg_class has been created)
// when backward scanning, collect the live_use and live_def
void
LWOPT_RPR::CollectDefUseExpr_(WN * wn, BOOL forward) 
{
    OPERATOR opr = WN_operator(wn);
    switch (opr) {
    case OPR_FUNC_ENTRY:
        // collect the chi on the function entry
        CollectDefUseEntry_(wn, forward);
        break;
    case OPR_LABEL:
        // unify the phi opnds and collect the chi
        CollectDefUseLabel_(wn, forward);
        break;
    case OPR_RETURN:
    case OPR_RETURN_VAL:
        // collect the mu on the return
        CollectDefUseReturn_(wn, forward);
        break;
    case OPR_LDID:
    case OPR_LDBITS:
        {
            VER_IDX idx = _CurrentWSSA->Get_wn_ver(wn);
            if (IsRegCandidate_(idx)) {
                REG_IDX reg_class = FindRegClass_(idx);
                Is_True(reg_class != REG_IDX_INVALID, ("no def before use"));
                if (!forward) {
                    INT32 reg_type = _RegTable[reg_class]->GetRegType();
                    _TmpLiveUse[reg_type] = BS_Union1D(_TmpLiveUse[reg_type],
                                                        reg_class, _LocalMemPool);
                    _TmpLiveDef[reg_type] = BS_Difference1D(_TmpLiveDef[reg_type],
                                                        reg_class);
                }
            }    
        }
        break;
    case OPR_STID:
    case OPR_STBITS:
        {
            VER_IDX idx = _CurrentWSSA->Get_wn_ver(wn);
            if (IsRegCandidate_(idx)) {
                REG_IDX reg_class = FindOrCreateRegClass_(idx);
                if (!forward) {
                    INT32 reg_type = _RegTable[reg_class]->GetRegType();
                    _TmpLiveDef[reg_type] = BS_Union1D(_TmpLiveDef[reg_type], 
                                                       reg_class, _LocalMemPool);
                    _TmpLiveUse[reg_type] = BS_Difference1D(_TmpLiveUse[reg_type], 
                                                       reg_class);
                }
            }    
        }
        // fall through
    default:
        {
            for (INT32 i = 0; i < WN_kid_count(wn); i++) 
                CollectDefUseExpr_(WN_kid(wn, i), forward);
        }        
        break;
    }
}

// whether this ssa idx is a candidate for liveness analysis
// only consider the preg ssa idx
bool
LWOPT_RPR::IsRegCandidate_(VER_IDX idx)
{
    // only consider the live ranges for preg
    WST_IDX wst_idx = _CurrentWSSA->Get_ver_wst(idx);
    if (_CurrentWSSA->Get_wst_type(wst_idx) != WST_PREG)
        return false;

    const WST_Symbol_Entry wst = _CurrentWSSA->Get_wst(wst_idx);
    if (Preg_Is_Dedicated(wst.Preg_num())) 
        return false;
        
    return TRUE;
}

// collect the may-def on entry stmt
void
LWOPT_RPR::CollectDefUseEntry_(WN* entry, BOOL forward)
{
    if (WN_has_chi(entry)) {
        CollectChiDef_(entry, forward);
    }
}

// collect the may-use on return stmt
void
LWOPT_RPR::CollectDefUseReturn_(WN* ret_stmt, BOOL forward)
{
    if (WN_has_mu(ret_stmt)) {
        CollectMuUse_(ret_stmt, forward);
    }
}

// unify the opnds of phis into one regclass
// and collect def for chi
void
LWOPT_RPR::CollectDefUseLabel_(WN* label, BOOL forward)
{
    if (WN_has_phi(label)) {
        CollectPhiDefUse_(label, forward);
    }
    if (WN_has_chi(label)) {
        CollectChiDef_(label, forward);
    }
}

// collect may-def and assign a regclass
void
LWOPT_RPR::CollectChiDef_(WN* chi_node, BOOL forward)
{
    for (WHIRL_SSA_MANAGER::chi_iterator cit = _CurrentWSSA->WN_chi_begin(chi_node);
        cit != _CurrentWSSA->WN_chi_end(chi_node); ++cit) {

        VER_IDX res_idx = cit->Res();
        if (IsRegCandidate_(res_idx)) {
            REG_IDX reg_class = FindOrCreateRegClass_(res_idx);
            if (!forward) {
                INT32 reg_type = _RegTable[reg_class]->GetRegType();
                _TmpLiveDef[reg_type] = BS_Union1D(_TmpLiveDef[reg_type],
                                        reg_class, _LocalMemPool);
                _TmpLiveUse[reg_type] = BS_Difference1D(_TmpLiveUse[reg_type],
                                        reg_class);
            }
        }
    }

}

// collect may-use and find the corresponding regclass 
void
LWOPT_RPR::CollectMuUse_(WN* mu_node, BOOL forward)
{
    for (WHIRL_SSA_MANAGER::mu_iterator mit = _CurrentWSSA->WN_mu_begin(mu_node);
        mit != _CurrentWSSA->WN_mu_end(mu_node); ++mit) {
        VER_IDX opnd_idx = mit->Opnd();
        if (IsRegCandidate_(opnd_idx)) {
            REG_IDX opnd_reg_class = FindRegClass_(opnd_idx);
            Is_True(opnd_reg_class != REG_IDX_INVALID, ("use before def"));
            if (!forward) {
                INT32 reg_type = _RegTable[opnd_reg_class]->GetRegType();
                _TmpLiveUse[reg_type] = BS_Union1D(_TmpLiveUse[reg_type],
                                        opnd_reg_class, _LocalMemPool);
                _TmpLiveDef[reg_type] = BS_Difference1D(_TmpLiveDef[reg_type],
                                        opnd_reg_class);
            }
        }
    }
}

// unify the opnds of phis into one regclass
void
LWOPT_RPR::CollectPhiDefUse_(WN* phi_node, BOOL forward)
{
    REG_IDX res_reg_idx, opnd_reg_idx;
    for (WHIRL_SSA_MANAGER::phi_iterator pit = _CurrentWSSA->WN_phi_begin(phi_node);
        pit != _CurrentWSSA->WN_phi_end(phi_node); ++pit) {
            
        VER_IDX res_idx = pit->Res();
        if (!IsRegCandidate_(res_idx)) continue;

        res_reg_idx = FindOrCreateRegClass_(res_idx);

        for (INT32 i = 0; i < pit->Opnd_count(); ++i) {
            VER_IDX opnd_idx = pit->Opnd(i);
            opnd_reg_idx = FindRegClass_(opnd_idx);
            if (opnd_reg_idx == REG_IDX_INVALID) {
                SetRegClass_(opnd_idx, res_reg_idx);
                RPR_REGCLASS * res_reg_class = _RegTable[res_reg_idx];
                Is_True(res_reg_class != NULL, ("empty reg class"));
                res_reg_class->AddMember(opnd_idx);
            }
            else if (opnd_reg_idx != res_reg_idx){
                JoinRegClass_(res_reg_idx, opnd_reg_idx);
            }
        }
    }
}

// find the regclass associated with the ssa idx
// return REG_IDX_INVALID if not found
REG_IDX
LWOPT_RPR::FindRegClass_(VER_IDX idx)
{
    SSA_REG_MAP::const_iterator it = _SSARegMap.find(idx);
    if (it != _SSARegMap.end()) return it->second;

    return REG_IDX_INVALID;    
}

// find the regclass associated with the ssa idx 
// if not found, create a regclass
REG_IDX
LWOPT_RPR::FindOrCreateRegClass_(VER_IDX idx)
{
    REG_IDX reg_idx = FindRegClass_(idx);

    if (reg_idx == REG_IDX_INVALID) {
        RPR_REGCLASS *reg_class = CXX_NEW(RPR_REGCLASS, _LocalMemPool);
        WST_IDX wst_idx = _CurrentWSSA->Get_ver_wst(idx);
        Is_True(_CurrentWSSA->Get_wst_type(wst_idx) != WST_VSYM, 
            ("should not be vsym"));
        ST* wn_st = _CurrentWSSA->Get_st(wst_idx);
        if (MTYPE_is_float(TY_mtype(ST_type(wn_st)))){
            reg_class->SetRegType(REG_FP);
            _RegClassNum[REG_FP] ++;
        }    
        else {
            reg_class->SetRegType(REG_GP);
            _RegClassNum[REG_GP] ++;
        }    
        reg_class->AddMember(idx);

        // push into the _RegTable
        reg_idx = (REG_IDX) _RegTable.size();
        _RegTable.push_back(reg_class);
        SetRegClass_(idx, reg_idx);
    }

    return reg_idx;
}

// join the "from" regclass to "to" regclass and delete 
// the "from" regclass
void
LWOPT_RPR::JoinRegClass_(REG_IDX to, REG_IDX from)
{
    Is_True(to != from, ("should not be the same regclass"));
    RPR_REGCLASS* to_class = _RegTable[to];
    RPR_REGCLASS* from_class = _RegTable[from];
    Is_True(to_class != NULL && from_class != NULL, 
        ("invalid reg class"));
    Is_True(to_class->GetRegType() == from_class->GetRegType(), 
        ("same type to join"));
    Is_True(to_class->GetMembers().size() > 0 && from_class->GetMembers().size() > 0,
        ("reg class has no member"));
    
    VER_IDX idx;
    VER_IDX_VECTOR::iterator it;
    for(it = from_class->GetMembers().begin(); 
        it != from_class->GetMembers().end(); ++it){
        idx = (VER_IDX) (*it);
        SetRegClass_(idx, to);
        to_class->AddMember(idx);
    }

    _RegClassNum[from_class->GetRegType()]--;
    _RegTable[from] = NULL;
    CXX_DELETE(from_class, _LocalMemPool);
}

void
LWOPT_RPR::SetRegClass_(VER_IDX idx,  REG_IDX reg_idx)
{
    _SSARegMap[idx] = reg_idx;
}

// global liveness analysis to compute the register pressure
BOOL
LWOPT_RPR::ComputeRegPressure_()
{
    if (_CurrentWCFG->Get_max_id() * (_RegClassNum[REG_GP]+_RegClassNum[REG_FP]) >
        _OutofMemoryLimit)
        return FALSE;
        
    _LiveTable.resize(_CurrentWCFG->Get_max_id(), NULL);

    // collect the local information (live_use, live_def)
    _TmpLiveUse[REG_GP] = BS_Create_Empty(_RegClassNum[REG_GP], _LocalMemPool);
    _TmpLiveUse[REG_FP] = BS_Create_Empty(_RegClassNum[REG_FP], _LocalMemPool);
    _TmpLiveDef[REG_GP] = BS_Create_Empty(_RegClassNum[REG_GP], _LocalMemPool);
    _TmpLiveDef[REG_FP] = BS_Create_Empty(_RegClassNum[REG_FP], _LocalMemPool);
    WN_CFG::BB_NODE * bb;
    for (WN_CFG::dfs_fwd_iterator bb_it = _CurrentWCFG->Dfs_fwd_begin();
        bb_it != _CurrentWCFG->Dfs_fwd_end(); ++bb_it) {
        bb = &(*bb_it);
        CollectDefUseBB_(bb);
    }

    do {
        _LiveChange = FALSE;
        for (WN_CFG::dfs_bwd_iterator bb_it = _CurrentWCFG->Dfs_bwd_begin();
            bb_it != _CurrentWCFG->Dfs_bwd_end(); ++bb_it) {
            bb = &(*bb_it);
            LivePropagate_(bb);    
        }
    } while (_LiveChange);
    
    if (_TraceKind == TRACE_maximal) 
        DumpLiveInfo_();

    return TRUE;    
}

// collect local def/use information inside a BB 
void
LWOPT_RPR::CollectDefUseBB_(WN_CFG::BB_NODE * bb)
{
    RPR_LIVENESS * reg_live = new RPR_LIVENESS(_RegClassNum[REG_GP], 
                                               _RegClassNum[REG_FP], _LocalMemPool); 
    _LiveTable[bb->Get_id()] = reg_live;
   
    _TmpLiveUse[REG_GP] = BS_ClearD(_TmpLiveUse[REG_GP]);
    _TmpLiveUse[REG_FP] = BS_ClearD(_TmpLiveUse[REG_FP]);
    _TmpLiveDef[REG_GP] = BS_ClearD(_TmpLiveDef[REG_GP]);
    _TmpLiveDef[REG_FP] = BS_ClearD(_TmpLiveDef[REG_FP]);
 
    WN_CFG::BB_NODE::stmt_iterator stmt_it;
    for (stmt_it = bb->Stmt_rbegin();  stmt_it != bb->Stmt_rend(); ++stmt_it) {
        WN* stmt = &(*stmt_it);
        CollectDefUseExpr_(stmt, FALSE);
    }  

    SetBBLiveUse_(bb, 
        BS_CopyD(GetBBLiveUse_(bb, REG_GP), _TmpLiveUse[REG_GP], _LocalMemPool), 
        REG_GP);
    SetBBLiveUse_(bb, 
        BS_CopyD(GetBBLiveUse_(bb, REG_FP), _TmpLiveUse[REG_FP], _LocalMemPool), 
        REG_FP);
    SetBBLiveDef_(bb, 
        BS_CopyD(GetBBLiveDef_(bb, REG_GP), _TmpLiveDef[REG_GP], _LocalMemPool), 
        REG_GP);
    SetBBLiveDef_(bb, 
        BS_CopyD(GetBBLiveDef_(bb, REG_FP), _TmpLiveDef[REG_FP], _LocalMemPool), 
        REG_FP);
}   

BS*
LWOPT_RPR::GetBBLiveIn_(WN_CFG::BB_NODE * bb, REG_CLASS_TYPE reg_type)
{
    return _LiveTable[bb->Get_id()]->bb_live_in[reg_type];
}

BS*
LWOPT_RPR::GetBBLiveOut_(WN_CFG::BB_NODE * bb, REG_CLASS_TYPE reg_type)
{
    return _LiveTable[bb->Get_id()]->bb_live_out[reg_type];
}

BS*
LWOPT_RPR::GetBBLiveUse_(WN_CFG::BB_NODE * bb, REG_CLASS_TYPE reg_type)
{
    return _LiveTable[bb->Get_id()]->bb_live_use[reg_type];
}

BS*
LWOPT_RPR::GetBBLiveDef_(WN_CFG::BB_NODE * bb, REG_CLASS_TYPE reg_type)
{
    return _LiveTable[bb->Get_id()]->bb_live_def[reg_type];
}

void
LWOPT_RPR::SetBBLiveIn_(WN_CFG::BB_NODE * bb, BS* in, REG_CLASS_TYPE reg_type)
{
    _LiveTable[bb->Get_id()]->bb_live_in[reg_type] = in;
}

void
LWOPT_RPR::SetBBLiveOut_(WN_CFG::BB_NODE * bb, BS* out, REG_CLASS_TYPE reg_type)
{
    _LiveTable[bb->Get_id()]->bb_live_out[reg_type] = out;
}

void
LWOPT_RPR::SetBBLiveUse_(WN_CFG::BB_NODE * bb, BS* use, REG_CLASS_TYPE reg_type)
{
    _LiveTable[bb->Get_id()]->bb_live_use[reg_type] = use;
}

void
LWOPT_RPR::SetBBLiveDef_(WN_CFG::BB_NODE * bb, BS* def, REG_CLASS_TYPE reg_type)
{
    _LiveTable[bb->Get_id()]->bb_live_def[reg_type] = def;
}

void    
LWOPT_RPR::LivePropagate_(WN_CFG::BB_NODE * bb)
{       
    for (WN_CFG::BB_LIST::iterator succ_it = bb->Succ_begin();
        succ_it != bb->Succ_end(); ++succ_it) {
        WN_CFG::BB_NODE * succ = *succ_it;
        if (!BS_ContainsP(GetBBLiveOut_(bb, REG_GP), GetBBLiveIn_(succ, REG_GP))) {
            _LiveChange = TRUE;
            SetBBLiveOut_(bb, 
                BS_UnionD(GetBBLiveOut_(bb, REG_GP), 
                          GetBBLiveIn_(succ, REG_GP), 
                          _LocalMemPool),
                REG_GP);
        }
        if (!BS_ContainsP(GetBBLiveOut_(bb, REG_FP), GetBBLiveIn_(succ, REG_FP))) {
            _LiveChange = TRUE;
            SetBBLiveOut_(bb, 
                BS_UnionD(GetBBLiveOut_(bb, REG_FP), 
                          GetBBLiveIn_(succ, REG_FP),              
                          _LocalMemPool),
                REG_FP);
        }
    }

    LocalLivePropagate_(bb);
}   
    
void
LWOPT_RPR::LocalLivePropagate_(WN_CFG::BB_NODE * bb)
{
    _LiveTable[bb->Get_id()]->reg_pre[REG_GP] = 
        BS_Size(BS_UnionD(GetBBLiveOut_(bb, REG_GP), 
                          GetBBLiveUse_(bb, REG_GP), _LocalMemPool));
    _LiveTable[bb->Get_id()]->reg_pre[REG_FP] =
        BS_Size(BS_UnionD(GetBBLiveOut_(bb, REG_FP), 
                          GetBBLiveUse_(bb, REG_FP), _LocalMemPool));

    SetBBLiveIn_(bb, 
        BS_CopyD(GetBBLiveIn_(bb,REG_GP), GetBBLiveOut_(bb, REG_GP), _LocalMemPool), 
        REG_GP);
    SetBBLiveIn_(bb, 
        BS_CopyD(GetBBLiveIn_(bb,REG_FP), GetBBLiveOut_(bb, REG_FP), _LocalMemPool), 
        REG_FP);
    SetBBLiveIn_(bb, 
        BS_UnionD(BS_DifferenceD(GetBBLiveIn_(bb, REG_GP), GetBBLiveDef_(bb, REG_GP)),
                  GetBBLiveUse_(bb, REG_GP), _LocalMemPool), 
        REG_GP);
    SetBBLiveIn_(bb, 
        BS_UnionD(BS_DifferenceD(GetBBLiveIn_(bb, REG_FP), GetBBLiveDef_(bb, REG_FP)),
                  GetBBLiveUse_(bb, REG_FP), _LocalMemPool), 
        REG_FP);

}


// Code motion to relieve register pressure
// Here is one simple example:
// if (cond) {
// S1: = x + y;
// }
// else { ... }
// S2: = x + y;
// After PRE, the code change to
// S0: t = x + y;
// if (cond) { 
//  S1: = t;
// } else { ...}
// S2: = t;
// If both x and y are live after S2, this PRE increase one live range, which spans then/else block.
// When the block (S0) has high register pressure, we will move the computation down to its uses.
// if (cond) { 
//  t = x + y;
//  S1: = t;
// } else { ...}
// t = x + y;
// S2: = t;
// The current heuristic model only consider whether x and y are live after all inserting point.
// TODO: add PBO in the heuristic model
void
LWOPT_RPR::RelieveRegPressure_()
{
    WN_CFG::dfs_fwd_iterator bb_it;
    WN_CFG::BB_NODE * bb;

    for (bb_it = _CurrentWCFG->Dfs_fwd_begin();
        bb_it != _CurrentWCFG->Dfs_fwd_end(); ++bb_it) {
        bb = &(*bb_it);
        DownCodeMotion_(bb);
    }

    // delete the stmt at the last
    DeleteStmts_();

    if (_TraceKind >= TRACE_info) {
        fprintf(TFile, "\n[STAT] \n");
        fprintf(TFile, "========== %d Statements MOVED ==========\n", 
            _NumExprMoved);
    }
}

void
LWOPT_RPR::DownCodeMotion_(WN_CFG::BB_NODE * bb)
{
    if (bb->Get_id() == _AvoidBB) return;

    if (!BB_high_reg_gp(bb) && !BB_high_reg_fp(bb))
        _BBMoveType = MOVE_NONE;
    else if (BB_high_reg_gp(bb) && !BB_high_reg_fp(bb))
        _BBMoveType = MOVE_GP;
    else if (!BB_high_reg_gp(bb) && BB_high_reg_fp(bb))
        _BBMoveType = MOVE_FP;
    else
        _BBMoveType = MOVE_BOTH;

    if (_BBMoveType == MOVE_NONE) return;
        
    // if the block has high register pressure, perform
    // the code motion
    WN_CFG::BB_NODE::stmt_iterator stmt_it;
    std::vector<WN*> dom_uses;
    for (stmt_it = bb->Stmt_begin();  stmt_it != bb->Stmt_end(); ++stmt_it) {
        WN* stmt = &(*stmt_it);
        if (!MoveableStmt_(stmt)) continue;
        dom_uses.clear();
        if (GetClosestUses_(stmt, dom_uses) &&
            LegalDownMove_(stmt, dom_uses) &&
            ProfitableDownMove_(stmt, dom_uses)) {
            MoveDownToUses_(stmt, dom_uses);
        }    
    }
}

// find the smallest set of the dominating uses
bool
LWOPT_RPR::GetClosestUses_(WN* stmt, vector<WN*> & dom_uses)
{
    Is_True(WN_def_ver(stmt), ("should have defs"));
    VER_IDX idx = _CurrentWSSA->Get_wn_ver(stmt);
    if (!_CurrentDU->Ver_has_use(idx)) return false;

    WN_CFG::BB_NODE* def_bb = _CurrentWCFG->Get_wn_node(stmt);
    vector<WN*> tmp_uses;
    list<WN*> tmp_dom_uses;
    tmp_dom_uses.clear();
    tmp_uses.clear();
    for (WSSA_DU_MANAGER::const_iterator it = _CurrentDU->begin(idx); 
        it != _CurrentDU->end(idx); ++it) {
        WN* use_wn = const_cast<WN*>(it->Get_use_wn());

        if (MuHasDefVsym_(_CurrentWCFG->Get_parent_stmt(use_wn))) 
            return false;
        
        // if there is any use that is in the same bb as stmt(def), no move.
        // if the use is a phi, then the block is the src of the edge.
        // scheduling should handle well with within bb move.
        if (WN_operator(use_wn) == OPR_LABEL) {
            //return false;
            vector<WN_CFG::BB_NODE*> nodes;
            nodes.clear();
            GetPhiPred_(stmt, use_wn, nodes);
            for (INT32 i = 0; i < nodes.size(); i++) {
                if (nodes[i] == def_bb) return false;
            }
        }
        else if (_CurrentWCFG->Get_wn_node(use_wn) == def_bb)
            return false;
        tmp_uses.push_back(use_wn);
    }
    if (tmp_uses.size() == 1) {
        dom_uses.push_back(tmp_uses[0]);
    }
    else {
        vector<WN*> delete_uses;
        tmp_dom_uses.push_back(tmp_uses[0]);
        bool should_insert = true;
        for (INT32 i = 1; i < tmp_uses.size(); i++) {
            should_insert = true;
            delete_uses.clear();    
            for (list<WN*>::iterator it = tmp_dom_uses.begin();
                it != tmp_dom_uses.end(); ++it) {
                if (IsStmtDominating_(tmp_uses[i], *it)) {
                    // dom_uses.erase j
                    delete_uses.push_back(*it);
                }
                else if (IsStmtDominating_(*it, tmp_uses[i])) {
                    should_insert = false;
                    break;
                }
            }
            for (vector<WN*>::iterator it = delete_uses.begin();
                it != delete_uses.end(); ++it) {
                tmp_dom_uses.remove(*it);
            }
            if (should_insert)
                tmp_dom_uses.push_back(tmp_uses[i]);
        }

        for (list<WN*>::iterator it = tmp_dom_uses.begin();
            it != tmp_dom_uses.end(); ++it) {
            dom_uses.push_back(*it);
        }    
    }      

    return true;
}

// get the predessors that the phi's opnd (def) come from
void
LWOPT_RPR::GetPhiPred_(WN* def, WN* phi, vector<WN_CFG::BB_NODE*> & nodes)
{
    VER_IDX def_idx = _CurrentWSSA->Get_wn_ver(def);
    WN_CFG::BB_NODE* phi_bb = _CurrentWCFG->Get_wn_node(phi);
    WN_CFG::BB_NODE* def_bb = _CurrentWCFG->Get_wn_node(def);
    
    for (WHIRL_SSA_MANAGER::phi_iterator pit = _CurrentWSSA->WN_phi_begin(phi); 
        pit != _CurrentWSSA->WN_phi_end(phi); ++pit) {
        for (INT32 i = 0; i < pit->Opnd_count(); i++) {
            if (pit->Opnd(i) == def_idx){
                WN_CFG::BB_NODE* pred_bb = const_cast<WN_CFG::BB_NODE*>(phi_bb->Get_pred(i));
                Is_True(def_bb == pred_bb || def_bb->Dominate(pred_bb), 
                    ("not the right order of phi opnds"));
                nodes.push_back(pred_bb);
            }
        }
    }
        
    Is_True(nodes.size() > 0, ("no preds is found"));
}

INT32
LWOPT_RPR::GetStmtOrder_(WN* stmt)
{
    if (WN_operator(stmt) == OPR_FUNC_ENTRY ||
        OPERATOR_is_stmt(WN_operator(stmt)))
        return WN_MAP32_Get(_StmtOrderMap, stmt);

    Is_True(_CurrentWCFG->Get_parent_stmt(stmt) != NULL, ("null parent stmt"));
    return WN_MAP32_Get(_StmtOrderMap, _CurrentWCFG->Get_parent_stmt(stmt));
}

// return true if the first stmt dominates the second stmt
bool
LWOPT_RPR::IsStmtDominating_(WN* first, WN* second)
{
    WN_CFG::BB_NODE* first_bb = _CurrentWCFG->Get_wn_node(first);
    WN_CFG::BB_NODE* second_bb = _CurrentWCFG->Get_wn_node(second);

    if (first_bb != second_bb) {
        return (first_bb->Dominate(second_bb));
    }
    else {
        return (GetStmtOrder_(first) <= GetStmtOrder_(second));
    }
}

// return true if the first ver's def stmt dominates the second ver's def stmt
bool
LWOPT_RPR::IsVerDominating_(VER_IDX first, VER_IDX second)
{
    const WST_Version_Entry& first_ver = _CurrentWSSA->Get_ver(first);
    const WST_Version_Entry& second_ver = _CurrentWSSA->Get_ver(second);
    WN* first_stmt = const_cast<WN*>(first_ver.Get_def_wn());
    WN* second_stmt = const_cast<WN*>(second_ver.Get_def_wn());

    return (IsStmtDominating_(first_stmt, second_stmt));
}

// whether legal to move down
// no redefinition of rhs in between
bool 
LWOPT_RPR::LegalDownMove_(WN* def, vector<WN*> & dom_uses)
{
    for (INT32 i = 0; i < dom_uses.size(); i++) {
        // for phi uses, the stmt will move to its related predecessors
        // thus consider the legality of moving to predecessors
        if (WN_operator(dom_uses[i]) == OPR_LABEL) {
            vector<WN_CFG::BB_NODE*> phi_preds;
            phi_preds.clear();
            GetPhiPred_(def, dom_uses[i], phi_preds);
            for (INT32 i = 0; i < phi_preds.size(); i++) {
                WN* last_stmt = phi_preds[i]->Last_stmt();
                Is_True(last_stmt, ("no last stmt"));
                if (!LegalDownMove_(def, last_stmt))
                    return false;
            }
        }
        else {
            if (!LegalDownMove_(def, dom_uses[i]))
                return false;
        }        
    }
    return true;
}

bool
LWOPT_RPR::LegalDownMove_(WN* def, WN* use)
{
    OPERATOR opr = WN_operator(def);
    switch(opr) {
    case OPR_LDID:
    case OPR_LDBITS:
    case OPR_ILOAD:
    case OPR_ILDBITS:
    case OPR_MLOAD:
        if (!DefReachable_(def, use))
            return false;
        break;
    default:
        for (INT32 i = 0; i < WN_kid_count(def); i++) {
            if (!LegalDownMove_(WN_kid(def, i), use))
                return false;
        }
        break;        
    }   
    return true;
}

bool
LWOPT_RPR::DefReachable_(WN* def, WN* use)
{
    if (_CurrentWSSA->WN_has_mu(def)) {
        for (WHIRL_SSA_MANAGER::mu_iterator mit = _CurrentWSSA->WN_mu_begin(def);
             mit != _CurrentWSSA->WN_mu_end(def); ++mit) {
             VER_IDX def_idx = mit->Opnd();
             if (!VerReachable_(def_idx, use))
                return false;
        }     
    }
    if (WN_has_ver(def))
        return VerReachable_(_CurrentWSSA->Get_wn_ver(def), use);
}

// determine whether there is redefine of rhs by checking
// the reaching def at the use is the same as the rhs's def
bool
LWOPT_RPR::VerReachable_(VER_IDX def_idx, WN * use) 
{
    WST_IDX def_wst_idx = _CurrentWSSA->Get_ver_wst(def_idx);
    const WST_Symbol_Entry def_wst = _CurrentWSSA->Get_wst(def_wst_idx);
    VER_IDX pre_idx = def_wst.Last_ver();
    vector<bool> idx_visit;
    vector<VER_IDX> dom_defs;
    dom_defs.clear();
    idx_visit.resize(_CurrentWSSA->Ver_count(), false);
    while (pre_idx != VER_INVALID) {
        const WST_Version_Entry& pre_ver = _CurrentWSSA->Get_ver(pre_idx);
        WN* pre_stmt = const_cast<WN*>(pre_ver.Get_def_wn());
        if (IsStmtDominating_(pre_stmt, use))
            dom_defs.push_back(pre_idx);
        Is_True(idx_visit[pre_idx] == false, ("def chain should not have cycle"));
        idx_visit[pre_idx] = true;
        pre_idx = pre_ver.Prev_ver();
        
    }

    FmtAssert(dom_defs.size()>0, ("no dominating defs"));
    if (GetLatestDef_(dom_defs) == def_idx) return true;
    
    return false;
}

// get the latest def (i.e.,reaching def) from a set of dominating defs
VER_IDX
LWOPT_RPR::GetLatestDef_(vector<VER_IDX> &dom_defs)
{
    if (dom_defs.size() == 1) 
        return (dom_defs.back());

    VER_IDX latest_def = dom_defs.back();
    dom_defs.pop_back();
    bool change = false;
    for (INT32 i = 0; i < dom_defs.size(); i++) {
        change = false;

        if (IsVerDominating_(latest_def, dom_defs[i])) {
            change = true;
        }
        else 
        {
            FmtAssert(IsVerDominating_(dom_defs[i], latest_def), ("wrong dom defs"));
        }
        if (change)
            latest_def = dom_defs[i];
    }

    return (latest_def);
}

bool
LWOPT_RPR::ProfitableDownMove_(WN* stmt, vector<WN*> & dom_uses)
{
    // simple heuristic: the rhs of stmt should live after all dom_uses
    if (!LiveAfter_(stmt, dom_uses))
        return false;

    // consider the computation cost for the stmt
    if (_InstrCompCost > _CompCostLimit)
        return false;
    
    return true;
}

bool
LWOPT_RPR::LiveAfter_(WN* stmt, vector<WN*> & dom_uses)
{
    OPERATOR opr = WN_operator(stmt);
    if (opr == OPR_LDID || opr == OPR_LDBITS) {
        for (INT32 i = 0; i < dom_uses.size(); i++) {
            WN_CFG::BB_NODE* use_bb = _CurrentWCFG->Get_wn_node(dom_uses[i]);
            VER_IDX idx = _CurrentWSSA->Get_wn_ver(stmt);
            if (IsRegCandidate_(idx)) {
                REG_IDX reg_class = FindRegClass_(idx);
                Is_True(reg_class != REG_IDX_INVALID, ("no def before use"));
                if (!_LiveTable[use_bb->Get_id()]->LiveIn(reg_class))
                    return false;
            }
        }
    }
    for (INT32 i = 0; i < WN_kid_count(stmt); i++)
        if (!LiveAfter_(WN_kid(stmt, i), dom_uses))
            return false;

    return true;
}

// perform the code motion
void
LWOPT_RPR::MoveDownToUses_(WN* stmt, vector<WN*> & dom_uses)
{
    if (_NumExprMoved >= _ExprLimit) {
        if (_TraceKind == TRACE_maximal) {
            fprintf(TFile, "[TRANSFORM] SKIP \n");
            fdump_tree(TFile, stmt);
        }
        return;
    }    

    _NumExprMoved ++;

    if (_TraceKind == TRACE_maximal) {
        fprintf(TFile, "[TRANSFORM] \n");
        fprintf(TFile, "================ MOVE ================\n");
        fdump_tree(TFile, stmt);
    }
    
    for (vector<WN*>::iterator it = dom_uses.begin();
        it != dom_uses.end(); ++it) {
        WN* use_stmt = _CurrentWCFG->Get_parent_stmt(*it);
        Is_True(use_stmt != NULL, ("should not be null parent"));
        
        if (_TraceKind == TRACE_maximal) {
            fprintf(TFile, "================= TO =================\n");
            fdump_tree(TFile, use_stmt);
        }
        // processing phis
        if (WN_operator(use_stmt) == OPR_LABEL) {
            vector<WN_CFG::BB_NODE*> phi_preds;
            phi_preds.clear();
            GetPhiPred_(stmt, use_stmt, phi_preds);
            for (INT32 i = 0; i < phi_preds.size(); i++) {
                WN* last_stmt = phi_preds[i]->Last_stmt();
                WN* new_stmt = _CurrentUpdate->Copy_tree(stmt);
                Is_True(last_stmt, ("no last stmt"));
                if (IsBranchOp_(WN_operator(last_stmt))) {
                    _CurrentUpdate->Insert_before(_CurrentWCFG->Get_parent_block(last_stmt),
                        last_stmt, new_stmt); 
                }
                else {
                    _CurrentUpdate->Insert_after(_CurrentWCFG->Get_parent_block(last_stmt),
                        last_stmt, new_stmt);
                }
            }    
        }
        else {
            WN* new_stmt = _CurrentUpdate->Copy_tree(stmt);
            WN_CFG::BB_NODE* use_bb = _CurrentWCFG->Get_wn_node(use_stmt);
            Is_True(use_bb != NULL, ("no bb"));
            _CurrentUpdate->Insert_before(_CurrentWCFG->Get_parent_block(use_stmt),
                use_stmt, new_stmt);
        }
    }
    _DeletedStmt.push_back(stmt);
}

void
LWOPT_RPR::DeleteStmts_()
{
    for (INT32 i=0; i< _DeletedStmt.size(); i++)
    {
        WN* stmt = _DeletedStmt[i];
        _CurrentUpdate->Delete_stmt(_CurrentWCFG->Get_parent_block(stmt), stmt);
    }
}
bool 
LWOPT_RPR::BB_high_reg_gp(WN_CFG::BB_NODE * bb)
{
    Is_True(_LiveTable[bb->Get_id()] != NULL, 
        ("invalid live information of BB %d\n", bb->Get_id()));
    
    if (_LiveTable[bb->Get_id()]->GetRegPreGP() > _RegGPLimit)
        return true;
        
    return false;

}

bool
LWOPT_RPR::BB_high_reg_fp(WN_CFG::BB_NODE * bb)
{
    Is_True(_LiveTable[bb->Get_id()] != NULL,
        ("invalid live information of BB %d\n", bb->Get_id()));

    if (_LiveTable[bb->Get_id()]->GetRegPreFP() > _RegFPLimit)
        return true;

    return false;

}

bool
LWOPT_RPR::MuHasDefVsym_(WN *wn)
{
    if (_CurrentWSSA->WN_has_mu(wn)) {
        for (WHIRL_SSA_MANAGER::mu_iterator mit = _CurrentWSSA->WN_mu_begin(wn);
            mit != _CurrentWSSA->WN_mu_end(wn); ++mit) {
            VER_IDX opnd_idx = mit->Opnd();
            WST_IDX opnd_wst_idx = _CurrentWSSA->Get_ver_wst(opnd_idx);
            if (opnd_wst_idx == _CurrentWSSA->Default_vsym()) return true;
        }
    }

    for (INT32 i = 0; i < WN_kid_count(wn); i++)
        if (MuHasDefVsym_(WN_kid(wn,i)))
            return true;

    return false;

}

// whether this expr is moveable
bool
LWOPT_RPR::MoveableExprs_(WN *wn)
{
    OPERATOR opr = WN_operator(wn);
    switch(opr) {
    case OPR_LDID:
    case OPR_LDBITS:
    case OPR_STBITS:
    case OPR_STID:
        if (ST_class(WN_st(wn)) == CLASS_PREG && 
            Preg_Is_Dedicated(WN_offset(wn)))
            return false;
        _InstrCompCost = _InstrCompCost + 1;       
        break;
    case OPR_CONST:
    case OPR_LDA:
    case OPR_INTCONST:
        _InstrCompCost = _InstrCompCost + 1;       
        break;
    case OPR_ILOAD:
    case OPR_ILDBITS:
        {
        for (WHIRL_SSA_MANAGER::mu_iterator mit = _CurrentWSSA->WN_mu_begin(wn);
            mit != _CurrentWSSA->WN_mu_end(wn); ++mit) {
                VER_IDX opnd_idx = mit->Opnd();
                WST_IDX opnd_wst_idx = _CurrentWSSA->Get_ver_wst(opnd_idx);
                if (opnd_wst_idx == _CurrentWSSA->Default_vsym()) 
                    return false;
            }    
        }   
        _InstrCompCost = _InstrCompCost + 4;
        break;
    case OPR_SELECT:
    case OPR_MIN:
    case OPR_MAX:
    case OPR_MINMAX:
    case OPR_ALLOCA:
    case OPR_DEALLOCA:
        return false;

    case OPR_DIV:
    case OPR_MOD:
    case OPR_REM:
    case OPR_DIVREM:
    case OPR_MPY:
        _InstrCompCost = _InstrCompCost + 8;
        break;

    default:
        _InstrCompCost = _InstrCompCost + 2;
        break;        
    }

    for (INT32 i = 0; i < WN_kid_count(wn); i++)
        if (!MoveableExprs_(WN_kid(wn,i)))
            return false;
            
    return true;            
}

bool
LWOPT_RPR::MoveableStmt_(WN* stmt)
{
    OPERATOR opr = WN_operator(stmt);
    _InstrCompCost = 0;
    if ((opr == OPR_STID || opr == OPR_STBITS) &&
        GetStmtOrder_(stmt) != 0 &&
        !Tree_is_volatile(stmt) &&
        ST_class(WN_st(stmt)) == CLASS_PREG &&
        MoveableExprs_(stmt)) {
        VER_IDX idx = _CurrentWSSA->Get_wn_ver(stmt);
        if (IsRegCandidate_(idx)){
            REG_IDX reg_class = FindRegClass_(idx);
            Is_True(reg_class != REG_IDX_INVALID, ("not find the reg class"));
            if ((_RegTable[reg_class]->GetRegType() == REG_GP && _BBMoveType != MOVE_FP) ||
                (_RegTable[reg_class]->GetRegType() == REG_FP && _BBMoveType != MOVE_GP))
                return true;
        }
    }
         
    return false;
}

bool
LWOPT_RPR::IsBranchOp_(OPERATOR opr) {
    if (opr == OPR_RETURN ||
      opr == OPR_RETURN_VAL ||
      opr == OPR_GOTO ||
      opr == OPR_TRUEBR ||
      opr == OPR_FALSEBR)
    return TRUE;
  else
    return FALSE;
}

// dump functions
// dump the regclass assignment
void        
LWOPT_RPR::DumpRegClass_()
{           
    fprintf(TFile, "[RegClass Assignment]\n");
    SSA_REG_MAP::const_iterator it;
    for (it = _SSARegMap.begin(); it != _SSARegMap.end(); it++) {
        VER_IDX idx = (VER_IDX) it->first;
        WST_IDX wst_idx = _CurrentWSSA->Get_ver_wst(idx);
        fprintf(TFile, "SSAName %-10sv%d RegClass %d\n",
            _CurrentWSSA->WST_name(wst_idx), _CurrentWSSA->Get_ver_num(idx), it->second);
    }
    fprintf(TFile, "\n");
}
    
// dump the liveness analysis result
void
LWOPT_RPR::DumpLiveInfo_()
{
    fprintf(TFile, "[Liveness Information]\n");
    WN_CFG::dfs_fwd_iterator bb_it;
    for (bb_it = _CurrentWCFG->Dfs_fwd_begin();
        bb_it != _CurrentWCFG->Dfs_fwd_end(); ++bb_it) {
        WN_CFG::BB_NODE * bb = &(*bb_it);
        fprintf(TFile, "============== BB:%d GP %d FP %d ==============\n",
            bb->Get_id(), _LiveTable[bb->Get_id()]->GetRegPreGP(),
            _LiveTable[bb->Get_id()]->GetRegPreFP());
        fprintf (TFile, "  GP live in     : ");
        BS_Print(_LiveTable[bb->Get_id()]->bb_live_in[REG_GP], TFile);
        fprintf (TFile, "\n");
        fprintf (TFile, "  GP live out    : ");
        BS_Print(_LiveTable[bb->Get_id()]->bb_live_out[REG_GP], TFile);
        fprintf (TFile, "\n");
        fprintf (TFile, "  GP live use    : ");
        BS_Print(_LiveTable[bb->Get_id()]->bb_live_use[REG_GP], TFile);
        fprintf (TFile, "\n");
        fprintf (TFile, "  GP live def    : ");
        BS_Print(_LiveTable[bb->Get_id()]->bb_live_def[REG_GP], TFile);
        fprintf (TFile, "\n");
        fprintf (TFile, "\n");

        fprintf (TFile, "  FP live in     : ");
        BS_Print(_LiveTable[bb->Get_id()]->bb_live_in[REG_FP], TFile);
        fprintf (TFile, "\n");
        fprintf (TFile, "  FP live out    : ");
        BS_Print(_LiveTable[bb->Get_id()]->bb_live_out[REG_FP], TFile);
        fprintf (TFile, "\n");
        fprintf (TFile, "  FP live use    : ");
        BS_Print(_LiveTable[bb->Get_id()]->bb_live_use[REG_FP], TFile);
        fprintf (TFile, "\n");
        fprintf (TFile, "  FP live def    : ");
        BS_Print(_LiveTable[bb->Get_id()]->bb_live_def[REG_FP], TFile);
        fprintf (TFile, "\n");

    }
    fprintf(TFile, "\n");
}
