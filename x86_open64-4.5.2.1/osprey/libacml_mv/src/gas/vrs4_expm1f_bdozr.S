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

#define fname FN_PROTOTYPE_BDOZR(vrs4_expm1f)
#ifdef __ELF__
    .section .note.GNU-stack,"",@progbits
#endif

.text
.p2align 4
.globl fname
.type	fname, @function
fname:

    vmovdqa       %xmm0, %xmm10   # save for later use
    
    #x_double = (double)x;
    vcvtps2pd     %xmm0, %ymm2    #ymm2 = (double)x3,x2,x1,x0
        
    # x * (64/ln(2))    
    vmulpd       .L__real_64_by_log2(%rip), %ymm2, %ymm3 #ymm3 = x3 * (64/ln(2),x2 * (64/ln(2),x1 * (64/ln(2),x0 * (64/ln(2)
   
    # n = int( x * (64/ln(2)) )
    vcvtpd2dq    %ymm3, %xmm4  #xmm4 = (int)n3,n2,n1,n0 
    vcvtdq2pd    %xmm4, %ymm0  #ymm0 = (double)n3,n2,n1,n0    
    
    # r = x - n * ln(2)/64
    vfmaddpd    %ymm2,.L__real_mlog2_by_64(%rip),%ymm0,%ymm1 #ymm1 = r3,r2,r1,r0

    # q = r+r*r*(1/2 + (1/6 * r))
    vmovdqa     .L__real_4_1_by_6s(%rip), %ymm3
    vfmaddpd    .L__real_4_1_by_2s(%rip),%ymm3,%ymm1,%ymm2 #ymm2 = (1/2 + (1/6 * r))
    vmulpd       %ymm1,%ymm1,%ymm3   #ymm3 = r3*r3,r2*r2,r1*r1,r0*r0
    vfmaddpd     %ymm1,%ymm3,%ymm2,%ymm0 #ymm0 = q3,q2,q1,q0    

    # m = (n - j) / 64 
    #j = n & 0x3f
    vpsrad      $6,%xmm4,%xmm5    #xmm5 = m3,m2,m1,m0
    vpslld      $26,%xmm4,%xmm3   
    vpsrld      $26,%xmm3,%xmm6   #xmm6 = j3,j2,j1,j0           
   
    #process each input seperately
    lea         .L__two_to_jby64_table(%rip), %r10    
    vmovd        %xmm6, %eax
    vmovd        %xmm5, %ecx
    vextractf128 $1,%ymm0, %xmm7
    vmovhlps     %xmm0, %xmm8,%xmm8    
    mov         $4, %r11d
    jmp         .L__start

.p2align 4
.L__check_n_prepare_next:
    dec         %r11d
    jz          .L__ret
    vpsrldq      $4,%xmm6,%xmm6
    vmovd        %xmm6, %eax
    vpsrldq      $4,%xmm5,%xmm5
    vmovd        %xmm5, %ecx 
    vpsrldq      $4,%xmm10,%xmm10       
    cmp         $3,%r11d
    je          .L__output1_inputq2
    cmp         $2,%r11d
    je          .L__output2_inputq3
    cmp         $1,%r11d
    je          .L__output3_inputq4
    
.p2align 4
.L__output1_inputq2:
    vpxor      %xmm9,%xmm9,%xmm9
    vpslldq    $12, %xmm0,%xmm0
    vpsrldq    $12, %xmm0,%xmm0
    vpor       %xmm0,%xmm9,%xmm9
    movdqa    %xmm8, %xmm0    
    jmp .L__start
    
.p2align 4
.L__output2_inputq3:    
    vpslldq    $12, %xmm0,%xmm0
    vpsrldq    $8, %xmm0, %xmm0
    vpor       %xmm0,%xmm9,%xmm9
    vmovdqa    %xmm7, %xmm0    
    jmp .L__start
    
.p2align 4
.L__output3_inputq4:
    vpslldq    $12, %xmm0,%xmm0
    vpsrldq    $4, %xmm0,%xmm0
    vpor       %xmm0,%xmm9,%xmm9
    vmovhlps   %xmm7,%xmm0, %xmm0    

.p2align 4
.L__start:
    ucomiss .L__max_expm1_arg(%rip),%xmm10         ##if(x > max_expm1_arg)
    ja .L__y_is_inf
    jp .L__y_is_nan
    ucomiss .L__log_OnePlus_OneByFour(%rip),%xmm10 ##if(x < log_OnePlus_OneByFour)
    jae .L__Normal_Flow
    ucomiss .L__log_OneMinus_OneByFour(%rip),%xmm10 ##if(x > log_OneMinus_OneByFour)
    ja .L__Small_Arg
    ucomiss .L__min_expm1_arg(%rip),%xmm10         ##if(x < min_expm1_arg)
    jb .L__y_is_minusOne

