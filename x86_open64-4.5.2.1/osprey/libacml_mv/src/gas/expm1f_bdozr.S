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

#define fname FN_PROTOTYPE_BDOZR(expm1f)
#ifdef __ELF__
    .section .note.GNU-stack,"",@progbits
#endif

.text
.p2align 4
.globl fname
.type	fname, @function
fname:
    vucomiss .L__max_expm1f_arg(%rip),%xmm0         ##if(x > max_expm1_arg)
    ja .L__y_is_inf
    jp .L__y_is_nan
    vucomiss .L__log_OnePlus_OneByFour(%rip),%xmm0 ##if(x < log_OnePlus_OneByFour)
    jae .L__Normal_Flow
    vucomiss .L__log_OneMinus_OneByFour(%rip),%xmm0 ##if(x > log_OneMinus_OneByFour)
    ja .L__Small_Arg
    vucomiss .L__min_expm1f_arg(%rip),%xmm0         ##if(x < min_expm1_arg)
    jb .L__y_is_minusOne
    
    .p2align 4
.L__Normal_Flow:
    #x_double = (double)x;
    vcvtps2pd    %xmm0, %xmm2    #xmm2 = (double)x
    
    # x * (64/ln(2))
    vmulsd       .L__real_64_by_log2(%rip), %xmm2,%xmm3  #xmm3 = x * (64/ln(2)
    
    # n = int( x * (64/ln(2)) )
    vcvtpd2dq    %xmm3, %xmm4  #xmm4 = (int)n
    vcvtdq2pd    %xmm4, %xmm0  #xmm0 = (double)n
    
    # r = x - n * ln(2)/64
    vfmaddsd    %xmm2,.L__real_mlog2_by_64(%rip),%xmm0,%xmm1 #xmm1 = r
    vmovd       %xmm4, %ecx     #ecx = n

    #j = n & 0x3f
    mov         $0x3f, %rax     #rax = 0x3f
    and         %ecx, %eax      #eax = j = n & 0x3f
    # m = (n - j) / 64    
    sar         $6, %ecx        #ecx = m
    
    # q = r+r*r*(1/2 + (1/6 * r))
    vmovhpd       .L__real_1_by_6(%rip), %xmm1,%xmm3  #%xmm3 =1/6,r 
    vmovlhps     %xmm3,%xmm1,%xmm1     #xmm1 = r,r        
    vfmaddpd     .L__real_1_by_2_zero(%rip), %xmm1, %xmm3, %xmm2 #xmm2 = r*r,1/2 + (1/6 * r)
    vmovhlps      %xmm2, %xmm1,%xmm3 #xmm3 = r,r*r
    vfmaddsd     %xmm1,%xmm3,%xmm2,%xmm0 #xmm0 = q
    
    #f
    lea         .L__two_to_jby64_table(%rip), %r10    
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
    vpsrad       $6,%xmm4,%xmm3
    vpsllq       $52,%xmm3,%xmm4
    vpaddq      %xmm1, %xmm4,%xmm2
    vcvtpd2ps   %xmm2, %xmm0
    ret   
	
.p2align 4
.L__Small_Arg:
    #log(1-1/4) < x < log(1+1/4)
	#q = x*x*x*(A1 + x*(A2 + x*(A3 + x*(A4 + x*(A5)))));
	vucomiss .L__minus_zero(%rip), %xmm0
	je     .L__ret
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
.L__ret:
    ret
    
.p2align 4
.L__y_is_minusOne:
    mov         $0xBF800000, %edx
    vmovd       %edx, %xmm0
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
    vaddss  %xmm0,%xmm0,%xmm0
    #call       fname_special
    ret  
    
.data
.align 16
.L__max_expm1f_arg:         .long 0x42B19999
.L__log_OnePlus_OneByFour:  .long 0x3E647FBF
.L__log_OneMinus_OneByFour: .long 0xBE934B11
.L__min_expm1f_arg:         .long 0xC18AA122
.L__real_64_by_log2:        .quad 0x40571547652b82fe # 64/ln(2)
.L__real_mlog2_by_64:       .quad 0xbf862e42fefa39ef # log2_by_64
.L__A1_f:                   .long 0x3E2AAAAA   
.L__A2_f:                   .long 0x3D2AAAA0
.L__A3_f:                   .long 0x3C0889FF     
.L__A4_f:                   .long 0x3AB64DE5
.L__A5_f:                   .long 0x394AB327
.L__minus_zero:             .long 0x80000000
.L__real_1_by_2_zero:           .octa 0x3fe00000000000000000000000000000
