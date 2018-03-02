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
//
// Module: lwopt_main.h
//
// Description:
//
// ====================================================================


#ifndef lwopt_main_INCLUDED
#define lwopt_main_INCLUDED

#include "comp_decl.h"

class LWOPT_Component : public O64_Component
{
public:
    enum OPTION
    {
        LWOPT_comp_first = OPT_component_first,
        LWOPT_comp_last = LWOPT_comp_first
    };

    static const O64_ComponentDescriptor ComponentDescriptor; 
    static const O64_OptionDescriptor
        OptionDescriptors[LWOPT_comp_last - LWOPT_comp_first + 1];

    LWOPT_Component();
    ~LWOPT_Component();

private:
    void Perform_();
};

#endif /* lwopt_main_INCLUDED */

