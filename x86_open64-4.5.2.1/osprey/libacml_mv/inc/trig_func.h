
/*
*  (C) 2008-2009 Advanced Micro Devices, Inc. All Rights Reserved.
*
*  This file is part of AMD LibM 3.0.
*
*  AMD LibM 3.0 is free software; you can redistribute it and/or
*  modify it under the terms of the GNU Lesser General Public
*  License as published by the Free Software Foundation; either
*  version 2.1 of the License, or (at your option) any later version.
*
*  AMD LibM 3.0 is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*  Lesser General Public License for more details.
*
*  You should have received a copy of the GNU Lesser General Public
*  License along with AMD LibM 3.0.  If not, see
*  <http://www.gnu.org/licenses/>.
*
*/



#############  Vector float    ymm0=r input  ymm0=output ##############
.macro sin_piby4_s4f

	VMOVAPD .L_Sin+0x40(%rip),%ymm4
	VMULPD		%ymm0,%ymm0,%ymm3                	#x * x  x2 ymm3
	VFMADDPD %ymm4,.L_Sin+0x60(%rip),%ymm3,%ymm4
	VFMADDPD .L_Sin+0x20(%rip),%ymm4,%ymm3,%ymm4
	VFMADDPD .L_Sin(%rip),%ymm4,%ymm3,%ymm4
	VMULPD 	  %ymm3,%ymm0,%ymm3					#x2 * x x3  ymm4
	VFMADDPD  %ymm0,%ymm3,%ymm4,%ymm0
	.endm

.macro  cos_piby4_s4f

	VMOVAPD	.L_one(%rip),%ymm2
	VMULPD		%ymm0,%ymm0,%ymm3                    # x * x ymm3
	VMULPD		.L_point_five(%rip),%ymm3,%ymm4		 # r ymm4
	VSUBPD		%ymm4,%ymm2,%ymm2
	VMOVAPD .L_Cos+0x40(%rip),%ymm4
	VFMADDPD %ymm4,.L_Cos+0x60(%rip),%ymm3,%ymm4
	VFMADDPD .L_Cos+0x20(%rip),%ymm4,%ymm3,%ymm4
	VFMADDPD .L_Cos(%rip),%ymm4,%ymm3,%ymm4
	VMULPD	%ymm3,%ymm3,%ymm3
	VFMADDPD  %ymm2,%ymm3,%ymm4,%ymm0
	.endm

.macro tan_piby4_s4f

	VMULPD	%ymm0,%ymm0,%ymm3					# x * x ymm3 (r)
	VMOVAPD	.L_tanf+0x20(%rip),%ymm4
	VFNMADDPD .L_tanf(%rip),%ymm4,%ymm3,%ymm4
	VMOVAPD	.L_tanf+0x80(%rip),%ymm5
	VFMADDPD .L_tanf+0x60(%rip),%ymm5,%ymm3,%ymm5
	VFMADDPD .L_tanf+0x40(%rip),%ymm5,%ymm3,%ymm5
	VDIVPD	%ymm5,%ymm4,%ymm4
	VMULPD	%ymm0,%ymm3,%ymm3
	VFMADDPD %ymm0,%ymm4,%ymm3,%ymm0
	VEXTRACTF128 $1,%ymm2,%xmm3
	VPCOMEQUQ .L_int_one(%rip),%xmm2,%xmm2		# recp mask ymm2
	VPCOMEQUQ .L_int_one(%rip),%xmm3,%xmm3		# recp mask ymm2
	VINSERTF128 $1,%xmm3,%ymm2,%ymm2
	VMOVAPD	.L_n_one(%rip),%ymm1
	VDIVPD	%ymm0,%ymm1,%ymm1
	VPCMOV	%ymm2,%ymm0,%ymm1,%ymm0
	.endm

############# End  vector float ##############


#############  scalar float   xmm0=r input  xmm0=output ##############

.macro sin_piby4_sf

	VMOVAPD .L_Sin+0x40(%rip),%xmm4
	VMULSD		%xmm0,%xmm0,%xmm3                	#x * x  x2 xmm3
	VFMADDSD %xmm4,.L_Sin+0x60(%rip),%xmm3,%xmm4
	VFMADDSD .L_Sin+0x20(%rip),%xmm4,%xmm3,%xmm4
	VFMADDSD .L_Sin(%rip),%xmm4,%xmm3,%xmm4
	VMULSD 	  %xmm3,%xmm0,%xmm3					#x2 * x x3  xmm4
	VFMADDSD  %xmm0,%xmm3,%xmm4,%xmm0
	.endm

.macro cos_piby4_sf

	VMOVAPD	.L_one(%rip),%xmm2
	VMULSD		%xmm0,%xmm0,%xmm3                    # x * x xmm3
	VMULSD		.L_point_five(%rip),%xmm3,%xmm4		 # r xmm4
	VSUBSD		%xmm4,%xmm2,%xmm2
	VMOVAPD .L_Cos+0x40(%rip),%xmm4
	VFMADDSD %xmm4,.L_Cos+0x60(%rip),%xmm3,%xmm4
	VFMADDSD .L_Cos+0x20(%rip),%xmm4,%xmm3,%xmm4
	VFMADDSD .L_Cos(%rip),%xmm4,%xmm3,%xmm4
	VMULSD	%xmm3,%xmm3,%xmm3
	VFMADDSD  %xmm2,%xmm3,%xmm4,%xmm0
	.endm

.macro  tan_piby4_sf

	VMULPD	%xmm0,%xmm0,%xmm3					# x * x xmm3 (r)
	VMOVAPD	.L_tanf+0x20(%rip),%xmm4
	VFNMADDSD .L_tanf(%rip),%xmm4,%xmm3,%xmm4
	VMOVAPD	.L_tanf+0x80(%rip),%xmm5
	VFMADDSD .L_tanf+0x60(%rip),%xmm5,%xmm3,%xmm5
	VFMADDSD .L_tanf+0x40(%rip),%xmm5,%xmm3,%xmm5
	VDIVSD	%xmm5,%xmm4,%xmm4
	VMULSD	%xmm0,%xmm3,%xmm3
	VFMADDSD %xmm0,%xmm4,%xmm3,%xmm0
	VPCOMEQUQ .L_int_one(%rip),%xmm2,%xmm2		# recp mask XMM2
	VMOVAPD	.L_n_one(%rip),%xmm1
	VDIVSD	%xmm0,%xmm1,%xmm1
	VPCMOV	%xmm2,%xmm0,%xmm1,%xmm0
	.endm

############# End  scalar float ##############


#############  vector double   xmm0=r xmm1=rr input  xmm3=recp xmm0=output ##############

.macro  cos_2fpiby4_s


	VMOVAPD .L_Cos+0x80(%rip),%xmm5
	VMOVAPD	.L_one(%rip),%xmm2
	VMULPD		%xmm0,%xmm0,%xmm3                    # x * x xmm3
	VMULPD		.L_point_five(%rip),%xmm3,%xmm4		 # r xmm4
	VSUBPD		%xmm4,%xmm2,%xmm6					 # t xmm6
	VSUBPD		%xmm6,%xmm2,%xmm2                    # 1-t
	VSUBPD		%xmm4,%xmm2,%xmm2					 # 	(1-t) -r xmm2
	VFNMADDPD	%xmm2,%xmm1,%xmm0,%xmm2				 # (1.0 - t) - r) - x * xx) xmm2
	VMULPD 		%xmm3,%xmm3,%xmm4					 # x2 * x2 xmm4
	VFMADDPD %xmm5,.L_Cos+0xA0(%rip),%xmm3,%xmm5
	VFMADDPD .L_Cos+0x60(%rip),%xmm5,%xmm3,%xmm5
	VFMADDPD .L_Cos+0x40(%rip),%xmm5,%xmm3,%xmm5
	VFMADDPD .L_Cos+0x20(%rip),%xmm5,%xmm3,%xmm5
	VFMADDPD .L_Cos(%rip),%xmm5,%xmm3,%xmm5
	VFMADDPD %xmm2,%xmm5,%xmm4,%xmm5
	VADDPD		%xmm6,%xmm5,%xmm0
	.endm


.macro  sin_2fpiby4_s_xx_zero

	VMOVAPD .L_Sin+0x80(%rip),%xmm5
	VMULPD		%xmm0,%xmm0,%xmm3                	#x * x  x2 xmm3

	VFMADDPD %xmm5,.L_Sin+0xA0(%rip),%xmm3,%xmm5
	VFMADDPD .L_Sin+0x60(%rip),%xmm5,%xmm3,%xmm5
	VFMADDPD .L_Sin+0x40(%rip),%xmm5,%xmm3,%xmm5
	VFMADDPD .L_Sin+0x20(%rip),%xmm5,%xmm3,%xmm5	#xmm5 r

	VMULPD 		%xmm3,%xmm0,%xmm4					#x2 * x x3  xmm4
	VFMADDPD .L_Sin(%rip),%xmm3,%xmm5,%xmm6
	VFMADDPD %xmm0,%xmm6,%xmm4,%xmm0				# xmm6 res1

	.endm





.macro  sin_2fpiby4_s

	VMOVAPD .L_Sin+0x80(%rip),%xmm5
	VMULPD		%xmm0,%xmm0,%xmm3                	#x * x  x2 xmm3

	VFMADDPD %xmm5,.L_Sin+0xA0(%rip),%xmm3,%xmm5
	VFMADDPD .L_Sin+0x60(%rip),%xmm5,%xmm3,%xmm5
	VFMADDPD .L_Sin+0x40(%rip),%xmm5,%xmm3,%xmm5
	VFMADDPD .L_Sin+0x20(%rip),%xmm5,%xmm3,%xmm5	#xmm5 r

	VMULPD 		%xmm3,%xmm0,%xmm4					#x2 * x x3  xmm4

	VMULPD	%xmm5,%xmm4,%xmm2		  	        	# xx,-(x3 * r)
	VMULPD	.L_point_five(%rip),%xmm1,%xmm5			# (0.5*xx)-(x3 * r)
	VSUBPD	%xmm2,%xmm5,%xmm2
	VMULPD %xmm2,%xmm3,%xmm2
	VSUBPD %xmm1,%xmm2,%xmm2
	VFNMADDPD %xmm2,.L_Sin(%rip),%xmm4,%xmm2
	VSUBPD	%xmm2,%xmm0,%xmm0						#res2 %xmm2
	.endm


