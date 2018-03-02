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
# log1p_bdozr.S
#
# A bulldozer implementation of log1p libm function.
#
# Prototype:
#
#     double log1p(double x);
#

#
#   Algorithm:
#
#   Based on:
#   Ping-Tak Peter Tang
#   "Table-driven implementation of the logarithm function in IEEE
#   floating-point arithmetic"
#   ACM Transactions on Mathematical Software (TOMS)
#   Volume 16, Issue 4 (December 1990)
#
#
#

#include "fn_macros.h"
#include "log_tables.h"
#define fname FN_PROTOTYPE_BDOZR(log1p)


# local variable storage offsets
.equ    p_temp, 0x0
.equ    stack_size, 0x18


#ifdef __ELF__
.section .note.GNU-stack,"",@progbits
#endif

.text
.align 16
.p2align 4,,15
.globl fname
.type fname,@function
fname:

    # compute exponent part
    vmovapd     .L__real_log1p_thresh2(%rip),%xmm12 # xmm12 = log1p_thresh2
    vmovapd     .L__real_log1p_thresh1(%rip),%xmm11 # xmm11 = log1p_thresh1
    vpand        .L__sign_mask_64(%rip),%xmm0,%xmm1
    vcomisd      .L__real_epsilon(%rip),%xmm1 #check for epsilons
    je           .L__x_is_epsilon
    vcomisd      .L__real_minus_one(%rip),%xmm0 #check input less than -1.0
    jb           .L__x_less_than_minus_one
    
    #get the mask for exactly -1.0
    vcomisd       .L__real_minus_one(%rip),%xmm0 # check for input = -1.0
    je           .L__x_is_minus_one
    
    #get the mask for Nans and Infs
    vpand        .L__exp_mask(%rip),%xmm0,%xmm14  # remove the mantissa and sign
    vcomisd     .L__exp_mask(%rip), %xmm14
    je          .L__x_is_inf_or_nan

    #calculate log1p
    # IF (x < log1p_thresh1 || x > log1p_thresh2) 
    vminsd       %xmm12, %xmm0,%xmm3 #max(x,log1p_thresh2)
    vmaxsd       %xmm11, %xmm0,%xmm4 #min(x,log1p_thresh1)
    vcomisd      %xmm4, %xmm3 # if both are equal
    je           .L__inside_the_threshold

