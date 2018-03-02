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
// Module: slp_symbol_pack.h
//
// Description:
//
// ====================================================================


#ifndef lwopt_slp_symbol_pack_INCLUDED
#define lwopt_slp_symbol_pack_INCLUDED





namespace slp {

  class Transform;

  class Symbol_Pack
    {
    public:
      Symbol_Pack();
      Symbol_Pack(int);
      ~Symbol_Pack();

      void set_i_th (int, VER_IDX, WHIRL_SSA_MANAGER*);
      void set_i_th_constant (int, WN*);
      void set_modified () { modified = true;}

      int     type_size()     const;
      int     size()          const;
      VER_IDX first()         const { return sym_pack[0];}
      VER_IDX last ()         const { return sym_pack[size()-1];}
      VER_IDX i_th (int i)    const { return sym_pack[i];}
      WN*     first_constant()const { return constant_pack[0];}
      WN*     last_constant ()const { return constant_pack[size()-1];}
      WN*     i_th_constant(int i) const { return constant_pack[i];}
      WN*     definition()         const { return def;}
      WN*     get_cvted_cond()     const { return cvted_cond;}
      void    set_cvted_cond(WN* wn){ cvted_cond = wn;};
      void    set_def(WN* wn);
      int     get_lane_number(VER_IDX) const;

      bool    is_modified()          const { return modified;}
      bool    is_conditional()       const { return conditional;}
      bool    are_contiguous_LDIDs() const;
      bool    are_contiguous_STIDs() const;
      bool    are_constants()        const;
      bool    is_cvted_cond_defined()const { return cvted_cond != NULL;}
      void    set_contiguous_LD_STIDs(OPERATOR opr);
      void    set_conditional() { conditional = true;}

      void print();
      void print_long(WHIRL_SSA_MANAGER*, Transform*);

      bool operator<        (const Symbol_Pack&) const;
      bool operator==       (const Symbol_Pack&) const;
      bool is_constant_smaller(const Symbol_Pack&) const;
      bool is_constant_equal(const Symbol_Pack&) const;

    private:
      // vector symbol for this pack
      WN* def;

      // if 'def' is the result of comparison operations, the values
      // are -1's and 0's instead of 1's and 0's. 'cond_cvted' will
      // keep 1's and 0's to keep the scalar semantics
      WN* cvted_cond;

      // true if 'def' is the result of comparison operations
      bool conditional;

      // true if this 'preg' is modified. This happens if the preg is
      // generated when the element variables are defined. Any 
      // subsequent use can still refer to either the scalar variable
      // or the packed pseudo register of vector type. Neither the 
      // element scalar variables nor the vector pseudo registers will
      // be redefined because we are using VER_IDX. Even after any 
      // element scalar variable is modified, the vector pseudo 
      // register can be used to represent the earlier version of the
      // defined element scalar variable. If 'modified' is true, 
      // the element scalar variables must be unpacked at the end of
      // the basic block if they are live on exit of the basic block.
      // 'modified' is false if the pack is generated at the point of
      // use.
      bool modified;  
      
      TYPE_ID ty_id;

      // a pack of scalar variables
      std::vector<VER_IDX> sym_pack;
      // a pack of constants
      std::vector<WN*> constant_pack;

      OPERATOR contiguous_LD_ST;
    };

  struct lt_sym_pack
  {
    bool operator()(const Symbol_Pack* p1, const Symbol_Pack* p2) const
    {
      return *p1<*p2;
    }
  };
}
#endif /* lwopt_slp_symbol_pack_INCLUDED */
