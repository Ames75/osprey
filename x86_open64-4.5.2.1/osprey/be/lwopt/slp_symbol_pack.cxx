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
// Module: slp_symbol_pack.cxx
//
// Description:
// Symbol_Pack is an abstraction of a pack of scalar operands, which 
// have either an SSA version index (VER_IDX) or are constants. Thus,
// a Symbol_Pack is a pack of VER_IDXs or pointers to WHIRL nodes if
// they are constants. Symbol_Pack's can also contain contiguous 
// memory accesses defined by LDID's or STID's. This is determined by 
// Transform::are_contiguous_LD_STIDs() in slp_transform.cxx. Thus,
// all LDID's and STID's are consistently treated as operands in 
// Symbol_pack.
// ====================================================================

#include "slp.h"

using namespace slp;




// --------------------------------------------------------------------
// builder routines
// --------------------------------------------------------------------

Symbol_Pack::Symbol_Pack() : def(NULL), cvted_cond(NULL), 
			     conditional(false), modified(false), 
			     ty_id(MTYPE_UNKNOWN), contiguous_LD_ST(OPERATOR_UNKNOWN)
{
}



Symbol_Pack::Symbol_Pack(int size) : def(NULL), cvted_cond(NULL), 
				     conditional(false), modified(false), 
				     sym_pack(size), constant_pack(size), 
				     ty_id(MTYPE_UNKNOWN),
				     contiguous_LD_ST(OPERATOR_UNKNOWN)
{
}



Symbol_Pack::~Symbol_Pack()
{
}




// This operator defines an order among packs, which is used in 
// an ordered set, 'sym_packs' of the 'Transform' class. 
// By using 'STL set', 'find'ing a pack in 'sym_packs' is fast,
// in Transform::transform_to_SIMD_operand().
bool Symbol_Pack::operator<(const Symbol_Pack& spack) const
{
  // constant packs are smaller than VER_IDX packs
  if (are_constants() && !spack.are_constants()) return true;
  if (!are_constants() && spack.are_constants()) return false;
  if (are_constants()) return is_constant_smaller(spack);

  int size1 = size();
  int size2 = spack.size();
  int smaller = size1 < size2 ? size1 : size2;

  for (int i=0; i<smaller; i++){
    if (i_th(i) < spack.i_th(i))
      return true;
    if (i_th(i) > spack.i_th(i))
      return false;
  }

  return size1 < size2;
}




bool Symbol_Pack::is_constant_smaller(const Symbol_Pack& spack) const
{
  int size1 = size();
  int size2 = spack.size();
  int smaller = size1 < size2 ? size1 : size2;

  for (int i=0; i<smaller; i++){
    if (WN_is_constant_smaller(i_th_constant(i), spack.i_th_constant(i)))
      return true;
    if (WN_is_constant_smaller(spack.i_th_constant(i), i_th_constant(i)))
      return false;
  }

  return size1 < size2;
}




bool Symbol_Pack::operator==(const Symbol_Pack& spack) const
{
  if (are_constants()) return is_constant_equal(spack);

  int size1 = size();
  int size2 = spack.size();
  if (size1 != size2) return false;

  for (int i=0; i<size1; i++)
    if (i_th(i) != spack.i_th(i))
      return false;

  return true;
}




bool Symbol_Pack::is_constant_equal(const Symbol_Pack& spack) const
{
  int size1 = size();
  int size2 = spack.size();
  if (size1 != size2) return false;

  for (int i=0; i<size1; i++)
    if (!WN_is_constant_equal(i_th_constant(i), spack.i_th_constant(i)))
      return false;

  return true;
}




int Symbol_Pack::get_lane_number(VER_IDX vidx) const
{
  for (int i=0; i<sym_pack.size(); i++)
    if (sym_pack[i] == vidx)
      return i;

  Is_True(0, ("Symbol_Pack::get_lane_number: vidx not found."));
  return 0;
}




int Symbol_Pack::type_size() const
{
  Is_True(ty_id!=MTYPE_UNKNOWN, ("Symbol_Pack::type_size: using uninitialized type ID"));
  return MTYPE_byte_size(ty_id);
}




void Symbol_Pack::set_i_th (int i, VER_IDX vidx, WHIRL_SSA_MANAGER* wssa) 
{ 
  Is_True(sym_pack.size()==i, ("Symbol_Pack::set_i_th: unexpected pack size(%d) vs. i(%d)", sym_pack.size(), i));
  sym_pack.push_back(vidx);

  if (i == 0){
    ty_id = get_scalar_type_from_VER_IDX(vidx, wssa);
  }
  else{
    TYPE_ID added_ele_type = get_scalar_type_from_VER_IDX(vidx, wssa);
    // because of a strange STID type in WHIRL, I will comment this for now.
//     Is_True(ty_id==added_ele_type, ("Symbol_Pack::set_i_th: different type is added to the symbol pack: expected(%d) vs. added(%d)", ty_id, added_ele_type));
  }
}




void Symbol_Pack::set_i_th_constant (int i, WN* wn) 
{ 
  Is_True(constant_pack.size()==i, ("Symbol_Pack::set_i_th_constant: unexpected constant pack size(%d) vs. i(%d)", constant_pack.size(), i));
  constant_pack.push_back(wn);

  if (i == 0)
    ty_id = WN_rtype(wn);
  else
    Is_True(ty_id==WN_rtype(wn), ("Symbol_Pack::set_i_th_constant: different type is added to the symbol pack: expected(%d) vs. added(%d)", ty_id, WN_rtype(wn)));
}





void Symbol_Pack::set_contiguous_LD_STIDs(OPERATOR opr)
{ 
  contiguous_LD_ST = opr;
}





bool Symbol_Pack::are_contiguous_LDIDs() const
{ 
  return contiguous_LD_ST == OPR_LDID;
}





bool Symbol_Pack::are_contiguous_STIDs() const
{ 
  return contiguous_LD_ST == OPR_STID;
}





bool Symbol_Pack::are_constants() const
{ 
  if (constant_pack.size() > 0){
    Is_True(sym_pack.size() == 0, ("Symbol_Pack::are_constants: sym_pack.size() is not zero"));
    return true;
  }
  return false;
}





int Symbol_Pack::size() const
{ 
  if (are_constants()) return constant_pack.size();
  return sym_pack.size();
}





void Symbol_Pack::set_def(WN* wn)
{ 
  Is_True(WN_operator(wn)==OPR_STID, ("Symbol_Pack::set_def: def is not STID"));
  def = wn;
}







// --------------------------------------------------------------------
// debug routines
// --------------------------------------------------------------------
void Symbol_Pack::print()
{
  fprintf(TFile, "( ");
  std::vector<VER_IDX>::iterator sit = sym_pack.begin();
  for (bool first=true; sit != sym_pack.end(); sit++, first = false){
    if (!first) fprintf(TFile, ", ");
    fprintf(TFile, "%d", *sit);
  }
  fprintf(TFile, " )");
}


void Symbol_Pack::print_long(WHIRL_SSA_MANAGER* wssa, Transform* tr)
{
  fprintf(TFile, "[ ");
  OPERATOR op = def?WN_operator(def):OPERATOR_UNKNOWN;
  fprintf(TFile, "def(%p, %d), modified(%s): ", def, op, modified?"true":"false");
  std::vector<VER_IDX>::iterator sit = sym_pack.begin();
  for (bool first=true; sit != sym_pack.end(); sit++, first = false){
    if (!first) fprintf(TFile, ", ");
    VER_IDX vidx = *sit;
    print_VER_IDX(vidx, wssa);
  }
  fprintf(TFile, " ]");
}




