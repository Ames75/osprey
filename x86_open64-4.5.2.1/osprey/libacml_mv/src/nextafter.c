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
#endif

#include <float.h>
#include <math.h>
#include <errno.h>
#include <limits.h>

#include "libm_amd.h"
#include "libm_util_amd.h"
#include "libm_special.h"




double FN_PROTOTYPE(nextafter)(double x, double y)
{


    UT64 checkbits,checkbitsy;
    double dy = y;
    checkbits.f64=x;
	checkbitsy.f64 = y;

    /* if x == y return y in the type of x */
    if( x == dy )
    {
        return dy;
    }


    /* check if the number is nan */
    if(((checkbits.u64 & ~SIGNBIT_DP64) >= EXPBITS_DP64 ))
    {
		__amd_handle_error(DOMAIN, ERANGE, "nextafter", x, y , x+x);
        return x+x;
    }


    /* check if y is nan */
    if(((checkbitsy.u64 & ~SIGNBIT_DP64) >= EXPBITS_DP64 ))
    {
		__amd_handle_error(DOMAIN, ERANGE, "nextafter", x, y , x+x);
        return y;
    }

    if( x == 0.0)
    {
        checkbits.u64 = 1;
        if( dy > 0.0 )
             return checkbits.f64;
        else
            return -checkbits.f64;
    }


    /* compute the next heigher or lower value */

    if(((x>0.0) ^ (dy>x)) == 0)
    {
        checkbits.u64++;
    }
    else
    {
        checkbits.u64--;
    }

    /* check if the result is nan or inf */
    if(((checkbits.u64 & ~SIGNBIT_DP64) >= EXPBITS_DP64 ))
    {
		__amd_handle_error(DOMAIN, ERANGE, "nextafter", x, y , checkbits.f64);

    }

    return checkbits.f64;
}
weak_alias (nextafter, FN_PROTOTYPE(nextafter))
