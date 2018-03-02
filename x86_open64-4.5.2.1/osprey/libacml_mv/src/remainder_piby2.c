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

#include "libm_amd.h"

void __amd_remainder_piby2(double x, double *r, double *rr, int *region);

void __amd_remainder_2dfpiby2(__m128d x, __m128d *r, __m128d *rr, __m128i *region)
{
	union XMMREGTYP_
	{

		__m128d d128;
		__m128i i128;
		double d[2];
		unsigned long long i[2];
	};

	typedef union XMMREGTYP_ XMMREGTYP;


	XMMREGTYP inpx;
	XMMREGTYP resr,resrr,resregion;
	int reg,reg1;
	double irr,irr1,ir,ir1;



	inpx.d128 = x;

     __amd_remainder_piby2(inpx.d[0],&ir,&irr,&reg);
	 __amd_remainder_piby2(inpx.d[1],&ir1,&irr1,&reg1);

	 resregion.i[0] = reg;
	 resregion.i[1] = reg1;

	 resrr.d[0] = irr;
	 resrr.d[1] = irr1;

	 resr.d[0] = ir;
	 resr.d[1] = ir1;



	*r = resr.d128;
	*rr = resrr.d128;
	*region = resregion.i128;

}