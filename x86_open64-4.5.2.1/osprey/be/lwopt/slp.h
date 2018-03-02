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
// Module: slp.h
//
// Description:
//
// ====================================================================


#ifndef lwopt_slp_INCLUDED
#define lwopt_slp_INCLUDED

#include <vector>
#include <set>
#include <map>
#include <iostream>

#include "comp_decl.h"
#include "wn_cfg.h"
#include "wn.h"
#include "wn_util.h"
#include "symtab_defs.h"
#include "wssa_du.h"
#include "ir_reader.h"
#include "wssa_update.h"

using namespace WSSA;
using namespace CFG_UTIL;

#include "slp_utils.h"
#include "slp_lin_eq.h"
#include "slp_statement.h"
#include "slp_distance.h"
#include "slp_dependence.h"
#include "slp_statement_pack.h"
#include "slp_schedule.h"
#include "slp_symbol_pack.h"
#include "slp_switch_br_ret.h"
#include "slp_transform.h"
#include "slp_main.h"

using namespace slp;


class LWOPT_SLP: public O64_Component
{
public:
    enum OPTION
    {
        LWOPT_slp_first = OPT_component_first,
        LWOPT_slp_skip_BB_before = LWOPT_slp_first,
        LWOPT_slp_skip_BB_after,
        LWOPT_slp_last
    };

    static const O64_ComponentDescriptor ComponentDescriptor; 
    static const O64_OptionDescriptor
        OptionDescriptors[LWOPT_slp_last - LWOPT_slp_first + 1];

    LWOPT_SLP();
    ~LWOPT_SLP();

private:

    WN*                CurrentWN_;
    WN_CFG*            CurrentWCFG_;
    WHIRL_SSA_MANAGER* CurrentWSSA_;
    WSSA_DU_MANAGER*   Current_DU_;
    ALIAS_MANAGER *    Current_Alias;
    UINT32             _skip_BB_before;
    UINT32             _skip_BB_after;

    MEM_POOL*          mem_pool;
    void Perform_();
};

extern void fdump_tree (FILE*, WN*);

#endif /* lwopt_slp_INCLUDED */
