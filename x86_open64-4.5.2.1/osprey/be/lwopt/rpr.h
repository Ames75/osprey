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
//
// Module: rpr.h
//
// Description:
//
// ====================================================================


#ifndef lwopt_rpr_INCLUDED
#define lwopt_rpr_INCLUDED

#include "comp_decl.h"
#include "wn_cfg.h"
#include "wn_map.h"
#include "wssa_utils.h"
#include "wssa_mgr.h"
#include "wssa_du.h"
#include "wssa_update.h"
#include "cfg_util.h"
#include <vector>
#include <ext/hash_map>
#include "bitset.h"

using __gnu_cxx::hash_map;

using namespace WSSA;
using namespace CFG_UTIL;

typedef enum
{
    REG_GP = 0,
    REG_FP,
    REG_NUM
} REG_CLASS_TYPE;

#define INVALID_REG ((UINT32) -1)

typedef enum 
{
    REG_IDX_ZERO    = 0,
    REG_IDX_INVALID = INVALID_REG
} REG_IDX;    

typedef enum    
{
    MOVE_NONE = 0,
    MOVE_GP,
    MOVE_FP,
    MOVE_BOTH
} MOVE_TYPE;

typedef std::vector<UINT32 /*VER_IDX*/> VER_IDX_VECTOR;

class RPR_REGCLASS
{
private:
    REG_CLASS_TYPE  _regType;
    VER_IDX_VECTOR  _members;
    
public:
    RPR_REGCLASS()  { _members.clear(); };
    ~RPR_REGCLASS() { };

    REG_CLASS_TYPE  GetRegType()                    { return _regType; }
    void            SetRegType(REG_CLASS_TYPE ty)   { _regType = ty; }
    void            AddMember(VER_IDX idx)          { _members.push_back(idx); }
    VER_IDX_VECTOR& GetMembers()                    { return _members; }
};

// class for expressing liveness information for a BB
class RPR_LIVENESS
{
public:

    BS *    bb_live_in[REG_NUM];
    BS *    bb_live_out[REG_NUM];
    BS *    bb_live_use[REG_NUM];
    BS *    bb_live_def[REG_NUM];
    UINT32  reg_pre[REG_NUM];

    RPR_LIVENESS(UINT32 reg_size_gp, UINT32 reg_size_fp, MEM_POOL* mpool)
    {
        bb_live_in[REG_GP] = BS_Create_Empty(reg_size_gp, mpool);
        bb_live_in[REG_FP] = BS_Create_Empty(reg_size_fp, mpool);
        bb_live_out[REG_GP] = BS_Create_Empty(reg_size_gp, mpool);
        bb_live_out[REG_FP] = BS_Create_Empty(reg_size_fp, mpool);
        bb_live_use[REG_GP] = BS_Create_Empty(reg_size_gp, mpool);
        bb_live_use[REG_FP] = BS_Create_Empty(reg_size_fp, mpool);
        bb_live_def[REG_GP] = BS_Create_Empty(reg_size_gp, mpool);
        bb_live_def[REG_FP] = BS_Create_Empty(reg_size_fp, mpool);
        reg_pre[REG_GP] = 0;
        reg_pre[REG_FP] = 0;
    }
    
    ~RPR_LIVENESS()   {};

    UINT32  GetRegPreGP()   { return reg_pre[REG_GP]; }
    UINT32  GetRegPreFP()   { return reg_pre[REG_FP]; }
    
    bool    LiveIn(REG_IDX reg) { return (BS_MemberP(bb_live_in[REG_GP], reg) ||
                                         BS_MemberP(bb_live_in[REG_FP], reg)); }
                                              
    bool    LiveOut(REG_IDX reg){ return (BS_MemberP(bb_live_out[REG_GP], reg) ||
                                         BS_MemberP(bb_live_out[REG_FP], reg)); }
    
}; 

typedef hash_map<UINT32 /*VER_IDX*/, REG_IDX>   SSA_REG_MAP;
typedef std::vector<RPR_REGCLASS*>              REG_TABLE;
typedef std::vector<RPR_LIVENESS*>              LIVENESS_TABLE;

class LWOPT_RPR: public O64_Component
{
public:
    enum OPTION
    {
        LWOPT_rpr_first = OPT_component_first,
        LWOPT_rpr_gp_limit = LWOPT_rpr_first,
        LWOPT_rpr_fp_limit,
        LWOPT_rpr_avoid_bb,
        LWOPT_rpr_expr_limit,
        LWOPT_rpr_comp_cost,
        LWOPT_rpr_memory_limit,
        LWOPT_rpr_last 
    };

    static const O64_ComponentDescriptor ComponentDescriptor; 
    static const O64_OptionDescriptor
        OptionDescriptors[LWOPT_rpr_last - LWOPT_rpr_first + 1];

    LWOPT_RPR();
    ~LWOPT_RPR();

private:

