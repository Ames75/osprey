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
// Module: lwopt_main.cxx
//
// Description:
// 
// ====================================================================

#include "lwopt_main.h"
#include "config.h"

void 
LWOPT_PerformOpt()
{
    LWOPT_Component lwopt;
}

const O64_ComponentDescriptor LWOPT_Component::ComponentDescriptor =
{
    O64_COMPONENT_DESC("low whirl global optimization", "LWOPT", OptionDescriptors)
};

const O64_OptionDescriptor LWOPT_Component::OptionDescriptors[] =
{
    O64_OPTION_DESC(LWOPT_comp_last, "end marker", 0, 0, OVK_INVALID, OV_INTERNAL, false, 0, 0, 0)
};


static O64_ComponentInitializer lwopt_init(
    COMPONENT_lwopt, &LWOPT_Component::ComponentDescriptor);

LWOPT_Component::LWOPT_Component()
    :O64_Component(COMPONENT_lwopt)
{
    if (_disable) return;

    Perform_();
}

LWOPT_Component::~LWOPT_Component()
{
}

void 
LWOPT_Component::Perform_()
{
  if (Opt_Level < 2) return;
  
  LWOPT_PerformEarlyExitTransform();
  LWOPT_PerformSLP();
  LWOPT_Lower();
  LWOPT_PerformRPR();
}