.macro  tan_2fpiby4_s

	VCMPGTPD .L_point_68(%rip),%xmm0,%xmm2
	VCMPLTPD .L_n_point_68(%rip),%xmm0,%xmm9
	VANDPD	.L_signbit(%rip),%xmm2,%xmm7
	VXORPD	%xmm7,%xmm0,%xmm5				# x-
	VXORPD	%xmm7,%xmm1,%xmm6				# xx-
	VANDPD	.L_signbit(%rip),%xmm9,%xmm7	# transform -1 if xmm9 set
	VADDPD	.L_piby4_lead(%rip),%xmm5,%xmm5
	VADDPD	.L_piby4_tail(%rip),%xmm6,%xmm6
	VADDPD	%xmm6,%xmm5,%xmm5				# x
	VORPD	%xmm2,%xmm9,%xmm8				# transform mask xmm8
	VPCMOV	%xmm8,%xmm0,%xmm5,%xmm0
	VXORPD	%xmm9,%xmm9,%xmm9
	VPCMOV	%xmm8,%xmm1,%xmm9,%xmm1		# xmm0 x xmm1 xx
	VMULPD	%xmm0,%xmm0,%xmm9				# x2 xmm9
	VMULPD	%xmm0,%xmm1,%xmm4        # x * xx xmm4
	VFMADDPD	%xmm9,.L_two(%rip),%xmm4,%xmm2	   # xmm2 r
	VMOVAPD	 .L_tan_c3(%rip),%xmm9
	VFMADDPD .L_tan_c2(%rip),%xmm9,%xmm2,%xmm9
	VFMADDPD .L_tan_c1(%rip),%xmm9,%xmm2,%xmm9
	VMOVAPD	  .L_tan_c7(%rip),%xmm4
	VFNMADDPD .L_tan_c6(%rip),%xmm4,%xmm2,%xmm4
	VFMADDPD .L_tan_c5(%rip),%xmm4,%xmm2,%xmm4
	VFMADDPD .L_tan_c4(%rip),%xmm4,%xmm2,%xmm4
	VDIVPD	%xmm4,%xmm9,%xmm9
	VMULPD	%xmm2,%xmm9,%xmm9
	VFMADDPD %xmm1,%xmm0,%xmm9,%xmm9			# t2
	VADDPD		%xmm9,%xmm0,%xmm1				# t = t1+ t2 xmm1 res3
	VMULPD		.L_two(%rip),%xmm1,%xmm6
	VSUBPD		.L_one(%rip),%xmm1,%xmm4
	VDIVPD		%xmm4,%xmm6,%xmm5
	VSUBPD		.L_one(%rip),%xmm5,%xmm5
	VXORPD		%xmm5,%xmm7,%xmm5
	VADDPD		.L_one(%rip),%xmm1,%xmm4
	VDIVPD		%xmm4,%xmm6,%xmm6
	VMOVAPD		.L_one(%rip),%xmm4
	VSUBPD		%xmm6,%xmm4,%xmm6
	VXORPD		%xmm6,%xmm7,%xmm6
	VANDPD  .L_half_mask(%rip),%xmm1,%xmm2		# xmm2 z1
	VSUBPD	%xmm0,%xmm2,%xmm4
	VSUBPD	%xmm4,%xmm9,%xmm4					# xmm4 z2
	VMOVAPD	.L_n_one(%rip),%xmm9
	VDIVPD	 %xmm1,%xmm9,%xmm9					# xmm9 trec
	VANDPD  .L_half_mask(%rip),%xmm9,%xmm7		# xmm7 trec_top
	VFMADDPD .L_one(%rip),%xmm7,%xmm2,%xmm2		#
	VFMADDPD  %xmm2,%xmm7,%xmm4,%xmm2			#
	VFMADDPD  %xmm7,%xmm9,%xmm2,%xmm2			# res2
	VPCOMEQUQ .L_int_one(%rip),%xmm3,%xmm3		# recp mask xmm11
	VPCMOV %xmm3,%xmm6,%xmm5,%xmm6				# xmm6 res1
	VPCMOV	%xmm3,%xmm1,%xmm2,%xmm2
	VPCMOV	%xmm8,%xmm2,%xmm6,%xmm0
	.endm

############# End  vector double ##############


#############  scalar double   xmm0=r xmm1=rr input  xmm0=output ##############
.macro  cos_piby4_s


	VMOVAPD .L_Cos+0x80(%rip),%xmm5
	VMOVAPD	.L_one(%rip),%xmm2
	VMULSD		%xmm0,%xmm0,%xmm3                    # x * x xmm3
	VMULSD		.L_point_five(%rip),%xmm3,%xmm4		 # r xmm4
	VSUBSD		%xmm4,%xmm2,%xmm6					 # t xmm6
	VSUBSD		%xmm6,%xmm2,%xmm2                    # 1-t
	VSUBSD		%xmm4,%xmm2,%xmm2					 # 	(1-t) -r xmm2
	VFNMADDSD	%xmm2,%xmm1,%xmm0,%xmm2				 # (1.0 - t) - r) - x * xx) xmm2
	VMULSD 		%xmm3,%xmm3,%xmm4					 # x2 * x2 xmm4
	VFMADDSD %xmm5,.L_Cos+0xA0(%rip),%xmm3,%xmm5
	VFMADDSD .L_Cos+0x60(%rip),%xmm5,%xmm3,%xmm5
	VFMADDSD .L_Cos+0x40(%rip),%xmm5,%xmm3,%xmm5
	VFMADDSD .L_Cos+0x20(%rip),%xmm5,%xmm3,%xmm5
	VFMADDSD .L_Cos(%rip),%xmm5,%xmm3,%xmm5
	VFMADDSD %xmm2,%xmm5,%xmm4,%xmm5
	VADDSD		%xmm6,%xmm5,%xmm0
	.endm


.macro  sin_piby4_s_xx_zero

	VMOVAPD .L_Sin+0x80(%rip),%xmm5
	VMULSD		%xmm0,%xmm0,%xmm3                	#x * x  x2 xmm3

	VFMADDSD %xmm5,.L_Sin+0xA0(%rip),%xmm3,%xmm5
	VFMADDSD .L_Sin+0x60(%rip),%xmm5,%xmm3,%xmm5
	VFMADDSD .L_Sin+0x40(%rip),%xmm5,%xmm3,%xmm5
	VFMADDSD .L_Sin+0x20(%rip),%xmm5,%xmm3,%xmm5	#xmm5 r

	VMULSD 		%xmm3,%xmm0,%xmm4					#x2 * x x3  xmm4
	VFMADDSD .L_Sin(%rip),%xmm3,%xmm5,%xmm6
	VFMADDSD %xmm0,%xmm6,%xmm4,%xmm0				# xmm6 res1

	.endm


.macro  sin_piby4_s


	VMOVAPD .L_Sin+0x80(%rip),%xmm5
	VMULSD		%xmm0,%xmm0,%xmm3                	#x * x  x2 xmm3
	VFMADDSD %xmm5,.L_Sin+0xA0(%rip),%xmm3,%xmm5
	VFMADDSD .L_Sin+0x60(%rip),%xmm5,%xmm3,%xmm5
	VFMADDSD .L_Sin+0x40(%rip),%xmm5,%xmm3,%xmm5
	VFMADDSD .L_Sin+0x20(%rip),%xmm5,%xmm3,%xmm5	#xmm5 r

	VMULSD 		%xmm3,%xmm0,%xmm4					#x2 * x x3  xmm4
	VMULSD	%xmm5,%xmm4,%xmm2		  	        	# xx,-(x3 * r)
	VMULSD	.L_point_five(%rip),%xmm1,%xmm5			# (0.5*xx)-(x3 * r)
	VSUBSD	%xmm2,%xmm5,%xmm2
	VMULSD %xmm2,%xmm3,%xmm2
	VSUBSD %xmm1,%xmm2,%xmm2
	VFNMADDSD %xmm2,.L_Sin(%rip),%xmm4,%xmm2
	VSUBSD	%xmm2,%xmm0,%xmm0						#res2 %xmm2
	.endm

.macro tan_piby4_s

	VCMPGTPD .L_point_68(%rip),%xmm0,%xmm2
	VCMPLTPD .L_n_point_68(%rip),%xmm0,%xmm9
	VANDPD	.L_signbit(%rip),%xmm2,%xmm7
	VXORPD	%xmm7,%xmm0,%xmm5				# x-
	VXORPD	%xmm7,%xmm1,%xmm6				# xx-
	VANDPD	.L_signbit(%rip),%xmm9,%xmm7	# transform -1 if xmm9 set
	VADDPD	.L_piby4_lead(%rip),%xmm5,%xmm5
	VADDPD	.L_piby4_tail(%rip),%xmm6,%xmm6
	VADDPD	%xmm6,%xmm5,%xmm5				# x
	VORPD	%xmm2,%xmm9,%xmm8				# transform mask xmm8
	VPCMOV	%xmm8,%xmm0,%xmm5,%xmm0
	VXORPD	%xmm9,%xmm9,%xmm9
	VPCMOV	%xmm8,%xmm1,%xmm9,%xmm1		# xmm0 x xmm1 xx
	VMULSD	%xmm0,%xmm0,%xmm9				# x2 xmm9
	VMULSD	%xmm0,%xmm1,%xmm4        # x * xx xmm4
	VFMADDSD	%xmm9,.L_two(%rip),%xmm4,%xmm2	   # xmm2 r
	VMOVAPD	 .L_tan_c3(%rip),%xmm9
	VFMADDSD .L_tan_c2(%rip),%xmm9,%xmm2,%xmm9
	VFMADDSD .L_tan_c1(%rip),%xmm9,%xmm2,%xmm9
	VMOVAPD	  .L_tan_c7(%rip),%xmm4
	VFNMADDSD .L_tan_c6(%rip),%xmm4,%xmm2,%xmm4
	VFMADDSD .L_tan_c5(%rip),%xmm4,%xmm2,%xmm4
	VFMADDSD .L_tan_c4(%rip),%xmm4,%xmm2,%xmm4
	VDIVSD	%xmm4,%xmm9,%xmm9
	VMULSD	%xmm2,%xmm9,%xmm9
	VFMADDSD %xmm1,%xmm0,%xmm9,%xmm9			# t2
	VADDSD		%xmm9,%xmm0,%xmm1				# t = t1+ t2 xmm1 res3

	VPCOMEQUQ .L_int_one(%rip),%xmm3,%xmm3		# recp mask xmm11

	VMOVDDUP	%xmm8,%xmm8
	VPTEST %xmm8,%xmm8
	JZ if_recip_set

