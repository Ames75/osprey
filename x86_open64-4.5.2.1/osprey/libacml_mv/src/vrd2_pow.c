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

/*This is quick prototype for the pow vector variant for the
 *Open64 team. */
#include "../inc/libm_amd.h"

__m128d FN_PROTOTYPE(vrd2_pow)(__m128d x, __m128d y)
{

	union XMMREGTYP_
	{

		__m128d d128;
		double d[2];
	};

	typedef union XMMREGTYP_ XMMREGTYP;


	XMMREGTYP inp_x_128;
	XMMREGTYP inp_y_128;
	XMMREGTYP res128;

	inp_x_128.d128 = x;
	inp_y_128.d128 = y;

	res128.d[0] = FN_PROTOTYPE(pow)(inp_x_128.d[0], inp_y_128.d[0]);
	res128.d[1] = FN_PROTOTYPE(pow)(inp_x_128.d[1], inp_y_128.d[1]);

	return res128.d128;
}


weak_alias (__vrd2_pow, FN_PROTOTYPE(vrd2_pow))
