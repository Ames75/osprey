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
# An implementation of the sinf function.
#
# Prototype:
#
#     double sinf(double x);
#
#   Computes sinf(x).
#   It will provide proper C99 return values,
#   but may not raise floating point status bits properly.
#   Based on the NAG C implementation.
#
#
#ifdef __ELF__
.section .note.GNU-stack,"",@progbits
#endif

.data
.align 32
.L__real_3ff0000000000000: .quad 0x03ff0000000000000  # 1.0
                  .quad 0                             # for alignment
.L__real_3fe0000000000000: .quad 0x03fe0000000000000  # 0.5
                  .quad 0
.L__real_3fc5555555555555: .quad 0x03fc5555555555555  # 0.166666666666
                  .quad 0
.L__real_3fe45f306dc9c883: .quad 0x03fe45f306dc9c883  # twobypi
                  .quad 0
.L__real_3ff921fb54400000: .quad 0x03ff921fb54400000  # piby2_1
                  .quad 0
.L__real_3dd0b4611a626331: .quad 0x03dd0b4611a626331  # piby2_1tail
                  .quad 0
.L__real_3dd0b4611a600000: .quad 0x03dd0b4611a600000  # piby2_2
                  .quad 0
.L__real_3ba3198a2e037073: .quad 0x03ba3198a2e037073  # piby2_2tail
                  .quad 0
.L__real_411E848000000000: .quad 0x415312d000000000   # 5e6 0x0411E848000000000  # 5e5
                  .quad 0

.align 32
.Lcosfarray:
   .quad   0x0bfe0000000000000                        # -0.5            c0
   .quad   0
   .quad   0x03fa5555555555555                        # 0.0416667       c1
   .quad   0
   .quad   0x0bf56c16c16c16c16                        # -0.00138889     c2
   .quad   0
   .quad   0x03EFA01A01A01A019                        # 2.48016e-005    c3
   .quad   0
   .quad   0x0be927e4fb7789f5c                        # -2.75573e-007   c4
   .quad   0

.align 32
.Lsinfarray:
   .quad   0x0bfc5555555555555                        # -0.166667       s1
   .quad   0
   .quad   0x03f81111111111111                        # 0.00833333      s2
   .quad   0
   .quad   0x0bf2a01a01a01a01a                        # -0.000198413    s3
   .quad   0
   .quad   0x03ec71de3a556c734                        # 2.75573e-006    s4
   .quad   0

.text
.align 32
.p2align 4,,15

#include "fn_macros.h"
#include "weak_macros.h"
#define fname FN_PROTOTYPE_BAS64(sinf)
#define fname_special _sinf_special@PLT

WEAK_ACML_LIB_ALIAS fastsinf, FN_PROTOTYPE(sinf)
# define local variable storage offsets
.equ   p_temp,     0x30                               # temporary for get/put bits operation
.equ   p_temp1,    0x40                               # temporary for get/put bits operation
.equ   r,          0x50                               # pointer to r for amd_remainder_piby2
.equ   region,     0x60                               # pointer to region for amd_remainder_piby2
.equ   stack_size, 0x88

.globl fname
.type  fname,@function

fname:
   sub      $stack_size, %rsp
   xorpd    %xmm2, %xmm2                              # zeroed out for later use

##  if NaN or inf
   movd     %xmm0, %edx
   mov      $0x07f800000, %eax
   mov      %eax, %r10d
   and      %edx, %r10d
   cmp      %eax, %r10d
   jz       .Lsinf_naninf

# GET_BITS_DP64(x, ux);
# get the input value to an integer register.
   cvtss2sd %xmm0, %xmm0         # convert input to double.
   movsd    %xmm0,p_temp(%rsp)   # get the input value to an integer register.

   mov   p_temp(%rsp), %rdx      # rdx is ux

#  ax = (ux & ~SIGNBIT_DP64);
   mov      $0x07fffffffffffffff, %r10
   and      %rdx, %r10            # r10 is ax
   mov      $1, %r8d            # for determining region later on

##  if (ax <= 0x3fe921fb54442d18) /* abs(x) <= pi/4 */
   mov      $0x03fe921fb54442d18, %rax
   cmp      %rax, %r10
   jg       .Lsinf_reduce

##      if (ax < 0x3f80000000000000) /* abs(x) < 2.0^(-7) */
   mov      $0x3f80000000000000, %rax
   cmp      %rax, %r10
   jge      .Lsinf_small

