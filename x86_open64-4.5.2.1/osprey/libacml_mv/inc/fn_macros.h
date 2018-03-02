#ifndef __FN_MACROS_H__
#define __FN_MACROS_H__






#if defined(WINDOWS)
#pragma warning( disable : 4985 )
#if defined(__COMP_REF__)
#define FN_PROTOTYPE(fn_name) fn_name
#elif defined(__NAG_REF__)
#define FN_PROTOTYPE(fn_name) amd_ref_##fn_name
#else
#define FN_PROTOTYPE(fn_name)  amd_##fn_name   // by default call  libm function
#endif
#else
#if defined(__COMP_REF__)
#define FN_PROTOTYPE(fn_name) fn_name
#elif defined(__NAG_REF__)
#define FN_PROTOTYPE(fn_name) amd_ref_##fn_name
#else
#define FN_PROTOTYPE(fn_name)  amd_##fn_name   // by default call  libm function
#endif
#endif

#if defined(AVX_XOP_FMA4)
#define FN_PROTOTYPE_BAS64(fn_name) __amd_bas64_##fn_name
#else
#define FN_PROTOTYPE_BAS64(fn_name) FN_PROTOTYPE(fn_name)
#endif


#define FN_PROTOTYPE_BDOZR(fn_name) __amd_bdozr_##fn_name

#if defined(WINDOWS)
#define weak_alias(name, aliasname) /* as nothing */
#else
/* Define ALIASNAME as a weak alias for NAME.
   If weak aliases are not available, this defines a strong alias.  */

#define weak_alias(aliasname, name)  _weak_alias (aliasname, name)  /* !!!!! REVISIT THIS SOON !!!!! */
#if 0 
#define _weak_alias(aliasname, name) extern __typeof (name) aliasname __attribute__ ((weak, alias (#name))); \
	extern __typeof (name) fast##aliasname __attribute__ ((weak, alias (#name)));
#endif
#define _weak_alias(aliasname, name) extern __typeof (name) fast##aliasname __attribute__ ((weak, alias (#name)));
#endif

#if defined(COMPILE_GAS)
#include "weak_macros.h"
#endif

#endif // __FN_MACROS_H__

