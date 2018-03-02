
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


/*
** A header file defining the C prototypes for the fast/vector libm functions
*/


#ifdef __cplusplus
extern "C" {
#endif

/* All lines containing _ACML_INT_T or INTEGER64 get             _ACML_INT_T
   filtered out of the distributed copy of acml_mv.h             _ACML_INT_T */
/* _ACML_INT_T The ACML integer type, either 32-bit or 64-bit */
#ifndef _ACML_INT_T
#define _ACML_INT_T
#ifdef INTEGER64
typedef long acml_int_t;                /* _ACML_INT_T */
#else /* ! INTEGER64 */
typedef int acml_int_t;                 /* _ACML_INT_T */
#endif /* ! INTEGER64 */
#endif /* _ACML_INT_T */

/*
** The scalar routines.
*/
double fastexp(double);
double fastlog(double);
double fastlog10(double);
double fastlog2(double);
double fastpow(double,double);
double fastsin(double);
double fastcos(double);
void fastsincos(double , double *, double *);

float fastexpf(float );
float fastlogf(float );
float fastlog10f(float );
float fastlog2f(float );
float fastpowf(float,float);
float fastcosf(float );
float fastsinf(float );
void fastsincosf(float, float *,float *);

/*
** The single vector routines.
*/
__m128d __vrd2_log(__m128d);
__m128d __vrd2_exp(__m128d);
__m128d __vrd2_log10(__m128d);
__m128d __vrd2_log2(__m128d);
__m128d __vrd2_sin(__m128d);
__m128d __vrd2_cos(__m128d);
__m128d __vrd2_pow(__m128d x,__m128d  y);
void __vrd2_sincos(__m128d, __m128d *, __m128d *);

__m128 __vrs4_expf(__m128);
__m128 __vrs4_logf(__m128);
__m128 __vrs4_log10f(__m128);
__m128 __vrs4_log2f(__m128);
__m128 __vrs4_powf(__m128,__m128);
__m128 __vrs4_powxf(__m128 x,float y);
__m128 __vrs4_sinf(__m128);
__m128 __vrs4_cosf(__m128);
void __vrs4_sincosf(__m128, __m128 *, __m128 *);


/*
** The array routines.
*/
void vrda_exp(acml_int_t, double *, double *);
void vrda_log(acml_int_t, double *, double *);
void vrda_log10(acml_int_t, double *, double *);
void vrda_log2(acml_int_t, double *, double *);
void vrda_sin(acml_int_t, double *, double *);
void vrda_cos(acml_int_t, double *, double *);
void vrda_sincos(acml_int_t, double *, double *, double *);

void vrsa_expf(acml_int_t, float *, float *);
void vrsa_logf(acml_int_t, float *, float *);
void vrsa_log10f(acml_int_t, float *, float *);
void vrsa_log2f(acml_int_t, float *, float *);
void vrsa_powf(int n, float *x, float *y, float *z);
void vrsa_powxf(int n, float *x, float y, float *z);
void vrsa_sinf(acml_int_t, float *, float *);
void vrsa_cosf(acml_int_t, float *, float *);
void vrsa_sincosf(acml_int_t, float *, float *, float *);



#ifdef __cplusplus
}
#endif
