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
// Module: slp_statement.h
//
// Description:
//
// ====================================================================


#ifndef lwopt_slp_statement_INCLUDED
#define lwopt_slp_statement_INCLUDED


namespace slp {

  typedef int Statement_ID;

  class Statement
    {
    public:
      Statement(Statement_ID, WN*, WHIRL_SSA_MANAGER*);
      ~Statement();

      void map_dst_srcs(std::map<VER_IDX, std::set<VER_IDX> >&);

      bool has_addr_syms(){ return addrs.size()>0;}
      void collect_address_syms(
				std::map<VER_IDX, LinEq>&,
				std::map<VER_IDX, std::set<VER_IDX> >&);
      void collect_address_syms_onesym(
				std::map<VER_IDX, LinEq>&,
				std::map<VER_IDX, std::set<VER_IDX> >&,
				VER_IDX);
      void collect_loads_stores(WN*);
      void set_stmt_typesize(int size){
	// do not vectorize 64-bit data 
	// until 64 bit PACK (finsr128v64) is supported.
	if (size == 8) size = 0;
	_stmt_typesize=size;
      }

      void print(WHIRL_SSA_MANAGER*);

      VER_IDX def       (){ return dst;}
      WN* whirl_node    (){ return wn; }
      Statement_ID id   (){ return _id; }

      bool has_def      (){ return dst != VER_INVALID;}
      int num_loads     (){ return _num_loads;}
      int num_stores    (){ return _num_stores;}
      int typesize      (){ return _stmt_typesize;}
      WN* ith_load (int i){ return loads[i];}
      WN* ith_store(int i){ return stores[i];}
      bool has_side_effects();
      
      std::vector<WN*> loads; 
      std::vector<WN*> stores;

      bool is_simd_op       (){ return simd_op;}
      bool is_packed_lower  (){ return packed_lower;}
      bool is_packed_higher (){ return packed_higher;}
      bool are_isomorphic(Statement*);
      void set_packed_lower (){ packed_lower  = true;}
      void set_packed_higher(){ packed_higher = true;}

    private:
      Statement_ID _id;
      int _num_loads;           // number of memory loads
      int _num_stores;          // number of memory stores
      int _stmt_typesize;       // typesize of the statement in #bytes

      bool packed_lower;        // packed at the 'lower' address
      bool packed_higher;       // packed at the 'higher' address

      WN* wn;
      VER_IDX dst;              // destination operand
      std::set<VER_IDX> srcs;   // source operands
      std::set<VER_IDX> addrs;  // address variables

      bool simd_op;             // is the op code simd_op?
      OPERATOR op;
    };
}

#endif /* lwopt_slp_statement_INCLUDED */
