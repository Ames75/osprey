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

#ifndef _X86INTRIN_HEADER
# error "Never use <xopintrin.h> directly; include <x86intrin.h> instead."
#endif

#ifndef _XOPMMINTRIN_HEADER
#define _XOPMMINTRIN_HEADER

#ifndef __XOP__
# error "XOP instruction set not enabled"
#else

/* Integer multiply/add intructions. */
static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_maccs_epi16(__m128i __A, __m128i __B, __m128i __C)
{
  return (__m128i) __mm_maccs_epi16 ((__v8hi)__A,(__v8hi)__B, (__v8hi)__C);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_macc_epi16(__m128i __A, __m128i __B, __m128i __C)
{
  return (__m128i) __mm_macc_epi16 ((__v8hi)__A, (__v8hi)__B, (__v8hi)__C);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_maccsd_epi16(__m128i __A, __m128i __B, __m128i __C)
{
  return  (__m128i) __mm_maccsd_epi16 ((__v8hi)__A, (__v8hi)__B, (__v4si)__C);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_maccd_epi16(__m128i __A, __m128i __B, __m128i __C)
{
  return  (__m128i) __mm_maccd_epi16 ((__v8hi)__A, (__v8hi)__B, (__v4si)__C);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_maccs_epi32(__m128i __A, __m128i __B, __m128i __C)
{
  return  (__m128i) __mm_maccs_epi32 ((__v4si)__A, (__v4si)__B, (__v4si)__C);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_macc_epi32(__m128i __A, __m128i __B, __m128i __C)
{
  return  (__m128i) __mm_macc_epi32 ((__v4si)__A, (__v4si)__B, (__v4si)__C);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_maccslo_epi32(__m128i __A, __m128i __B, __m128i __C)
{
  return  (__m128i) __mm_maccslo_epi32 ((__v4si)__A, (__v4si)__B, (__v2di)__C);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_macclo_epi32(__m128i __A, __m128i __B, __m128i __C)
{
  return  (__m128i) __mm_macclo_epi32 ((__v4si)__A, (__v4si)__B, (__v2di)__C);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_maccshi_epi32(__m128i __A, __m128i __B, __m128i __C)
{
  return  (__m128i) __mm_maccshi_epi32 ((__v4si)__A, (__v4si)__B, (__v2di)__C);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_macchi_epi32(__m128i __A, __m128i __B, __m128i __C)
{
  return  (__m128i) __mm_macchi_epi32 ((__v4si)__A, (__v4si)__B, (__v2di)__C);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_maddsd_epi16(__m128i __A, __m128i __B, __m128i __C)
{
  return  (__m128i) __mm_maddsd_epi16 ((__v8hi)__A,(__v8hi)__B,(__v4si)__C);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_maddd_epi16(__m128i __A, __m128i __B, __m128i __C)
{
  return  (__m128i) __mm_maddd_epi16 ((__v8hi)__A,(__v8hi)__B,(__v4si)__C);
}

/* Packed Integer Horizontal Add and Subtract */
static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_haddw_epi8(__m128i __A)
{
  return  (__m128i) __mm_haddw_epi8 ((__v16qi)__A);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_haddd_epi8(__m128i __A)
{
  return  (__m128i) __mm_haddd_epi8 ((__v16qi)__A);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_haddq_epi8(__m128i __A)
{
  return  (__m128i) __mm_haddq_epi8 ((__v16qi)__A);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_haddd_epi16(__m128i __A)
{
  return  (__m128i) __mm_haddd_epi16 ((__v8hi)__A);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_haddq_epi16(__m128i __A)
{
  return  (__m128i) __mm_haddq_epi16 ((__v8hi)__A);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_haddq_epi32(__m128i __A)
{
  return  (__m128i) __mm_haddq_epi32 ((__v4si)__A);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_haddw_epu8(__m128i __A)
{
  return  (__m128i) __mm_haddw_epu8 ((__v16qi)__A);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_haddd_epu8(__m128i __A)
{
  return  (__m128i) __mm_haddd_epu8 ((__v16qi)__A);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_haddq_epu8(__m128i __A)
{
  return  (__m128i) __mm_haddq_epu8 ((__v16qi)__A);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_haddd_epu16(__m128i __A)
{
  return  (__m128i) __mm_haddd_epu16 ((__v8hi)__A);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_haddq_epu16(__m128i __A)
{
  return  (__m128i) __mm_haddq_epu16 ((__v8hi)__A);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_haddq_epu32(__m128i __A)
{
  return  (__m128i) __mm_haddq_epu32 ((__v4si)__A);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_hsubw_epi8(__m128i __A)
{
  return  (__m128i) __mm_hsubw_epi8 ((__v16qi)__A);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_hsubd_epi16(__m128i __A)
{
  return  (__m128i) __mm_hsubd_epi16 ((__v8hi)__A);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_hsubq_epi32(__m128i __A)
{
  return  (__m128i) __mm_hsubq_epi32 ((__v4si)__A);
}

/* Vector conditional move and permute */

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_cmov_si128(__m128i __A, __m128i __B, __m128i __C)
{
  return  (__m128i) __mm_cmov_si128 (__A, __B, __C);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_perm_epi8(__m128i __A, __m128i __B, __m128i __C)
{
  return  (__m128i) __mm_perm_epi8 ((__v16qi)__A, (__v16qi)__B, (__v16qi)__C);
}

/* Packed Integer Rotates and Shifts
   Rotates - Non-Immediate form */

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_rot_epi8(__m128i __A,  __m128i __B)
{
  return  (__m128i) __mm_rot_epi8 ((__v16qi)__A, (__v16qi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_rot_epi16(__m128i __A,  __m128i __B)
{
  return  (__m128i) __mm_rot_epi16 ((__v8hi)__A, (__v8hi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_rot_epi32(__m128i __A,  __m128i __B)
{
  return  (__m128i) __mm_rot_epi32 ((__v4si)__A, (__v4si)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_rot_epi64(__m128i __A,  __m128i __B)
{
  return (__m128i)  __mm_rot_epi64 ((__v2di)__A, (__v2di)__B);
}

/* Rotates - Immediate form */

#ifdef __OPTIMIZE__
static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_roti_epi8(__m128i __A, const int __B)
{
  return  (__m128i) __mm_roti_epi8 ((__v16qi)__A, __B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_roti_epi16(__m128i __A, const int __B)
{
  return  (__m128i) __mm_roti_epi16 ((__v8hi)__A, __B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_roti_epi32(__m128i __A, const int __B)
{
  return  (__m128i) __mm_roti_epi32 ((__v4si)__A, __B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_roti_epi64(__m128i __A, const int __B)
{
  return  (__m128i) __mm_roti_epi64 ((__v2di)__A, __B);
}
#else
#define _mm_roti_epi8(A, N) \
  ((__m128i) __mm_roti_epi8 ((__v16qi)(__m128i)(A), (int)(N)))
#define _mm_roti_epi16(A, N) \
  ((__m128i) __mm_roti_epi16 ((__v8hi)(__m128i)(A), (int)(N)))
#define _mm_roti_epi32(A, N) \
  ((__m128i) __mm_roti_epi32 ((__v4si)(__m128i)(A), (int)(N)))
#define _mm_roti_epi64(A, N) \
  ((__m128i) __mm_roti_epi64 ((__v2di)(__m128i)(A), (int)(N)))
#endif

/* Shifts */

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_shl_epi8(__m128i __A,  __m128i __B)
{
  return  (__m128i) __mm_shl_epi8 ((__v16qi)__A, (__v16qi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_shl_epi16(__m128i __A,  __m128i __B)
{
  return  (__m128i) __mm_shl_epi16 ((__v8hi)__A, (__v8hi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_shl_epi32(__m128i __A,  __m128i __B)
{
  return  (__m128i) __mm_shl_epi32 ((__v4si)__A, (__v4si)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_shl_epi64(__m128i __A,  __m128i __B)
{
  return  (__m128i) __mm_shl_epi64 ((__v2di)__A, (__v2di)__B);
}


static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_sha_epi8(__m128i __A,  __m128i __B)
{
  return  (__m128i) __mm_sha_epi8 ((__v16qi)__A, (__v16qi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_sha_epi16(__m128i __A,  __m128i __B)
{
  return  (__m128i) __mm_sha_epi16 ((__v8hi)__A, (__v8hi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_sha_epi32(__m128i __A,  __m128i __B)
{
  return  (__m128i) __mm_sha_epi32 ((__v4si)__A, (__v4si)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_sha_epi64(__m128i __A,  __m128i __B)
{
  return  (__m128i) __mm_sha_epi64 ((__v2di)__A, (__v2di)__B);
}

/* Compare and Predicate Generation
   pcom (integer, unsinged bytes) */

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comlt_epu8(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comlt_epu8 ((__v16qi)__A, (__v16qi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comle_epu8(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comle_epu8 ((__v16qi)__A, (__v16qi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comgt_epu8(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comgt_epu8 ((__v16qi)__A, (__v16qi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comge_epu8(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comge_epu8 ((__v16qi)__A, (__v16qi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comeq_epu8(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comeq_epu8 ((__v16qi)__A, (__v16qi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comneq_epu8(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comneq_epu8 ((__v16qi)__A, (__v16qi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comfalse_epu8(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comfalse_epu8 ((__v16qi)__A, (__v16qi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comtrue_epu8(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comtrue_epu8 ((__v16qi)__A, (__v16qi)__B);
}

/*pcom (integer, unsinged words) */

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comlt_epu16(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comlt_epu16 ((__v8hi)__A, (__v8hi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comle_epu16(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comle_epu16 ((__v8hi)__A, (__v8hi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comgt_epu16(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comgt_epu16 ((__v8hi)__A, (__v8hi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comge_epu16(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comge_epu16 ((__v8hi)__A, (__v8hi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comeq_epu16(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comeq_epu16 ((__v8hi)__A, (__v8hi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comneq_epu16(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comneq_epu16 ((__v8hi)__A, (__v8hi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comfalse_epu16(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comfalse_epu16 ((__v8hi)__A, (__v8hi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comtrue_epu16(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comtrue_epu16 ((__v8hi)__A, (__v8hi)__B);
}

/*pcom (integer, unsinged double words) */

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comlt_epu32(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comlt_epu32 ((__v4si)__A, (__v4si)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comle_epu32(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comle_epu32 ((__v4si)__A, (__v4si)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comgt_epu32(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comgt_epu32 ((__v4si)__A, (__v4si)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comge_epu32(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comge_epu32 ((__v4si)__A, (__v4si)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comeq_epu32(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comge_epu32 ((__v4si)__A, (__v4si)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comneq_epu32(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comneq_epu32 ((__v4si)__A, (__v4si)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comfalse_epu32(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comfalse_epu32 ((__v4si)__A, (__v4si)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comtrue_epu32(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comtrue_epu32 ((__v4si)__A, (__v4si)__B);
}

/*pcom (integer, unsinged quad words) */

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comlt_epu64(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comlt_epu64 ((__v2di)__A, (__v2di)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comle_epu64(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comle_epu64 ((__v2di)__A, (__v2di)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comgt_epu64(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comgt_epu64 ((__v2di)__A, (__v2di)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comge_epu64(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comge_epu64 ((__v2di)__A, (__v2di)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comeq_epu64(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comeq_epu64 ((__v2di)__A, (__v2di)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comneq_epu64(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comneq_epu64 ((__v2di)__A, (__v2di)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comfalse_epu64(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comfalse_epu64 ((__v2di)__A, (__v2di)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comtrue_epu64(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comtrue_epu64 ((__v2di)__A, (__v2di)__B);
}

/*pcom (integer, signed bytes) */

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comlt_epi8(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comlt_epi8 ((__v16qi)__A, (__v16qi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comle_epi8(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comle_epi8 ((__v16qi)__A, (__v16qi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comgt_epi8(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comgt_epi8 ((__v16qi)__A, (__v16qi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comge_epi8(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comge_epi8 ((__v16qi)__A, (__v16qi)__B);
}
static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comeq_epi8(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comeq_epi8 ((__v16qi)__A, (__v16qi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comneq_epi8(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comneq_epi8 ((__v16qi)__A, (__v16qi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comfalse_epi8(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comfalse_epi8 ((__v16qi)__A, (__v16qi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comtrue_epi8(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comtrue_epi8 ((__v16qi)__A, (__v16qi)__B);
}

/*pcom (integer, signed words) */

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comlt_epi16(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comlt_epi16 ((__v8hi)__A, (__v8hi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comle_epi16(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comle_epi16 ((__v8hi)__A, (__v8hi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comgt_epi16(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comgt_epi16 ((__v8hi)__A, (__v8hi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comge_epi16(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comge_epi16 ((__v8hi)__A, (__v8hi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comeq_epi16(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comeq_epi16 ((__v8hi)__A, (__v8hi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comneq_epi16(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comneq_epi16 ((__v8hi)__A, (__v8hi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comfalse_epi16(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comfalse_epi16 ((__v8hi)__A, (__v8hi)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comtrue_epi16(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comtrue_epi16 ((__v8hi)__A, (__v8hi)__B);
}

/*pcom (integer, signed double words) */

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comlt_epi32(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comlt_epi32 ((__v4si)__A, (__v4si)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comle_epi32(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comle_epi32 ((__v4si)__A, (__v4si)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comgt_epi32(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comgt_epi32 ((__v4si)__A, (__v4si)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comge_epi32(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comge_epi32 ((__v4si)__A, (__v4si)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comeq_epi32(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comeq_epi32 ((__v4si)__A, (__v4si)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comneq_epi32(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comneq_epi32 ((__v4si)__A, (__v4si)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comfalse_epi32(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comfalse_epi32 ((__v4si)__A, (__v4si)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comtrue_epi32(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comtrue_epi32 ((__v4si)__A, (__v4si)__B);
}

/*pcom (integer, signed quad words) */

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comlt_epi64(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comlt_epi64 ((__v2di)__A, (__v2di)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comle_epi64(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comle_epi64 ((__v2di)__A, (__v2di)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comgt_epi64(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comgt_epi64 ((__v2di)__A, (__v2di)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comge_epi64(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comge_epi64 ((__v2di)__A, (__v2di)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comeq_epi64(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comeq_epi64 ((__v2di)__A, (__v2di)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comneq_epi64(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comneq_epi64 ((__v2di)__A, (__v2di)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comfalse_epi64(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comfalse_epi64 ((__v2di)__A, (__v2di)__B);
}

static __inline __m128i __attribute__((__gnu_inline__, __always_inline__))
_mm_comtrue_epi64(__m128i __A, __m128i __B)
{
  return (__m128i) __mm_comtrue_epi64 ((__v2di)__A, (__v2di)__B);
}

/* FRCZ */

static __inline __m128 __attribute__((__gnu_inline__, __always_inline__))
_mm_frcz_ps (__m128 __A)
{
  return (__m128) __mm_frcz_ps ((__v4sf)__A);
}

static __inline __m128d __attribute__((__gnu_inline__, __always_inline__))
_mm_frcz_pd (__m128d __A)
{
  return (__m128d) __mm_frcz_pd ((__v2df)__A);
}

static __inline __m128 __attribute__((__gnu_inline__, __always_inline__))
_mm_frcz_ss (__m128 __A, __m128 __B)
{
  return (__m128) __mm_frcz_ss ((__v4sf)__A, (__v4sf)__B);
}

static __inline __m128d __attribute__((__gnu_inline__, __always_inline__))
_mm_frcz_sd (__m128d __A, __m128d __B)
{
  return (__m128d) __mm_frcz_sd ((__v2df)__A, (__v2df)__B);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_frcz_ps (__m256 __A)
{
  return (__m256) __mm256_frcz_ps ((__v8sf)__A);
}

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_frcz_pd (__m256d __A)
{
  return (__m256d) __mm256_frcz_pd ((__v4df)__A);
}

/* PERMIL2 */

#ifdef __OPTIMIZE__
#if 0
//Following commented builtins are not handled in opencc
static __inline __m128d __attribute__((__gnu_inline__, __always_inline__))
_mm_permute2_pd (__m128d __X, __m128d __Y, __m128i __C, const int __I)
{
  return (__m128d) __mm_permute2_pd ((__v2df)__X,
					      (__v2df)__Y,
					      (__v2di)__C,
					      __I);
}

static __inline __m256d __attribute__((__gnu_inline__, __always_inline__))
_mm256_permute2_pd (__m256d __X, __m256d __Y, __m256i __C, const int __I)
{
  return (__m256d) __mm256_permute2_pd ((__v4df)__X,
						 (__v4df)__Y,
						 (__v4di)__C,
						 __I);
}
static __inline __m128 __attribute__((__gnu_inline__, __always_inline__))
_mm_permute2_ps (__m128 __X, __m128 __Y, __m128i __C, const int __I)
{
  return (__m128) __mm_permute2_ps ((__v4sf)__X,
					     (__v4sf)__Y,
					     (__v4si)__C,
					     __I);
}

static __inline __m256 __attribute__((__gnu_inline__, __always_inline__))
_mm256_permute2_ps (__m256 __X, __m256 __Y, __m256i __C, const int __I)
{
  return (__m256) __mm256_permute2_ps ((__v8sf)__X,
						(__v8sf)__Y,
						(__v8si)__C,
						__I);
}
#endif
#else
#define _mm_permute2_pd(X, Y, C, I)					\
  ((__m128d) __mm_permute2_pd ((__v2df)(__m128d)(X),		        \
					(__v2df)(__m128d)(Y),		\
					(__v2di)(__m128d)(C),		\
					(int)(I)))

#define _mm256_permute2_pd(X, Y, C, I)					\
  ((__m256d) __mm256_permute2_pd ((__v4df)(__m256d)(X),	                \
					   (__v4df)(__m256d)(Y),	\
					   (__v4di)(__m256d)(C),	\
					   (int)(I)))

#define _mm_permute2_ps(X, Y, C, I)					\
  ((__m128) __mm_permute2_ps ((__v4sf)(__m128)(X),		        \
				       (__v4sf)(__m128)(Y),		\
				       (__v4si)(__m128)(C),		\
				       (int)(I)))

#define _mm256_permute2_ps(X, Y, C, I)					\
  ((__m256) __mm256_permute2_ps ((__v8sf)(__m256)(X),		        \
					  (__v8sf)(__m256)(Y),  	\
					  (__v8si)(__m256)(C),		\
 					  (int)(I)))
#endif /* __OPTIMIZE__ */
#endif /* _XOPMMINTRIN_HEADER */
#endif
