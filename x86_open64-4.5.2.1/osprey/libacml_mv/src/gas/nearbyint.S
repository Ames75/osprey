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



# fabs.S
#
# An implementation of the fabs libm function.
#
# Prototype:
#
#     double fabs(double x);
#

#
#   Algorithm:
#

#include "fn_macros.h"
#include "weak_macros.h"

#define fname FN_PROTOTYPE(nearbyint)
#define fname_special _nearbyint_special@PLT

WEAK_ACML_LIB_ALIAS fastnearbyint, FN_PROTOTYPE(nearbyint)

# local variable storage offsets

#ifdef __ELF__
.section .note.GNU-stack,"",@progbits
#endif

.equ mvalue1,    0x10 
.equ mvalue2,    0x20 


.text
.align 16
.p2align 4,,15
.globl fname
.type fname,@function
WEAK_MATH_LIB_ALIAS nearbyint,fname
fname:                                                      
    
    sub $0x28,%rsp                                                    
    movsd .L__2p52_mask_64(%rip),%xmm2                             
    movsd .L__sign_mask_64(%rip),%xmm4                               
    movsd %xmm0,%xmm1                                                 
    movsd %xmm0,%xmm5  # 
    pand  %xmm4,%xmm1 
    movsd  %xmm1,%xmm3  #  
    movd   %xmm1,%rax
    cmp    .L__2p52_mask_64(%rip),%rax 
    jg    .L__greater_than_2p52      # xmm0 is Nan 

.L__normal_input_case:
    #sign.u32 = checkbits.u32[1] & 0x80000000;
    #xmm4 = sign.u32
    pandn %xmm5,%xmm4
    #val_2p52.u32[1] = sign.u32 | 0x43300000;
    #val_2p52.u32[0] = 0;
    por   %xmm4,%xmm2
    #val_2p52.f64 = (x + val_2p52.f64) - val_2p52.f64;

    STMXCSR mvalue1(%rsp)
    mov     mvalue1(%rsp),%eax
    or	    $0x000000800,%eax
    mov    %eax,mvalue2(%rsp) 
    LDMXCSR mvalue2(%rsp)
    addpd %xmm2,%xmm5 
    subpd %xmm5,%xmm2
    mov   mvalue1(%rsp),%eax
    and	 $0xffffffc0,%eax
    mov   %eax,mvalue2(%rsp) 
    LDMXCSR	mvalue2(%rsp)
    pand	.L__sign_mask_64(%rip),%xmm2	
    por   %xmm4,%xmm2
    movsd	%xmm2, 	%xmm0						
    add $0x28,%rsp
    ret
.L__special_case:
.L__greater_than_2p52:
    call fname_special
    add $0x28,%rsp
    ret
.align 16
.L__sign_mask_64:          .quad 0x7FFFFFFFFFFFFFFF
                           .quad 0
.L__2p52_mask_64:          .quad 0x4330000000000000 
                           .quad 0
.L__exp_mask_64:           .quad 0x7FF0000000000000
                           .quad 0






