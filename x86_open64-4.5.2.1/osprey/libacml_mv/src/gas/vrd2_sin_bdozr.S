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
#define fname FN_PROTOTYPE_BDOZR(vrd2_sin)

#include "trig_func.h"


.equ    r,    0x10                               # pointer to r for amd_remainder_piby2
.equ    rr,   0x20                               # pointer to rr for amd_remainder_piby2
.equ    region,    0x30                               # pointer to region for amd_remainder_piby2
.equ    ret_addr, 0x40
.equ    res_pi_4, 0x50
.equ    mas_res_pi_4, 0x60
.equ    input, 0x70
.equ    r1,    0x80                               # pointer to r for amd_remainder_piby2
.equ    rr1,   0x90                               # pointer to rr for amd_remainder_piby2
.equ    region1,    0x100                               # pointer to region for amd_remainder_piby2
.equ    input_val,    0x110                               # pointer to region for amd_remainder_piby2
.equ   stack_size, 0x128




#ifdef __ELF__
.section .note.GNU-stack,"",@progbits
#endif

.text
.align 32
.p2align 4,,15
.globl fname
.type fname,@function
fname:

    	sub     $stack_size, %rsp

sin_early_exit_s:

	VMOVAPD	 %xmm0,input_val(%rsp)
	VCMPNEQPD %xmm0,%xmm0,%xmm1   					#nan mask xmm1
	VANDPD .L__sign_mask(%rip),%xmm0,%xmm8			# xmm8 clear sign
	VPCMPEQQ .L__inf_mask_64(%rip),%xmm8,%xmm2   	#xmm2 has inf mask
	VADDPD	 %xmm0,%xmm0,%xmm3						#nan value
	VPCMOV	%xmm1,%xmm1,%xmm3,%xmm4					#xmm4 nan value
	VMOVAPD	.L_nan(%rip),%xmm3
	VPCMOV	%xmm2,%xmm4,%xmm3,%xmm12				#xmm12 nan and inf values
	VORPD	%xmm1,%xmm2,%xmm11						# xmm11 nan and inf mask


sin_early_exit_s_1:

	VPCOMLEUQ  .L_mask_3fe(%rip),%xmm8,%xmm7

	VORPD   %xmm11,%xmm7,%xmm2
	VPTEST %xmm2,%xmm2
	JZ range_reduce

	VMOVAPD	%xmm0,%xmm10
	VMULPD	%xmm0,%xmm0,%xmm1 						#
	VMULPD	%xmm0,%xmm1,%xmm1 						# xmm1 x3
	VFNMADDPD %xmm0,.L_point_166(%rip),%xmm1,%xmm9         #  x - x*x*x*0.166666666666666666;
	VXORPD	%xmm1,%xmm1,%xmm1

	sin_2fpiby4_s_xx_zero

	VPCOMLTUQ  .L_mask_3e4(%rip),%xmm8,%xmm3
	VPCOMLTUQ  .L_mask_3f2(%rip),%xmm8,%xmm4

	VANDNPD	%xmm7,%xmm4,%xmm1
	VANDPD	%xmm0,%xmm1,%xmm1				# res2
	VANDNPD %xmm7,%xmm3,%xmm5
	VANDPD  %xmm5,%xmm4,%xmm5
	VANDPD  %xmm9,%xmm5,%xmm5
	VANDPD  %xmm7,%xmm3,%xmm3
	VANDPD  %xmm10,%xmm3,%xmm3
	VORPD	%xmm3,%xmm5,%xmm5				# res1 amm5
	VORPD	%xmm1,%xmm5,%xmm0				# res_pi_4
	VPCMOV	%xmm11,%xmm0,%xmm12,%xmm0

	VPTEST .L__allone_mask(%rip),%xmm2
	JC return_sin_s

range_reduce:

	VORPD   %xmm11,%xmm7,%xmm7
	VMOVAPD  %xmm0,res_pi_4(%rsp)
	VMOVAPD  %xmm7,mas_res_pi_4(%rsp)

	VANDNPD	%xmm8,%xmm7,%xmm0                     # xmm0 x with the sign cleared
	VMOVAPD %xmm0,input(%rsp)

	VCMPGEPD .L_e_5(%rip),%xmm0,%xmm3
	VPTEST %xmm3,%xmm3

	JZ call_range_e5

	call_remainder_2fpiby2

ret_remainder_2fpiby2:

	VMOVAPD	%xmm0,r1(%rsp)
	VMOVAPD	%xmm1,rr1(%rsp)
	VMOVAPD	%xmm11,region1(%rsp)

call_range_e5:
	VMOVAPD input(%rsp),%xmm0
	range_e_5_2f_s

if_not_remainder:


	VMOVAPD input(%rsp),%xmm2
	VCMPLTPD .L_e_5(%rip),%xmm2,%xmm3

	VPCMOV	%xmm3,r1(%rsp),%xmm0,%xmm7
	VPCMOV	%xmm3,rr1(%rsp),%xmm1,%xmm8
	VPCMOV	%xmm3,region1(%rsp),%xmm11,%xmm11

	VPCOMEQUQ .L_int_one(%rip),%xmm11,%xmm1
	VPCOMEQUQ .L_int_two(%rip),%xmm11,%xmm2
	VPCOMEQUQ .L_int_three(%rip),%xmm11,%xmm3

	VORPD	%xmm1,%xmm3,%xmm10
	VORPD	%xmm3,%xmm2,%xmm9

	VMOVAPD	%xmm7,%xmm0
	VMOVAPD	%xmm8,%xmm1

	VMOVD %xmm10,%r8
	VPUNPCKHQDQ %xmm10,%xmm10,%xmm10
	VMOVD %xmm10,%r9

	cmp	$0xFFFFFFFF,%r8d
	je compute_xxx_cos

	cmp	$0xFFFFFFFF,%r9d
	je compute_cos_sin


both_sin_sin:
		sin_2fpiby4_s

		jmp ret_sin_2fpiby4_s

compute_cos_sin:

		sin_piby4_s
		VMOVAPD	%xmm0,%xmm10
		VPUNPCKHQDQ %xmm7,%xmm7,%xmm0
		VPUNPCKHQDQ %xmm8,%xmm8,%xmm1
		cos_piby4_s
		VPUNPCKLQDQ	%xmm0,%xmm10,%xmm0

		jmp ret_sin_2fpiby4_s

compute_xxx_cos:
	cmp	$0xFFFFFFFF,%r9d
	je compute_cos_cos

		cos_piby4_s
		VMOVAPD	%xmm0,%xmm10
		VPUNPCKHQDQ %xmm7,%xmm7,%xmm0
		VPUNPCKHQDQ %xmm8,%xmm8,%xmm1
		sin_piby4_s
		VPUNPCKLQDQ	%xmm0,%xmm10,%xmm0
		jmp ret_sin_2fpiby4_s

compute_cos_cos:

	cos_2fpiby4_s

ret_sin_2fpiby4_s:


	VANDNPD	.L_signbit(%rip),%xmm9,%xmm9
	VXORPD	%xmm9,%xmm0,%xmm9

	VMOVAPD	input_val(%rsp),%xmm0
	VANDNPD	.L_signbit(%rip),%xmm0,%xmm0
	VXORPD	%xmm9,%xmm0,%xmm9


	VMOVAPD mas_res_pi_4(%rsp),%xmm8
	VMOVAPD res_pi_4(%rsp),%xmm0

	VPCMOV %xmm8,%xmm9,%xmm0,%xmm0

return_sin_s:

   	add      $stack_size, %rsp
	ret

