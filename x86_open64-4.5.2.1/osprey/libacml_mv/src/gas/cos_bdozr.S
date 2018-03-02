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
#define fname FN_PROTOTYPE_BDOZR(cos)

#include "trig_func.h"


.equ    r,    0x30                               # pointer to r for amd_remainder_piby2
.equ    rr,   0x40                               # pointer to rr for amd_remainder_piby2
.equ    region,    0x50                               # pointer to region for amd_remainder_piby2
.equ    ret_addr, 0x60
.equ   stack_size, 0x88



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

cos_early_exit_s:

	VANDPD .L__sign_mask(%rip),%xmm0,%xmm8			# xmm8 clear sign
	VCMPNEQSD %xmm0,%xmm0,%xmm1   					#nan mask xmm1
	VPCMPEQQ .L__inf_mask_64(%rip),%xmm8,%xmm2   	#xmm2 has inf mask
	VORPD	%xmm1,%xmm2,%xmm11						# xmm11 nan and inf mask
	VMOVAPD	.L_nan(%rip),%xmm3
	VPCMOV	%xmm2,%xmm1,%xmm3,%xmm10				#xmm10 nan and inf values
	VADDSD	 %xmm0,%xmm0,%xmm3						#nan value
	VPCMOV	%xmm1,%xmm10,%xmm3,%xmm10				#xmm10 nan and inf values


cos_early_exit_s_1:

	VPCOMLEUQ  .L_mask_3fe(%rip),%xmm8,%xmm7
	VORPD   %xmm11,%xmm7,%xmm7
	VMOVDDUP	%xmm7,%xmm7

	VPTEST	%xmm7,%xmm7
	JZ	range_reduce

	VMULSD	.L_point_five(%rip),%xmm0,%xmm1 						#
	VFNMADDSD .L_one(%rip),%xmm0,%xmm1,%xmm9 		# xmm9 1.0 - x*x*(double2)0.5;
	VXORPD	%xmm1,%xmm1,%xmm1
	cos_piby4_s

	VPCOMLTUQ  .L_mask_3e4(%rip),%xmm8,%xmm3
	VPCOMLTUQ  .L_mask_3f2(%rip),%xmm8,%xmm4

	VANDNPD	%xmm7,%xmm4,%xmm1
	VANDPD	%xmm0,%xmm1,%xmm1						# res2
	VANDNPD %xmm7,%xmm3,%xmm5
	VANDPD  %xmm5,%xmm4,%xmm5
	VANDPD  %xmm9,%xmm5,%xmm5
	VANDPD  %xmm7,%xmm3,%xmm3
	VANDPD  .L_one(%rip),%xmm3,%xmm3
	VORPD	%xmm3,%xmm5,%xmm5						# res1 amm5
	VORPD	%xmm1,%xmm5,%xmm0						# res_pi_4
	VPCMOV	%xmm11,%xmm0,%xmm10,%xmm0
	JMP	return_cos_s



range_reduce:

	MOVAPD	%xmm8,%xmm0								# xmm0 x with the sign cleared
	VCMPLTSD .L_e_5(%rip),%xmm0,%xmm8

	VMOVDDUP	%xmm8,%xmm8
	VPTEST	%xmm8,%xmm8

	JZ  cos_remainder_piby2

#cos_range_e_5_s:
	range_e_5_s
	JMP cos_exit_s

cos_remainder_piby2:
	call_remainder_piby2

cos_exit_s:

	VANDPD	.L_int_one(%rip),%xmm11,%xmm3

	VPCOMEQUQ .L_int_one(%rip),%xmm3,%xmm3
	VMOVDDUP	%xmm3,%xmm3
	VPTEST	%xmm3,%xmm3
	JNZ	sin_piby4_compute

cos_piby4_compute:
	cos_piby4_s
	JMP cos_exit_s_1

sin_piby4_compute:
	sin_piby4_s

cos_exit_s_1:

	VPCOMEQUQ .L_int_one(%rip),%xmm11,%xmm1
	VPCOMEQUQ .L_int_two(%rip),%xmm11,%xmm2
	VORPD	%xmm1,%xmm2,%xmm3

	VANDPD	.L_signbit(%rip),%xmm3,%xmm3
	VXORPD	%xmm3,%xmm0,%xmm0

return_cos_s:

   	add      $stack_size, %rsp
	ret