    WN *                    _CurrentWN;
    WN_CFG*                 _CurrentWCFG;
    WHIRL_SSA_MANAGER *     _CurrentWSSA;
    WSSA_DU_MANAGER*        _CurrentDU;
    WSSA_UPDATER*           _CurrentUpdate;

    WN_MAP                  _StmtOrderMap;
    SSA_REG_MAP             _SSARegMap;
    REG_TABLE               _RegTable;
    LIVENESS_TABLE          _LiveTable;
    vector<WN*>             _DeletedStmt;
    
    UINT32                  _NumExprMoved;
    UINT32                  _RegGPLimit;
    UINT32                  _RegFPLimit; 
    UINT32                  _ExprLimit;
    UINT32                  _AvoidBB;
    UINT32                  _CompCostLimit;
    UINT32                  _OutofMemoryLimit;

    BOOL                    _LiveChange;
    BS *                    _TmpLiveUse[REG_NUM];
    BS *                    _TmpLiveDef[REG_NUM];
    UINT32                  _RegClassNum[REG_NUM];

    MOVE_TYPE               _BBMoveType;
    UINT32                  _InstrCompCost;
    
    
    void    Perform_();
    void    InitRPR_();
    BOOL    ComputeRegPressure_();
    void    RelieveRegPressure_();

    // assign a regclass for each def
    void    AssignRegClass_(WN_CFG::BB_NODE*);
    void    CollectDefUseBB_(WN_CFG::BB_NODE*);
    void    CollectDefUseExpr_(WN*, BOOL forward = TRUE);
    void    CollectDefUseReturn_(WN*, BOOL forward = TRUE);
    void    CollectDefUseEntry_(WN*, BOOL forward = TRUE);
    void    CollectDefUseLabel_(WN*, BOOL forward = TRUE);
    void    CollectChiDef_(WN*, BOOL foward = TRUE);
    void    CollectMuUse_ (WN*, BOOL foward = TRUE);
    void    CollectPhiDefUse_(WN*, BOOL foward = TRUE);

    bool    IsRegCandidate_(VER_IDX);
    REG_IDX FindRegClass_(VER_IDX);
    REG_IDX FindOrCreateRegClass_(VER_IDX);
    void    JoinRegClass_(REG_IDX, REG_IDX);
    void    SetRegClass_(VER_IDX,  REG_IDX);

    // global liveness analysis
    void    LivePropagate_(WN_CFG::BB_NODE*);
    void    LocalLivePropagate_(WN_CFG::BB_NODE*);
    BS*     GetBBLiveIn_(WN_CFG::BB_NODE *, REG_CLASS_TYPE);
    BS*     GetBBLiveOut_(WN_CFG::BB_NODE *, REG_CLASS_TYPE);
    BS*     GetBBLiveUse_(WN_CFG::BB_NODE *, REG_CLASS_TYPE);
    BS*     GetBBLiveDef_(WN_CFG::BB_NODE *, REG_CLASS_TYPE);
    void    SetBBLiveIn_(WN_CFG::BB_NODE *, BS*, REG_CLASS_TYPE);
    void    SetBBLiveOut_(WN_CFG::BB_NODE *, BS*, REG_CLASS_TYPE);
    void    SetBBLiveUse_(WN_CFG::BB_NODE *, BS*, REG_CLASS_TYPE);
    void    SetBBLiveDef_(WN_CFG::BB_NODE *, BS*, REG_CLASS_TYPE);

    // code motion to relieve register pressure
    void    DownCodeMotion_(WN_CFG::BB_NODE*);
    bool    BB_high_reg_gp(WN_CFG::BB_NODE *);
    bool    BB_high_reg_fp(WN_CFG::BB_NODE *);

    bool    MuHasDefVsym_(WN*);
    bool    MoveableStmt_(WN*);
    bool    MoveableExprs_(WN*);
    bool    GetClosestUses_(WN*, vector<WN*> &);

    // legal to move?
    bool    LegalDownMove_(WN*, vector<WN*> &);
    bool    LegalDownMove_(WN*, WN*);
    bool    DefReachable_(WN*, WN*);
    bool    VerReachable_(VER_IDX, WN *);
    VER_IDX GetLatestDef_(vector<VER_IDX> &);

    // profitable to move?
    bool    ProfitableDownMove_(WN*, vector<WN*> &);
    bool    LiveAfter_(WN*, vector<WN*> &);
    void    GetPhiPred_(WN*, WN*, vector<WN_CFG::BB_NODE*> &);
    INT32   GetStmtOrder_(WN*);
    bool    IsStmtDominating_(WN*, WN*);
    bool    IsVerDominating_(VER_IDX, VER_IDX);

    // move and delete the stmts
    void    MoveDownToUses_(WN*, vector<WN*> &);
    void    DeleteStmts_();
    bool    IsBranchOp_(OPERATOR opr);

    // dump functions
    void    DumpRegClass_();
    void    DumpLiveInfo_();

};

extern void fdump_tree (FILE*, WN*);

#endif /* lwopt_rpr_INCLUDED */
