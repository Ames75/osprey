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
// Module: slp_dependence.h
//
// Description:
//
// ====================================================================


#ifndef lwopt_slp_dependence_INCLUDED
#define lwopt_slp_dependence_INCLUDED


namespace slp {

  typedef std::vector<bool> Dependence_Vector;

  class Dependence_Matrix
    {
    public:
      Dependence_Matrix(int, std::vector<Statement*>&, 
			WHIRL_SSA_MANAGER*, Distance_Analysis&, 
			ALIAS_MANAGER*, TRACE_OPTION_KIND);
      ~Dependence_Matrix();

      void print();
      void print_defs_uses();
      void print_statement_defs(int);
      void print_statement_uses(int);
      void print_dependence_matrix();
      void print_dependence_vector(int);
      void print_wst_set(std::set<WST_IDX>&);

      // true if there a dependence between i and j
      bool is_dependent(int, int);
      bool is_dependent_set(std::set<WST_IDX>&,Statement_ID, Statement_ID, 
			    SLP_DEPENDENCE);
      

    private:

      void collect_defs_uses();
      void WN_collect_uses (Statement_ID, WN*);
      void Phi_collect_defs_uses(Statement_ID, WN*);
      void Chi_collect_defs_uses(Statement_ID, WN*);
      void Mu_collect_defs_uses (Statement_ID, WN*);

      bool find_dependence(int, int);
      bool output_dependence(int, int);
      bool true_dependence(int, int);
      bool anti_dependence(int, int);
      bool are_aliased(std::vector<WN*>&, std::vector<WN*>&);

      std::vector<Statement*>&        stmts;
      WHIRL_SSA_MANAGER*              wssa;
      Distance_Analysis&              dists;
      ALIAS_MANAGER*                  slp_alias;
      TRACE_OPTION_KIND               _TraceKind;

      // dependence matrix
      std::vector<Dependence_Vector>  dep_mat;

      // use set for each statement
      std::vector<std::set<WST_IDX> > uses;

      // definition set for each statement
      std::vector<std::set<WST_IDX> > defs;
    };
}

#endif /* lwopt_slp_dependence_INCLUDED */