if_transfor_set:

	VMULSD		.L_two(%rip),%xmm1,%xmm6 # 2*t
	VMOVAPD		.L_one(%rip),%xmm4
	VSUBSD		%xmm4,%xmm1,%xmm5		# t-1
	VADDSD		%xmm4,%xmm1,%xmm10		# t+1
	VPCMOV	   %xmm3,%xmm10,%xmm5,%xmm5
	VDIVSD	   %xmm5,%xmm6,%xmm5			# 2*t/(t-1) or 2*t/(t+1)
	VSUBSD		%xmm5,%xmm4,%xmm6      #(1.0 - 2*t/(1+t)
	VSUBSD		%xmm4,%xmm5,%xmm5       #(2*t/(t-1) - 1.0)
	VPCMOV	   %xmm3,%xmm6,%xmm5,%xmm6
	VXORPD		%xmm6,%xmm7,%xmm6		# res1
	JMP exit_tanpiby4

if_recip_set:
	VMOVDDUP	%xmm3,%xmm3
	VPTEST %xmm3,%xmm3
	JZ exit_tanpiby4

	VANDPD  .L_half_mask(%rip),%xmm1,%xmm2		# xmm2 z1
	VSUBSD	%xmm0,%xmm2,%xmm4
	VSUBSD	%xmm4,%xmm9,%xmm4					# xmm4 z2
	VMOVAPD	.L_n_one(%rip),%xmm9
	VDIVSD	 %xmm1,%xmm9,%xmm9					# xmm9 trec
	VANDPD  .L_half_mask(%rip),%xmm9,%xmm7		# xmm7 trec_top
	VFMADDSD .L_one(%rip),%xmm7,%xmm2,%xmm2		#
	VFMADDSD  %xmm2,%xmm7,%xmm4,%xmm2			#
	VFMADDSD  %xmm7,%xmm9,%xmm2,%xmm2			# xmm2 res2

exit_tanpiby4:
	VPCMOV %xmm3,%xmm1,%xmm2,%xmm0
	VPCMOV %xmm8,%xmm0,%xmm6,%xmm0				# xmm6 res1

	.endm



.macro tan_piby4_s_zero

	VCMPGTPD .L_point_68(%rip),%xmm0,%xmm2
	VCMPLTPD .L_n_point_68(%rip),%xmm0,%xmm9
	VANDPD	.L_signbit(%rip),%xmm2,%xmm7
	VXORPD	%xmm7,%xmm0,%xmm5				# x-
	VANDPD	.L_signbit(%rip),%xmm9,%xmm7	# transform -1 if xmm9 set
	VADDPD	.L_piby4_lead(%rip),%xmm5,%xmm5
	VADDPD	.L_piby4_tail(%rip),%xmm5,%xmm5	# x
	VORPD	%xmm2,%xmm9,%xmm8				# transform mask xmm8
	VPCMOV	%xmm8,%xmm0,%xmm5,%xmm0
	VXORPD	%xmm9,%xmm9,%xmm9
	VMULSD	%xmm0,%xmm0,%xmm2				#  xmm2 r
	VMOVAPD	 .L_tan_c3(%rip),%xmm9
	VFMADDSD .L_tan_c2(%rip),%xmm9,%xmm2,%xmm9
	VFMADDSD .L_tan_c1(%rip),%xmm9,%xmm2,%xmm9
	VMOVAPD	  .L_tan_c7(%rip),%xmm4
	VFNMADDSD .L_tan_c6(%rip),%xmm4,%xmm2,%xmm4
	VFMADDSD .L_tan_c5(%rip),%xmm4,%xmm2,%xmm4
	VFMADDSD .L_tan_c4(%rip),%xmm4,%xmm2,%xmm4
	VDIVSD	%xmm4,%xmm9,%xmm9
	VMULSD	%xmm2,%xmm9,%xmm9
	VMULSD  %xmm0,%xmm9,%xmm9			# t2
	VADDSD		%xmm9,%xmm0,%xmm0				# t = t1+ t2 xmm1 res3
	VMOVDDUP %xmm8,%xmm8
	VPTEST %xmm8,%xmm8
	JZ ext_tanpiby4_zero
	VMULSD		.L_two(%rip),%xmm0,%xmm6
	VADDSD		.L_one(%rip),%xmm0,%xmm4
	VDIVSD		%xmm4,%xmm6,%xmm6
	VMOVAPD		.L_one(%rip),%xmm4
	VSUBSD		%xmm6,%xmm4,%xmm6
	VXORPD		%xmm6,%xmm7,%xmm6
	VPCMOV	%xmm8,%xmm0,%xmm6,%xmm0
ext_tanpiby4_zero:

	.endm


############# End  scalar double ##############


.macro  call_remainder_piby2

    lea  .L__Pibits(%rip),%r9
    #xexp = (x >> 52) - 1023
    movd %xmm0, %r11
    mov  %r11,  %rcx
    shr  $52,   %r11
    sub  $1023, %r11      #r11 = xexp = exponent of input x
    #calculate the last byte from which to start multiplication
    #last = 134 - (xexp >> 3)
    mov  %r11, %r10
    shr  $3,   %r10
    sub  $134, %r10       #r10 = -last
    neg  %r10             #r10 = last
    #load 64 bits of 2_by_pi
    mov  (%r9, %r10),%rax
    mov  %rdx, %rdi      # save address of region since mul modifies rdx
    #mantissa of x = ((x << 12) >> 12) | implied bit
    shl  $12,   %rcx
    shr  $12,   %rcx      #rcx = mantissa part of input x
    bts  $52,   %rcx      #add the implied bit as well
    #load next 128 bits of 2_by_pi
    add  $8, %r10        #increment to next 8 bytes of 2_by_pi
    movdqu (%r9, %r10), %xmm0
    #do three 64-bit multiplications with mant of x
    mul  %rcx
    mov  %rax, %r8       #r8 = last 64 bits of multiplication = res1[2]
    mov  %rdx, %r10      #r10 = carry
    movd %xmm0, %rax
    mul  %rcx
    #resexp = xexp & 7
    and  $7, %r11        #r11 = resexp = xexp & 7 = last 3 bits
    psrldq $8, %xmm0
    add  %r10, %rax      # add the previous carry
    adc  $0,   %rdx
    mov  %rax, %r9       #r9 = next 64 bits of multiplication = res1[1]
    mov  %rdx, %r10      #r10 = carry
    movd %xmm0,%rax
    mul  %rcx
    add  %rax, %r10      #r10 = most significant 64 bits = res1[0]
    #find the region
    #last three bits ltb = most sig bits >> (54 - resexp)); // decimal point in last 18 bits == 8 lsb's in first 64 bits and 8 msb's in next 64 bits
    #point_five = ltb & 0x1;
    #region = ((ltb >> 1) + point_five) & 3;
    mov $54,  %rcx
    mov %r10, %rax
    sub %r11, %rcx
    xor %rdx, %rdx       #rdx = sign of x(i.e first part of x * 2bypi)
    shr %cl,  %rax
    jnc  .L__no_point_five
    ##if there is carry.. then negate the result of multiplication
    not  %r10
    not  %r9
    not  %r8
    mov $0x8000000000000000,%rdx

#.p2align 4
.L__no_point_five:
    adc $0,   %rax
    and $3,   %rax
    VMOVD %eax, %xmm11   #store region to xmm11
    #calculate the number of integer bits and zero them out
    mov %r11, %rcx
    add $10,  %rcx  #rcx = no. of integer bits
    shl %cl,  %r10
    shr %cl,  %r10  #r10 contains only mant bits
    sub $64,  %rcx  #form the exponent
    mov %rcx, %r11
    #find the highest set bit
    bsr %r10,%rcx
    jnz  .L__form_mantissa
    mov %r9,%r10
    mov %r8,%r9
    mov $0, %r8
    bsr %r10,%rcx  #rcx = hsb
    sub $64, %r11

#.p2align 4
.L__form_mantissa:
    add %rcx,%r11  #for exp of x
    sub $52,%rcx #rcx = no. of bits to shift in r10
    cmp $0,%rcx
    jl  .L__hsb_below_52
    je  .L__form_numbers
    #hsb above 52
    mov %r10,%r8 #previous contents of r8 not required
    shr %cl,%r10 #r10 = mantissa of x with hsb at 52
    shr %cl,%r9  #make space for bits from r10
    sub $64,%rcx
    neg %rcx     #rvx = no of bits to shift r10 to move those bits to r9
    shl %cl,%r8
    or  %r8,%r9  #r9 = mantissa bits of xx
    jmp .L__form_numbers

#.p2align 4
.L__hsb_below_52:
    neg %rcx
    mov %r9,%rax
    shl %cl,%r10
    shl %cl,%r9
    sub $64,%rcx
    neg %rcx
    shr %cl,%rax
    or  %rax,%r10
    shr %cl,%r8
    or  %r8,%r9


#.p2align 4
.L__form_numbers:
    add $1023, %r11
    btr $52,%r10     #remove the implied bit
    mov %r11,%rcx
    or  %rdx,%r10    #put the sign
    shl $52, %rcx
    or  %rcx,%r10    #x is in r10
    movd %r10,%xmm8  #xmm8 = x
    #form xx
    xor %rcx,%rcx
    bsr %r9,%rcx
    sub $64, %rcx   #to shift the implied bit as well
    neg %rcx
    shl %cl,%r9
    shr $12,%r9
    add $52,%rcx
    sub %rcx, %r11
    shl $52, %r11
    or  %rdx,%r9
    or  %r11,%r9
    movd %r9,%xmm1  #xmm1 = xx
	# tx
	VANDPD .L_fff800(%rip),%xmm8,%xmm4   # xmm4 hx
	VSUBSD	%xmm4,%xmm8,%xmm6     # xmm6 tx
	# c
	VMULSD	.L_piby2_lead(%rip),%xmm8,%xmm5  # xmm5 c
	# cc
	VMULSD	.L_piby2_part1(%rip),%xmm4,%xmm7
	VSUBSD	%xmm5,%xmm7,%xmm7
	VFMADDSD  %xmm7,.L_piby2_part1(%rip),%xmm6,%xmm7
	VFMADDSD  %xmm7,.L_piby2_part2(%rip),%xmm4,%xmm7
	VFMADDSD  %xmm7,.L_piby2_part2(%rip),%xmm6,%xmm7
	VMULSD	.L_piby2_lead(%rip),%xmm1,%xmm9
	VFMADDSD  %xmm9,.L_piby2_part3(%rip),%xmm8,%xmm9
	VADDSD	%xmm9,%xmm7,%xmm7	# xmm7 cc
	VADDSD %xmm7,%xmm5,%xmm0		# r
	VSUBSD %xmm0,%xmm5,%xmm1
	VADDSD %xmm7,%xmm1,%xmm1		# rr

	.endm


