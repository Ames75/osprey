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
// Module: slp_lin_eq.cxx
//
// Description:
// This file is a collection of methods to manipulate linear equations
// used in the distance analysis. For example, for a statement a = b + c; 
// where a, b and c are address variables, i.e., variables used in address
// computations, the linear equation for 'a' is defined by adding the
// linear equations for 'b' and 'c'. So, if LinEq(b) = e + f and 
// LinEq(c) = f + g, LinEq(a) becomes 'e + 2f + g'. In place of symbols,
// we use VER_IDX, version index, which is unique for each version of
// symbols. For array symbols, we use their ST_IDX instead of VER_IDX
// by flipping their MSBs (in st2ver_idx() of slp_utils.cxx).
// 
// ====================================================================

#include "slp.h"

using namespace slp;


LinEq::LinEq(VER_IDX vidx, int offset)
{
  term_map[vidx] = 1;
  term_map[VER_IDX_ZERO] = offset;
}



LinEq::LinEq(int offset)
{
  term_map[VER_IDX_ZERO] = offset;
}



int LinEq::constant() const
{ 
  // only linear equations have a constant
  Is_True(!is_non_linear(), ("LinEq::constant: nonlinear eq for WN"));
  std::map<VER_IDX, int>::const_iterator i =term_map.find(VER_IDX_ZERO);
  if (i == term_map.end()) return 0;

  return i->second;
}



bool LinEq::is_constant() const
{ 
  if (is_non_linear())     return false;
  if (term_map.size() > 1) return false;

  return term_map.find(VER_IDX_ZERO) != term_map.end();
}



void LinEq::print(WHIRL_SSA_MANAGER *wssa, int indent)
{
  bool first = true;

  std::map<VER_IDX, int>::iterator i = term_map.begin();
  for(;i != term_map.end(); i++){
    for(int j=0; j<indent; j++) fprintf(TFile, "\t");
    VER_IDX vidx = i->first;
    if (!first) fprintf(TFile, " + ");
    if (vidx == VER_IDX_ZERO) fprintf(TFile, "const(%d)", i->second);
    else {
      fprintf(TFile, "coeff(%d) * ", i->second);
      print_VER_IDX(vidx, wssa);
    }
    first = false;
  }

  if (term_map.empty()) fprintf(TFile, " (nonlinear) ");
  fprintf(TFile, "\n");
}



LinEq LinEq::operator+(const LinEq& leq) const {
  // non-linear if either is non-linear
  if (is_non_linear() || leq.is_non_linear()) return LinEq();

  LinEq res = *this;
  std::map<VER_IDX, int>::const_iterator i = leq.begin();
  for(; i != leq.end(); i++){
    VER_IDX vidx = i->first;
    if (term_map.find(vidx) != term_map.end()){
      int coeff = res.get_term(vidx) + i->second;
      if (coeff == 0 && vidx != VER_IDX_ZERO) res.erase_term(vidx);
      else res.set_term(vidx, coeff);
    }
    else
      res.set_term(vidx, i->second);
  }

  return res;
}



LinEq LinEq::operator-(const LinEq& leq) const {
  // non-linear if either is non-linear
  if (is_non_linear() || leq.is_non_linear()) return LinEq();

  LinEq res = *this;
  std::map<VER_IDX, int>::const_iterator i = leq.begin();
  for(; i != leq.end(); i++){
    VER_IDX vidx = i->first;
    if (term_map.find(vidx) != term_map.end()) {
      // if coeffience becomes zero after this operation,
      // delete the variable entry
      int coeff = res.get_term(vidx) - i->second;
      if (coeff == 0 && vidx != VER_IDX_ZERO) res.erase_term(vidx);
      else res.set_term(vidx, coeff);
    }
    else
      res.set_term(vidx, -i->second);
  }

  return res;
}



LinEq LinEq::operator-() const {
  // non-linear if either is non-linear
  if (is_non_linear()) return LinEq();

  LinEq res = *this;
  std::map<VER_IDX, int>::const_iterator i = term_map.begin();
  for(; i != term_map.end(); i++){
    VER_IDX vidx = i->first;
    res.set_term(vidx, -i->second);
  }

  return res;
}



LinEq LinEq::operator*(const LinEq& leq) const {
  // non-linear if neither is constant
  if (!is_constant() && !leq.is_constant()) return LinEq();

  LinEq res; int con;
  if (is_constant()){
    res = leq;
    con = constant();
  }
  else{
    res = *this;
    con = leq.constant();
  }

  std::map<VER_IDX, int>::const_iterator i = res.begin();
  for(; i != res.end(); i++){
    VER_IDX vidx = i->first;

    res.set_term(vidx, res.get_term(vidx) * con);
  }

  return res;
}

