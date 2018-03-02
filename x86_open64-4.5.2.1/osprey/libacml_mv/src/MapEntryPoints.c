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


#include "../inc/libm_amd_paths.h"
#ifdef _MSC_VER
#include <intrin.h>
#define CPUID __cpuid
#define CCALL __cdecl
#pragma section(".CRT$XCU",read)
#define INITIALIZER(f)  static void __cdecl f(void); __declspec(allocate(".CRT$XCU")) void (__cdecl*f##_)(void) = f; static void __cdecl f(void)
#else
static void cpuid(int *out, int in) __attribute__((noinline));
static void cpuid(int *out, int in)
{
    __asm__ __volatile__("    pushq %%rbx;          \
                          xorq %%rax, %%rax;        \
                          movl %%esi, %%eax;        \
                          cpuid;                    \
                          movl %%eax, 0x0(%%rdi);   \
                          movl %%ebx, 0x4(%%rdi);   \
                          movl %%ecx, 0x8(%%rdi);   \
                          movl %%edx, 0xc(%%rdi);   \
                          popq %%rbx;"              \
                          : : "D" (out), "S" (in)   \
                          : "%rax", "%rcx", "%rdx" );
}
#define CPUID cpuid
#define CCALL
#define INITIALIZER(f) static void f(void) __attribute__((constructor)); static void f(void)
#endif
#ifdef __cplusplus
extern "C"
{
#endif
    void    (*g_amd_libm_ep_vrda_exp)(int, double*, double*);
    void    (*g_amd_libm_ep_vrda_exp2)(int, double*, double*);
    void    (*g_amd_libm_ep_vrda_exp10)(int, double*, double*);
    void    (*g_amd_libm_ep_vrda_expm1)(int, double*, double*);
    void    (*g_amd_libm_ep_vrsa_expf)(int, float*, float*);
    void    (*g_amd_libm_ep_vrsa_exp2f)(int, float*, float*);
    void    (*g_amd_libm_ep_vrsa_exp10f)(int, float*, float*);
    void    (*g_amd_libm_ep_vrsa_expm1f)(int, float*, float*);

    double  (*g_amd_libm_ep_fma)(double,double,double);
    double  (*g_amd_libm_ep_exp)(double);
    double  (*g_amd_libm_ep_exp2)(double);
    double  (*g_amd_libm_ep_exp10)(double);
    double  (*g_amd_libm_ep_expm1)(double);
    double  (*g_amd_libm_ep_log)(double);
    double  (*g_amd_libm_ep_log2)(double);
    double  (*g_amd_libm_ep_log10)(double);
    double  (*g_amd_libm_ep_log1p)(double);
    double  (*g_amd_libm_ep_cbrt)(double );
    double  (*g_amd_libm_ep_cos)(double);
    double  (*g_amd_libm_ep_sin)(double);
    double  (*g_amd_libm_ep_tan)(double);

    float   (*g_amd_libm_ep_fmaf)(float,float,float);
    float   (*g_amd_libm_ep_expf)(float);
    float   (*g_amd_libm_ep_exp2f)(float);
    float   (*g_amd_libm_ep_exp10f)(float);
    float   (*g_amd_libm_ep_expm1f)(float);
    float   (*g_amd_libm_ep_logf)(float);
    float   (*g_amd_libm_ep_log2f)(float);
    float   (*g_amd_libm_ep_log10f)(float);
    float   (*g_amd_libm_ep_log1pf)(float);
    float   (*g_amd_libm_ep_cosf)(float);
    float   (*g_amd_libm_ep_sinf)(float);
    float   (*g_amd_libm_ep_tanf)(float);
    float   (*g_amd_libm_ep_cbrtf)(float);

    __m128  (*g_amd_libm_ep_vrs4_expf)(__m128);
    __m128  (*g_amd_libm_ep_vrs4_exp2f)(__m128);
    __m128  (*g_amd_libm_ep_vrs4_exp10f)(__m128);
    __m128  (*g_amd_libm_ep_vrs4_expm1f)(__m128);
    __m128  (*g_amd_libm_ep_vrs4_logf)(__m128);
    __m128  (*g_amd_libm_ep_vrs4_log2f)(__m128);
    __m128  (*g_amd_libm_ep_vrs4_log10f)(__m128);
    __m128  (*g_amd_libm_ep_vrs4_log1pf)(__m128);
    __m128  (*g_amd_libm_ep_vrs4_cosf)(__m128);
    __m128  (*g_amd_libm_ep_vrs4_sinf)(__m128);
 	__m128  (*g_amd_libm_ep_vrs4_tanf)(__m128);
    __m128  (*g_amd_libm_ep_vrs4_cbrtf)(__m128);

    __m128d (*g_amd_libm_ep_vrd2_exp)(__m128d);
    __m128d (*g_amd_libm_ep_vrd2_exp2)(__m128d);
    __m128d (*g_amd_libm_ep_vrd2_exp10)(__m128d);
    __m128d (*g_amd_libm_ep_vrd2_expm1)(__m128d);
    __m128d (*g_amd_libm_ep_vrd2_log)(__m128d);
    __m128d (*g_amd_libm_ep_vrd2_log2)(__m128d);
    __m128d (*g_amd_libm_ep_vrd2_log10)(__m128d);
    __m128d (*g_amd_libm_ep_vrd2_log1p)(__m128d);
    __m128d (*g_amd_libm_ep_vrd2_cbrt)(__m128d);
    __m128d (*g_amd_libm_ep_vrd2_cos)(__m128d);
    __m128d (*g_amd_libm_ep_vrd2_sin)(__m128d);
    __m128d (*g_amd_libm_ep_vrd2_tan)(__m128d);

#ifdef __cplusplus
}
#endif
static int cpuid_bdozr(void)
{
        int avx = 0, fma4 = 0;
        int info[4];
        CPUID(info, 0x1);
        avx = (info[2] & (0x1 << 28)) ? 1 : 0;
        CPUID(info, 0x80000001);
        fma4 = (info[2] & (1 << 16)) ? 1 : 0;
        return (avx & fma4);
}
INITIALIZER(InitMapEntryPoints)
{
    int bdozr = cpuid_bdozr();
    g_amd_libm_ep_cbrt       = bdozr ? FN_PROTOTYPE_BDOZR(cbrt)       : FN_PROTOTYPE_BAS64(cbrt);
    g_amd_libm_ep_cbrtf      = bdozr ? FN_PROTOTYPE_BDOZR(cbrtf)      : FN_PROTOTYPE_BAS64(cbrtf);
	g_amd_libm_ep_sin        = bdozr ? FN_PROTOTYPE_BDOZR(sin)        : FN_PROTOTYPE_BAS64(sin);
    g_amd_libm_ep_sinf       = bdozr ? FN_PROTOTYPE_BDOZR(sinf)       : FN_PROTOTYPE_BAS64(sinf);
    g_amd_libm_ep_cos        = bdozr ? FN_PROTOTYPE_BDOZR(cos)        : FN_PROTOTYPE_BAS64(cos) ;
    g_amd_libm_ep_cosf       = bdozr ? FN_PROTOTYPE_BDOZR(cosf)       : FN_PROTOTYPE_BAS64(cosf);
    g_amd_libm_ep_tan        = bdozr ? FN_PROTOTYPE_BDOZR(tan)        : FN_PROTOTYPE_BAS64(tan);
    g_amd_libm_ep_tanf       = bdozr ? FN_PROTOTYPE_BDOZR(tanf)       : FN_PROTOTYPE_BAS64(tanf);
    g_amd_libm_ep_vrd2_cbrt  = bdozr ? FN_PROTOTYPE_BDOZR(vrd2_cbrt)  : FN_PROTOTYPE_BAS64(vrd2_cbrt);
    g_amd_libm_ep_vrs4_cbrtf = bdozr ? FN_PROTOTYPE_BDOZR(vrs4_cbrtf) : FN_PROTOTYPE_BAS64(vrs4_cbrtf);
	g_amd_libm_ep_vrd2_cos   = bdozr ? FN_PROTOTYPE_BDOZR(vrd2_cos)   : FN_PROTOTYPE_BAS64(vrd2_cos);
	g_amd_libm_ep_vrs4_cosf  = bdozr ? FN_PROTOTYPE_BDOZR(vrs4_cosf)  : FN_PROTOTYPE_BAS64(vrs4_cosf);
	g_amd_libm_ep_vrd2_sin   = bdozr ? FN_PROTOTYPE_BDOZR(vrd2_sin)   : FN_PROTOTYPE_BAS64(vrd2_sin);
    g_amd_libm_ep_vrs4_sinf  = bdozr ? FN_PROTOTYPE_BDOZR(vrs4_sinf)  : FN_PROTOTYPE_BAS64(vrs4_sinf);
	g_amd_libm_ep_vrd2_tan   = bdozr ? FN_PROTOTYPE_BDOZR(vrd2_tan)   : FN_PROTOTYPE_BAS64(vrd2_tan);
    g_amd_libm_ep_vrs4_tanf  = bdozr ? FN_PROTOTYPE_BDOZR(vrs4_tanf)  : FN_PROTOTYPE_BAS64(vrs4_tanf);
    g_amd_libm_ep_vrd2_log   = bdozr ? FN_PROTOTYPE_BDOZR(vrd2_log)   : FN_PROTOTYPE_BAS64(vrd2_log);
    g_amd_libm_ep_vrd2_log2  = bdozr ? FN_PROTOTYPE_BDOZR(vrd2_log2)  : FN_PROTOTYPE_BAS64(vrd2_log2);
    g_amd_libm_ep_vrd2_log10 = bdozr ? FN_PROTOTYPE_BDOZR(vrd2_log10) : FN_PROTOTYPE_BAS64(vrd2_log10);
    g_amd_libm_ep_vrd2_log1p = bdozr ? FN_PROTOTYPE_BDOZR(vrd2_log1p) : FN_PROTOTYPE_BAS64(vrd2_log1p);
    g_amd_libm_ep_vrs4_logf  = bdozr ? FN_PROTOTYPE_BDOZR(vrs4_logf)  : FN_PROTOTYPE_BAS64(vrs4_logf);
    g_amd_libm_ep_vrs4_log2f = bdozr ? FN_PROTOTYPE_BDOZR(vrs4_log2f) : FN_PROTOTYPE_BAS64(vrs4_log2f);
    g_amd_libm_ep_vrs4_log10f= bdozr ? FN_PROTOTYPE_BDOZR(vrs4_log10f): FN_PROTOTYPE_BAS64(vrs4_log10f);
    g_amd_libm_ep_vrs4_log1pf= bdozr ? FN_PROTOTYPE_BDOZR(vrs4_log1pf): FN_PROTOTYPE_BAS64(vrs4_log1pf);
    g_amd_libm_ep_logf       = bdozr ? FN_PROTOTYPE_BDOZR(logf)       : FN_PROTOTYPE_BAS64(logf);
    g_amd_libm_ep_log2f      = bdozr ? FN_PROTOTYPE_BDOZR(log2f)      : FN_PROTOTYPE_BAS64(log2f);
    g_amd_libm_ep_log10f     = bdozr ? FN_PROTOTYPE_BDOZR(log10f)     : FN_PROTOTYPE_BAS64(log10f);
    g_amd_libm_ep_log1pf     = bdozr ? FN_PROTOTYPE_BDOZR(log1pf)     : FN_PROTOTYPE_BAS64(log1pf);
    g_amd_libm_ep_log        = bdozr ? FN_PROTOTYPE_BDOZR(log)        : FN_PROTOTYPE_BAS64(log);
    g_amd_libm_ep_log2       = bdozr ? FN_PROTOTYPE_BDOZR(log2)       : FN_PROTOTYPE_BAS64(log2);
    g_amd_libm_ep_log10      = bdozr ? FN_PROTOTYPE_BDOZR(log10)      : FN_PROTOTYPE_BAS64(log10);
    g_amd_libm_ep_log1p      = bdozr ? FN_PROTOTYPE_BDOZR(log1p)      : FN_PROTOTYPE_BAS64(log1p);
    g_amd_libm_ep_exp        = bdozr ? FN_PROTOTYPE_BDOZR(exp)        : FN_PROTOTYPE_BAS64(exp);
    g_amd_libm_ep_exp2       = bdozr ? FN_PROTOTYPE_BDOZR(exp2)       : FN_PROTOTYPE_BAS64(exp2);
    g_amd_libm_ep_exp10      = bdozr ? FN_PROTOTYPE_BDOZR(exp10)      : FN_PROTOTYPE_BAS64(exp10);
    g_amd_libm_ep_expm1      = bdozr ? FN_PROTOTYPE_BDOZR(expm1)      : FN_PROTOTYPE_BAS64(expm1);
    g_amd_libm_ep_expf       = bdozr ? FN_PROTOTYPE_BDOZR(expf)       : FN_PROTOTYPE_BAS64(expf);
    g_amd_libm_ep_exp2f		 = bdozr ? FN_PROTOTYPE_BDOZR(exp2f)      : FN_PROTOTYPE_BAS64(exp2f);
    g_amd_libm_ep_exp10f	 = bdozr ? FN_PROTOTYPE_BDOZR(exp10f)     : FN_PROTOTYPE_BAS64(exp10f);
    g_amd_libm_ep_expm1f	 = bdozr ? FN_PROTOTYPE_BDOZR(expm1f)     : FN_PROTOTYPE_BAS64(expm1f);
    g_amd_libm_ep_vrs4_expf  = bdozr ? FN_PROTOTYPE_BDOZR(vrs4_expf)  : FN_PROTOTYPE_BAS64(vrs4_expf);
    g_amd_libm_ep_vrs4_exp2f = bdozr ? FN_PROTOTYPE_BDOZR(vrs4_exp2f) : FN_PROTOTYPE_BAS64(vrs4_exp2f);
    g_amd_libm_ep_vrs4_exp10f= bdozr ? FN_PROTOTYPE_BDOZR(vrs4_exp10f): FN_PROTOTYPE_BAS64(vrs4_exp10f);
    g_amd_libm_ep_vrs4_expm1f= bdozr ? FN_PROTOTYPE_BDOZR(vrs4_expm1f): FN_PROTOTYPE_BAS64(vrs4_expm1f);
    g_amd_libm_ep_vrd2_exp   = bdozr ? FN_PROTOTYPE_BDOZR(vrd2_exp)   : FN_PROTOTYPE_BAS64(vrd2_exp);
    g_amd_libm_ep_vrd2_exp2	 = bdozr ? FN_PROTOTYPE_BDOZR(vrd2_exp2)  : FN_PROTOTYPE_BAS64(vrd2_exp2);
    g_amd_libm_ep_vrd2_exp10 = bdozr ? FN_PROTOTYPE_BDOZR(vrd2_exp10) : FN_PROTOTYPE_BAS64(vrd2_exp10);
    g_amd_libm_ep_vrd2_expm1 = bdozr ? FN_PROTOTYPE_BDOZR(vrd2_expm1) : FN_PROTOTYPE_BAS64(vrd2_expm1);
    g_amd_libm_ep_vrda_exp   = bdozr ? FN_PROTOTYPE_BDOZR(vrda_exp)   : FN_PROTOTYPE_BAS64(vrda_exp);
    g_amd_libm_ep_vrda_exp2	 = bdozr ? FN_PROTOTYPE_BDOZR(vrda_exp2)  : FN_PROTOTYPE_BAS64(vrda_exp2);
    g_amd_libm_ep_vrda_exp10 = bdozr ? FN_PROTOTYPE_BDOZR(vrda_exp10) : FN_PROTOTYPE_BAS64(vrda_exp10);
    g_amd_libm_ep_vrda_expm1 = bdozr ? FN_PROTOTYPE_BDOZR(vrda_expm1) : FN_PROTOTYPE_BAS64(vrda_expm1);
    g_amd_libm_ep_vrsa_expf  = bdozr ? FN_PROTOTYPE_BDOZR(vrsa_expf)  : FN_PROTOTYPE_BAS64(vrsa_expf);
    g_amd_libm_ep_vrsa_exp2f = bdozr ? FN_PROTOTYPE_BDOZR(vrsa_exp2f) : FN_PROTOTYPE_BAS64(vrsa_exp2f);
    g_amd_libm_ep_vrsa_exp10f= bdozr ? FN_PROTOTYPE_BDOZR(vrsa_exp10f): FN_PROTOTYPE_BAS64(vrsa_exp10f);
    g_amd_libm_ep_vrsa_expm1f= bdozr ? FN_PROTOTYPE_BDOZR(vrsa_expm1f): FN_PROTOTYPE_BAS64(vrsa_expm1f);
    g_amd_libm_ep_fmaf       = bdozr ? FN_PROTOTYPE_BDOZR(fmaf)       : FN_PROTOTYPE_BAS64(fmaf);
    g_amd_libm_ep_fma        = bdozr ? FN_PROTOTYPE_BDOZR(fma)        : FN_PROTOTYPE_BAS64(fma);

}
