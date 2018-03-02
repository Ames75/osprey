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



#include "fn_macros.h"
#include "exp_tables.h"
#define fname FN_PROTOTYPE_BDOZR(expf)
# #define fname_special _expf_special@PLT

#ifdef __ELF__
.section .note.GNU-stack,"",@progbits
#endif

.text
.p2align 4
.globl fname
.type fname,@function
fname:
    vucomiss .L__max_expf_arg(%rip), %xmm0
    ja .L__y_is_inf
    jp .L__y_is_nan
    vucomiss .L__min_expf_arg(%rip), %xmm0
    jb .L__y_is_zero

    vcvtps2pd     %xmm0, %xmm2    #xmm2 = (double)x

    # x * (64/ln(2))
    vmulsd       .L__real_64_by_log2(%rip),%xmm2,%xmm3  #xmm3 = x * (64/ln(2)

    # n = int( x * (64/ln(2)) )
    vcvtpd2dq    %xmm3, %xmm4  #xmm4 = (int)n
    vcvtdq2pd    %xmm4, %xmm0  #xmm0 = (double)n

    # r = x - n * ln(2)/64
    vfmaddsd    %xmm2,.L__real_mlog2_by_64(%rip),%xmm0,%xmm1 #xmm1 = r
    vmovd       %xmm4, %ecx     #ecx = n

    # q = r+r*r*(1/2 + (1/6 * r))
    vmovhpd       .L__real_1_by_6(%rip), %xmm1,%xmm3  #%xmm3 =1/6,r 
    vmovlhps     %xmm3,%xmm1,%xmm1     #xmm1 = r,r        
    vfmaddpd     .L__real_1_by_2_zero(%rip), %xmm1, %xmm3, %xmm2 #xmm2 = r*r,1/2 + (1/6 * r)
    vmovhlps      %xmm2, %xmm1,%xmm3 #xmm3 = r,r*r
    vfmaddsd     %xmm1,%xmm3,%xmm2,%xmm0 #xmm0 = q
    
    #j = n & 0x3f
    mov         $0x3f, %rax     #rax = 0x3f
    and         %ecx, %eax      #eax = j = n & 0x3f

    # f + (f*q)
    lea         .L__two_to_jby64_table(%rip), %r10    
    vmovsd      (%r10,%rax,8), %xmm2
    vfmaddsd    %xmm2,%xmm2,%xmm0,%xmm3

    .p2align 4
    # m = (n - j) / 64        
    vpsrad       $6,%xmm4,%xmm1
    vpsllq       $52,%xmm1,%xmm4
    vpaddq      %xmm3, %xmm4,%xmm2
    vcvtpd2ps   %xmm2, %xmm0
    ret

.p2align 4
.L__y_is_zero:
    vpxor       %xmm2,%xmm2,%xmm0
    #call       fname_special
    ret         

.p2align 4
.L__y_is_inf:
    mov         $0x7f800000,%edx
    vmovd       %edx, %xmm0
    #call       fname_special
    ret     

.p2align 4
.L__y_is_nan:
    vaddss      %xmm0,%xmm0,%xmm0
    #call       fname_special
    ret      
    
.data
.align 16
.L__max_expf_arg:               .long 0x42B17218
.L__min_expf_arg:               .long 0xC2CE8ED0
.L__real_64_by_log2:            .quad 0x40571547652b82fe # 64/ln(2)
.L__real_mlog2_by_64:           .quad 0xbf862e42fefa39ef # log2_by_64
.L__real_1_by_2_zero:           .octa 0x3fe00000000000000000000000000000