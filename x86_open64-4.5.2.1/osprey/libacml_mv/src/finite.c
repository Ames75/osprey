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

/* Returns 0 if x is infinite or NaN, otherwise returns 1 */

#ifdef WINDOWS
int FN_PROTOTYPE(finite)(double x)
#else
int FN_PROTOTYPE(finite)(double x)
#endif
{

#ifdef WINDOWS

  unsigned long long ux;
  GET_BITS_DP64(x, ux);
  return (int)(((ux & ~SIGNBIT_DP64) - PINFBITPATT_DP64) >> 63);

#else

  /* This works on Hammer with gcc */
  unsigned long ux =0x7ff0000000000000 ;
  double temp;
  PUT_BITS_DP64(ux, temp);

 // double temp = 1.0e444; /* = infinity = 0x7ff0000000000000 */
  volatile int retval;
  retval = 0;
  asm volatile ("andpd	%1, %2; \
		 comisd	%1, %2;\
		 setnz	%0;" : "=g" (retval): "x"(temp), "x"(x));
  return retval;

#endif
}
weak_alias (finite, FN_PROTOTYPE(finite))