.macro   call_remainder_2fpiby2

	push %r12
	push %r13

	VMAXPD	.L_two(%rip),%xmm0,%xmm0
	VANDPD .L__inf_mask_64(%rip),%xmm0,%xmm1
	VPSRLQ	$52,%xmm1,%xmm1
	VPSUBQ	.L_1023(%rip),%xmm1,%xmm1			# xmm1 xexp
	VANDPD .L__mant_mask_64(%rip),%xmm0,%xmm2
	VORPD .L__imp_mask_64(%rip),%xmm2,%xmm2		# xmm2 ux
	VPSRLQ	$3,%xmm1,%xmm3
	VMOVAPD	.L_157(%rip),%xmm4
	VPSUBQ  %xmm3,%xmm4,%xmm5			# xmm5 first
	VPSLLQ	$3,%xmm3,%xmm3
	VPSUBQ %xmm3,%xmm1,%xmm1			# xmm1 resexp
	VPSUBQ .L_23(%rip),%xmm5,%xmm3			# xmm3 last
	VMOVQ %xmm3,%r12					# index lo
	VPUNPCKHQDQ %xmm3,%xmm3,%xmm3
	VMOVQ %xmm3,%r13					# index hi
	lea .L__Pibits(%rip),%r11
	MOV (%r11,%r12),%rax
	VMOVQ %xmm2,%rcx		#ux
	MUL	%rcx
	VMOVQ	%rax,%xmm9
	MOV	%rdx,%r9			# carry
	VPUNPCKHQDQ %xmm2,%xmm2,%xmm2
	VMOVQ %xmm2,%r8		#ux
	MOV (%r11,%r13),%rax
	MUL	%r8
	VMOVQ %rax,%xmm6
	VPUNPCKLQDQ	%xmm6,%xmm9,%xmm9	# res[2] xmm9
	MOV	%rdx,%r10					# carry
	add $8,%r12
	add $8,%r13
	MOV (%r11,%r12),%rax
	MUL	%rcx
	ADD	%r9,%rax
	ADC	$0,%rdx
	VMOVQ	%rax,%xmm7		# res[1] xmm7
	MOV	%rdx,%r9			# cary
	MOV (%r11,%r13),%rax
	MUL	%r8
	ADD	%r10,%rax
	ADC	$0,%rdx
	VMOVQ %rax,%xmm6
	VPUNPCKLQDQ	%xmm6,%xmm7,%xmm7	# res[1] xmm7
	MOV	%rdx,%r10					# carry
	add $8,%r12
	add $8,%r13
	MOV (%r11,%r12),%rax
	MUL	%rcx
	ADD	%r9,%rax
	ADC	$0,%rdx
	VMOVQ	%rax,%xmm6		# res[0] xmm6
	MOV (%r11,%r13),%rax
	MUL	%r8
	ADD	%r10,%rax
	ADC	$0,%rdx
	VMOVQ %rax,%xmm8
	VPUNPCKLQDQ	%xmm8,%xmm6,%xmm6	# res[0] xmm6
	#ltb
	VPSUBQ	.L_53(%rip),%xmm1,%xmm3
	VPSHLQ	%xmm3,%xmm6,%xmm4		# ltb xmm4
	VPAND	.L_int_one(%rip),%xmm4,%xmm3   # xmm3 	point_five
	VPSRLQ	$1,%xmm4,%xmm4
	VPADDQ	%xmm3,%xmm4,%xmm4
	VPAND	.L_int_three(%rip),%xmm4,%xmm11	# xmm11 region
	VPCOMEQUQ .L_int_one(%rip),%xmm3,%xmm3
	VXORPD	%xmm3,%xmm6,%xmm6		#res[0]
	VXORPD	%xmm3,%xmm7,%xmm7		#res[1]
	VXORPD	%xmm3,%xmm9,%xmm9		#res[2]
	VANDPD	.L_signbit(%rip),%xmm3,%xmm3  					#sign xmm3
	VPADDQ	.L_10(%rip),%xmm1,%xmm4	 # initbits xmm4
	# remove all the integer bits
	VPSHLQ %xmm4,%xmm9,%xmm10	# new res[2] 10
	VPSUBQ	.L_64(%rip),%xmm4,%xmm5
	VPSHLQ %xmm5,%xmm9,%xmm9
	VPSHLQ %xmm4,%xmm7,%xmm8
	VORPD	%xmm8,%xmm9,%xmm9	#new res[1] 9
	VPSHLQ %xmm5,%xmm7,%xmm7
	VPSHLQ %xmm4,%xmm6,%xmm6
	VORPD	%xmm6,%xmm7,%xmm8	#new res[0] 8
	#leading bit set
	VMOVQ	%xmm8,%r10
	VPUNPCKHQDQ %xmm8,%xmm8,%xmm7
	VMOVQ %xmm7,%r9
	bsr %r10,%rcx
	bsr %r9,%rax
	VMOVQ %rcx,%xmm7
	VMOVQ %rax,%xmm6
	VPUNPCKLQDQ	%xmm6,%xmm7,%xmm7
	VMOVAPD .L_64(%rip),%xmm12
	VPSUBQ %xmm7,%xmm12,%xmm6	# xmm6 shift bits xmm7 highest set bit
	VPXOR %xmm13,%xmm13,%xmm13   # zero
	VPSUBQ %xmm7,%xmm13,%xmm13
	VPSHLQ	%xmm6,%xmm10,%xmm2	# new res[2] xmm2
	VPSHLQ	%xmm13,%xmm10,%xmm10
	VPSHLQ	%xmm6,%xmm9,%xmm4
	VPOR	%xmm10,%xmm4,%xmm4	# new res[1] xmm4
	VPSHLQ	%xmm13,%xmm9,%xmm9
	VPSHLQ	%xmm6,%xmm8,%xmm5
	VPOR	%xmm9,%xmm5,%xmm5	# new res[0] xmm5
	# construct x;
	VPADDQ	.L_959(%rip),%xmm7,%xmm7	# xmm7 rexp
	VPSLLQ	$52,%xmm7,%xmm6
	VPSRLQ $12,%xmm5,%xmm8				# xmm8 mant
	VPOR	%xmm8,%xmm6,%xmm8
	VPOR	%xmm8,%xmm3,%xmm8		# xmm8 x
	# for xx
	VPSLLQ $52,%xmm5,%xmm6
	VPSRLQ $12,%xmm4,%xmm9
	VPOR %xmm6,%xmm9,%xmm6		# xmm6 mant
	VMOVQ	%xmm6,%r10
	VPUNPCKHQDQ %xmm6,%xmm6,%xmm1
	VMOVQ %xmm1,%r9
	bsr %r10,%rcx
	bsr %r9,%rax
	VMOVQ %rcx,%xmm1
	VMOVQ %rax,%xmm13
	VPUNPCKLQDQ	%xmm13,%xmm1,%xmm1   # high set bit xmm1
	VPSUBQ %xmm1,%xmm12,%xmm13	# xmm13 shift bits
	VPSLLQ	$52,%xmm4,%xmm9
	VPSRLQ	$12,%xmm2,%xmm10
	VPOR	%xmm10,%xmm9,%xmm9	# temp
	VPXOR	%xmm12,%xmm12,%xmm12
	VPSUBQ	%xmm1,%xmm12,%xmm12			# change sign to shift right
	VPSHLQ	%xmm12,%xmm9,%xmm9
	VPSHLQ	%xmm13,%xmm6,%xmm10
	VPOR	%xmm10,%xmm9,%xmm9	# mant
	VPSRLQ	$12,%xmm9,%xmm9		# mant
	# construct xx
	VPSUBQ .L_116(%rip),%xmm7,%xmm7
	VPADDQ %xmm7,%xmm1,%xmm1
	VPSLLQ	$52,%xmm1,%xmm1
	VPOR	%xmm9,%xmm1,%xmm1
	VPOR	%xmm3,%xmm1,%xmm1	#xx
	# tx
	VANDPD .L_fff800(%rip),%xmm8,%xmm4   # xmm4 hx
	VSUBPD	%xmm4,%xmm8,%xmm6     # xmm6 tx
	# c
	VMULPD	.L_piby2_lead(%rip),%xmm8,%xmm5  # xmm5 c
	# cc
	VMULPD	.L_piby2_part1(%rip),%xmm4,%xmm7
	VSUBPD	%xmm5,%xmm7,%xmm7
	VFMADDPD  %xmm7,.L_piby2_part1(%rip),%xmm6,%xmm7
	VFMADDPD  %xmm7,.L_piby2_part2(%rip),%xmm4,%xmm7
	VFMADDPD  %xmm7,.L_piby2_part2(%rip),%xmm6,%xmm7
	VMULPD	.L_piby2_lead(%rip),%xmm1,%xmm9
	VFMADDPD  %xmm9,.L_piby2_part3(%rip),%xmm8,%xmm9
	VADDPD	%xmm9,%xmm7,%xmm7	# xmm7 cc
	VADDPD %xmm7,%xmm5,%xmm0		# r
	VSUBPD %xmm0,%xmm5,%xmm1
	VADDPD %xmm7,%xmm1,%xmm1		# rr

	pop %r13
	pop %r12
	.endm

