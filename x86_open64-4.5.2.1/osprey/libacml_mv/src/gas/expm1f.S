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

#define fname FN_PROTOTYPE_BAS64(expm1f)
WEAK_ACML_LIB_ALIAS fastexpm1f, FN_PROTOTYPE(expm1f)
#ifdef __ELF__
    .section .note.GNU-stack,"",@progbits
#endif

.text
.p2align 4
.globl fname
.type	fname, @function
fname:
    ucomiss .L__max_expm1f_arg(%rip),%xmm0         ##if(x > max_expm1_arg)
    ja .L__y_is_inf
    jp .L__y_is_nan
    ucomiss .L__log_OnePlus_OneByFour(%rip),%xmm0 ##if(x < log_OnePlus_OneByFour)
    jae .L__Normal_Flow
    ucomiss .L__log_OneMinus_OneByFour(%rip),%xmm0 ##if(x > log_OneMinus_OneByFour)
    ja .L__Small_Arg
    ucomiss .L__min_expm1f_arg(%rip),%xmm0         ##if(x < min_expm1_arg)
    jb .L__y_is_minusOne
    
    .p2align 4
.L__Normal_Flow:
    #x_double = (double)x;
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

    #j = n & 0x3f
    mov         $0x3f, %rax     #rax = 0x3f
    and         %ecx, %eax      #eax = j = n & 0x3f
    # m = (n - j) / 64    
    sar         $6, %ecx        #ecx = m
    
    # q
    movsd       .L__real_1_by_6(%rip), %xmm3 
    mulsd       %xmm0, %xmm3 #xmm3 = 1/6 * r
    mulsd       %xmm1, %xmm0 #xmm0 =  r  * r
    addsd       .L__real_1_by_2(%rip), %xmm3 #xmm3 = 1/2 + (1/6 * r)
    mulsd       %xmm3, %xmm0  #xmm0 = r*r*(1/2 + (1/6 * r))
    addsd       %xmm1, %xmm0  #xmm0 = r+r*r*(1/2 + (1/6 * r))
    
    #f
    lea         .L__two_to_jby64_table(%rip), %r10    
    movsd       (%r10,%rax,8), %xmm2 #xmm2 = f
    
    #f*q
    mulsd       %xmm2, %xmm0  #xmm0 = f*q
    
    #twopmm.u64 = (1023 - (long)m) << 52;    
    #f - twopmm
    mov         $1023, %eax
    sub         %ecx, %eax
    shl         $52, %rax    
    movd        %rax, %xmm1
    subsd       %xmm1, %xmm2
    
    #z = f * q + (f - twopmm.f64) ;
    #z = z* 2^m
    addsd       %xmm2, %xmm0    
    shl         $52, %rcx
    movd        %rcx, %xmm1
    paddq       %xmm0, %xmm1
    cvtpd2ps    %xmm1, %xmm0
    ret
	
.p2align 4
.L__Small_Arg:
    #log(1-1/4) < x < log(1+1/4)
	#q = x*x*x*(A1 + x*(A2 + x*(A3 + x*(A4 + x*(A5)))));
	ucomiss .L__minus_zero(%rip), %xmm0
	je     .L__ret
	movdqa %xmm0,%xmm1
	mulss .L__A5_f(%rip),%xmm1
	addss .L__A4_f(%rip),%xmm1
	mulss %xmm0,%xmm1
	addss .L__A3_f(%rip),%xmm1
	mulss %xmm0,%xmm1
	addss .L__A2_f(%rip),%xmm1
	mulss %xmm0,%xmm1
	addss .L__A1_f(%rip),%xmm1
	mulss %xmm0,%xmm1
	mulss %xmm0,%xmm1
	mulss %xmm0,%xmm1	
	cvtps2pd %xmm0,%xmm2
	movdqa %xmm2,%xmm0
	mulsd %xmm0,%xmm2	
	mulsd .L__real_1_by_2(%rip),%xmm2
	addsd %xmm2,%xmm0
	cvtps2pd %xmm1,%xmm2
	addsd %xmm0,%xmm2
	cvtpd2ps %xmm2,%xmm0	    
.L__ret:
    ret
    
.p2align 4
.L__y_is_minusOne:
    mov         $0xBF800000, %edx
    movd        %edx, %xmm1     #return value in xmm1,input in xmm0 before calling
    mov         $2, %edi        #code in edi
    #call       fname_special
    movdqa      %xmm1,%xmm0     #remove this if calling fname special
    ret     
    
.p2align 4
.L__y_is_inf:
    mov         $0x7f800000,%edx
    movd        %edx, %xmm1
    mov         $3, %edi
    #call        fname_special
    movdqa     %xmm1,%xmm0#remove this if calling fname special
    ret     

.p2align 4
.L__y_is_nan:
    movaps %xmm0,%xmm1
    addss  %xmm1,%xmm1
    mov         $1, %edi
    #call        fname_special
    movdqa %xmm1,%xmm0  #remove this if calling fname special
    ret 
    
.data
.align 16
.L__max_expm1f_arg:         .long 0x42B19999
.L__log_OnePlus_OneByFour:  .long 0x3E647FBF
.L__log_OneMinus_OneByFour: .long 0xBE934B11
.L__min_expm1f_arg:         .long 0xC18AA122
.L__real_64_by_log2:        .quad 0x40571547652b82fe # 64/ln(2)
.L__real_log2_by_64:        .quad 0x3f862e42fefa39ef # log2_by_64
.L__A1_f:                   .long 0x3E2AAAAA   
.L__A2_f:                   .long 0x3D2AAAA0
.L__A3_f:                   .long 0x3C0889FF     
.L__A4_f:                   .long 0x3AB64DE5
.L__A5_f:                   .long 0x394AB327
.L__minus_zero:             .long 0x80000000
