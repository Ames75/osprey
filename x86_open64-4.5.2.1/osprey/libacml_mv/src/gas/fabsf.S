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



# fabsf.S
#
# An implementation of the fabsf libm function.
#
# Prototype:
#
#     float fabsf(float x);
#

#
#   Algorithm: AND the Most Significant Bit of the 
#              single precision number with 0 to get the 
#              floating point absolute.
#

#include "fn_macros.h"
#include "weak_macros.h"
#define fname FN_PROTOTYPE(fabsf)
#define fname_special _fabsf_special

WEAK_ACML_LIB_ALIAS fastfabsf, FN_PROTOTYPE(fabsf)

#ifdef __ELF__
.section .note.GNU-stack,"",@progbits
#endif

.text
.align 16
.p2align 4,,15
.globl fname
.type fname,@function
#include "weak_macros.h"
WEAK_MATH_LIB_ALIAS fabsf,fname
fname:
    #input is in xmm0, which contains the final result also.
    andps .L__fabsf_and_mask(%rip), %xmm0 # <result> latency = 3 
    ret


.align 16
.L__fabsf_and_mask:          .long 0x7FFFFFFF
                             .long 0x0
                             .quad 0x0





