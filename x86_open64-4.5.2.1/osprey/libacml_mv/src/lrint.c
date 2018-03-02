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

#include "libm_amd.h"
#include "libm_util_amd.h"
#include "libm_special.h"



long int FN_PROTOTYPE(lrint)(double x)
{

    UT64 checkbits,val_2p52;
    checkbits.f64=x;

    /* Clear the sign bit and check if the value can be rounded */

    if( (checkbits.u64 & 0x7FFFFFFFFFFFFFFF) > 0x4330000000000000)
    {
        /* number cant be rounded raise an exception */
        /* Number exceeds the representable range could be nan or inf also*/
		__amd_handle_error(DOMAIN, EDOM, "lrint", x,0.0 ,(double)x);


		return (long int) x;
    }

    val_2p52.u32[1] = (checkbits.u32[1] & 0x80000000) | 0x43300000;
    val_2p52.u32[0] = 0;

	/* Add and sub 2^52 to round the number according to the current rounding direction */

    return (long int) ((x + val_2p52.f64) - val_2p52.f64);
}
weak_alias (lrint, FN_PROTOTYPE(lrint))
