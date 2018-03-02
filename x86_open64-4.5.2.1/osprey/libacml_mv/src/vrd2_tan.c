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

#define USE_NAN_WITH_FLAGS
#define USE_VAL_WITH_FLAGS
#define USE_HANDLE_ERROR
#include "../inc/libm_inlines_amd.h"
#undef USE_NAN_WITH_FLAGS
#undef USE_VAL_WITH_FLAGS
#undef USE_HANDLE_ERROR

#ifdef WINDOWS
#include "../inc/libm_errno_amd.h"
#endif


#ifdef WINDOWS
#pragma function(tan)
#endif

double FN_PROTOTYPE_BAS64(tan)(double x);



__m128d FN_PROTOTYPE_BAS64(vrd2_tan)(__m128d x)
{

	union XMMREGTYP_
	{

		__m128d d128;
		double d[2];
	};

	typedef union XMMREGTYP_ XMMREGTYP;


	XMMREGTYP inp128;
	XMMREGTYP res128;

	inp128.d128 = x;

	res128.d[0] = FN_PROTOTYPE_BAS64(tan)(inp128.d[0]);
	res128.d[1] = FN_PROTOTYPE_BAS64(tan)(inp128.d[1]);

	return res128.d128;

}


