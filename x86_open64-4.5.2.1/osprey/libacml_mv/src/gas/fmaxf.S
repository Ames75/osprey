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



#fmaxf.S
#
# An implementation of the fmaxf libm function.
#
# The fmax functions determine the maximum numeric value of their arguments.
#
# Prototype:
#
#     float fmaxf(float x, float y)
#

#
#   Algorithm:
#

#include "fn_macros.h"
#include "weak_macros.h"
#define fname FN_PROTOTYPE(fmaxf)

WEAK_ACML_LIB_ALIAS fastfmaxf, FN_PROTOTYPE(fmaxf)
#ifdef __ELF__
.section .note.GNU-stack,"",@progbits
#endif

.text
.align 16
.p2align 4,,15
.globl fname
.type fname,@function
#include "weak_macros.h"
WEAK_MATH_LIB_ALIAS fmaxf,fname
fname:

    movaps      %xmm0, %xmm2
    movaps      %xmm0, %xmm3
    movaps      %xmm0, %xmm4

    xorps       %xmm5, %xmm5 # 0
    maxps       %xmm1, %xmm3 # max(a,b)

    orps        %xmm1, %xmm2 # a | b
    andps       %xmm1, %xmm4 
    cmpeqps     %xmm5, %xmm2 # both a,b are zero

    pand        %xmm2, %xmm4 # max zero
    pandn       %xmm3, %xmm2
    por         %xmm4, %xmm2

    cmpneqps    %xmm1, %xmm1 # b is NaN
    pand        %xmm1, %xmm0
    pandn       %xmm2, %xmm1
    por         %xmm1, %xmm0

    ret

