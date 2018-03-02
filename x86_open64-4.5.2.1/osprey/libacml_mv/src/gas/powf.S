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
#  (C) 2008-2010 Advanced Micro Devices, Inc. All Rights Reserved.
#
#  This file is part of AMD LibM 2.1.
#
#  AMD LibM 2.1 is free software; you can redistribute it and/or
#  modify it under the terms of the GNU Lesser General Public
#  License as published by the Free Software Foundation; either
#  version 2.1 of the License, or (at your option) any later version.
#
#  AMD LibM 2.1 is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#  Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public
#  License along with AMD LibM 2.1.  If not, see
#  <http://www.gnu.org/licenses/>.
#
#


# powf.S
#
# An implementation of the powf libm function.
#
# Prototype:
#
#     float powf(float x, float y);
#

#
#   Algorithm:
#       x^y = e^(y*ln(x))
#
#       Look in exp, log for the respective algorithms
#

#include "fn_macros.h"
#include "weak_macros.h"
#define fname FN_PROTOTYPE(powf)
#define fname_special _powf_special@PLT

WEAK_ACML_LIB_ALIAS fastpowf, FN_PROTOTYPE(powf)

# local variable storage offsets
.equ    save_x, 0x0
.equ    save_y, 0x10
.equ    p_temp_exp, 0x20
.equ    negate_result, 0x30
.equ    save_ax, 0x40
.equ    y_intrmdt, 0x50
.equ    p_temp_log, 0x60
.equ    x_intrmdt, 0x70
.equ    stack_size, 0x88


#ifdef __ELF__
.section .note.GNU-stack,"",@progbits
#endif

.text
.align 16
.p2align 4,,15
.globl fname
.type fname,@function
#include "weak_macros.h"
WEAK_MATH_LIB_ALIAS powf,fname
WEAK_MATH_LIB_ALIAS fastpowf,fname
fname:

    sub         $stack_size, %rsp

    movss       %xmm0, save_x(%rsp)
    movss       %xmm1, save_y(%rsp)

    movd        %xmm0, %edx
    movd        %xmm1, %r8d

    andpd       .L__f32_exp_mant_mask(%rip), %xmm0
    movss       %xmm1, %xmm7

    # -----------------------------
    # compute log(x) here
    # -----------------------------
.L__log_x:

    cvtss2sd    %xmm0, %xmm0
    cvtss2sd    %xmm7, %xmm7

    # compute exponent part
    xor         %r10, %r10
    movdqa      %xmm0, %xmm3
    movsd       %xmm7, y_intrmdt(%rsp)
    psrlq       $52, %xmm3
    movd        %xmm0, %r10
    psubq       .L__mask_1023(%rip), %xmm3
    movdqa      %xmm0, %xmm2
    cvtdq2pd    %xmm3, %xmm6 # xexp
    pand        .L__real_mant(%rip), %xmm2

    # compute index into the log tables
    mov         %r10, %r9
    and         .L__mask_mant_all8(%rip), %r10
    and         .L__mask_mant9(%rip), %r9
    shl         %r9
    add         %r9, %r10
    mov         %r10, p_temp_log(%rsp)

    movsd       %xmm0, %xmm7
    movsd       %xmm0, %xmm4

    # F, Y
    movsd       p_temp_log(%rsp), %xmm1
    shr         $44, %r10
    por         .L__real_half(%rip), %xmm2
    por         .L__real_half(%rip), %xmm1
    lea         .L__log_F_inv(%rip), %r9

    # f = F - Y, r = f * inv
    subsd       %xmm2, %xmm1
    mulsd       (%r9,%r10,8), %xmm1
    movsd       %xmm1, %xmm2
    movsd       %xmm1, %xmm3

    lea         .L__log_256_table(%rip), %r9
    movsd       .L__real_log2(%rip), %xmm5
    movsd       (%r9,%r10,8), %xmm0

    # poly
    mulsd       .L__real_1_over_3(%rip), %xmm3

    # special case divert
    test        .L__f32_exp_mant_mask(%rip), %r8d
    jz          .L__y_is_zero

    mulsd       %xmm2, %xmm1
    addsd       .L__real_1_over_2(%rip), %xmm3

    # special case divert
    cmp         .L__f32_pos_one(%rip), %r8d
    je          .L__y_is_one

    mulsd       %xmm1, %xmm3
    subsd       .L__real_one(%rip), %xmm7

    # special case divert
    xor         %eax, %eax
    test        .L__f32_sign_mask(%rip), %edx
    mov         %eax, negate_result(%rsp)
    jnz         .L__x_is_neg

.L__return_x_neg:

    addsd       %xmm2, %xmm3
    mulsd       %xmm6, %xmm5

    # special case divert
    andpd       .L__real_notsign(%rip), %xmm7
    comisd      .L__real_threshold(%rip), %xmm7
    jb          .L__near_one

    subsd       %xmm3, %xmm0
    addsd       %xmm5, %xmm0

.L__return_from_near_one:

    mulsd       y_intrmdt(%rsp), %xmm0
 
    # v = y * ln(x)
    # xmm0 - v

    # -----------------------------
    # compute exp( y * ln(x) ) here
    # -----------------------------

    # x * (64/ln(2))
    movsd       .L__real_64_by_log2(%rip), %xmm7
    movsd       %xmm0, p_temp_exp(%rsp)
    mulsd       %xmm0, %xmm7

    # v < 128*ln(2), ( v * (64/ln(2)) ) < 64*128
    # v >= -150*ln(2), ( v * (64/ln(2)) ) >= 64*(-150)
    comisd      .L__real_p8192(%rip), %xmm7
    jae         .L__process_result_inf

    comisd      .L__real_m9536(%rip), %xmm7
    jb          .L__process_result_zero

    # n = int( v * (64/ln(2)) )
    cvtpd2dq    %xmm7, %xmm4
    lea         .L__two_to_jby64_table(%rip), %r9
    cvtdq2pd    %xmm4, %xmm1

    # r = x - n * ln(2)/64
    movsd       .L__real_log2_by_64(%rip), %xmm2
    mulsd       %xmm1, %xmm2
    movd        %xmm4, %ecx
    mov         $0x3f, %r10
    and         %ecx, %r10d
    subsd       %xmm2, %xmm0
    movsd       %xmm0, %xmm1

    # m = (n - j) / 64
    sub         %r10d, %ecx
    sar         $6, %ecx

    # q
    mulsd       .L__real_1_by_6(%rip), %xmm3
    mulsd       %xmm0, %xmm1

    # special case divert
    test        .L__f32_exp_mant_mask(%rip), %edx
    je          .L__x_is_zero
    
    addsd       .L__real_1_by_2(%rip), %xmm3
    mulsd       %xmm1, %xmm3

    # special case divert
    mov         .L__f32_exp_mask(%rip), %eax
    and         %r8d, %eax
    cmp         .L__f32_ay_max_bound(%rip), %eax
    jg          .L__ay_is_very_large

    addsd       %xmm3, %xmm0

    # special case divert
    cmp         .L__f32_ay_min_bound(%rip), %eax
    jl          .L__ay_is_very_small
    
    add         $1023, %rcx
    shl         $52, %rcx

    # (f)*(1+q)
    movsd       (%r9,%r10,8), %xmm1
    mulsd       %xmm1, %xmm0
    addsd       %xmm1, %xmm0

    mov         %rcx, p_temp_exp(%rsp)
    mulsd       p_temp_exp(%rsp), %xmm0
    cvtsd2ss    %xmm0, %xmm0
    orps        negate_result(%rsp), %xmm0

