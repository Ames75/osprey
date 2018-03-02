/* Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007
   Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   GCC is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING.  If not, write to
   the Free Software Foundation, 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, if you include this header file into source
   files compiled by GCC, this header file does not by itself cause
   the resulting executable to be covered by the GNU General Public
   License.  This exception does not however invalidate any other
   reasons why the executable file might be covered by the GNU General
   Public License.  */

/* Implemented from the specification included in the Intel C++ Compiler
   User Guide and Reference, version 9.0.  */
#ifndef _IMMINTRIN_HEADER
#define _IMMINTRIN_HEADER
typedef double __v4df __attribute__ ((__vector_size__ (32)));
typedef float __v8sf __attribute__ ((__vector_size__ (32)));
typedef long long __v4di __attribute__ ((__vector_size__ (32)));
typedef int __v8si __attribute__ ((__vector_size__ (32)));
typedef short __v16hi __attribute__ ((__vector_size__ (32)));
typedef char __v32qi __attribute__ ((__vector_size__ (32)));
typedef float __m256 __attribute__ ((__vector_size__ (32),
				     __may_alias__));
typedef long long __m256i __attribute__ ((__vector_size__ (32),
					  __may_alias__));
typedef double __m256d __attribute__ ((__vector_size__ (32),
				       __may_alias__));

#ifdef __MMX__
#include <mmintrin.h>
#endif

#ifdef __SSE__
#include <xmmintrin.h>
#endif

#ifdef __SSE2__
#include <emmintrin.h>
#endif

#ifdef __SSE3__
#include <pmmintrin.h>
#endif

#ifdef __AVX__
#include <avxintrin.h>
#endif

#ifdef __F16C__
static __inline float __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_cvtsh_ss (unsigned short __S)
{
  __v8hi __H = __extension__ (__v8hi){ __S, 0, 0, 0, 0, 0, 0, 0 };
  __v4sf __A = __mm_cvtph_ps (__H);
  return _mm_cvtss_f32(__A);
}

static __inline __m128 __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtph_ps (__m128i __A)
{
  return (__m128) __mm_cvtph_ps ((__v8hi) __A);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm256_cvtph_ps (__m128i __A)
{
  return (__m256) __mm256_cvtph_ps ((__v8hi) __A);
}

#ifdef __OPTIMIZE__
static __inline unsigned short __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_cvtss_sh (float __F, const int __I)
{
  __v4sf __A =  __extension__ (__v4sf){ __F, 0, 0, 0 };
  __v8hi __H = __mm_cvtps_ph (__A, __I);
  return (unsigned short)_mm_extract_epi16(__H, 0);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtps_ph (__m128 __A, const int __I)
{
  return (__m128i) __mm_cvtps_ph ((__v4sf) __A, __I);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm256_cvtps_ph (__m256 __A, const int __I)
{
  return (__m128i) __mm256_cvtps_ph ((__v8sf) __A, __I);
}
#else
#define _cvtss_sh(__F, __I)                                             \
  (__extension__                                                        \
   ({                                                                   \
      __v4sf __A =  __extension__ (__v4sf){ __F, 0, 0, 0 };             \
      __v8hi __H = __mm_cvtps_ph (__A, __I);                            \
      (unsigned short)_mm_extract_epi16 (__H, 0);                       \
    }))

#define _mm_cvtps_ph(A, I) \
  ((__m128i) __mm_cvtps_ph ((__v4sf)(__m128) A, (int) (I)))

#define _mm256_cvtps_ph(A, I) \
  ((__m128i) __mm256_cvtps_ph ((__v8sf)(__m256) A, (int) (I)))
#endif

#endif /* __F16C__ */
#endif /* _IMMINTRIN_HEADER */