.L__outside_the_threshold:    
    #calculate outside the threshold range
    vaddsd       .L__one_mask_64(%rip), %xmm0,%xmm5  #xmm5 = 1.0 +x
    vpand       .L__exp_mask(%rip),%xmm5,%xmm4
    vpsrlq       $52,%xmm4,%xmm4
    #xexp = (int)((ux & EXPBITS_DP64) >> EXPSHIFTBITS_DP64) - EXPBIAS_DP64 - expadjust;
    vpsubq       .L__mask_1023(%rip),%xmm4,%xmm4
     
    #index = (int)((((ux & 0x000fc00000000000) | 0x0010000000000000) >> 46) + ((ux & 0x0000200000000000) >> 45));
    vpand        .L__index_mask1(%rip), %xmm5, %xmm6
    vpand        .L__index_mask2(%rip), %xmm5, %xmm7
    vpor         .L__index_mask3(%rip), %xmm6, %xmm6
    
    vpsrlq       $45,%xmm7, %xmm7 # ((ux & 0x0000200000000000) >> 45)
    vpsrlq       $46,%xmm6, %xmm6 # (((ux & 0x000fc00000000000) | 0x0010000000000000) >> 46)
    vpaddq       %xmm7,%xmm6,%xmm6 # index = xmm6
    vcvtdq2pd    %xmm6,%xmm7
    
    vmulsd       .L__index_constant1(%rip),%xmm7,%xmm7 # f1 =index*0.0078125
    vpsubq       .L__index_constant2(%rip),%xmm6,%xmm6 # index -= 64

    vpand        .L__mantissa_mask(%rip),%xmm5,%xmm5
    #PUT_BITS_DP64((ux & MANTBITS_DP64) | ONEEXPBITS_DP64, f);
    vpor         .L__one_mask_64(%rip),%xmm5,%xmm5 # xmm5 = f
    
    vpshufd      $0xF0,%xmm4,%xmm8 # [11 11 00 00] = 0xF0 higher 64 is not concerned here
    vmovapd      .L__plus_sixtyone_minus_two(%rip),%xmm9
    vpcmpgtd     %xmm8,%xmm9,%xmm9 
    vpsrldq      $4,%xmm9,%xmm10 
    # IF (xexp <= -2 || xexp >= MANTLENGTH_DP64 + 8)
    vpandn       %xmm9,%xmm10,%xmm9 # xmm9 stores the mask for all the numbers which lie between -2 and 61

    #vpshufd      $0x50, %xmm10,%xmm9 # [01 01 00 00] = 0x50
    vsubpd       %xmm7,%xmm5,%xmm5 # f2 = f - f1;
    #ELSE
    vmovapd      .L__mask_1023(%rip),%xmm11
    vpsubq        %xmm4,%xmm11,%xmm11
    #ux = (unsigned long long)(0x3ff - xexp) << EXPSHIFTBITS_DP64;
    #PUT_BITS_DP64(ux,m2);
    vpsllq       $52,%xmm11,%xmm11 # xmm11 = m2;
    vsubsd       %xmm7,%xmm11,%xmm13 # (m2 - f1)
    vfmaddsd     %xmm13,%xmm0,%xmm11,%xmm13 # xmm13 =f2
    #xmm7=f1, xmm11 = m2*x
    #f2 = xmm13/xmm5 f1 = xmm7 
    vpcmov       %xmm9,%xmm5,%xmm13,%xmm13
  
    #  z1 = ln_lead_table[index];
    #  q = ln_tail_table[index];
    vmovd        %xmm6,%r10 # move lower order index
    #vpsrldq      $8,%xmm6,%xmm6
    #vmovd        %xmm6,%r11 # move higher order index
    lea         .L__ln_lead_64_table(%rip), %r9
    lea         .L__ln_tail_64_table(%rip), %r8
    vmovlpd      (%r9,%r10,8), %xmm6,%xmm6
    #vmovhpd      (%r9,%r11,8), %xmm6,%xmm6 # xmm6 = z1 = ln_lead_table[index]
    vmovlpd      (%r8,%r10,8), %xmm8, %xmm8
    #vmovhpd      (%r8,%r11,8), %xmm8, %xmm8 # xmm8 = q = ln_tail_table[index]

    vfmaddsd     %xmm7,.L__real_half(%rip),%xmm13,%xmm7 # (f1 + 0.5 * f2);
    vdivsd       %xmm7,%xmm13,%xmm7  # u = f2 / (f1 + 0.5 * f2);
    vmulsd       %xmm7,%xmm7,%xmm5  # v = u*u

    vmovapd      .L__real_cb_3(%rip), %xmm13 # cb_3
    vmovapd      %xmm5,%xmm11 #  
    vfmaddsd  .L__real_cb_2(%rip),%xmm5,%xmm13,%xmm5 # cb_2 + v*cb_3
     
    vfmaddsd  .L__real_cb_1(%rip),%xmm5,%xmm11,%xmm13 # (cb_1 + v * (cb_2 + v * cb_3))
    vmulsd      %xmm13,%xmm11,%xmm5 # poly = (v * (cb_1 + v * (cb_2 + v * cb_3)));
    #poly = xmm5 u = xmm7 q = xmm8
    vfmaddsd    %xmm7,%xmm7,%xmm5,%xmm5
    vaddsd      %xmm5,%xmm8,%xmm5   # z2 = q + (u + u * poly)

    vcvtdq2pd    %xmm4,%xmm4 # xexp (float) 
    vmovapd      %xmm4,%xmm8 # xmm8 = xexp
    vfmaddsd     %xmm6, .L__real_log2_lead(%rip), %xmm4, %xmm4 # r1 = (xexp * log2_lead + z1)
    vfmaddsd    %xmm5, .L__real_log2_tail(%rip), %xmm8, %xmm8 # r2 = (xexp * log2_tail + z2)
    vaddsd       %xmm4,%xmm8, %xmm0 # return r1 + r2
    ret
    ####END of calculating outside the threshold




