C
C  Copyright (C) 2006. QLogic Corporation. All Rights Reserved.
C

C
C
C  Copyright (C) 2000, 2001 Silicon Graphics, Inc.  All Rights Reserved.
C
C  This program is free software; you can redistribute it and/or modify it
C  under the terms of version 2 of the GNU General Public License as
C  published by the Free Software Foundation.
C
C  This program is distributed in the hope that it would be useful, but
C  WITHOUT ANY WARRANTY; without even the implied warranty of
C  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
C
C  Further, this software is distributed without any warranty that it is
C  free of the rightful claim of any third person regarding infringement 
C  or the like.  Any license provided herein, whether implied or 
C  otherwise, applies only to this software file.  Patent licenses, if 
C  any, provided herein do not apply to combinations of this program with 
C  other software, or any other product whatsoever.  
C
C  You should have received a copy of the GNU General Public License along
C  with this program; if not, write the Free Software Foundation, Inc., 59
C  Temple Place - Suite 330, Boston MA 02111-1307, USA.
C
C  Contact information:  Silicon Graphics, Inc., 1600 Amphitheatre Pky,
C  Mountain View, CA 94043, or:
C
C  http://www.sgi.com
C
C  For further information regarding this notice, see:
C
C  http://oss.sgi.com/projects/GenInfo/NoticeExplan
C
C

      SUBROUTINE FOLD_OPERATION(operator,
     &                          result,
     &                          result_type,
     &               	        left,
     &                          left_type,
     &                          right,
     &                          right_type,
     &                          third,
     &                          third_type) 

      IMPLICIT NONE

      integer i

      integer Type_Void
      integer Short_Char_Const
      integer Short_Typeless_Const
      integer Typeless_1
      integer Typeless_2
      integer Typeless_4
      integer Typeless_8
      integer Long_Typeless
      integer Integer_1
      integer Integer_2
      integer Integer_4
      integer Integer_8
      integer Real_4
      integer Real_8
      integer Real_16
      integer Complex_4
      integer Complex_8
      integer Complex_16
      integer CRI_Ptr_8
      integer Logical_1
      integer Logical_2
      integer Logical_4
      integer Logical_8
      integer Character_1
      integer Character_2
      integer Character_4
      integer CRI_Ch_Ptr_8
      integer Structure_Type
      integer CRI_Parcel_Ptr_8
      integer Mult_Opr
      integer Plus_Opr
      integer Minus_Opr
      integer Div_Opr
      integer Eq_Opr
      integer Ne_Opr
      integer Lt_Opr
      integer Le_Opr
      integer Gt_Opr
      integer Ge_Opr
      integer Shiftl_Opr
      integer Shifta_Opr
      integer Shiftr_Opr
      integer Shift_Opr
      integer Mod_Opr
      integer Modulo_Opr
      integer Abs_Opr
      integer Uminus_Opr
      integer Cvrt_Opr
      integer Int_Opr
      integer Nint_Opr
      integer Power_Opr
      integer Ibits_Opr
      integer Ishftc_Opr
      integer SRK_Opr
      integer Sqrt_Opr
      integer Sin_Opr
      integer Cos_Opr
      integer Tan_Opr
      integer Log_10_Opr
      integer Log_E_Opr
      integer Cmplx_Opr
      integer Exp_Opr
      integer Sinh_Opr
      integer Cosh_Opr
      integer Tanh_Opr
      integer Asin_Opr
      integer Acos_Opr
      integer Atan_Opr
      integer Atan2_Opr
      integer Atan2d_Opr
      integer Dprod_Opr
      integer Floor_Opr
      integer Nearest_Opr
      integer Ceiling_Opr
      integer Fraction_Opr
      integer Aint_Opr


      parameter (Cvrt_Opr = 4)
      parameter (Power_Opr = 6)
      parameter (Mult_Opr = 7)
      parameter (Uminus_Opr = 10)
      parameter (Plus_Opr = 11)
      parameter (Minus_Opr = 12)
      parameter (Div_Opr = 8)
      parameter (Eq_Opr = 14)
      parameter (Ne_Opr = 15)
      parameter (Lt_Opr = 16)
      parameter (Le_Opr = 17)
      parameter (Gt_Opr = 18)
      parameter (Ge_Opr = 19)
      parameter (Abs_Opr = 29)
      parameter (Int_Opr = 46)
      parameter (Nint_Opr = 50)
      parameter (Shift_Opr = 53)
      parameter (Shiftl_Opr = 54)
      parameter (Shifta_Opr = 315)
      parameter (Shiftr_Opr = 55)
      parameter (Mod_Opr = 48)
      parameter (Modulo_Opr = 52)
      parameter (Ibits_Opr = 344)
      parameter (Ishftc_Opr = 343)
      parameter (Sqrt_Opr = 43)
      parameter (SRK_Opr = 129)
      parameter (Sin_Opr = 31)
      parameter (Cos_Opr = 30)
      parameter (Tan_Opr = 34)
      parameter (Sinh_Opr = 36)
      parameter (Cosh_Opr = 40)
      parameter (Tanh_Opr = 35)
      parameter (Asin_Opr = 38)
      parameter (Acos_Opr = 37)
      parameter (Atan_Opr = 39)
      parameter (Atan2_Opr = 41)
      parameter (Log_E_Opr = 32)
      parameter (Log_10_Opr = 33)
      parameter (Cmplx_Opr = 73)
      parameter (Exp_Opr = 45)
      parameter (Dprod_Opr = 68)
      parameter (Ceiling_Opr = 93)
      parameter (Floor_Opr = 95)
      parameter (Fraction_Opr = 96)
      parameter (Nearest_Opr = 99)
      parameter (Aint_Opr = 59)

      parameter (Type_Void = 0)
      parameter (Short_Char_Const = 1)
      parameter (Short_Typeless_Const = 2)
      parameter (Typeless_1 = 3)
      parameter (Typeless_2 = 4)
      parameter (Typeless_4 = 5)
      parameter (Typeless_8 = 6)
      parameter (Long_Typeless = 7)
      parameter (Integer_1 = 8)
      parameter (Integer_2 = 9)
      parameter (Integer_4 = 10)
      parameter (Integer_8 = 11)
      parameter (Real_4 = 12)
      parameter (Real_8 = 13)
      parameter (Real_16 = 14)
      parameter (Complex_4 = 15)
      parameter (Complex_8 = 16)
      parameter (Complex_16 = 17)
      parameter (CRI_Ptr_8 = 18)
      parameter (Logical_1 = 19)
      parameter (Logical_2 = 20)
      parameter (Logical_4 = 21)
      parameter (Logical_8 = 22)
      parameter (Character_1 = 23)
      parameter (Character_2 = 24)
      parameter (Character_4 = 25)
      parameter (CRI_Ch_Ptr_8 = 26)
      parameter (Structure_Type = 27)
      parameter (CRI_Parcel_Ptr_8 = 28)

	integer oper_type
      integer    operator
      integer    result(8), left(8), right(8), third(8)
      integer    result_opnd(8), left_opnd(8), right_opnd(8), 
     &                                         third_opnd(8)

      integer*1  integer_1_result, integer_1_l_opnd, integer_1_r_opnd,
     &                                               integer_1_t_opnd
      integer*2  integer_2_result, integer_2_l_opnd, integer_2_r_opnd,
     &                                               integer_2_t_opnd
      integer*4  integer_4_result, integer_4_l_opnd, integer_4_r_opnd,
     &                                               integer_4_t_opnd
      integer*8  integer_8_result, integer_8_l_opnd, integer_8_r_opnd,
     &                                               integer_8_t_opnd

      logical*1  logical_1_result, logical_1_l_opnd, logical_1_r_opnd
      logical*2  logical_2_result, logical_2_l_opnd, logical_2_r_opnd
      logical*4  logical_4_result, logical_4_l_opnd, logical_4_r_opnd
      logical*8  logical_8_result, logical_8_l_opnd, logical_8_r_opnd

      real   *4  real_4_result,  real_4_l_opnd,  real_4_r_opnd
      real   *8  real_8_result,  real_8_l_opnd,  real_8_r_opnd
      real   *8  real_16_result, real_16_l_opnd, real_16_r_opnd

      complex*8  complex_4_result,  complex_4_l_opnd,  complex_4_r_opnd
      complex*16 complex_8_result,  complex_8_l_opnd,  complex_8_r_opnd
      complex*16 complex_16_result, complex_16_l_opnd, complex_16_r_opnd

      integer left_type, right_type, third_type, result_type

      logical    logical_default_result
      integer    integer_default_result

      equivalence (logical_1_l_opnd, left_opnd)
      equivalence (logical_1_r_opnd, right_opnd)
      equivalence (logical_2_l_opnd, left_opnd)
      equivalence (logical_2_r_opnd, right_opnd)
      equivalence (logical_4_l_opnd, left_opnd)
      equivalence (logical_4_r_opnd, right_opnd)
      equivalence (logical_8_l_opnd, left_opnd)
      equivalence (logical_8_r_opnd, right_opnd)

      equivalence (integer_1_l_opnd, left_opnd)
      equivalence (integer_1_r_opnd, right_opnd)
      equivalence (integer_1_t_opnd, third_opnd)
      equivalence (integer_2_l_opnd, left_opnd)
      equivalence (integer_2_r_opnd, right_opnd)
      equivalence (integer_2_t_opnd, third_opnd)
      equivalence (integer_4_l_opnd, left_opnd)
      equivalence (integer_4_r_opnd, right_opnd)
      equivalence (integer_4_t_opnd, third_opnd)
      equivalence (integer_8_l_opnd, left_opnd)
      equivalence (integer_8_r_opnd, right_opnd)
      equivalence (integer_8_t_opnd, third_opnd)

      equivalence (real_4_l_opnd, left_opnd)
      equivalence (real_4_r_opnd, right_opnd)
      equivalence (real_8_l_opnd, left_opnd)
      equivalence (real_8_r_opnd, right_opnd)
      equivalence (real_16_l_opnd, left_opnd)
      equivalence (real_16_r_opnd, right_opnd)

      equivalence (complex_4_l_opnd, left_opnd)
      equivalence (complex_4_r_opnd, right_opnd)
      equivalence (complex_8_l_opnd, left_opnd)
      equivalence (complex_8_r_opnd, right_opnd)
      equivalence (complex_16_l_opnd, left_opnd)
      equivalence (complex_16_r_opnd, right_opnd)

      equivalence (integer_1_result,
     &             integer_2_result,
     &             integer_4_result,
     &             integer_8_result,
     &             real_4_result, 
     &             real_8_result,
     &             real_16_result,
     &             complex_4_result,
     &             complex_8_result,
     &             complex_16_result,
     &             logical_1_result,
     &             logical_2_result,
     &             logical_4_result,
     &             logical_8_result,
     &             integer_default_result,
     &             result_opnd)