.L__final_check:
    add         $stack_size, %rsp
    ret

.p2align 4,,15
.L__process_result_zero:

    # special case divert
    mov         .L__f32_exp_mask(%rip), %eax
    and         %r8d, %eax
    cmp         .L__f32_ay_max_bound(%rip), %eax
    jg          .L__ay_is_very_large

    mov         .L__f32_real_zero(%rip), %r11d
    or          negate_result(%rsp), %r11d
    jmp         .L__z_is_zero_or_inf
 
.p2align 4,,15
.L__process_result_inf:

    # special case divert
    mov         .L__f32_exp_mask(%rip), %eax
    and         %r8d, %eax
    cmp         .L__f32_ay_max_bound(%rip), %eax
    jg          .L__ay_is_very_large

    mov         .L__f32_real_inf(%rip), %r11d
    or          negate_result(%rsp), %r11d
    jmp         .L__z_is_zero_or_inf


.p2align 4,,15
.L__x_is_neg:

    movsd       %xmm4, x_intrmdt(%rsp)

    movss       save_y(%rsp), %xmm1
    mov         .L__f32_exp_mask(%rip), %r10d
    and         %r8d, %r10d

    # determine if y is an integer
    cvtss2si    %xmm1, %ecx
    cmp         $0x4b000000, %r10d
    cvtsi2ss    %ecx, %xmm4
    jg          .L__continue_x_is_neg

    comiss      %xmm1, %xmm4
    mov         $0, %r10d
    jne         .L__x_is_neg_y_is_not_int

    mov         .L__f32_sign_mask(%rip), %eax
    and         $0x1, %ecx
    cmovnz      %eax, %r10d
    mov         %r10d, negate_result(%rsp)

.L__continue_x_is_neg:

    cmp         .L__f32_neg_one(%rip), %edx
    je          .L__x_is_neg_one

    andpd       .L__real_notsign(%rip), %xmm7
    comisd      .L__real_threshold(%rip), %xmm7
    movsd       x_intrmdt(%rsp), %xmm4
    jb          .L__near_one
    
    jmp         .L__return_x_neg 


.p2align 4,,15
.L__near_one:

    mov         .L__f32_exp_mant_mask(%rip), %r11d
    and         %edx, %r11d
    cmp         .L__f32_exp_mask(%rip), %r11d
    jge         .L__x_is_inf_or_nan

    # special case divert
    cmp         .L__f32_pos_one(%rip), %edx
    je          .L__x_is_pos_one

    movsd       %xmm4, %xmm0

    # r = x - 1.0
    movsd       .L__real_two(%rip), %xmm2
    subsd       .L__real_one(%rip), %xmm0 # r

    addsd       %xmm0, %xmm2
    movsd       %xmm0, %xmm1
    divsd       %xmm2, %xmm1 # r/(2+r) = u/2

    movsd       .L__real_ca2(%rip), %xmm4
    movsd       .L__real_ca4(%rip), %xmm5

    movsd       %xmm0, %xmm6
    mulsd       %xmm1, %xmm6 # correction

    addsd       %xmm1, %xmm1 # u
    movsd       %xmm1, %xmm2

    mulsd       %xmm1, %xmm2 # u^2

    mulsd       %xmm2, %xmm4
    mulsd       %xmm2, %xmm5

    addsd       .L__real_ca1(%rip), %xmm4
    addsd       .L__real_ca3(%rip), %xmm5

    mulsd       %xmm1, %xmm2 # u^3
    mulsd       %xmm2, %xmm4

    mulsd       %xmm2, %xmm2
    mulsd       %xmm1, %xmm2 # u^7
    mulsd       %xmm2, %xmm5

    addsd       %xmm5, %xmm4
    subsd       %xmm6, %xmm4
    addsd       %xmm4, %xmm0

    jmp         .L__return_from_near_one

.p2align 4,,15
.L__x_is_pos_one:
    movd        %edx, %xmm0
    xor         %eax, %eax
    mov         .L__f32_exp_mask(%rip), %r10d
    and         %r8d, %r10d
    cmp         .L__f32_exp_mask(%rip), %r10d
    cmove       %r8d, %eax
    mov         .L__f32_mant_mask(%rip), %r10d
    and         %eax, %r10d
    jz          .L__final_check

    mov         .L__f32_qnan_set(%rip), %r10d
    and         %r8d, %r10d
    jnz         .L__final_check

    movss       save_x(%rsp), %xmm0
    movss       save_y(%rsp), %xmm1
    movss       .L__f32_pos_one(%rip), %xmm2
    mov         .L__flag_x_one_y_snan(%rip), %edi

    call        fname_special
    jmp         .L__final_check      

.p2align 4,,15
.L__y_is_zero:

    xor         %eax, %eax
    mov         .L__f32_exp_mask(%rip), %r9d
    mov         .L__f32_pos_one(%rip), %r11d
    and         %edx, %r9d
    cmp         .L__f32_exp_mask(%rip), %r9d
    cmove       %edx, %eax
    mov         .L__f32_mant_mask(%rip), %r9d
    and         %eax, %r9d
    jnz         .L__x_is_nan

    movss       .L__f32_pos_one(%rip), %xmm0
    jmp         .L__final_check

.p2align 4,,15
.L__y_is_one:
    xor         %eax, %eax
    mov         %edx, %r11d
    mov         .L__f32_exp_mask(%rip), %r9d
    or          .L__f32_qnan_set(%rip), %r11d
    and         %edx, %r9d
    cmp         .L__f32_exp_mask(%rip), %r9d
    cmove       %edx, %eax
    mov         .L__f32_mant_mask(%rip), %r9d
    and         %eax, %r9d
    jnz         .L__x_is_nan

    movd        %edx, %xmm0 
    jmp         .L__final_check

.p2align 4,,15
.L__x_is_neg_one:
    mov         .L__f32_pos_one(%rip), %edx
    or          negate_result(%rsp), %edx
    xor         %eax, %eax
    mov         %r8d, %r11d
    mov         .L__f32_exp_mask(%rip), %r10d
    or          .L__f32_qnan_set(%rip), %r11d
    and         %r8d, %r10d
    cmp         .L__f32_exp_mask(%rip), %r10d
    cmove       %r8d, %eax
    mov         .L__f32_mant_mask(%rip), %r10d
    and         %eax, %r10d
    jnz         .L__y_is_nan

    movd        %edx, %xmm0
    jmp         .L__final_check