.L__inside_the_threshold:    
    ####Now calculate when the value lies within the threshold
    #xmm0 still contains the input x = r1
    vmovapd     .L__plus_two(%rip),%xmm9 # xmm9 = 2.0
    vmovapd     .L__real_ca_4(%rip),%xmm10 # xmm10 = ca_4
    vmovapd     .L__real_ca_3(%rip),%xmm15 # xmm15 = ca_3
    vmovapd     .L__real_ca_2(%rip),%xmm12 # xmm12 = ca_2
    vmovapd     .L__real_ca_1(%rip),%xmm11 # xmm11 = ca_1
    vmovapd     %xmm0,%xmm4         #  r1
    vaddsd      %xmm9,%xmm4, %xmm5  # (2.0 + r)
    vdivsd      %xmm5,%xmm4,%xmm6   # xmm6 = u = r / (2.0 + r); 
    vmulsd      %xmm6,%xmm0,%xmm7   # correction = r * u # TBD
    vaddsd      %xmm6,%xmm6, %xmm6  # u = u+ u
    vmulsd      %xmm6,%xmm6,%xmm9   # v = u * u
    #r1 = xmm4 v = xmm9, u = xmm6, correction = xmm7
    vfmaddsd    %xmm15,%xmm10,%xmm9,%xmm10 # (ca_3 + (v * ca_4))
    vfmaddsd    %xmm12,%xmm9,%xmm10,%xmm10 # (ca_2 + v * (ca_3 + v * ca_4))
    vfmaddsd    %xmm11,%xmm9,%xmm10,%xmm10 # (ca_1 + v *  (ca_2 + v * (ca_3 + v * ca_4)))
    vmulsd      %xmm9,%xmm10,%xmm10        # v * (ca_1 + v * (ca_2 + v * (ca_3 + v * ca_4)))
    vfmsubsd    %xmm7,%xmm6,%xmm10,%xmm10  # r2 = (u * v * (ca_1 + v * (ca_2 + v * (ca_3 +  v * ca_4))) - correction) 
    vaddpd      %xmm4,%xmm10,%xmm0
    ret
    #END calculating within the threshold



    #process inputs = 0x3ca0000000000000 epsilon
.L__x_is_epsilon:
    ret

    # now restore if there are some inputs less than -1.0
.L__x_less_than_minus_one:
    vmovapd   .L__real_qnan(%rip), %xmm0
    ret 

    # now restore if there are some inputs with -1.0
.L__x_is_minus_one:
    vmovapd .L__real_ninf(%rip),%xmm0
    ret 

.L__x_is_inf_or_nan:
    # now restore the Nans and Infs
    vpand      .L__sign_bit_64(%rip),%xmm0,%xmm3 # for negative infities we need to set the result as Qnan
    vaddpd     %xmm0,%xmm0,%xmm0
    #so we get the sign bit and move it to the qnan Bit.
    #then OR it with Qnan/inf result
    vpsrlq     $12,%xmm3,%xmm3
    vpor       %xmm3,%xmm0,%xmm0
    ret
    
.data

.align 16
.L__sign_mask_64:     .quad 0x7FFFFFFFFFFFFFFF
                      .quad 0x7FFFFFFFFFFFFFFF
.L__real_epsilon:     .quad 0x3ca0000000000000
                      .quad 0x3ca0000000000000
.L__real_minus_one:   .quad  0xBFF0000000000000
                      .quad  0xBFF0000000000000
