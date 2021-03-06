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

#define fname FN_PROTOTYPE_BDOZR(vrs4_exp2f)
#ifdef __ELF__
.section .note.GNU-stack,"",@progbits
#endif

.text
.p2align 4
.globl fname
.type fname,@function
fname:
    vmovdqa       %xmm0, %xmm5   # save for later use
    vminps        .L__max_exp2f_arg(%rip),%xmm0,%xmm0
    vcvtps2pd     %xmm0, %ymm2    #ymm2 = (double)x3,x2,x1,x0

    # x * (64)
    vmulpd       .L__sixtyfour(%rip), %ymm2, %ymm3 #ymm3 = x3 * (64/ln(2),x2 * (64/ln(2),x1 * (64/ln(2),x0 * (64/ln(2)

    # n = int( x * (64)
    vcvtpd2dq    %ymm3, %xmm4  #xmm4 = (int)n3,n2,n1,n0 
    vcvtdq2pd    %xmm4, %ymm0  #ymm0 = (double)n3,n2,n1,n0 
    
    # r = x - n * 1/64
    # r *= ln(2)
    vfmaddpd    %ymm2,.L__mone_by_64(%rip),%ymm0,%ymm1 #ymm1 = r3,r2,r1,r0
    vmulpd      .L__ln2(%rip),%ymm1,%ymm1 #ymm1 = r = r*ln(2)        

    # q
    vmovdqa     .L__real_4_1_by_6s(%rip), %ymm3
    vfmaddpd    .L__real_4_1_by_2s(%rip),%ymm3,%ymm1,%ymm2 #ymm2 = (1/2 + (1/6 * r))
    vmulpd       %ymm1,%ymm1,%ymm3   #ymm3 = r3*r3,r2*r2,r1*r1,r0*r0
    vfmaddpd     %ymm1,%ymm3,%ymm2,%ymm0 #ymm0 = q3,q2,q1,q0    
    
    #j = n & 0x3f
    vpsrad      $6,%xmm4,%xmm1    #xmm1 = m3,m2,m1,m0
    vpslld      $26,%xmm4,%xmm3   
    vpsrld      $26,%xmm3,%xmm4   #xmm4 = j3,j2,j1,j0        
    
    # f + (f*q)
    lea         .L__two_to_jby64_table(%rip), %r10
    vmovd        %xmm4,%eax      #eax = j0
    vpsrldq      $4,%xmm4,%xmm3  #xmm3 = XX,j3,j2,j1
    vmovd        %xmm3,%ecx      #ecx = j1
    vmovsd      (%r10,%rax,8), %xmm2
    vmovhpd     (%r10,%rcx,8), %xmm2,%xmm2  #xmm2 = f1,f0    
    vpsrldq      $4,%xmm3,%xmm4  #xmm4 = XX,XX,j3,j2
    vmovd        %xmm4,%eax      #eax = j2
    vpsrldq      $4,%xmm4,%xmm3  #xmm3 = XX,XX,XX,j3
    vmovd        %xmm3,%ecx      #ecx = j3
    vmovsd      (%r10,%rax,8), %xmm3
    vmovhpd     (%r10,%rcx,8), %xmm3,%xmm3  #xmm3 = f3,f2    
    vinsertf128  $1,%xmm3,%ymm2,%ymm2  #ymm2 = f3,f2,f1,f0
    vfmaddpd     %ymm2,%ymm0,%ymm2,%ymm3   #ymm3 = f + (f*q)

    # m = (n - j) / 64       
    vpmovsxdq   %xmm1,%xmm2      #xmm2 = m1,m0     
    vpsllq      $52,%xmm2,%xmm0 #xmm0 = 2^m1,2^m0
    vpsrldq     $8,%xmm1,%xmm2   #xmm2 = XX,XX,m3,m2
    vpmovsxdq   %xmm2,%xmm1      #xmm1 = m3,m2
    vpsllq      $52,%xmm1,%xmm2  #xmm2 = 2^m3,2^m2     
    
    #2 ^m * (f + (f*q))
    vextractf128   $1,%ymm3,%xmm1
    vpaddq      %xmm3,%xmm0,%xmm0
    vpaddq      %xmm1,%xmm2,%xmm1
    vinsertf128    $1,%xmm1,%ymm0,%ymm2
    vcvtpd2ps   %ymm2, %xmm0

    ##special case for any x < min_exp_arg
    ##remove this code if the above code takes care of this
    vmovdqa      .L__min_exp2f_arg(%rip), %xmm1        
    vcmpps       $1,%xmm5,%xmm1,%xmm2
    vpand        %xmm2, %xmm0,%xmm1   #put zeros in place of any x < min_exp2_arg     
    
    ##special case for any x = nan
    ##remove this code if the above code takes care of this
    vcmpps      $0x0,%xmm5,%xmm5,%xmm2
    vaddps      %xmm5, %xmm5,%xmm3  #make qnan to put in place of any x =nan    
    vpcmov      %xmm2, %xmm3,%xmm1,%xmm0
    ret           
    
.data
.align 16
.L__max_exp2f_arg:              .octa 0x43000000430000004300000043000000
.L__min_exp2f_arg:              .octa 0xc3150000c3150000c3150000c3150000

.align 32
.L__sixtyfour:                  .octa 0x40500000000000004050000000000000 # 64
                                .octa 0x40500000000000004050000000000000
.L__mone_by_64:                 .octa 0xbF90000000000000bF90000000000000 # 1/64
                                .octa 0xbF90000000000000bF90000000000000 # 1/64
.L__ln2:                        .octa 0x3FE62E42FEFA39EF3FE62E42FEFA39EF # ln(2)
                                .octa 0x3FE62E42FEFA39EF3FE62E42FEFA39EF # ln(2)
.L__real_4_1_by_2s:             .octa 0x3fe00000000000003fe0000000000000
                                .octa 0x3fe00000000000003fe0000000000000                                 
.L__real_4_1_by_6s:             .octa 0x3fc55555555555553fc5555555555555    # 1/6
                                .octa 0x3fc55555555555553fc5555555555555                                