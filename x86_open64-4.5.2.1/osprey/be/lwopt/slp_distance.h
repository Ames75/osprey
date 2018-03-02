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
// Module: slp_distance.h
//
// Description:
//
// ====================================================================


#ifndef lwopt_slp_distance_INCLUDED
#define lwopt_slp_distance_INCLUDED


namespace slp {

  typedef std::pair<int, int> Distance; // (group, offset)

  class Distance_Analysis
    {
    public:
      Distance_Analysis(
			std::vector<Statement*>&, 
			std::map<VER_IDX, LinEq>&,
			WHIRL_SSA_MANAGER*,
			TRACE_OPTION_KIND);
      ~Distance_Analysis();

      bool is_addr_sym(VER_IDX vidx){ 
	       return lin_eqs.find(vidx) != lin_eqs.end();
      }

      bool are_independent(WN*, WN*);
      bool are_adjacent_mem_refs(Statement_ID, Statement_ID);
      bool are_adjacent_mem_refs(WN*, WN*);

      Distance get_distance(WN*);
      bool are_same_group(Distance, Distance);
      bool are_same_offset(Distance, Distance);

      void print();

      void print_distances();
      void print_distance(WN*, Distance);

      void print_addr_leqs();
      void print_addr_leq(WN*, LinEq);

      void print_lin_eqs();
      void print_lin_eq(VER_IDX, LinEq);

    private:
      // evaluating linear equations
      void eval_linear_equations();
      LinEq eval(WN*);

      void eval_address_nodes();
      void eval_address_nodes(WN*);

      void assign_distance();
      void set_distance(WN*, int);
      bool is_dist_assigned(WN*);

      std::vector<Statement*>&   stmts;

      // linear equations for the symbols used in address computations
      std::map<VER_IDX, LinEq>&  lin_eqs;

      WHIRL_SSA_MANAGER*         wssa;
      TRACE_OPTION_KIND          _TraceKind;

      // temporary map from WN* to lin_eq for address nodes
      std::map<WN*, LinEq>       addr_lin_eqs;

      // distance for each address WHIRL node
      std::map<WN*, Distance>    distances;
    };
}

#endif /* lwopt_slp_distance_INCLUDED */