.p2align 4,,15
.L__x_is_neg_y_is_not_int:
    mov         .L__f32_exp_mask(%rip), %r9d
    and         %edx, %r9d
    cmp         .L__f32_exp_mask(%rip), %r9d
    je          .L__x_is_inf_or_nan

    cmp         .L__f32_neg_zero(%rip), %edx
    je          .L__x_is_zero

    movss       save_x(%rsp), %xmm0
    movss       save_y(%rsp), %xmm1
    movss       .L__f32_qnan(%rip), %xmm2
    mov         .L__flag_x_neg_y_notint(%rip), %edi

    call        fname_special
    jmp         .L__final_check

.p2align 4,,15
.L__ay_is_very_large:
    mov         .L__f32_exp_mask(%rip), %r9d
    and         %edx, %r9d
    cmp         .L__f32_exp_mask(%rip), %r9d
    je          .L__x_is_inf_or_nan

    mov         .L__f32_exp_mant_mask(%rip), %r9d
    and         %edx, %r9d
    jz          .L__x_is_zero 

    cmp         .L__f32_neg_one(%rip), %edx
    je          .L__x_is_neg_one

    mov         %edx, %r9d
    and         .L__f32_exp_mant_mask(%rip), %r9d
    cmp         .L__f32_pos_one(%rip), %r9d
    jl          .L__ax_lt1_y_is_large_or_inf_or_nan
  
    jmp         .L__ax_gt1_y_is_large_or_inf_or_nan

.p2align 4,,15
.L__x_is_zero:
    mov         .L__f32_exp_mask(%rip), %r10d
    xor         %eax, %eax
    and         %r8d, %r10d
    cmp         .L__f32_exp_mask(%rip), %r10d
    je          .L__x_is_zero_y_is_inf_or_nan

    mov         .L__f32_sign_mask(%rip), %r10d
    and         %r8d, %r10d
    cmovnz      .L__f32_pos_inf(%rip), %eax
    jnz         .L__x_is_zero_z_is_inf

    movd        %eax, %xmm0
    orps        negate_result(%rsp), %xmm0
    jmp         .L__final_check

.p2align 4,,15
.L__x_is_zero_z_is_inf:

    movss       save_x(%rsp), %xmm0
    movss       save_y(%rsp), %xmm1
    movd        %eax, %xmm2
    orps        negate_result(%rsp), %xmm2
    mov         .L__flag_x_zero_z_inf(%rip), %edi

    call        fname_special
    jmp         .L__final_check    

.p2align 4,,15
.L__x_is_zero_y_is_inf_or_nan:
    mov         %r8d, %r11d
    cmp         .L__f32_neg_inf(%rip), %r8d
    cmove       .L__f32_pos_inf(%rip), %eax
    je          .L__x_is_zero_z_is_inf

    or          .L__f32_qnan_set(%rip), %r11d
    mov         .L__f32_mant_mask(%rip), %r10d
    and         %r8d, %r10d
    jnz         .L__y_is_nan

    movd        %eax, %xmm0
    jmp         .L__final_check

.p2align 4,,15
.L__x_is_inf_or_nan:
    xor         %r11d, %r11d
    mov         .L__f32_sign_mask(%rip), %r10d
    and         %r8d, %r10d
    cmovz       .L__f32_pos_inf(%rip), %r11d
    mov         %edx, %eax
    mov         .L__f32_mant_mask(%rip), %r9d
    or          .L__f32_qnan_set(%rip), %eax
    and         %edx, %r9d
    cmovnz      %eax, %r11d
    jnz         .L__x_is_nan

    xor         %eax, %eax
    mov         %r8d, %r9d
    mov         .L__f32_exp_mask(%rip), %r10d
    or          .L__f32_qnan_set(%rip), %r9d
    and         %r8d, %r10d
    cmp         .L__f32_exp_mask(%rip), %r10d
    cmove       %r8d, %eax
    mov         .L__f32_mant_mask(%rip), %r10d
    and         %eax, %r10d
    cmovnz      %r9d, %r11d
    jnz         .L__y_is_nan

    movd        %r11d, %xmm0
    orps        negate_result(%rsp), %xmm0
    jmp         .L__final_check

.p2align 4,,15
.L__ay_is_very_small:
    movss       .L__f32_pos_one(%rip), %xmm0
    addss       save_y(%rsp), %xmm0
    jmp         .L__final_check


.p2align 4,,15
.L__ax_lt1_y_is_large_or_inf_or_nan:
    xor         %r11d, %r11d
    mov         .L__f32_sign_mask(%rip), %r10d
    and         %r8d, %r10d
    cmovnz      .L__f32_pos_inf(%rip), %r11d
    jmp         .L__adjust_for_nan

.p2align 4,,15
.L__ax_gt1_y_is_large_or_inf_or_nan:
    xor         %r11d, %r11d
    mov         .L__f32_sign_mask(%rip), %r10d
    and         %r8d, %r10d
    cmovz       .L__f32_pos_inf(%rip), %r11d

.p2align 4,,15
.L__adjust_for_nan:

    xor         %eax, %eax
    mov         %r8d, %r9d
    mov         .L__f32_exp_mask(%rip), %r10d
    or          .L__f32_qnan_set(%rip), %r9d
    and         %r8d, %r10d
    cmp         .L__f32_exp_mask(%rip), %r10d
    cmove       %r8d, %eax
    mov         .L__f32_mant_mask(%rip), %r10d
    and         %eax, %r10d
    cmovnz      %r9d, %r11d
    jnz         .L__y_is_nan

    test        %eax, %eax
    jnz         .L__y_is_inf

.p2align 4,,15
.L__z_is_zero_or_inf:

    mov         .L__flag_z_zero(%rip), %edi
    test        %r11d, %r11d
    cmovnz      .L__flag_z_inf(%rip), %edi
    
    movss       save_x(%rsp), %xmm0
    movss       save_y(%rsp), %xmm1
    movd        %r11d, %xmm2

    call        fname_special
    jmp         .L__final_check

.p2align 4,,15
.L__y_is_inf:

    movd        %r11d, %xmm0
    jmp         .L__final_check

.p2align 4,,15
.L__x_is_nan:

    xor         %eax, %eax
    mov         .L__f32_exp_mask(%rip), %r10d
    and         %r8d, %r10d
    cmp         .L__f32_exp_mask(%rip), %r10d
    cmove       %r8d, %eax
    mov         .L__f32_mant_mask(%rip), %r10d
    and         %eax, %r10d
    jnz         .L__x_is_nan_y_is_nan

    mov         .L__f32_qnan_set(%rip), %r9d
    and         %edx, %r9d
    movd        %r11d, %xmm0
    jnz         .L__final_check

    movss       save_x(%rsp), %xmm0
    movss       save_y(%rsp), %xmm1
    movd        %r11d, %xmm2
    mov         .L__flag_x_nan(%rip), %edi

    call        fname_special
    jmp         .L__final_check

.p2align 4,,15
.L__y_is_nan:

    mov         .L__f32_qnan_set(%rip), %r10d
    and         %r8d, %r10d
    movd        %r11d, %xmm0
    jnz         .L__final_check

    movss       save_x(%rsp), %xmm0
    movss       save_y(%rsp), %xmm1
    movd        %r11d, %xmm2
    mov         .L__flag_y_nan(%rip), %edi

    call        fname_special
    jmp         .L__final_check

