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
# error "Never use <avxintrin.h> directly; include <immintrin.h> instead."
#endif

/* Compare predicates for scalar and packed compare intrinsics.  */

/* Equal (ordered, non-signaling)  */
#define _CMP_EQ_OQ	0x00
/* Less-than (ordered, signaling)  */
#define _CMP_LT_OS	0x01
/* Less-than-or-equal (ordered, signaling)  */
#define _CMP_LE_OS	0x02
/* Unordered (non-signaling)  */
#define _CMP_UNORD_Q	0x03
/* Not-equal (unordered, non-signaling)  */
#define _CMP_NEQ_UQ	0x04
/* Not-less-than (unordered, signaling)  */
#define _CMP_NLT_US	0x05
/* Not-less-than-or-equal (unordered, signaling)  */
#define _CMP_NLE_US	0x06
/* Ordered (nonsignaling)   */
#define _CMP_ORD_Q	0x07
/* Equal (unordered, non-signaling)  */
#define _CMP_EQ_UQ	0x08
/* Not-greater-than-or-equal (unordered, signaling)  */
#define _CMP_NGE_US	0x09
/* Not-greater-than (unordered, signaling)  */
#define _CMP_NGT_US	0x0a
/* False (ordered, non-signaling)  */
#define _CMP_FALSE_OQ	0x0b
/* Not-equal (ordered, non-signaling)  */
#define _CMP_NEQ_OQ	0x0c
/* Greater-than-or-equal (ordered, signaling)  */
#define _CMP_GE_OS	0x0d
/* Greater-than (ordered, signaling)  */
#define _CMP_GT_OS	0x0e
/* True (unordered, non-signaling)  */
#define _CMP_TRUE_UQ	0x0f
/* Equal (ordered, signaling)  */
#define _CMP_EQ_OS	0x10
/* Less-than (ordered, non-signaling)  */
#define _CMP_LT_OQ	0x11
/* Less-than-or-equal (ordered, non-signaling)  */
#define _CMP_LE_OQ	0x12
/* Unordered (signaling)  */
#define _CMP_UNORD_S	0x13
/* Not-equal (unordered, signaling)  */
#define _CMP_NEQ_US	0x14
/* Not-less-than (unordered, non-signaling)  */
#define _CMP_NLT_UQ	0x15
/* Not-less-than-or-equal (unordered, non-signaling)  */
#define _CMP_NLE_UQ	0x16
/* Ordered (signaling)  */
#define _CMP_ORD_S	0x17
/* Equal (unordered, signaling)  */
#define _CMP_EQ_US	0x18
/* Not-greater-than-or-equal (unordered, non-signaling)  */
#define _CMP_NGE_UQ	0x19
/* Not-greater-than (unordered, non-signaling)  */
#define _CMP_NGT_UQ	0x1a
/* False (ordered, signaling)  */
#define _CMP_FALSE_OS	0x1b
/* Not-equal (ordered, signaling)  */
#define _CMP_NEQ_OS	0x1c
/* Greater-than-or-equal (ordered, non-signaling)  */
#define _CMP_GE_OQ	0x1d
/* Greater-than (ordered, non-signaling)  */
#define _CMP_GT_OQ	0x1e
/* True (unordered, signaling)  */
#define _CMP_TRUE_US	0x1f

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_add_pd (__m256d __A, __m256d __B)
{
  return (__m256d) __mm256_add_pd ((__v4df)__A, (__v4df)__B);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_add_ps (__m256 __A, __m256 __B)
{
  return (__m256) __mm256_add_ps ((__v8sf)__A, (__v8sf)__B);
}

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_addsub_pd (__m256d __A, __m256d __B)
{
  return (__m256d) __mm256_addsub_pd ((__v4df)__A, (__v4df)__B);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_addsub_ps (__m256 __A, __m256 __B)
{
  return (__m256) __mm256_addsub_ps ((__v8sf)__A, (__v8sf)__B);
}


static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_and_pd (__m256d __A, __m256d __B)
{
  return (__m256d) __mm256_and_pd ((__v4df)__A, (__v4df)__B);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_and_ps (__m256 __A, __m256 __B)
{
  return (__m256) __mm256_and_ps ((__v8sf)__A, (__v8sf)__B);
}

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_andnot_pd (__m256d __A, __m256d __B)
{
  return (__m256d) __mm256_andnot_pd ((__v4df)__A, (__v4df)__B);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_andnot_ps (__m256 __A, __m256 __B)
{
  return (__m256) __mm256_andnot_ps ((__v8sf)__A, (__v8sf)__B);
}

/* Double/single precision floating point blend instructions - select
   data from 2 sources using constant/variable mask.  */

#ifdef __OPTIMIZE__
static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_blend_pd (__m256d __X, __m256d __Y, const int __M)
{
  return (__m256d) __mm256_blend_pd ((__v4df)__X,
				     (__v4df)__Y,
				      __M);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_blend_ps (__m256 __X, __m256 __Y, const int __M)
{
  return (__m256) __mm256_blend_ps ((__v8sf)__X,
				    (__v8sf)__Y,
				     __M);
}
#else
#define _mm256_blend_pd(X, Y, M)					\
  ((__m256d) __mm256_blend_pd ((__v4df)(__m256d)(X),		\
					(__v4df)(__m256d)(Y), (int)(M)))

#define _mm256_blend_ps(X, Y, M)					\
  ((__m256) __mm256_blend_ps ((__v8sf)(__m256)(X),		\
				       (__v8sf)(__m256)(Y), (int)(M)))
#endif

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_blendv_pd (__m256d __X, __m256d __Y, __m256d __M)
{
  return (__m256d) __mm256_blendv_pd ((__v4df)__X,
				      (__v4df)__Y,
				      (__v4df)__M);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_blendv_ps (__m256 __X, __m256 __Y, __m256 __M)
{
  return (__m256) __mm256_blendv_ps ((__v8sf)__X,
				     (__v8sf)__Y,
				     (__v8sf)__M);
}

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_div_pd (__m256d __A, __m256d __B)
{
  return (__m256d) __mm256_div_pd ((__v4df)__A, (__v4df)__B);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_div_ps (__m256 __A, __m256 __B)
{
  return (__m256) __mm256_div_ps ((__v8sf)__A, (__v8sf)__B);
}

/* Dot product instructions with mask-defined summing and zeroing parts
   of result.  */

#ifdef __OPTIMIZE__
static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_dp_ps (__m256 __X, __m256 __Y, const int __M)
{
  return (__m256) __mm256_dp_ps((__v8sf)__X,
				(__v8sf)__Y,
				 __M);
}
#else
#define _mm256_dp_ps(X, Y, M)						\
  ((__m256) __mm256_dp_ps ((__v8sf)(__m256)(X),		\
			   (__v8sf)(__m256)(Y), (int)(M)))
#endif

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_hadd_pd (__m256d __X, __m256d __Y)
{
  return (__m256d) __mm256_hadd_pd ((__v4df)__X, (__v4df)__Y);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_hadd_ps (__m256 __X, __m256 __Y)
{
  return (__m256) __mm256_hadd_ps ((__v8sf)__X, (__v8sf)__Y);
}

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_hsub_pd (__m256d __X, __m256d __Y)
{
  return (__m256d) __mm256_hsub_pd ((__v4df)__X, (__v4df)__Y);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_hsub_ps (__m256 __X, __m256 __Y)
{
  return (__m256) __mm256_hsub_ps ((__v8sf)__X, (__v8sf)__Y);
}

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_max_pd (__m256d __A, __m256d __B)
{
  return (__m256d) __mm256_max_pd ((__v4df)__A, (__v4df)__B);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_max_ps (__m256 __A, __m256 __B)
{
  return (__m256) __mm256_max_ps ((__v8sf)__A, (__v8sf)__B);
}

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_min_pd (__m256d __A, __m256d __B)
{
  return (__m256d) __mm256_min_pd ((__v4df)__A, (__v4df)__B);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_min_ps (__m256 __A, __m256 __B)
{
  return (__m256) __mm256_min_ps ((__v8sf)__A, (__v8sf)__B);
}

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_mul_pd (__m256d __A, __m256d __B)
{
  return (__m256d) __mm256_mul_pd ((__v4df)__A, (__v4df)__B);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_mul_ps (__m256 __A, __m256 __B)
{
  return (__m256) __mm256_mul_ps ((__v8sf)__A, (__v8sf)__B);
}

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_or_pd (__m256d __A, __m256d __B)
{
  return (__m256d) __mm256_or_pd ((__v4df)__A, (__v4df)__B);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_or_ps (__m256 __A, __m256 __B)
{
  return (__m256) __mm256_or_ps ((__v8sf)__A, (__v8sf)__B);
}

#ifdef __OPTIMIZE__
static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_shuffle_pd (__m256d __A, __m256d __B, const int __mask)
{
  return (__m256d) __mm256_shuffle_pd ((__v4df)__A, (__v4df)__B,
					__mask);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_shuffle_ps (__m256 __A, __m256 __B, const int __mask)
{
  return (__m256) __mm256_shuffle_ps ((__v8sf)__A, (__v8sf)__B,
				       __mask);
}
#else
#define _mm256_shuffle_pd(A, B, N)					\
  ((__m256d)__mm256_shuffle_pd ((__v4df)(__m256d)(A),		\
				(__v4df)(__m256d)(B), (int)(N)))

#define _mm256_shuffle_ps(A, B, N)					\
  ((__m256) __mm256_shuffle_ps ((__v8sf)(__m256)(A),		\
				(__v8sf)(__m256)(B), (int)(N)))
#endif

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_sub_pd (__m256d __A, __m256d __B)
{
  return (__m256d) __mm256_sub_pd ((__v4df)__A, (__v4df)__B);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_sub_ps (__m256 __A, __m256 __B)
{
  return (__m256) __mm256_sub_ps ((__v8sf)__A, (__v8sf)__B);
}
static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_xor_pd (__m256d __A, __m256d __B)
{
  return (__m256d) __mm256_xor_pd ((__v4df)__A, (__v4df)__B);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_xor_ps (__m256 __A, __m256 __B)
{
  return (__m256) __mm256_xor_ps ((__v8sf)__A, (__v8sf)__B);
}

#ifdef __OPTIMIZE__
static __inline __m128d __attribute__((__gnu_inline__, __always_inline__))
_mm_cmp_pd (__m128d __X, __m128d __Y, const int __P)
{
  return (__m128d) __mm_cmp_pd ((__v2df)__X, (__v2df)__Y, __P);
}

static __inline __m128 __attribute__((__gnu_inline__, __always_inline__))
_mm_cmp_ps (__m128 __X, __m128 __Y, const int __P)
{
  return (__m128) __mm_cmp_ps ((__v4sf)__X, (__v4sf)__Y, __P);
}

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_cmp_pd (__m256d __X, __m256d __Y, const int __P)
{
  return (__m256d) __mm256_cmp_pd ((__v4df)__X, (__v4df)__Y,
				    __P);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_cmp_ps (__m256 __X, __m256 __Y, const int __P)
{
  return (__m256) __mm256_cmp_ps ((__v8sf)__X, (__v8sf)__Y,
					   __P);
}

static __inline __m128d __attribute__((__gnu_inline__, __always_inline__))
_mm_cmp_sd (__m128d __X, __m128d __Y, const int __P)
{
  return (__m128d) __mm_cmp_sd ((__v2df)__X, (__v2df)__Y, __P);
}

static __inline __m128 __attribute__((__gnu_inline__, __always_inline__))
_mm_cmp_ss (__m128 __X, __m128 __Y, const int __P)
{
  return (__m128) __mm_cmp_ss ((__v4sf)__X, (__v4sf)__Y, __P);
}
#else
#define _mm_cmp_pd(X, Y, P)						\
  ((__m128d) __mm_cmp_pd ((__v2df)(__m128d)(X),		                \
			  (__v2df)(__m128d)(Y), (int)(P)))

#define _mm_cmp_ps(X, Y, P)						\
  ((__m128) __mm_cmp_ps ((__v4sf)(__m128)(X),			        \
			 (__v4sf)(__m128)(Y), (int)(P)))

#define _mm256_cmp_pd(X, Y, P)						\
  ((__m256d) __mm256_cmp_pd ((__v4df)(__m256d)(X),		        \
			     (__v4df)(__m256d)(Y), (int)(P)))

#define _mm256_cmp_ps(X, Y, P)						\
  ((__m256) __mm256_cmp_ps ((__v8sf)(__m256)(X),		        \
			    (__v8sf)(__m256)(Y), (int)(P)))

#define _mm_cmp_sd(X, Y, P)						\
  ((__m128d) __mm_cmp_sd ((__v2df)(__m128d)(X),		                \
				   (__v2df)(__m128d)(Y), (int)(P)))

#define _mm_cmp_ss(X, Y, P)						\
  ((__m128) __mm_cmp_ss ((__v4sf)(__m128)(X),			        \
				  (__v4sf)(__m128)(Y), (int)(P)))
#endif

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_cvtepi32_pd (__m128i __A)
{
  return (__m256d)__mm256_cvtepi32_pd ((__v4si) __A);
}
static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_cvtepi32_ps (__m256i __A)
{
  return (__m256)__mm256_cvtepi32_ps ((__v8si) __A);
}

static __inline __m128 __attribute__((__gnu_inline__, __always_inline__))
_mm256_cvtpd_ps (__m256d __A)
{
  return (__m128)__mm256_cvtpd_ps ((__v4df) __A);
}

static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_cvtps_epi32 (__m256 __A)
{
  return (__m256i)__mm256_cvtps_epi32 ((__v8sf) __A);
}

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_cvtps_pd (__m128 __A)
{
  return (__m256d)__mm256_cvtps_pd ((__v4sf) __A);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm256_cvttpd_epi32 (__m256d __A)
{
  return (__m128i)__mm256_cvttpd_epi32 ((__v4df) __A);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm256_cvtpd_epi32 (__m256d __A)
{
  return (__m128i)__mm256_cvtpd_epi32 ((__v4df) __A);
}

static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_cvttps_epi32 (__m256 __A)
{
  return (__m256i)__mm256_cvttps_epi32 ((__v8sf) __A);
}

#ifdef __OPTIMIZE__
static __inline __m128d __attribute__((__gnu_inline__, __always_inline__))
_mm256_extractf128_pd (__m256d __X, const int __N)
{
  return (__m128d) __mm256_extractf128_pd ((__v4df)__X, __N);
}

static __inline __m128 __attribute__((__gnu_inline__, __always_inline__))
_mm256_extractf128_ps (__m256 __X, const int __N)
{
  return (__m128) __mm256_extractf128_ps ((__v8sf)__X, __N);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm256_extractf128_si256 (__m256i __X, const int __N)
{
  return (__m128i) __mm256_extractf128_si256 ((__v8si)__X, __N);
}
#if 0
//NO SUPORT for _mm_extract_epi*
static __inline int __attribute__((__gnu_inline__, __always_inline__))
_mm256_extract_epi32 (__m256i __X, int const __N)
{
  __m128i __Y = __mm256_extractf128_si256 (__X, __N >> 2);
  return _mm_extract_epi32 (__Y, __N % 4);
}

static __inline int __attribute__((__gnu_inline__, __always_inline__))
_mm256_extract_epi16 (__m256i __X, int const __N)
{
  __m128i __Y = __mm256_extractf128_si256 (__X, __N >> 3);
  return __mm_extract_epi16 (__Y, __N % 8);
}

static __inline int __attribute__((__gnu_inline__, __always_inline__))
_mm256_extract_epi8 (__m256i __X, int const __N)
{
  __m128i __Y = __mm256_extractf128_si256 (__X, __N >> 4);
  return __mm_extract_epi8 (__Y, __N % 16);
}
#ifdef __x86_64__
static __inline long long  __attribute__((__gnu_inline__, __always_inline__))
_mm256_extract_epi64 (__m256i __X, const int __N)
{
  __m128i __Y = __mm256_extractf128_si256 (__X, __N >> 1);
  return __mm_extract_epi64 (__Y, __N % 2);
}
#endif
#endif
#else
#define _mm256_extractf128_pd(X, N)			                \
  ((__m128d) __mm256_extractf128_pd ((__v4df)(__m256d)(X),	        \
				     (int)(N)))

#define _mm256_extractf128_ps(X, N)					\
  ((__m128) __mm256_extractf128_ps ((__v8sf)(__m256)(X),	        \
					       (int)(N)))

#define _mm256_extractf128_si256(X, N)					\
  ((__m128i) __mm256_extractf128_si256 ((__v8si)(__m256i)(X),	        \
						(int)(N)))

#define _mm256_extract_epi32(X, N)					\
  (__extension__							\
   ({									\
      __m128i __Y = _mm256_extractf128_si256 ((X), (N) >> 2);		\
      _mm_extract_epi32 (__Y, (N) % 4);					\
    }))

#define _mm256_extract_epi16(X, N)					\
  (__extension__							\
   ({									\
      __m128i __Y = __mm256_extractf128_si256 ((X), (N) >> 3);		\
      __mm_extract_epi16 (__Y, (N) % 8);				\
    }))

#define _mm256_extract_epi8(X, N)					\
  (__extension__							\
   ({									\
      __m128i __Y = __mm256_extractf128_si256 ((X), (N) >> 4);		\
      __mm_extract_epi8 (__Y, (N) % 16);				\
    }))

#ifdef __x86_64__
#define _mm256_extract_epi64(X, N)					\
  (__extension__							\
   ({									\
      __m128i __Y = __mm256_extractf128_si256 ((X), (N) >> 1);		\
      __mm_extract_epi64 (__Y, (N) % 2);				\
    }))
#endif
#endif
static __inline void __attribute__((__gnu_inline__, __always_inline__))
_mm256_zeroall (void)
{
  __asm__("vzeroall\n");
  //__mm256_zeroall ();
}

static __inline void __attribute__((__gnu_inline__, __always_inline__))
_mm256_zeroupper (void)
{
  __asm__("vzeroupper\n");
  //__mm256_zeroupper ();
}
static __inline __m128d __attribute__((__gnu_inline__, __always_inline__))
_mm_permutevar_pd (__m128d __A, __m128i __C)
{
  return (__m128d) __mm_permutevar_pd ((__v2df)__A,
				       (__v2di)__C);
}

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_permutevar_pd (__m256d __A, __m256i __C)
{
  return (__m256d) __mm256_permutevar_pd ((__v4df)__A,
					  (__v4di)__C);
}

static __inline __m128 __attribute__((__gnu_inline__, __always_inline__))
_mm_permutevar_ps (__m128 __A, __m128i __C)
{
  return (__m128) __mm_permutevar_ps ((__v4sf)__A,
				      (__v4si)__C);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_permutevar_ps (__m256 __A, __m256i __C)
{
  return (__m256) __mm256_permutevar_ps ((__v8sf)__A,
					 (__v8si)__C);
}

#ifdef __OPTIMIZE__
static __inline __m128d __attribute__((__gnu_inline__, __always_inline__))
_mm_permute_pd (__m128d __X, const int __C)
{
  return (__m128d) __mm_permute_pd ((__v2df)__X, __C);
}

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_permute_pd (__m256d __X, const int __C)
{
  return (__m256d) __mm256_permute_pd ((__v4df)__X, __C);
}

static __inline __m128 __attribute__((__gnu_inline__, __always_inline__))
_mm_permute_ps (__m128 __X, const int __C)
{
  return (__m128) __mm_permute_ps  ((__v4sf)__X, __C);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_permute_ps (__m256 __X, const int __C)
{
  return (__m256) __mm256_permute_ps ((__v8sf)__X, __C);
}
#else
#define _mm_permute_pd(X, C)						\
  ((__m128d) __mm_permute_pd ((__v2df)(__m128d)(X), (int)(C)))

#define _mm256_permute_pd(X, C)						\
  ((__m256d) __mm256_permute_pd ((__v4df)(__m256d)(X),	(int)(C)))

#define _mm_permute_ps(X, C)						\
  ((__m128) __mm_permute_ps ((__v4sf)(__m128)(X), (int)(C)))

#define _mm256_permute_ps(X, C)						\
  ((__m256) __mm256_permute_ps ((__v8sf)(__m256)(X), (int)(C)))
#endif

#ifdef __OPTIMIZE__
static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_permute2f128_pd (__m256d __X, __m256d __Y, const int __C)
{
  return (__m256d) __mm256_permute2f128_pd ((__v4df)__X,
					    (__v4df)__Y,
					     __C);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_permute2f128_ps (__m256 __X, __m256 __Y, const int __C)
{
  return (__m256) __mm256_permute2f128_ps ((__v8sf)__X,
					   (__v8sf)__Y,
					    __C);
}

static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_permute2f128_si256 (__m256i __X, __m256i __Y, const int __C)
{
  return (__m256i) __mm256_permute2f128_si256 ((__v8si)__X,
					       (__v8si)__Y,
						__C);
}
#else
#define _mm256_permute2f128_pd(X, Y, C)					\
  ((__m256d) __mm256_permute2f128_pd ((__v4df)(__m256d)(X),	        \
					      (__v4df)(__m256d)(Y),	\
					      (int)(C)))

#define _mm256_permute2f128_ps(X, Y, C)					\
  ((__m256) __mm256_permute2f128_ps ((__v8sf)(__m256)(X),	        \
					     (__v8sf)(__m256)(Y),	\
					     (int)(C)))

#define _mm256_permute2f128_si256(X, Y, C)				\
  ((__m256i) __mm256_permute2f128_si256 ((__v8si)(__m256i)(X),	        \
					      (__v8si)(__m256i)(Y),	\
					      (int)(C)))
#endif

static __inline __m128 __attribute__((__gnu_inline__, __always_inline__))
_mm_broadcast_ss (float const *__X)
{
  return (__m128) __mm_broadcast_ss (__X);
}

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_broadcast_sd (double const *__X)
{
  return (__m256d) __mm256_broadcast_sd (__X);
}
static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_broadcast_ss (float const *__X)
{
  return (__m256) __mm256_broadcast_ss (__X);
}

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_broadcast_pd (__m128d const *__X)
{
  return (__m256d) __mm256_broadcast_pd (__X);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_broadcast_ps (__m128 const *__X)
{
  return (__m256) __mm256_broadcast_ps (__X);
}
#ifdef __OPTIMIZE__
static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_insertf128_pd (__m256d __X, __m128d __Y, const int __O)
{
  return (__m256d) __mm256_insertf128_pd ((__v4df)__X,
					  (__v2df)__Y,
					   __O);
}
static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_insertf128_ps (__m256 __X, __m128 __Y, const int __O)
{
  return (__m256) __mm256_insertf128_ps ((__v8sf)__X,
					 (__v4sf)__Y,
					  __O);
}

static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_insertf128_si256 (__m256i __X, __m128i __Y, const int __O)
{
  return (__m256i) __mm256_insertf128_si256 ((__v8si)__X,
					     (__v4si)__Y,
					      __O);
}
#if 0
//NO SUPPORT FOR _mm_insert_epi*
static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_insert_epi32 (__m256i __X, int __D, int const __N)
{
  __m128i __Y = _mm256_extractf128_si256 (__X, __N >> 2);
  __Y = _mm_insert_epi32 (__Y, __D, __N % 4);
  return _mm256_insertf128_si256 (__X, __Y, __N >> 2);
}
static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_insert_epi16 (__m256i __X, int __D, int const __N)
{
  __m128i __Y = _mm256_extractf128_si256 (__X, __N >> 3);
  __Y = _mm_insert_epi16 (__Y, __D, __N % 8);
  return _mm256_insertf128_si256 (__X, __Y, __N >> 3);
}
static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_insert_epi8 (__m256i __X, int __D, int const __N)
{
  __m128i __Y = _mm256_extractf128_si256 (__X, __N >> 4);
  __Y = _mm_insert_epi8 (__Y, __D, __N % 16);
  return _mm256_insertf128_si256 (__X, __Y, __N >> 4);
}
#ifdef __x86_64__
static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_insert_epi64 (__m256i __X, int __D, int const __N)
{
  __m128i __Y = _mm256_extractf128_si256 (__X, __N >> 1);
  __Y = _mm_insert_epi64 (__Y, __D, __N % 2);
  return _mm256_insertf128_si256 (__X, __Y, __N >> 1);
}
#endif
#endif
#else
#define _mm256_insertf128_pd(X, Y, O)			        \
  ((__m256d) __mm256_insertf128_pd ((__v4df)(__m256d)(X),	\
				    (__v2df)(__m128d)(Y),	\
				    (int)(O)))

#define _mm256_insertf128_ps(X, Y, O)					\
  ((__m256) __mm256_insertf128_ps ((__v8sf)(__m256)(X),	\
					      (__v4sf)(__m128)(Y),  	\
					      (int)(O)))

#define _mm256_insertf128_si256(X, Y, O)				\
  ((__m256i) __mm256_insertf128_si256 ((__v8si)(__m256i)(X),	\
					       (__v4si)(__m128i)(Y),	\
					       (int)(O)))

#define _mm256_insert_epi32(X, D, N)					\
  (__extension__							\
   ({									\
      __m128i __Y = _mm256_extractf128_si256 ((X), (N) >> 2);		\
      __Y = _mm_insert_epi32 (__Y, (D), (N) % 4);			\
      _mm256_insertf128_si256 ((X), __Y, (N) >> 2);			\
    }))

#define _mm256_insert_epi16(X, D, N)					\
  (__extension__							\
   ({									\
      __m128i __Y = _mm256_extractf128_si256 ((X), (N) >> 3);		\
      __Y = _mm_insert_epi16 (__Y, (D), (N) % 8);			\
      _mm256_insertf128_si256 ((X), __Y, (N) >> 3);			\
    }))

#define _mm256_insert_epi8(X, D, N)					\
  (__extension__							\
   ({									\
      __m128i __Y = _mm256_extractf128_si256 ((X), (N) >> 4);		\
      __Y = _mm_insert_epi8 (__Y, (D), (N) % 16);			\
      _mm256_insertf128_si256 ((X), __Y, (N) >> 4);			\
    }))

#ifdef __x86_64__
#define _mm256_insert_epi64(X, D, N)					\
  (__extension__							\
   ({									\
      __m128i __Y = _mm256_extractf128_si256 ((X), (N) >> 1);		\
      __Y = _mm_insert_epi64 (__Y, (D), (N) % 2);			\
      _mm256_insertf128_si256 ((X), __Y, (N) >> 1);			\
    }))
#endif
#endif
static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_load_pd (double const *__P)
{
   return (__m256d) __mm256_load_pd (__P);
}

static __inline void __attribute__((__gnu_inline__, __always_inline__))
_mm256_store_pd (double *__P, __m256d __A)
{
   __mm256_store_pd(__P, __A);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_load_ps (float const *__P)
{
   return (__m256) __mm256_load_ps (__P);
}

static __inline void __attribute__((__gnu_inline__, __always_inline__))
_mm256_store_ps (float *__P, __m256 __A)
{
   __mm256_store_ps(__P, __A);
}
static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_loadu_pd (double const *__P)
{
  return (__m256d) __mm256_loadu_pd (__P);
}

static __inline void __attribute__((__gnu_inline__, __always_inline__))
_mm256_storeu_pd (double *__P, __m256d __A)
{
  __mm256_storeu_pd (__P, (__v4df)__A);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_loadu_ps (float const *__P)
{
  return (__m256) __mm256_loadu_ps (__P);
}

static __inline void __attribute__((__gnu_inline__, __always_inline__))
_mm256_storeu_ps (float *__P, __m256 __A)
{
  __mm256_storeu_ps (__P, (__v8sf)__A);
}
static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_load_si256 (__m256i const *__P)
{
//TODO NEED TO CHECK THIS FOR ARG WARNING
 // return *__P;
  return (__m256i)__mm256_load_si256 ((char const*)__P);
}
static __inline void __attribute__((__gnu_inline__, __always_inline__))
_mm256_store_si256 (__m256i *__P, __m256i __A)
{
 // *__P = __A;
 __mm256_store_si256 ((char*)__P, (__v32qi)__A);
}

static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_loadu_si256 (__m256i const *__P)
{
  return (__m256i) __mm256_loadu_si256 ((char const *)__P);
}

static __inline void __attribute__((__gnu_inline__, __always_inline__))
_mm256_storeu_si256 (__m256i *__P, __m256i __A)
{
  __mm256_storeu_si256 ((char *)__P, (__v32qi)__A);
}
#if 0
//TODO In all these functions 2nd arg is incorrect either here in header or in i386.c
static __inline __m128d __attribute__((__gnu_inline__, __always_inline__))
_mm_maskload_pd (double const *__P, __m128i __M)
{
  return (__m128d) __mm_maskload_pd ((const __v2df *)__P,
					      (__v2di)__M);
}
static __inline void __attribute__((__gnu_inline__, __always_inline__))
_mm_maskstore_pd (double *__P, __m128i __M, __m128d __A)
{
  __mm_maskstore_pd ((__v2df *)__P, (__v2di)__M, (__v2df)__A);
}
static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_maskload_pd (double const *__P, __m256i __M)
{
  return (__m256d) __mm256_maskload_pd ((const __v4df *)__P,
						 (__v4di)__M);
}

static __inline void __attribute__((__gnu_inline__, __always_inline__))
_mm256_maskstore_pd (double *__P, __m256i __M, __m256d __A)
{
  __mm256_maskstore_pd ((__v4df *)__P, (__v4di)__M, (__v4df)__A);
}

static __inline __m128 __attribute__((__gnu_inline__, __always_inline__))
_mm_maskload_ps (float const *__P, __m128i __M)
{
  return (__m128) __mm_maskload_ps ((const __v4sf *)__P,
					     (__v4si)__M);
}

static __inline void __attribute__((__gnu_inline__, __always_inline__))
_mm_maskstore_ps (float *__P, __m128i __M, __m128 __A)
{
  __mm_maskstore_ps ((__v4sf *)__P, (__v4si)__M, (__v4sf)__A);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_maskload_ps (float const *__P, __m256i __M)
{
  return (__m256) __mm256_maskload_ps ((const __v8sf *)__P,
						(__v8si)__M);
}

static __inline void __attribute__((__gnu_inline__, __always_inline__))
_mm256_maskstore_ps (float *__P, __m256i __M, __m256 __A)
{
  __mm256_maskstore_ps ((__v8sf *)__P, (__v8si)__M, (__v8sf)__A);
}
#endif
static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_movehdup_ps (__m256 __X)
{
  return (__m256) __mm256_movehdup_ps ((__v8sf)__X);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_moveldup_ps (__m256 __X)
{
  return (__m256) __mm256_moveldup_ps ((__v8sf)__X);
}

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_movedup_pd (__m256d __X)
{
  return (__m256d) __mm256_movedup_pd ((__v4df)__X);
}

static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_lddqu_si256 (__m256i const *__P)
{
  return (__m256i) __mm256_lddqu_si256 ((char const *)__P);
}
#if 0
TODO: check the warning for 2nd arg
static __inline void __attribute__((__gnu_inline__, __always_inline__))
_mm256_stream_si256 (__m256i *__A, __m256i __B)
{
  __mm256_stream_si256 ((__v4di *)__A, (__v4di)__B);
}
#endif
static __inline void __attribute__((__gnu_inline__, __always_inline__))
_mm256_stream_pd (double *__A, __m256d __B)
{
  __mm256_stream_pd (__A, (__v4df)__B);
}

static __inline void __attribute__((__gnu_inline__, __always_inline__))
_mm256_stream_ps (float *__P, __m256 __A)
{
  __mm256_stream_ps (__P, (__v8sf)__A);
}
static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_rcp_ps (__m256 __A)
{
  return (__m256) __mm256_rcp_ps ((__v8sf)__A);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_rsqrt_ps (__m256 __A)
{
  return (__m256) __mm256_rsqrt_ps ((__v8sf)__A);
}

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_sqrt_pd (__m256d __A)
{
  return (__m256d) __mm256_sqrt_pd ((__v4df)__A);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_sqrt_ps (__m256 __A)
{
  return (__m256) __mm256_sqrt_ps ((__v8sf)__A);
}

#ifdef __OPTIMIZE__
static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_round_pd (__m256d __V, const int __M)
{
  return (__m256d) __mm256_round_pd ((__v4df)__V, __M);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_round_ps (__m256 __V, const int __M)
{
  return (__m256) __mm256_round_ps ((__v8sf)__V, __M);
}
#else
#define _mm256_round_pd(V, M) \
  ((__m256d) __mm256_round_pd ((__v4df)(__m256d)(V), (int)(M)))

#define _mm256_round_ps(V, M) \
  ((__m256) __mm256_round_ps ((__v8sf)(__m256)(V), (int)(M)))
#endif

#define _mm256_ceil_pd(V)	_mm256_round_pd ((V), _MM_FROUND_CEIL)
#define _mm256_floor_pd(V)	_mm256_round_pd ((V), _MM_FROUND_FLOOR)
#define _mm256_ceil_ps(V)	_mm256_round_ps ((V), _MM_FROUND_CEIL)
#define _mm256_floor_ps(V)	_mm256_round_ps ((V), _MM_FROUND_FLOOR)

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_unpackhi_pd (__m256d __A, __m256d __B)
{
  return (__m256d) __mm256_unpackhi_pd ((__v4df)__A, (__v4df)__B);
}

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_unpacklo_pd (__m256d __A, __m256d __B)
{
  return (__m256d) __mm256_unpacklo_pd ((__v4df)__A, (__v4df)__B);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_unpackhi_ps (__m256 __A, __m256 __B)
{
  return (__m256) __mm256_unpackhi_ps ((__v8sf)__A, (__v8sf)__B);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_unpacklo_ps (__m256 __A, __m256 __B)
{
  return (__m256) __mm256_unpacklo_ps ((__v8sf)__A, (__v8sf)__B);
}

static __inline int __attribute__((__gnu_inline__, __always_inline__))
_mm_testz_pd (__m128d __M, __m128d __V)
{
  return __mm_testz_pd ((__v2df)__M, (__v2df)__V);
}

static __inline int __attribute__((__gnu_inline__, __always_inline__))
_mm_testc_pd (__m128d __M, __m128d __V)
{
  return __mm_testc_pd ((__v2df)__M, (__v2df)__V);
}

static __inline int __attribute__((__gnu_inline__, __always_inline__))
_mm_testnzc_pd (__m128d __M, __m128d __V)
{
  return __mm_testnzc_pd ((__v2df)__M, (__v2df)__V);
}

static __inline int __attribute__((__gnu_inline__, __always_inline__))
_mm_testz_ps (__m128 __M, __m128 __V)
{
  return __mm_testz_ps ((__v4sf)__M, (__v4sf)__V);
}

static __inline int __attribute__((__gnu_inline__, __always_inline__))
_mm_testc_ps (__m128 __M, __m128 __V)
{
  return __mm_testc_ps ((__v4sf)__M, (__v4sf)__V);
}

static __inline int __attribute__((__gnu_inline__, __always_inline__))
_mm_testnzc_ps (__m128 __M, __m128 __V)
{
  return __mm_testnzc_ps ((__v4sf)__M, (__v4sf)__V);
}

static __inline int __attribute__((__gnu_inline__, __always_inline__))
_mm256_testz_pd (__m256d __M, __m256d __V)
{
  return __mm256_testz_pd ((__v4df)__M, (__v4df)__V);
}

static __inline int __attribute__((__gnu_inline__, __always_inline__))
_mm256_testc_pd (__m256d __M, __m256d __V)
{
  return __mm256_testc_pd ((__v4df)__M, (__v4df)__V);
}

static __inline int __attribute__((__gnu_inline__, __always_inline__))
_mm256_testnzc_pd (__m256d __M, __m256d __V)
{
  return __mm256_testnzc_pd ((__v4df)__M, (__v4df)__V);
}

static __inline int __attribute__((__gnu_inline__, __always_inline__))
_mm256_testz_ps (__m256 __M, __m256 __V)
{
  return __mm256_testz_ps ((__v8sf)__M, (__v8sf)__V);
}

static __inline int __attribute__((__gnu_inline__, __always_inline__))
_mm256_testc_ps (__m256 __M, __m256 __V)
{
  return __mm256_testc_ps ((__v8sf)__M, (__v8sf)__V);
}

static __inline int __attribute__((__gnu_inline__, __always_inline__))
_mm256_testnzc_ps (__m256 __M, __m256 __V)
{
  return __mm256_testnzc_ps ((__v8sf)__M, (__v8sf)__V);
}

static __inline int __attribute__((__gnu_inline__, __always_inline__))
_mm256_testz_si256 (__m256i __M, __m256i __V)
{
  return __mm256_testz_si256 ((__v4di)__M, (__v4di)__V);
}

static __inline int __attribute__((__gnu_inline__, __always_inline__))
_mm256_testc_si256 (__m256i __M, __m256i __V)
{
  return __mm256_testc_si256 ((__v4di)__M, (__v4di)__V);
}

static __inline int __attribute__((__gnu_inline__, __always_inline__))
_mm256_testnzc_si256 (__m256i __M, __m256i __V)
{
  return __mm256_testnzc_si256 ((__v4di)__M, (__v4di)__V);
}

static __inline int __attribute__((__gnu_inline__, __always_inline__))
_mm256_movemask_pd (__m256d __A)
{
  return __mm256_movemask_pd ((__v4df)__A);
}

static __inline int __attribute__((__gnu_inline__, __always_inline__))
_mm256_movemask_ps (__m256 __A)
{
  return __mm256_movemask_ps ((__v8sf)__A);
}

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_setzero_pd (void)
{
  return __extension__ (__m256d)__mm256_setzero_pd ();
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_setzero_ps (void)
{
  return __extension__ (__m256)__mm256_setzero_ps ();
}

static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_setzero_si256 (void)
{
  return __extension__ (__m256i)(__v4di)__mm256_setzero_si256 ();
}

/* Create the vector [A B C D].  */
static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_set_pd (double __A, double __B, double __C, double __D)
{
  return __extension__ (__m256d)__mm256_set_pd (__A, __B, __C, __D);
}

/* Create the vector [A B C D E F G H].  */
static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_set_ps (float __A, float __B, float __C, float __D,
	       float __E, float __F, float __G, float __H)
{
  return __extension__ (__m256)__mm256_set_ps ( 
  __A, __B, __C, __D, __E, __F, __G, __H );
}

/* Create the vector [A B C D E F G H].  */
static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_set_epi32 (int __A, int __B, int __C, int __D,
		  int __E, int __F, int __G, int __H)
{
  return __extension__ (__m256i)(__v8si)__mm256_set_epi32 (
  __A, __B, __C, __D, __E, __F, __G, __H );
}

static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_set_epi16 (short __q15, short __q14, short __q13, short __q12,
		  short __q11, short __q10, short __q09, short __q08,
		  short __q07, short __q06, short __q05, short __q04,
		  short __q03, short __q02, short __q01, short __q00)
{
  return __extension__ (__m256i)(__v16hi) __mm256_set_epi16 (
    __q15, __q14, __q13, __q12, __q11, __q10, __q09, __q08,
    __q07, __q06, __q05, __q04, __q03, __q02, __q01, __q00
  );
}

static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_set_epi8  (char __q31, char __q30, char __q29, char __q28,
		  char __q27, char __q26, char __q25, char __q24,
		  char __q23, char __q22, char __q21, char __q20,
		  char __q19, char __q18, char __q17, char __q16,
		  char __q15, char __q14, char __q13, char __q12,
		  char __q11, char __q10, char __q09, char __q08,
		  char __q07, char __q06, char __q05, char __q04,
		  char __q03, char __q02, char __q01, char __q00)
{
  return __extension__ (__m256i)(__v32qi)__mm256_set_epi8 (
    __q31, __q30, __q29, __q28, __q27, __q26, __q25, __q24, 
    __q23, __q22, __q21, __q20, __q19, __q18, __q17, __q16, 
    __q15, __q14, __q13, __q12, __q11, __q10, __q09, __q08, 
    __q07, __q06, __q05, __q04, __q03, __q02, __q01, __q00
  );
}

static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_set_epi64x (long long __A, long long __B, long long __C,
		   long long __D)
{
  return __extension__ (__m256i)(__v4di)__mm256_set_epi64x (__A, __B, __C, __D);
}

/* Create a vector with all elements equal to A.  */
static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_set1_pd (double __A)
{
  return __extension__ (__m256d)__mm256_set1_pd(__A);
}

/* Create a vector with all elements equal to A.  */
static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_set1_ps (float __A)
{
  return __extension__ (__m256)__mm256_set1_ps (__A);
}

/* Create a vector with all elements equal to A.  */
static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_set1_epi32 (int __A)
{
  return __extension__ (__m256i)(__v8si)__mm256_set1_epi32 (__A);
}

static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_set1_epi16 (short __A)
{
  return __mm256_set1_epi16 (__A);
}

static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_set1_epi8 (char __A)
{
  return __mm256_set1_epi8 (__A);
}

static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_set1_epi64x (long long __A)
{
  return (__m256i)(__v4di)__mm256_set1_epi64x (__A);
}

/* Create vectors of elements in the reversed order from the
   _mm256_set_XXX functions.  */

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_setr_pd (double __A, double __B, double __C, double __D)
{
  return __mm256_setr_pd (__A, __B, __C, __D);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_setr_ps (float __A, float __B, float __C, float __D,
		float __E, float __F, float __G, float __H)
{
  return __mm256_setr_ps (__A, __B, __C, __D, __E, __F, __G, __H);
}

static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_setr_epi32 (int __A, int __B, int __C, int __D,
		   int __E, int __F, int __G, int __H)
{
  return __mm256_setr_epi32 (__A, __B, __C, __D, __E, __F, __G, __H);
}

static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_setr_epi16 (short __q15, short __q14, short __q13, short __q12,
		   short __q11, short __q10, short __q09, short __q08,
		   short __q07, short __q06, short __q05, short __q04,
		   short __q03, short __q02, short __q01, short __q00)
{
  return __mm256_setr_epi16 (__q15, __q14, __q13, __q12,
			   __q11, __q10, __q09, __q08,
			   __q07, __q06, __q05, __q04,
			   __q03, __q02, __q01, __q00);
}

static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_setr_epi8  (char __q31, char __q30, char __q29, char __q28,
		   char __q27, char __q26, char __q25, char __q24,
		   char __q23, char __q22, char __q21, char __q20,
		   char __q19, char __q18, char __q17, char __q16,
		   char __q15, char __q14, char __q13, char __q12,
		   char __q11, char __q10, char __q09, char __q08,
		   char __q07, char __q06, char __q05, char __q04,
		   char __q03, char __q02, char __q01, char __q00)
{
  return __mm256_setr_epi8 (__q31, __q30, __q29, __q28,
			  __q27, __q26, __q25, __q24,
			  __q23, __q22, __q21, __q20,
			  __q19, __q18, __q17, __q16,
			  __q15, __q14, __q13, __q12,
			  __q11, __q10, __q09, __q08,
			  __q07, __q06, __q05, __q04,
			  __q03, __q02, __q01, __q00);
}

static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_setr_epi64x (long long __A, long long __B, long long __C,
		    long long __D)
{
  return __mm256_setr_epi64x (__A, __B, __C, __D);
}

/* Casts between various SP, DP, INT vector types.  Note that these do no
   conversion of values, they just change the type.  */
static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_castpd_ps (__m256d __A)
{
  return (__m256)__mm256_castpd_ps(__A);
}

static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_castpd_si256 (__m256d __A)
{
  return (__m256i)__mm256_castpd_si256(__A);
}

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_castps_pd (__m256 __A)
{
  return (__m256d) __mm256_castps_pd (__A);
}

static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_castps_si256(__m256 __A)
{
  return (__m256i) __mm256_castps_si256 (__A);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_castsi256_ps (__m256i __A)
{
  return (__m256) __mm256_castsi256_ps (__A);
}

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_castsi256_pd (__m256i __A)
{
  return (__m256d) __mm256_castsi256_pd(__A);
}

static __inline __m128d __attribute__((__gnu_inline__, __always_inline__))
_mm256_castpd256_pd128 (__m256d __A)
{
  return (__m128d) __mm256_castpd256_pd128 ((__v4df)__A);
}

static __inline __m128 __attribute__((__gnu_inline__, __always_inline__))
_mm256_castps256_ps128 (__m256 __A)
{
  return (__m128) __mm256_castps256_ps128 ((__v8sf)__A);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm256_castsi256_si128 (__m256i __A)
{
  return (__m128i) __mm256_castsi256_si128 ((__v8si)__A);
}

/* When cast is done from a 128 to 256-bit type, the low 128 bits of
   the 256-bit result contain source parameter value and the upper 128
   bits of the result are undefined.  Those intrinsics shouldn't
   generate any extra moves.  */

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_castpd128_pd256 (__m128d __A)
{
  return (__m256d) __mm256_castpd128_pd256 ((__v2df)__A);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_castps128_ps256 (__m128 __A)
{
  return (__m256) __mm256_castps128_ps256 ((__v4sf)__A);
}

static __inline __m256i __attribute__((__gnu_inline__, __always_inline__))
_mm256_castsi128_si256 (__m128i __A)
{
  return (__m256i) __mm256_castsi128_si256 ((__v4si)__A);
}
