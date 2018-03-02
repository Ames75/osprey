#
#  (C) 2008-2011 Advanced Micro Devices, Inc. All Rights Reserved.
#
#  This file is part of AMD LibM 3.0.
#
#  AMD LibM 3.0 is free software; you can redistribute it and/or
#  modify it under the terms of the GNU Lesser General Public
#  License as published by the Free Software Foundation; either
#  version 2.1 of the License, or (at your option) any later version.
#
#  AMD LibM 3.0 is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#  Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public
#  License along with AMD LibM 3.0.  If not, see
#  <http://www.gnu.org/licenses/>.
#
#



#fdim.S
#
# An implementation of the fdim libm function.
#
#  The fdim functions determine the positive difference between their arguments
#	
#	x - y if x > y
#	+0    if x <= y
#
#
#
# Prototype:
#
#     double fdim(double x, double y)
#

#
#   Algorithm:
#

#include "fn_macros.h"
#include "weak_macros.h"
#define fname FN_PROTOTYPE(fdim)

WEAK_ACML_LIB_ALIAS fastfdim, FN_PROTOTYPE(fdim)
#ifdef __ELF__
.section .note.GNU-stack,"",@progbits
#endif

.text
.align 16
.p2align 4,,15
.globl fname
.type fname,@function
#include "weak_macros.h"
WEAK_MATH_LIB_ALIAS fdim,fname
fname:

	MOVAPD 	%xmm0,%xmm2	
	SUBSD   %xmm1,%xmm0 	
	CMPNLESD %xmm1,%xmm2
	ANDPD 	 %xmm2,%xmm0
	
    ret
