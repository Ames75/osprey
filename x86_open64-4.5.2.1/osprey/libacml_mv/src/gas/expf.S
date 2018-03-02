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



#
# expf.S
#
# An implementation of the expf libm function.
#
# Prototype:
#
#     float expf(float x);
#

#
#   Algorithm:
#       Similar to one presnted in exp.S
#

#include "fn_macros.h"
#include "weak_macros.h"
#include "exp_tables.h"
#define fname FN_PROTOTYPE_BAS64(expf)
#define fname_special _expf_special@PLT

WEAK_ACML_LIB_ALIAS fastexpf, FN_PROTOTYPE(expf)

#ifdef __ELF__
.section .note.GNU-stack,"",@progbits
#endif

.text
.p2align 4
.globl fname
.type fname,@function
fname:
    ucomiss .L__max_expf_arg(%rip), %xmm0
    ja .L__y_is_inf
    jp .L__y_is_nan
    ucomiss .L__min_expf_arg(%rip), %xmm0
    jb .L__y_is_zero

    cvtps2pd     %xmm0, %xmm0    #xmm0 = (double)x

    # x * (64/ln(2))
    movapd      %xmm0,%xmm3      #xmm3 = (xouble)x
    mulsd       .L__real_64_by_log2(%rip), %xmm3  #xmm3 = x * (64/ln(2)

    # n = int( x * (64/ln(2)) )
    cvtpd2dq    %xmm3, %xmm4  #xmm4 = (int)n
    cvtdq2pd    %xmm4, %xmm2  #xmm2 = (double)n

    # r = x - n * ln(2)/64
    mulsd       .L__real_log2_by_64(%rip),%xmm2 #xmm2 = n * ln(2)/64
    movd        %xmm4, %ecx     #ecx = n
    subsd       %xmm2, %xmm0    #xmm0 = r
    movapd      %xmm0, %xmm1    #xmm1 = r

    # q = r+r*r*(1/2 + (1/6 * r))
    movsd       .L__real_1_by_6(%rip), %xmm3 
    mulsd       %xmm0, %xmm3 #xmm3 = 1/6 * r
    mulsd       %xmm1, %xmm0 #xmm0 =  r  * r
    addsd       .L__real_1_by_2(%rip), %xmm3 #xmm3 = 1/2 + (1/6 * r)
    mulsd       %xmm3, %xmm0  #xmm0 = r*r*(1/2 + (1/6 * r))
    addsd       %xmm1, %xmm0  #xmm0 = r+r*r*(1/2 + (1/6 * r))
    
    #j = n & 0x3f
    mov         $0x3f, %rax     #rax = 0x3f
    and         %ecx, %eax      #eax = j = n & 0x3f

    # (f)*(1+q)
    lea         .L__two_to_jby64_table(%rip), %r10    
    mulsd       (%r10,%rax,8), %xmm0
    addsd       (%r10,%rax,8), %xmm0
    
    .p2align 4    
    # m = (n - j) / 64        
    psrad       $6,%xmm4
    psllq       $52,%xmm4
    paddq       %xmm0, %xmm4
    cvtpd2ps    %xmm4, %xmm0
    ret

.p2align 4
.L__y_is_zero:

    pxor        %xmm1, %xmm1    #return value in xmm1,input in xmm0 before calling
    mov         $2, %edi        #code in edi
    call        fname_special
    ret         

.p2align 4
.L__y_is_inf:

    mov         $0x7f800000,%edx
    movd        %edx, %xmm1
    mov         $3, %edi
    call        fname_special
    ret     

.p2align 4
.L__y_is_nan:
    movaps %xmm0,%xmm1
    addss  %xmm1,%xmm1
    mov         $1, %edi
    call        fname_special
    ret       
    
.data
.align 16
.L__max_expf_arg:                 .long 0x42B17218
.L__min_expf_arg:                 .long 0xC2CE8ED0
.L__real_64_by_log2:            .quad 0x40571547652b82fe # 64/ln(2)
.L__real_log2_by_64:            .quad 0x3f862e42fefa39ef # log2_by_64