.macro  call_remainder_2fpiby2_4f
	push %r12
	push %r13

	VMOVAPD	 %ymm0,%ymm14
	VMAXPD	.L_two(%rip),%xmm0,%xmm0
	VANDPD .L__inf_mask_64(%rip),%xmm0,%xmm1
	VPSRLQ	$52,%xmm1,%xmm1
	VPSUBQ	.L_1023(%rip),%xmm1,%xmm1			# xmm1 xexp
	VANDPD .L__mant_mask_64(%rip),%xmm0,%xmm2
	VORPD .L__imp_mask_64(%rip),%xmm2,%xmm2		# xmm2 ux
	VPSRLQ	$3,%xmm1,%xmm3
	VMOVAPD	.L_157(%rip),%xmm4
	VPSUBQ  %xmm3,%xmm4,%xmm5			# xmm5 first
	VPSLLQ	$3,%xmm3,%xmm3
	VPSUBQ %xmm3,%xmm1,%xmm1			# xmm1 resexp
	VPSUBQ .L_23(%rip),%xmm5,%xmm3			# xmm3 last
	VMOVQ %xmm3,%r12					# index lo
	VPUNPCKHQDQ %xmm3,%xmm3,%xmm3
	VMOVQ %xmm3,%r13					# index hi
	lea .L__Pibits(%rip),%r11
	MOV (%r11,%r12),%rax
	VMOVQ %xmm2,%rcx		#ux
	MUL	%rcx
	VMOVQ	%rax,%xmm9
	MOV	%rdx,%r9			# carry
	VPUNPCKHQDQ %xmm2,%xmm2,%xmm2
	VMOVQ %xmm2,%r8		#ux
	MOV (%r11,%r13),%rax
	MUL	%r8
	VMOVQ %rax,%xmm6
	VPUNPCKLQDQ	%xmm6,%xmm9,%xmm9	# res[2] xmm9
	MOV	%rdx,%r10					# carry
	add $8,%r12
	add $8,%r13
	MOV (%r11,%r12),%rax
	MUL	%rcx
	ADD	%r9,%rax
	ADC	$0,%rdx
	VMOVQ	%rax,%xmm7		# res[1] xmm7
	MOV	%rdx,%r9			# cary
	MOV (%r11,%r13),%rax
	MUL	%r8
	ADD	%r10,%rax
	ADC	$0,%rdx
	VMOVQ %rax,%xmm6
	VPUNPCKLQDQ	%xmm6,%xmm7,%xmm7	# res[1] xmm7
	MOV	%rdx,%r10					# carry
	add $8,%r12
	add $8,%r13
	MOV (%r11,%r12),%rax
	MUL	%rcx
	ADD	%r9,%rax
	ADC	$0,%rdx
	VMOVQ	%rax,%xmm6		# res[0] xmm6
	MOV (%r11,%r13),%rax
	MUL	%r8
	ADD	%r10,%rax
	ADC	$0,%rdx
	VMOVQ %rax,%xmm8
	VPUNPCKLQDQ	%xmm8,%xmm6,%xmm6	# res[0] xmm6
	#ltb
	VPSUBQ	.L_53(%rip),%xmm1,%xmm3
	VPSHLQ	%xmm3,%xmm6,%xmm4		# ltb xmm4
	VPAND	.L_int_one(%rip),%xmm4,%xmm3   # xmm3 	point_five
	VPSRLQ	$1,%xmm4,%xmm4
	VPADDQ	%xmm3,%xmm4,%xmm4
	VPAND	.L_int_three(%rip),%xmm4,%xmm11	# xmm11 region
	VPCOMEQUQ .L_int_one(%rip),%xmm3,%xmm3
	VXORPD	%xmm3,%xmm6,%xmm6		#res[0]
	VXORPD	%xmm3,%xmm7,%xmm7		#res[1]
	VXORPD	%xmm3,%xmm9,%xmm9		#res[2]
	VANDPD	.L_signbit(%rip),%xmm3,%xmm3  					#sign xmm3
	VPADDQ	.L_10(%rip),%xmm1,%xmm4	 # initbits xmm4
	# remove all the integer bits
	VPSHLQ %xmm4,%xmm9,%xmm10	# new res[2] 10
	VPSUBQ	.L_64(%rip),%xmm4,%xmm5
	VPSHLQ %xmm5,%xmm9,%xmm9
	VPSHLQ %xmm4,%xmm7,%xmm8
	VORPD	%xmm8,%xmm9,%xmm9	#new res[1] 9
	VPSHLQ %xmm5,%xmm7,%xmm7
	VPSHLQ %xmm4,%xmm6,%xmm6
	VORPD	%xmm6,%xmm7,%xmm8	#new res[0] 8
	#leading bit set
	VMOVQ	%xmm8,%r10
	VPUNPCKHQDQ %xmm8,%xmm8,%xmm7
	VMOVQ %xmm7,%r9
	bsr %r10,%rcx
	bsr %r9,%rax
	VMOVQ %rcx,%xmm7
	VMOVQ %rax,%xmm6
	VPUNPCKLQDQ	%xmm6,%xmm7,%xmm7
	VMOVAPD .L_64(%rip),%xmm12
	VPSUBQ %xmm7,%xmm12,%xmm6	# xmm6 shift bits xmm7 highest set bit
	VPXOR %xmm13,%xmm13,%xmm13   # zero
	VPSUBQ %xmm7,%xmm13,%xmm13
	VPSHLQ	%xmm6,%xmm10,%xmm2	# new res[2] xmm2
	VPSHLQ	%xmm13,%xmm10,%xmm10
	VPSHLQ	%xmm6,%xmm9,%xmm4
	VPOR	%xmm10,%xmm4,%xmm4	# new res[1] xmm4
	VPSHLQ	%xmm13,%xmm9,%xmm9
	VPSHLQ	%xmm6,%xmm8,%xmm5
	VPOR	%xmm9,%xmm5,%xmm5	# new res[0] xmm5
	# construct x;
	VPADDQ	.L_959(%rip),%xmm7,%xmm7	# xmm7 rexp
	VPSLLQ	$52,%xmm7,%xmm6
	VPSRLQ $12,%xmm5,%xmm8				# xmm8 mant
	VPOR	%xmm8,%xmm6,%xmm8
	VEXTRACTF128 $1,%ymm14,%xmm0
	VPOR	%xmm8,%xmm3,%xmm14		# xmm14 x
	VMAXPD	.L_two(%rip),%xmm0,%xmm0
	VANDPD .L__inf_mask_64(%rip),%xmm0,%xmm1
	VPSRLQ	$52,%xmm1,%xmm1
	VPSUBQ	.L_1023(%rip),%xmm1,%xmm1			# xmm1 xexp
	VANDPD .L__mant_mask_64(%rip),%xmm0,%xmm2
	VORPD .L__imp_mask_64(%rip),%xmm2,%xmm2		# xmm2 ux
	VPSRLQ	$3,%xmm1,%xmm3
	VMOVAPD	.L_157(%rip),%xmm4
	VPSUBQ  %xmm3,%xmm4,%xmm5			# xmm5 first
	VPSLLQ	$3,%xmm3,%xmm3
	VPSUBQ %xmm3,%xmm1,%xmm1			# xmm1 resexp
	VPSUBQ .L_23(%rip),%xmm5,%xmm3			# xmm3 last
	VMOVQ %xmm3,%r12					# index lo
	VPUNPCKHQDQ %xmm3,%xmm3,%xmm3
	VMOVQ %xmm3,%r13					# index hi
	lea .L__Pibits(%rip),%r11
	MOV (%r11,%r12),%rax
	VMOVQ %xmm2,%rcx		#ux
	MUL	%rcx
	VMOVQ	%rax,%xmm9
	MOV	%rdx,%r9			# carry
	VPUNPCKHQDQ %xmm2,%xmm2,%xmm2
	VMOVQ %xmm2,%r8		#ux
	MOV (%r11,%r13),%rax
	MUL	%r8
	VMOVQ %rax,%xmm6
	VPUNPCKLQDQ	%xmm6,%xmm9,%xmm9	# res[2] xmm9
	MOV	%rdx,%r10					# carry
	add $8,%r12
	add $8,%r13
	MOV (%r11,%r12),%rax
	MUL	%rcx
	ADD	%r9,%rax
	ADC	$0,%rdx
	VMOVQ	%rax,%xmm7		# res[1] xmm7
	MOV	%rdx,%r9			# cary
	MOV (%r11,%r13),%rax
	MUL	%r8
	ADD	%r10,%rax
	ADC	$0,%rdx
	VMOVQ %rax,%xmm6
	VPUNPCKLQDQ	%xmm6,%xmm7,%xmm7	# res[1] xmm7
	MOV	%rdx,%r10					# carry
	add $8,%r12
	add $8,%r13
	MOV (%r11,%r12),%rax
	MUL	%rcx
	ADD	%r9,%rax
	ADC	$0,%rdx
	VMOVQ	%rax,%xmm6		# res[0] xmm6
	MOV (%r11,%r13),%rax
	MUL	%r8
	ADD	%r10,%rax
	ADC	$0,%rdx
	VMOVQ %rax,%xmm8
	VPUNPCKLQDQ	%xmm8,%xmm6,%xmm6	# res[0] xmm6
	#ltb
	VPSUBQ	.L_53(%rip),%xmm1,%xmm3
	VPSHLQ	%xmm3,%xmm6,%xmm4		# ltb xmm4
	VPAND	.L_int_one(%rip),%xmm4,%xmm3   # xmm3 	point_five
	VPSRLQ	$1,%xmm4,%xmm4
	VPADDQ	%xmm3,%xmm4,%xmm4
	VPAND	.L_int_three(%rip),%xmm4,%xmm4	# xmm11 region
	VINSERTF128 $1,%xmm4,%ymm11,%ymm11
	VPCOMEQUQ .L_int_one(%rip),%xmm3,%xmm3
	VXORPD	%xmm3,%xmm6,%xmm6		#res[0]
	VXORPD	%xmm3,%xmm7,%xmm7		#res[1]
	VXORPD	%xmm3,%xmm9,%xmm9		#res[2]
	VANDPD	.L_signbit(%rip),%xmm3,%xmm3  					#sign xmm3
	VPADDQ	.L_10(%rip),%xmm1,%xmm4	 # initbits xmm4
	# remove all the integer bits
	VPSHLQ %xmm4,%xmm9,%xmm10	# new res[2] 10
	VPSUBQ	.L_64(%rip),%xmm4,%xmm5
	VPSHLQ %xmm5,%xmm9,%xmm9
	VPSHLQ %xmm4,%xmm7,%xmm8
	VORPD	%xmm8,%xmm9,%xmm9	#new res[1] 9
	VPSHLQ %xmm5,%xmm7,%xmm7
	VPSHLQ %xmm4,%xmm6,%xmm6
	VORPD	%xmm6,%xmm7,%xmm8	#new res[0] 8
	#leading bit set
	VMOVQ	%xmm8,%r10
	VPUNPCKHQDQ %xmm8,%xmm8,%xmm7
	VMOVQ %xmm7,%r9
	bsr %r10,%rcx
	bsr %r9,%rax
	VMOVQ %rcx,%xmm7
	VMOVQ %rax,%xmm6
	VPUNPCKLQDQ	%xmm6,%xmm7,%xmm7
	VMOVAPD .L_64(%rip),%xmm12
	VPSUBQ %xmm7,%xmm12,%xmm6	# xmm6 shift bits xmm7 highest set bit
	VPXOR %xmm13,%xmm13,%xmm13   # zero
	VPSUBQ %xmm7,%xmm13,%xmm13
	VPSHLQ	%xmm6,%xmm10,%xmm2	# new res[2] xmm2
	VPSHLQ	%xmm13,%xmm10,%xmm10
	VPSHLQ	%xmm6,%xmm9,%xmm4
	VPOR	%xmm10,%xmm4,%xmm4	# new res[1] xmm4
	VPSHLQ	%xmm13,%xmm9,%xmm9
	VPSHLQ	%xmm6,%xmm8,%xmm5
	VPOR	%xmm9,%xmm5,%xmm5	# new res[0] xmm5
	# construct x;
	VPADDQ	.L_959(%rip),%xmm7,%xmm7	# xmm7 rexp
	VPSLLQ	$52,%xmm7,%xmm6
	VPSRLQ $12,%xmm5,%xmm8				# xmm8 mant
	VPOR	%xmm8,%xmm6,%xmm8
	VPOR	%xmm8,%xmm3,%xmm8		# xmm8 x
	VINSERTF128 $1,%xmm8,%ymm14,%ymm0
   	VMULPD .L_piby2_lead(%rip),%ymm0,%ymm0

	pop %r13
	pop %r12

	.endm