.p2align 4,,15
.L__x_is_nan_y_is_nan:

    mov         .L__f32_qnan_set(%rip), %r9d
    and         %edx, %r9d
    jz          .L__continue_xy_nan

    mov         .L__f32_qnan_set(%rip), %r10d
    and         %r8d, %r10d
    jz          .L__continue_xy_nan

    movd        %r11d, %xmm0
    jmp         .L__final_check

.L__continue_xy_nan:    
    movss       save_x(%rsp), %xmm0
    movss       save_y(%rsp), %xmm1
    movd        %r11d, %xmm2
    mov         .L__flag_x_nan_y_nan(%rip), %edi

    call        fname_special
    jmp         .L__final_check  

.data

.align 16

# these codes and the ones in the corresponding .c file have to match
.L__flag_x_one_y_snan:          .long 1
.L__flag_x_zero_z_inf:          .long 2
.L__flag_x_nan:                 .long 3
.L__flag_y_nan:                 .long 4
.L__flag_x_nan_y_nan:           .long 5
.L__flag_x_neg_y_notint:        .long 6
.L__flag_z_zero:                .long 7
.L__flag_z_denormal:            .long 8
.L__flag_z_inf:                 .long 9

.align 16

.L__f32_ay_max_bound:           .long 0x4f000000
.L__f32_ay_min_bound:           .long 0x2e800000
.L__f32_sign_mask:              .long 0x80000000
.L__f32_sign_and_exp_mask:      .long 0x0ff800000
.L__f32_exp_mask:               .long 0x7f800000
.L__f32_neg_inf:                .long 0x0ff800000
.L__f32_pos_inf:                .long 0x7f800000
.L__f32_pos_one:                .long 0x3f800000
.L__f32_pos_zero:               .long 0x00000000

.align 16
.L__f32_exp_mant_mask:          .long 0x7fffffff
                                .long 0x0
                                .quad 0x0

.L__f32_mant_mask:              .long 0x007fffff

.L__f32_neg_qnan:               .long 0x0ffc00000
.L__f32_qnan:                   .long 0x7fc00000
.L__f32_qnan_set:               .long 0x00400000

.L__f32_neg_one:                .long 0x0bf800000
.L__f32_neg_zero:               .long 0x80000000

.L__f32_real_one:               .long 0x3f800000
.L__f32_real_zero:              .long 0x00000000
.L__f32_real_inf:               .long 0x7f800000

.L__yexp_24:                    .long 0x00000018

.L__f32_exp_shift:              .long 0x00000017
.L__f32_exp_bias:               .long 0x0000007f
.L__f32_mant_full:              .long 0x007fffff
.L__f32_1_before_mant:          .long 0x00800000

.align 16

.L__mask_mant_all8:         .quad 0x000ff00000000000
.L__mask_mant9:             .quad 0x0000080000000000

#---------------------
# log data
#---------------------

.align 16

.L__real_ninf:  .quad 0x0fff0000000000000   # -inf
                .quad 0x0000000000000000
.L__real_inf:   .quad 0x7ff0000000000000    # +inf
                .quad 0x0000000000000000
.L__real_nan:   .quad 0x7ff8000000000000    # NaN
                .quad 0x0000000000000000
.L__real_mant:  .quad 0x000FFFFFFFFFFFFF    # mantissa bits
                .quad 0x0000000000000000
.L__mask_1023:  .quad 0x00000000000003ff
                .quad 0x0000000000000000


.L__real_log2:      .quad 0x3fe62e42fefa39ef
                    .quad 0x0000000000000000

.L__real_two:       .quad 0x4000000000000000 # 2
                    .quad 0x0000000000000000

.L__real_one:       .quad 0x3ff0000000000000 # 1
                    .quad 0x0000000000000000

.L__real_half:      .quad 0x3fe0000000000000 # 1/2
                    .quad 0x0000000000000000

.L__real_1_over_1:  .quad 0x3ff0000000000000
                    .quad 0x0000000000000000
.L__real_1_over_2:  .quad 0x3fe0000000000000
                    .quad 0x0000000000000000
.L__real_1_over_3:  .quad 0x3fd5555555555555
                    .quad 0x0000000000000000
.L__real_1_over_4:  .quad 0x3fd0000000000000
                    .quad 0x0000000000000000

.L__real_notsign:   .quad 0x7ffFFFFFFFFFFFFF
                    .quad 0x0000000000000000

.L__real_threshold: .quad 0x3fb0000000000000 # .0625
                    .quad 0x0000000000000000

.L__real_ca1:       .quad 0x3fb55555555554e6 # 8.33333333333317923934e-02
                    .quad 0x0000000000000000
.L__real_ca2:       .quad 0x3f89999999bac6d4 # 1.25000000037717509602e-02
                    .quad 0x0000000000000000
.L__real_ca3:       .quad 0x3f62492307f1519f # 2.23213998791944806202e-03
                    .quad 0x0000000000000000
.L__real_ca4:       .quad 0x3f3c8034c85dfff0 # 4.34887777707614552256e-04
                    .quad 0x0000000000000000

