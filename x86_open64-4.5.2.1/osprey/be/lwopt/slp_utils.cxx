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
// Module: slp_utils.cxx
//
// Description:
// This file is a collection of little utility functions that are 
// independent of contexts. Thus, all these functions are stateless.
// Most of these little functions are associated with intuitive names
// so that the implementation details need not be understood. 
// ====================================================================

#include "slp.h"

namespace slp {



// returns the destination symbol of the given WN if one exists.
// NULL otherwise.
VER_IDX WN_get_dst_sym(WN* wn, 
		    WHIRL_SSA_MANAGER* wssa)
{
  if (WN_def_ver(wn)) return wssa->Get_wn_ver(wn);

  return VER_INVALID;
}


// finds and returns all source operands' symbols in 'wn'
void find_sources(std::set<VER_IDX>& srcs, 
		  WN* wn, 
		  WHIRL_SSA_MANAGER* wssa)
{
  const OPERATOR op = WN_operator(wn);
  
  if(op == OPR_STID) find_symbols(srcs, WN_kid0(wn), wssa);
  else find_symbols(srcs, wn, wssa);
}


// finds and returns all symbols in 'wn'
void find_symbols(std::set<VER_IDX>& srcs, 
		  WN* wn, 
		  WHIRL_SSA_MANAGER* wssa)
{
  if (!wn) return;

  if (WN_has_ver(wn)) srcs.insert(wssa->Get_wn_ver(wn));
  else {
    if (WN_operator(wn) == OPR_LDA){
      Is_True(WN_has_sym(wn), 
	             ("slp_utils::find_symbols: no symbol in LDA"));
      srcs.insert(st2ver_idx(WN_st_idx(wn)));
    }
  }

  // for kids ...
  for(INT i=0; i<WN_kid_count(wn); i++) 
    find_symbols(srcs, WN_kid(wn, i), wssa);
}



// finds and returns all symbols used in the address computation of 'wn'
void find_addr_syms(std::set<VER_IDX>& addrs, 
		    WN* wn, 
		    WHIRL_SSA_MANAGER* wssa)
{
  if (WN_is_LDID_from_array(wn)) addrs.insert(wssa->Get_wn_ver(wn));
  if (WN_is_STID_into_array(wn)) addrs.insert(wssa->Get_wn_ver(wn));

  const OPERATOR op = WN_operator(wn);
  switch (op) 
    {
    case OPR_ILOADX: find_symbols(addrs, WN_kid1(wn), wssa);
    case OPR_MLOAD:  
    case OPR_ILOAD:  find_symbols(addrs, WN_kid0(wn), wssa);   break;
    case OPR_STID:   find_addr_syms(addrs, WN_kid0(wn), wssa); break;
    case OPR_ISTOREX:find_symbols(addrs, WN_kid2(wn), wssa);
    case OPR_ISTORE: 
    case OPR_MSTORE: 
      find_addr_syms(addrs, WN_kid0(wn), wssa);
      find_symbols(addrs, WN_kid1(wn), wssa); break;
    default: 
      for(INT i=0; i<WN_kid_count(wn); i++) 
	       find_addr_syms(addrs, WN_kid(wn, i), wssa);
    }
}




// true if 'i'th source is an address operand of 'wn'
bool WN_is_address_operand(WN* wn, int i_th)
{
  const OPERATOR op = WN_operator(wn);
  switch (op) 
    {
    case OPR_ILOADX: if (i_th == 1) return true;
    case OPR_MLOAD:  
    case OPR_ILOAD:  if (i_th == 0) return true; break;
    case OPR_ISTOREX:if (i_th == 2) return true;
    case OPR_ISTORE: 
    case OPR_MSTORE: 
    case OPR_ASHR:
    case OPR_LSHR:
    case OPR_SHL:    if (i_th == 1) return true; break;
    default: ;
    }
  return false;
}



int WN_non_address_kid(WN* wn)
{
  for (int i=0; i<WN_kid_count(wn); i++)
    if (!WN_is_address_operand(wn, i)) return i;

  Is_True(WN_kid_count(wn)>0, ("WN_non_address_kid: no non-address kid"));
  return 0;
}




// true if 'wn' is a statement that should be processed by SLP
bool WN_is_true_statement(WN* wn)
{
  const OPERATOR op = WN_operator(wn);
  switch (op) 
    {
    case OPR_PRAGMA: 
    case OPR_FUNC_ENTRY: return false;
    default:             return true;
    }
  return true;
}



// true if 'wn' is a SwitchReturn statement
bool WN_is_SwitchReturn(WN* wn)
{
  if (WN_operator(wn)  != OPR_INTRINSIC_CALL)  return false;
  if (WN_intrinsic(wn) != INTRN_SWITCH_RETURN) return false;

  return true;
}



// true if 'wn' is a SwitchReturn statement
bool WN_is_VSwitchReturn(WN* wn)
{
  if (WN_operator(wn)  != OPR_INTRINSIC_CALL)  return false;
  if (WN_intrinsic(wn) != INTRN_VSWITCH_RETURN) return false;

  return true;
}



// true if 'wn' is a SwitchBranch statement
// SwitchBranch is changed to OPR_COMPGOTO with FIRST_TRUE_INDEX as 
// the first kid.
bool WN_is_SwitchBranch(WN* wn)
{
  if (WN_operator(wn)  != OPR_COMPGOTO)  return false;
  if (!WN_is_FIRST_TRUE_INDEX(WN_kid0(wn))) return false;

  return true;
}



bool WN_is_VSwitchBranch(WN* wn)
{
  if (WN_operator(wn)  != OPR_COMPGOTO)  return false;
  if (!WN_is_VEC_FIRST_TRUE_INDEX(WN_kid0(wn))) return false;

  return true;
}



// true for any one of the four SwitchBranch or SwitchReturn
bool WN_is_Early_Exits(WN* wn)
{
  return WN_is_SwitchReturn(wn) || WN_is_SwitchBranch(wn) 
    || WN_is_VSwitchReturn(wn) || WN_is_VSwitchBranch(wn) ;
}




// true if 'wn' is a FIRST_TRUE_INDEX statement
bool WN_is_FIRST_TRUE_INDEX(WN* wn)
{
  if (WN_operator(wn)  != OPR_INTRINSIC_OP)  return false;
  if (WN_intrinsic(wn) != INTRN_FIRST_TRUE_INDEX) return false;

  return true;
}



// true if 'wn' is a FIRST_TRUE_INDEX statement
bool WN_is_VEC_FIRST_TRUE_INDEX(WN* wn)
{
  if (WN_operator(wn)  != OPR_INTRINSIC_OP)  return false;
  if (WN_intrinsic(wn) != INTRN_VEC_FIRST_TRUE_INDEX) return false;

  return true;
}




// count and returns the number of memory access instructions
int WN_count_mem_refs(WN* wn)
{
  int count=0;

  const OPERATOR op = WN_operator(wn);
  switch(op)
    {
    case OPR_ILOADX:  
    case OPR_ILOAD:
    case OPR_MLOAD:   
    case OPR_ISTOREX: 
    case OPR_ISTORE: 
    case OPR_MSTORE:  count+= 1; break;
    case OPR_LDID: if (WN_is_LDID_from_array(wn)) count+= 1; break;
    case OPR_STID: if (WN_is_STID_into_array(wn)) count+= 1; break;
    default: ;
    }

  for(INT i=0; i<WN_kid_count(wn); i++)
    count += WN_count_mem_refs(WN_kid(wn, i));

  return count;
}




// finds and returns one address node
// NULL if none is found
WN* WN_get_mem_ref(WN* wn)
{
  const OPERATOR op = WN_operator(wn);
  switch(op)
    {
    case OPR_ILOADX:  
    case OPR_ISTOREX: 
    case OPR_ILOAD:
    case OPR_MLOAD:
    case OPR_ISTORE: 
    case OPR_MSTORE: return wn;
    case OPR_LDID: if (WN_is_LDID_from_array(wn)) return wn;
    case OPR_STID: if (WN_is_STID_into_array(wn)) return wn;
    default: ;
    }

  for(INT i=0; i<WN_kid_count(wn); i++) {
    WN* ret = WN_get_mem_ref(WN_kid(wn, i));
    if (ret) return ret;
  }

  return NULL;
}





TY_IDX WN_get_mem_type(WN* wn)
{
  const OPERATOR op = WN_operator(wn);
  switch(op)
    {
    case OPR_ILOADX:  
    case OPR_ILOAD:
    case OPR_MLOAD: return WN_ty(wn);
    case OPR_ISTOREX: 
    case OPR_ISTORE: 
    case OPR_MSTORE: return WN_object_ty(wn);
    case OPR_LDID: if (WN_is_LDID_from_array(wn)) return WN_ty(wn);
    case OPR_STID: if (WN_is_STID_into_array(wn)) return WN_object_ty(wn);
    default: ;
    }

  Is_True(0, ("slp:WN_get_mem_type: expects a memory access node."));
  return TY_IDX_ZERO;
}




// Array symbols don't have VER_IDX's. 
// We use ST_IDX as VER_IDX by setting the MSB to 1.
VER_IDX st2ver_idx(ST_IDX sidx)
{
  return (VER_IDX)((unsigned)sidx | 0x80000000);
}


ST_IDX ver2st_idx(VER_IDX vidx)
{
  return (ST_IDX)((unsigned)vidx ^ 0x80000000);
}


bool is_st_idx(VER_IDX vidx)
{
  return (unsigned)vidx & 0x80000000;
}


bool WN_is_LDID_from_array(WN* wn)
{
  if (WN_operator(wn) != OPR_LDID) return false;

  ST* st = WN_st(wn);
  TY_IDX ty_idx = ST_type(st);
  return TY_kind(ty_idx) == KIND_ARRAY;
}


bool WN_is_STID_into_array(WN* wn)
{
  if (WN_operator(wn) != OPR_STID) return false;

  ST* st = WN_st(wn);
  TY_IDX ty_idx = ST_type(st);
  return TY_kind(ty_idx) == KIND_ARRAY;
}


bool are_all_vsyms(std::set<WST_IDX>& wst_syms, WHIRL_SSA_MANAGER* wssa)
{
  std::set<WST_IDX>::iterator i = wst_syms.begin();
  for (; i != wst_syms.end(); i++)
    if (wssa->Get_wst_type(*i) != WST_VSYM)
      return false;

  return true;
}




WST_IDX get_wst_idx(WN* wn, WHIRL_SSA_MANAGER* wssa)
{
  Is_True(WN_has_ver(wn), ("slp_utils:get_wst_idx: no version in wn."));
  VER_IDX vidx = wssa->Get_wn_ver(wn);
  return wssa->Get_ver_wst(vidx);
}


bool WN_are_isomorphic_nodes(WN* wn1, WN* wn2)
{
  if (wn1 == NULL && wn2 == NULL) return true;
  if (wn1 == NULL || wn2 == NULL) return false;

  OPERATOR op1 = WN_operator(wn1);
  OPERATOR op2 = WN_operator(wn2);
  if (op1 != op2) return false;

  int num_kids1 = WN_kid_count(wn1);
  int num_kids2 = WN_kid_count(wn2);
  if (num_kids1 != num_kids2) return false;

  // With the following line, uddu_chop_float.c breaks.
//   if (WN_ty(wn1)    != WN_ty(wn2))    return false;
  // With the following line, blocksort.c breaks because of strange U1STID
//   if (WN_desc(wn1)  != WN_desc(wn2))  return false;
  if (WN_rtype(wn1) != WN_rtype(wn2)) return false;

  if (is_shift_op(op1) && 
      WN_const_val(wn1) != WN_const_val(wn2)) return false;

  for(int i=0; i<num_kids1; i++)
    if (!WN_is_address_operand(wn1, i)) // don't check address computations
      if (!WN_are_isomorphic_nodes(WN_kid(wn1, i), WN_kid(wn2, i)))
	return false;

  return true;
}


bool WN_is_vectorizable_stmt(WN* wn)
{
  if (!wn) return true;

  OPERATOR op    = WN_operator(wn);
  TYPE_ID  rtype = WN_rtype(wn);
  TYPE_ID  desc  = WN_desc(wn);
//   if (!is_vectorizable_op(op)) return false;
  if (!is_vectorizable_op(op, rtype, desc)) return false;

  // temporarily disable 'integer multiplications'
  if (MTYPE_is_integral(rtype)) 
    switch (op)
      {
      case OPR_MPY:
      case OPR_DIV:
      case OPR_REM: return false;
      default:;
      }

  for(int i=0; i<WN_kid_count(wn); i++)
    if (!WN_is_address_operand(wn, i)) // don't check address computations
      if (!WN_is_vectorizable_stmt(WN_kid(wn, i)))
	return false;

  return true;
}



// This is copied from simd.cxx and modified to suit the SLP needs. 
// From the original version, the following are modified.
// - 'under_if' and 'Simd_vect_conf.Is_SSE3()' are removed so that they are always true.
// - By default, this returns 'true' unlike the original version.
bool is_vectorizable_op (OPERATOR opr, TYPE_ID rtype, TYPE_ID desc) {

  switch (opr) {
  case OPR_SELECT:
    if (MTYPE_is_float(rtype))
      return TRUE;
    else
      return FALSE;
  case OPR_EQ: case OPR_NE: 
  case OPR_LT: case OPR_GT: case OPR_LE: case OPR_GE:
    if (MTYPE_is_float(desc))
      return FALSE;

    if (MTYPE_is_integral(desc) && MTYPE_byte_size(desc)>4 )
      return FALSE;
    return TRUE;
  case OPR_TRUNC:
    return FALSE;
  case OPR_CVT:
    if ((rtype == MTYPE_F8 || rtype == MTYPE_F4) && 
	(desc == MTYPE_I4 || desc == MTYPE_F4))
      return TRUE;
    else
      return FALSE;
  case OPR_INTRINSIC_OP:
    return TRUE;
  case OPR_PAREN:    
    return TRUE;
  case OPR_ABS:
    if (rtype == MTYPE_F4 || rtype == MTYPE_F8)
      return TRUE;
    else
      return FALSE;
  // BUG 5701: vectorize NEG for integers
  case OPR_NEG:
    if (rtype == MTYPE_C4)//why C4 is not good?
      return FALSE;
    else
      return TRUE;
  case OPR_ADD:
  case OPR_SUB:
    return TRUE;
  case OPR_MPY:
    if (rtype == MTYPE_F8 || rtype == MTYPE_F4)
      return TRUE;
    else if (rtype == MTYPE_I4) {
	    // I2MPY followed by I2STID is actually I4MPY followed by I2STID 
	    // We will distinguish between I4MPY and I2MPY in Is_Well_Formed_Simd
      return TRUE;
    } else if ((rtype == MTYPE_C4 || rtype == MTYPE_C8)) {
      // TODO: explain why requires SSE3
      return TRUE;      
    }

    return FALSE;

  case OPR_DIV:
    if (rtype == MTYPE_F8 || rtype == MTYPE_F4 || 
        (rtype == MTYPE_C4))
      return TRUE;
    else
      return FALSE;

  case OPR_MAX:
  case OPR_MIN:
    if (rtype == MTYPE_F4 || rtype == MTYPE_F8 || rtype == MTYPE_I4)
      return TRUE;
    else
      return FALSE;
  case OPR_BAND:
  case OPR_SHL:
  case OPR_BXOR:
    if (MTYPE_is_integral(rtype))
      return TRUE;
    else
      return FALSE;    
  case OPR_SQRT:
    if (rtype == MTYPE_F4 || rtype == MTYPE_F8)
      return TRUE;
    else
      return FALSE;
  case OPR_RSQRT:
#ifdef TARG_X8664
  case OPR_ATOMIC_RSQRT:
#endif
    if (rtype == MTYPE_F4)
      return TRUE;
    else
      return FALSE;
//BUG 10136: allows F8RECIP to be vectorized here, and V16F8RECIP
//           will be lowered down to DIV after LNO
  case OPR_RECIP:
    if (rtype == MTYPE_F4 || rtype == MTYPE_F8)
      return TRUE;
    else
      return FALSE;

  case OPR_PARM:
    return TRUE;
  default:
    return true;
  }  
}



bool WN_is_mem_opr(WN* wn)
{
  const OPERATOR op = WN_operator(wn);
  switch(op)
    {
    case OPR_ILOADX:  
    case OPR_ILOAD:
    case OPR_MLOAD: 
    case OPR_ISTOREX: 
    case OPR_ISTORE: 
    case OPR_MSTORE:  return true;
    case OPR_LDID:    return WN_is_LDID_from_array(wn);
    case OPR_STID:    return WN_is_STID_into_array(wn);
    default: ;
    }

  return false;
}



bool has_void_desc(OPERATOR opr)
{
  switch(opr)
    {
    case OPR_ABS:
    case OPR_ADD:
    case OPR_CONST:
    case OPR_SUB:
    case OPR_ASM_EXPR:
    case OPR_AGOTO:
    case OPR_ALTENTRY:
    case OPR_ASSERT:
    case OPR_BACKWARD_BARRIER:
    case OPR_BLOCK:
    case OPR_CASEGOTO:
    case OPR_COMMENT:
    case OPR_COMPGOTO:
    case OPR_DO_LOOP:
    case OPR_DO_WHILE:
    case OPR_EVAL:
    case OPR_EXC_SCOPE_BEGIN:
    case OPR_EXC_SCOPE_END:
    case OPR_FALSEBR:
    case OPR_FORWARD_BARRIER:
    case OPR_FUNC_ENTRY:
    case OPR_GOTO:
    case OPR_IDNAME:
    case OPR_IF:
    case OPR_IO:
    case OPR_IO_ITEM:
    case OPR_LABEL:
    case OPR_LOOP_INFO:
    case OPR_MSTORE:
    case OPR_OPT_CHI:
    case OPR_OPT_RESERVE2:
    case OPR_PRAGMA:
    case OPR_PREFETCH:
    case OPR_PREFETCHX:
    case OPR_REGION:
    case OPR_REGION_EXIT:
    case OPR_RETURN:
    case OPR_SWITCH:
    case OPR_TRAP:
    case OPR_TRUEBR:
    case OPR_WHERE:
    case OPR_WHILE_DO:
    case OPR_XGOTO:
    case OPR_XPRAGMA:
    case OPR_AFFIRM:
    case OPR_DEALLOCA:
    case OPR_ASM_STMT:
    case OPR_ASM_INPUT:
    case OPR_GOTO_OUTER_BLOCK:
    case OPR_ARRAY:
    case OPR_ARRSECTION:
    case OPR_LDA:
    case OPR_ILDA:
    case OPR_LDMA:
    case OPR_LDA_LABEL:
    case OPR_ARRAYEXP:
    case OPR_ASHR:
    case OPR_BNOR:
    case OPR_BNOT:
    case OPR_COMPOSE_BITS:
    case OPR_CVTL:
    case OPR_DIVREM:
    case OPR_EXTRACT_BITS:
    case OPR_HIGHMPY:
    case OPR_HIGHPART:
    case OPR_LOWPART:
    case OPR_LSHR:
    case OPR_MOD:
    case OPR_REM:
    case OPR_SHL:
    case OPR_TRIPLET:
    case OPR_XMPY:
    case OPR_BAND:
    case OPR_BIOR:
    case OPR_BXOR:
    case OPR_CAND:
    case OPR_CIOR:
    case OPR_LAND:
    case OPR_LIOR:
    case OPR_COMMA:
    case OPR_RCOMMA:
    case OPR_MPY:
    case OPR_DIV:
    case OPR_NEG:
    case OPR_OPTPARM:
    case OPR_MADD:
    case OPR_MSUB:
    case OPR_NMADD:
    case OPR_NMSUB:
    case OPR_ILOADX:
    case OPR_FIRSTPART:
    case OPR_SECONDPART:
    case OPR_INTCONST:
    case OPR_INTRINSIC_OP:
    case OPR_MAX:
    case OPR_MIN:
    case OPR_MINMAX:
    case OPR_MAXPART:
    case OPR_MINPART:
    case OPR_MLOAD:
    case OPR_RECIP:
    case OPR_RSQRT:
    case OPR_SQRT:
    case OPR_PARM:
    case OPR_RETURN_VAL:
    case OPR_TAS:
      return true;
    default: ;
    }

  return false;
}



bool is_shift_op(OPERATOR op)
{
  switch(op)
    {
    case OPR_ASHR:
    case OPR_LSHR:
    case OPR_SHL: return true; 
    default: ;
    }

  return false;
}


bool is_comparison_op(OPERATOR op)
{
  switch(op)
    {
    case OPR_EQ:
    case OPR_NE:
    case OPR_GT:
    case OPR_GE:
    case OPR_LT:
    case OPR_LE: return true; 
    default: ;
    }

  return false;
}


bool WN_is_comparison_intrn(WN* wn)
{
  if (WN_operator(wn) != OPR_INTRINSIC_OP) return false;
  switch(WN_intrinsic(wn))
    {
    case INTRN_PCMPEQB128:
    case INTRN_PCMPEQW128:
    case INTRN_PCMPEQD128:
    case INTRN_PCMPGTB128:
    case INTRN_PCMPGTW128:
    case INTRN_PCMPGTD128: return true;
    defaults:;
    }
  return false;
}




// true if 'wn' has one or more compare operator
bool WN_has_CMP(WN* wn)
{
  if (!wn) return false;
  if (is_comparison_op(WN_operator(wn))) return true;
  if (WN_is_comparison_intrn(wn)) return true;

  // search the kids
  for (int i=0; i<WN_kid_count(wn); i++)
    if (!WN_is_address_operand(wn, i)) // don't search address operands
      if (WN_has_CMP(WN_kid(wn, i))) return true;

  return false;
}




// true if 'wn' has one or more integer compare operator
bool WN_has_INT_CMP(WN* wn)
{
  if (!wn) return false;

  // search the kids
  for (int i=0; i<WN_kid_count(wn); i++)
    if (!WN_is_address_operand(wn, i)) // don't search address operands
      if (WN_has_INT_CMP(WN_kid(wn, i))) return true;

  if (!is_comparison_op(WN_operator(wn))) return false;
  if (!MTYPE_is_integral(WN_rtype(wn)))   return false;
  
  return true;
}




// finds and returns a desc type of a compare operator
TYPE_ID WN_get_CMP_type(WN* wn)
{
  if (!wn) return MTYPE_UNKNOWN;
  if (is_comparison_op(WN_operator(wn)) || WN_is_comparison_intrn(wn)) 
    return WN_rtype(WN_kid0(wn));

  // search the kids
  for (int i=0; i<WN_kid_count(wn); i++)
    if (!WN_is_address_operand(wn, i)) {// don't search address operands
      TYPE_ID cmp_type = WN_get_CMP_type(WN_kid(wn, i));
      if (cmp_type != MTYPE_UNKNOWN) return cmp_type;
    }
  return MTYPE_UNKNOWN;
}




// set all nodes' desc and rtype with the given type
void WN_set_CMP_type(WN* wn, TYPE_ID cmp_type)
{
  if (!wn) return;
  WN_set_desc(wn, cmp_type);
  WN_set_rtype(wn, cmp_type);

  // search the kids
  for (int i=0; i<WN_kid_count(wn); i++)
    if (!WN_is_address_operand(wn, i)) // don't search address operands
      WN_set_CMP_type(WN_kid(wn, i), cmp_type);
}






// true if vector type
bool is_vector_type(TYPE_ID type)
{
  switch (type)
    {
    case MTYPE_V16I1: 
    case MTYPE_V16I2: 
    case MTYPE_V16I4: 
    case MTYPE_V16I8: 
    case MTYPE_V16F4: 
    case MTYPE_V16F8: return true;
    default: ;
    }
  return false;
}



TYPE_ID get_vector_type(TYPE_ID scalar_type)
{
  if (is_vector_type(scalar_type)) return scalar_type;

  int typesize = MTYPE_byte_size(scalar_type);
  if (MTYPE_is_float(scalar_type)) {
    switch (typesize)
      {
      case 4: return MTYPE_V16F4;
      case 8: return MTYPE_V16F8;
      default: Is_True(0, ("slp::get_vector_type: unexpected float type: %d", scalar_type));
      }
  }

  switch (typesize)
    {
    case 1: return MTYPE_V16I1;
    case 2: return MTYPE_V16I2;
    case 4: return MTYPE_V16I4;
    case 8: return MTYPE_V16I8;
    default: Is_True(0, ("slp::get_vector_type: unexpected int type: %d(size: %d)", scalar_type, typesize));
    }
  return MTYPE_UNKNOWN;
}



// returns the result type for a vector comparison between operands 
// of the given type
TYPE_ID get_vector_comparison_type(TYPE_ID vec_type)
{
  if (!is_vector_type(vec_type))
    vec_type = get_vector_type(vec_type);

  int typesize = MTYPE_byte_size(get_scalar_type(vec_type));
  switch (typesize)
    {
    case 1: return MTYPE_V16I1;
    case 2: return MTYPE_V16I2;
    case 4: return MTYPE_V16I4;
    case 8: return MTYPE_V16I8;
    default: Is_True(0, ("slp::get_vector_comparison_type: unexpected type size: %d", typesize));
    }
  return MTYPE_UNKNOWN;
}







TYPE_ID WN_get_vector_type(WN* wn)
{
  TYPE_ID type = MTYPE_UNKNOWN;
  switch(WN_operator(wn))
    {
    case OPR_ILOAD: type = TY_mtype(WN_object_ty(wn)); break;
    case OPR_LDID: 
      if (WN_is_LDID_from_array(wn)) 
	type = TY_mtype(TY_etype(ST_type(WN_st_idx(wn))));
      else 
	type = TY_mtype(ST_type(WN_st_idx(wn))); // vector type
      break;
    default: 
      type = WN_rtype(WN_kid(wn, WN_non_address_kid(wn)));
    }
  TYPE_ID vector_type = get_vector_type(type);

  return vector_type;
}


// returns a scalar type for the given vector type
TYPE_ID get_scalar_type(TYPE_ID vector_type)
{
  switch (vector_type)
    {
    case MTYPE_V16I1: return MTYPE_I1;
    case MTYPE_V16I2: return MTYPE_I2;
    case MTYPE_V16I4: return MTYPE_I4;
    case MTYPE_V16I8: return MTYPE_I8;
    case MTYPE_V16F4: return MTYPE_F4;
    case MTYPE_V16F8: return MTYPE_F8;
    default: Is_True(0, ("slp::get_scalar_type: unexpected type: %d", vector_type));
    }
  return MTYPE_UNKNOWN;
}


// returns a scalar type for the given vector type
// intended for use as the destination of 'movemask'
TYPE_ID get_mask_type(TYPE_ID vector_type)
{
  switch (vector_type)
    {
    case MTYPE_V16I1: return MTYPE_U1;
    case MTYPE_V16I2: return MTYPE_U2;
    case MTYPE_V16I4: return MTYPE_U4;
    case MTYPE_V16I8: return MTYPE_U8;
    case MTYPE_V16F4: return MTYPE_U4;
    case MTYPE_V16F8: return MTYPE_U8;
    default: Is_True(0, ("slp::get_mask_type: unexpected type: %d", vector_type));
    }
  return MTYPE_UNKNOWN;
}


bool is_scalar_type(TYPE_ID type)
{
  switch (type)
    {
    case MTYPE_V16I1: 
    case MTYPE_V16I2: 
    case MTYPE_V16I4: 
    case MTYPE_V16I8: 
    case MTYPE_V16F4: 
    case MTYPE_V16F8:
    case MTYPE_V: 
    case MTYPE_M: 
    case MTYPE_UNKNOWN: return false;
    default: ;
    }
  return true;
}





ST_IDX get_ST_IDX_from_VER_IDX(VER_IDX vi, WHIRL_SSA_MANAGER* wssa)
{
  WST_IDX wst_idx = wssa->Get_ver_wst(vi);
  return wssa->Get_st_idx(wst_idx);
}





ST* get_ST_from_VER_IDX(VER_IDX vi, WHIRL_SSA_MANAGER* wssa)
{
  WST_IDX wst_idx = wssa->Get_ver_wst(vi);
  return wssa->Get_st(wst_idx);
}





TYPE_ID get_type_from_VER_IDX(VER_IDX vi, WHIRL_SSA_MANAGER* wssa)
{
  ST_IDX st_idx = get_ST_IDX_from_VER_IDX(vi, wssa);
  TY_IDX ty_idx = ST_type(st_idx);
  return TY_mtype(ty_idx);
}




// similar to 'get_type_from_VER_IDX' but returns scalar type for arrays
TYPE_ID get_scalar_type_from_VER_IDX(VER_IDX vi, WHIRL_SSA_MANAGER* wssa)
{
  ST_IDX st_idx = get_ST_IDX_from_VER_IDX(vi, wssa);
  TY_IDX ty_idx = ST_type(st_idx);

  if (TY_kind(ty_idx) == KIND_ARRAY) ty_idx = TY_etype(ty_idx);
  return TY_mtype(ty_idx);
}





const WST_Symbol_Entry& 
get_WST_Symbol_Entry_from_VER_IDX(VER_IDX vi, WHIRL_SSA_MANAGER* wssa)
{
  const WST_Version_Entry& ver_info = wssa->Get_ver(vi);
  WST_IDX widx = ver_info.Get_wst();
  return wssa->Get_wst(widx);
}





WN_OFFSET get_offset_from_VER_IDX(VER_IDX vi, WHIRL_SSA_MANAGER* wssa)
{
  Is_True(!is_st_idx(vi), ("get_offset_from_VER_IDX: vi shouldn't be ST_IDX."));
  const WN* def = get_def_wn(vi, wssa);
  if (WN_operator(def) != OPR_LABEL) return WN_offset(def);

  const WST_Symbol_Entry& wst_sym = 
    get_WST_Symbol_Entry_from_VER_IDX(vi, wssa);

  switch (wst_sym.Sym_type())
    {
    case WST_PREG: return wst_sym.Preg_num();
    case WST_VSYM: return (WN_OFFSET) wst_sym.Vsym_idx();
    case WST_WHIRL:return 0;
    default: ;
    }
  
  return 0;
}





WN* get_def_wn(VER_IDX vidx, WHIRL_SSA_MANAGER* wssa)
{
  if (is_st_idx(vidx)) return NULL;

  const WST_Version_Entry& ver_info = wssa->Get_ver(vidx);
  const WN* def = ver_info.Get_def_wn();
  return const_cast<WN*>(def);
}





WN* make_LDID(const WN* def, WHIRL_SSA_MANAGER* wssa)
{
  Is_True(def!=NULL,("make_LDID: NULL WN"));
  ST* st = WN_st(def);
  TYPE_ID ty_id = WN_desc(def);
  WN_OFFSET offset = WN_offset(def);
  ST_IDX st_idx = WN_st_idx(def);
//   TY_IDX ty_idx = ST_type(st_idx);
  TY_IDX ty_idx = WN_ty(def);
  if (TY_kind(ty_idx) == KIND_ARRAY) ty_idx = TY_etype(ty_idx);
  WN* new_Ldid = WN_Ldid(ty_id, offset, st_idx, ty_idx);

  if (wssa->WN_has_ver(def)){
    VER_IDX vidx = wssa->Get_wn_ver(def);
    WN_MAP_Set_ID(Current_Map_Tab, new_Ldid);
    wssa->Set_wn_ver(new_Ldid, vidx);
  }

  return new_Ldid;
}




// returns a mask with as many 1's as 'valid_lanes'
UINT32 make_mask(int valid_lanes)
{
  Is_True(valid_lanes<=16, ("slp_utils:make_mask: wrong valid_lanes(%u)", valid_lanes));
  UINT32 ret = 0;
  for (int i=0; i<valid_lanes; i++)
    ret = ret | (1<<i);

  return ret;
}





// count and return the defined or used versions
// other than those used in address computation.
int WN_count_versions(WN* wn)
{
  if (!wn) return 0;
  int count = 0;

  if (WN_has_ver(wn)) count++;

  for(INT i=0; i<WN_kid_count(wn); i++)
    if (!WN_is_address_operand(wn, i)) // don't count address symbols
      count += WN_count_versions(WN_kid(wn, i));

  return count;
}





// count and return the defined, used versions and constants
// other than those used in address computation.
int WN_count_versions_constants(WN* wn)
{
  if (!wn) return 0;
  int count = 0;

  if (WN_has_ver(wn) || WN_is_constant_expr(wn)) count++;

  for(INT i=0; i<WN_kid_count(wn); i++)
    if (!WN_is_address_operand(wn, i)) // don't count address symbols
      count += WN_count_versions_constants(WN_kid(wn, i));

  return count;
}





// true if wn1 is smaller than wn2
bool WN_is_constant_smaller(WN* wn1, WN* wn2)
{
  Is_True(WN_is_constant_expr(wn1), ("WN_is_constant_smaller: non-constant WN"));
  Is_True(WN_operator(wn1)==WN_operator(wn2), ("WN_is_constant_smaller: different operators"));

  // integer constants
  if (WN_operator(wn1)==OPR_INTCONST) 
    return WN_const_val(wn1) < WN_const_val(wn2);

  // floating point constants
  Is_True(WN_operator(wn1)==OPR_CONST&&WN_operator(wn2)==OPR_CONST,
	  ("WN_is_constant_smaller: unexpected operators: wn1(%s) vs. wn2(%s)",
	   OPCODE_name(WN_opcode(wn1)), OPCODE_name(WN_opcode(wn2))));

  TCON val1 = ST_tcon_val(WN_st(wn1));
  TCON val2 = ST_tcon_val(WN_st(wn2));

  return Targ_To_Host_Float(val1) < Targ_To_Host_Float(val2);
}





// true if the constant value of wn1 is equal to that of wn2
bool WN_is_constant_equal(WN* wn1, WN* wn2)
{
  Is_True(WN_is_constant_expr(wn1), ("WN_is_constant_equal: non-constant WN"));
  Is_True(WN_operator(wn1)==WN_operator(wn2), ("WN_is_constant_equal: different operators"));

  // integer constants
  if (WN_operator(wn1)==OPR_INTCONST)
    return WN_const_val(wn1) == WN_const_val(wn2);

  // floating point constants
  Is_True(WN_operator(wn1)==OPR_CONST&&WN_operator(wn2)==OPR_CONST,
	  ("WN_is_constant_equal: unexpected operators: wn1(%s) vs. wn2(%s)",
	   OPCODE_name(WN_opcode(wn1)), OPCODE_name(WN_opcode(wn2))));

  TCON val1 = ST_tcon_val(WN_st(wn1));
  TCON val2 = ST_tcon_val(WN_st(wn2));

  return Targ_To_Host_Float(val1) == Targ_To_Host_Float(val2);
}



// returns the corresponding PACK intrinsic for the given scalar 'type'
INTRINSIC get_PACK_intrinsic(TYPE_ID type)
{
  switch(type)
    {
    case MTYPE_B: 
    case MTYPE_I1: 
    case MTYPE_U1: return INTRN_PINSRB;
    case MTYPE_I2: 
    case MTYPE_U2: return INTRN_PINSRW;
    case MTYPE_I4:
    case MTYPE_U4: return INTRN_PINSRD;
    case MTYPE_I8:
    case MTYPE_U8: return INTRN_PINSRQ;
    case MTYPE_F4: return INTRN_INSRPS;
    case MTYPE_F8: return INTRN_INSRPD;
    default: Is_True(0,("slp_utils::get_PACK_intrinsic: unexpected type"));
    }
  return INTRN_INSRPD;
}



// returns the corresponding UNPACK intrinsic for the given scalar 'type'
INTRINSIC get_UNPACK_intrinsic(TYPE_ID type)
{
  switch(type)
    {
    case MTYPE_B: 
    case MTYPE_I1: 
    case MTYPE_U1: return INTRN_PEXTRB;
    case MTYPE_I2: 
    case MTYPE_U2: return INTRN_PEXTRW;
    case MTYPE_I4:
    case MTYPE_U4: return INTRN_PEXTRD;
    case MTYPE_I8:
    case MTYPE_U8: return INTRN_PEXTRQ;
    case MTYPE_F4: return INTRN_EXTRPS;
    case MTYPE_F8: return INTRN_EXTRPD;
    default: Is_True(0,("slp_utils::get_UNPACK_intrinsic: unexpected type"));
    }
  return INTRN_EXTRPD;
}




char* get_dep_str(SLP_DEPENDENCE d)
{
  switch(d)
    {
    case SLP_DEP_true:   return "true";
    case SLP_DEP_anti:   return "anti";
    case SLP_DEP_output: return "output";
    default: Is_True(0, ("get_dep_str: unexpected"));
    }
  return "";
}





// --------------------------------------------------------------------
// display routines
// --------------------------------------------------------------------
void print_wst(VER_IDX vidx, WHIRL_SSA_MANAGER* wssa)
{
  if (vidx == VER_INVALID) {
    fprintf(TFile, "print_wst: invalid vidx\n");
    return;
  }

  if (vidx == VER_IDX_ZERO) {
    fprintf(TFile, "SLP_CONSTANT\n");
    return;
  }

  if (is_st_idx(vidx)){
    print_st(ver2st_idx(vidx)); 
    return;
  }

  WST_IDX widx = wssa->Get_ver_wst(vidx);
  wssa->Print_wst(widx, stdout);
}




bool ST_IDX_has_type(ST_IDX st_idx)
{
  ST_CLASS st_class = ST_class(st_idx);
  switch (st_class)
    {
    case CLASS_VAR:
    case CLASS_CONST:
    case CLASS_PREG:
    case CLASS_NAME: return true;
    default:;
    }
  return false;
}




char* get_type_name(ST_IDX st_idx)
{
  ST_CLASS st_class = ST_class(st_idx);
  switch (st_class)
    {
    case CLASS_VAR:
    case CLASS_CONST:
    case CLASS_PREG:
    case CLASS_NAME:  return TY_name(ST_type(st_idx));
    case CLASS_UNK:   return "UNKNOWN";
    case CLASS_FUNC:  return "FUNC";   
    case CLASS_BLOCK: return "BLOCK";  
    default: ;
    }
  return "UNEXPECTED";
}




void print_ST_IDX(ST_IDX st_idx)
{
  fprintf(TFile, "%s{array, %s}", ST_name(st_idx), get_type_name(st_idx));
}




void print_VER_IDX(VER_IDX vidx, WHIRL_SSA_MANAGER* wssa)
{
  if (is_st_idx(vidx)) {
    print_ST_IDX(ver2st_idx(vidx));
    return;
  }

  ST_IDX  st_idx   = get_ST_IDX_from_VER_IDX(vidx, wssa);
  char*   type_name= get_type_name(st_idx);
  WN_OFFSET offset = get_offset_from_VER_IDX(vidx, wssa);

  fprintf(TFile, "%s(%d, %d, %s)", ST_name(st_idx), offset, vidx, type_name);
}


void print_wst_short(WST_IDX widx, WHIRL_SSA_MANAGER* wssa, char* delimiter)
{
  fprintf(TFile, "%s", wssa->WST_name(widx));
  const WST_Symbol_Entry& wst_sym = wssa->Get_wst(widx);

  switch (wssa->Get_wst_type(widx))
    {
    case WST_PREG:
      fprintf(TFile, "(%d)", wst_sym.Preg_num()); break;
    case WST_VSYM: 
      fprintf(TFile, "(%d)", wst_sym.Vsym_idx()); break;
    default: ;
    }
  fprintf(TFile, "%s", delimiter);
}



void print_st(ST_IDX st_idx)
{
  fprintf(TFile, "SYMBOL(%s)", ST_name(st_idx));
}



void slp_trace_title(TRACE_OPTION_KIND tr_level, char* str)
{
  for (int i=0; i<tr_level-1; i++) fprintf(TFile, "---");
  fprintf(TFile, " %s ", str);
  switch(tr_level)
    {
    case TRACE_info:    fprintf(TFile, "--------");
    case TRACE_minimal: fprintf(TFile, "--------");
    case TRACE_medium:  fprintf(TFile, "--------");
    case TRACE_maximal: fprintf(TFile, "---\n"); break;
    default: Is_True(0, ("slp_trace_title: Unexpected _TraceKind(%d)", tr_level));
    }
}




void print_PU_name(char* str)
{
  char * PU_name = ST_name(&St_Table[PU_Info_proc_sym(Current_PU_Info)]);
  fprintf(TFile, str, PU_name);
}




char* get_PU_name()
{
  return ST_name(&St_Table[PU_Info_proc_sym(Current_PU_Info)]);
}



void slp_dump_tree(TRACE_OPTION_KIND tr_level, char* str, WN* wn)
{
  char buffer[100];
  for (int i=0; i<tr_level-1; i++) sprintf(buffer+i*3, "   ");

  fprintf(TFile, buffer); fprintf(TFile, "++++++++++++++++++++\n");
  fprintf(TFile, buffer); fprintf(TFile, str);

  fprintf(TFile, buffer);
  if (WN_operator(wn) == OPR_FUNC_ENTRY)
    print_PU_name("FUNC_ENTRY(%s)\n");
  else dump_tree(wn);

  fprintf(TFile, buffer); fprintf(TFile, "--------------------\n");
}



}
