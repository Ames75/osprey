
/*
 * Copyright (C) 2008-2011 Advanced Micro Devices, Inc.  All Rights Reserved.
 */

/*
  This program is free software; you can redistribute it and/or modify it
  under the terms of version 2 of the GNU General Public License as
  published by the Free Software Foundation.

  This program is distributed in the hope that it would be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

  Further, this software is distributed without any warranty that it is
  free of the rightful claim of any third person regarding infringement 
  or the like.  Any license provided herein, whether implied or 
  otherwise, applies only to this software file.  Patent licenses, if 
  any, provided herein do not apply to combinations of this program with 
  other software, or any other product whatsoever.  

  You should have received a copy of the GNU General Public License along
  with this program; if not, write the Free Software Foundation, Inc., 59
  Temple Place - Suite 330, Boston MA 02111-1307, USA.
*/
/* ====================================================================

* Interface to the new CMOV Converter.
* Conditional MOV instruction moves source value into the destination register 
* if the condition specified in the opcode is met.
* The power of CMOVs lies in the fact that,it can help eliminate conditional jumps. 
* This module aims at replacing the reg movs with cmovs at CGIR,
* eliminating conditional jumps.
*
* Case 1: hammock pattern
----------------------------------------------------------------
* - fall thru has only reg moves w/wo a jmp to imm post dominator
* - target has only reg moves w/wo a jmp to imm post dominator
* What we do:
* Remove the movs from fall thru and target insert cmovs to parent
* Append the jmp to imm post dominator into parent 
* Remove fall thru,branch target
* Blocks cmoved: fall thru, branch target
* Blocks merged: -
* 
* Case 2:(simple if pattern)
--------------------------------------------------------------
* For a simple if statement such as :
*	if(cond){
*	  s1;
*	}
*	s2;
* The compiler inverts the cond
* - puts statements within if in the fall thru
* - statements following the if in the branch target
* The statements within the if (s1), fall thru to the statements following the if(s2).
*
* Basic idea: If the statements within if had only reg movs, execute them conditionally,
* and eliminate the jump to the target  
*
* - parent is a LOGIF bb 
* - fall thru has only reg movs
* - successor of fall thru is the branch target
*
* What we do:
* Remove the movs from fall thru, insert cmovs to parent
* Remove jmp from parent
* Append all ops in the branch target to parent
* Add the successors of the branch target to the successors of parent
* Remove fall thru bb,branch target bb
* Blocks cmoved : fall thru
* Blocks merged : branch target
*       
* ====================================================================
* ====================================================================
*/

#ifndef cmov_conv_INCLUDED
#define cmov_conv_INCLUDED
#include "bb.h"
#include "topcode.h"
#include "tracing.h"
#include <cmath>

enum convert_mode{NOCMOV, FALL_THRU , HAMMOCK};
 
class CMOV_Converter{
private:

  bool Trace_CMOV;
  const float min_branch_prob_diff;
    
  //Determines cmov's opcode from the parent's conditional branch
  TOP Determine_Cmov_From_Cond_Branch(TOP top,bool choose_fall);
  //Checks if the fall thru is suitable for cmov conversion
  bool Is_Fall_Thru_Suitable(BB *bb,BB *fall_thru);
  //Checks if hammock pattern suitable for cmov conversion
  bool Is_Hammock(BB *bb,BB *fall_thru,BB *target);
  //Checks if the parent bb is suitable for cmov conversion
  bool Is_Parent_Suitable(BB *bb);

  convert_mode Test_Criteria(BB *bb);

  bool Test_Merge_Criteria(BB *,BB *);
  //cmov the fall thru and merge target bb into parent
  bool Merge_Parent_Fall_Thru(BB *bb);
  //cmov both fall thru and target bb into parent
  bool Merge_Hammock(BB *bb);
//utility function to remove the movs from succs, covert to cmovs and add to parent bb
  void Convert_Movs_To_Cmovs(BB *,BB *,TOP);
public:
  CMOV_Converter();
  ~CMOV_Converter();

// Top Level function for cmov conversion
// NOTE: first cut,called from cg before assembly 
  int cmov_convert();
};

static inline bool BB_last_OP_computes_got (BB* bb);

static inline bool BB_first_OP_computes_got (BB* bb);

#endif /* cmov_conv_INCLUDED */

