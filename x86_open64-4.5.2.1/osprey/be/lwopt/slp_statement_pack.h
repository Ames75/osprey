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
// Module: slp_statement_pack.h
//
// Description:
//
// ====================================================================


#ifndef lwopt_slp_statement_pack_INCLUDED
#define lwopt_slp_statement_pack_INCLUDED


namespace slp {

  class Statement_Pack
    {
    public:
      Statement_Pack(Statement_ID, Statement_ID);
      Statement_Pack(std::vector<Statement_ID>&);
      ~Statement_Pack();

      void merge(Statement_Pack*);
      void resize(int);
      int num_common_stmts(Statement_Pack*);

      int size() const { return stmt_pack.size();}
      Statement_ID first() const { return stmt_pack[0];}
      Statement_ID last () const { return stmt_pack[size()-1];}
      Statement_ID i_th (int i) const { return stmt_pack[i];}
      void print();

      bool operator<(const Statement_Pack&) const;

    private:

      // a pack of scalar statements
      std::vector<Statement_ID> stmt_pack;
    };
}

#endif /* lwopt_slp_statement_pack_INCLUDED */
