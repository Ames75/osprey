
/*
*  (C) 2008-2009 Advanced Micro Devices, Inc. All Rights Reserved.
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


#ifndef LIBM_AMD_PATH_H_INCLUDED
#define LIBM_AMD_PATH_H_INCLUDED 1

#include "fn_macros.h"
#ifdef WIN64
#include <intrin.h>
#else

#if (__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 5))
#include <x86intrin.h>
#else
#include <emmintrin.h>
#endif

#endif

#ifdef __cplusplus
extern "C" {
#endif


 double FN_PROTOTYPE_BAS64( fma)(double x, double y, double z);
 double FN_PROTOTYPE_BDOZR( fma)(double x, double y, double z);
 float FN_PROTOTYPE_BAS64(fmaf)(float x, float y, float z);
 float FN_PROTOTYPE_BDOZR(fmaf)(float x, float y, float z);

 double FN_PROTOTYPE_BAS64(exp)(double x);
 double FN_PROTOTYPE_BDOZR(exp)(double x);
 double FN_PROTOTYPE_BAS64(exp2)(double x);
 double FN_PROTOTYPE_BDOZR(exp2)(double x);
 double FN_PROTOTYPE_BAS64(exp10)(double x);
 double FN_PROTOTYPE_BDOZR(exp10)(double x);
 double FN_PROTOTYPE_BAS64(expm1)(double x);
 double FN_PROTOTYPE_BDOZR(expm1)(double x);

 float FN_PROTOTYPE_BAS64(expf)(float x);
 float FN_PROTOTYPE_BDOZR(expf)(float x);
 float FN_PROTOTYPE_BAS64(exp2f)(float x);
 float FN_PROTOTYPE_BDOZR(exp2f)(float x);
 float FN_PROTOTYPE_BAS64(exp10f)(float x);
 float FN_PROTOTYPE_BDOZR(exp10f)(float x);
 float FN_PROTOTYPE_BAS64(expm1f)(float x);
 float FN_PROTOTYPE_BDOZR(expm1f)(float x);

 __m128 FN_PROTOTYPE_BAS64(vrs4_expf)(__m128 x);
 __m128 FN_PROTOTYPE_BDOZR(vrs4_expf)(__m128 x);
 __m128 FN_PROTOTYPE_BAS64(vrs4_exp2f)(__m128 x);
 __m128 FN_PROTOTYPE_BDOZR(vrs4_exp2f)(__m128 x);
 __m128 FN_PROTOTYPE_BAS64(vrs4_exp10f)(__m128 x);
 __m128 FN_PROTOTYPE_BDOZR(vrs4_exp10f)(__m128 x);
 __m128 FN_PROTOTYPE_BAS64(vrs4_expm1f)(__m128 x);
 __m128 FN_PROTOTYPE_BDOZR(vrs4_expm1f)(__m128 x);

 __m128d FN_PROTOTYPE_BAS64(vrd2_exp)(__m128d x);
 __m128d FN_PROTOTYPE_BDOZR(vrd2_exp)(__m128d x);
 __m128d FN_PROTOTYPE_BAS64(vrd2_exp2)(__m128d x);
 __m128d FN_PROTOTYPE_BDOZR(vrd2_exp2)(__m128d x);
 __m128d FN_PROTOTYPE_BAS64(vrd2_exp10)(__m128d x);
 __m128d FN_PROTOTYPE_BDOZR(vrd2_exp10)(__m128d x);
 __m128d FN_PROTOTYPE_BAS64(vrd2_expm1)(__m128d x);
 __m128d FN_PROTOTYPE_BDOZR(vrd2_expm1)(__m128d x);

 void FN_PROTOTYPE_BAS64(vrda_exp)(int len, double* x, double* y);
 void FN_PROTOTYPE_BDOZR(vrda_exp)(int len, double* x, double* y);
 void FN_PROTOTYPE_BAS64(vrda_exp2)(int len, double* x, double* y);
 void FN_PROTOTYPE_BDOZR(vrda_exp2)(int len, double* x, double* y);
 void FN_PROTOTYPE_BAS64(vrda_exp10)(int len, double* x, double* y);
 void FN_PROTOTYPE_BDOZR(vrda_exp10)(int len, double* x, double* y);
 void FN_PROTOTYPE_BAS64(vrda_expm1)(int len, double* x, double* y);
 void FN_PROTOTYPE_BDOZR(vrda_expm1)(int len, double* x, double* y);

 void FN_PROTOTYPE_BAS64(vrsa_expf)(int len, float* x, float* y);
 void FN_PROTOTYPE_BDOZR(vrsa_expf)(int len, float* x, float* y);
 void FN_PROTOTYPE_BAS64(vrsa_exp2f)(int len, float* x, float* y);
 void FN_PROTOTYPE_BDOZR(vrsa_exp2f)(int len, float* x, float* y);
 void FN_PROTOTYPE_BAS64(vrsa_exp10f)(int len, float* x, float* y);
 void FN_PROTOTYPE_BDOZR(vrsa_exp10f)(int len, float* x, float* y);
 void FN_PROTOTYPE_BAS64(vrsa_expm1f)(int len, float* x, float* y);
 void FN_PROTOTYPE_BDOZR(vrsa_expm1f)(int len, float* x, float* y);

 double FN_PROTOTYPE_BAS64(cbrt)(double x);
 double FN_PROTOTYPE_BDOZR(cbrt)(double x);
 float FN_PROTOTYPE_BAS64(cbrtf)(float x);
 float FN_PROTOTYPE_BDOZR(cbrtf)(float x);
 __m128d FN_PROTOTYPE_BDOZR(vrd2_cbrt)(__m128d z);
 __m128d FN_PROTOTYPE_BAS64(vrd2_cbrt)(__m128d x);
 __m128 FN_PROTOTYPE_BDOZR(vrs4_cbrtf)(__m128  z);
 __m128 FN_PROTOTYPE_BAS64(vrs4_cbrtf)(__m128  x);


 __m128d FN_PROTOTYPE_BDOZR(vrd2_log)(__m128d  x);
 __m128d FN_PROTOTYPE_BAS64(vrd2_log)(__m128d x);
 __m128d FN_PROTOTYPE_BDOZR(vrd2_log2)(__m128d x);
 __m128d FN_PROTOTYPE_BAS64(vrd2_log2)(__m128d x);
 __m128d FN_PROTOTYPE_BDOZR(vrd2_log10)(__m128d x);
 __m128d FN_PROTOTYPE_BAS64(vrd2_log10)(__m128d x);
 __m128d FN_PROTOTYPE_BDOZR(vrd2_log1p)(__m128d x);
 __m128d FN_PROTOTYPE_BAS64(vrd2_log1p)(__m128d x);
 __m128 FN_PROTOTYPE_BDOZR(vrs4_logf)(__m128 z);
 __m128 FN_PROTOTYPE_BAS64(vrs4_logf)(__m128 x);
 __m128 FN_PROTOTYPE_BDOZR(vrs4_log2f)(__m128 z);
 __m128 FN_PROTOTYPE_BAS64(vrs4_log2f)(__m128 x);
 __m128 FN_PROTOTYPE_BDOZR(vrs4_log10f)(__m128 z);
 __m128 FN_PROTOTYPE_BAS64(vrs4_log10f)(__m128 x);
 __m128 FN_PROTOTYPE_BDOZR(vrs4_log1pf)(__m128 z);
 __m128 FN_PROTOTYPE_BAS64(vrs4_log1pf)(__m128 x);
 float FN_PROTOTYPE_BAS64(logf)(float x);
 float FN_PROTOTYPE_BDOZR(logf)(float x);
 float FN_PROTOTYPE_BAS64(log2f)(float x);
 float FN_PROTOTYPE_BDOZR(log2f)(float x);
 float FN_PROTOTYPE_BAS64(log10f)(float x);
 float FN_PROTOTYPE_BDOZR(log10f)(float x);
 float FN_PROTOTYPE_BAS64(log1pf)(float x);
 float FN_PROTOTYPE_BDOZR(log1pf)(float x);
 double FN_PROTOTYPE_BAS64(log)(double x);
 double FN_PROTOTYPE_BDOZR(log)(double x);
 double FN_PROTOTYPE_BAS64(log2)(double x);
 double FN_PROTOTYPE_BDOZR(log2)(double x);
 double FN_PROTOTYPE_BAS64(log10)(double x);
 double FN_PROTOTYPE_BDOZR(log10)(double x);
 double FN_PROTOTYPE_BAS64(log1p)(double x);
 double FN_PROTOTYPE_BDOZR(log1p)(double x);



 double FN_PROTOTYPE_BAS64(cos)(double x);
 double FN_PROTOTYPE_BDOZR(cos)(double x);
 double FN_PROTOTYPE_BAS64(sin)(double x);
 double FN_PROTOTYPE_BDOZR(sin)(double x);
 double FN_PROTOTYPE_BAS64(tan)(double x);
 double FN_PROTOTYPE_BDOZR(tan)(double x);


 __m128d FN_PROTOTYPE_BAS64(vrd2_cos)(__m128d x);
 __m128d FN_PROTOTYPE_BDOZR(vrd2_cos)(__m128d x);
 __m128d FN_PROTOTYPE_BAS64(vrd2_sin)(__m128d x);
 __m128d FN_PROTOTYPE_BDOZR(vrd2_sin)(__m128d x);
 __m128d FN_PROTOTYPE_BAS64(vrd2_tan)(__m128d x);
 __m128d FN_PROTOTYPE_BDOZR(vrd2_tan)(__m128d x);



 float FN_PROTOTYPE_BAS64(cosf)(float x);
 float FN_PROTOTYPE_BDOZR(cosf)(float x);
 float FN_PROTOTYPE_BAS64(sinf)(float x);
 float FN_PROTOTYPE_BDOZR(sinf)(float x);
 float FN_PROTOTYPE_BAS64(tanf)(float x);
 float FN_PROTOTYPE_BDOZR(tanf)(float x);


 __m128 FN_PROTOTYPE_BAS64(vrs4_cosf)(__m128 x);
 __m128 FN_PROTOTYPE_BDOZR(vrs4_cosf)(__m128 x);
 __m128 FN_PROTOTYPE_BAS64(vrs4_sinf)(__m128 x);
 __m128 FN_PROTOTYPE_BDOZR(vrs4_sinf)(__m128 x);
 __m128 FN_PROTOTYPE_BAS64(vrs4_tanf)(__m128 x);
 __m128 FN_PROTOTYPE_BDOZR(vrs4_tanf)(__m128 x);



#ifdef __cplusplus
}
#endif

#endif /* LIBM_AMD_PATH_H_INCLUDED */
