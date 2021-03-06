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

#ifdef WIN64
#include <fpieee.h>
#else
#include <errno.h>
#endif

#include <math.h>
#include "../inc/libm_amd.h"
#include "../inc/libm_util_amd.h"

#include "../inc/libm_special.h"

double FN_PROTOTYPE(ldexp)(double x, int n)
{
    UT64 val;
    unsigned int sign;
    int exponent;
    val.f64 = x;
    sign = val.u32[1] & 0x80000000;
    val.u32[1] = val.u32[1] & 0x7fffffff; /* remove the sign bit */

    if((val.u32[1] & 0x7ff00000)== 0x7ff00000)/* x= nan or x = +-inf*/
        return x;

    if((val.u64 == 0x0000000000000000) || (n==0))
        return x; /* x= +-0 or n= 0*/

    exponent = val.u32[1] >> 20; /* get the exponent */

    if(exponent == 0)/*x is denormal*/
    {
		val.f64 = val.f64 * VAL_2PMULTIPLIER_DP;/*multiply by 2^53 to bring it to the normal range*/
        exponent = val.u32[1] >> 20; /* get the exponent */
		exponent = exponent + n - MULTIPLIER_DP;
		if(exponent < -MULTIPLIER_DP)/*underflow*/
		{
			val.u32[1] = sign | 0x00000000;
			val.u32[0] = 0x00000000;
			__amd_handle_error(UNDERFLOW, ERANGE, "ldexp", x,(double)n ,val.f64);
			
			return val.f64;
		}
		if(exponent > 2046)/*overflow*/
		{
			val.u32[1] = sign | 0x7ff00000;
			val.u32[0] = 0x00000000;
			__amd_handle_error(OVERFLOW, ERANGE, "ldexp", x,(double)n ,val.f64);
			
			return val.f64;
		}

		exponent += MULTIPLIER_DP;
		val.u32[1] = sign | (exponent << 20) | (val.u32[1] & 0x000fffff);
		val.f64 = val.f64 * VAL_2PMMULTIPLIER_DP;
        return val.f64;
    }

    exponent += n;

    if(exponent < -MULTIPLIER_DP)/*underflow*/
	{
		val.u32[1] = sign | 0x00000000;
		val.u32[0] = 0x00000000;

		__amd_handle_error(UNDERFLOW, ERANGE, "ldexp", x,(double)n ,val.f64);
		

		return val.f64;
	}

    if(exponent < 1)/*x is normal but output is debnormal*/
    {
		exponent += MULTIPLIER_DP;
		val.u32[1] = sign | (exponent << 20) | (val.u32[1] & 0x000fffff);
		val.f64 = val.f64 * VAL_2PMMULTIPLIER_DP;
        return val.f64;
    }

    if(exponent > 2046)/*overflow*/
	{
		val.u32[1] = sign | 0x7ff00000;
		val.u32[0] = 0x00000000;
		__amd_handle_error(OVERFLOW, ERANGE, "ldexp", x,(double)n ,val.f64);
		

		return val.f64;
	}

    val.u32[1] = sign | (exponent << 20) | (val.u32[1] & 0x000fffff);
    return val.f64;
}

weak_alias (ldexp, FN_PROTOTYPE(ldexp))