.align 16
.L__log_256_table:
                    .quad 0x0000000000000000
                    .quad 0x3f6ff00aa2b10bc0
                    .quad 0x3f7fe02a6b106789
                    .quad 0x3f87dc475f810a77
                    .quad 0x3f8fc0a8b0fc03e4
                    .quad 0x3f93cea44346a575
                    .quad 0x3f97b91b07d5b11b
                    .quad 0x3f9b9fc027af9198
                    .quad 0x3f9f829b0e783300
                    .quad 0x3fa1b0d98923d980
                    .quad 0x3fa39e87b9febd60
                    .quad 0x3fa58a5bafc8e4d5
                    .quad 0x3fa77458f632dcfc
                    .quad 0x3fa95c830ec8e3eb
                    .quad 0x3fab42dd711971bf
                    .quad 0x3fad276b8adb0b52
                    .quad 0x3faf0a30c01162a6
                    .quad 0x3fb075983598e471
                    .quad 0x3fb16536eea37ae1
                    .quad 0x3fb253f62f0a1417
                    .quad 0x3fb341d7961bd1d1
                    .quad 0x3fb42edcbea646f0
                    .quad 0x3fb51b073f06183f
                    .quad 0x3fb60658a93750c4
                    .quad 0x3fb6f0d28ae56b4c
                    .quad 0x3fb7da766d7b12cd
                    .quad 0x3fb8c345d6319b21
                    .quad 0x3fb9ab42462033ad
                    .quad 0x3fba926d3a4ad563
                    .quad 0x3fbb78c82bb0eda1
                    .quad 0x3fbc5e548f5bc743
                    .quad 0x3fbd4313d66cb35d
                    .quad 0x3fbe27076e2af2e6
                    .quad 0x3fbf0a30c01162a6
                    .quad 0x3fbfec9131dbeabb
                    .quad 0x3fc0671512ca596e
                    .quad 0x3fc0d77e7cd08e59
                    .quad 0x3fc14785846742ac
                    .quad 0x3fc1b72ad52f67a0
                    .quad 0x3fc2266f190a5acb
                    .quad 0x3fc29552f81ff523
                    .quad 0x3fc303d718e47fd3
                    .quad 0x3fc371fc201e8f74
                    .quad 0x3fc3dfc2b0ecc62a
                    .quad 0x3fc44d2b6ccb7d1e
                    .quad 0x3fc4ba36f39a55e5
                    .quad 0x3fc526e5e3a1b438
                    .quad 0x3fc59338d9982086
                    .quad 0x3fc5ff3070a793d4
                    .quad 0x3fc66acd4272ad51
                    .quad 0x3fc6d60fe719d21d
                    .quad 0x3fc740f8f54037a5
                    .quad 0x3fc7ab890210d909
                    .quad 0x3fc815c0a14357eb
                    .quad 0x3fc87fa06520c911
                    .quad 0x3fc8e928de886d41
                    .quad 0x3fc9525a9cf456b4
                    .quad 0x3fc9bb362e7dfb83
                    .quad 0x3fca23bc1fe2b563
                    .quad 0x3fca8becfc882f19
                    .quad 0x3fcaf3c94e80bff3
                    .quad 0x3fcb5b519e8fb5a4
                    .quad 0x3fcbc286742d8cd6
                    .quad 0x3fcc2968558c18c1
                    .quad 0x3fcc8ff7c79a9a22
                    .quad 0x3fccf6354e09c5dc
                    .quad 0x3fcd5c216b4fbb91
                    .quad 0x3fcdc1bca0abec7d
                    .quad 0x3fce27076e2af2e6
                    .quad 0x3fce8c0252aa5a60
                    .quad 0x3fcef0adcbdc5936
                    .quad 0x3fcf550a564b7b37
                    .quad 0x3fcfb9186d5e3e2b
                    .quad 0x3fd00e6c45ad501d
                    .quad 0x3fd0402594b4d041
                    .quad 0x3fd071b85fcd590d
                    .quad 0x3fd0a324e27390e3
                    .quad 0x3fd0d46b579ab74b
                    .quad 0x3fd1058bf9ae4ad5
                    .quad 0x3fd136870293a8b0
                    .quad 0x3fd1675cababa60e
                    .quad 0x3fd1980d2dd4236f
                    .quad 0x3fd1c898c16999fb
                    .quad 0x3fd1f8ff9e48a2f3
                    .quad 0x3fd22941fbcf7966
                    .quad 0x3fd2596010df763a
                    .quad 0x3fd2895a13de86a3
                    .quad 0x3fd2b9303ab89d25
                    .quad 0x3fd2e8e2bae11d31
                    .quad 0x3fd31871c9544185
                    .quad 0x3fd347dd9a987d55
                    .quad 0x3fd3772662bfd85b
                    .quad 0x3fd3a64c556945ea
                    .quad 0x3fd3d54fa5c1f710
                    .quad 0x3fd404308686a7e4
                    .quad 0x3fd432ef2a04e814
                    .quad 0x3fd4618bc21c5ec2
                    .quad 0x3fd49006804009d1
                    .quad 0x3fd4be5f957778a1
                    .quad 0x3fd4ec973260026a
                    .quad 0x3fd51aad872df82d
                    .quad 0x3fd548a2c3add263
                    .quad 0x3fd5767717455a6c
                    .quad 0x3fd5a42ab0f4cfe2
                    .quad 0x3fd5d1bdbf5809ca
                    .quad 0x3fd5ff3070a793d4
                    .quad 0x3fd62c82f2b9c795
                    .quad 0x3fd659b57303e1f3
                    .quad 0x3fd686c81e9b14af
                    .quad 0x3fd6b3bb2235943e
                    .quad 0x3fd6e08eaa2ba1e4
                    .quad 0x3fd70d42e2789236
                    .quad 0x3fd739d7f6bbd007
                    .quad 0x3fd7664e1239dbcf
                    .quad 0x3fd792a55fdd47a2
                    .quad 0x3fd7bede0a37afc0
                    .quad 0x3fd7eaf83b82afc3
                    .quad 0x3fd816f41da0d496
                    .quad 0x3fd842d1da1e8b17
                    .quad 0x3fd86e919a330ba0
                    .quad 0x3fd89a3386c1425b
                    .quad 0x3fd8c5b7c858b48b
                    .quad 0x3fd8f11e873662c7
                    .quad 0x3fd91c67eb45a83e
                    .quad 0x3fd947941c2116fb
                    .quad 0x3fd972a341135158
                    .quad 0x3fd99d958117e08b
                    .quad 0x3fd9c86b02dc0863
                    .quad 0x3fd9f323ecbf984c
                    .quad 0x3fda1dc064d5b995
                    .quad 0x3fda484090e5bb0a
                    .quad 0x3fda72a4966bd9ea
                    .quad 0x3fda9cec9a9a084a
                    .quad 0x3fdac718c258b0e4
                    .quad 0x3fdaf1293247786b
                    .quad 0x3fdb1b1e0ebdfc5b
                    .quad 0x3fdb44f77bcc8f63
                    .quad 0x3fdb6eb59d3cf35e
                    .quad 0x3fdb9858969310fb
                    .quad 0x3fdbc1e08b0dad0a
                    .quad 0x3fdbeb4d9da71b7c
                    .quad 0x3fdc149ff115f027
                    .quad 0x3fdc3dd7a7cdad4d
                    .quad 0x3fdc66f4e3ff6ff8
                    .quad 0x3fdc8ff7c79a9a22
                    .quad 0x3fdcb8e0744d7aca
                    .quad 0x3fdce1af0b85f3eb
                    .quad 0x3fdd0a63ae721e64
                    .quad 0x3fdd32fe7e00ebd5
                    .quad 0x3fdd5b7f9ae2c684
                    .quad 0x3fdd83e7258a2f3e
                    .quad 0x3fddac353e2c5954
                    .quad 0x3fddd46a04c1c4a1
                    .quad 0x3fddfc859906d5b5
                    .quad 0x3fde24881a7c6c26
                    .quad 0x3fde4c71a8687704
                    .quad 0x3fde744261d68788
                    .quad 0x3fde9bfa659861f5
                    .quad 0x3fdec399d2468cc0
                    .quad 0x3fdeeb20c640ddf4
                    .quad 0x3fdf128f5faf06ed
                    .quad 0x3fdf39e5bc811e5c
                    .quad 0x3fdf6123fa7028ac
                    .quad 0x3fdf884a36fe9ec2
                    .quad 0x3fdfaf588f78f31f
                    .quad 0x3fdfd64f20f61572
                    .quad 0x3fdffd2e0857f498
                    .quad 0x3fe011fab125ff8a
                    .quad 0x3fe02552a5a5d0ff
                    .quad 0x3fe0389eefce633b
                    .quad 0x3fe04bdf9da926d2
                    .quad 0x3fe05f14bd26459c
                    .quad 0x3fe0723e5c1cdf40
                    .quad 0x3fe0855c884b450e
                    .quad 0x3fe0986f4f573521
                    .quad 0x3fe0ab76bece14d2
                    .quad 0x3fe0be72e4252a83
                    .quad 0x3fe0d163ccb9d6b8
                    .quad 0x3fe0e44985d1cc8c
                    .quad 0x3fe0f7241c9b497d
                    .quad 0x3fe109f39e2d4c97
                    .quad 0x3fe11cb81787ccf8
                    .quad 0x3fe12f719593efbc
                    .quad 0x3fe1422025243d45
                    .quad 0x3fe154c3d2f4d5ea
                    .quad 0x3fe1675cababa60e
                    .quad 0x3fe179eabbd899a1
                    .quad 0x3fe18c6e0ff5cf06
                    .quad 0x3fe19ee6b467c96f
                    .quad 0x3fe1b154b57da29f
                    .quad 0x3fe1c3b81f713c25
                    .quad 0x3fe1d610fe677003
                    .quad 0x3fe1e85f5e7040d0
                    .quad 0x3fe1faa34b87094c
                    .quad 0x3fe20cdcd192ab6e
                    .quad 0x3fe21f0bfc65beec
                    .quad 0x3fe23130d7bebf43
                    .quad 0x3fe2434b6f483934
                    .quad 0x3fe2555bce98f7cb
                    .quad 0x3fe26762013430e0
                    .quad 0x3fe2795e1289b11b
                    .quad 0x3fe28b500df60783
                    .quad 0x3fe29d37fec2b08b
                    .quad 0x3fe2af15f02640ad
                    .quad 0x3fe2c0e9ed448e8c
                    .quad 0x3fe2d2b4012edc9e
                    .quad 0x3fe2e47436e40268
                    .quad 0x3fe2f62a99509546
                    .quad 0x3fe307d7334f10be
                    .quad 0x3fe3197a0fa7fe6a
                    .quad 0x3fe32b1339121d71
                    .quad 0x3fe33ca2ba328995
                    .quad 0x3fe34e289d9ce1d3
                    .quad 0x3fe35fa4edd36ea0
                    .quad 0x3fe37117b54747b6
                    .quad 0x3fe38280fe58797f
                    .quad 0x3fe393e0d3562a1a
                    .quad 0x3fe3a5373e7ebdfa
                    .quad 0x3fe3b68449fffc23
                    .quad 0x3fe3c7c7fff73206
                    .quad 0x3fe3d9026a7156fb
                    .quad 0x3fe3ea33936b2f5c
                    .quad 0x3fe3fb5b84d16f42
                    .quad 0x3fe40c7a4880dce9
                    .quad 0x3fe41d8fe84672ae
                    .quad 0x3fe42e9c6ddf80bf
                    .quad 0x3fe43f9fe2f9ce67
                    .quad 0x3fe4509a5133bb0a
                    .quad 0x3fe4618bc21c5ec2
                    .quad 0x3fe472743f33aaad
                    .quad 0x3fe48353d1ea88df
                    .quad 0x3fe4942a83a2fc07
                    .quad 0x3fe4a4f85db03ebb
                    .quad 0x3fe4b5bd6956e274
                    .quad 0x3fe4c679afccee3a
                    .quad 0x3fe4d72d3a39fd00
                    .quad 0x3fe4e7d811b75bb1
                    .quad 0x3fe4f87a3f5026e9
                    .quad 0x3fe50913cc01686b
                    .quad 0x3fe519a4c0ba3446
                    .quad 0x3fe52a2d265bc5ab
                    .quad 0x3fe53aad05b99b7d
                    .quad 0x3fe54b2467999498
                    .quad 0x3fe55b9354b40bcd
                    .quad 0x3fe56bf9d5b3f399
                    .quad 0x3fe57c57f336f191
                    .quad 0x3fe58cadb5cd7989
                    .quad 0x3fe59cfb25fae87e
                    .quad 0x3fe5ad404c359f2d
                    .quad 0x3fe5bd7d30e71c73
                    .quad 0x3fe5cdb1dc6c1765
                    .quad 0x3fe5ddde57149923
                    .quad 0x3fe5ee02a9241675
                    .quad 0x3fe5fe1edad18919
                    .quad 0x3fe60e32f44788d9
                    .quad 0x3fe61e3efda46467
                    .quad 0x3fe62e42fefa39ef

