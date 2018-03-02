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
// Module: slp_switch_br_ret.cxx
//
// Description:
// SwitchBrRet refers to two scalar Early Exits constructs, one for
// Switch Return and the other for Switch Branch. The comments above 
// two functions, LWOPT_LOWER::lower_Switch_Return() and
// LWOPT_LOWER::lower_Switch_Branch() defined in early_exits_lower.cxx
// provide the syntax and semantics of the two in detail. SwitchBrRet
// defined in this file abstracts operations on the two constructs.
// ====================================================================

#include "slp.h"

using namespace slp;




// --------------------------------------------------------------------
// builder routines
// --------------------------------------------------------------------

SwitchBrRet::SwitchBrRet(Statement* s, int reg_width,
			 WHIRL_SSA_MANAGER* wssa,
			 std::set<Symbol_Pack*, lt_sym_pack>& spacks,
			 TRACE_OPTION_KIND tr) : 
  _stmt(s), _SIMD_register_width(reg_width), _wssa(wssa), 
  sym_packs(spacks), _TraceKind(tr)
{
  _wn            = _stmt->whirl_node();
  _typesize      = _stmt->typesize();
  _vector_length = _SIMD_register_width / _typesize;
  _num_vectorized_srcs = 0;
  if (WN_is_SwitchBranch(_wn)) {
    _num_srcs    = WN_kid_count(WN_kid0(_wn));
    _intrn       = INTRN_SWITCH_BRANCH;
  }
  else {
    _num_srcs    = WN_kid_count(_wn);
    _intrn       = INTRN_SWITCH_RETURN;
    Is_True(_num_srcs%2==0, ("SwitchBrRet: odd _num_srcs"));
  }
}




SwitchBrRet::~SwitchBrRet()
{
}




void SwitchBrRet::pack_operands()
{
  int num_ele = is_switch_br() ? _num_srcs : _num_srcs/2;
  if (_TraceKind >= TRACE_maximal)
    fprintf(TFile, "SwitchBrRet::pack_operands: is_switch_br(%d), num_ele(%d)\n", is_switch_br(), num_ele);

  for (int i=0; i<num_ele; i+=_vector_length){
    int togo  = num_ele-i;
    int count = togo<_vector_length ? togo : _vector_length;
    Symbol_Pack cond_syms;
    Symbol_Pack ret_syms ;
    // break temporarily until 'early_exits' generates VER_IDXs
    // assert when permanent
    if (!pack_a_vector(cond_syms, ret_syms, i, count)) break;

    std::set<Symbol_Pack*, lt_sym_pack>::iterator cond_iter;
    cond_iter = sym_packs.find(&cond_syms);
    if (cond_iter == sym_packs.end()) {
      if (_TraceKind >= TRACE_maximal) {
	fprintf(TFile, "SwitchBrRet::pack_operands: cond_syms not found:");
	cond_syms.print();fprintf(TFile, "\n");
      }
      break;
    }

    _cond_vsyms.push_back((*cond_iter)->definition());
    if (is_switch_br()) {
      _num_lanes.push_back(count);
      _num_vectorized_srcs = i+count;
      continue;
    }

    std::set<Symbol_Pack*, lt_sym_pack>::iterator ret_iter;
    ret_iter  = sym_packs.find(&ret_syms);
    if (ret_iter == sym_packs.end()) break;
    _ret_vsyms.push_back((*ret_iter)->definition());
    // for SwitchReturn, we must use the numer of return values
    _num_lanes.push_back(count);
    _num_vectorized_srcs = (i+count)*2;
  }
}






// fill in the two Symbol_Pack's with VER_IDX's
// true if all VER_IDX's are packed
bool SwitchBrRet::pack_a_vector(Symbol_Pack& cond_syms,
			       Symbol_Pack& ret_syms, int from, int count)
{
  for (int i=from; i<from+count; i++){
    WN* cond_wn=NULL, *ret_wn=NULL;
    if (is_switch_ret()){
      cond_wn = WN_kid0(WN_kid(_wn, i*2));
      ret_wn  = WN_kid0(WN_kid(_wn, i*2+1));
	   }
    else
      cond_wn = WN_kid0(WN_kid(WN_kid0(_wn), i));

    // temporarily until before versions are found as arguments
    if (!WN_use_ver(cond_wn)) {
      if (_TraceKind >= TRACE_maximal) {
	fprintf(TFile, "SwitchBrRet::pack_a_vector: no ver for cond_wn\n");
	dump_tree_ssa(cond_wn);
	fprintf(TFile, "SwitchBrRet::pack_a_vector: ------------------\n");
      }
      return false;
    }
    if (is_switch_ret() && !WN_use_ver(ret_wn)) {
      if (_TraceKind >= TRACE_maximal) 
	fprintf(TFile, "SwitchBrRet::pack_a_vector: no ver for ret_wn\n");
      return false;
    }

    Is_True(WN_use_ver(cond_wn), 
	    ("SwitchBrRet::pack_symbols: false WN_use_ver: cond(%d)", WN_use_ver(cond_wn)));
    Is_True(!is_switch_ret() || WN_use_ver(ret_wn), 
	    ("SwitchBrRet::pack_symbols: false WN_use_ver: ret(%d)", WN_use_ver(ret_wn)));

    cond_syms.set_i_th(i-from, _wssa->Get_wn_ver(cond_wn), _wssa);
    if (is_switch_ret())
      ret_syms.set_i_th (i-from, _wssa->Get_wn_ver(ret_wn), _wssa);
  }
  return true;
}






int SwitchBrRet::num_vectors()
{
  if (is_switch_ret()) return _ret_vsyms.size();
  return _cond_vsyms.size();
}





WN* SwitchBrRet::ith_cond_vsym(int i)
{ 
  Is_True(i<num_vectors(), 
	  ("SwitchBrRet::ith_cond_vsyms: index out of bound"));
  return _cond_vsyms[i];
}




WN* SwitchBrRet::ith_ret_vsym(int i)
{ 
  Is_True(i<num_vectors(), 
	  ("SwitchBrRet::ith_ret_vsyms: index out of bound"));
  return _ret_vsyms[i];
}





int SwitchBrRet::ith_num_lanes(int i)
{ 
  Is_True(i<num_vectors(), 
	  ("SwitchBrRet::ith_num_lanes: index out of bound"));
  return _num_lanes[i];
}





bool SwitchBrRet::is_none_vectorized()
{ 
  return _num_vectorized_srcs == 0;
}






bool SwitchBrRet::is_fully_vectorized()
{ 
  return _num_vectorized_srcs == _num_srcs;
}




// --------------------------------------------------------------------
// debug routines
// --------------------------------------------------------------------
void SwitchBrRet::print()
{
  fprintf(TFile, "SwitchBrRet ");
}





