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

#define fname FN_PROTOTYPE_BDOZR(vrd2_exp2)
#ifdef __ELF__
.section .note.GNU-stack,"",@progbits
#endif

.text
.p2align 4
.globl fname
.type fname,@function
fname:

    vmovdqa      %xmm0, %xmm10   # save for later use
    
    # x * (64)
    vmulpd       .L__real_64(%rip), %xmm0,%xmm3

    # n = int( x * (64))
    vcvttpd2dq  %xmm3, %xmm4   #xmm4 = 0,0,(int)n1,(int)n0
    vcvtdq2pd   %xmm4, %xmm3   #xmm3 = (double)n1,n0    
    vmovd       %xmm4, %rcx    #rcx = (int)n1,n0

    # r = x - n * 1/64  
    #r *= ln2;      
    vfmaddpd    %xmm0,.L__mone_by_64(%rip),%xmm3,%xmm1
    vmulpd    .L__ln_2(%rip),%xmm1,%xmm2  #xmm2 = r_1,r_0  
        
    #j = n & 0x3f    
    mov         $0x0000003f0000003f, %rax
    and         %rcx, %rax     #rax = j1,j0
    mov         %eax, %ecx     #rcx = j0
    shr         $32, %rax      #rax = j1        
    # m = (n - j) / 64      
    vpsrad         $6, %xmm4,%xmm5      #xmm5 = 0,0,m1,m0

    # q = r + r^2*1/2 + r^3*1/6 + r^4 *1/24 + r^5*1/120 + r^6*1/720
    # q = r + r*r*(1/2 + r*(1/6+ r*(1/24 + r*(1/120 + r*(1/720)))))
    vmovapd    .L__real_1_by_720(%rip),%xmm3
    vfmaddpd   .L__real_1_by_120(%rip),%xmm3,%xmm2,%xmm3
    vfmaddpd   .L__real_1_by_24(%rip),%xmm3,%xmm2,%xmm3
    vfmaddpd   .L__real_1_by_6(%rip),%xmm3,%xmm2,%xmm3
    vfmaddpd   .L__real_1_by_2(%rip),%xmm3,%xmm2,%xmm3
    vmulpd     %xmm2,%xmm2,%xmm0
    vfmaddpd   %xmm2,%xmm3,%xmm0,%xmm0 
    
    # (f)*(q) + f2 + f1
    lea         .L__two_to_jby64_table(%rip), %rdx        
    lea         .L__two_to_jby64_tail_table(%rip), %r11       
    lea         .L__two_to_jby64_head_table(%rip), %r10    
    vmovsd      (%rdx,%rcx,8), %xmm2
    vmovhpd     (%rdx,%rax,8),%xmm2,%xmm1  #xmm1 = f_1,f_0    
    vmovsd      (%r11,%rcx,8), %xmm2    
    vmovhpd     (%r11,%rax,8), %xmm2,%xmm3 #xmm3 = f2_1,f2_0
    vmovsd      (%r10,%rcx,8), %xmm4
    vmovhpd     (%r10,%rax,8), %xmm4,%xmm2 #xmm2 = f1_1,f1_0           
    vfmaddpd    %xmm3,%xmm1,%xmm0,%xmm4    #xmm4 = f*q + f2
    vaddpd      %xmm4,%xmm2,%xmm0   

    # normal results
    vpmovsxdq   %xmm5,%xmm4       #xmm4 = m1,m0
    vpsllq      $52,%xmm4,%xmm5   #xmm5 = 2^m1,2^m0
    vpaddq      %xmm5,%xmm0,%xmm1 #xmm1 = normal results
  
    #check and process denormals    
    vcmppd      $1,.L__real_one(%rip),%xmm0,%xmm3 #check e^r < 1
    vpcomeqq    .L__m1022(%rip),%xmm5,%xmm2   #check m == -1022
    vpand       %xmm2,%xmm3,%xmm3  #xmm3 = ( e^r < 1 and m = -1022 )           
    vpcomltq    .L__m1022(%rip),%xmm5,%xmm2   #check m < -1022    
    vpor        %xmm3,%xmm2,%xmm2   #xmm2 = mask for inputs requiring denormal processing
    vpmovmskb   %xmm2,%eax
    cmp         $0,%eax
    je          .L__check_min   #jmp to avoid any accidental intermediate denormal results    
    vpaddq      .L__ulong_1074(%rip),%xmm4,%xmm3 #xmm3 = 1074 + m        
    vpshlq      %xmm3,.L__ulong_1(%rip),%xmm4
    vmulpd      %xmm4,%xmm0,%xmm3  #xmm3 = results for denormal numbers
    vpcmov      %xmm2,%xmm1,%xmm3,%xmm1
  
.L__check_min:   
    ##special case for any x < min_exp_arg,remove this code if the above code takes care of this
    vcmppd       $2,.L__min_exp2_arg(%rip),%xmm10,%xmm2 #cmp x<= min_exp_arg
    vpxor        %xmm3,%xmm3,%xmm4  #make zeros to put in place of x<= min_exp_arg
    vpcmov       %xmm2,%xmm1,%xmm4,%xmm1 #put zeros in place of any x <= min_exp_arg 
        
    ##special case for any x > max_exp_arg,remove this code if the above code takes care of this
    vcmppd       $1,.L__max_exp2_arg(%rip),%xmm10,%xmm2 #cmp x < max_exp_arg
    vmovdqa     .L__real_inf(%rip), %xmm3  #inf to put in place of any x >= max_exp_arg
    vpcmov       %xmm2,%xmm3,%xmm1,%xmm1 #xmm1 = normal results
    
    ##special case for any x = nan,remove this code if the above code takes care of this
    vcmppd       $0x0,%xmm10,%xmm10,%xmm2    
    vaddpd       %xmm10, %xmm10,%xmm3  #make qnan to put in place of any x =nan
    vpcmov       %xmm2,%xmm3,%xmm1,%xmm0 #xmm0 = normal results
    ret 
    
.data
.align 16
.L__max_exp2_arg:            .octa 0x40900000000000004090000000000000
.L__min_exp2_arg:            .octa 0xc090c80000000000c090c80000000000
.L__real_64:                 .octa 0x40500000000000004050000000000000    # 64
.L__ln_2:                    .octa 0x3FE62E42FEFA39EF3FE62E42FEFA39EF
.L__mone_by_64:              .octa 0xbF90000000000000bF90000000000000
.L__real_one:                .octa 0x3ff00000000000003ff0000000000000
.L__real_inf:                .octa 0x7ff00000000000007ff0000000000000
.L__m1022:                        .octa 0xc020000000000000c020000000000000
.L__ulong_1074:                   .octa 0x00000000000004320000000000000432
.L__ulong_1:                      .octa 0x00000000000000010000000000000001