.align 16
.L__log_F_inv:
                    .quad 0x4000000000000000
                    .quad 0x3fffe01fe01fe020
                    .quad 0x3fffc07f01fc07f0
                    .quad 0x3fffa11caa01fa12
                    .quad 0x3fff81f81f81f820
                    .quad 0x3fff6310aca0dbb5
                    .quad 0x3fff44659e4a4271
                    .quad 0x3fff25f644230ab5
                    .quad 0x3fff07c1f07c1f08
                    .quad 0x3ffee9c7f8458e02
                    .quad 0x3ffecc07b301ecc0
                    .quad 0x3ffeae807aba01eb
                    .quad 0x3ffe9131abf0b767
                    .quad 0x3ffe741aa59750e4
                    .quad 0x3ffe573ac901e574
                    .quad 0x3ffe3a9179dc1a73
                    .quad 0x3ffe1e1e1e1e1e1e
                    .quad 0x3ffe01e01e01e01e
                    .quad 0x3ffde5d6e3f8868a
                    .quad 0x3ffdca01dca01dca
                    .quad 0x3ffdae6076b981db
                    .quad 0x3ffd92f2231e7f8a
                    .quad 0x3ffd77b654b82c34
                    .quad 0x3ffd5cac807572b2
                    .quad 0x3ffd41d41d41d41d
                    .quad 0x3ffd272ca3fc5b1a
                    .quad 0x3ffd0cb58f6ec074
                    .quad 0x3ffcf26e5c44bfc6
                    .quad 0x3ffcd85689039b0b
                    .quad 0x3ffcbe6d9601cbe7
                    .quad 0x3ffca4b3055ee191
                    .quad 0x3ffc8b265afb8a42
                    .quad 0x3ffc71c71c71c71c
                    .quad 0x3ffc5894d10d4986
                    .quad 0x3ffc3f8f01c3f8f0
                    .quad 0x3ffc26b5392ea01c
                    .quad 0x3ffc0e070381c0e0
                    .quad 0x3ffbf583ee868d8b
                    .quad 0x3ffbdd2b899406f7
                    .quad 0x3ffbc4fd65883e7b
                    .quad 0x3ffbacf914c1bad0
                    .quad 0x3ffb951e2b18ff23
                    .quad 0x3ffb7d6c3dda338b
                    .quad 0x3ffb65e2e3beee05
                    .quad 0x3ffb4e81b4e81b4f
                    .quad 0x3ffb37484ad806ce
                    .quad 0x3ffb2036406c80d9
                    .quad 0x3ffb094b31d922a4
                    .quad 0x3ffaf286bca1af28
                    .quad 0x3ffadbe87f94905e
                    .quad 0x3ffac5701ac5701b
                    .quad 0x3ffaaf1d2f87ebfd
                    .quad 0x3ffa98ef606a63be
                    .quad 0x3ffa82e65130e159
                    .quad 0x3ffa6d01a6d01a6d
                    .quad 0x3ffa574107688a4a
                    .quad 0x3ffa41a41a41a41a
                    .quad 0x3ffa2c2a87c51ca0
                    .quad 0x3ffa16d3f97a4b02
                    .quad 0x3ffa01a01a01a01a
                    .quad 0x3ff9ec8e951033d9
                    .quad 0x3ff9d79f176b682d
                    .quad 0x3ff9c2d14ee4a102
                    .quad 0x3ff9ae24ea5510da
                    .quad 0x3ff999999999999a
                    .quad 0x3ff9852f0d8ec0ff
                    .quad 0x3ff970e4f80cb872
                    .quad 0x3ff95cbb0be377ae
                    .quad 0x3ff948b0fcd6e9e0
                    .quad 0x3ff934c67f9b2ce6
                    .quad 0x3ff920fb49d0e229
                    .quad 0x3ff90d4f120190d5
                    .quad 0x3ff8f9c18f9c18fa
                    .quad 0x3ff8e6527af1373f
                    .quad 0x3ff8d3018d3018d3
                    .quad 0x3ff8bfce8062ff3a
                    .quad 0x3ff8acb90f6bf3aa
                    .quad 0x3ff899c0f601899c
                    .quad 0x3ff886e5f0abb04a
                    .quad 0x3ff87427bcc092b9
                    .quad 0x3ff8618618618618
                    .quad 0x3ff84f00c2780614
                    .quad 0x3ff83c977ab2bedd
                    .quad 0x3ff82a4a0182a4a0
                    .quad 0x3ff8181818181818
                    .quad 0x3ff8060180601806
                    .quad 0x3ff7f405fd017f40
                    .quad 0x3ff7e225515a4f1d
                    .quad 0x3ff7d05f417d05f4
                    .quad 0x3ff7beb3922e017c
                    .quad 0x3ff7ad2208e0ecc3
                    .quad 0x3ff79baa6bb6398b
                    .quad 0x3ff78a4c8178a4c8
                    .quad 0x3ff77908119ac60d
                    .quad 0x3ff767dce434a9b1
                    .quad 0x3ff756cac201756d
                    .quad 0x3ff745d1745d1746
                    .quad 0x3ff734f0c541fe8d
                    .quad 0x3ff724287f46debc
                    .quad 0x3ff713786d9c7c09
                    .quad 0x3ff702e05c0b8170
                    .quad 0x3ff6f26016f26017
                    .quad 0x3ff6e1f76b4337c7
                    .quad 0x3ff6d1a62681c861
                    .quad 0x3ff6c16c16c16c17
                    .quad 0x3ff6b1490aa31a3d
                    .quad 0x3ff6a13cd1537290
                    .quad 0x3ff691473a88d0c0
                    .quad 0x3ff6816816816817
                    .quad 0x3ff6719f3601671a
                    .quad 0x3ff661ec6a5122f9
                    .quad 0x3ff6524f853b4aa3
                    .quad 0x3ff642c8590b2164
                    .quad 0x3ff63356b88ac0de
                    .quad 0x3ff623fa77016240
                    .quad 0x3ff614b36831ae94
                    .quad 0x3ff6058160581606
                    .quad 0x3ff5f66434292dfc
                    .quad 0x3ff5e75bb8d015e7
                    .quad 0x3ff5d867c3ece2a5
                    .quad 0x3ff5c9882b931057
                    .quad 0x3ff5babcc647fa91
                    .quad 0x3ff5ac056b015ac0
                    .quad 0x3ff59d61f123ccaa
                    .quad 0x3ff58ed2308158ed
                    .quad 0x3ff5805601580560
                    .quad 0x3ff571ed3c506b3a
                    .quad 0x3ff56397ba7c52e2
                    .quad 0x3ff5555555555555
                    .quad 0x3ff54725e6bb82fe
                    .quad 0x3ff5390948f40feb
                    .quad 0x3ff52aff56a8054b
                    .quad 0x3ff51d07eae2f815
                    .quad 0x3ff50f22e111c4c5
                    .quad 0x3ff5015015015015
                    .quad 0x3ff4f38f62dd4c9b
                    .quad 0x3ff4e5e0a72f0539
                    .quad 0x3ff4d843bedc2c4c
                    .quad 0x3ff4cab88725af6e
                    .quad 0x3ff4bd3edda68fe1
                    .quad 0x3ff4afd6a052bf5b
                    .quad 0x3ff4a27fad76014a
                    .quad 0x3ff49539e3b2d067
                    .quad 0x3ff4880522014880
                    .quad 0x3ff47ae147ae147b
                    .quad 0x3ff46dce34596066
                    .quad 0x3ff460cbc7f5cf9a
                    .quad 0x3ff453d9e2c776ca
                    .quad 0x3ff446f86562d9fb
                    .quad 0x3ff43a2730abee4d
                    .quad 0x3ff42d6625d51f87
                    .quad 0x3ff420b5265e5951
                    .quad 0x3ff4141414141414
                    .quad 0x3ff40782d10e6566
                    .quad 0x3ff3fb013fb013fb
                    .quad 0x3ff3ee8f42a5af07
                    .quad 0x3ff3e22cbce4a902
                    .quad 0x3ff3d5d991aa75c6
                    .quad 0x3ff3c995a47babe7
                    .quad 0x3ff3bd60d9232955
                    .quad 0x3ff3b13b13b13b14
                    .quad 0x3ff3a524387ac822
                    .quad 0x3ff3991c2c187f63
                    .quad 0x3ff38d22d366088e
                    .quad 0x3ff3813813813814
                    .quad 0x3ff3755bd1c945ee
                    .quad 0x3ff3698df3de0748
                    .quad 0x3ff35dce5f9f2af8
                    .quad 0x3ff3521cfb2b78c1
                    .quad 0x3ff34679ace01346
                    .quad 0x3ff33ae45b57bcb2
                    .quad 0x3ff32f5ced6a1dfa
                    .quad 0x3ff323e34a2b10bf
                    .quad 0x3ff3187758e9ebb6
                    .quad 0x3ff30d190130d190
                    .quad 0x3ff301c82ac40260
                    .quad 0x3ff2f684bda12f68
                    .quad 0x3ff2eb4ea1fed14b
                    .quad 0x3ff2e025c04b8097
                    .quad 0x3ff2d50a012d50a0
                    .quad 0x3ff2c9fb4d812ca0
                    .quad 0x3ff2bef98e5a3711
                    .quad 0x3ff2b404ad012b40
                    .quad 0x3ff2a91c92f3c105
                    .quad 0x3ff29e4129e4129e
                    .quad 0x3ff293725bb804a5
                    .quad 0x3ff288b01288b013
                    .quad 0x3ff27dfa38a1ce4d
                    .quad 0x3ff27350b8812735
                    .quad 0x3ff268b37cd60127
                    .quad 0x3ff25e22708092f1
                    .quad 0x3ff2539d7e9177b2
                    .quad 0x3ff2492492492492
                    .quad 0x3ff23eb79717605b
                    .quad 0x3ff23456789abcdf
                    .quad 0x3ff22a0122a0122a
                    .quad 0x3ff21fb78121fb78
                    .quad 0x3ff21579804855e6
                    .quad 0x3ff20b470c67c0d9
                    .quad 0x3ff2012012012012
                    .quad 0x3ff1f7047dc11f70
                    .quad 0x3ff1ecf43c7fb84c
                    .quad 0x3ff1e2ef3b3fb874
                    .quad 0x3ff1d8f5672e4abd
                    .quad 0x3ff1cf06ada2811d
                    .quad 0x3ff1c522fc1ce059
                    .quad 0x3ff1bb4a4046ed29
                    .quad 0x3ff1b17c67f2bae3
                    .quad 0x3ff1a7b9611a7b96
                    .quad 0x3ff19e0119e0119e
                    .quad 0x3ff19453808ca29c
                    .quad 0x3ff18ab083902bdb
                    .quad 0x3ff1811811811812
                    .quad 0x3ff1778a191bd684
                    .quad 0x3ff16e0689427379
                    .quad 0x3ff1648d50fc3201
                    .quad 0x3ff15b1e5f75270d
                    .quad 0x3ff151b9a3fdd5c9
                    .quad 0x3ff1485f0e0acd3b
                    .quad 0x3ff13f0e8d344724
                    .quad 0x3ff135c81135c811
                    .quad 0x3ff12c8b89edc0ac
                    .quad 0x3ff12358e75d3033
                    .quad 0x3ff11a3019a74826
                    .quad 0x3ff1111111111111
                    .quad 0x3ff107fbbe011080
                    .quad 0x3ff0fef010fef011
                    .quad 0x3ff0f5edfab325a2
                    .quad 0x3ff0ecf56be69c90
                    .quad 0x3ff0e40655826011
                    .quad 0x3ff0db20a88f4696
                    .quad 0x3ff0d24456359e3a
                    .quad 0x3ff0c9714fbcda3b
                    .quad 0x3ff0c0a7868b4171
                    .quad 0x3ff0b7e6ec259dc8
                    .quad 0x3ff0af2f722eecb5
                    .quad 0x3ff0a6810a6810a7
                    .quad 0x3ff09ddba6af8360
                    .quad 0x3ff0953f39010954
                    .quad 0x3ff08cabb37565e2
                    .quad 0x3ff0842108421084
                    .quad 0x3ff07b9f29b8eae2
                    .quad 0x3ff073260a47f7c6
                    .quad 0x3ff06ab59c7912fb
                    .quad 0x3ff0624dd2f1a9fc
                    .quad 0x3ff059eea0727586
                    .quad 0x3ff05197f7d73404
                    .quad 0x3ff04949cc1664c5
                    .quad 0x3ff0410410410410
                    .quad 0x3ff038c6b78247fc
                    .quad 0x3ff03091b51f5e1a
                    .quad 0x3ff02864fc7729e9
                    .quad 0x3ff0204081020408
                    .quad 0x3ff0182436517a37
                    .quad 0x3ff0101010101010
                    .quad 0x3ff0080402010080
                    .quad 0x3ff0000000000000