##          if (ax < 0x3f20000000000000) /* abs(x) < 2.0^(-13) */
   mov      $0x3f20000000000000, %rax
   cmp      %rax, %r10
   jge      .Lsinf_smaller

#                  sinf = x;
   jmp      .Lsinf_cleanup         # done

##          else

.Lsinf_smaller:
#              sinf = x - x^3 * 0.1666666666666666666;
   movsd    %xmm0, %xmm2
   movsd    .L__real_3fc5555555555555(%rip), %xmm4   # 0.1666666666666666666
   mulsd    %xmm2, %xmm2            # x^2
   mulsd    %xmm0, %xmm2            # x^3
   mulsd    %xmm4, %xmm2            # x^3 * 0.1666666666666666666
   subsd    %xmm2, %xmm0            # x - x^3 * 0.1666666666666666666
   jmp      .Lsinf_cleanup

.Lsinf_small:
   movsd    %xmm0, %xmm2
   mulsd    %xmm0, %xmm2            # x2

#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
# region 0 or 2    - do a sinf calculation
#  zs = x + x3((s1 + x2 * s2) + x4(s3 + x2 * s4));
   movsd    .Lsinfarray+0x30(%rip), %xmm1   # s4
   mulsd    %xmm2, %xmm1                 # s4x2
   movsd    %xmm2, %xmm4                    # move for x4
   movsd    .Lsinfarray+0x10(%rip), %xmm5   # s2
   mulsd    %xmm2, %xmm4                 # x4
   movsd    %xmm0, %xmm3                     # move for x3
   mulsd    %xmm2, %xmm5                     # s2x2
   mulsd    %xmm2, %xmm3                     # x3
   addsd    .Lsinfarray+0x20(%rip), %xmm1   # s3+s4x2
   mulsd    %xmm4, %xmm1                    # s3x4+s4x6
   addsd    .Lsinfarray(%rip), %xmm5           # s1+s2x2
   addsd    %xmm5, %xmm1                    # s1+s2x2+s3x4+s4x6
   mulsd    %xmm3, %xmm1                    # x3(s1+s2x2+s3x4+s4x6)
   addsd    %xmm1, %xmm0                    # x + x3(s1+s2x2+s3x4+s4x6)
   jmp      .Lsinf_cleanup

#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.align 32
.Lsinf_reduce:

#  xneg = (ax != ux);
   cmp      %r10, %rdx
   mov      $0, %r11d

##  if (xneg) x = -x;
   jz       .L50e5
   mov      $1, %r11d
   subsd    %xmm0, %xmm2
   movsd    %xmm2, %xmm0

.L50e5:
##  if (x < 5.0e5)
   cmp      .L__real_411E848000000000(%rip), %r10
   jae      .Lsinf_reduce_precise

# reduce  the argument to be in a range from -pi/4 to +pi/4
# by subtracting multiples of pi/2
   movsd    %xmm0, %xmm2
   movsd    .L__real_3fe45f306dc9c883(%rip), %xmm3            # twobypi
   movsd    %xmm0, %xmm4
   movsd    .L__real_3fe0000000000000(%rip), %xmm5            # .5
   mulsd    %xmm3, %xmm2

#/* How many pi/2 is x a multiple of? */
#      xexp  = ax >> EXPSHIFTBITS_DP64;
   mov      %r10, %r9
   shr      $52, %r9                  #>>EXPSHIFTBITS_DP64

#        npi2  = (int)(x * twobypi + 0.5);
   addsd    %xmm5, %xmm2                  # npi2

   movsd    .L__real_3ff921fb54400000(%rip), %xmm3         # piby2_1
   cvttpd2dq   %xmm2, %xmm0               # convert to integer
   movsd    .L__real_3dd0b4611a626331(%rip), %xmm1         # piby2_1tail
   cvtdq2pd   %xmm0, %xmm2               # and back to double.

#      /* Subtract the multiple from x to get an extra-precision remainder */
#      rhead  = x - npi2 * piby2_1;
   mulsd    %xmm2, %xmm3
   subsd    %xmm3, %xmm4                  # rhead

#      rtail  = npi2 * piby2_1tail;
   mulsd    %xmm2, %xmm1
   movd     %xmm0, %eax

