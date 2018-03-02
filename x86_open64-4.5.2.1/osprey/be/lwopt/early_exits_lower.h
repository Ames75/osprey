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
// Module: early_exits_lower.h
//
// Description:
//
// ====================================================================


#ifndef lwopt_early_exits_lower_INCLUDED
#define lwopt_early_exits_lower_INCLUDED

#include <vector>
#include <list>
#include <set>
#include <map>
#include <iostream>

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
#include "wssa_update.h"

using namespace WSSA;
using namespace CFG_UTIL;

#include "slp_utils.h"
using namespace slp;

class chain;

class LWOPT_LOWER: public O64_Component
{
public:
    enum OPTION
    {
        LWOPT_lower_first = OPT_component_first,
        LWOPT_lower_skip_BB_before = LWOPT_lower_first,
        LWOPT_lower_skip_BB_after,
        LWOPT_lower_last
    };

    static const O64_ComponentDescriptor ComponentDescriptor; 
    static const O64_OptionDescriptor
        OptionDescriptors[LWOPT_lower_last - LWOPT_lower_first + 1];

    LWOPT_LOWER() ;
    ~LWOPT_LOWER(){};
    
private:

    void lower();
    void collect_intrinsics(WN_CFG::BB_NODE*, list<WN*>&, list<WN*>&, 
			    list<WN*>&, list<WN*>&);
    void lower_intrinsics(list<WN*>&, INTRINSIC);
    void lower_Switch_Return(WN*);
    void lower_VSwitch_Return(WN*);
    void lower_Switch_Branch(WN*);
    void lower_VSwitch_Branch(WN*);

    WN*  gen_movemask(WN*);
    WN*  gen_mask(WN*, int, WN*);
    WN*  gen_if(WN*, WN*);
    WN*  gen_ctz(WN*, WN*);
    WN*  gen_lshr1(WN*, WN*);
    WN*  gen_an_intrinsic(INTRINSIC, WN_OFFSET, ST*, WN**, int, TY_IDX[]);
    void gen_cvted_cond(WN*, WN*);
    void gen_COMPGOTO(WN*, WN*);
    ST* create_symbol();

    void gen_stid_to_temp_mem(WN*, WN*, WN*);
    void gen_return(WN*, WN*, int, bool);
    void EE_LOWER_insert_after (WN*, WN*);
    void EE_LOWER_insert_before(WN*, WN*);
    void set_map_id(WN*);

    void set_conditional(VER_IDX vidx){ _conditionals.insert(vidx); };
    bool is_conditional(WN*);

    WN *                        CurrentWN_;
    WHIRL_SSA_MANAGER *         CurrentWSSA_;
    WSSA_DU_MANAGER *           CurrentWSSA_DU_;
    WN_CFG*                     CurrentWCFG_;
    MEM_POOL                    mem_pool;
    int                         SIMD_reg_width;
    WN*                         block;
    WSSA_UPDATER*               wssa_updater;

    ST*                         temp_stack_mem;
    RETURN_INFO                 return_info;
    WN_OFFSET                   ret_preg;
    TYPE_ID                     ret_type;
    ST*                         ret_st;
    TYPE_ID                     mtype;

    set<VER_IDX>                _conditionals;
};


#endif /* lwopt_early_exits_lower_INCLUDED */