.macro  call_remainder_piby2_f


    lea  .L__Pibits(%rip),%r9
    #xexp = (x >> 52) - 1023
    movd %xmm0, %r11
    mov  %r11,  %rcx
    shr  $52,   %r11
    sub  $1023, %r11      #r11 = xexp = exponent of input x
    #calculate the last byte from which to start multiplication
    #last = 134 - (xexp >> 3)
    mov  %r11, %r10
    shr  $3,   %r10
    sub  $134, %r10       #r10 = -last
    neg  %r10             #r10 = last
    #load 64 bits of 2_by_pi
    mov  (%r9, %r10),%rax
    mov  %rdx, %rdi      # save address of region since mul modifies rdx
    #mantissa of x = ((x << 12) >> 12) | implied bit
    shl  $12,   %rcx
    shr  $12,   %rcx      #rcx = mantissa part of input x
    bts  $52,   %rcx      #add the implied bit as well
    #load next 128 bits of 2_by_pi
    add  $8, %r10        #increment to next 8 bytes of 2_by_pi
    movdqu (%r9, %r10), %xmm0
    #do three 64-bit multiplications with mant of x
    mul  %rcx
    mov  %rax, %r8       #r8 = last 64 bits of multiplication = res1[2]
    mov  %rdx, %r10      #r10 = carry
    movd %xmm0, %rax
    mul  %rcx
    #resexp = xexp & 7
    and  $7, %r11        #r11 = resexp = xexp & 7 = last 3 bits
    psrldq $8, %xmm0
    add  %r10, %rax      # add the previous carry
    adc  $0,   %rdx
    mov  %rax, %r9       #r9 = next 64 bits of multiplication = res1[1]
    mov  %rdx, %r10      #r10 = carry
    movd %xmm0,%rax
    mul  %rcx
    add  %rax, %r10      #r10 = most significant 64 bits = res1[0]
    #find the region
    #last three bits ltb = most sig bits >> (54 - resexp)); // decimal point in last 18 bits == 8 lsb's in first 64 bits and 8 msb's in next 64 bits
    #point_five = ltb & 0x1;
    #region = ((ltb >> 1) + point_five) & 3;
    mov $54,  %rcx
    mov %r10, %rax
    sub %r11, %rcx
    xor %rdx, %rdx       #rdx = sign of x(i.e first part of x * 2bypi)
    shr %cl,  %rax
    jnc  .L__no_point_five_f
    ##if there is carry.. then negate the result of multiplication
    not  %r10
    not  %r9
    not  %r8
    mov $0x8000000000000000,%rdx
.p2align 4
.L__no_point_five_f:
    adc $0,   %rax
    and $3,   %rax
    VMOVD %eax, %xmm11   #store region to xmm11
    #calculate the number of integer bits and zero them out
    mov %r11, %rcx
    add $10,  %rcx  #rcx = no. of integer bits
    shl %cl,  %r10
    shr %cl,  %r10  #r10 contains only mant bits
    sub $64,  %rcx  #form the exponent
    mov %rcx, %r11
    #find the highest set bit
    bsr %r10,%rcx
    jnz  .L__form_mantissa_f
    mov %r9,%r10
    mov %r8,%r9
    mov $0, %r8
    bsr %r10,%rcx  #rcx = hsb
    sub $64, %r11
.p2align 4
.L__form_mantissa_f:
    add %rcx,%r11  #for exp of x
    sub $52,%rcx #rcx = no. of bits to shift in r10
    cmp $0,%rcx
    jl  .L__hsb_below_52_f
    je  .L__form_numbers_f
    #hsb above 52
    mov %r10,%r8 #previous contents of r8 not required
    shr %cl,%r10 #r10 = mantissa of x with hsb at 52
    shr %cl,%r9  #make space for bits from r10
    sub $64,%rcx
    neg %rcx     #rvx = no of bits to shift r10 to move those bits to r9
    shl %cl,%r8
    or  %r8,%r9  #r9 = mantissa bits of xx
    jmp .L__form_numbers_f
.p2align 4
.L__hsb_below_52_f:
    neg %rcx
    mov %r9,%rax
    shl %cl,%r10
    shl %cl,%r9
    sub $64,%rcx
    neg %rcx
    shr %cl,%rax
    or  %rax,%r10
    shr %cl,%r8
    or  %r8,%r9
.p2align 4
.L__form_numbers_f:
    add $1023, %r11
    btr $52,%r10     #remove the implied bit
    mov %r11,%rcx
    or  %rdx,%r10    #put the sign
    shl $52, %rcx
    or  %rcx,%r10    #x is in r10
    movd %r10,%xmm0  #xmm0 = x
    VMULSD .L_piby2_lead(%rip),%xmm0,%xmm0
	.endm


.macro  range_e_5_2f_s


	VANDPD .L__sign_mask(%rip),%xmm0,%xmm1		 	#clear the sign

	VMOVAPD	 .L_twobypi(%rip),%xmm8
	VFMADDPD .L_point_five(%rip),%xmm8,%xmm1,%xmm8
	VCVTTPD2DQ %xmm8,%xmm8
	VPMOVSXDQ %xmm8,%xmm6

	VANDPD	.L_int_three(%rip),%xmm6,%xmm11			# region xmm11
	VSHUFPS $8,%xmm6,%xmm6,%xmm6
	VCVTDQ2PD	%xmm6,%xmm6
	VFNMADDPD %xmm0,.L_piby2_1(%rip),%xmm6,%xmm2		# xmm2 rhead
	VMULPD	.L_piby2_1tail(%rip),%xmm6,%xmm3			# xmm3 rtail
	VANDPD .L__inf_mask_64(%rip),%xmm2,%xmm4
	VPSRLQ $52,%xmm4,%xmm4
	VPSRLQ $52,%xmm0,%xmm5
	VPSUBQ	%xmm4,%xmm5,%xmm4						# expdiff xmm4

	VPCOMGTUQ  .L_val_15(%rip),%xmm4,%xmm8			# mask_expdiff15 xmm8
	VPTEST %xmm8,%xmm8
	JZ exit_range_e5

	VMOVAPD %xmm2,%xmm5
	VMULPD	.L_piby2_2(%rip),%xmm6,%xmm3 			# rtail_1 xmm3
	VSUBPD	%xmm3,%xmm5,%xmm2						# rhead_1 xmm2

	VSUBPD	%xmm2,%xmm5,%xmm1
	VSUBPD	%xmm3,%xmm1,%xmm1
	VXORPD	.L_signbit(%rip),%xmm1,%xmm1
	VFMADDPD  %xmm1,.L_piby2_2tail(%rip),%xmm6,%xmm3	# rtail_1 xmm5


	VPCOMGTUQ  .L_val_48(%rip),%xmm4,%xmm8			# mask_expdiff15 xmm8
	VPTEST %xmm8,%xmm8
	JZ exit_range_e5

	VMOVAPD %xmm2,%xmm5
	VMULPD	.L_piby2_3(%rip),%xmm6,%xmm3 			# rtail_1 xmm3
	VSUBPD	%xmm3,%xmm5,%xmm2						# rhead_1 xmm2

	VSUBPD	%xmm2,%xmm5,%xmm1
	VSUBPD	%xmm3,%xmm1,%xmm1
	VXORPD	.L_signbit(%rip),%xmm1,%xmm1
	VFMADDPD  %xmm1,.L_piby2_3tail(%rip),%xmm6,%xmm3	# rtail_1 xmm5

exit_range_e5:
	VSUBPD %xmm3,%xmm2,%xmm10						# r_1  xmm10
	VSUBPD %xmm10,%xmm2,%xmm4
	VSUBPD %xmm3,%xmm4,%xmm1						# rr_1 xmm4
	VMOVAPD %xmm10,%xmm0

	.endm


.macro  range_e_5_s4f


	VANDPD .L__sign_mask(%rip),%ymm0,%ymm1		 	#clear the sign

	VMOVAPD	 .L_twobypi(%rip),%ymm8
	VFMADDPD .L_point_five(%rip),%ymm8,%ymm1,%ymm8
	VCVTTPD2DQ %ymm8,%xmm8
	VPMOVSXDQ %xmm8,%xmm9
	VPUNPCKHQDQ %xmm8,%xmm8,%xmm8
	VPMOVSXDQ %xmm8,%xmm8

	VINSERTF128 $1,%xmm8,%ymm9,%ymm6

	VANDPD	.L_int_three(%rip),%ymm6,%ymm11			# region ymm11
	VEXTRACTF128 $1,%ymm6,%xmm7
	VSHUFPS $8,%xmm6,%xmm6,%xmm6
	VSHUFPS $8,%xmm7,%xmm7,%xmm7
	VPUNPCKLQDQ %xmm7,%xmm6,%xmm6
	VCVTDQ2PD	%xmm6,%ymm6
	VFNMADDPD %ymm0,.L_piby2_1(%rip),%ymm6,%ymm2		# ymm2 rhead
	VMULPD	.L_piby2_1tail(%rip),%ymm6,%ymm3			# ymm3 rtail

	VSUBPD %ymm3,%ymm2,%ymm10						# r_1  xmm10
	VSUBPD %ymm10,%ymm2,%ymm4
	VSUBPD %ymm3,%ymm4,%ymm1						# rr_1 xmm4
	VMOVAPD %ymm10,%ymm0


	.endm



.macro  range_e_5_sf


	VANDPD .L__sign_mask(%rip),%xmm0,%xmm1		 	#clear the sign
