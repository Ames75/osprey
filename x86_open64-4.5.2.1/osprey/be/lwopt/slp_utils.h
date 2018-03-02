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
// Module: slp_utils.h
//
// Description:
//
// ====================================================================


#ifndef lwopt_slp_utils_INCLUDED
#define lwopt_slp_utils_INCLUDED


namespace slp {

  enum SLP_DEPENDENCE {
    SLP_DEP_true,
    SLP_DEP_anti,
    SLP_DEP_output
  };

#define TrMax(str) (_TraceKind >= TRACE_maximal ? fprintf (TFile, str):0)
#define WN_is_constant_expr(wn) \
   (WN_operator(wn) == OPR_INTCONST || WN_operator(wn) == OPR_CONST)

  class Transform;

  VER_IDX WN_get_dst_sym(WN*, WHIRL_SSA_MANAGER*);
  void find_sources(std::set<VER_IDX>&, WN*, WHIRL_SSA_MANAGER*);
  void find_symbols(std::set<VER_IDX>&, WN*, WHIRL_SSA_MANAGER*);
  void find_addr_syms(std::set<VER_IDX>&, WN*, WHIRL_SSA_MANAGER*);

  VER_IDX st2ver_idx(ST_IDX);
  ST_IDX ver2st_idx(VER_IDX);
  bool is_st_idx(VER_IDX);
  bool are_all_vsyms(std::set<WST_IDX>&, WHIRL_SSA_MANAGER*);
  bool WN_are_isomorphic_nodes(WN*, WN*);
  bool WN_is_mem_opr(WN*);
  bool WN_is_address_operand(WN*, int);
  bool WN_is_true_statement(WN*);
  bool WN_is_SwitchReturn(WN*);
  bool WN_is_VSwitchReturn(WN*);
  bool WN_is_SwitchBranch(WN*);
  bool WN_is_VSwitchBranch(WN*);
  bool WN_is_FIRST_TRUE_INDEX(WN*);
  bool WN_is_VEC_FIRST_TRUE_INDEX(WN*);
  bool WN_is_Early_Exits(WN*);

  bool WN_is_LDID_from_array(WN*);
  bool WN_is_STID_into_array(WN*);
  bool ST_IDX_has_type(ST_IDX);
  bool WN_is_constant_smaller(WN*, WN*);
  bool WN_is_constant_equal(WN*, WN*);
  bool WN_is_vectorizable_stmt(WN*);
  bool is_vectorizable_op (OPERATOR, TYPE_ID, TYPE_ID);
  bool is_shift_op(OPERATOR);
  bool is_comparison_op(OPERATOR);
  bool WN_is_comparison_intrn(WN*);
  bool WN_has_CMP(WN*);
  bool WN_has_INT_CMP(WN*);
  bool is_vector_type(TYPE_ID);
  bool has_void_desc(OPERATOR);
  TYPE_ID WN_get_CMP_type(WN*);
  void WN_set_CMP_type(WN*, TYPE_ID);

  int WN_count_mem_refs(WN*);
  int WN_count_versions(WN*);
  int WN_count_versions_constants(WN*);

  WN* WN_get_mem_ref(WN*);
  TY_IDX WN_get_mem_type(WN*);

  const WST_Symbol_Entry& 
    get_WST_Symbol_Entry_from_VER_IDX(VER_IDX, WHIRL_SSA_MANAGER*);
  WN_OFFSET get_offset_from_VER_IDX(VER_IDX, WHIRL_SSA_MANAGER*);
  ST* get_ST_from_VER_IDX(VER_IDX, WHIRL_SSA_MANAGER*);
  ST_IDX get_ST_IDX_from_VER_IDX(VER_IDX, WHIRL_SSA_MANAGER*);
  TYPE_ID get_type_from_VER_IDX(VER_IDX, WHIRL_SSA_MANAGER*);
  TYPE_ID get_scalar_type_from_VER_IDX(VER_IDX, WHIRL_SSA_MANAGER*);
  WST_IDX get_wst_idx(WN*, WHIRL_SSA_MANAGER*);
  TYPE_ID get_scalar_type(TYPE_ID);
  TYPE_ID get_vector_type(TYPE_ID);
  TYPE_ID WN_get_vector_type(WN*);
  TYPE_ID get_vector_comparison_type(TYPE_ID);
  int WN_non_address_kid(WN*);
  bool is_scalar_type(TYPE_ID);
  TYPE_ID get_mask_type(TYPE_ID);

  INTRINSIC get_PACK_intrinsic(TYPE_ID);
  INTRINSIC get_UNPACK_intrinsic(TYPE_ID);

  WN* get_def_wn(VER_IDX, WHIRL_SSA_MANAGER*);
  WN* make_LDID(const WN*, WHIRL_SSA_MANAGER*);
  UINT32 make_mask(int);
  char* get_dep_str(SLP_DEPENDENCE);
  char* get_type_name(ST_IDX);
  char* get_PU_name();

  void print_ST_IDX(ST_IDX);
/*   void print_VER_IDX(VER_IDX, WHIRL_SSA_MANAGER*, const WN*); */
  void print_VER_IDX(VER_IDX, WHIRL_SSA_MANAGER*);
  void print_wst(VER_IDX, WHIRL_SSA_MANAGER*);
  void print_wst_short(WST_IDX, WHIRL_SSA_MANAGER*, char*);
  void print_st(ST_IDX);
  void print_PU_name(char*);

  void slp_trace_title(TRACE_OPTION_KIND, char*);
  void slp_dump_tree(TRACE_OPTION_KIND, char*, WN*);
}

#endif /* lwopt_slp_utils_INCLUDED */
