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

void __amd_remainder_piby2d2f(unsigned long long ux, double *r, int *region);
void __amd_remainder_piby2d2f_4f(unsigned long long  *x, double *r, unsigned long long *region)
{


	int region1[4];
     __amd_remainder_piby2d2f(x[0],r,region1);
	 __amd_remainder_piby2d2f(x[1],&r[1],&region1[1]);
     __amd_remainder_piby2d2f(x[2],&r[2],&region1[2]);
	 __amd_remainder_piby2d2f(x[3],&r[3],&region1[3]);

	 region[0] = region1[0];
	 region[1] = region1[1];
	 region[2] = region1[2];
	 region[3] = region1[3];
}