#	VPCOMLEUQ  .L_mask_5piby4(%rip),%xmm1,%xmm2
#	VPCOMLEUQ  .L_mask_3piby4(%rip),%xmm1,%xmm3
#	VPCOMLEUQ  .L_mask_9piby4(%rip),%xmm1,%xmm4
#	VPCOMLEUQ  .L_mask_7piby4(%rip),%xmm1,%xmm5
#	VANDPD	%xmm2,%xmm3,%xmm6					#
#	VANDPD	.L_int_one(%rip),%xmm6,%xmm6		#npi2_1  xmm6
#	VANDNPD	%xmm2,%xmm3,%xmm7					#
#	VANDPD	.L_int_two(%rip),%xmm7,%xmm7		#npi2_2  xmm7
#	VORPD	%xmm6,%xmm7,%xmm6					#npi2_2 xmm6
#	VANDNPD	%xmm4,%xmm2,%xmm7					#
#	VANDPD	%xmm7,%xmm5,%xmm8					#
#	VANDPD	.L_int_three(%rip),%xmm8,%xmm8		#npi2_3  xmm8
#	VANDNPD	%xmm7,%xmm5,%xmm7					#
#	VANDPD	.L_int_four(%rip),%xmm7,%xmm7		#npi2_4  xmm7
#	VORPD	%xmm7,%xmm8,%xmm7					#npi2_3 xmm7

	VMOVAPD	 .L_twobypi(%rip),%xmm8
	VFMADDSD .L_point_five(%rip),%xmm8,%xmm1,%xmm8
	VCVTTPD2DQ %xmm8,%xmm8
#	VPMOVSXDQ %xmm8,%xmm8
	#uncoment all and delete below line
	VPMOVSXDQ %xmm8,%xmm6

#	VANDNPD	 %xmm8,%xmm2,%xmm8
#	VANDNPD	 %xmm8,%xmm4,%xmm8					# xmm8 npi2_1
#	VORPD	%xmm8,%xmm7,%xmm7
#	VORPD	%xmm6,%xmm7,%xmm6					# npi2 xmm6

	VANDPD	.L_int_three(%rip),%xmm6,%xmm11			# region xmm11
	VSHUFPS $8,%xmm6,%xmm6,%xmm6
	VCVTDQ2PD	%xmm6,%xmm6
	VFNMADDSD %xmm0,.L_piby2_1(%rip),%xmm6,%xmm2		# xmm2 rhead
	VMULSD	.L_piby2_1tail(%rip),%xmm6,%xmm3			# xmm3 rtail

#	VANDPD .L__inf_mask_64(%rip),%xmm2,%xmm4
#	VPSRLQ $52,%xmm4,%xmm4
#	VPSRLQ $52,%xmm0,%xmm5
#	VPSUBQ	%xmm4,%xmm5,%xmm4						# expdiff xmm4


	VSUBSD %xmm3,%xmm2,%xmm10						# r_1  xmm10
	VSUBSD %xmm10,%xmm2,%xmm4
	VSUBSD %xmm3,%xmm4,%xmm1						# rr_1 xmm4
	VMOVAPD %xmm10,%xmm0

	.endm

.macro  range_e_5_s


	VANDPD .L__sign_mask(%rip),%xmm0,%xmm1		 	#clear the sign
#	VPCOMLEUQ  .L_mask_5piby4(%rip),%xmm1,%xmm2
#	VPCOMLEUQ  .L_mask_3piby4(%rip),%xmm1,%xmm3
#	VPCOMLEUQ  .L_mask_9piby4(%rip),%xmm1,%xmm4
#	VPCOMLEUQ  .L_mask_7piby4(%rip),%xmm1,%xmm5
#	VANDPD	%xmm2,%xmm3,%xmm6					#
#	VANDPD	.L_int_one(%rip),%xmm6,%xmm6		#npi2_1  xmm6
#	VANDNPD	%xmm2,%xmm3,%xmm7					#
#	VANDPD	.L_int_two(%rip),%xmm7,%xmm7		#npi2_2  xmm7
#	VORPD	%xmm6,%xmm7,%xmm6					#npi2_2 xmm6
#	VANDNPD	%xmm4,%xmm2,%xmm7					#
#	VANDPD	%xmm7,%xmm5,%xmm8					#
#	VANDPD	.L_int_three(%rip),%xmm8,%xmm8		#npi2_3  xmm8
#	VANDNPD	%xmm7,%xmm5,%xmm7					#
#	VANDPD	.L_int_four(%rip),%xmm7,%xmm7		#npi2_4  xmm7
#	VORPD	%xmm7,%xmm8,%xmm7					#npi2_3 xmm7

	VMOVAPD	 .L_twobypi(%rip),%xmm8
	VFMADDSD .L_point_five(%rip),%xmm8,%xmm1,%xmm8
	VCVTTPD2DQ %xmm8,%xmm8
#	VPMOVSXDQ %xmm8,%xmm8
	#uncoment all and delete below line
	VPMOVSXDQ %xmm8,%xmm6

#	VANDNPD	 %xmm8,%xmm2,%xmm8
#	VANDNPD	 %xmm8,%xmm4,%xmm8					# xmm8 npi2_1
#	VORPD	%xmm8,%xmm7,%xmm7
#	VORPD	%xmm6,%xmm7,%xmm6					# npi2 xmm6

	VANDPD	.L_int_three(%rip),%xmm6,%xmm11			# region xmm11
	VSHUFPS $8,%xmm6,%xmm6,%xmm6
	VCVTDQ2PD	%xmm6,%xmm6
	VFNMADDSD %xmm0,.L_piby2_1(%rip),%xmm6,%xmm2		# xmm2 rhead
	VMULSD	.L_piby2_1tail(%rip),%xmm6,%xmm3			# xmm3 rtail
	VANDPD .L__inf_mask_64(%rip),%xmm2,%xmm4
	VPSRLQ $52,%xmm4,%xmm4
	VPSRLQ $52,%xmm0,%xmm5
	VPSUBQ	%xmm4,%xmm5,%xmm4						# expdiff xmm4

	VMOVD %xmm4,%rax
	cmp .L_val_15(%rip),%rax
	JB exit_range_e5

	VMOVAPD %xmm2,%xmm5
	VMULSD	.L_piby2_2(%rip),%xmm6,%xmm3 			# rtail_1 xmm3
	VSUBSD	%xmm3,%xmm5,%xmm2						# rhead_1 xmm2

	VSUBSD	%xmm2,%xmm5,%xmm1
	VSUBSD	%xmm3,%xmm1,%xmm1
	VXORPD	.L_signbit(%rip),%xmm1,%xmm1
	VFMADDSD  %xmm1,.L_piby2_2tail(%rip),%xmm6,%xmm3	# rtail_1 xmm5

	cmp .L_val_48(%rip),%rax
	JB exit_range_e5

	VMOVAPD %xmm2,%xmm5
	VMULSD	.L_piby2_3(%rip),%xmm6,%xmm3 			# rtail_1 xmm3
	VSUBSD	%xmm3,%xmm5,%xmm2						# rhead_1 xmm2

	VSUBSD	%xmm2,%xmm5,%xmm1
	VSUBSD	%xmm3,%xmm1,%xmm1
	VXORPD	.L_signbit(%rip),%xmm1,%xmm1
	VFMADDSD  %xmm1,.L_piby2_3tail(%rip),%xmm6,%xmm3	# rtail_1 xmm5

exit_range_e5:
	VSUBSD %xmm3,%xmm2,%xmm10						# r_1  xmm10
	VSUBSD %xmm10,%xmm2,%xmm4
	VSUBSD %xmm3,%xmm4,%xmm1						# rr_1 xmm4
	VMOVAPD %xmm10,%xmm0

	.endm



.data
.align 32
.L_Cos:
    .quad    0x3fa5555555555555                       # 0.0416667     c1
    .quad    0x3fa5555555555555
    .quad    0x3fa5555555555555                       # 0.0416667     c1
    .quad    0x3fa5555555555555

    .quad    0xbf56c16c16c16967                       # -0.00138889   c2
    .quad    0xbf56c16c16c16967
    .quad    0xbf56c16c16c16967                       # -0.00138889   c2
    .quad    0xbf56c16c16c16967

    .quad    0x3EFA01A019F4EC91                       # 2.48016e-005  c3
    .quad    0x3EFA01A019F4EC91
    .quad    0x3EFA01A019F4EC91                       # 2.48016e-005  c3
    .quad    0x3EFA01A019F4EC91


    .quad    0xbE927E4FA17F667B                       # -2.75573e-007 c4
    .quad    0xbE927E4FA17F667B
    .quad    0xbE927E4FA17F667B                       # -2.75573e-007 c4
    .quad    0xbE927E4FA17F667B

    .quad    0x3E21EEB690382EEC                       # 2.08761e-009  c5
    .quad    0x3E21EEB690382EEC
    .quad    0x3E21EEB690382EEC                       # 2.08761e-009  c5
    .quad    0x3E21EEB690382EEC

    .quad    0xbDA907DB47258AA7                       # -1.13826e-011 c6
    .quad    0xbDA907DB47258AA7
    .quad    0xbDA907DB47258AA7                       # -1.13826e-011 c6
    .quad    0xbDA907DB47258AA7


.align 32
.L_Sin:
    .quad    0xbfc5555555555555                       # -0.166667     s1
    .quad    0xbfc5555555555555
    .quad    0xbfc5555555555555                       # -0.166667     s1
    .quad    0xbfc5555555555555

    .quad    0x3f81111111110bb3                       # 0.00833333    s2
    .quad    0x3f81111111110bb3
    .quad    0x3f81111111110bb3                       # 0.00833333    s2
    .quad    0x3f81111111110bb3

    .quad    0xbf2a01a019e83e5c                       # -0.000198413  s3
    .quad    0xbf2a01a019e83e5c
    .quad    0xbf2a01a019e83e5c                       # -0.000198413  s3
    .quad    0xbf2a01a019e83e5c

    .quad    0x3ec71de3796cde01                       # 2.75573e-006  s4
    .quad    0x3ec71de3796cde01
    .quad    0x3ec71de3796cde01                       # 2.75573e-006  s4
    .quad    0x3ec71de3796cde01

    .quad    0xbe5ae600b42fdfa7                       # -2.50511e-008 s5
    .quad    0xbe5ae600b42fdfa7
    .quad    0xbe5ae600b42fdfa7                       # -2.50511e-008 s5
    .quad    0xbe5ae600b42fdfa7

    .quad    0x3de5e0b2f9a43bb8                       # 1.59181e-010  s6
    .quad    0x3de5e0b2f9a43bb8
    .quad    0x3de5e0b2f9a43bb8                       # 1.59181e-010  s6
    .quad    0x3de5e0b2f9a43bb8


