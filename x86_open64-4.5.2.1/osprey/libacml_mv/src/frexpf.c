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



float FN_PROTOTYPE(frexpf)(float value, int *exp)
{
    UT32 val;
    unsigned int sign;
    int exponent;
    val.f32 = value;
    sign = val.u32 & SIGNBIT_SP32;
    val.u32 = val.u32 & ~SIGNBIT_SP32; /* remove the sign bit */
    *exp = 0;
    if((val.f32 == 0.0) || ((val.u32 & 0x7f800000)== 0x7f800000)) 
        return value; /* value= +-0 or value= nan or value = +-inf return value */

    exponent = val.u32 >> 23; /* get the exponent */

	if(exponent == 0)/*x is denormal*/
	{
		val.f32 = val.f32 * VAL_2PMULTIPLIER_SP;/*multiply by 2^24 to bring it to the normal range*/
		exponent = (val.u32 >> 23); /* get the exponent */
		exponent = exponent - MULTIPLIER_SP;
	}

    exponent -= 126; /* remove bias(127)-1 */
    *exp = exponent; /* set the integral power of two */
    val.u32 = sign | 0x3f000000 | (val.u32 & 0x007fffff);/* make the fractional part(divide by 2) */                                              
    return val.f32;
}
weak_alias (frexpf, FN_PROTOTYPE(frexpf))

