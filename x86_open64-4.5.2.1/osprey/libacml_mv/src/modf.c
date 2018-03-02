/*
*  (C) 2008-2011 Advanced Micro Devices, Inc. All Rights Reserved.
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

#include "../inc/libm_amd.h"
#include "../inc/libm_util_amd.h"

double FN_PROTOTYPE(modf)(double x, double *iptr)
{
  /* modf splits the argument x into integer and fraction parts,
     each with the same sign as x. */


  long long xexp;
  unsigned long long ux, ax, mask;

  GET_BITS_DP64(x, ux);
  ax = ux & (~SIGNBIT_DP64);

  if (ax >= 0x4340000000000000)
    {
      /* abs(x) is either NaN, infinity, or >= 2^53 */
      if (ax > 0x7ff0000000000000)
        {
          /* x is NaN */
          *iptr = x;
          return x + x; /* Raise invalid if it is a signalling NaN */
        }
      else
        {
          /* x is infinity or large. Return zero with the sign of x */
          *iptr = x;
          PUT_BITS_DP64(ux & SIGNBIT_DP64, x);
          return x;
        }
    }
  else if (ax < 0x3ff0000000000000)
    {
      /* abs(x) < 1.0. Set iptr to zero with the sign of x
         and return x. */
      PUT_BITS_DP64(ux & SIGNBIT_DP64, *iptr);
      return x;
    }
  else
    {
      double r;
      unsigned long long ur;
      xexp = ((ux & EXPBITS_DP64) >> EXPSHIFTBITS_DP64) - EXPBIAS_DP64;
      /* Mask out the bits of x that we don't want */
      mask = 1;
      mask = (mask << (EXPSHIFTBITS_DP64 - xexp)) - 1;
      PUT_BITS_DP64(ux & ~mask, *iptr);
      r = x - *iptr;
      GET_BITS_DP64(r, ur);
      PUT_BITS_DP64(((ux & SIGNBIT_DP64)|ur), r);
      return r;
    }

}

weak_alias (modf, FN_PROTOTYPE(modf))