#---------------------
# exp data
#---------------------

.align 16

.L__real_zero:                  .quad 0x0000000000000000
                                .quad 0

.L__real_p8192:                 .quad 0x40c0000000000000
                                .quad 0
.L__real_m9536:                 .quad 0x0c0c2a00000000000
                                .quad 0

.L__real_64_by_log2:            .quad 0x40571547652b82fe # 64/ln(2)
                                .quad 0
.L__real_log2_by_64:            .quad 0x3f862e42fefa39ef # log2_by_64
                                .quad 0

.L__real_1_by_24:               .quad 0x3fa5555555555555 # 1/24
                                .quad 0
.L__real_1_by_6:                .quad 0x3fc5555555555555 # 1/6
                                .quad 0
.L__real_1_by_2:                .quad 0x3fe0000000000000 # 1/2
                                .quad 0
.L__real_1_by_1:                .quad 0x3ff0000000000000 # 1
                                .quad 0

.align 16

.L__two_to_jby64_table:
    .quad 0x3ff0000000000000
    .quad 0x3ff02c9a3e778061
    .quad 0x3ff059b0d3158574
    .quad 0x3ff0874518759bc8
    .quad 0x3ff0b5586cf9890f
    .quad 0x3ff0e3ec32d3d1a2
    .quad 0x3ff11301d0125b51
    .quad 0x3ff1429aaea92de0
    .quad 0x3ff172b83c7d517b
    .quad 0x3ff1a35beb6fcb75
    .quad 0x3ff1d4873168b9aa
    .quad 0x3ff2063b88628cd6
    .quad 0x3ff2387a6e756238
    .quad 0x3ff26b4565e27cdd
    .quad 0x3ff29e9df51fdee1
    .quad 0x3ff2d285a6e4030b
    .quad 0x3ff306fe0a31b715
    .quad 0x3ff33c08b26416ff
    .quad 0x3ff371a7373aa9cb
    .quad 0x3ff3a7db34e59ff7
    .quad 0x3ff3dea64c123422
    .quad 0x3ff4160a21f72e2a
    .quad 0x3ff44e086061892d
    .quad 0x3ff486a2b5c13cd0
    .quad 0x3ff4bfdad5362a27
    .quad 0x3ff4f9b2769d2ca7
    .quad 0x3ff5342b569d4f82
    .quad 0x3ff56f4736b527da
    .quad 0x3ff5ab07dd485429
    .quad 0x3ff5e76f15ad2148
    .quad 0x3ff6247eb03a5585
    .quad 0x3ff6623882552225
    .quad 0x3ff6a09e667f3bcd
    .quad 0x3ff6dfb23c651a2f
    .quad 0x3ff71f75e8ec5f74
    .quad 0x3ff75feb564267c9
    .quad 0x3ff7a11473eb0187
    .quad 0x3ff7e2f336cf4e62
    .quad 0x3ff82589994cce13
    .quad 0x3ff868d99b4492ed
    .quad 0x3ff8ace5422aa0db
    .quad 0x3ff8f1ae99157736
    .quad 0x3ff93737b0cdc5e5
    .quad 0x3ff97d829fde4e50
    .quad 0x3ff9c49182a3f090
    .quad 0x3ffa0c667b5de565
    .quad 0x3ffa5503b23e255d
    .quad 0x3ffa9e6b5579fdbf
    .quad 0x3ffae89f995ad3ad
    .quad 0x3ffb33a2b84f15fb
    .quad 0x3ffb7f76f2fb5e47
    .quad 0x3ffbcc1e904bc1d2
    .quad 0x3ffc199bdd85529c
    .quad 0x3ffc67f12e57d14b
    .quad 0x3ffcb720dcef9069
    .quad 0x3ffd072d4a07897c
    .quad 0x3ffd5818dcfba487
    .quad 0x3ffda9e603db3285
    .quad 0x3ffdfc97337b9b5f
    .quad 0x3ffe502ee78b3ff6
    .quad 0x3ffea4afa2a490da
    .quad 0x3ffefa1bee615a27
    .quad 0x3fff50765b6e4540
    .quad 0x3fffa7c1819e90d8


