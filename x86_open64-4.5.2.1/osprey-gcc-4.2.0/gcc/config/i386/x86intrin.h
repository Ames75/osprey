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
#define _X86INTRIN_HEADER

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

#ifdef __SSE4A__
#include <ammintrin.h>
#endif

/* For including AVX instructions */
#include <immintrin.h>

#ifdef __3dNOW__
#include <mm3dnow.h>
#endif

#ifdef __FMA4__
#include <fma4intrin.h>
#endif

#ifdef __XOP__
#include <xopintrin.h>
#endif

#ifdef __BM__
#include <bmintrin.h>
#endif

#endif /* _X86INTRIN_HEADER */
