/* Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2012
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

#ifndef BMINTRIN_H_INCLUDED
#define BMINTRIN_H_INCLUDED

typedef unsigned short __u16i;
typedef unsigned int __u32i;
typedef unsigned long long int __u64i;

/* TBM Intrinsic */
/* blcfill */
static __inline __u32i __attribute__((__always_inline__))
__blcfill_u32 (__u32i __src)
{
  return (__u32i) __builtin_ia32_blcfill32 ((__src));
}
static __inline __u64i __attribute__((__always_inline__))
__blcfill_u64 (__u64i __src)
{
  return (__u64i) __builtin_ia32_blcfill64 ((__src));
}

/* blci */
static __inline __u32i __attribute__((__always_inline__))
__blci_u32 (__u32i __src)
{
  return (__u32i) __builtin_ia32_blci32 ((__src));
}

static __inline __u64i __attribute__((__always_inline__))
__blci_u64 (__u64i __src)
{
  return (__u64i) __builtin_ia32_blci64 ((__src));
}

/* blcic */
static __inline __u32i __attribute__((__always_inline__))
__blcic_u32 (__u32i __src)
{
  return (__u32i) __builtin_ia32_blcic32 ((__src));
}

static __inline __u64i __attribute__((__always_inline__))
__blcic_u64 (__u64i __src)
{
  return (__u64i) __builtin_ia32_blcic64 ((__src));
}
/* blcmsk */
static __inline __u32i __attribute__((__always_inline__))
__blcmsk_u32 (__u32i __src)
{
  return (__u32i) __builtin_ia32_blcmsk32 ((__src));
}

static __inline __u64i __attribute__((__always_inline__))
__blcmsk_u64 (__u64i __src)
{
  return (__u64i) __builtin_ia32_blcmsk64 ((__src));
}

/* blcs */
static __inline __u32i __attribute__((__always_inline__))
__blcs_u32 (__u32i __src)
{
  return (__u32i) __builtin_ia32_blcs32 ((__src));
}

static __inline __u64i __attribute__((__always_inline__))
__blcs_u64 (__u64i __src)
{
  return (__u64i) __builtin_ia32_blcs64 ((__src));
}

/* blsfill */
static __inline __u32i __attribute__((__always_inline__))
__blsfill_u32 (__u32i __src)
{
  return (__u32i) __builtin_ia32_blsfill32 ((__src));
}

static __inline __u64i __attribute__((__always_inline__))
__blsfill_u64 (__u64i __src)
{
  return (__u64i) __builtin_ia32_blsfill64 ((__src));
}

/* blsic */
static __inline __u32i __attribute__((__always_inline__))
__blsic_u32 (__u32i __src)
{
  return (__u32i) __builtin_ia32_blsic32 ((__src));
}

static __inline __u64i __attribute__((__always_inline__))
__blsic_u64 (__u64i __src)
{
  return (__u64i) __builtin_ia32_blsic64 ((__src));
}

/* t1mskc */
static __inline __u32i __attribute__((__always_inline__))
__t1mskc_u32 (__u32i __src)
{
  return (__u32i) __builtin_ia32_t1mskc32 ((__src));
}

static __inline __u64i __attribute__((__always_inline__))
__t1mskc_u64 (__u64i __src)
{
  return (__u64i) __builtin_ia32_t1mskc64 ((__src));
}

/* tzmsk */
static __inline __u32i __attribute__((__always_inline__))
__tzmsk_u32 (__u32i __src)
{
  return (__u32i) __builtin_ia32_tzmsk32 ((__src));
}

static __inline __u64i __attribute__((__always_inline__))
__tzmsk_u64 (__u64i __src)
{
  return (__u64i) __builtin_ia32_tzmsk64 ((__src));
}


 static __inline unsigned int __attribute__(( __always_inline__))
__bextri_u32 (unsigned int __X, const unsigned int __I)
{
        return __builtin_ia32_bextr32_imm (__X, __I);
}


 static __inline __u64i __attribute__(( __always_inline__))
__bextri_u64 (__u64i __X, const unsigned int __I)
{
        return __builtin_ia32_bextr64_imm (__X, __I);
}


/* BMI */
static __inline __u16i __attribute__((__always_inline__))
__tzcnt_u16 (__u16i __X)
{
   return  __builtin_ia32_tzcnt16(__X);
}

static __inline __u16i __attribute__((__always_inline__))
__lzcnt_u16 (__u16i __X)
{
   return  __builtin_ia32_lzcnt16(__X);
}

static __inline __u32i  __attribute__((__always_inline__))
__andn_u32 (__u32i __X, unsigned int __Y)
{
  return __builtin_ia32_andn32(__X, __Y);
}

static __inline __u32i __attribute__((__always_inline__))
__bextr_u32 (__u32i __X, unsigned int __Y)
{
  return __builtin_ia32_bextr32 (__X, __Y);
}

static __inline __u32i __attribute__((__always_inline__))
__blsi_u32 (__u32i __X)
{
  return __builtin_ia32_blsi32(__X);
}

static __inline __u32i __attribute__((__always_inline__))
__blsmsk_u32 (__u32i __X)
{
  return __builtin_ia32_blsmsk32(__X);
}

static __inline __u32i __attribute__((__always_inline__))
__blsr_u32 (__u32i __X)
{
  return __builtin_ia32_blsr32(__X);
}


static __inline __u32i __attribute__((__always_inline__))
__tzcnt_u32 (__u32i __X)
{
  return  __builtin_ia32_tzcnt32(__X);
}

static __inline __u32i  __attribute__((__always_inline__))
__lzcnt_u32 (__u32i __X)
{
  return  __builtin_ia32_lzcnt32(__X);
}


static __inline __u64i __attribute__((__always_inline__))
__andn_u64 ( __u64i __X, __u64i __Y)
{
  return __builtin_ia32_andn64(__X, __Y);
}


static __inline __u64i __attribute__((__always_inline__))
__bextr_u64 ( __u64i __X, __u32i __Y)
{
  return __builtin_ia32_bextr64 (__X, __Y);
}

static __inline __u64i __attribute__((__always_inline__))
__blsi_u64 ( __u64i __X)
{
  return __builtin_ia32_blsi64(__X);
}

static __inline __u64i __attribute__((__always_inline__))
__blsmsk_u64 ( __u64i __X)
{
  return __builtin_ia32_blsmsk64(__X);
}

static __inline __u64i __attribute__((__always_inline__))
__blsr_u64 ( __u64i __X)
{
  return __builtin_ia32_blsr64(__X);
}

static __inline __u64i __attribute__((__always_inline__))
__tzcnt_u64 ( __u64i __X)
{
  return __builtin_ia32_tzcnt64(__X);
}

static __inline __u64i __attribute__((__always_inline__))
__lzcnt_u64 (__u64i __X)
{
  return  __builtin_ia32_lzcnt64(__X);
}

#endif /* BMINTRIN_H_INCLUDED */