#      GET_BITS_DP64(rhead-rtail, uy);               ; originally only rhead
   movsd    %xmm4, %xmm0
   subsd    %xmm1, %xmm0

   movsd    .L__real_3dd0b4611a600000(%rip), %xmm3      # piby2_2
   movsd    %xmm0,p_temp(%rsp)
   movsd    .L__real_3ba3198a2e037073(%rip), %xmm5      # piby2_2tail
   mov      p_temp(%rsp), %rcx         # rcx is rhead-rtail

#   xmm0=r, xmm4=rhead, xmm1=rtail, xmm2=npi2, xmm3=temp for calc, xmm5= temp for calc
#      expdiff = xexp - ((uy & EXPBITS_DP64) >> EXPSHIFTBITS_DP64);
   shl      $1, %rcx               # strip any sign bit
   shr      $53, %rcx               #>> EXPSHIFTBITS_DP64 +1
   sub      %rcx, %r9               #expdiff

##      if (expdiff > 15)
   cmp      $15, %r9
   jle      .Lexpdiff15

#          /* The remainder is pretty small compared with x, which
#             implies that x is a near multiple of pi/2
#             (x matches the multiple to at least 15 bits) */

#          t  = rhead;
   movsd    %xmm4, %xmm1

#          rtail  = npi2 * piby2_2;
   mulsd    %xmm2, %xmm3

#          rhead  = t - rtail;
   mulsd    %xmm2, %xmm5            # npi2 * piby2_2tail
   subsd    %xmm3, %xmm4            # rhead

#          rtail  = npi2 * piby2_2tail - ((t - rhead) - rtail);
   subsd    %xmm4, %xmm1            # t - rhead
   subsd    %xmm3, %xmm1            # -rtail
   subsd    %xmm1, %xmm5            #rtail

#      r = rhead - rtail;
   movsd    %xmm4, %xmm0


#xmm1=rtail
   movsd    %xmm5, %xmm1
   subsd    %xmm5, %xmm0

#   xmm0=r, xmm4=rhead, xmm1=rtail
.Lexpdiff15:
#      region = npi2 & 3;
# No need rr for float case

#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
## if the input was close to a pi/2 multiple
# The original NAG code missed this trick.  If the input is very close to n*pi/2 after
# reduction,
# then the sinf is ~ 1.0 , to within 15 bits, when r is < 2^-13.  We already
# have x at this point, so we can skip the sinf polynomials.

   cmp      $0x03f2, %rcx            ## if r  small.
   jge      .Lsinf_piby4            # use taylor series if not
   cmp      $0x03de, %rcx            ## if r really small.
   jle      .Lr_small               # then sinf(r) = 0

   movsd    %xmm0, %xmm2
   mulsd    %xmm2, %xmm2            #x^2

##      if region is 0 or 2 do a sinf calc.
   and      %eax, %r8d
   jnz      .Lcosfregion

# region 0 or 2 do a sinf calculation
# use simply polynomial
#              x - x*x*x*0.166666666666666666;
   movsd    .L__real_3fc5555555555555(%rip), %xmm3         #
   mulsd    %xmm0, %xmm3                   # * x
   mulsd    %xmm2, %xmm3                  # * x^2
   subsd    %xmm3, %xmm0                   # xs
   jmp      .Ladjust_region

.align 32
.Lcosfregion:
# region 1 or 3 do a cosf calculation
# use simply polynomial
#              1.0 - x*x*0.5;
   movsd    .L__real_3ff0000000000000(%rip), %xmm0         # 1.0
   mulsd    .L__real_3fe0000000000000(%rip), %xmm2         # 0.5 *x^2
   subsd    %xmm2, %xmm0                  # xc
   jmp      .Ladjust_region

.align 32
.Lr_small:
##      if region is 1 or 3   do a cosf calc.
   and      %eax, %r8d
   jz       .Ladjust_region

# odd
   movsd    .L__real_3ff0000000000000(%rip), %xmm0         # cosf(r) is a 1
   jmp      .Ladjust_region

#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.Lsinf_reduce_precise:
#      // Reduce x into range [-pi/4,pi/4]
#      __amd_remainder_piby2d2f(x, &r, &region);

   mov      %r11,p_temp(%rsp)
   lea      region(%rsp), %rdx
   lea      r(%rsp), %rsi
   movd     %xmm0, %rdi
   sub      $0x20, %rsp

   call     __amd_remainder_piby2d2f@PLT

   add      $0x20, %rsp
   mov      p_temp(%rsp), %r11
   mov      $1, %r8d            # for determining region later on
   movsd    r(%rsp), %xmm1      #//x
   mov      region(%rsp), %eax   #//region

