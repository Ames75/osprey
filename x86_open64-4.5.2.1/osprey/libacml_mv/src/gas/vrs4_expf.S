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
#include "weak_macros.h"
#include "exp_tables.h"

#define fname FN_PROTOTYPE_BAS64(vrs4_expf)
WEAK_ACML_LIB_ALIAS __vrs4_expf,FN_PROTOTYPE(vrs4_expf)
#ifdef __ELF__
.section .note.GNU-stack,"",@progbits
#endif

.text
.p2align 4
.globl fname
.type fname,@function
fname:
    movdqa       %xmm0, %xmm10   # save for later use
    minps        .L__max_expf_arg(%rip), %xmm0
    movhlps      %xmm0, %xmm5  
    cvtps2pd     %xmm5, %xmm5    #xmm5 = x3,x2
    cvtps2pd     %xmm0, %xmm0    #xmm0 = (double)x

    # x * (64/ln(2))    
    movapd      %xmm5,%xmm8      #xmm8 = (double)x3,x2    
    movapd      %xmm0,%xmm3      #xmm3 = (double)x1,x0
    mulpd       .L__real_64_by_log2(%rip), %xmm8  #xmm8 = x3 * (64/ln(2),x2 * (64/ln(2)    
    mulpd       .L__real_64_by_log2(%rip), %xmm3  #xmm3 = x1 * (64/ln(2),x0 * (64/ln(2)

    # n = int( x * (64/ln(2)) )
    cvtpd2dq    %xmm8, %xmm9  #xmm9 = (int)n3,n2 
    cvtpd2dq    %xmm3, %xmm4  #xmm4 = (int)n1,n0
    cvtdq2pd    %xmm9, %xmm7  #xmm7 = (double)n3,n2    
    cvtdq2pd    %xmm4, %xmm2  #xmm2 = (double)n1,n0

    # r = x - n * ln(2)/64
    mulpd       .L__real_log2_by_64(%rip),%xmm7 #xmm7 = n3 * ln(2)/64,n2 * ln(2)/64    
    mulpd       .L__real_log2_by_64(%rip),%xmm2 #xmm2 = n1 * ln(2)/64,n0 * ln(2)/64
    subpd       %xmm7, %xmm5    #xmm5 = r3,r2    
    subpd       %xmm2, %xmm0    #xmm0 = r1,r0
    movapd      %xmm5, %xmm6    #xmm6 = r3,r2    
    movapd      %xmm0, %xmm1    #xmm1 = r1,r0

    # q
    movapd       .L__real_1_by_6(%rip), %xmm8     
    movapd       .L__real_1_by_6(%rip), %xmm3 
    mulpd       %xmm5, %xmm8 #xmm8 = 1/6 * r3,1/6 * r2    
    mulpd       %xmm0, %xmm3 #xmm3 = 1/6 * r1,1/6 * r0
    mulpd       %xmm6, %xmm5 #xmm5 =  r  * r    
    mulpd       %xmm1, %xmm0 #xmm0 =  r  * r
    addpd       .L__real_1_by_2(%rip), %xmm8 #xmm8 = 1/2 + (1/6 * r)    
    addpd       .L__real_1_by_2(%rip), %xmm3 #xmm3 = 1/2 + (1/6 * r)
    mulpd       %xmm8, %xmm5  #xmm5 = r*r*(1/2 + (1/6 * r))    
    mulpd       %xmm3, %xmm0  #xmm0 = r*r*(1/2 + (1/6 * r))
    addpd       %xmm6, %xmm5  #xmm5 = r+r*r*(1/2 + (1/6 * r))    
    addpd       %xmm1, %xmm0  #xmm0 = r+r*r*(1/2 + (1/6 * r))
    
    #j = n & 0x3f
    mov         $0x0000003f0000003f, %rax     #rax = 0x3f,0x3f    
    movd        %xmm4, %rcx     #rcx = n1,n0
    and         %rax, %rcx      #rcx = j1,j0
    movd        %xmm9, %r8     #r8 = n3,n2 
    and         %rax, %r8      #r8 = j3,j2
    
    # f + (f*q)
    lea         .L__two_to_jby64_table(%rip), %r10
    mov         %rcx, %rax
    shl         $32, %rcx
    shr         $32, %rcx       #rcx = j0
    movsd      (%r10,%rcx,8), %xmm1
    shr         $32, %rax       #rax = j1
    movhpd     (%r10,%rax,8), %xmm1
    mulpd       %xmm1, %xmm0
    addpd       %xmm1, %xmm0    
    mov         %r8, %rax
    shl         $32, %r8
    shr         $32, %r8       #r8 = j2
    movsd      (%r10,%r8,8), %xmm1
    shr         $32, %rax       #rax = j3
    movhpd     (%r10,%rax,8), %xmm1
    mulpd       %xmm1, %xmm5
    addpd       %xmm1, %xmm5

    # m = (n - j) / 64    
    psrad       $6,%xmm9     
    psrad       $6,%xmm4
    punpckldq   %xmm9, %xmm9
    punpckldq   %xmm4, %xmm4
    psllq       $52,%xmm9    
    psllq       $52,%xmm4
    
    #2 ^m * (f + (f*q))
    paddq       %xmm5, %xmm9    
    paddq       %xmm0, %xmm4
    cvtpd2ps    %xmm9, %xmm5    
    cvtpd2ps    %xmm4, %xmm0
    movlhps     %xmm5, %xmm0

    ##special case for any x < min_exp_arg
    ##remove this code if the above code takes care of this
    movdqa      .L__min_expf_arg(%rip), %xmm1        
    cmpps       $1,%xmm10,%xmm1
    pand        %xmm1, %xmm0   #make zeros to put in place of any x < min_exp2_arg     
    
    ##special case for any x = nan
    ##remove this code if the above code takes care of this
    movdqa      %xmm10, %xmm1    
    cmpps       $0x0,%xmm10,%xmm10
    pand        %xmm10, %xmm0    
    addps       %xmm1, %xmm1  #make qnan to put in place of any x =nan
    pandn       %xmm1, %xmm10
    por         %xmm10, %xmm0       
    ret           
    
.data
.align 16
.L__max_expf_arg:                .octa 0x42B1721842B1721842B1721842B17218
.L__min_expf_arg:                .octa 0xC2CE8ED0C2CE8ED0C2CE8ED0C2CE8ED0
.L__real_64_by_log2:            .octa 0x40571547652b82fe40571547652b82fe # 64/ln(2)
.L__real_log2_by_64:            .octa 0x3f862e42fefa39ef3f862e42fefa39ef # log2_by_64
