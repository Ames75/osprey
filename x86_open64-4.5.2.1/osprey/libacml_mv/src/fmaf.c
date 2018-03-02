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
#include "../inc/libm_amd_paths.h"
#include "../inc/libm_util_amd.h"

float FN_PROTOTYPE_BAS64(fmaf)(float a, float b, float c)
{
    double dc, dp, dr;
    long long ir;
    UT32 aa, bb, cc;
    union { double d; long long l; } dru, iru;

    aa.f32 = a;
    bb.f32 = b;
    cc.f32 = c;
    
    dp = (double)a * (double)b;
    dc = c;
    dr = dp + dc;
    dru.d = dr;
    ir = dru.l;

    if ((ir & 0x000000001fffffffL) == 0x0000000010000000L) {
        int ec = ((cc.u32 >> 23) & 0xff) - 127;
        int ep = ((aa.u32 >> 23) & 0xff) + ((bb.u32 >> 23) & 0xff) - 2*127;
        long long jr, ir52 = (ir & 0x7ff0000000000000L) - 0x0340000000000000L;

    jr = ir52 | (long long)(dr - dc > dp) << 63;
    ir = (ec - ep > 53 - 48) & (dr - dc != dp) ? jr : 0L;

        jr = ir52 | (long long)(dr - dp > dc) << 63;
    ir = (ep - ec > 53 - 24) & (dr - dp != dc) ? jr : ir;

    iru.l = ir;
    dr += iru.d;
    }

    return (float)dr;
}
weak_alias (fmaf, FN_PROTOTYPE_BAS64(fmaf))

