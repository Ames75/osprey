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
// Module: slp_statement_pack.cxx
//
// Description:
// Statement_Pack is an abstraction of a pack of statements. Like other
// objects, it defines several operations on a pack of statements.
// ====================================================================

#include "slp.h"

using namespace slp;




// --------------------------------------------------------------------
// builder routines
// --------------------------------------------------------------------

Statement_Pack::Statement_Pack(Statement_ID s1, Statement_ID s2)
{
  stmt_pack.push_back(s1);
  stmt_pack.push_back(s2);
}



Statement_Pack::Statement_Pack(std::vector<Statement_ID>& spack) :
  stmt_pack(spack)
{
}



Statement_Pack::~Statement_Pack()
{
}




// - appends 'pack' at the end of 'this'
// - If 'this' is a pack of memory accesses, the appended 'pack' will 
//   be mapped to the higher address side of 'this'.
void Statement_Pack::merge(Statement_Pack* pack)
{
  Is_True(num_common_stmts(pack) == 1, ("Statement_Pack::merge: num_common_stmts(pack:%d) > 1", num_common_stmts(pack)));
  for (int i=1; i<pack->size(); i++){
    stmt_pack.push_back(pack->i_th(i));
  }
}



// reduce the size of stmt_pack
void Statement_Pack::resize(int new_size)
{
  Is_True(new_size < size(), ("Statement_Pack::resize: new size is larger than the current one."));
  stmt_pack.resize(new_size);
}




// returns the number of common statement IDs between 'this' and 'pack'
// assumes both 'this' and 'pack' have ordered statement IDs from
// low address to high address.
int Statement_Pack::num_common_stmts(Statement_Pack* pack)
{
  int count = 0;
  for (int i=0; i<size(); i++){
    for (int j=0; j<pack->size(); j++)
      if (stmt_pack[i] == pack->i_th(j)) count++;
  }

  return count;
}





bool Statement_Pack::operator<(const Statement_Pack& spack) const
{
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




// --------------------------------------------------------------------
// debug routines
// --------------------------------------------------------------------
void Statement_Pack::print()
{
  fprintf(TFile, "( ");
  std::vector<Statement_ID>::iterator sit = stmt_pack.begin();
  for (bool first=true; sit != stmt_pack.end(); sit++, first = false){
    if (!first) fprintf(TFile, ", ");
    fprintf(TFile, "%d", *sit);
  }
  fprintf(TFile, " )");
}






