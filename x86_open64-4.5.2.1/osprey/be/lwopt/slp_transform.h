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
// Module: slp_transform.h
//
// Description:
//
// ====================================================================


#ifndef lwopt_slp_transform_INCLUDED
#define lwopt_slp_transform_INCLUDED





namespace slp {


  class Transform
    {
    public:
      Transform(WN_CFG*, 
		WN_CFG::BB_NODE*,
		WHIRL_SSA_MANAGER*,
		WSSA_DU_MANAGER*,
		std::vector<Statement*>&, 
		Scheduler&,
		MEM_POOL*,
		WSSA_UPDATER&,
		int,
		TRACE_OPTION_KIND,
		bool);
      ~Transform();

      void transform();
      void gen_scalar_statement(Statement_ID);
      void gen_SIMD_statement(Statement_Pack*);
      void transform_to_SIMD(WN*, std::vector<Symbol_Pack>&, Statement_Pack*);
      void transform_to_SIMD_STID(WN*, Symbol_Pack&);
      void transform_to_SIMD_ISTORE(WN*, Statement_Pack*, TYPE_ID);
      void transform_to_SIMD_operand(WN*, int, WN*, std::vector<Symbol_Pack>&, 
				     int&);
      void transform_to_SIMD_operator(WN*);
      void pack_operands(std::vector<Symbol_Pack>&, Statement_Pack*);
      void pack_operands_stmt(std::vector<Symbol_Pack>&, int, WN*, int&);
      void gen_PACK_statements(std::vector<Symbol_Pack>&);
      void gen_a_PACK_statement(Symbol_Pack&);
      WN*  gen_a_PACK_intrinsic(Symbol_Pack&, TYPE_ID, TYPE_ID, PREG_NUM, int, 
				VER_IDX);
      void gen_an_UNPACK_intrinsic(VER_IDX, WN* use_block=NULL, WN* use=NULL);
      void gen_an_UNPACK_intrinsic(VER_IDX, WN*, int, WN* use_block=NULL, 
				   WN* use=NULL);
      WN* gen_an_intrinsic(INTRINSIC, WN_OFFSET, ST*, WN**, int, TY_IDX[], 
			   WN* use_block=NULL, WN* use=NULL);
      WN* gen_an_UNPACK_8byte_scalar(ST*, WN_OFFSET, WN*, TYPE_ID, int, WN*, WN*);
      void gen_cvted_cond(Symbol_Pack*);
      void unpack_to_memory(WN*, int, TYPE_ID);

      void trash_the_rest(Statement_Pack*);
      void empty_trash_bin();
      void unpack_live_variables();
      void unpack_packed_srcs(WN*);
      void WN_insert(WN*, WN* use_block=NULL, WN* use=NULL);
      void set_map_id(WN*);

      WN*  get_WN(VER_IDX);
      bool is_live_on_exit(VER_IDX, WN*&, WN*&);
      bool is_full_pack(Statement_Pack*);
      OPERATOR are_contiguous_LD_STIDs(Symbol_Pack&);

      void print_stmt_sym_pack(Statement_Pack*, std::vector<Symbol_Pack>&);
      void print_current_sym_packs();

      // only-in-packed-form
      bool is_only_in_packed_form(VER_IDX);
      void set_only_in_packed_form(VER_IDX, Symbol_Pack*);
      void set_only_in_packed_form(Symbol_Pack*);
      void set_also_in_scalar_form(VER_IDX);
      Symbol_Pack* get_Symbol_Pack(VER_IDX);

      // early-exits
      bool is_SwitchBrRet(Statement_ID);
      void vectorize_SwitchBrRet(Statement_ID);
      void insert_VSwitchReturn(WN*, WN*, int);
      void insert_VSwitchBranch(WN*, WN*, int, int);
      void adjust_SwitchBr(int, WN*);
      void adjust_SwitchRet(int, WN*);
      WN* find_first_SwitchBrRet();

      // SIMD compare transformation
      WN* get_vec_PREG(WN*);
      WN* gen_PCMPGT(WN*, WN*);
      WN* gen_PCMPEQ(WN*, WN*);
      WN* gen_REPLICATE(TYPE_ID, int);
      WN* gen_NOT(WN*);
      void transform_to_SIMD_compares(WN*, WN*, int);
      void gen_compare_intrinsics(WN*, WN*, int);

    private:
      // set of packs of scalar symbols
      std::set<Symbol_Pack*, lt_sym_pack> sym_packs;

      // A VER_IDX will have an entry in this map if it exists 
      // only in packed vector pseudo registers(VPR) and not in a scalar form.
      // If a VER_IDX needs to be packed in two or more VPRs, it will be 
      // unpacked into a scalar first although VPR-to-VPR code movements might
      // be generated later. I hope the dead code elemination will remove the
      // dead scalar assignments.
      std::map<VER_IDX, Symbol_Pack*> only_in_packed_form;

      // map from a VER_IDX to WN* "from which VER_IDX is obtained". 
      // WN* can be either WN_use_ver or WN_def_ver point. Without keeping
      // it's not possible to obtain the 'offset' information when
      // I create an LDID that references the same offset of a symbol.
      std::map<VER_IDX, WN*> VER_IDX_to_WN;

      // statements to be deleted
      // we don't wanna delete anything until we are done.
      std::list<WN*> trash_bin;

      WN_CFG*                    cfg;
      WN_CFG::BB_NODE*           bb_node;
      WN*                        block;
      WN*                        last_stmt;
      WHIRL_SSA_MANAGER*         wssa;
      WSSA_DU_MANAGER*           slp_du_mgr;

      std::vector<Statement*>&   stmts;
      Scheduler&                 sched;
      MEM_POOL*                  slp_mem_pool;
      WSSA_UPDATER&              wssa_updater;
      int                        SIMD_register_width;
      TRACE_OPTION_KIND          _TraceKind;
      bool                       _early_exit;
    };

}
#endif /* lwopt_slp_transform_INCLUDED */
