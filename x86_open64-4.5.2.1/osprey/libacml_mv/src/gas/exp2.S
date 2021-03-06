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

#define fname FN_PROTOTYPE_BAS64(exp2)
#define fname_special _exp2_special@PLT

WEAK_ACML_LIB_ALIAS fastexp2, FN_PROTOTYPE(exp2)
#ifdef __ELF__
.section .note.GNU-stack,"",@progbits
#endif

.text
.p2align 4
.globl fname
.type fname,@function
fname:
    ucomisd      .L__max_exp2_arg(%rip), %xmm0
    ja           .L__y_is_inf
    jp           .L__y_is_nan
    ucomisd      .L__min_exp2_arg(%rip), %xmm0
    jbe          .L__y_is_zero

    # x * (64)
    movapd      %xmm0,%xmm2        
    mulsd       .L__real_64(%rip), %xmm2

    # n = int( x * (64))
    cvttpd2dq    %xmm2, %xmm1   #xmm1 = (int)n
    cvtdq2pd    %xmm1, %xmm2   #xmm2 = (double)n
    movd        %xmm1, %ecx

    # r = x - n * 1/64  
    #r *= ln2;      
    mulsd    .L__one_by_64(%rip),%xmm2
    addsd    %xmm0,%xmm2   #xmm2 = r    
    mulsd    .L__ln_2(%rip),%xmm2    
        
    #j = n & 0x3f    
    mov         $0x3f, %rax
    and         %ecx, %eax     #eax = j
    # m = (n - j) / 64      
    sar         $6, %ecx       #ecx = m

    # q = r + r^2*1/2 + r^3*1/6 + r^4 *1/24 + r^5*1/120 + r^6*1/720
    # q = r + r*r*(1/2 + r*(1/6+ r*(1/24 + r*(1/120 + r*(1/720)))))
    movapd       .L__real_1_by_720(%rip), %xmm3  #xmm3 = 1/720
    mulsd       %xmm2, %xmm3    #xmm3 = r*1/720
    movapd       .L__real_1_by_6(%rip), %xmm0    #xmm0 = 1/6    
    movapd      %xmm2, %xmm1 #xmm1 = r            
    mulsd       %xmm2, %xmm0    #xmm0 = r*1/6
    addsd       .L__real_1_by_120(%rip), %xmm3  #xmm3 = 1/120 + (r*1/720)
    mulsd       %xmm2, %xmm1    #xmm1 = r*r    
    addsd       .L__real_1_by_2(%rip), %xmm0  #xmm0 = 1/2 + (r*1/6)        
    movapd       %xmm1, %xmm4   #xmm4 = r*r
    mulsd       %xmm1, %xmm4    #xmm4 = (r*r) * (r*r)    
    mulsd       %xmm2, %xmm3    #xmm3 = r * (1/120 + (r*1/720))
    mulsd       %xmm1, %xmm0    #xmm0 = (r*r)*(1/2 + (r*1/6))
    addsd       .L__real_1_by_24(%rip), %xmm3  #xmm3 = 1/24 + (r * (1/120 + (r*1/720)))
    addsd       %xmm2, %xmm0   #xmm0 = r + ((r*r)*(1/2 + (r*1/6)))
    mulsd       %xmm4, %xmm3   #xmm3 = ((r*r) * (r*r)) * (1/24 + (r * (1/120 + (r*1/720))))
    addsd       %xmm3, %xmm0   #xmm0 = r + ((r*r)*(1/2 + (r*1/6))) + ((r*r) * (r*r)) * (1/24 + (r * (1/120 + (r*1/720))))
    
    # (f)*(q) + f2 + f1
    cmp         $0xfffffc02, %ecx # -1022    
    lea         .L__two_to_jby64_table(%rip), %rdx        
    lea         .L__two_to_jby64_tail_table(%rip), %r11       
    lea         .L__two_to_jby64_head_table(%rip), %r10      
    mulsd       (%rdx,%rax,8), %xmm0
    addsd       (%r11,%rax,8), %xmm0
    addsd       (%r10,%rax,8), %xmm0        

    jle         .L__process_denormal 
.L__process_normal:
    shl         $52, %rcx    
    movd        %rcx,%xmm2
    paddq       %xmm2, %xmm0
    ret

.p2align 4
.L__process_denormal:
    jl          .L__process_true_denormal
    ucomisd     .L__real_one(%rip), %xmm0
    jae         .L__process_normal
.L__process_true_denormal:
    # here ( e^r < 1 and m = -1022 ) or m <= -1023
    add         $1074, %ecx
    mov         $1, %rax    
    shl         %cl, %rax
    movd         %rax, %xmm2
    mulsd       %xmm2, %xmm0
    ret        
    
.p2align 4
.L__y_is_inf:
    mov         $0x7ff0000000000000,%rax
    movd       %rax, %xmm1
    mov         $3, %edi
    #call        fname_special
    movdqa     %xmm1,%xmm0 #remove this if call is made    
    ret     

.p2align 4
.L__y_is_nan:
    movapd      %xmm0,%xmm1
    addsd       %xmm0,%xmm1
    mov         $1, %edi
    #call        fname_special
    movdqa     %xmm1,%xmm0 #remove this if call is made    
    ret

.p2align 4
.L__y_is_zero:
    pxor        %xmm1,%xmm1
    mov         $2, %edi
    #call        fname_special
    movdqa     %xmm1,%xmm0 #remove this if call is made
    ret      
    
.data
.align 16
.L__max_exp2_arg:            .quad 0x4090000000000000
.L__min_exp2_arg:            .quad 0xc090c80000000000
.L__real_64:                 .quad 0x4050000000000000    # 64
.L__ln_2:                    .quad 0x3FE62E42FEFA39EF
.L__one_by_64:               .quad 0xbF90000000000000

.align 16
.L__real_one:                   .quad 0x3ff0000000000000