.p2align 4    
.L__Normal_Flow:    
    #f
    vmovsd       (%r10,%rax,8), %xmm3 #xmm3 = f
    
    #f*q
    #vmulsd       %xmm3, %xmm0, %xmm2  #xmm2 = f*q    
    
    #twopmm.u64 = (1023 - (long)m) << 52;    
    #f - twopmm
    mov         $1023, %eax
    sub         %ecx, %eax
    shl         $52, %rax    
    vmovq        %rax, %xmm1
    vsubsd      %xmm1, %xmm3,%xmm2  #xmm2 = f - twopmm
    
    #z = f * q + (f - twopmm.f64) ;
    #z = z* 2^m
    vfmaddsd    %xmm2,%xmm3,%xmm0,%xmm1 #xmm1 = z
    shl         $52, %rcx    
    movd        %rcx, %xmm2
    vpaddq      %xmm1, %xmm2,%xmm3
    vcvtpd2ps   %xmm3, %xmm0
    jmp        .L__check_n_prepare_next
	
.p2align 4
.L__Small_Arg:
    #log(1-1/4) < x < log(1+1/4)
	#q = x*x*x*(A1 + x*(A2 + x*(A3 + x*(A4 + x*(A5)))));
	movapd %xmm10,%xmm0
	vucomiss .L__minus_zero(%rip), %xmm0
	je     .L__check_n_prepare_next
	vmulss .L__A5_f(%rip),%xmm0,%xmm3
	vaddss .L__A4_f(%rip),%xmm3,%xmm1	
	vfmaddss .L__A3_f(%rip),%xmm0,%xmm1,%xmm3
	vfmaddss .L__A2_f(%rip),%xmm0,%xmm3,%xmm1
	vfmaddss .L__A1_f(%rip),%xmm0,%xmm1,%xmm3 #xmm3 = (A1 + x*(A2 + x*(A3 + x*(A4 + x*(A5)))))
	vmulss  %xmm0,%xmm3,%xmm1
	vmulss  %xmm0,%xmm1,%xmm3 
	vmulss  %xmm0,%xmm3,%xmm1       #xmm1 = q	
	vcvtps2pd %xmm0,%xmm2           #xmm2 = (double)x
	vmulsd %xmm2,%xmm2,%xmm0	#xmm0 = x*x - in double
	vfmaddsd %xmm2,.L__real_1_by_2(%rip),%xmm0,%xmm3
	vcvtps2pd %xmm1,%xmm0
	vaddsd %xmm3,%xmm0,%xmm2
	vcvtpd2ps %xmm2,%xmm0	    	
        jmp    .L__check_n_prepare_next         
        
.p2align 4
.L__y_is_minusOne:
    mov         $0xBF800000, %eax
    vmovd        %eax, %xmm0
    jmp    .L__check_n_prepare_next     
    
.p2align 4
.L__y_is_inf:
    mov         $0x7f800000,%eax
    vmovd        %eax, %xmm0
    jmp    .L__check_n_prepare_next     
    
.p2align 4
.L__y_is_nan:
    vaddss  %xmm10,%xmm10,%xmm0
    jmp    .L__check_n_prepare_next     
    
.L__ret:
    vpslldq    $12, %xmm0,%xmm0
    vpor       %xmm0,%xmm9,%xmm9
    vmovdqa    %xmm9, %xmm0    
    ret
    
.data
.align 16
.L__max_expm1_arg:          .long 0x42B19999
.L__log_OnePlus_OneByFour:  .long 0x3E647FBF
.L__log_OneMinus_OneByFour: .long 0xBE934B11
.L__min_expm1_arg:          .long 0xC18AA122
.L__A1_f:                   .long 0x3E2AAAAA   
.L__A2_f:                   .long 0x3D2AAAA0
.L__A3_f:                   .long 0x3C0889FF     
.L__A4_f:                   .long 0x3AB64DE5
.L__A5_f:                   .long 0x394AB327
.L__minus_zero:             .long 0x80000000
.align 32 
.L__real_64_by_log2:            .octa 0x40571547652b82fe40571547652b82fe # 64/ln(2)
                                .octa 0x40571547652b82fe40571547652b82fe # 64/ln(2)
.L__real_mlog2_by_64:           .octa 0xbf862e42fefa39efbf862e42fefa39ef # log2_by_64
                                .octa 0xbf862e42fefa39efbf862e42fefa39ef # log2_by_64
.L__real_4_1_by_2s:             .octa 0x3fe00000000000003fe0000000000000
                                .octa 0x3fe00000000000003fe0000000000000                                                            
.L__real_4_1_by_6s:             .octa 0x3fc55555555555553fc5555555555555    # 1/6
                                .octa 0x3fc55555555555553fc5555555555555    
    

    

