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
# error "Never use <fma4intrin.h> directly; include <x86intrin.h> instead."
#endif
#ifndef _FMA4INTRIN_HEADER
#define _FMA4INTRIN_HEADER

#ifndef __FMA4__
# error "FMA4 instruction set not enabled"
#else

/* 128b Floating point multiply/add type instructions.  */
extern  __m128 _mm_macc_ps (__m128 __A, __m128 __B, __m128 __C);
extern  __m128d _mm_macc_pd (__m128d __A, __m128d __B, __m128d __C);
extern  __m128 _mm_macc_ss (__m128 __A, __m128 __B, __m128 __C);
extern  __m128d _mm_macc_sd (__m128d __A, __m128d __B, __m128d __C);
extern  __m128 _mm_msub_ps (__m128 __A, __m128 __B, __m128 __C);
extern  __m128d _mm_msub_pd (__m128d __A, __m128d __B, __m128d __C);
extern  __m128 _mm_msub_ss (__m128 __A, __m128 __B, __m128 __C);
extern  __m128d _mm_msub_sd (__m128d __A, __m128d __B, __m128d __C);
extern  __m128 _mm_nmacc_ps (__m128 __A, __m128 __B, __m128 __C);
extern  __m128d _mm_nmacc_pd (__m128d __A, __m128d __B, __m128d __C);
extern  __m128 _mm_nmacc_ss (__m128 __A, __m128 __B, __m128 __C);
extern  __m128d _mm_nmacc_sd (__m128d __A, __m128d __B, __m128d __C);
extern  __m128 _mm_nmsub_ps (__m128 __A, __m128 __B, __m128 __C);
extern  __m128d _mm_nmsub_pd (__m128d __A, __m128d __B, __m128d __C);
extern  __m128 _mm_nmsub_ss (__m128 __A, __m128 __B, __m128 __C);
extern  __m128d _mm_nmsub_sd (__m128d __A, __m128d __B, __m128d __C);
extern  __m128 _mm_maddsub_ps (__m128 __A, __m128 __B, __m128 __C);
extern  __m128d _mm_maddsub_pd (__m128d __A, __m128d __B, __m128d __C);
extern  __m128 _mm_msubadd_ps (__m128 __A, __m128 __B, __m128 __C);
extern  __m128d _mm_msubadd_pd (__m128d __A, __m128d __B, __m128d __C);
/* 256b Floating point multiply/add type instructions.  */
extern  __m256 _mm256_macc_ps (__m256 __A, __m256 __B, __m256 __C);
extern  __m256d _mm256_macc_pd (__m256d __A, __m256d __B, __m256d __C);
extern  __m256 _mm256_msub_ps (__m256 __A, __m256 __B, __m256 __C);
extern  __m256d _mm256_msub_pd (__m256d __A, __m256d __B, __m256d __C);
extern  __m256 _mm256_nmacc_ps (__m256 __A, __m256 __B, __m256 __C);
extern  __m256d _mm256_nmacc_pd (__m256d __A, __m256d __B, __m256d __C);
extern  __m256 _mm256_nmsub_ps (__m256 __A, __m256 __B, __m256 __C);
extern  __m256d _mm256_nmsub_pd (__m256d __A, __m256d __B, __m256d __C);
extern  __m256 _mm256_maddsub_ps (__m256 __A, __m256 __B, __m256 __C);
extern  __m256d _mm256_maddsub_pd (__m256d __A, __m256d __B, __m256d __C);
extern  __m256 _mm256_msubadd_ps (__m256 __A, __m256 __B, __m256 __C);
extern  __m256d _mm256_msubadd_pd (__m256d __A, __m256d __B, __m256d __C);
#endif /* _FMA4INTRIN_HEADER */
#endif
