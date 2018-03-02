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
#define fname FN_PROTOTYPE_BDOZR(exp)
# #define fname_special _exp_special@PLT
#ifdef __ELF__
.section .note.GNU-stack,"",@progbits
#endif

.text
.p2align 4
.globl fname
.type fname,@function
fname:
    vucomisd    .L__max_exp_arg(%rip), %xmm0
    ja          .L__y_is_inf
    jp          .L__y_is_nan
    vucomisd    .L__denormal_tiny_threshold(%rip), %xmm0
    jbe         .L__y_is_zero

    # x * (64/ln(2))
    vmulsd       .L__real_64_by_log2(%rip), %xmm0,%xmm1

    # n = int( x * (64/ln(2)) )
    vcvttpd2dq   %xmm1, %xmm2   #xmm2 = (int)n
    vcvtdq2pd    %xmm2, %xmm1   #xmm1 = (double)n #can use round
    vmovd        %xmm2, %ecx

    # r1 = x - n * ln(2)/64 head    
    # r2 = - n * ln(2)/64 tail    
    # r  = r1+r2    
    vmovlhps     %xmm1,%xmm1,%xmm1     #xmm1 = (double)n,(double)n
    vmovq        %xmm0,%xmm0           #xmm0 = 0,x   #zero out the upper part
    vfmaddpd     %xmm0,.L__log2_by_64_mtail_mhead(%rip),%xmm1,%xmm2
    vhaddpd      %xmm2,%xmm2,%xmm2     #xmm2 = r,r
    
    #j = n & 0x3f    
    mov         $0x3f, %rax
    and         %ecx, %eax     #eax = j
    # m = (n - j) / 64      
    sar         $6, %ecx       #ecx = m

    # q = r + r^2*1/2 + r^3*1/6 + r^4 *1/24 + r^5*1/120 + r^6*1/720
    # q = r + r*r*(1/2 + r*(1/6+ r*(1/24 + r*(1/120 + r*(1/720)))))
    vmovapd    .L__real_1_by_720(%rip),%xmm3
    vfmaddsd   .L__real_1_by_120(%rip),%xmm3,%xmm2,%xmm3
    vfmaddsd   .L__real_1_by_24(%rip),%xmm3,%xmm2,%xmm3
    vfmaddsd   .L__real_1_by_6(%rip),%xmm3,%xmm2,%xmm3
    vfmaddsd   .L__real_1_by_2(%rip),%xmm3,%xmm2,%xmm3
    vmulsd     %xmm2,%xmm2,%xmm0
    vfmaddsd   %xmm2,%xmm3,%xmm0,%xmm0 
    
    # (f)*(q) + f2 + f1
    cmp         $0xfffffc02, %ecx # -1022    
    lea         .L__two_to_jby64_table(%rip), %rdx        
    lea         .L__two_to_jby64_tail_table(%rip), %r11       
    lea         .L__two_to_jby64_head_table(%rip), %r10      
    vmulsd      (%rdx,%rax,8), %xmm0,%xmm2
    vaddsd      (%r11,%rax,8), %xmm2,%xmm1
    vaddsd      (%r10,%rax,8), %xmm1,%xmm0        

    jle         .L__process_denormal 
.L__process_normal:
    shl         $52, %rcx    
    vmovq        %rcx,%xmm2
    vpaddq       %xmm2,%xmm0,%xmm0
    ret

.p2align 4
.L__process_denormal:
    jl          .L__process_true_denormal
    vucomisd    .L__real_one(%rip), %xmm0
    jae         .L__process_normal
.L__process_true_denormal:
    # here ( e^r < 1 and m = -1022 ) or m <= -1023
    add         $1074, %ecx
    mov         $1, %rax    
    shl         %cl, %rax
    vmovq       %rax, %xmm2
    vmulsd      %xmm2,%xmm0,%xmm0
    ret        
    
.p2align 4
.L__y_is_inf:
    mov         $0x7ff0000000000000,%rax
    vmovq       %rax, %xmm0
    #call        fname_special
    ret     

.p2align 4
.L__y_is_nan:
    vaddsd      %xmm0,%xmm0,%xmm0
    #call        fname_special
    ret

.p2align 4
.L__y_is_zero:
    vucomisd     .L__min_exp_arg(%rip),%xmm0
    jbe          .L__return_zero
    vmovapd      .L__real_smallest_denormal(%rip), %xmm0
    ret
    
.p2align 4        
.L__return_zero:    
    vpxor       %xmm2,%xmm2,%xmm0
    #call        fname_special
    ret      
    
.data
.align 16
.L__max_exp_arg:            .quad 0x40862e42fefa39ef
.L__denormal_tiny_threshold:.quad 0xc0874046dfefd9d0
.L__min_exp_arg:            .quad 0xc0874910d52d3051
.L__real_64_by_log2:        .quad 0x40571547652b82fe    # 64/ln(2)
.L__log2_by_64_mtail_mhead: .octa 0xbd1cf79abc9e3b39bf862e42fefa0000
.L__real_smallest_denormal: .quad 0x0000000000000001
.L__real_one:               .quad 0x3ff0000000000000

