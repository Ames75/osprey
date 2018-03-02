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


#define USE_SPLITEXP
#define USE_SCALEDOUBLE_2
#define USE_VAL_WITH_FLAGS
#include "../inc/libm_inlines_amd.h"
#undef USE_SPLITEXP
#undef USE_SCALEDOUBLE_2
#undef USE_VAL_WITH_FLAGS

double FN_PROTOTYPE(tanh)(double x)
{
  /*
    The definition of tanh(x) is sinh(x)/cosh(x), which is also equivalent
    to the following three formulae:
    1.  (exp(x) - exp(-x))/(exp(x) + exp(-x))
    2.  (1 - (2/(exp(2*x) + 1 )))
    3.  (exp(2*x) - 1)/(exp(2*x) + 1)
    but computationally, some formulae are better on some ranges.
  */
  static const double
    thirtytwo_by_log2 = 4.61662413084468283841e+01, /* 0x40471547652b82fe */
    log2_by_32_lead = 2.16608493356034159660e-02, /* 0x3f962e42fe000000 */
    log2_by_32_tail = 5.68948749532545630390e-11, /* 0x3dcf473de6af278e */
    large_threshold = 20.0; /* 0x4034000000000000 */

  unsigned long long ux, aux, xneg;
  double y, z, p, z1, z2;
  int m;

  /* Special cases */

  GET_BITS_DP64(x, ux);
  aux = ux & ~SIGNBIT_DP64;
  if (aux < 0x3e30000000000000) /* |x| small enough that tanh(x) = x */
    {
      if (aux == 0)
        return x; /* with no inexact */
      else
        return val_with_flags(x, AMD_F_INEXACT);
    }
  else if (aux > 0x7ff0000000000000) /* |x| is NaN */
    return x + x;

  xneg = (aux != ux);

  y = x;
  if (xneg) y = -x;

  if (y > large_threshold)
    {
      /* If x is large then exp(-x) is negligible and
         formula 1 reduces to plus or minus 1.0 */
      z = 1.0;
    }
  else if (y <= 1.0)
    {
      double y2;
      y2 = y*y;
      if (y < 0.9)
        {
          /* Use a [3,3] Remez approximation on [0,0.9]. */
          z = y + y*y2*
            (-0.274030424656179760118928e0 +
             (-0.176016349003044679402273e-1 +
              (-0.200047621071909498730453e-3 -
               0.142077926378834722618091e-7*y2)*y2)*y2)/
            (0.822091273968539282568011e0 +
             (0.381641414288328849317962e0 +
              (0.201562166026937652780575e-1 +
               0.2091140262529164482568557e-3*y2)*y2)*y2);
        }
      else
        {
          /* Use a [3,3] Remez approximation on [0.9,1]. */
          z = y + y*y2*
            (-0.227793870659088295252442e0 +
             (-0.146173047288731678404066e-1 +
              (-0.165597043903549960486816e-3 -
               0.115475878996143396378318e-7*y2)*y2)*y2)/
            (0.683381611977295894959554e0 +
             (0.317204558977294374244770e0 +
              (0.167358775461896562588695e-1 +
               0.173076050126225961768710e-3*y2)*y2)*y2);
        }
    }
  else
    {
      /* Compute p = exp(2*y) + 1. The code is basically inlined
         from exp_amd. */

      splitexp(2*y, 1.0, thirtytwo_by_log2, log2_by_32_lead,
	       log2_by_32_tail, &m, &z1, &z2);
      p = scaleDouble_2(z1 + z2, m) + 1.0;

      /* Now reconstruct tanh from p. */
      z = (1.0 - 2.0/p);
    }

  if (xneg) z = - z;
  return z;
}

weak_alias (tanh, FN_PROTOTYPE(tanh))
