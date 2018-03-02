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
// Module: slp_lin_eq.h
//
// Description:
//
// ====================================================================


#ifndef lwopt_slp_LinEq_INCLUDED
#define lwopt_slp_LinEq_INCLUDED


namespace slp {

  class LinEq
    {
    public:
      LinEq(){}; // non-linear
      LinEq(int);
      LinEq(VER_IDX, int);
      ~LinEq(){};

      LinEq operator+(const LinEq&) const;
      LinEq operator-(const LinEq&) const;
      LinEq operator*(const LinEq&) const;
      LinEq operator-() const;

      int constant () const;
      bool is_constant() const;
      void print(WHIRL_SSA_MANAGER *, int);

      // empty map for non-linear equation
      bool is_non_linear() const { return term_map.empty();}

      std::map<VER_IDX, int>::const_iterator begin() const { 
	       return term_map.begin();
      }
      std::map<VER_IDX, int>::const_iterator end() const { 
	       return term_map.end();
      }

      int get_term(VER_IDX vi){ return term_map[vi]; }
      void set_term(VER_IDX vi, int co){ term_map[vi] = co; }
      void erase_term(VER_IDX vi){ term_map.erase(vi); }

    private:
      // linear equations: 
      // each record means a term <sym, coefficient> in the 
      // linear equation.
      // constant is stored with VER_IDX==VER_IDX_ZERO
      std::map<VER_IDX, int> term_map;
    };
}

#endif /* lwopt_slp_LinEq_INCLUDED */
