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
// Module: slp_main.h
//
// Description:
//
// ====================================================================


#ifndef lwopt_slp_main_INCLUDED
#define lwopt_slp_main_INCLUDED





namespace slp {

  class SLP_Main
    {
    public:
      SLP_Main(WHIRL_SSA_MANAGER*, 
	       WN_CFG*,
	       WSSA_DU_MANAGER*,
	       ALIAS_MANAGER*,
	       WN_CFG::BB_NODE*, 
	       MEM_POOL*,
	       WSSA_UPDATER&,
	       TRACE_OPTION_KIND);
      ~SLP_Main();

      bool perform();

      void print_addr_syms();
      void print_dstsrc_map();
      void print_stmt_packs();
      void print_collected_info();
      int  get_stmt_typesize(WN*);

    private:
      void collect_info();
      void pack_statements(Dependence_Matrix&, Distance_Analysis&);
      bool has_early_exit(){ return _early_exit;}

      void pack_adjacent_mem_refs(Dependence_Matrix&, Distance_Analysis&);
      void pack_statements_UD(WN*, WN*, Dependence_Matrix&);
      void pack_statements_DU(WN*, WN*, Dependence_Matrix&);
      void follow_UD(WN*, WN*, Dependence_Matrix&);
      void follow_DU(WN*, WN*, Dependence_Matrix&);

      bool good_to_pack(Statement_ID, Statement_ID);
      bool outside_BB(WN*);
      bool are_packed(WN*, WN*);
      void add_to_pack_set(Statement_ID, Statement_ID);

      void pack_UD_chains(Dependence_Matrix&);
      void pack_DU_chains(Dependence_Matrix&);
      void merge_packs();
      void chop_packs();
      void chop_a_pack(Statement_Pack*, int);
    
      bool                       _early_exit;
      WHIRL_SSA_MANAGER*         wssa;
      WN_CFG*                    wcfg;
      WSSA_DU_MANAGER*           slp_du_mgr;
      ALIAS_MANAGER*             slp_alias;
      WN_CFG::BB_NODE*           bb;
      UINT32                     bb_ID;
      MEM_POOL*                  slp_mem_pool;
      WSSA_UPDATER&              wssa_updater;
      TRACE_OPTION_KIND          _TraceKind;
      int                        SIMD_register_width;

      std::vector<Statement*> stmts;
      std::map<WN*, Statement_ID> stmt_ID;

      // map from dst to srcs
      std::map<VER_IDX, std::set<VER_IDX> > ds_map; 

      // linear equations for the symbols used in address computations
      std::map<VER_IDX, LinEq> lin_eqs;

      // (stmt1, stmt2) have an entry if stmt2 is packed in the 
      // right side of stmt1
      std::map<Statement_ID, Statement_ID> stmt_packed_right;
      // packs of statements
      std::list<Statement_Pack*> stmt_packs;

      // To find correct statement type size defeating type promotion
      std::map<VER_IDX, int> ver_typesize;
    };

}
#endif /* lwopt_slp_main_INCLUDED */