.align 32
.L_tanf:
	.quad 0x3FD8A8B0DA56CB17
	.quad 0x3FD8A8B0DA56CB17
	.quad 0x3FD8A8B0DA56CB17
	.quad 0x3FD8A8B0DA56CB17

	.quad 0x3F919DBA6EFD6AAD
	.quad 0x3F919DBA6EFD6AAD
	.quad 0x3F919DBA6EFD6AAD
	.quad 0x3F919DBA6EFD6AAD

	.quad 0x3FF27E84A3E73A2E
	.quad 0x3FF27E84A3E73A2E
	.quad 0x3FF27E84A3E73A2E
	.quad 0x3FF27E84A3E73A2E

	.quad 0xBFE07266D7B3511B
	.quad 0xBFE07266D7B3511B
	.quad 0xBFE07266D7B3511B
	.quad 0xBFE07266D7B3511B

	.quad 0x3F92E29003C692D9
	.quad 0x3F92E29003C692D9
	.quad 0x3F92E29003C692D9
	.quad 0x3F92E29003C692D9


.L_e_5:
		.quad 0x415312d000000000
		.quad 0x415312d000000000
		.quad 0x415312d000000000
		.quad 0x415312d000000000

.L_signbit:
			.quad 0x8000000000000000
			.quad 0x8000000000000000
			.quad 0x8000000000000000
			.quad 0x8000000000000000

.L_nan:
		.quad 0x7ff8000000000000
		.quad 0x7ff8000000000000
		.quad 0x7ff8000000000000
		.quad 0x7ff8000000000000


.L__sign_mask: .quad 0x7FFFFFFFFFFFFFFF
			   .quad 0x7FFFFFFFFFFFFFFF
			   .quad 0x7FFFFFFFFFFFFFFF
			   .quad 0x7FFFFFFFFFFFFFFF

.L__allone_mask: .quad 0xFFFFFFFFFFFFFFFF
			   .quad 0xFFFFFFFFFFFFFFFF
			   .quad 0xFFFFFFFFFFFFFFFF
			   .quad 0xFFFFFFFFFFFFFFFF


.L_one:
	.quad    0x3FF0000000000000
	.quad    0x3FF0000000000000
	.quad    0x3FF0000000000000
	.quad    0x3FF0000000000000



.L_int_one:
	.quad    0x0000000000000001
	.quad    0x0000000000000001
	.quad    0x0000000000000001
	.quad    0x0000000000000001




.L_int_three:
	.quad    0x0000000000000003
	.quad    0x0000000000000003
	.quad    0x0000000000000003
	.quad    0x0000000000000003


.L_int_four:
	.quad    0x0000000000000004
	.quad    0x0000000000000004
	.quad    0x0000000000000004
	.quad    0x0000000000000004


.L_point_five:
	 .quad   0x3FE0000000000000
	 .quad   0x3FE0000000000000
	 .quad   0x3FE0000000000000
	 .quad   0x3FE0000000000000


.L_twobypi:
			.quad 0x3FE45F306DC9C883
			.quad 0x3FE45F306DC9C883
			.quad 0x3FE45F306DC9C883
			.quad 0x3FE45F306DC9C883


.L_piby2_3tail:
			.quad 0x397B839A252049C1
			.quad 0x397B839A252049C1
			.quad 0x397B839A252049C1
			.quad 0x397B839A252049C1



.L_piby2_3:
			.quad 0x3BA3198A2E000000
			.quad 0x3BA3198A2E000000
			.quad 0x3BA3198A2E000000
			.quad 0x3BA3198A2E000000



.L_piby2_1:
			.quad 0x3FF921FB54400000
			.quad 0x3FF921FB54400000
			.quad 0x3FF921FB54400000
			.quad 0x3FF921FB54400000



.L_piby2_2:
			.quad 0x3DD0B4611A600000
			.quad 0x3DD0B4611A600000
			.quad 0x3DD0B4611A600000
			.quad 0x3DD0B4611A600000

.L_point_166:
			.quad 0x3FC5555555555555
			.quad 0x3FC5555555555555
			.quad 0x3FC5555555555555
			.quad 0x3FC5555555555555

.L_point_333:
			.quad 0x3FD5555555555555
			.quad 0x3FD5555555555555
			.quad 0x3FD5555555555555
			.quad 0x3FD5555555555555

.L_n_one:
		.quad 0xBFF0000000000000
		.quad 0xBFF0000000000000
		.quad 0xBFF0000000000000
		.quad 0xBFF0000000000000


.L_piby2_1tail:
			.quad 0x3DD0B4611A626331
			.quad 0x3DD0B4611A626331
			.quad 0x3DD0B4611A626331
			.quad 0x3DD0B4611A626331


.L_piby2_2tail:
			.quad 0x3BA3198A2E037073
			.quad 0x3BA3198A2E037073
			.quad 0x3BA3198A2E037073
			.quad 0x3BA3198A2E037073


.L_mask_5piby4:
				.quad 0x400f6a7a2955385e
				.quad 0x400f6a7a2955385e
				.quad 0x400f6a7a2955385e
				.quad 0x400f6a7a2955385e


.L_mask_3piby4:
				.quad 0x4002d97c7f3321d2
				.quad 0x4002d97c7f3321d2
				.quad 0x4002d97c7f3321d2
				.quad 0x4002d97c7f3321d2


.L_mask_9piby4:
				.quad 0x401c463abeccb2bb
				.quad 0x401c463abeccb2bb
				.quad 0x401c463abeccb2bb
				.quad 0x401c463abeccb2bb


.L_mask_7piby4:
				.quad 0x4015fdbbe9bba775
				.quad 0x4015fdbbe9bba775
				.quad 0x4015fdbbe9bba775
				.quad 0x4015fdbbe9bba775


.L__inf_mask_64: .quad 0x7FF0000000000000
				 .quad 0x7FF0000000000000
				 .quad 0x7FF0000000000000
				 .quad 0x7FF0000000000000

.L_val_15:
				.quad 0xF
				.quad 0xF
				.quad 0xF
				.quad 0xF

.L_val_48:
				.quad 0x30
				.quad 0x30
				.quad 0x30
				.quad 0x30


.L_int_two:
	.quad    0x0000000000000002
	.quad    0x0000000000000002
	.quad    0x0000000000000002
	.quad    0x0000000000000002


.L_piby2_lead:
		.quad  0x3ff921fb54442d18
		.quad  0x3ff921fb54442d18
		.quad  0x3ff921fb54442d18
		.quad  0x3ff921fb54442d18




.align 16



.L_mask_3fe:
				.quad 0x3fe921fb54442d18
				.quad 0x3fe921fb54442d18


.L_mask_3e4:
				.quad 0x3e40000000000000
				.quad 0x3e40000000000000


.L_mask_3f2:
				.quad 0x3f20000000000000
				.quad 0x3f20000000000000




.L_tan_c1:
			.quad 0x3FD7D50F6638564A
			.quad 0x3FD7D50F6638564A

.L_tan_c2:
			.quad 0xBF977C24C7569ABB
			.quad 0xBF977C24C7569ABB

.L_tan_c3:
			.quad 0x3F2D5DAF289C385A
			.quad 0x3F2D5DAF289C385A


.L_tan_c4:
			.quad 0x3FF1DFCB8CAA40B8
			.quad 0x3FF1DFCB8CAA40B8

.L_tan_c5:
			.quad 0xBFE08046499EB90F
			.quad 0xBFE08046499EB90F

.L_tan_c6:
			.quad 0x3F9AB0F4F80A0ACF
			.quad 0x3F9AB0F4F80A0ACF

.L_tan_c7:
			.quad 0x3F2E7517EF6D98F8
			.quad 0x3F2E7517EF6D98F8

.L_half_mask:
			.quad 0xffffffff00000000
			.quad 0xffffffff00000000


.L_point_68:
			.quad 0x3FE5C28F5C28F5C3
			.quad 0x3FE5C28F5C28F5C3

.L_n_point_68:
			.quad 0xBFE5C28F5C28F5C3
			.quad 0xBFE5C28F5C28F5C3



.L_piby4_lead:
			.quad 0x3FE921FB54442D18
			.quad 0x3FE921FB54442D18

.L_piby4_tail:
			.quad 0x3C81A62633145C06
			.quad 0x3C81A62633145C06


.L_two:
	.quad    0x4000000000000000
	.quad    0x4000000000000000


.L__mant_mask_64:
		.quad 0x000fffffffffffff
		.quad 0x000fffffffffffff

.L__imp_mask_64:
		.quad 0x0010000000000000
		.quad 0x0010000000000000


.L_157:
		.quad 0x9D
		.quad 0x9D

.L_8:
		.quad 0x8
		.quad 0x8

.L_10:
		.quad 0xA
		.quad 0xA
.L_959:

		.quad 0x3BF
		.quad 0x3BF

.L_116:
		.quad 0x74
		.quad 0x74

.L_fff800:
		.quad 0xfffffffff8000000
		.quad 0xfffffffff8000000

.L_piby2_part1:
		.quad 0x3ff921fb50000000
		.quad 0x3ff921fb50000000
.L_piby2_part2:
		 .quad 0x3e5110b460000000
		 .quad 0x3e5110b460000000

.L_piby2_part3:
		.quad 0x3c91a62633145c06
		.quad 0x3c91a62633145c06

.L_1023:
		.quad 0x3FF
		.quad 0x3FF


.L_23:
		.quad 0x17
		.quad 0x17

.L_53:
		.quad 0x35
		.quad 0x35

.L_64:
		.quad 0x40
		.quad 0x40


.type	.L__Pibits, @object
.size	.L__Pibits, 158
.L__Pibits:
    .byte 224,241,27,193,12,88,33,116,53,126,196,126,237,175,169,75,74,41,222,231,28,244,236,197,151,175,31,235,158,212,181,168,127,121,154,253,24,61,221,38,44,159,60,251,217,180,125,180,41,104,45,70,188,188,63,96,22,120,255,95,226,127,236,160,228,247,46,126,17,114,210,231,76,13,230,88,71,230,4,249,125,209,154,192,113,166,19,18,237,186,212,215,8,162,251,156,166,196,114,172,119,248,115,72,70,39,168,187,36,25,128,75,55,9,233,184,145,220,134,21,239,122,175,142,69,249,7,65,14,241,100,86,138,109,3,119,211,212,71,95,157,240,167,84,16,57,185,13,230,139,2,0,0,0,0,0,0,0