# xmm0 = x, xmm4 = xx, r8d = 1, eax= region
#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
# perform taylor series to calc sinfx, cosfx
.Lsinf_piby4:
#  x2 = r * r;
   movsd    %xmm0, %xmm2
   mulsd    %xmm0, %xmm2                  #x2

##      if region is 0 or 2   do a sinf calc.
   and      %eax, %r8d
   jnz      .Lcosfregion2

#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
# region 0 or 2 do a sinf calculation
#  zs = x + x3((s1 + x2 * s2) + x4(s3 + x2 * s4));
   movsd    .Lsinfarray+0x30(%rip), %xmm1   # s4
   mulsd    %xmm2, %xmm1                 # s4x2
   movsd    %xmm2, %xmm4                    # move for x4
   mulsd    %xmm2, %xmm4                 # x4
   movsd    .Lsinfarray+0x10(%rip), %xmm5   # s2
   mulsd    %xmm2, %xmm5                     # s2x2
   movsd    %xmm0, %xmm3                     # move for x3
   mulsd    %xmm2, %xmm3                     # x3
   addsd    .Lsinfarray+0x20(%rip), %xmm1   # s3+s4x2
   mulsd    %xmm4, %xmm1                    # s3x4+s4x6
   addsd    .Lsinfarray(%rip), %xmm5           # s1+s2x2
   addsd    %xmm5, %xmm1                    # s1+s2x2+s3x4+s4x6
   mulsd    %xmm3, %xmm1                    # x3(s1+s2x2+s3x4+s4x6)
   addsd    %xmm1, %xmm0                    # x + x3(s1+s2x2+s3x4+s4x6)

   jmp      .Ladjust_region

.align 32
.Lcosfregion2:
#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
# region 1 or 3    - do a cosf calculation
#    zc = 1-0.5*x2+ c1*x4 +c2*x6 +c3*x8 + c4*x10 for a higher precision
   movsd    .Lcosfarray+0x40(%rip), %xmm1    # c4
   movsd    %xmm2, %xmm4                     # move for x4
   mulsd    %xmm2, %xmm1                     # c4x2
   movsd    .Lcosfarray+0x20(%rip), %xmm3    # c2
   mulsd    %xmm2, %xmm4                     # x4
   movsd    .Lcosfarray(%rip), %xmm0         # c0
   mulsd    %xmm2, %xmm3                     # c2x2
   mulsd    %xmm2, %xmm0                     # c0x2 (=-0.5x2)
   addsd    .Lcosfarray+0x30(%rip), %xmm1      # c3+c4x2
   mulsd    %xmm4, %xmm1                     # c3x4 + c4x6
   addsd    .Lcosfarray+0x10(%rip), %xmm3      # c1+c2x2
   addsd    %xmm3, %xmm1                     # c1 + c2x2 + c3x4 + c4x6
   mulsd    %xmm4, %xmm1                  # c1x4 + c2x6 + c3x8 + c4x10
   addsd    .L__real_3ff0000000000000(%rip), %xmm0 # 1 - 0.5x2
   addsd    %xmm1, %xmm0                     # 1 - 0.5x2 + c1x4 + c2x6 + c3x8 + c4x10

#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.align 32
.Ladjust_region:      # positive or negative
#      switch (region)
   shr      $1, %eax
   mov      %eax, %ecx
   and      %r11d, %eax

   not      %ecx
   not      %r11d
   and      %r11d, %ecx

   or       %ecx, %eax
   and      $1, %eax
   jnz      .Lsinf_cleanup

## if the original region 0, 1 and arg is negative, then we negate the result.
## if the original region 2, 3 and arg is positive, then we negate the result.
   movsd    %xmm0, %xmm2
   xorpd    %xmm0, %xmm0
   subsd    %xmm2, %xmm0

.align 32
.Lsinf_cleanup:
   cvtsd2ss %xmm0, %xmm0
   add      $stack_size, %rsp
   ret

.align 32
.Lsinf_naninf:
   call     fname_special
   add      $stack_size, %rsp
   ret


