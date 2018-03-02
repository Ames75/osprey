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



# truncf.S
#
# An implementation of the truncf libm function.
#
#
# The trunf functions round their argument to the integer value, in floating format,
# nearest to but no larger in magnitude than the argument.
#
#
# Prototype:
#
#     float truncf(float x);
#

#
#   Algorithm:
#

#include "fn_macros.h"
#include "weak_macros.h"
#define fname FN_PROTOTYPE(truncf )

WEAK_ACML_LIB_ALIAS fasttruncf, FN_PROTOTYPE(truncf)

#ifdef __ELF__
.section .note.GNU-stack,"",@progbits
#endif

.text
.align 16
.p2align 4,,15
.globl fname
.type fname,@function
#include "weak_macros.h"
WEAK_MATH_LIB_ALIAS truncf,fname
fname:
	
	
	MOVAPD %xmm0,%xmm1	

# convert  float to integer.
	CVTTSS2SIQ %xmm0,%rax
	
	CMP .L__Erro_mask(%rip),%rax
	jz .Error_val	
	
# convert  integer	to float
	CVTSI2SSQ %rax,%xmm0
	
	PSRLD $31,%xmm1
	PSLLD $31,%xmm1
	
	POR %xmm1,%xmm0
	
	
	ret
	
.Error_val:
	MOVAPD %xmm1,%xmm2
	CMPEQSS	%xmm1,%xmm1			
	ADDSS %xmm2,%xmm2	
	
	PAND %xmm1,%xmm0
	PANDN %xmm2,%xmm1
	POR %xmm1,%xmm0
	
	

	
    ret

.data
.align 16
.L__Erro_mask:  		.quad 0x8000000000000000
					    .quad 0x0