! KEY Bug 10177
      logical_default_result = .false.

      result_opnd(1) = 0
      result_opnd(2) = 0
      result_opnd(3) = 0
      result_opnd(4) = 0
      result_opnd(5) = 0
      result_opnd(6) = 0
      result_opnd(7) = 0
      result_opnd(8) = 0

      if ((operator .ne. Cvrt_Opr) .and.
     &    (operator .ne. Power_Opr) .and.
     &    (operator .ne. Mult_Opr) .and.
     &    (operator .ne. Uminus_Opr) .and.
     &    (operator .ne. Plus_Opr) .and.
     &    (operator .ne. Minus_Opr) .and.
     &    (operator .ne. Div_Opr) .and.
     &    (operator .ne. Eq_Opr) .and.
     &    (operator .ne. Ne_Opr) .and.
     &    (operator .ne. Lt_Opr) .and.
     &    (operator .ne. Le_Opr) .and.
     &    (operator .ne. Gt_Opr) .and.
     &    (operator .ne. Ge_Opr) .and.
     &    (operator .ne. Abs_Opr) .and.
     &    (operator .ne. SRK_Opr) .and.
     &    (operator .ne. Int_Opr) .and.
     &    (operator .ne. Nint_Opr) .and.
     &    (operator .ne. Shift_Opr) .and.
     &    (operator .ne. Shiftl_Opr) .and.
     &    (operator .ne. Ishftc_Opr) .and.
     &    (operator .ne. Ibits_Opr) .and.
     &    (operator .ne. Shiftr_Opr) .and.
     &    (operator .ne. Shifta_Opr) .and.
     &    (operator .ne. Sqrt_Opr) .and.
     &    (operator .ne. Sin_Opr) .and.
     &    (operator .ne. Cos_Opr) .and.
     &    (operator .ne. Tan_Opr) .and.
     &    (operator .ne. Sinh_Opr) .and.
     &    (operator .ne. Cosh_Opr) .and.
     &    (operator .ne. Tanh_Opr) .and.
     &    (operator .ne. Asin_Opr) .and.
     &    (operator .ne. Acos_Opr) .and.
     &    (operator .ne. Atan_Opr) .and.
     &    (operator .ne. Atan2_Opr) .and.
     &    (operator .ne. Log_10_Opr) .and.
     &    (operator .ne. Log_E_Opr) .and.
     &    (operator .ne. Cmplx_Opr) .and.
     &    (operator .ne. Exp_Opr) .and.
     &    (operator .ne. Dprod_Opr) .and.
     &    (operator .ne. Aint_Opr) .and.
     &    (operator .ne. Floor_Opr) .and.
     &    (operator .ne. Nearest_Opr) .and.
     &    (operator .ne. Ceiling_Opr) .and.
     &    (operator .ne. Fraction_Opr) .and.
     &    (operator .ne. Modulo_Opr) .and.
     &    (operator .ne. Mod_Opr)) then
         call fold_f_abort(operator)    
      endif



      left_opnd(1) = left(1)
      left_opnd(2) = left(2)
      left_opnd(3) = left(3)
      left_opnd(4) = left(4)
      left_opnd(5) = left(5)
      left_opnd(6) = left(6)
      left_opnd(7) = left(7)
      left_opnd(8) = left(8)

      right_opnd(1) = right(1)
      right_opnd(2) = right(2)
      right_opnd(3) = right(3)
      right_opnd(4) = right(4)
      right_opnd(5) = right(5)
      right_opnd(6) = right(6)
      right_opnd(7) = right(7)
      right_opnd(8) = right(8)

      third_opnd(1) = third(1)
      third_opnd(2) = third(2)
      third_opnd(3) = third(3)
      third_opnd(4) = third(4)
      third_opnd(5) = third(5)
      third_opnd(6) = third(6)
      third_opnd(7) = third(7)
      third_opnd(8) = third(8)

	oper_type = operator * 1000000
	oper_type = oper_type + (result_type*10000)
	oper_type = oper_type + (left_type*100)
	oper_type = oper_type + right_type

      if (result_type .eq. Real_4) then  

         if (operator .eq. Sqrt_Opr) then
            real_4_result = SQRT(real_4_l_opnd)
         elseif (operator .eq. Sin_Opr) then
            real_4_result = SIN(real_4_l_opnd)
         elseif (operator .eq. Cos_Opr) then
            real_4_result = COS(real_4_l_opnd)
         elseif (operator .eq. Tan_Opr) then
            real_4_result = TAN(real_4_l_opnd)
         elseif (operator .eq. Asin_Opr) then
            real_4_result = ASIN(real_4_l_opnd)
         elseif (operator .eq. Acos_Opr) then
            real_4_result = ACOS(real_4_l_opnd)
         elseif (operator .eq. Atan_Opr) then
            real_4_result = ATAN(real_4_l_opnd)
         elseif (operator .eq. Atan2_Opr) then
            real_4_result = ATAN2(real_4_l_opnd,real_4_r_opnd)
         elseif (operator .eq. Sinh_Opr) then
            real_4_result = SINH(real_4_l_opnd)
         elseif (operator .eq. Cosh_Opr) then
            real_4_result = COSH(real_4_l_opnd)
         elseif (operator .eq. Tanh_Opr) then
            real_4_result = TANH(real_4_l_opnd)
         elseif (operator .eq. Log_E_Opr) then
            real_4_result = LOG(real_4_l_opnd)
         elseif (operator .eq. Log_10_Opr) then
            real_4_result = LOG10(real_4_l_opnd)
         elseif (operator .eq. Log_E_Opr) then
            real_4_result = LOG(real_4_l_opnd)
         elseif (operator .eq. Exp_Opr) then
            real_4_result = EXP(real_4_l_opnd)
         elseif (operator .eq. Aint_Opr) then
            real_4_result = Aint(real_4_l_opnd)
         elseif (operator .eq. Floor_Opr) then
            real_4_result = Floor(real_4_l_opnd)
         elseif (operator .eq. Nearest_Opr) then
            real_4_result = Nearest(real_4_l_opnd,real_4_r_opnd)
         elseif (operator .eq. Ceiling_Opr) then
            real_4_result = Ceiling(real_4_l_opnd)
         elseif (operator .eq. Fraction_Opr) then
            real_4_result = Fraction(real_4_l_opnd)
         elseif (operator .eq. Plus_Opr) then
            real_4_result = real_4_l_opnd + real_4_r_opnd  
         elseif (operator .eq. Uminus_Opr) then
            real_4_result = -(real_4_l_opnd)
         elseif (operator .eq. Minus_Opr) then
            real_4_result = real_4_l_opnd - real_4_r_opnd  
         elseif (operator .eq. Mult_Opr) then
            real_4_result = real_4_l_opnd * real_4_r_opnd  
         elseif (operator .eq. Div_Opr) then
            real_4_result = real_4_l_opnd / real_4_r_opnd  
         elseif (operator .eq. Power_Opr) then
            if (right_type .eq. Integer_1) then
               real_4_result = real_4_l_opnd ** integer_1_r_opnd
            elseif (right_type .eq. Integer_2) then
               real_4_result = real_4_l_opnd ** integer_2_r_opnd
            elseif (right_type .eq. Integer_4) then
               real_4_result = real_4_l_opnd ** integer_4_r_opnd
            elseif (right_type .eq. Integer_8) then
               real_4_result = real_4_l_opnd ** INT(integer_8_r_opnd)
            else 
               real_4_result = real_4_l_opnd ** real_4_r_opnd
            endif
         elseif (operator .eq. Eq_Opr) then
            logical_default_result = real_4_l_opnd .EQ. real_4_r_opnd  
         elseif (operator .eq. Ne_Opr) then
            logical_default_result = real_4_l_opnd .NE. real_4_r_opnd  
         elseif (operator .eq. Lt_Opr) then
            logical_default_result = real_4_l_opnd .LT. real_4_r_opnd  
         elseif (operator .eq. Le_Opr) then
            logical_default_result = real_4_l_opnd .LE. real_4_r_opnd  
         elseif (operator .eq. Gt_Opr) then
            logical_default_result = real_4_l_opnd .GT. real_4_r_opnd  
         elseif (operator .eq. Ge_Opr) then
            logical_default_result = real_4_l_opnd .GE. real_4_r_opnd  
         elseif (operator .eq. Mod_Opr) then
            real_4_result = MOD(real_4_l_opnd, real_4_r_opnd)
         elseif (operator .eq. Modulo_Opr) then
            real_4_result = MODULO(real_4_l_opnd, real_4_r_opnd)
         elseif (operator .eq. Cvrt_Opr) then
            if (left_type .eq. Integer_1) then
               real_4_result = integer_1_l_opnd
            elseif (left_type .eq. Integer_2) then
               real_4_result = integer_2_l_opnd
            elseif (left_type .eq. Integer_4) then
               real_4_result = integer_4_l_opnd
            elseif (left_type .eq. Integer_8) then
               real_4_result = integer_8_l_opnd
            elseif (left_type .eq. Real_4) then
               real_4_result = real_4_l_opnd
            elseif (left_type .eq. Real_8) then
               real_4_result = real_8_l_opnd
            elseif (left_type .eq. Real_16) then
               real_4_result = real_16_l_opnd
            elseif (left_type .eq. Complex_4) then
               real_4_result = complex_4_l_opnd
            elseif (left_type .eq. Complex_8) then
               real_4_result = complex_8_l_opnd
            elseif (left_type .eq. Complex_16) then
               real_4_result = complex_16_l_opnd
	    else
               call fold_f_abort(oper_type)
            endif
         elseif (operator .eq. Abs_Opr) then
            real_4_result = ABS(real_4_l_opnd) 
	 else
            call fold_f_abort(oper_type)
         endif


      elseif (result_type .eq. Real_8) then


         if (operator .eq. Sqrt_Opr) then
            real_8_result = SQRT(real_8_l_opnd)
         elseif (operator .eq. Sin_Opr) then
            real_8_result = SIN(real_8_l_opnd)
         elseif (operator .eq. Cos_Opr) then
            real_8_result = COS(real_8_l_opnd)
         elseif (operator .eq. Tan_Opr) then
            real_8_result = TAN(real_8_l_opnd)
         elseif (operator .eq. Asin_Opr) then
            real_8_result = ASIN(real_8_l_opnd)
         elseif (operator .eq. Acos_Opr) then
            real_8_result = ACOS(real_8_l_opnd)
         elseif (operator .eq. Atan_Opr) then
            real_8_result = ATAN(real_8_l_opnd)
         elseif (operator .eq. Atan2_Opr) then
            real_8_result = ATAN2(real_8_l_opnd,real_8_r_opnd)
         elseif (operator .eq. Sinh_Opr) then
            real_8_result = SINH(real_8_l_opnd)
         elseif (operator .eq. Cosh_Opr) then
            real_8_result = COSH(real_8_l_opnd)
         elseif (operator .eq. Tanh_Opr) then
            real_8_result = TANH(real_8_l_opnd)
         elseif (operator .eq. Log_E_Opr) then
            real_8_result = LOG(real_8_l_opnd)
         elseif (operator .eq. Log_10_Opr) then
            real_8_result = LOG10(real_8_l_opnd)
         elseif (operator .eq. Exp_Opr) then
            real_8_result = EXP(real_8_l_opnd)
         elseif (operator .eq. Dprod_Opr) then
            real_8_result=Dprod(REAL(real_8_l_opnd),REAL(real_8_r_opnd))
         elseif (operator .eq. Aint_Opr) then
            real_8_result = Aint(real_8_l_opnd)
         elseif (operator .eq. Floor_Opr) then
            real_8_result = Floor(real_8_l_opnd)
         elseif (operator .eq. Nearest_Opr) then
            real_8_result = Nearest(real_8_l_opnd,real_8_r_opnd)
         elseif (operator .eq. Ceiling_Opr) then
            real_8_result = Ceiling(real_8_l_opnd)
         elseif (operator .eq. Fraction_Opr) then
            real_8_result = Fraction(real_8_l_opnd)
         elseif (operator .eq. Plus_Opr) then
            real_8_result = real_8_l_opnd + real_8_r_opnd  
         elseif (operator .eq. Uminus_Opr) then
            real_8_result = -(real_8_l_opnd)
         elseif (operator .eq. Minus_Opr) then
            real_8_result = real_8_l_opnd - real_8_r_opnd  
         elseif (operator .eq. Mult_Opr) then
            real_8_result = real_8_l_opnd * real_8_r_opnd  
         elseif (operator .eq. Div_Opr) then
            real_8_result = real_8_l_opnd / real_8_r_opnd  
         elseif (operator .eq. Power_Opr) then
            if (right_type .eq. Integer_1) then
               real_8_result = real_8_l_opnd ** integer_1_r_opnd
            elseif (right_type .eq. Integer_2) then
               real_8_result = real_8_l_opnd ** integer_2_r_opnd
            elseif (right_type .eq. Integer_4) then
               real_8_result = real_8_l_opnd ** integer_4_r_opnd
            elseif (right_type .eq. Integer_8) then
               real_8_result = real_8_l_opnd ** INT(integer_8_r_opnd)
            else 
               real_8_result = real_8_l_opnd ** real_8_r_opnd
            endif
         elseif (operator .eq. Eq_Opr) then
            logical_default_result = real_8_l_opnd .EQ. real_8_r_opnd  
         elseif (operator .eq. Ne_Opr) then
            logical_default_result = real_8_l_opnd .NE. real_8_r_opnd  
         elseif (operator .eq. Lt_Opr) then
            logical_default_result = real_8_l_opnd .LT. real_8_r_opnd  
         elseif (operator .eq. Le_Opr) then
            logical_default_result = real_8_l_opnd .LE. real_8_r_opnd  
         elseif (operator .eq. Gt_Opr) then
            logical_default_result = real_8_l_opnd .GT. real_8_r_opnd  
         elseif (operator .eq. Ge_Opr) then
            logical_default_result = real_8_l_opnd .GE. real_8_r_opnd  
         elseif (operator .eq. Mod_Opr) then
            real_8_result = MOD(real_8_l_opnd, real_8_r_opnd)
         elseif (operator .eq. Modulo_Opr) then
            real_8_result = MODULO(real_8_l_opnd, real_8_r_opnd)
         elseif (operator .eq. Cvrt_Opr) then
            if (left_type .eq. Integer_1) then
               real_8_result = integer_1_l_opnd
            elseif (left_type .eq. Integer_2) then
               real_8_result = integer_2_l_opnd
            elseif (left_type .eq. Integer_4) then
               real_8_result = integer_4_l_opnd
            elseif (left_type .eq. Integer_8) then
               real_8_result = integer_8_l_opnd
            elseif (left_type .eq. Real_4) then
               real_8_result = real_4_l_opnd
            elseif (left_type .eq. Real_8) then
               real_8_result = real_8_l_opnd
            elseif (left_type .eq. Real_16) then
               real_8_result = real_16_l_opnd
            elseif (left_type .eq. Complex_4) then
               real_8_result = complex_4_l_opnd
            elseif (left_type .eq. Complex_8) then
               real_8_result = complex_8_l_opnd
            elseif (left_type .eq. Complex_16) then
               real_8_result = complex_16_l_opnd
	    else
               call fold_f_abort(oper_type)
            endif
         elseif (operator .eq. Abs_Opr) then
            real_8_result = ABS(real_8_l_opnd) 
	 else
            call fold_f_abort(oper_type)
         endif


      elseif (result_type .eq. Real_16) then


         if (operator .eq. Sqrt_Opr) then
            real_16_result = SQRT(real_16_l_opnd)
         elseif (operator .eq. Sin_Opr) then
            real_16_result = SIN(real_16_l_opnd)
         elseif (operator .eq. Cos_Opr) then
            real_16_result = COS(real_16_l_opnd)
         elseif (operator .eq. Tan_Opr) then
            real_16_result = TAN(real_16_l_opnd)
         elseif (operator .eq. Asin_Opr) then
            real_16_result = ASIN(real_16_l_opnd)
         elseif (operator .eq. Acos_Opr) then
            real_16_result = ACOS(real_16_l_opnd)
         elseif (operator .eq. Atan_Opr) then
            real_16_result = ATAN(real_16_l_opnd)
         elseif (operator .eq. Atan2_Opr) then
            real_16_result = ATAN2(real_16_l_opnd,real_16_r_opnd)
         elseif (operator .eq. Sinh_Opr) then
            real_16_result = SINH(real_16_l_opnd)
         elseif (operator .eq. Cosh_Opr) then
            real_16_result = COSH(real_16_l_opnd)
         elseif (operator .eq. Tanh_Opr) then
            real_16_result = TANH(real_16_l_opnd)
         elseif (operator .eq. Log_E_Opr) then
            real_16_result = LOG(real_16_l_opnd)
         elseif (operator .eq. Log_10_Opr) then
            real_16_result = LOG10(real_16_l_opnd)
         elseif (operator .eq. Exp_Opr) then
            real_16_result = EXP(real_16_l_opnd)
         elseif (operator .eq. Aint_Opr) then
            real_16_result = Aint(real_16_l_opnd)
         elseif (operator .eq. Floor_Opr) then
            real_16_result = Floor(real_16_l_opnd)
         elseif (operator .eq. Nearest_Opr) then
            real_16_result = Nearest(real_16_l_opnd,real_16_r_opnd)
         elseif (operator .eq. Ceiling_Opr) then
            real_16_result = Ceiling(real_16_l_opnd)
         elseif (operator .eq. Fraction_Opr) then
            real_16_result = Fraction(real_16_l_opnd)
         elseif (operator .eq. Plus_Opr) then
            real_16_result = real_16_l_opnd + real_16_r_opnd  
         elseif (operator .eq. Uminus_Opr) then
            real_16_result = -(real_16_l_opnd)
         elseif (operator .eq. Minus_Opr) then
            real_16_result = real_16_l_opnd - real_16_r_opnd  
         elseif (operator .eq. Mult_Opr) then
            real_16_result = real_16_l_opnd * real_16_r_opnd  
         elseif (operator .eq. Div_Opr) then
            real_16_result = real_16_l_opnd / real_16_r_opnd  
         elseif (operator .eq. Power_Opr) then
            if (right_type .eq. Integer_1) then
               real_16_result = real_16_l_opnd ** integer_1_r_opnd
            elseif (right_type .eq. Integer_2) then
               real_16_result = real_16_l_opnd ** integer_2_r_opnd
            elseif (right_type .eq. Integer_4) then
               real_16_result = real_16_l_opnd ** integer_4_r_opnd
            elseif (right_type .eq. Integer_8) then
               real_16_result = real_16_l_opnd ** INT(integer_8_r_opnd)
            else 
               real_16_result = real_16_l_opnd ** real_16_r_opnd
            endif
         elseif (operator .eq. Eq_Opr) then
            logical_default_result = real_16_l_opnd .EQ. real_16_r_opnd  
         elseif (operator .eq. Ne_Opr) then
            logical_default_result = real_16_l_opnd .NE. real_16_r_opnd  
         elseif (operator .eq. Lt_Opr) then
            logical_default_result = real_16_l_opnd .LT. real_16_r_opnd  
         elseif (operator .eq. Le_Opr) then
            logical_default_result = real_16_l_opnd .LE. real_16_r_opnd  
         elseif (operator .eq. Gt_Opr) then
            logical_default_result = real_16_l_opnd .GT. real_16_r_opnd  
         elseif (operator .eq. Ge_Opr) then
            logical_default_result = real_16_l_opnd .GE. real_16_r_opnd  
         elseif (operator .eq. Mod_Opr) then
            real_16_result = MOD(real_16_l_opnd, real_16_r_opnd)
         elseif (operator .eq. Modulo_Opr) then
            real_16_result = MODULO(real_16_l_opnd, real_16_r_opnd)
         elseif (operator .eq. Cvrt_Opr) then
            if (left_type .eq. Integer_1) then
               real_16_result = integer_1_l_opnd
            elseif (left_type .eq. Integer_2) then
               real_16_result = integer_2_l_opnd
            elseif (left_type .eq. Integer_4) then
               real_16_result = integer_4_l_opnd
            elseif (left_type .eq. Integer_8) then
               real_16_result = integer_8_l_opnd
            elseif (left_type .eq. Real_4) then
               real_16_result = real_4_l_opnd
            elseif (left_type .eq. Real_8) then
               real_16_result = real_8_l_opnd
            elseif (left_type .eq. Real_16) then
               real_16_result = real_16_l_opnd
            elseif (left_type .eq. Complex_4) then
               real_16_result = complex_4_l_opnd
            elseif (left_type .eq. Complex_8) then
               real_16_result = complex_8_l_opnd
            elseif (left_type .eq. Complex_16) then
               real_16_result = complex_16_l_opnd
	    else
               call fold_f_abort(oper_type)
            endif
         elseif (operator .eq. Abs_Opr) then
            real_16_result = ABS(real_16_l_opnd) 
	 else
            call fold_f_abort(oper_type)
         endif


      elseif (result_type .eq. Complex_4) then

         if (operator .eq. Sqrt_Opr) then
            complex_4_result = SQRT(complex_4_l_opnd)
         elseif (operator .eq. Sin_Opr) then
            complex_4_result = SIN(complex_4_l_opnd)
         elseif (operator .eq. Cos_Opr) then
            complex_4_result = COS(complex_4_l_opnd)
         elseif (operator .eq. Log_E_Opr) then
            complex_4_result = LOG(complex_4_l_opnd)
         elseif (operator .eq. Exp_Opr) then
            complex_4_result = EXP(complex_4_l_opnd)
         elseif (operator .eq. Cmplx_Opr) then
            if (left_type .eq. Complex_4) then
               complex_4_result = CMPLX(complex_4_l_opnd)
            elseif (left_type .eq. Real_4) then
               complex_4_result = CMPLX(real_4_l_opnd,real_4_r_opnd)
            elseif (left_type .eq. Complex_8) then
               complex_8_result = DCMPLX(complex_8_l_opnd)
            elseif (left_type .eq. Real_8) then
               complex_4_result = CMPLX(real_8_l_opnd,real_8_r_opnd)
            elseif (left_type .eq. Real_16) then
               complex_4_result = CMPLX(real_16_l_opnd,real_16_r_opnd)
            elseif (left_type .eq. Complex_8) then
               complex_4_result = CMPLX(complex_8_l_opnd)
            endif
         elseif (operator .eq. Plus_Opr) then
            complex_4_result = complex_4_l_opnd + complex_4_r_opnd  
         elseif (operator .eq. Uminus_Opr) then
            complex_4_result = -(complex_4_l_opnd)
         elseif (operator .eq. Minus_Opr) then
            complex_4_result = complex_4_l_opnd - complex_4_r_opnd  
         elseif (operator .eq. Mult_Opr) then
            complex_4_result = complex_4_l_opnd * complex_4_r_opnd  
         elseif (operator .eq. Div_Opr) then
            complex_4_result = complex_4_l_opnd / complex_4_r_opnd  
         elseif (operator .eq. Power_Opr) then
            if (right_type .eq. Integer_1) then
               integer_4_r_opnd = integer_1_r_opnd
               call pow_ci(complex_4_result, complex_4_l_opnd,
     &            integer_4_r_opnd)
            elseif (right_type .eq. Integer_2) then
               integer_4_r_opnd = integer_2_r_opnd
               call pow_ci(complex_4_result, complex_4_l_opnd,
     &            integer_4_r_opnd)
            elseif (right_type .eq. Integer_4) then
               call pow_ci(complex_4_result, complex_4_l_opnd,
     &            integer_4_r_opnd)
            elseif (right_type .eq. Integer_8) then
               call pow_cl(complex_4_result, complex_4_l_opnd,
     &            integer_8_r_opnd)
            elseif (left_type .eq. Complex_4) then
	       complex_4_l_opnd = DCMPLX(complex_4_l_opnd)
               call pow_cc(complex_4_result, complex_4_l_opnd,
     &            complex_4_r_opnd)
            elseif (right_type .eq. Complex_4) then
	       complex_4_r_opnd = DCMPLX(complex_4_r_opnd)
               call pow_cc(complex_4_result, complex_4_l_opnd,
     &            complex_4_r_opnd)
	    else
               call fold_f_abort(oper_type)
            endif
         elseif (operator .eq. Eq_Opr) then
            logical_default_result = complex_4_l_opnd .EQ. 
     &                               complex_4_r_opnd  
         elseif (operator .eq. Ne_Opr) then
            logical_default_result = complex_4_l_opnd .NE. 
     &                               complex_4_r_opnd  
         elseif (operator .eq. Cvrt_Opr) then
            if (left_type .eq. Integer_1) then
               complex_4_result = integer_1_l_opnd
            elseif (left_type .eq. Integer_2) then
               complex_4_result = integer_2_l_opnd
            elseif (left_type .eq. Integer_4) then
               complex_4_result = integer_4_l_opnd
            elseif (left_type .eq. Integer_8) then
               complex_4_result = integer_8_l_opnd
            elseif (left_type .eq. Real_4) then
               complex_4_result = real_4_l_opnd
            elseif (left_type .eq. Real_8) then
               complex_4_result = real_8_l_opnd
            elseif (left_type .eq. Real_16) then
               complex_4_result = real_16_l_opnd
            elseif (left_type .eq. Complex_4) then
               complex_4_result = complex_4_l_opnd
            elseif (left_type .eq. Complex_8) then
               complex_4_result = complex_8_l_opnd
            elseif (left_type .eq. Complex_16) then
               complex_4_result = complex_16_l_opnd
	    else
               call fold_f_abort(oper_type)
            endif
         elseif (operator .eq. Abs_Opr) then
            real_4_result = ABS(complex_4_l_opnd) 
	 else
            call fold_f_abort(oper_type)
         endif
      elseif (result_type .eq. Complex_8) then

         if (operator .eq. Sqrt_Opr) then
            complex_8_result = SQRT(complex_8_l_opnd)
         elseif (operator .eq. Sin_Opr) then
            complex_8_result = SIN(complex_8_l_opnd)
         elseif (operator .eq. Cos_Opr) then
            complex_8_result = COS(complex_8_l_opnd)
         elseif (operator .eq. Log_E_Opr) then
            complex_8_result = LOG(complex_8_l_opnd)
         elseif (operator .eq. Exp_Opr) then
            complex_8_result = EXP(complex_8_l_opnd)
         elseif (operator .eq. Cmplx_Opr) then
            if (left_type .eq. Complex_4) then
               complex_8_result = DCMPLX(complex_4_l_opnd)
            elseif (left_type .eq. Real_4) then
               complex_8_result = DCMPLX(real_4_l_opnd,real_4_r_opnd)
            elseif (left_type .eq. Complex_8) then
               complex_8_result = DCMPLX(complex_8_l_opnd)
            elseif (left_type .eq. Real_8) then
               complex_8_result = DCMPLX(real_8_l_opnd,real_8_r_opnd)
            elseif (left_type .eq. Real_16) then
               complex_8_result = DCMPLX(real_16_l_opnd,real_16_r_opnd)
            elseif (left_type .eq. Complex_8) then
               complex_8_result = DCMPLX(complex_8_l_opnd)
            endif
         elseif (operator .eq. Plus_Opr) then
            complex_8_result = complex_8_l_opnd + complex_8_r_opnd  
         elseif (operator .eq. Uminus_Opr) then
            complex_8_result = -(complex_8_l_opnd)
         elseif (operator .eq. Minus_Opr) then
            complex_8_result = complex_8_l_opnd - complex_8_r_opnd  
         elseif (operator .eq. Mult_Opr) then
            complex_8_result = complex_8_l_opnd * complex_8_r_opnd  
         elseif (operator .eq. Div_Opr) then
            complex_8_result = complex_8_l_opnd / complex_8_r_opnd  
         elseif (operator .eq. Power_Opr) then
            if (right_type .eq. Integer_1) then
               integer_4_r_opnd = integer_1_r_opnd
               call pow_zi(complex_8_result, complex_8_l_opnd,
     &            integer_4_r_opnd)
            elseif (right_type .eq. Integer_2) then
               integer_4_r_opnd = integer_2_r_opnd
               call pow_zi(complex_8_result, complex_8_l_opnd,
     &            integer_4_r_opnd)
            elseif (right_type .eq. Integer_4) then
               call pow_zi(complex_8_result, complex_8_l_opnd,
     &            integer_4_r_opnd)
            elseif (right_type .eq. Integer_8) then
               call pow_zl(complex_8_result, complex_8_l_opnd,
     &            integer_8_r_opnd)
            elseif (left_type .eq. Complex_4) then
	       complex_8_l_opnd = DCMPLX(complex_4_l_opnd)
               call pow_zz(complex_8_result, complex_8_l_opnd,
     &            complex_8_r_opnd)
            elseif (right_type .eq. Complex_4) then
	       complex_8_r_opnd = DCMPLX(complex_4_r_opnd)
               call pow_zz(complex_8_result, complex_8_l_opnd,
     &            complex_8_r_opnd)
	    else
               call pow_zz(complex_8_result, complex_8_l_opnd,
     &            complex_8_r_opnd)
            endif
         elseif (operator .eq. Eq_Opr) then
            logical_default_result = complex_8_l_opnd .EQ. 
     &                               complex_8_r_opnd  
         elseif (operator .eq. Ne_Opr) then
            logical_default_result = complex_8_l_opnd .NE. 
     &                               complex_8_r_opnd  
         elseif (operator .eq. Cvrt_Opr) then
            if (left_type .eq. Integer_1) then
               complex_8_result = integer_1_l_opnd
            elseif (left_type .eq. Integer_2) then
               complex_8_result = integer_2_l_opnd
            elseif (left_type .eq. Integer_4) then
               complex_8_result = integer_4_l_opnd
            elseif (left_type .eq. Integer_8) then
               complex_8_result = integer_8_l_opnd
            elseif (left_type .eq. Real_4) then
               complex_8_result = real_4_l_opnd
            elseif (left_type .eq. Real_8) then
               complex_8_result = real_8_l_opnd
            elseif (left_type .eq. Real_16) then
               complex_8_result = real_16_l_opnd
            elseif (left_type .eq. Complex_4) then
               complex_8_result = complex_4_l_opnd
            elseif (left_type .eq. Complex_8) then
               complex_8_result = complex_8_l_opnd
            elseif (left_type .eq. Complex_16) then
               complex_8_result = complex_16_l_opnd
	    else
               call fold_f_abort(oper_type)
            endif
         elseif (operator .eq. Abs_Opr) then
            real_8_result = ABS(complex_8_l_opnd) 
	 else
            call fold_f_abort(oper_type)
         endif

      elseif (result_type .eq. Complex_16) then


         if (operator .eq. Sqrt_Opr) then
            complex_16_result = SQRT(complex_16_l_opnd)
         elseif (operator .eq. Sin_Opr) then
            complex_16_result = SIN(complex_16_l_opnd)
         elseif (operator .eq. Cos_Opr) then
            complex_16_result = COS(complex_16_l_opnd)
         elseif (operator .eq. Log_E_Opr) then
            complex_16_result = LOG(complex_16_l_opnd)
         elseif (operator .eq. Exp_Opr) then
            complex_16_result = EXP(complex_16_l_opnd)
         elseif (operator .eq. Plus_Opr) then
            complex_16_result = complex_16_l_opnd + complex_16_r_opnd  
         elseif (operator .eq. Uminus_Opr) then
            complex_16_result = -(complex_16_l_opnd)
         elseif (operator .eq. Minus_Opr) then
            complex_16_result = complex_16_l_opnd - complex_16_r_opnd  
         elseif (operator .eq. Mult_Opr) then
            complex_16_result = complex_16_l_opnd * complex_16_r_opnd  
         elseif (operator .eq. Div_Opr) then
            complex_16_result = complex_16_l_opnd / complex_16_r_opnd  
         elseif (operator .eq. Eq_Opr) then
            logical_default_result = complex_16_l_opnd .EQ. 
     &                               complex_16_r_opnd  
         elseif (operator .eq. Ne_Opr) then
            logical_default_result = complex_16_l_opnd .NE. 
     &                               complex_16_r_opnd  
         elseif (operator .eq. Cvrt_Opr) then
            if (left_type .eq. Integer_1) then
               complex_16_result = integer_1_l_opnd
            elseif (left_type .eq. Integer_2) then
               complex_16_result = integer_2_l_opnd
            elseif (left_type .eq. Integer_4) then
               complex_16_result = integer_4_l_opnd
            elseif (left_type .eq. Integer_8) then
               complex_16_result = integer_8_l_opnd
            elseif (left_type .eq. Real_4) then
               complex_16_result = real_4_l_opnd
            elseif (left_type .eq. Real_8) then
               complex_16_result = real_8_l_opnd
            elseif (left_type .eq. Real_16) then
               complex_16_result = real_16_l_opnd
            elseif (left_type .eq. Complex_4) then
               complex_16_result = complex_4_l_opnd
            elseif (left_type .eq. Complex_8) then
               complex_16_result = complex_8_l_opnd
            elseif (left_type .eq. Complex_16) then
               complex_16_result = complex_16_l_opnd
	    else
               call fold_f_abort(oper_type)
            endif
         elseif (operator .eq. Abs_Opr) then
            real_16_result = ABS(complex_16_l_opnd) 
	 else
            call fold_f_abort(oper_type)
         endif


      elseif (result_type .eq. Integer_1) then


         if (operator .eq. Plus_Opr) then
            integer_1_result = integer_1_l_opnd + integer_1_r_opnd
         elseif (operator .eq. Uminus_Opr) then
            integer_1_result = -(integer_1_l_opnd)
         elseif (operator .eq. Minus_Opr) then
            integer_1_result = integer_1_l_opnd - integer_1_r_opnd
         elseif (operator .eq. Mult_Opr) then
            integer_1_result = integer_1_l_opnd * integer_1_r_opnd
         elseif (operator .eq. Div_Opr) then
            integer_1_result = integer_1_l_opnd / integer_1_r_opnd
         elseif (operator .eq. Power_Opr) then
            integer_1_result = integer_1_l_opnd ** integer_1_r_opnd
         elseif (operator .eq. Eq_Opr) then
            logical_default_result = integer_1_l_opnd .EQ. 
     &                               integer_1_r_opnd
         elseif (operator .eq. Ne_Opr) then
            logical_default_result = integer_1_l_opnd .NE. 
     &                               integer_1_r_opnd
         elseif (operator .eq. Lt_Opr) then
            logical_default_result = integer_1_l_opnd .LT. 
     &                               integer_1_r_opnd
         elseif (operator .eq. Le_Opr) then
            logical_default_result = integer_1_l_opnd .LE. 
     &                               integer_1_r_opnd
         elseif (operator .eq. Gt_Opr) then
            logical_default_result = integer_1_l_opnd .GT. 
     &                               integer_1_r_opnd
         elseif (operator .eq. Ge_Opr) then
            logical_default_result = integer_1_l_opnd .GE. 
     &                               integer_1_r_opnd
         elseif (operator .eq. Shiftl_Opr) then
            integer_1_result = ISHFT(integer_1_l_opnd, 
     &                               integer_1_r_opnd)
         elseif (operator .eq. Shift_Opr) then
            integer_1_result = ISHFTC(integer_1_l_opnd, 
     &                                integer_1_r_opnd, 8)
         elseif (operator .eq. Shiftr_Opr) then
            integer_1_result = ISHFT(integer_1_l_opnd, 
     &                               -integer_1_r_opnd)
         elseif (operator .eq. Shifta_Opr) then
            if (integer_1_l_opnd .GE. 0) then
               integer_1_result = ISHFT(integer_1_l_opnd, 
     &                                  -integer_1_r_opnd)
            else
               integer_1_result = integer_1_l_opnd
               do i = 1,integer_1_r_opnd
                  integer_1_result = ISHFT(integer_1_result,-1)
                  integer_1_result = IBSET(integer_1_result,7)
               enddo
            endif
         elseif (operator .eq. Mod_Opr) then
            integer_1_result = MOD(integer_1_l_opnd, 
     &                             integer_1_r_opnd)
         elseif (operator .eq. Modulo_Opr) then
            integer_1_result = MODULO(integer_1_l_opnd, 
     &                                integer_1_r_opnd)
         elseif (operator .eq. Cvrt_Opr) then
            if (left_type .eq. Integer_1) then
               integer_1_result = integer_1_l_opnd
            elseif (left_type .eq. Integer_2) then
               integer_1_result = integer_2_l_opnd
            elseif (left_type .eq. Integer_4) then
               integer_1_result = integer_4_l_opnd
            elseif (left_type .eq. Integer_8) then
               integer_1_result = integer_8_l_opnd
            elseif (left_type .eq. Real_4) then
               integer_1_result = real_4_l_opnd
            elseif (left_type .eq. Real_8) then
               integer_1_result = real_8_l_opnd
            elseif (left_type .eq. Real_16) then
               integer_1_result = real_16_l_opnd
            elseif (left_type .eq. Complex_4) then
               integer_1_result = complex_4_l_opnd
            elseif (left_type .eq. Complex_8) then
               integer_1_result = complex_8_l_opnd
            elseif (left_type .eq. Complex_16) then
               integer_1_result = complex_16_l_opnd
	    else
               call fold_f_abort(oper_type)
            endif
         elseif (operator .eq. Abs_Opr) then
            integer_1_result = ABS(integer_1_l_opnd) 
         elseif (operator .eq. Ibits_Opr) then
            integer_1_result = IBITS(integer_1_l_opnd, 
     &                               integer_1_r_opnd, 
     &                               integer_1_t_opnd) 
         elseif (operator .eq. Ishftc_Opr) then
            integer_1_result = ISHFTC(integer_1_l_opnd, 
     &                                integer_1_r_opnd, 
     &                                integer_1_t_opnd) 
         elseif (operator .eq. Nint_Opr) then
            if (left_type .eq. Real_4) then
               integer_1_result = NINT(real_4_l_opnd)
            elseif (left_type .eq. Real_8) then
               integer_1_result = NINT(real_8_l_opnd)
            elseif (left_type .eq. Real_16) then
               integer_1_result = NINT(real_16_l_opnd)
	    else
                call fold_f_abort(oper_type)
            endif
	 else
            call fold_f_abort(oper_type)
         endif

         integer_8_result = integer_1_result;

      elseif (result_type .eq. Integer_2) then


         if (operator .eq. Plus_Opr) then
            integer_2_result = integer_2_l_opnd + integer_2_r_opnd
         elseif (operator .eq. Uminus_Opr) then
            integer_2_result = -(integer_2_l_opnd)
         elseif (operator .eq. Minus_Opr) then
            integer_2_result = integer_2_l_opnd - integer_2_r_opnd
         elseif (operator .eq. Mult_Opr) then
            integer_2_result = integer_2_l_opnd * integer_2_r_opnd
         elseif (operator .eq. Div_Opr) then
            integer_2_result = integer_2_l_opnd / integer_2_r_opnd
         elseif (operator .eq. Power_Opr) then
            integer_2_result = integer_2_l_opnd ** integer_2_r_opnd
         elseif (operator .eq. Eq_Opr) then
            logical_default_result = integer_2_l_opnd .EQ. 
     &                                             integer_2_r_opnd
         elseif (operator .eq. Ne_Opr) then
            logical_default_result = integer_2_l_opnd .NE. 
     &                               integer_2_r_opnd
         elseif (operator .eq. Lt_Opr) then
            logical_default_result = integer_2_l_opnd .LT. 
     &                               integer_2_r_opnd
         elseif (operator .eq. Le_Opr) then
            logical_default_result = integer_2_l_opnd .LE. 
     &                               integer_2_r_opnd
         elseif (operator .eq. Gt_Opr) then
            logical_default_result = integer_2_l_opnd .GT. 
     &                               integer_2_r_opnd
         elseif (operator .eq. Ge_Opr) then
            logical_default_result = integer_2_l_opnd .GE. 
     &                               integer_2_r_opnd
         elseif (operator .eq. Shiftl_Opr) then
            integer_2_result = ISHFT(integer_2_l_opnd, 
     &                               integer_2_r_opnd)
         elseif (operator .eq. Shift_Opr) then
            integer_2_result = ISHFTC(integer_2_l_opnd, 
     &                                integer_2_r_opnd, 16)
         elseif (operator .eq. Shiftr_Opr) then
            integer_2_result = ISHFT(integer_2_l_opnd, 
     &                               -integer_2_r_opnd)
         elseif (operator .eq. Shifta_Opr) then
            if (integer_2_l_opnd .GE. 0) then
               integer_2_result = ISHFT(integer_2_l_opnd,
     &                                  -integer_2_r_opnd)
            else
               integer_2_result = integer_2_l_opnd
               do i = 1,integer_2_r_opnd
                  integer_2_result = ISHFT(integer_2_result,-1)
                  integer_2_result = IBSET(integer_2_result,15)
               enddo
            endif
         elseif (operator .eq. Mod_Opr) then
            integer_2_result = MOD(integer_2_l_opnd, 
     &                             integer_2_r_opnd)
         elseif (operator .eq. Modulo_Opr) then
            integer_2_result = MODULO(integer_2_l_opnd, 
     &                                integer_2_r_opnd)
         elseif (operator .eq. Cvrt_Opr) then
            if (left_type .eq. Integer_1) then
               integer_2_result = integer_1_l_opnd
            elseif (left_type .eq. Integer_2) then
               integer_2_result = integer_2_l_opnd
            elseif (left_type .eq. Integer_4) then
               integer_2_result = integer_4_l_opnd
            elseif (left_type .eq. Integer_8) then
               integer_2_result = integer_8_l_opnd
            elseif (left_type .eq. Real_4) then
               integer_2_result = real_4_l_opnd
            elseif (left_type .eq. Real_8) then
               integer_2_result = real_8_l_opnd
            elseif (left_type .eq. Real_16) then
               integer_2_result = real_16_l_opnd
            elseif (left_type .eq. Complex_4) then
               integer_2_result = complex_4_l_opnd
            elseif (left_type .eq. Complex_8) then
               integer_2_result = complex_8_l_opnd
            elseif (left_type .eq. Complex_16) then
               integer_2_result = complex_16_l_opnd
	    else
               call fold_f_abort(oper_type)
            endif
         elseif (operator .eq. Abs_Opr) then
            integer_2_result = ABS(integer_2_l_opnd) 
         elseif (operator .eq. Ibits_Opr) then
            integer_2_result = IBITS(integer_2_l_opnd,   
     &                               integer_2_r_opnd,
     &                               integer_2_t_opnd) 
         elseif (operator .eq. Ishftc_Opr) then
            integer_2_result = ISHFTC(integer_2_l_opnd,    
     &                                integer_2_r_opnd,
     &                                integer_2_t_opnd)
         elseif (operator .eq. Nint_Opr) then
            if (left_type .eq. Real_4) then
               integer_2_result = NINT(real_4_l_opnd)
            elseif (left_type .eq. Real_8) then
               integer_2_result = NINT(real_8_l_opnd)
            elseif (left_type .eq. Real_16) then
               integer_2_result = NINT(real_16_l_opnd)
	    else
               call fold_f_abort(oper_type)
            endif
	 else
            call fold_f_abort(oper_type)
         endif

         integer_8_result = integer_2_result;

      elseif (result_type .eq. Integer_4) then


         if (operator .eq. Plus_Opr) then
            integer_4_result = integer_4_l_opnd + integer_4_r_opnd  
         elseif (operator .eq. Uminus_Opr) then
            integer_4_result = -(integer_4_l_opnd)
         elseif (operator .eq. Minus_Opr) then
            integer_4_result = integer_4_l_opnd - integer_4_r_opnd  
         elseif (operator .eq. Mult_Opr) then
            integer_4_result = integer_4_l_opnd * integer_4_r_opnd  
         elseif (operator .eq. Div_Opr) then
            integer_4_result = integer_4_l_opnd / integer_4_r_opnd  
         elseif (operator .eq. Power_Opr) then
            integer_4_result = integer_4_l_opnd ** integer_4_r_opnd
         elseif (operator .eq. Eq_Opr) then
            logical_default_result = integer_4_l_opnd .EQ. 
     &                               integer_4_r_opnd  
         elseif (operator .eq. Ne_Opr) then
            logical_default_result = integer_4_l_opnd .NE. 
     &                               integer_4_r_opnd  
         elseif (operator .eq. Lt_Opr) then
            logical_default_result = integer_4_l_opnd .LT. 
     &                               integer_4_r_opnd  
         elseif (operator .eq. Le_Opr) then
            logical_default_result = integer_4_l_opnd .LE. 
     &                               integer_4_r_opnd  
         elseif (operator .eq. Gt_Opr) then
            logical_default_result = integer_4_l_opnd .GT. 
     &                               integer_4_r_opnd  
         elseif (operator .eq. Ge_Opr) then
            logical_default_result = integer_4_l_opnd .GE. 
     &                               integer_4_r_opnd  
         elseif (operator .eq. Shiftl_Opr) then
            integer_4_result = ISHFT(integer_4_l_opnd, 
     &                               integer_4_r_opnd)
         elseif (operator .eq. Shift_Opr) then
            integer_4_result = ISHFTC(integer_4_l_opnd, 
     &                                integer_4_r_opnd, 32)
         elseif (operator .eq. Shiftr_Opr) then
            integer_4_result = ISHFT(integer_4_l_opnd, 
     &                               -integer_4_r_opnd)
         elseif (operator .eq. Shifta_Opr) then
            if (integer_4_l_opnd .GE. 0) then
               integer_4_result = ISHFT(integer_4_l_opnd,
     &                                  -integer_4_r_opnd)
            else
               integer_4_result = integer_4_l_opnd
               do i = 1,integer_4_r_opnd
                  integer_4_result = ISHFT(integer_4_result,-1)
                  integer_4_result = IBSET(integer_4_result,31)
               enddo
            endif
         elseif (operator .eq. Mod_Opr) then
            integer_4_result = MOD(integer_4_l_opnd, 
     &                             integer_4_r_opnd)
         elseif (operator .eq. Modulo_Opr) then
            integer_4_result = MODULO(integer_4_l_opnd, 
     &                                integer_4_r_opnd)
         elseif (operator .eq. Cvrt_Opr) then
            if (left_type .eq. Integer_1) then
               integer_4_result = integer_1_l_opnd
            elseif (left_type .eq. Integer_2) then
               integer_4_result = integer_2_l_opnd
            elseif (left_type .eq. Integer_4) then
               integer_4_result = integer_4_l_opnd
            elseif (left_type .eq. Integer_8) then
               integer_4_result = integer_8_l_opnd
            elseif (left_type .eq. Real_4) then
               integer_4_result = real_4_l_opnd
            elseif (left_type .eq. Real_8) then
               integer_4_result = real_8_l_opnd
            elseif (left_type .eq. Real_16) then
               integer_4_result = real_16_l_opnd
            elseif (left_type .eq. Complex_4) then
               integer_4_result = complex_4_l_opnd
            elseif (left_type .eq. Complex_8) then
               integer_4_result = complex_8_l_opnd
            elseif (left_type .eq. Complex_16) then
               integer_4_result = complex_16_l_opnd
	    else
               call fold_f_abort(oper_type)
            endif
         elseif (operator .eq. Abs_Opr) then
            integer_4_result = ABS(integer_4_l_opnd) 
         elseif (operator .eq. Ibits_Opr) then
            integer_4_result = IBITS(integer_4_l_opnd,   
     &                               integer_4_r_opnd,
     &                               integer_4_t_opnd) 
         elseif (operator .eq. Ishftc_Opr) then
            integer_4_result = ISHFTC(integer_4_l_opnd,    
     &                                integer_4_r_opnd,
     &                                integer_4_t_opnd)
         elseif (operator .eq. Nint_Opr) then
            if (left_type .eq. Real_4) then
               integer_4_result = NINT(real_4_l_opnd)
            elseif (left_type .eq. Real_8) then
               integer_4_result = NINT(real_8_l_opnd)
            elseif (left_type .eq. Real_16) then
               integer_4_result = NINT(real_16_l_opnd)
	    else
               call fold_f_abort(oper_type)
            endif
         elseif (operator .eq. SRK_Opr) then
            if (left_type .eq. 0) then
               integer_4_result = SELECTED_REAL_KIND(R=integer_4_r_opnd)
            elseif (right_type .eq. 0) then
               integer_4_result = SELECTED_REAL_KIND(P=integer_4_l_opnd)
            else
               integer_4_result = SELECTED_REAL_KIND(integer_4_l_opnd,
     &                                               integer_4_r_opnd)  
            endif
	 else
            call fold_f_abort(oper_type)
         endif

         integer_8_result = integer_4_result;

      elseif (result_type .eq. Integer_8) then


         if (operator .eq. Plus_Opr) then
            integer_8_result = integer_8_l_opnd + integer_8_r_opnd  
         elseif (operator .eq. Uminus_Opr) then
            integer_8_result = -(integer_8_l_opnd)
         elseif (operator .eq. Minus_Opr) then
            integer_8_result = integer_8_l_opnd - integer_8_r_opnd  
         elseif (operator .eq. Mult_Opr) then
            integer_8_result = integer_8_l_opnd * integer_8_r_opnd  
         elseif (operator .eq. Div_Opr) then
            integer_8_result = integer_8_l_opnd / integer_8_r_opnd  
         elseif (operator .eq. Power_Opr) then
            integer_8_result = integer_8_l_opnd ** integer_8_r_opnd
         elseif (operator .eq. Eq_Opr) then
            logical_default_result = integer_8_l_opnd .EQ. 
     &                               integer_8_r_opnd  
         elseif (operator .eq. Ne_Opr) then
            logical_default_result = integer_8_l_opnd .NE. 
     &                               integer_8_r_opnd  
         elseif (operator .eq. Lt_Opr) then
            logical_default_result = integer_8_l_opnd .LT. 
     &                               integer_8_r_opnd  
         elseif (operator .eq. Le_Opr) then
            logical_default_result = integer_8_l_opnd .LE. 
     &                               integer_8_r_opnd  
         elseif (operator .eq. Gt_Opr) then
            logical_default_result = integer_8_l_opnd .GT. 
     &                               integer_8_r_opnd  
         elseif (operator .eq. Ge_Opr) then
            logical_default_result = integer_8_l_opnd .GE. 
     &                               integer_8_r_opnd  
         elseif (operator .eq. Shiftl_Opr) then
            integer_8_result = ISHFT(integer_8_l_opnd, 
     &                               integer_8_r_opnd)
         elseif (operator .eq. Shift_Opr) then
            integer_8_result = ISHFTC(integer_8_l_opnd, 
     &                                integer_8_r_opnd, 64)
         elseif (operator .eq. Shiftr_Opr) then
            integer_8_result = ISHFT(integer_8_l_opnd, 
     &                               -integer_8_r_opnd)
         elseif (operator .eq. Shifta_Opr) then
            if (integer_8_l_opnd .GE. 0) then
               integer_8_result = ISHFT(integer_8_l_opnd,
     &                                  -integer_8_r_opnd)
            else
               integer_8_result = integer_8_l_opnd
               do i = 1,integer_8_r_opnd
                  integer_8_result = ISHFT(integer_8_result,-1)
                  integer_8_result = IBSET(integer_8_result,63)
               enddo
            endif
         elseif (operator .eq. Mod_Opr) then
            integer_8_result = MOD(integer_8_l_opnd, 
     &                             integer_8_r_opnd)
         elseif (operator .eq. Modulo_Opr) then
            integer_8_result = MODULO(integer_8_l_opnd, 
     &                                integer_8_r_opnd)
         elseif (operator .eq. Cvrt_Opr) then
            if (left_type .eq. Integer_1) then
               integer_8_result = integer_1_l_opnd
            elseif (left_type .eq. Integer_2) then
               integer_8_result = integer_2_l_opnd
            elseif (left_type .eq. Integer_4) then
               integer_8_result = integer_4_l_opnd
            elseif (left_type .eq. Integer_8) then
               integer_8_result = integer_8_l_opnd
            elseif (left_type .eq. Real_4) then
               integer_8_result = real_4_l_opnd
            elseif (left_type .eq. Real_8) then
               integer_8_result = real_8_l_opnd
            elseif (left_type .eq. Real_16) then
               integer_8_result = real_16_l_opnd
            elseif (left_type .eq. Complex_4) then
               integer_8_result = complex_4_l_opnd
            elseif (left_type .eq. Complex_8) then
               integer_8_result = complex_8_l_opnd
            elseif (left_type .eq. Complex_16) then
               integer_8_result = complex_16_l_opnd
	    else
               call fold_f_abort(oper_type)
            endif
         elseif (operator .eq. Abs_Opr) then
            integer_8_result = ABS(integer_8_l_opnd) 
         elseif (operator .eq. Ibits_Opr) then
            integer_8_result = IBITS(integer_8_l_opnd,   
     &                               integer_8_r_opnd,
     &                               integer_8_t_opnd) 
         elseif (operator .eq. Ishftc_Opr) then
            integer_8_result = ISHFTC(integer_8_l_opnd,    
     &                                integer_8_r_opnd,
     &                                integer_8_t_opnd)
         elseif (operator .eq. Nint_Opr) then
            if (left_type .eq. Real_4) then
               integer_8_result = NINT(real_4_l_opnd)
            elseif (left_type .eq. Real_8) then
               integer_8_result = NINT(real_8_l_opnd)
            elseif (left_type .eq. Real_16) then
               integer_8_result = NINT(real_16_l_opnd)
	    else
               call fold_f_abort(oper_type)
            endif
         elseif (operator .eq. SRK_Opr) then
            if (left_type .eq. 0) then
               integer_8_result = SELECTED_REAL_KIND(R=integer_8_r_opnd)
            elseif (right_type .eq. 0) then
               integer_8_result = SELECTED_REAL_KIND(P=integer_8_l_opnd)
            else
               integer_8_result = SELECTED_REAL_KIND(integer_8_l_opnd,
     &                                               integer_8_r_opnd)
            endif
	 else
            call fold_f_abort(oper_type)
         endif


      elseif (result_type .eq. Typeless_1) then


         if (operator .eq. Shiftl_Opr) then
            integer_1_result = ISHFT(integer_1_l_opnd, 
     &                               integer_1_r_opnd)
         elseif (operator .eq. Shift_Opr) then
            integer_1_result = ISHFTC(integer_1_l_opnd, 
     &                                integer_1_r_opnd, 8)
         elseif (operator .eq. Shiftr_Opr) then
            integer_1_result = ISHFT(integer_1_l_opnd, 
     &                               -integer_1_r_opnd)
         elseif (operator .eq. Shifta_Opr) then
            if (integer_1_l_opnd .GE. 0) then
               integer_1_result = ISHFT(integer_1_l_opnd,
     &                                  -integer_1_r_opnd)
            else
               integer_1_result = integer_1_l_opnd
               do i = 1,integer_1_r_opnd
                  integer_1_result = ISHFT(integer_1_result,-1)
                  integer_1_result = IBSET(integer_1_result,7)
               enddo
            endif
         elseif (operator .eq. Cvrt_Opr) then
            integer_1_result = integer_1_l_opnd  
	 else
            call fold_f_abort(oper_type)
         endif


      elseif (result_type .eq. Typeless_2) then


         if (operator .eq. Shiftl_Opr) then
            integer_2_result = ISHFT(integer_2_l_opnd, 
     &                               integer_2_r_opnd)
         elseif (operator .eq. Shift_Opr) then
            integer_2_result = ISHFTC(integer_2_l_opnd, 
     &                                integer_2_r_opnd, 16)
         elseif (operator .eq. Shiftr_Opr) then
            integer_2_result = ISHFT(integer_2_l_opnd, 
     &                               -integer_2_r_opnd)
         elseif (operator .eq. Shifta_Opr) then
            if (integer_2_l_opnd .GE. 0) then
               integer_2_result = ISHFT(integer_2_l_opnd,
     &                                  -integer_2_r_opnd)
            else
               integer_2_result = integer_2_l_opnd
               do i = 1,integer_2_r_opnd
                  integer_2_result = ISHFT(integer_2_result,-1)
                  integer_2_result = IBSET(integer_2_result,15)
               enddo
            endif
         elseif (operator .eq. Cvrt_Opr) then
            integer_2_result = integer_2_l_opnd  
	 else
            call fold_f_abort(oper_type)
         endif


      elseif (result_type .eq. Typeless_4) then


         if (operator .eq. Shiftl_Opr) then
            integer_4_result = ISHFT(integer_4_l_opnd, 
     &                               integer_4_r_opnd)
         elseif (operator .eq. Shift_Opr) then
            integer_4_result = ISHFTC(integer_4_l_opnd, 
     &                                integer_4_r_opnd, 32)
         elseif (operator .eq. Shiftr_Opr) then
            integer_4_result = ISHFT(integer_4_l_opnd, 
     &                               -integer_4_r_opnd)
         elseif (operator .eq. Shifta_Opr) then
            if (integer_4_l_opnd .GE. 0) then
               integer_4_result = ISHFT(integer_4_l_opnd,
     &                                  -integer_4_r_opnd)
            else
               integer_4_result = integer_4_l_opnd
               do i = 1,integer_4_r_opnd
                  integer_4_result = ISHFT(integer_4_result,-1)
                  integer_4_result = IBSET(integer_4_result,31)
               enddo
            endif
         elseif (operator .eq. Cvrt_Opr) then
            integer_4_result = integer_4_l_opnd  
	 else
            call fold_f_abort(oper_type)
         endif


      elseif (result_type .eq. Typeless_8) then


         if (operator .eq. Shiftl_Opr) then
            integer_8_result = ISHFT(integer_8_l_opnd, 
     &                               integer_8_r_opnd)
         elseif (operator .eq. Shift_Opr) then
            integer_8_result = ISHFTC(integer_8_l_opnd, 
     &                                integer_8_r_opnd, 64)
         elseif (operator .eq. Shiftr_Opr) then
            integer_8_result = ISHFT(integer_8_l_opnd, 
     &                               -integer_8_r_opnd)
         elseif (operator .eq. Shifta_Opr) then
            if (integer_8_l_opnd .GE. 0) then
               integer_8_result = ISHFT(integer_8_l_opnd,
     &                                  -integer_8_r_opnd)
            else
               integer_8_result = integer_8_l_opnd
               do i = 1,integer_8_r_opnd
                  integer_8_result = ISHFT(integer_8_result,-1)
                  integer_8_result = IBSET(integer_8_result,63)
               enddo
            endif
         elseif (operator .eq. Cvrt_Opr) then
            integer_8_result = integer_8_l_opnd  
	 else
            call fold_f_abort(oper_type)
         endif



      else
         call fold_f_abort(oper_type)
      endif



      if ((operator .eq. Eq_Opr)  .or.
     &    (operator .eq. Ne_Opr)  .or.
     &    (operator .eq. Lt_Opr)  .or.
     &    (operator .eq. Le_Opr)  .or.
     &    (operator .eq. Gt_Opr)  .or.
     &    (operator .eq. Ge_Opr)) then
         if (logical_default_result) then
            integer_default_result = 1
         else 
            integer_default_result = 0
         endif
      endif

      result(1) = result_opnd(1)
      result(2) = result_opnd(2)
      result(3) = result_opnd(3)
      result(4) = result_opnd(4)
      result(5) = result_opnd(5)
      result(6) = result_opnd(6)
      result(7) = result_opnd(7)
      result(8) = result_opnd(8)

      END