.L__exp_mask:         .quad 0x7ff0000000000000   #
                      .quad 0x7ff0000000000000
.L__exponent_compare: .quad 0x7FF000007FF00000  
                      .quad 0x7FF000007FF00000
# The values exp(-1/16)-1 and exp(1/16)-1 */
.L__real_log1p_thresh2: .quad 0x3fb082b577d34ed8 #  6.44944589178594318568e-02;  
                        .quad 0x3fb082b577d34ed8 
.L__real_log1p_thresh1: .quad 0xbfaf0540438fd5c4 # -6.05869371865242201114e-02, 
                        .quad 0xbfaf0540438fd5c4
.L__one_mask_64:      .quad 0x3ff0000000000000 # 1
                      .quad 0x3ff0000000000000
.L__mask_1023:        .quad 0x00000000000003ff
                      .quad 0x00000000000003ff
.L__mantissa_mask:    .quad 0x000FFFFFFFFFFFFF    # mantissa bits
                      .quad 0x000FFFFFFFFFFFFF

.L__index_mask1:      .quad 0x000fc00000000000
                      .quad 0x000fc00000000000
.L__index_mask2:      .quad 0x0000200000000000
                      .quad 0x0000200000000000
.L__index_mask3:      .quad 0x0010000000000000
                      .quad 0x0010000000000000
.L__index_constant1:  .quad 0x3F90000000000000
                      .quad 0x3F90000000000000
.L__index_constant2:  .quad 0x0000000000000040
                      .quad 0x0000000000000040
#.L__plus_sixtyone_minus_two:  .quad 0x0000003D0000003D
#                              .quad 0xFFFFFFFEFFFFFFFE
.L__plus_sixtyone_minus_two:  .quad 0xFFFFFFFE0000003D
                              .quad 0xFFFFFFFEFFFFFFFE
.L__real_half:        .quad 0x3fe0000000000000 # 1/2
                      .quad 0x3fe0000000000000

# Approximating polynomial coefficients for other x 
.L__real_cb_3:       .quad 0x3f6249423bd94741 # 2.23219810758559851206e-03;  
                     .quad 0x3f6249423bd94741
.L__real_cb_2:       .quad 0x3f89999999865ede # 1.24999999978138668903e-02,  
                     .quad 0x3f89999999865ede
.L__real_cb_1:       .quad 0x3fb5555555555557 # 8.33333333333333593622e-02, 
                     .quad 0x3fb5555555555557
.L__real_log2_lead:  .quad 0x3fe62e42e0000000 # log2_lead  6.93147122859954833984e-01
                     .quad 0x3fe62e42e0000000
.L__real_log2_tail:  .quad 0x3e6efa39ef35793c # log2_tail  5.76999904754328540596e-08
                     .quad 0x3e6efa39ef35793c
.L__plus_two:        .quad 0x4000000000000000
                     .quad 0x4000000000000000
# Approximating polynomial coefficients for x near 0.0 
.L__real_ca_4:       .quad 0x3f3c8034c85dfff0 # 4.34887777707614552256e-04,  
                     .quad 0x3f3c8034c85dfff0
.L__real_ca_3:       .quad 0x3f62492307f1519f # 2.23213998791944806202e-03,  
                     .quad 0x3f62492307f1519f
.L__real_ca_2:       .quad 0x3f89999999bac6d4 # 1.25000000037717509602e-02,  
                     .quad 0x3f89999999bac6d4
.L__real_ca_1:       .quad 0x3fb55555555554e6 # 8.33333333333317923934e-02,  
                     .quad 0x3fb55555555554e6
.L__real_qnan:       .quad 0x7ff8000000000000   # qNaN
                     .quad 0x7ff8000000000000
.L__real_ninf:       .quad 0xfff0000000000000   # -inf
                     .quad 0xfff0000000000000
.L__sign_bit_64:     .quad 0x8000000000000000 
                     .quad 0x8000000000000000

