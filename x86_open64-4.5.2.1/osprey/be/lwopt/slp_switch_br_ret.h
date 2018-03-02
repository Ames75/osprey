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
// Module: slp_switch_br_ret.h
//
// Description:
//
// ====================================================================


#ifndef lwopt_slp_switch_br_ret_INCLUDED
#define lwopt_slp_switch_br_ret_INCLUDED





namespace slp {

  class Transform;

  class SwitchBrRet
    {
    public:
      SwitchBrRet(Statement*, int, WHIRL_SSA_MANAGER*,
		  std::set<Symbol_Pack*, lt_sym_pack>&, TRACE_OPTION_KIND);
      ~SwitchBrRet();

      int  num_srcs(){ return _num_srcs;}
      bool is_switch_ret(){ return _intrn == INTRN_SWITCH_RETURN;}
      bool is_switch_br() { return _intrn == INTRN_SWITCH_BRANCH;}
      bool pack_a_vector(Symbol_Pack&, Symbol_Pack&, int, int);
      void pack_operands();
      int  num_vectors();
      int  num_vec_srcs(){ return _num_vectorized_srcs;};

      WN* ith_cond_vsym(int);
      WN* ith_ret_vsym(int);
      WN* wn(){ return _wn;}
      int ith_num_lanes(int);

      bool is_none_vectorized();
      bool is_fully_vectorized();

      void print();

    private:
      Statement* _stmt;
      int        _SIMD_register_width;
      WN*        _wn;
      int        _typesize;
      int        _vector_length;
      int        _num_srcs;
      int        _num_vectorized_srcs;
      INTRINSIC  _intrn;
      WHIRL_SSA_MANAGER* _wssa;

      // set of packs of scalar symbols
      std::set<Symbol_Pack*, lt_sym_pack>& sym_packs;

      // vector WNs for packs of conditionals
      std::vector<WN*> _cond_vsyms;
      // vector WNs for packs of return values
      std::vector<WN*> _ret_vsyms;
       // vector sizes for partially useful lanes
      std::vector<int> _num_lanes;
      TRACE_OPTION_KIND _TraceKind;
   };
}
#endif /* lwopt_slp_switch_br_ret_INCLUDED */
