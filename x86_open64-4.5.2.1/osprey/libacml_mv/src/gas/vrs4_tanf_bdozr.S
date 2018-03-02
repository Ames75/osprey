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
#define fname FN_PROTOTYPE_BDOZR(vrs4_tanf)

#include "trig_func.h"

.align 32
.equ    r,    0x20                               # pointer to r for amd_remainder_piby2
.equ    rr,   0x40                               # pointer to rr for amd_remainder_piby2
.equ    region,    0x60                               # pointer to region for amd_remainder_piby2
.equ    res_pi_4, 0x80
.equ    mas_res_pi_4, 0xA0
.equ    input, 0xC0
.equ    r1,    0xE0                               # pointer to r for amd_remainder_piby2
.equ    rr1,   0x100                               # pointer to rr for amd_remainder_piby2
.equ    region1,    0x120                               # pointer to region for amd_remainder_piby2
.equ    ret_addr, 0x140
.equ    store_input, 0x160
.equ   stack_size, 0x188







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
		VCVTPS2PD	%xmm0,%ymm0
tan_early_exit_s:

	VMOVUPD	 %ymm0,store_input(%rsp)


	VCMPNEQPD %ymm0,%ymm0,%ymm1   					#nan mask ymm1
	VANDPD .L__sign_mask(%rip),%ymm0,%ymm8			# ymm8 clear sign

	VEXTRACTF128 $1,%ymm8,%xmm3
	VPCMPEQQ .L__inf_mask_64(%rip),%xmm8,%xmm2   	#
	VPCMPEQQ .L__inf_mask_64(%rip),%xmm3,%xmm3   	#
	VINSERTF128 $1,%xmm3,%ymm2,%ymm2			   	#ymm2 has inf mask

	VADDPD	 %ymm0,%ymm0,%ymm3						#nan value
	VPCMOV	%ymm1,%ymm1,%ymm3,%ymm4					#ymm4 nan value
	VMOVUPD	.L_nan(%rip),%ymm3
	VPCMOV	%ymm2,%ymm4,%ymm3,%ymm12				#ymm12 nan and inf values
	VORPD	%ymm1,%ymm2,%ymm11						# ymm11 nan and inf mask

tan_early_exit_s_1:

	VEXTRACTF128 $1,%ymm8,%xmm7

	VPCOMLEUQ  .L_mask_3fe(%rip),%xmm8,%xmm13
	VPCOMLEUQ  .L_mask_3fe(%rip),%xmm7,%xmm5
	VINSERTF128 $1,%xmm5,%ymm13,%ymm13

	VORPD   %ymm11,%ymm13,%ymm14
	VPTEST %ymm14,%ymm14
	JZ range_reduce


	VMOVAPD	%ymm0,%ymm10
	VMULPD	%ymm0,%ymm0,%ymm1 						#
	VMULPD	%ymm0,%ymm1,%ymm1 						# ymm1 x3
	VFMADDPD %ymm0,.L_point_333(%rip),%ymm1,%ymm14         #  x + x*x*x*0.3333333333333333;
	VXORPD	%ymm2,%ymm2,%ymm2
	tan_piby4_s4f


	VPCOMLTUQ  .L_mask_3e4(%rip),%xmm8,%xmm3
	VPCOMLTUQ  .L_mask_3e4(%rip),%xmm7,%xmm6
	VINSERTF128 $1,%xmm6,%ymm3,%ymm3
	VPCOMLTUQ  .L_mask_3f2(%rip),%xmm8,%xmm4
	VPCOMLTUQ  .L_mask_3f2(%rip),%xmm7,%xmm7
	VINSERTF128 $1,%xmm7,%ymm4,%ymm4


	VANDNPD	%ymm13,%ymm4,%ymm1
	VANDPD	%ymm0,%ymm1,%ymm1				# res2

	VANDNPD %ymm13,%ymm3,%ymm5
	VANDPD  %ymm5,%ymm4,%ymm5
	VANDPD  %ymm14,%ymm5,%ymm5

	VANDPD  %ymm13,%ymm3,%ymm3
	VANDPD  %ymm10,%ymm3,%ymm3
	VORPD	%ymm3,%ymm5,%ymm5				# res1 amm5
	VORPD	%ymm1,%ymm5,%ymm0				# res_pi_4
	VPCMOV	%ymm11,%ymm0,%ymm12,%ymm0

	VPTEST .L__allone_mask(%rip),%ymm14
	JC return_tanf_s

	VMOVUPD  %ymm0,res_pi_4(%rsp)

range_reduce:

	VORPD   %ymm11,%ymm13,%ymm13
	VMOVUPD  %ymm13,mas_res_pi_4(%rsp)
	VANDNPD	%ymm8,%ymm13,%ymm0                     # ymm0 x with the sign cleared
	VMOVUPD %ymm0,input(%rsp)

	VCMPGEPD .L_e_5(%rip),%ymm0,%ymm3
	VPTEST %ymm3,%ymm3
	JZ call_range_e5

	call_remainder_2fpiby2_4f

	VMOVUPD	%ymm0,r1(%rsp)
	VMOVUPD	%ymm11,region1(%rsp)
	VMOVUPD input(%rsp),%ymm0

	VCMPLTPD .L_e_5(%rip),%ymm0,%ymm3
	VPTEST %ymm3,%ymm3
	JZ if_not_remainder

call_range_e5:

	range_e_5_s4f

if_not_remainder:


	VMOVUPD input(%rsp),%ymm2
	VCMPLTPD .L_e_5(%rip),%ymm2,%ymm3

	VPCMOV	%ymm3,r1(%rsp),%ymm0,%ymm0
	VPCMOV	%ymm3,region1(%rsp),%ymm11,%ymm11


	VANDPD	.L_int_one(%rip),%ymm11,%ymm2

	tan_piby4_s4f

ret_tan_2fpiby4_s:

	VMOVUPD	 store_input(%rsp),%ymm1
	VANDPD	.L_signbit(%rip),%ymm1,%ymm1
	VXORPD	%ymm0,%ymm1,%ymm4

	VMOVUPD mas_res_pi_4(%rsp),%ymm11
	VMOVUPD res_pi_4(%rsp),%ymm0

	VPCMOV %ymm11,%ymm4,%ymm0,%ymm0

return_tanf_s:
	VCVTPD2PS	%ymm0,%xmm0
   	add      $stack_size, %rsp
	ret
