# 0 "src/u_hash.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4

# 1 "/usr/include/stdc-predef.h" 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */




/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */

/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
# 56 "/usr/include/stdc-predef.h" 3 4
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
# 0 "<command-line>" 2
# 1 "src/u_hash.c"

# 1 "src/u_hash.c"
/*This file is part of Revenant.

Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Revenant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */

# 1 "/home/anton/revenant/game/headers/u_hash.h" 1
/*This file is part of Revenant.

Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Revenant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */



# 1 "/usr/include/stdio.h" 1 3 4

# 1 "/usr/include/stdio.h" 3 4
/* Define ISO C stdio on top of C++ iostreams.
   Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.19 Input/output	<stdio.h>
 */





# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
/* Handle feature test macros at the start of a header.
   Copyright (C) 2016-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* This header is internal to glibc and should not be included outside
   of glibc headers.  Headers including it must define
   __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION first.  This header
   cannot have multiple include guards because ISO C feature test
   macros depend on the definition of the macro when an affected
   header is included, not when the first system header is
   included.  */







# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */




/* These are defined by the user (or the compiler)
   to specify the desired environment:

   __STRICT_ANSI__	ISO Standard C.
   _ISOC99_SOURCE	Extensions to ISO C89 from ISO C99.
   _ISOC11_SOURCE	Extensions to ISO C99 from ISO C11.
   _ISOC2X_SOURCE	Extensions to ISO C99 from ISO C2X.
   __STDC_WANT_LIB_EXT2__
			Extensions to ISO C99 from TR 27431-2:2010.
   __STDC_WANT_IEC_60559_BFP_EXT__
			Extensions to ISO C11 from TS 18661-1:2014.
   __STDC_WANT_IEC_60559_FUNCS_EXT__
			Extensions to ISO C11 from TS 18661-4:2015.
   __STDC_WANT_IEC_60559_TYPES_EXT__
			Extensions to ISO C11 from TS 18661-3:2015.
   __STDC_WANT_IEC_60559_EXT__
			ISO C2X interfaces defined only in Annex F.

   _POSIX_SOURCE	IEEE Std 1003.1.
   _POSIX_C_SOURCE	If ==1, like _POSIX_SOURCE; if >=2 add IEEE Std 1003.2;
			if >=199309L, add IEEE Std 1003.1b-1993;
			if >=199506L, add IEEE Std 1003.1c-1995;
			if >=200112L, all of IEEE 1003.1-2004
			if >=200809L, all of IEEE 1003.1-2008
   _XOPEN_SOURCE	Includes POSIX and XPG things.  Set to 500 if
			Single Unix conformance is wanted, to 600 for the
			sixth revision, to 700 for the seventh revision.
   _XOPEN_SOURCE_EXTENDED XPG things and X/Open Unix extensions.
   _LARGEFILE_SOURCE	Some more functions for correct standard I/O.
   _LARGEFILE64_SOURCE	Additional functionality from LFS for large files.
   _FILE_OFFSET_BITS=N	Select default filesystem interface.
   _ATFILE_SOURCE	Additional *at interfaces.
   _DYNAMIC_STACK_SIZE_SOURCE Select correct (but non compile-time constant)
			MINSIGSTKSZ, SIGSTKSZ and PTHREAD_STACK_MIN.
   _GNU_SOURCE		All of the above, plus GNU extensions.
   _DEFAULT_SOURCE	The default set of features (taking precedence over
			__STRICT_ANSI__).

   _FORTIFY_SOURCE	Add security hardening to many library functions.
			Set to 1 or 2; 2 performs stricter checks than 1.

   _REENTRANT, _THREAD_SAFE
			Obsolete; equivalent to _POSIX_C_SOURCE=199506L.

   The `-ansi' switch to the GNU C compiler, and standards conformance
   options such as `-std=c99', define __STRICT_ANSI__.  If none of
   these are defined, or if _DEFAULT_SOURCE is defined, the default is
   to have _POSIX_SOURCE set to one and _POSIX_C_SOURCE set to
   200809L, as well as enabling miscellaneous functions from BSD and
   SVID.  If more than one of these are defined, they accumulate.  For
   example __STRICT_ANSI__, _POSIX_SOURCE and _POSIX_C_SOURCE together
   give you ISO C, 1003.1, and 1003.2, but nothing else.

   These are defined by this file and are used by the
   header files to decide what to declare or define:

   __GLIBC_USE (F)	Define things from feature set F.  This is defined
			to 1 or 0; the subsequent macros are either defined
			or undefined, and those tests should be moved to
			__GLIBC_USE.
   __USE_ISOC11		Define ISO C11 things.
   __USE_ISOC99		Define ISO C99 things.
   __USE_ISOC95		Define ISO C90 AMD1 (C95) things.
   __USE_ISOCXX11	Define ISO C++11 things.
   __USE_POSIX		Define IEEE Std 1003.1 things.
   __USE_POSIX2		Define IEEE Std 1003.2 things.
   __USE_POSIX199309	Define IEEE Std 1003.1, and .1b things.
   __USE_POSIX199506	Define IEEE Std 1003.1, .1b, .1c and .1i things.
   __USE_XOPEN		Define XPG things.
   __USE_XOPEN_EXTENDED	Define X/Open Unix things.
   __USE_UNIX98		Define Single Unix V2 things.
   __USE_XOPEN2K        Define XPG6 things.
   __USE_XOPEN2KXSI     Define XPG6 XSI things.
   __USE_XOPEN2K8       Define XPG7 things.
   __USE_XOPEN2K8XSI    Define XPG7 XSI things.
   __USE_LARGEFILE	Define correct standard I/O things.
   __USE_LARGEFILE64	Define LFS things with separate names.
   __USE_FILE_OFFSET64	Define 64bit interface as default.
   __USE_MISC		Define things from 4.3BSD or System V Unix.
   __USE_ATFILE		Define *at interfaces and AT_* constants for them.
   __USE_DYNAMIC_STACK_SIZE Define correct (but non compile-time constant)
			MINSIGSTKSZ, SIGSTKSZ and PTHREAD_STACK_MIN.
   __USE_GNU		Define GNU extensions.
   __USE_FORTIFY_LEVEL	Additional security measures used, according to level.

   The macros `__GNU_LIBRARY__', `__GLIBC__', and `__GLIBC_MINOR__' are
   defined by this file unconditionally.  `__GNU_LIBRARY__' is provided
   only for compatibility.  All new code should use the other symbols
   to test for features.

   All macros listed above as possibly being defined by this file are
   explicitly undefined if they are not explicitly defined.
   Feature-test macros that are not defined by the user or compiler
   but are implied by the other feature-test macros defined (or by the
   lack of any definitions) are defined by the file.

   ISO C feature test macros depend on the definition of the macro
   when an affected header is included, not when the first system
   header is included, and so they are handled in
   <bits/libc-header-start.h>, which does not have a multiple include
   guard.  Feature test macros that can be handled from the first
   system header included are handled here.  */


/* Undefine everything, so we get a clean slate.  */
# 154 "/usr/include/features.h" 3 4
/* Suppress kernel-name space pollution unless user expressedly asks
   for it.  */




/* Convenience macro to test the version of gcc.
   Use like this:
   #if __GNUC_PREREQ (2,8)
   ... code requiring gcc 2.8 or later ...
   #endif
   Note: only works for GCC 2.0 and later, because __GNUC_MINOR__ was
   added in 2.0.  */







/* Similarly for clang.  Features added to GCC after version 4.2 may
   or may not also be available in clang, and clang's definitions of
   __GNUC(_MINOR)__ are fixed at 4 and 2 respectively.  Not all such
   features can be queried via __has_extension/__has_feature.  */







/* Whether to use feature set F.  */


/* _BSD_SOURCE and _SVID_SOURCE are deprecated aliases for
   _DEFAULT_SOURCE.  If _DEFAULT_SOURCE is present we do not
   issue a warning; the expectation is that the source is being
   transitioned to use the new macro.  */







/* If _GNU_SOURCE was defined by the user, turn on all the other features.  */
# 227 "/usr/include/features.h" 3 4
/* If nothing (other than _GNU_SOURCE and _DEFAULT_SOURCE) is defined,
   define _DEFAULT_SOURCE.  */
# 239 "/usr/include/features.h" 3 4
/* This is to enable the ISO C2X extension.  */







/* This is to enable the ISO C11 extension.  */





/* This is to enable the ISO C99 extension.  */






/* This is to enable the ISO C90 Amendment 1:1995 extension.  */
# 280 "/usr/include/features.h" 3 4
/* If none of the ANSI/POSIX macros are defined, or if _DEFAULT_SOURCE
   is defined, use POSIX.1-2008 (or another version depending on
   _XOPEN_SOURCE).  */
# 309 "/usr/include/features.h" 3 4
/* Some C libraries once required _REENTRANT and/or _THREAD_SAFE to be
   defined in all multithreaded code.  GNU libc has not required this
   for many years.  We now treat them as compatibility synonyms for
   _POSIX_C_SOURCE=199506L, which is the earliest level of POSIX with
   comprehensive support for multithreaded code.  Using them never
   lowers the selected level of POSIX conformance, only raises it.  */
# 392 "/usr/include/features.h" 3 4
# 1 "/usr/include/features-time64.h" 1 3 4
/* Features part to handle 64-bit time_t support.
   Copyright (C) 2021-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* We need to know the word size in order to check the time size.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
/* Determine the wordsize from the preprocessor defines.  */
# 13 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
/* Both x86-64 and x32 use the 64-bit system call interface.  */
# 21 "/usr/include/features-time64.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 1 3 4
/* Bit size of the time_t type at glibc build time, x86-64 and x32 case.
   Copyright (C) 2018-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
/* Determine the wordsize from the preprocessor defines.  */
# 13 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
/* Both x86-64 and x32 use the 64-bit system call interface.  */
# 20 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 2 3 4





/* For others, time size is word size.  */
# 22 "/usr/include/features-time64.h" 2 3 4
# 393 "/usr/include/features.h" 2 3 4
# 431 "/usr/include/features.h" 3 4
/* The function 'gets' existed in C89, but is impossible to use
   safely.  It has been removed from ISO C11 and ISO C++14.  Note: for
   compatibility with various implementations of <cstdio>, this test
   must consider only the value of __cplusplus when compiling C++.  */






/* GNU formerly extended the scanf functions with modified format
   specifiers %as, %aS, and %a[...] that allocate a buffer for the
   input using malloc.  This extension conflicts with ISO C99, which
   defines %a as a standalone format specifier that reads a floating-
   point number; moreover, POSIX.1-2008 provides the same feature
   using the modifier letter 'm' instead (%ms, %mS, %m[...]).

   We now follow C99 unless GNU extensions are active and the compiler
   is specifically in C89 or C++98 mode (strict or not).  For
   instance, with GCC, -std=gnu11 will have C99-compliant scanf with
   or without -D_GNU_SOURCE, but -std=c89 -D_GNU_SOURCE will have the
   old extension.  */
# 462 "/usr/include/features.h" 3 4
/* Get definitions of __STDC_* predefined macros, if the compiler has
   not preincluded this header automatically.  */
# 1 "/usr/include/stdc-predef.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 465 "/usr/include/features.h" 2 3 4

/* This macro indicates that the installed library is the GNU C Library.
   For historic reasons the value now is 6 and this will stay from now
   on.  The use of this variable is deprecated.  Use __GLIBC__ and
   __GLIBC_MINOR__ now (see below) when you want to test for a specific
   GNU C library version and use the values in <gnu/lib-names.h> to get
   the sonames of the shared libraries.  */



/* Major and minor version number of the GNU C library package.  Use
   these macros to test for features in specific releases.  */






/* This is here only because every header file already includes this one.  */


# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
/* Copyright (C) 1992-2022 Free Software Foundation, Inc.
   Copyright The GNU Toolchain Authors.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */




/* We are almost always included from features.h. */




/* The GNU libc does not support any K&R compilers or the traditional mode
   of ISO C compilers anymore.  Check for some of the combinations not
   supported anymore.  */




/* Some user header file might have defined this before.  */



/* Compilers that lack __has_attribute may object to
       #if defined __has_attribute && __has_attribute (...)
   even though they do not need to evaluate the right-hand side of the &&.
   Similarly for __has_builtin, etc.  */
# 62 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* All functions, except those with callbacks or those that
   synchronize memory, are leaf functions.  */
# 72 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* GCC can always grok prototypes.  For C++ programs we add throw()
   to help it optimize the function calls.  But this only works with
   gcc 2.8.x and egcs.  For gcc 3.4 and up we even mark C functions
   as non-throwing using a function attribute since programs can use
   the -fexceptions options for C code as well.  */
# 116 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* These two macros are not used in glibc anymore.  They are kept here
   only because some other projects expect the macros to be defined.  */



/* For these things, GCC behaves the ANSI way normally,
   and the non-ANSI way under -traditional.  */




/* This is not a typedef so `const __ptr_t' does the right thing.  */



/* C++ needs to know that types and declarations are C, not C++.  */
# 141 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* Fortify support.  */



/* Use __builtin_dynamic_object_size at _FORTIFY_SOURCE=3 when available.  */
# 155 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* Compile time conditions to choose between the regular, _chk and _chk_warn
   variants.  These conditions should get evaluated to constant and optimized
   away.  */






/* Length is known to be safe at compile time if the __L * __S <= __OBJSZ
   condition can be folded to a constant and if it is true.  The -1 check is
   redundant because since it implies that __glibc_safe_len_cond is true.  */






/* Conversely, we know at compile time that the length is unsafe if the
   __L * __S <= __OBJSZ condition can be folded to a constant and if it is
   false.  */






/* Fortify function f.  __f_alias, __f_chk and __f_chk_warn must be
   declared.  */
# 192 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* Fortify function f, where object size argument passed to f is the number of
   elements and not total size.  */
# 211 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* Support for flexible arrays.
   Headers that should use flexible arrays only if they're "real"
   (e.g. only if they won't affect sizeof()) should test
   #if __glibc_c99_flexarr_available.  */
# 235 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* __asm__ ("xyz") is used throughout the headers to rename functions
   at the assembly language level.  This is wrapped by the __REDIRECT
   macro, in order to support compilers that can do this some other
   way.  When compilers don't support asm-names at all, we have to do
   preprocessor tricks instead (which don't have exactly the right
   semantics, but it's the best we can do).

   Example:
   int __REDIRECT(setpgrp, (__pid_t pid, __pid_t pgrp), setpgid); */
# 262 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/*
#elif __SOME_OTHER_COMPILER__

# define __REDIRECT(name, proto, alias) name proto; 	_Pragma("let " #name " = " #alias)
)
*/


/* GCC and clang have various useful declarations that can be made with
   the '__attribute__' syntax.  All of the ways we use this do fine if
   they are omitted for compilers that don't understand it.  */




/* At some point during the gcc 2.96 development the `malloc' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.  */






/* Tell the compiler which arguments to an allocation function
   indicate the size of the allocation.  */







/* Tell the compiler which argument to an allocation function
   indicates the alignment of the allocation.  */







/* At some point during the gcc 2.96 development the `pure' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.  */






/* This declaration tells the compiler that the value is constant.  */
# 326 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* At some point during the gcc 3.1 development the `used' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.  */
# 337 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* Since version 3.2, gcc allows marking deprecated functions.  */






/* Since version 4.5, gcc also allows one to specify the message printed
   when a deprecated function is used.  clang claims to be gcc 4.2, but
   may also support this feature.  */
# 355 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* At some point during the gcc 2.8 development the `format_arg' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.
   If several `format_arg' attributes are given for the same function, in
   gcc-3.0 and older, all but the last one are ignored.  In newer gccs,
   all designated arguments are considered.  */






/* At some point during the gcc 2.97 development the `strfmon' format
   attribute for functions was introduced.  We don't want to use it
   unconditionally (although this would be possible) since it
   generates warnings.  */







/* The nonnull function attribute marks pointer parameters that
   must not be NULL.  This has the name __nonnull in glibc,
   and __attribute_nonnull__ in files shared with Gnulib to avoid
   collision with a different __nonnull in DragonFlyBSD 5.9.  */
# 393 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* The returns_nonnull function attribute marks the return type of the function
   as always being non-null.  */
# 403 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* If fortification mode, we warn about unused results of certain
   function calls which can lead to problems.  */
# 418 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* Forces a function to be always inlined.  */

/* The Linux kernel defines __always_inline in stddef.h (283d7573), and
   it conflicts with this definition.  Therefore undefine it first to
   allow either header to be included first.  */







/* Associate error messages with the source location of the call site rather
   than with the source location inside the function.  */






/* GCC 4.3 and above with -std=c99 or -std=gnu99 implements ISO C99
   inline semantics, unless -fgnu89-inline is used.  Using __GNUC_STDC_INLINE__
   or __GNUC_GNU_INLINE is not a good enough check for gcc because gcc versions
   older than 4.3 may define these macros and still not guarantee GNU inlining
   semantics.

   clang++ identifies itself as gcc-4.2, but has support for GNU inlining
   semantics, that can be checked for by using the __GNUC_STDC_INLINE_ and
   __GNUC_GNU_INLINE__ macro definitions.  */
# 464 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* GCC 4.3 and above allow passing all anonymous arguments of an
   __extern_always_inline function to some other vararg function.  */





/* It is possible to compile containing GCC extensions even if GCC is
   run in pedantic mode if the uses are carefully marked using the
   `__extension__' keyword.  But this is not generally available before
   version 2.8.  */




/* __restrict is known in EGCS 1.2 and above, and in clang.
   It works also in C++ mode (outside of arrays), but only when spelled
   as '__restrict', not 'restrict'.  */
# 490 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* ISO C99 also allows to declare arrays as non-overlapping.  The syntax is
     array_name[restrict]
   GCC 3.1 and clang support this.
   This syntax is not usable in C++ mode.  */
# 529 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* Describes a char array whose address can safely be passed as the first
   argument to strncpy and strncat, as the char array is not necessarily
   a NUL-terminated string.  */





/* Undefine (also defined in libc-symbols.h).  */


/* Copies attributes from the declaration or type referenced by
   the argument.  */
# 556 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* Gnulib avoids including these, as they don't work on non-glibc or
   older glibc platforms.  */

# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
/* Determine the wordsize from the preprocessor defines.  */
# 13 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
/* Both x86-64 and x32 use the 64-bit system call interface.  */
# 560 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
/* Properties of long double type.  ldbl-96 version.
   Copyright (C) 2016-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License  published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* long double is distinct from double, so there is nothing to
   define here.  */
# 561 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 629 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* __glibc_macro_warning (MESSAGE) issues warning MESSAGE.  This is
   intended for use in preprocessor macros.

   Note: MESSAGE must be a _single_ string; concatenation of string
   literals is not supported.  */
# 642 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* Generic selection (ISO C11) is a C-only feature, available in GCC
   since version 4.9.  Previous versions do not provide generic
   selection, even though they might set __STDC_VERSION__ to 201112L,
   when in -std=c11 mode.  Thus, we must check for !defined __GNUC__
   when testing __STDC_VERSION__ for generic selection support.
   On the other hand, Clang also defines __GNUC__, so a clang-specific
   check is required to enable the use of generic selection.  */
# 660 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* Designates a 1-based positional argument ref-index of pointer type
   that can be used to access size-index elements of the pointed-to
   array according to access mode, or at least one element when
   size-index is not provided:
     access (access-mode, <ref-index> [, <size-index>])  */

/* For _FORTIFY_SOURCE == 3 we use __builtin_dynamic_object_size, which may
   use the access attribute to get object sizes from function definition
   arguments, so we can't use them on functions we fortify.  Drop the object
   size hints for such functions.  */
# 687 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* Designates dealloc as a function to call to deallocate objects
   allocated by the declared function.  */
# 697 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* Specify that a function such as setjmp or vfork may return
   twice.  */
# 487 "/usr/include/features.h" 2 3 4


/* If we don't have __REDIRECT, prototypes will be missing if
   __USE_FILE_OFFSET64 but not __USE_LARGEFILE[64]. */







/* Decide whether we can define 'extern inline' functions in headers.  */







/* This is here only because every header file already includes this one.
   Get the definitions of all the appropriate `__stub_FUNCTION' symbols.
   <gnu/stubs.h> contains `#define __stub_FUNCTION' when FUNCTION is a stub
   that will always return failure (and set errno to ENOSYS).  */
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
/* This file is automatically generated.
   This file selects the right generated file of `__stub_FUNCTION' macros
   based on the architecture being compiled for.  */






# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
/* This file is automatically generated.
   It defines a symbol `__stub_FUNCTION' for each function
   in the C library which is a stub, meaning it will fail
   every time called, usually setting errno to ENOSYS.  */
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 511 "/usr/include/features.h" 2 3 4
# 34 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 2 3 4

/* ISO/IEC TR 24731-2:2010 defines the __STDC_WANT_LIB_EXT2__
   macro.  */
# 45 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
/* ISO/IEC TS 18661-1:2014 defines the __STDC_WANT_IEC_60559_BFP_EXT__
   macro.  Most but not all symbols enabled by that macro in TS
   18661-1 are enabled unconditionally in C2X.  In C2X, the symbols in
   Annex F still require a new feature test macro
   __STDC_WANT_IEC_60559_EXT__ instead (C2X does not define
   __STDC_WANT_IEC_60559_BFP_EXT__), while a few features from TS
   18661-1 are not included in C2X (and thus should depend on
   __STDC_WANT_IEC_60559_BFP_EXT__ even when C2X features are
   enabled).

   __GLIBC_USE (IEC_60559_BFP_EXT) controls those features from TS
   18661-1 not included in C2X.

   __GLIBC_USE (IEC_60559_BFP_EXT_C2X) controls those features from TS
   18661-1 that are also included in C2X (with no feature test macro
   required in C2X).

   __GLIBC_USE (IEC_60559_EXT) controls those features from TS 18661-1
   that are included in C2X but conditional on
   __STDC_WANT_IEC_60559_EXT__.  (There are currently no features
   conditional on __STDC_WANT_IEC_60559_EXT__ that are not in TS
   18661-1.)  */
# 86 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
/* ISO/IEC TS 18661-4:2015 defines the
   __STDC_WANT_IEC_60559_FUNCS_EXT__ macro.  Other than the reduction
   functions, the symbols from this TS are enabled unconditionally in
   C2X.  */
# 103 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
/* ISO/IEC TS 18661-3:2015 defines the
   __STDC_WANT_IEC_60559_TYPES_EXT__ macro.  */
# 28 "/usr/include/stdio.h" 2 3 4





# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 1 3 4
/* Copyright (C) 1989-2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */






/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */
# 46 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */
# 86 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 111 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 159 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 209 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 235 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 387 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* A null pointer constant.  */
# 34 "/usr/include/stdio.h" 2 3 4


# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stdarg.h" 1 3 4
/* Copyright (C) 1989-2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.15  Variable arguments  <stdarg.h>
 */
# 36 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stdarg.h" 3 4
/* Define __gnuc_va_list.  */



typedef __builtin_va_list __gnuc_va_list;


/* Define the standard macros for the user,
   if this invocation was from the user program.  */
# 37 "/usr/include/stdio.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */




# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 27 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
/* Determine the wordsize from the preprocessor defines.  */
# 13 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
/* Both x86-64 and x32 use the 64-bit system call interface.  */
# 28 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 1 3 4
/* Bit size of the time_t type at glibc build time, x86-64 and x32 case.
   Copyright (C) 2018-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
/* Determine the wordsize from the preprocessor defines.  */
# 13 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
/* Both x86-64 and x32 use the 64-bit system call interface.  */
# 20 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 2 3 4





/* For others, time size is word size.  */
# 29 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4

/* Convenience types.  */
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;

/* Fixed-size types, underlying types depend on word size and compiler.  */
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;





/* Smallest types with at least a given width.  */
typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;

/* quad_t is also 64 bits.  */

typedef long int __quad_t;
typedef unsigned long int __u_quad_t;





/* Largest integral types.  */

typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;






/* The machine-dependent file <bits/typesizes.h> defines __*_T_TYPE
   macros for each of the OS types we define below.  The definitions
   of those macros must use the following macros for underlying types.
   We define __S<SIZE>_TYPE and __U<SIZE>_TYPE for the signed and unsigned
   variants of each of the following integer types on this machine.

	16		-- "natural" 16-bit type (always short)
	32		-- "natural" 32-bit type (always int)
	64		-- "natural" 64-bit type (long or long long)
	LONG32		-- 32-bit type, traditionally long
	QUAD		-- 64-bit type, traditionally long long
	WORD		-- natural type of __WORDSIZE bits (int or long)
	LONGWORD	-- type of __WORDSIZE bits, traditionally long

   We distinguish WORD/LONGWORD, 32/LONG32, and 64/QUAD so that the
   conventional uses of `long' or `long long' type modifiers match the
   types we define, even when a less-adorned type would be the same size.
   This matters for (somewhat) portably writing printf/scanf formats for
   these types, where using the appropriate l or ll format modifiers can
   make the typedefs and the formats match up across all GNU platforms.  If
   we used `long' when it's 64 bits where `long long' is expected, then the
   compiler would warn about the formats not matching the argument types,
   and the programmer changing them to shut up the compiler would break the
   program's portability.

   Here we assume what is presently the case in all the GCC configurations
   we support: long long is always 64 bits, long is always word/address size,
   and int is always 32 bits.  */
# 136 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
/* No need to mark the typedef with __extension__.   */




# 1 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 1 3 4
/* bits/typesizes.h -- underlying types for *_t.  Linux/x86-64 version.
   Copyright (C) 2012-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 26 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 3 4
/* See <bits/types.h> for the meaning of these macros.  This file exists so
   that <bits/types.h> need not vary across different GNU platforms.  */

/* X32 kernel interface is 64-bit.  */
# 78 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 3 4
/* Tell the libc code that off_t and off64_t are actually the same type
   for all ABI purposes, even if possibly expressed as different base types
   for C type-checking purposes.  */


/* Same for ino_t and ino64_t.  */


/* And for __rlim_t and __rlim64_t.  */


/* And for fsblkcnt_t, fsblkcnt64_t, fsfilcnt_t and fsfilcnt64_t.  */


/* And for getitimer, setitimer and rusage  */
# 102 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 3 4
/* Number of descriptors that can fit in an `fd_set'.  */
# 142 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/time64.h" 1 3 4
/* bits/time64.h -- underlying types for __time64_t.  Generic version.
   Copyright (C) 2018-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 26 "/usr/include/x86_64-linux-gnu/bits/time64.h" 3 4
/* Define __TIME64_T_TYPE so that it is always a 64-bit type.  */


/* If we already have 64-bit time type then use it.  */
# 143 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


typedef unsigned long int __dev_t; /* Type of device numbers.  */
typedef unsigned int __uid_t; /* Type of user identifications.  */
typedef unsigned int __gid_t; /* Type of group identifications.  */
typedef unsigned long int __ino_t; /* Type of file serial numbers.  */
typedef unsigned long int __ino64_t; /* Type of file serial numbers (LFS).*/
typedef unsigned int __mode_t; /* Type of file attribute bitmasks.  */
typedef unsigned long int __nlink_t; /* Type of file link counts.  */
typedef long int __off_t; /* Type of file sizes and offsets.  */
typedef long int __off64_t; /* Type of file sizes and offsets (LFS).  */
typedef int __pid_t; /* Type of process identifications.  */
typedef struct { int __val[2]; } __fsid_t; /* Type of file system IDs.  */
typedef long int __clock_t; /* Type of CPU usage counts.  */
typedef unsigned long int __rlim_t; /* Type for resource measurement.  */
typedef unsigned long int __rlim64_t; /* Type for resource measurement (LFS).  */
typedef unsigned int __id_t; /* General type for IDs.  */
typedef long int __time_t; /* Seconds since the Epoch.  */
typedef unsigned int __useconds_t; /* Count of microseconds.  */
typedef long int __suseconds_t; /* Signed count of microseconds.  */
typedef long int __suseconds64_t;

typedef int __daddr_t; /* The type of a disk address.  */
typedef int __key_t; /* Type of an IPC key.  */

/* Clock ID used in clock and timer functions.  */
typedef int __clockid_t;

/* Timer ID returned by `timer_create'.  */
typedef void * __timer_t;

/* Type to represent block size.  */
typedef long int __blksize_t;

/* Types from the Large File Support interface.  */

/* Type to count number of disk blocks.  */
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;

/* Type to count file system blocks.  */
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;

/* Type to count file system nodes.  */
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;

/* Type of miscellaneous file system fields.  */
typedef long int __fsword_t;

typedef long int __ssize_t; /* Type of a byte count, or error.  */

/* Signed long type used in system calls.  */
typedef long int __syscall_slong_t;
/* Unsigned long type used in system calls.  */
typedef unsigned long int __syscall_ulong_t;

/* These few don't really vary by system, they always correspond
   to one of the other defined types.  */
typedef __off64_t __loff_t; /* Type of file sizes and offsets (LFS).  */
typedef char *__caddr_t;

/* Duplicates info from stdint.h but this is used in unistd.h.  */
typedef long int __intptr_t;

/* Duplicate info from sys/socket.h.  */
typedef unsigned int __socklen_t;

/* C99: An integer type that can be accessed as an atomic entity,
   even in the presence of asynchronous interrupts.
   It is not currently necessary for this to be machine-specific.  */
typedef int __sig_atomic_t;

/* Seconds since the Epoch, visible to user code when time_t is too
   narrow only for consistency with the old way of widening too-narrow
   types.  User code should never use __time64_t.  */
# 39 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h" 1 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 5 "/usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h" 1 3 4



/* Integral type unchanged by default argument promotions that can
   hold any value corresponding to members of the extended character
   set, as well as at least one value that does not correspond to any
   member of the extended character set.  */




/* Conversion state information.  */
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value; /* Value so far.  */
} __mbstate_t;
# 6 "/usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h" 2 3 4

/* The tag name of this struct is _G_fpos_t to preserve historic
   C++ mangled names for functions taking fpos_t arguments.
   That name should not be used in new code.  */
typedef struct _G_fpos_t
{
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
# 40 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h" 1 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 5 "/usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h" 2 3 4


/* The tag name of this struct is _G_fpos64_t to preserve historic
   C++ mangled names for functions taking fpos_t and/or fpos64_t
   arguments.  That name should not be used in new code.  */
typedef struct _G_fpos64_t
{
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;
# 41 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__FILE.h" 1 3 4



struct _IO_FILE;
typedef struct _IO_FILE __FILE;
# 42 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h" 1 3 4



struct _IO_FILE;

/* The opaque type of streams.  This is the definition used elsewhere.  */
typedef struct _IO_FILE FILE;
# 43 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */




/* Caution: The contents of this file are not part of the official
   stdio.h API.  However, much of it is part of the official *binary*
   interface, and therefore cannot be changed.  */
# 33 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 34 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 2 3 4

struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;

/* During the build of glibc itself, _IO_lock_t will already have been
   defined by internal headers.  */

typedef void _IO_lock_t;


/* The tag name of this struct is _IO_FILE to preserve historic
   C++ mangled names for functions taking FILE* arguments.
   That name should not be used in new code.  */
struct _IO_FILE
{
  int _flags; /* High-order word is _IO_MAGIC; rest is flags. */

  /* The following pointers correspond to the C++ streambuf protocol. */
  char *_IO_read_ptr; /* Current read pointer */
  char *_IO_read_end; /* End of get area. */
  char *_IO_read_base; /* Start of putback+get area. */
  char *_IO_write_base; /* Start of put area. */
  char *_IO_write_ptr; /* Current put pointer. */
  char *_IO_write_end; /* End of put area. */
  char *_IO_buf_base; /* Start of reserve area. */
  char *_IO_buf_end; /* End of reserve area. */

  /* The following fields are used to support backing up and undo. */
  char *_IO_save_base; /* Pointer to start of non-current get area. */
  char *_IO_backup_base; /* Pointer to first valid character of backup area */
  char *_IO_save_end; /* Pointer to end of non-current get area. */

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;
  int _flags2;
  __off_t _old_offset; /* This used to be _offset but it's too small.  */

  /* 1+column number of pbase(); 0 is unknown. */
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];

  _IO_lock_t *_lock;







  __off64_t _offset;
  /* Wide character stream stuff.  */
  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  size_t __pad5;
  int _mode;
  /* Make sure we don't get into trouble again.  */
  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};

/* These macros are used by bits/stdio.h and internal headers.  */
# 118 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3 4
/* Many more flag bits are defined internally.  */
# 44 "/usr/include/stdio.h" 2 3 4
# 52 "/usr/include/stdio.h" 3 4
typedef __gnuc_va_list va_list;
# 63 "/usr/include/stdio.h" 3 4
typedef __off_t off_t;
# 77 "/usr/include/stdio.h" 3 4
typedef __ssize_t ssize_t;




/* The type of the second argument to `fgetpos' and `fsetpos'.  */

typedef __fpos_t fpos_t;







/* The possibilities for the third argument to `setvbuf'.  */





/* Default buffer size.  */



/* The value returned by fgetc and similar functions to indicate the
   end of the file.  */



/* The possibilities for the third argument to `fseek'.
   These values should not be changed.  */
# 119 "/usr/include/stdio.h" 3 4
/* Default path prefix for `tempnam' and `tmpnam'.  */




/* Get the values:
   L_tmpnam	How long an array of chars must be to be passed to `tmpnam'.
   TMP_MAX	The minimum number of unique filenames generated by tmpnam
		(and tempnam when it uses tmpnam's name space),
		or tempnam (the two are separate).
   L_ctermid	How long an array to pass to `ctermid'.
   L_cuserid	How long an array to pass to `cuserid'.
   FOPEN_MAX	Minimum number of files that can be open at once.
   FILENAME_MAX	Maximum length of a filename.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/stdio_lim.h" 1 3 4
/* Copyright (C) 1994-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 134 "/usr/include/stdio.h" 2 3 4
# 142 "/usr/include/stdio.h" 3 4
/* Standard streams.  */
extern FILE *stdin; /* Standard input stream.  */
extern FILE *stdout; /* Standard output stream.  */
extern FILE *stderr; /* Standard error output stream.  */
/* C89/C99 say they're macros.  Make them happy.  */




/* Remove file FILENAME.  */
extern int remove (const char *__filename) __attribute__ ((__nothrow__ , __leaf__));
/* Rename file OLD to NEW.  */
extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__ , __leaf__));


/* Rename file OLD relative to OLDFD to NEW relative to NEWFD.  */
extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) __attribute__ ((__nothrow__ , __leaf__));
# 174 "/usr/include/stdio.h" 3 4
/* Close STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fclose (FILE *__stream);




/* Create a temporary file and open it read/write.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */

extern FILE *tmpfile (void)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
# 204 "/usr/include/stdio.h" 3 4
/* Generate a temporary filename.  */
extern char *tmpnam (char[20]) __attribute__ ((__nothrow__ , __leaf__)) ;


/* This is the reentrant variant of `tmpnam'.  The only difference is
   that it does not allow S to be NULL.  */
extern char *tmpnam_r (char __s[20]) __attribute__ ((__nothrow__ , __leaf__)) ;




/* Generate a unique temporary filename using up to five characters of PFX
   if it is not NULL.  The directory to put this file in is searched for
   as follows: First the environment variable "TMPDIR" is checked.
   If it contains the name of a writable directory, that directory is used.
   If not and if DIR is not NULL, that value is checked.  If that fails,
   P_tmpdir is tried and finally "/tmp".  The storage for the filename
   is allocated by `malloc'.  */
extern char *tempnam (const char *__dir, const char *__pfx)
   __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (__builtin_free, 1)));


/* Flush STREAM, or all streams if STREAM is NULL.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fflush (FILE *__stream);


/* Faster versions when locking is not required.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern int fflush_unlocked (FILE *__stream);
# 254 "/usr/include/stdio.h" 3 4
/* Open a file and create a new stream for it.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
/* Open a file, replacing an existing stream with it.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) ;
# 292 "/usr/include/stdio.h" 3 4
/* Create a new stream that refers to an existing system file descriptor.  */
extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
# 307 "/usr/include/stdio.h" 3 4
/* Create a new stream that refers to a memory buffer.  */
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;

/* Open a stream that writes into a malloc'd buffer that is expanded as
   necessary.  *BUFLOC and *SIZELOC are updated with the buffer's location
   and the number of characters written on fflush or fclose.  */
extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
# 326 "/usr/include/stdio.h" 3 4
/* If BUF is NULL, make STREAM unbuffered.
   Else make it use buffer BUF, of size BUFSIZ.  */
extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
/* Make STREAM use buffering mode MODE.
   If BUF is not NULL, use N bytes of it for buffering;
   else allocate an internal buffer N bytes long.  */
extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__ , __leaf__));


/* If BUF is NULL, make STREAM unbuffered.
   Else make it use SIZE bytes of BUF for buffering.  */
extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__ , __leaf__));

/* Make STREAM line-buffered.  */
extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));



/* Write formatted output to STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...);
/* Write formatted output to stdout.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int printf (const char *__restrict __format, ...);
/* Write formatted output to S.  */
extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) __attribute__ ((__nothrow__));

/* Write formatted output to S from argument list ARG.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg);
/* Write formatted output to stdout from argument list ARG.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);
/* Write formatted output to S from argument list ARG.  */
extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));


/* Maximum chars of output to write in MAXLEN.  */
extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));
# 402 "/usr/include/stdio.h" 3 4
/* Write formatted output to a file descriptor.  */
extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));



/* Read formatted input from STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) ;
/* Read formatted input from stdin.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int scanf (const char *__restrict __format, ...) ;
/* Read formatted input from S.  */
extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) __attribute__ ((__nothrow__ , __leaf__));

/* For historical reasons, the C99-compliant versions of the scanf
   functions are at alternative names.  When __LDBL_COMPAT or
   __LDOUBLE_REDIRECTS_TO_FLOAT128_ABI are in effect, this is handled in
   bits/stdio-ldbl.h.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 1 3 4
/* Macros to control TS 18661-3 glibc features on x86.
   Copyright (C) 2017-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */




# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 23 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 2 3 4

/* Defined to 1 if the current compiler invocation provides a
   floating-point type with the IEEE 754 binary128 format, and this
   glibc includes corresponding *f128 interfaces for it.  The required
   libgcc support was added some time after the basic compiler
   support, for x86_64 and x86.  */
# 37 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
/* Defined to 1 if __HAVE_FLOAT128 is 1 and the type is ABI-distinct
   from the default float, double and long double types in this glibc.  */






/* Defined to 1 if the current compiler invocation provides a
   floating-point type with the right format for _Float64x, and this
   glibc includes corresponding *f64x interfaces for it.  */


/* Defined to 1 if __HAVE_FLOAT64X is 1 and _Float64x has the format
   of long double.  Otherwise, if __HAVE_FLOAT64X is 1, _Float64x has
   the format of _Float128, which must be different from that of long
   double.  */




/* Defined to concatenate the literal suffix to be used with _Float128
   types, if __HAVE_FLOAT128 is 1. */
# 69 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
/* Defined to a complex binary128 type if __HAVE_FLOAT128 is 1.  */
# 81 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
/* The remaining of this file provides support for older compilers.  */


/* The type _Float128 exists only since GCC 7.0.  */




/* __builtin_huge_valf128 doesn't exist before GCC 7.0.  */




/* Older GCC has only a subset of built-in functions for _Float128 on
   x86, and __builtin_infq is not usable in static initializers.
   Converting a narrower sNaN to _Float128 produces a quiet NaN, so
   attempts to use _Float128 sNaNs will not work properly with older
   compilers.  */
# 107 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
/* In math/math.h, __MATH_TG will expand signbit to __builtin_signbit*,
   e.g.: __builtin_signbitf128, before GCC 6.  However, there has never
   been a __builtin_signbitf128 in GCC and the type-generic builtin is
   only available since GCC 6.  */
# 119 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 1 3 4
/* Macros to control TS 18661-3 glibc features where the same
   definitions are appropriate for all platforms.
   Copyright (C) 2017-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */




# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 24 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
/* Properties of long double type.  ldbl-96 version.
   Copyright (C) 2016-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License  published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* long double is distinct from double, so there is nothing to
   define here.  */
# 25 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 2 3 4

/* This header should be included at the bottom of each bits/floatn.h.
   It defines the following macros for each _FloatN and _FloatNx type,
   where the same definitions, or definitions based only on the macros
   in bits/floatn.h, are appropriate for all glibc configurations.  */

/* Defined to 1 if the current compiler invocation provides a
   floating-point type with the right format for this type, and this
   glibc includes corresponding *fN or *fNx interfaces for it.  */






/* Defined to 1 if the corresponding __HAVE_<type> macro is 1 and the
   type is the first with its format in the sequence of (the default
   choices for) float, double, long double, _Float16, _Float32,
   _Float64, _Float128, _Float32x, _Float64x, _Float128x for this
   glibc; that is, if functions present once per floating-point format
   rather than once per type are present for this type.

   All configurations supported by glibc have _Float32 the same format
   as float, _Float64 and _Float32x the same format as double, the
   _Float64x the same format as either long double or _Float128.  No
   configurations support _Float128x or, as of GCC 7, have compiler
   support for a type meeting the requirements for _Float128x.  */







/* Defined to 1 if the corresponding _FloatN type is not binary compatible
   with the corresponding ISO C type in the current compilation unit as
   opposed to __HAVE_DISTINCT_FLOATN, which indicates the default types built
   in glibc.  */



/* Defined to 1 if any _FloatN or _FloatNx types that are not
   ABI-distinct are however distinct types at the C language level (so
   for the purposes of __builtin_types_compatible_p and _Generic).  */
# 77 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
/* Defined to concatenate the literal suffix to be used with _FloatN
   or _FloatNx types, if __HAVE_<type> is 1.  The corresponding
   literal suffixes exist since GCC 7, for C only.  */
# 137 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
/* Defined to a complex type if __HAVE_<type> is 1.  */
# 195 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
/* The remaining of this file provides support for older compilers.  */
# 228 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
/* If double, long double and _Float64 all have the same set of
   values, TS 18661-3 requires the usual arithmetic conversions on
   long double and _Float64 to produce _Float64.  For this to be the
   case when building with a compiler without a distinct _Float64
   type, _Float64 must be a typedef for long double, not for
   double.  */
# 120 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 2 3 4
# 431 "/usr/include/stdio.h" 2 3 4



extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf")

                               ;
extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf")
                              ;
extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__ , __leaf__))

                      ;
# 455 "/usr/include/stdio.h" 3 4
/* Read formatted input from S into argument list ARG.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;

/* Read formatted input from stdin into argument list ARG.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;

/* Read formatted input from S into argument list ARG.  */
extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format__ (__scanf__, 2, 0)));

/* Same redirection as above for the v*scanf family.  */



extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")



     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")

     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__ , __leaf__))



     __attribute__ ((__format__ (__scanf__, 2, 0)));
# 509 "/usr/include/stdio.h" 3 4
/* Read a character from STREAM.

   These functions are possible cancellation points and therefore not
   marked with __THROW.  */
extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);

/* Read a character from stdin.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int getchar (void);


/* These are defined in POSIX.1:1996.

   These functions are possible cancellation points and therefore not
   marked with __THROW.  */
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);



/* Faster version when locking is not necessary.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern int fgetc_unlocked (FILE *__stream);



/* Write a character to STREAM.

   These functions are possible cancellation points and therefore not
   marked with __THROW.

   These functions is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);

/* Write a character to stdout.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int putchar (int __c);


/* Faster version when locking is not necessary.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern int fputc_unlocked (int __c, FILE *__stream);



/* These are defined in POSIX.1:1996.

   These functions are possible cancellation points and therefore not
   marked with __THROW.  */
extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);





/* Get a word (int) from STREAM.  */
extern int getw (FILE *__stream);

/* Write a word (int) to STREAM.  */
extern int putw (int __w, FILE *__stream);



/* Get a newline-terminated string of finite length from STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     __attribute__ ((__access__ (__write_only__, 1, 2)));
# 622 "/usr/include/stdio.h" 3 4
/* Read up to (and including) a DELIMITER from STREAM into *LINEPTR
   (and null-terminate it). *LINEPTR is a pointer returned from malloc (or
   NULL), pointing to *N characters of space.  It is realloc'd as
   necessary.  Returns the number of characters read (not including the
   null terminator), or -1 on error or EOF.

   These functions are not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation they are cancellation points and
   therefore not marked with __THROW.  */
extern __ssize_t __getdelim (char **__restrict __lineptr,
                             size_t *__restrict __n, int __delimiter,
                             FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
                           size_t *__restrict __n, int __delimiter,
                           FILE *__restrict __stream) ;

/* Like `getdelim', but reads up to a newline.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern __ssize_t getline (char **__restrict __lineptr,
                          size_t *__restrict __n,
                          FILE *__restrict __stream) ;



/* Write a string to STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fputs (const char *__restrict __s, FILE *__restrict __stream);

/* Write a string, followed by a newline, to stdout.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int puts (const char *__s);


/* Push a character back onto the input buffer of STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int ungetc (int __c, FILE *__stream);


/* Read chunks of generic data from STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;
/* Write chunks of generic data to STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);
# 696 "/usr/include/stdio.h" 3 4
/* Faster versions when locking is not necessary.

   These functions are not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation they are cancellation points and
   therefore not marked with __THROW.  */
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);



/* Seek to a certain position on STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fseek (FILE *__stream, long int __off, int __whence);
/* Return the current position of STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern long int ftell (FILE *__stream) ;
/* Rewind to the beginning of STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern void rewind (FILE *__stream);

/* The Single Unix Specification, Version 2, specifies an alternative,
   more adequate interface for the two functions above which deal with
   file offset.  `long int' is not the right type.  These definitions
   are originally defined in the Large File Support API.  */



/* Seek to a certain position on STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fseeko (FILE *__stream, __off_t __off, int __whence);
/* Return the current position of STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern __off_t ftello (FILE *__stream) ;
# 756 "/usr/include/stdio.h" 3 4
/* Get STREAM's position.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);
/* Set STREAM's position.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fsetpos (FILE *__stream, const fpos_t *__pos);
# 785 "/usr/include/stdio.h" 3 4
/* Clear the error and EOF indicators for STREAM.  */
extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
/* Return the EOF indicator for STREAM.  */
extern int feof (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
/* Return the error indicator for STREAM.  */
extern int ferror (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;


/* Faster versions when locking is not required.  */
extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;



/* Print a message describing the meaning of the value of errno.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern void perror (const char *__s);



/* Return the system file descriptor for STREAM.  */
extern int fileno (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;



/* Faster version when locking is not required.  */
extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;




/* Close a stream opened by popen and return the status of its child.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int pclose (FILE *__stream);

/* Create a new stream connected to a pipe running the given command.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern FILE *popen (const char *__command, const char *__modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (pclose, 1))) ;





/* Return the name of the controlling terminal.  */
extern char *ctermid (char *__s) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 1)));
# 864 "/usr/include/stdio.h" 3 4
/* These are defined in POSIX.1:1996.  */

/* Acquire ownership of STREAM.  */
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));

/* Try to acquire ownership of STREAM but do not block if it is not
   possible.  */
extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;

/* Relinquish the ownership granted for STREAM.  */
extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
# 883 "/usr/include/stdio.h" 3 4
/* Slow-path routines used by the optimized inline functions in
   bits/stdio.h.  */
extern int __uflow (FILE *);
extern int __overflow (FILE *, int);

/* If we are compiling with optimizing read this file.  It contains
   several optimizing inline functions and macros.  */







# 1 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 1 3 4
/* Macros to control TS 18661-3 glibc features on x86.
   Copyright (C) 2017-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 898 "/usr/include/stdio.h" 2 3 4





# 18 "/home/anton/revenant/game/headers/u_hash.h" 2
# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/float.h" 1 3 4
/* Copyright (C) 2002-2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  5.2.4.2.2  Characteristics of floating types <float.h>
 */




/* Radix of exponent representation, b. */



/* Number of base-FLT_RADIX digits in the significand, p.  */







/* Number of decimal digits, q, such that any floating-point number with q
   decimal digits can be rounded into a floating-point number with p radix b
   digits and back again without change to the q decimal digits,

	p * log10(b)			if b is a power of 10
	floor((p - 1) * log10(b))	otherwise
*/







/* Minimum int x such that FLT_RADIX**(x-1) is a normalized float, emin */







/* Minimum negative integer such that 10 raised to that power is in the
   range of normalized floating-point numbers,

	ceil(log10(b) * (emin - 1))
*/







/* Maximum int x such that FLT_RADIX**(x-1) is a representable float, emax.  */







/* Maximum integer such that 10 raised to that power is in the range of
   representable finite floating-point numbers,

	floor(log10((1 - b**-p) * b**emax))
*/







/* Maximum representable finite floating-point number,

	(1 - b**-p) * b**emax
*/







/* The difference between 1 and the least value greater than 1 that is
   representable in the given floating point type, b**1-p.  */







/* Minimum normalized positive floating-point number, b**(emin - 1).  */







/* Addition rounds to 0: zero, 1: nearest, 2: +inf, 3: -inf, -1: unknown.  */
/* ??? This is supposed to change with calls to fesetround in <fenv.h>.  */





/* The floating-point expression evaluation method.  The precise
   definitions of these values are generalised to include support for
   the interchange and extended types defined in ISO/IEC TS 18661-3.
   Prior to this (for C99/C11) the definitions were:

	-1  indeterminate
	 0  evaluate all operations and constants just to the range and
	    precision of the type
	 1  evaluate operations and constants of type float and double
	    to the range and precision of the double type, evaluate
	    long double operations and constants to the range and
	    precision of the long double type
	 2  evaluate all operations and constants to the range and
	    precision of the long double type

   The TS 18661-3 definitions are:

	-1  indeterminate
	 0  evaluate all operations and constants, whose semantic type has
	    at most the range and precision of float, to the range and
	    precision of float; evaluate all other operations and constants
	    to the range and precision of the semantic type.
	 1  evaluate all operations and constants, whose semantic type has
	    at most the range and precision of double, to the range and
	    precision of double; evaluate all other operations and constants
	    to the range and precision of the semantic type.
	 2  evaluate all operations and constants, whose semantic type has
	    at most the range and precision of long double, to the range and
	    precision of long double; evaluate all other operations and
	    constants to the range and precision of the semantic type.
	 N  where _FloatN  is a supported interchange floating type
	    evaluate all operations and constants, whose semantic type has
	    at most the range and precision of the _FloatN type, to the
	    range and precision of the _FloatN type; evaluate all other
	    operations and constants to the range and precision of the
	    semantic type.
	 N + 1, where _FloatNx is a supported extended floating type
	    evaluate operations and constants, whose semantic type has at
	    most the range and precision of the _FloatNx type, to the range
	    and precision of the _FloatNx type; evaluate all other
	    operations and constants to the range and precision of the
	    semantic type.

   The compiler predefines two macros:

      __FLT_EVAL_METHOD__
      Which, depending on the value given for
      -fpermitted-flt-eval-methods, may be limited to only those values
      for FLT_EVAL_METHOD defined in C99/C11.

     __FLT_EVAL_METHOD_TS_18661_3__
      Which always permits the values for FLT_EVAL_METHOD defined in
      ISO/IEC TS 18661-3.

     Here we want to use __FLT_EVAL_METHOD__, unless
     __STDC_WANT_IEC_60559_TYPES_EXT__ is defined, in which case the user
     is specifically asking for the ISO/IEC TS 18661-3 types, so we use
     __FLT_EVAL_METHOD_TS_18661_3__.

   ??? This ought to change with the setting of the fp control word;
   the value provided by the compiler assumes the widest setting.  */







/* Number of decimal digits, n, such that any floating-point number in the
   widest supported floating type with pmax radix b digits can be rounded
   to a floating-point number with n decimal digits and back again without
   change to the value,

	pmax * log10(b)			if b is a power of 10
	ceil(1 + pmax * log10(b))	otherwise
*/







/* Versions of DECIMAL_DIG for each floating-point type.  */







/* Whether types support subnormal numbers.  */







/* Minimum positive values, including subnormals.  */
# 19 "/home/anton/revenant/game/headers/u_hash.h" 2
# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/limits.h" 1 3 4
/* Copyright (C) 1992-2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/* This administrivia gets added to the beginning of limits.h
   if the system has its own version of limits.h.  */

/* We use _GCC_LIMITS_H_ because we want this not to match
   any macros that the system's limits.h uses for its own purposes.  */




/* Use "..." so that we find syslimits.h only in this same directory.  */
# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/syslimits.h" 1 3 4
/* syslimits.h stands for the system's own limits.h file.
   If we can use it ok unmodified, then we install this text.
   If fixincludes fixes it, then the fixed version is installed
   instead of this text.  */


# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/limits.h" 1 3 4
/* Copyright (C) 1992-2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/* This administrivia gets added to the beginning of limits.h
   if the system has its own version of limits.h.  */

/* We use _GCC_LIMITS_H_ because we want this not to match
   any macros that the system's limits.h uses for its own purposes.  */
# 203 "/usr/lib/gcc/x86_64-linux-gnu/11/include/limits.h" 3 4
# 1 "/usr/include/limits.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.10/5.2.4.2.1 Sizes of integer types	<limits.h>
 */





# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
/* Handle feature test macros at the start of a header.
   Copyright (C) 2016-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* This header is internal to glibc and should not be included outside
   of glibc headers.  Headers including it must define
   __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION first.  This header
   cannot have multiple include guards because ISO C feature test
   macros depend on the definition of the macro when an affected
   header is included, not when the first system header is
   included.  */







# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 34 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 2 3 4

/* ISO/IEC TR 24731-2:2010 defines the __STDC_WANT_LIB_EXT2__
   macro.  */
# 45 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
/* ISO/IEC TS 18661-1:2014 defines the __STDC_WANT_IEC_60559_BFP_EXT__
   macro.  Most but not all symbols enabled by that macro in TS
   18661-1 are enabled unconditionally in C2X.  In C2X, the symbols in
   Annex F still require a new feature test macro
   __STDC_WANT_IEC_60559_EXT__ instead (C2X does not define
   __STDC_WANT_IEC_60559_BFP_EXT__), while a few features from TS
   18661-1 are not included in C2X (and thus should depend on
   __STDC_WANT_IEC_60559_BFP_EXT__ even when C2X features are
   enabled).

   __GLIBC_USE (IEC_60559_BFP_EXT) controls those features from TS
   18661-1 not included in C2X.

   __GLIBC_USE (IEC_60559_BFP_EXT_C2X) controls those features from TS
   18661-1 that are also included in C2X (with no feature test macro
   required in C2X).

   __GLIBC_USE (IEC_60559_EXT) controls those features from TS 18661-1
   that are included in C2X but conditional on
   __STDC_WANT_IEC_60559_EXT__.  (There are currently no features
   conditional on __STDC_WANT_IEC_60559_EXT__ that are not in TS
   18661-1.)  */
# 86 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
/* ISO/IEC TS 18661-4:2015 defines the
   __STDC_WANT_IEC_60559_FUNCS_EXT__ macro.  Other than the reduction
   functions, the symbols from this TS are enabled unconditionally in
   C2X.  */
# 103 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
/* ISO/IEC TS 18661-3:2015 defines the
   __STDC_WANT_IEC_60559_TYPES_EXT__ macro.  */
# 27 "/usr/include/limits.h" 2 3 4


/* Maximum length of any multibyte character in any locale.
   We define this value here since the gcc header does not define
   the correct value.  */



/* If we are not using GNU CC we have to define all the symbols ourself.
   Otherwise use gcc's definitions (see below).  */
# 117 "/usr/include/limits.h" 3 4
 /* Get the compiler's limits.h, which defines almost all the ISO constants.

    We put this #include_next outside the double inclusion check because
    it should be possible to include this file more than once and still get
    the definitions from gcc's header.  */





/* The <limits.h> files in some gcc versions don't define LLONG_MIN,
   LLONG_MAX, and ULLONG_MAX.  Instead only the values gcc defined for
   ages are available.  */
# 142 "/usr/include/limits.h" 3 4
/* The integer width macros are not defined by GCC's <limits.h> before
   GCC 7, or if _GNU_SOURCE rather than
   __STDC_WANT_IEC_60559_BFP_EXT__ is used to enable this feature.  */
# 181 "/usr/include/limits.h" 3 4
/* The macros for _Bool are not defined by GCC's <limits.h> before GCC
   11, or if _GNU_SOURCE is defined rather than enabling C2x support
   with -std.  */
# 194 "/usr/include/limits.h" 3 4
/* POSIX adds things to <limits.h>.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/posix1_lim.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 *	POSIX Standard: 2.9.2 Minimum Values	Added to <limits.h>
 *
 *	Never include this file directly; use <limits.h> instead.
 */




# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
/* Determine the wordsize from the preprocessor defines.  */
# 13 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
/* Both x86-64 and x32 use the 64-bit system call interface.  */
# 28 "/usr/include/x86_64-linux-gnu/bits/posix1_lim.h" 2 3 4

/* These are the standard-mandated minimum values.  */

/* Minimum number of operations in one list I/O call.  */


/* Minimal number of outstanding asynchronous I/O operations.  */


/* Maximum length of arguments to `execve', including environment.  */


/* Maximum simultaneous processes per real user ID.  */






/* Minimal number of timer expiration overruns.  */


/* Maximum length of a host name (not including the terminating null)
   as returned from the GETHOSTNAME function.  */


/* Maximum link count of a file.  */


/* Maximum length of login name.  */


/* Number of bytes in a terminal canonical input queue.  */


/* Number of bytes for which space will be
   available in a terminal input queue.  */


/* Maximum number of message queues open for a process.  */


/* Maximum number of supported message priorities.  */


/* Number of bytes in a filename.  */


/* Number of simultaneous supplementary group IDs per process.  */






/* Number of files one process can have open at once.  */
# 96 "/usr/include/x86_64-linux-gnu/bits/posix1_lim.h" 3 4
/* Number of bytes in a pathname.  */


/* Number of bytes than can be written atomically to a pipe.  */


/* The number of repeated occurrences of a BRE permitted by the
   REGEXEC and REGCOMP functions when using the interval notation.  */


/* Minimal number of realtime signals reserved for the application.  */


/* Number of semaphores a process can have.  */


/* Maximal value of a semaphore.  */


/* Number of pending realtime signals.  */


/* Largest value of a `ssize_t'.  */


/* Number of streams a process can have open at once.  */


/* The number of bytes in a symbolic link.  */


/* The number of symbolic links that can be traversed in the
   resolution of a pathname in the absence of a loop.  */


/* Number of timer for a process.  */


/* Maximum number of characters in a tty name.  */


/* Maximum length of a timezone name (element of `tzname').  */
# 156 "/usr/include/x86_64-linux-gnu/bits/posix1_lim.h" 3 4
/* Maximum clock resolution in nanoseconds.  */



/* Get the implementation-specific values for the above.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/local_lim.h" 1 3 4
/* Minimum guaranteed maximum values for system limits.  Linux version.
   Copyright (C) 1993-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation; either version 2.1 of the
   License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If
   not, see <https://www.gnu.org/licenses/>.  */

/* The kernel header pollutes the namespace with the NR_OPEN symbol
   and defines LINK_MAX although filesystems have different maxima.  A
   similar thing is true for OPEN_MAX: the limit can be changed at
   runtime and therefore the macro must not be defined.  Remove this
   after including the header if necessary.  */
# 37 "/usr/include/x86_64-linux-gnu/bits/local_lim.h" 3 4
/* The kernel sources contain a file with all the needed information.  */
# 1 "/usr/include/linux/limits.h" 1 3 4
/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
# 39 "/usr/include/x86_64-linux-gnu/bits/local_lim.h" 2 3 4

/* Have to remove NR_OPEN?  */




/* Have to remove LINK_MAX?  */




/* Have to remove OPEN_MAX?  */




/* Have to remove ARG_MAX?  */





/* The number of data keys per process.  */

/* This is the value this implementation supports.  */


/* Controlling the iterations of destructors for thread-specific data.  */

/* Number of iterations this implementation does.  */


/* The number of threads per process.  */

/* We have no predefined limit on the number of threads.  */


/* Maximum amount by which a process can descrease its asynchronous I/O
   priority level.  */


/* Arrange for the definition of PTHREAD_STACK_MIN.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h" 1 3 4
/* Definition of PTHREAD_STACK_MIN, possibly dynamic.
   Copyright (C) 2021-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 29 "/usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h" 1 3 4
/* Definition of PTHREAD_STACK_MIN.  Linux version.
   Copyright (C) 2021-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* Minimum size for a thread.  We are free to choose a reasonable value.  */
# 30 "/usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h" 2 3 4
# 82 "/usr/include/x86_64-linux-gnu/bits/local_lim.h" 2 3 4

/* Maximum number of timer expiration overruns.  */


/* Maximum tty name length.  */


/* Maximum login name length.  This is arbitrary.  */


/* Maximum host name length.  */


/* Maximum message queue priority level.  */


/* Maximum value the semaphore can have.  */
# 162 "/usr/include/x86_64-linux-gnu/bits/posix1_lim.h" 2 3 4



/* ssize_t is not formally required to be the signed type
   corresponding to size_t, but it is for all configurations supported
   by glibc.  */
# 176 "/usr/include/x86_64-linux-gnu/bits/posix1_lim.h" 3 4
/* This value is a guaranteed minimum maximum.
   The current maximum can be got from `sysconf'.  */
# 196 "/usr/include/limits.h" 2 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/posix2_lim.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; include <limits.h> instead.
 */





/* The maximum `ibase' and `obase' values allowed by the `bc' utility.  */


/* The maximum number of elements allowed in an array by the `bc' utility.  */


/* The maximum `scale' value allowed by the `bc' utility.  */


/* The maximum length of a string constant accepted by the `bc' utility.  */


/* The maximum number of weights that can be assigned to an entry of
   the LC_COLLATE `order' keyword in the locale definition file.  */


/* The maximum number of expressions that can be nested
   within parentheses by the `expr' utility.  */


/* The maximum length, in bytes, of an input line.  */


/* The maximum number of repeated occurrences of a regular expression
   permitted when using the interval notation `\{M,N\}'.  */


/* The maximum number of bytes in a character class name.  We have no
   fixed limit, 2048 is a high number.  */



/* These values are implementation-specific,
   and may vary within the implementation.
   Their precise values can be obtained from sysconf.  */
# 87 "/usr/include/x86_64-linux-gnu/bits/posix2_lim.h" 3 4
/* This value is defined like this in regex.h.  */
# 200 "/usr/include/limits.h" 2 3 4
# 204 "/usr/lib/gcc/x86_64-linux-gnu/11/include/limits.h" 2 3 4
# 8 "/usr/lib/gcc/x86_64-linux-gnu/11/include/syslimits.h" 2 3 4
# 35 "/usr/lib/gcc/x86_64-linux-gnu/11/include/limits.h" 2 3 4

/* Copyright (C) 1991-2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */




/* Number of bits in a `char'.  */



/* Maximum length of a multibyte character.  */




/* Minimum and maximum values a `signed char' can hold.  */





/* Maximum value an `unsigned char' can hold.  (Minimum is 0).  */







/* Minimum and maximum values a `char' can hold.  */
# 102 "/usr/lib/gcc/x86_64-linux-gnu/11/include/limits.h" 3 4
/* Minimum and maximum values a `signed short int' can hold.  */





/* Maximum value an `unsigned short int' can hold.  (Minimum is 0).  */







/* Minimum and maximum values a `signed int' can hold.  */





/* Maximum value an `unsigned int' can hold.  (Minimum is 0).  */



/* Minimum and maximum values a `signed long int' can hold.
   (Same as `int').  */





/* Maximum value an `unsigned long int' can hold.  (Minimum is 0).  */




/* Minimum and maximum values a `signed long long int' can hold.  */





/* Maximum value an `unsigned long long int' can hold.  (Minimum is 0).  */
# 197 "/usr/lib/gcc/x86_64-linux-gnu/11/include/limits.h" 3 4
/* This administrivia gets added to the end of limits.h
   if the system has its own version of limits.h.  */
# 20 "/home/anton/revenant/game/headers/u_hash.h" 2
# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stdint.h" 1 3 4
# 9 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stdint.h" 3 4
# 1 "/usr/include/stdint.h" 1 3 4
/* Copyright (C) 1997-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 *	ISO C99: 7.18 Integer types <stdint.h>
 */





# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
/* Handle feature test macros at the start of a header.
   Copyright (C) 2016-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* This header is internal to glibc and should not be included outside
   of glibc headers.  Headers including it must define
   __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION first.  This header
   cannot have multiple include guards because ISO C feature test
   macros depend on the definition of the macro when an affected
   header is included, not when the first system header is
   included.  */







# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 34 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 2 3 4

/* ISO/IEC TR 24731-2:2010 defines the __STDC_WANT_LIB_EXT2__
   macro.  */
# 45 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
/* ISO/IEC TS 18661-1:2014 defines the __STDC_WANT_IEC_60559_BFP_EXT__
   macro.  Most but not all symbols enabled by that macro in TS
   18661-1 are enabled unconditionally in C2X.  In C2X, the symbols in
   Annex F still require a new feature test macro
   __STDC_WANT_IEC_60559_EXT__ instead (C2X does not define
   __STDC_WANT_IEC_60559_BFP_EXT__), while a few features from TS
   18661-1 are not included in C2X (and thus should depend on
   __STDC_WANT_IEC_60559_BFP_EXT__ even when C2X features are
   enabled).

   __GLIBC_USE (IEC_60559_BFP_EXT) controls those features from TS
   18661-1 not included in C2X.

   __GLIBC_USE (IEC_60559_BFP_EXT_C2X) controls those features from TS
   18661-1 that are also included in C2X (with no feature test macro
   required in C2X).

   __GLIBC_USE (IEC_60559_EXT) controls those features from TS 18661-1
   that are included in C2X but conditional on
   __STDC_WANT_IEC_60559_EXT__.  (There are currently no features
   conditional on __STDC_WANT_IEC_60559_EXT__ that are not in TS
   18661-1.)  */
# 86 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
/* ISO/IEC TS 18661-4:2015 defines the
   __STDC_WANT_IEC_60559_FUNCS_EXT__ macro.  Other than the reduction
   functions, the symbols from this TS are enabled unconditionally in
   C2X.  */
# 103 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
/* ISO/IEC TS 18661-3:2015 defines the
   __STDC_WANT_IEC_60559_TYPES_EXT__ macro.  */
# 27 "/usr/include/stdint.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 28 "/usr/include/stdint.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wchar.h" 1 3 4
/* wchar_t type related definitions.
   Copyright (C) 2000-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */




/* The fallback definitions, for when __WCHAR_MAX__ or __WCHAR_MIN__
   are not defined, give the right value and type as long as both int
   and wchar_t are 32-bit types.  Adding L'\0' to a constant value
   ensures that the type is correct; it is necessary to use (L'\0' +
   0) rather than just L'\0' so that the type in C++ is the promoted
   version of wchar_t rather than the distinct wchar_t type itself.
   Because wchar_t in preprocessor #if expressions is treated as
   intmax_t or uintmax_t, the expression (L'\0' - 1) would have the
   wrong value for WCHAR_MAX in such expressions and so cannot be used
   to define __WCHAR_MAX in the unsigned case.  */
# 29 "/usr/include/stdint.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
/* Determine the wordsize from the preprocessor defines.  */
# 13 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
/* Both x86-64 and x32 use the 64-bit system call interface.  */
# 30 "/usr/include/stdint.h" 2 3 4

/* Exact integral types.  */

/* Signed.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h" 1 3 4
/* Define intN_t types.
   Copyright (C) 2017-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */




# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 23 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h" 2 3 4

typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
# 35 "/usr/include/stdint.h" 2 3 4

/* Unsigned.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/stdint-uintn.h" 1 3 4
/* Define uintN_t types.
   Copyright (C) 2017-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */




# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 23 "/usr/include/x86_64-linux-gnu/bits/stdint-uintn.h" 2 3 4

typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;
# 38 "/usr/include/stdint.h" 2 3 4


/* Small types.  */

/* Signed.  */
typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;

/* Unsigned.  */
typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;


/* Fast types.  */

/* Signed.  */
typedef signed char int_fast8_t;

typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;







/* Unsigned.  */
typedef unsigned char uint_fast8_t;

typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
# 84 "/usr/include/stdint.h" 3 4
/* Types for `void *' pointers.  */


typedef long int intptr_t;


typedef unsigned long int uintptr_t;
# 100 "/usr/include/stdint.h" 3 4
/* Largest integral types.  */
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
# 113 "/usr/include/stdint.h" 3 4
/* Limits of integral types.  */

/* Minimum of signed integral types.  */




/* Maximum of signed integral types.  */





/* Maximum of unsigned integral types.  */






/* Minimum of signed integral types having a minimum size.  */




/* Maximum of signed integral types having a minimum size.  */





/* Maximum of unsigned integral types having a minimum size.  */






/* Minimum of fast signed integral types having a minimum size.  */
# 161 "/usr/include/stdint.h" 3 4
/* Maximum of fast signed integral types having a minimum size.  */
# 172 "/usr/include/stdint.h" 3 4
/* Maximum of fast unsigned integral types having a minimum size.  */
# 184 "/usr/include/stdint.h" 3 4
/* Values to test for integral types holding `void *' pointer.  */
# 196 "/usr/include/stdint.h" 3 4
/* Minimum for largest signed integral type.  */

/* Maximum for largest signed integral type.  */


/* Maximum for largest unsigned integral type.  */



/* Limits of other integer types.  */

/* Limits of `ptrdiff_t' type.  */
# 221 "/usr/include/stdint.h" 3 4
/* Limits of `sig_atomic_t'.  */



/* Limit of `size_t' type.  */
# 236 "/usr/include/stdint.h" 3 4
/* Limits of `wchar_t'.  */

/* These constants might also be defined in <wchar.h>.  */




/* Limits of `wint_t'.  */



/* Signed.  */
# 257 "/usr/include/stdint.h" 3 4
/* Unsigned.  */
# 267 "/usr/include/stdint.h" 3 4
/* Maximal type.  */
# 10 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stdint.h" 2 3 4
# 21 "/home/anton/revenant/game/headers/u_hash.h" 2
# 1 "/usr/include/string.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.21 String handling	<string.h>
 */





# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
/* Handle feature test macros at the start of a header.
   Copyright (C) 2016-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* This header is internal to glibc and should not be included outside
   of glibc headers.  Headers including it must define
   __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION first.  This header
   cannot have multiple include guards because ISO C feature test
   macros depend on the definition of the macro when an affected
   header is included, not when the first system header is
   included.  */







# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 34 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 2 3 4

/* ISO/IEC TR 24731-2:2010 defines the __STDC_WANT_LIB_EXT2__
   macro.  */
# 45 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
/* ISO/IEC TS 18661-1:2014 defines the __STDC_WANT_IEC_60559_BFP_EXT__
   macro.  Most but not all symbols enabled by that macro in TS
   18661-1 are enabled unconditionally in C2X.  In C2X, the symbols in
   Annex F still require a new feature test macro
   __STDC_WANT_IEC_60559_EXT__ instead (C2X does not define
   __STDC_WANT_IEC_60559_BFP_EXT__), while a few features from TS
   18661-1 are not included in C2X (and thus should depend on
   __STDC_WANT_IEC_60559_BFP_EXT__ even when C2X features are
   enabled).

   __GLIBC_USE (IEC_60559_BFP_EXT) controls those features from TS
   18661-1 not included in C2X.

   __GLIBC_USE (IEC_60559_BFP_EXT_C2X) controls those features from TS
   18661-1 that are also included in C2X (with no feature test macro
   required in C2X).

   __GLIBC_USE (IEC_60559_EXT) controls those features from TS 18661-1
   that are included in C2X but conditional on
   __STDC_WANT_IEC_60559_EXT__.  (There are currently no features
   conditional on __STDC_WANT_IEC_60559_EXT__ that are not in TS
   18661-1.)  */
# 86 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
/* ISO/IEC TS 18661-4:2015 defines the
   __STDC_WANT_IEC_60559_FUNCS_EXT__ macro.  Other than the reduction
   functions, the symbols from this TS are enabled unconditionally in
   C2X.  */
# 103 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
/* ISO/IEC TS 18661-3:2015 defines the
   __STDC_WANT_IEC_60559_TYPES_EXT__ macro.  */
# 27 "/usr/include/string.h" 2 3 4



/* Get size_t and NULL from <stddef.h>.  */


# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 1 3 4
/* Copyright (C) 1989-2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */






/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */
# 46 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */
# 86 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 111 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 159 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 235 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 387 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* A null pointer constant.  */
# 34 "/usr/include/string.h" 2 3 4

/* Tell the caller that we provide correct C++ prototypes.  */






/* Copy N bytes of SRC to DEST.  */
extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
/* Copy N bytes of SRC to DEST, guaranteeing
   correct behavior for overlapping strings.  */
extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

/* Copy no more than N bytes of SRC to DEST, stopping when C is found.
   Return the position in DEST one byte past where C was copied,
   or NULL if C was not found in the first N bytes of SRC.  */

extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__write_only__, 1, 4)));



/* Set N bytes of S to C.  */
extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

/* Compare N bytes of S1 and S2.  */
extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

/* Compare N bytes of S1 and S2.  Return zero if S1 and S2 are equal.
   Return some non-zero value otherwise.

   Essentially __memcmpeq has the exact same semantics as memcmp
   except the return value is less constrained.  memcmp is always a
   correct implementation of __memcmpeq.  As well !!memcmp, -memcmp,
   or bcmp are correct implementations.

   __memcmpeq is meant to be used by compilers when memcmp return is
   only used for its bolean value.

   __memcmpeq is declared only for use by compilers.  Programs should
   continue to use memcmp.  */
extern int __memcmpeq (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

/* Search N bytes of S for C.  */
# 107 "/usr/include/string.h" 3 4
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 140 "/usr/include/string.h" 3 4
/* Copy SRC to DEST.  */
extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
/* Copy no more than N characters of SRC to DEST.  */
extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

/* Append SRC onto DEST.  */
extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
/* Append no more than N characters from SRC onto DEST.  */
extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

/* Compare S1 and S2.  */
extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
/* Compare N characters of S1 and S2.  */
extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

/* Compare the collated forms of S1 and S2.  */
extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
/* Put a transformation of SRC into no more than N bytes of DEST.  */
extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__access__ (__write_only__, 1, 3)));


/* POSIX.1-2008 extended locale interface (see locale.h).  */
# 1 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 1 3 4
/* Definition of locale_t.
   Copyright (C) 2017-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */




# 1 "/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h" 1 3 4
/* Definition of struct __locale_struct and __locale_t.
   Copyright (C) 1997-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */




/* POSIX.1-2008: the locale_t type, representing a locale context
   (implementation-namespace version).  This type should be treated
   as opaque by applications; some details are exposed for the sake of
   efficiency in e.g. ctype functions.  */

struct __locale_struct
{
  /* Note: LC_ALL is not a valid index into this array.  */
  struct __locale_data *__locales[13]; /* 13 = __LC_LAST. */

  /* To increase the speed of this solution we add some special members.  */
  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;

  /* Note: LC_ALL is not a valid index into this array.  */
  const char *__names[13];
};

typedef struct __locale_struct *__locale_t;
# 23 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 2 3 4

typedef __locale_t locale_t;
# 173 "/usr/include/string.h" 2 3 4

/* Compare the collated forms of S1 and S2, using sorting rules from L.  */
extern int strcoll_l (const char *__s1, const char *__s2, locale_t __l)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));
/* Put a transformation of SRC into no more than N bytes of DEST,
   using sorting rules from L.  */
extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    locale_t __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)))
     __attribute__ ((__access__ (__write_only__, 1, 3)));




/* Duplicate S, returning an identical malloc'd string.  */
extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));


/* Return a malloc'd copy of at most N bytes of STRING.  The
   resultant string is terminated even if no null terminator
   appears before STRING[N].  */

extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
# 222 "/usr/include/string.h" 3 4
/* Find the first occurrence of C in S.  */
# 246 "/usr/include/string.h" 3 4
extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));

/* Find the last occurrence of C in S.  */
# 273 "/usr/include/string.h" 3 4
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 291 "/usr/include/string.h" 3 4
/* Return the length of the initial segment of S which
   consists entirely of characters not in REJECT.  */
extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
/* Return the length of the initial segment of S which
   consists entirely of characters in ACCEPT.  */
extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
/* Find the first occurrence in S of any character in ACCEPT.  */
# 323 "/usr/include/string.h" 3 4
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

/* Find the first occurrence of NEEDLE in HAYSTACK.  */
# 350 "/usr/include/string.h" 3 4
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));



/* Divide S into tokens separated by characters in DELIM.  */
extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

/* Divide S into tokens separated by characters in DELIM.  Information
   passed between calls are stored in SAVE_PTR.  */
extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));

extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
# 406 "/usr/include/string.h" 3 4
/* Return the length of S.  */
extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


/* Find the length of STRING, but scan at most MAXLEN characters.
   If no '\0' terminator is found in that many characters, return MAXLEN.  */
extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));



/* Return a string describing the meaning of the `errno' code in ERRNUM.  */
extern char *strerror (int __errnum) __attribute__ ((__nothrow__ , __leaf__));

/* Reentrant version of `strerror'.
   There are 2 flavors of `strerror_r', GNU which returns the string
   and may or may not use the supplied temporary buffer and POSIX one
   which fills the string into the buffer.
   To use the POSIX version, -D_XOPEN_SOURCE=600 or -D_POSIX_C_SOURCE=200112L
   without -D_GNU_SOURCE is needed, otherwise the GNU version is
   preferred.  */

/* Fill BUF with a string describing the meaning of the `errno' code in
   ERRNUM.  */

extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__ , __leaf__))

                        __attribute__ ((__nonnull__ (2)))
    __attribute__ ((__access__ (__write_only__, 2, 3)));
# 457 "/usr/include/string.h" 3 4
/* Translate error number to string according to the locale L.  */
extern char *strerror_l (int __errnum, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));



# 1 "/home/anton/revenant/game/headers/strings.h" 1 3 4
/*This file is part of Revnant.

Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Revenant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */



# 1 "/usr/include/stdlib.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   Copyright The GNU Toolchain Authors.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.20 General utilities	<stdlib.h>
 */




# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
/* Handle feature test macros at the start of a header.
   Copyright (C) 2016-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* This header is internal to glibc and should not be included outside
   of glibc headers.  Headers including it must define
   __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION first.  This header
   cannot have multiple include guards because ISO C feature test
   macros depend on the definition of the macro when an affected
   header is included, not when the first system header is
   included.  */







# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 34 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 2 3 4

/* ISO/IEC TR 24731-2:2010 defines the __STDC_WANT_LIB_EXT2__
   macro.  */
# 45 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
/* ISO/IEC TS 18661-1:2014 defines the __STDC_WANT_IEC_60559_BFP_EXT__
   macro.  Most but not all symbols enabled by that macro in TS
   18661-1 are enabled unconditionally in C2X.  In C2X, the symbols in
   Annex F still require a new feature test macro
   __STDC_WANT_IEC_60559_EXT__ instead (C2X does not define
   __STDC_WANT_IEC_60559_BFP_EXT__), while a few features from TS
   18661-1 are not included in C2X (and thus should depend on
   __STDC_WANT_IEC_60559_BFP_EXT__ even when C2X features are
   enabled).

   __GLIBC_USE (IEC_60559_BFP_EXT) controls those features from TS
   18661-1 not included in C2X.

   __GLIBC_USE (IEC_60559_BFP_EXT_C2X) controls those features from TS
   18661-1 that are also included in C2X (with no feature test macro
   required in C2X).

   __GLIBC_USE (IEC_60559_EXT) controls those features from TS 18661-1
   that are included in C2X but conditional on
   __STDC_WANT_IEC_60559_EXT__.  (There are currently no features
   conditional on __STDC_WANT_IEC_60559_EXT__ that are not in TS
   18661-1.)  */
# 86 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
/* ISO/IEC TS 18661-4:2015 defines the
   __STDC_WANT_IEC_60559_FUNCS_EXT__ macro.  Other than the reduction
   functions, the symbols from this TS are enabled unconditionally in
   C2X.  */
# 103 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
/* ISO/IEC TS 18661-3:2015 defines the
   __STDC_WANT_IEC_60559_TYPES_EXT__ macro.  */
# 27 "/usr/include/stdlib.h" 2 3 4

/* Get size_t, wchar_t and NULL from <stddef.h>.  */



# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 1 3 4
/* Copyright (C) 1989-2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */






/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */
# 46 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */
# 86 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 111 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 159 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 235 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 276 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* On BSD/386 1.1, at least, machine/ansi.h defines _BSD_WCHAR_T_
   instead of _WCHAR_T_, and _BSD_RUNE_T_ (which, unlike the other
   symbols in the _FOO_T_ family, stays defined even after its
   corresponding type is defined).  If we define wchar_t, then we
   must undef _WCHAR_T_; for BSD/386 1.1 (and perhaps others), if
   we undef _WCHAR_T_, then we must also define rune_t, since 
   headers like runetype.h assume that if machine/ansi.h is included,
   and _BSD_WCHAR_T_ is not defined, then rune_t is available.
   machine/ansi.h says, "Note that _WCHAR_T_ and _RUNE_T_ must be of
   the same type." */
# 303 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* FreeBSD 5 can't be handled well using "traditional" logic above
   since it no longer defines _BSD_RUNE_T_ yet still desires to export
   rune_t in some cases... */
# 321 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
typedef int wchar_t;
# 387 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* A null pointer constant.  */
# 33 "/usr/include/stdlib.h" 2 3 4






/* XPG requires a few symbols from <sys/wait.h> being defined.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/waitflags.h" 1 3 4
/* Definitions of flag bits for `waitpid' et al.
   Copyright (C) 1992-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */






/* Bits in the third argument to `waitpid'.  */



/* Bits in the fourth argument to `waitid'.  */
# 41 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h" 1 3 4
/* Definitions of status bits for `wait' et al.
   Copyright (C) 1992-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */






/* Everything extant so far uses these same bits.  */


/* If WIFEXITED(STATUS), the low-order 8 bits of the status.  */


/* If WIFSIGNALED(STATUS), the terminating signal.  */


/* If WIFSTOPPED(STATUS), the signal that stopped the child.  */


/* Nonzero if STATUS indicates normal termination.  */


/* Nonzero if STATUS indicates termination by a signal.  */



/* Nonzero if STATUS indicates the child is stopped.  */


/* Nonzero if STATUS indicates the child continued after a stop.  We only
   define this if <bits/waitflags.h> provides the WCONTINUED flag bit.  */




/* Nonzero if STATUS indicates the child dumped core.  */


/* Macros for constructing status values.  */
# 42 "/usr/include/stdlib.h" 2 3 4

/* Define the macros <sys/wait.h> also would define this way.  */
# 55 "/usr/include/stdlib.h" 3 4
/* _FloatN API tests for enablement.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 1 3 4
/* Macros to control TS 18661-3 glibc features on x86.
   Copyright (C) 2017-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 57 "/usr/include/stdlib.h" 2 3 4

/* Returned by `div'.  */
typedef struct
  {
    int quot; /* Quotient.  */
    int rem; /* Remainder.  */
  } div_t;

/* Returned by `ldiv'.  */

typedef struct
  {
    long int quot; /* Quotient.  */
    long int rem; /* Remainder.  */
  } ldiv_t;




/* Returned by `lldiv'.  */
__extension__ typedef struct
  {
    long long int quot; /* Quotient.  */
    long long int rem; /* Remainder.  */
  } lldiv_t;




/* The largest number rand will return (same as INT_MAX).  */



/* We define these the same for all machines.
   Changes from this to the outside world should be done in `_exit'.  */




/* Maximum length of a multibyte character in the current locale.  */

extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__ , __leaf__)) ;


/* Convert a string to a floating-point number.  */
extern double atof (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
/* Convert a string to an integer.  */
extern int atoi (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
/* Convert a string to a long integer.  */
extern long int atol (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;


/* Convert a string to a long long integer.  */
__extension__ extern long long int atoll (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;


/* Convert a string to a floating-point number.  */
extern double strtod (const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


/* Likewise for `float' and `long double' sizes of floating-point numbers.  */
extern float strtof (const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern long double strtold (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


/* Likewise for '_FloatN' and '_FloatNx'.  */
# 176 "/usr/include/stdlib.h" 3 4
/* Convert a string to a long integer.  */
extern long int strtol (const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
/* Convert a string to an unsigned long integer.  */
extern unsigned long int strtoul (const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


/* Convert a string to a quadword integer.  */
__extension__
extern long long int strtoq (const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
/* Convert a string to an unsigned quadword integer.  */
__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



/* Convert a string to a quadword integer.  */
__extension__
extern long long int strtoll (const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
/* Convert a string to an unsigned quadword integer.  */
__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


/* Convert a floating-point number to a string.  */
# 383 "/usr/include/stdlib.h" 3 4
/* Convert N to base 64 using the digits "./0-9A-Za-z", least-significant
   digit first.  Returns a pointer to static storage overwritten by the
   next call.  */
extern char *l64a (long int __n) __attribute__ ((__nothrow__ , __leaf__)) ;

/* Read a number from a string S in base 64 as above.  */
extern long int a64l (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;




# 1 "/usr/include/x86_64-linux-gnu/sys/types.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 *	POSIX Standard: 2.6 Primitive System Data Types	<sys/types.h>
 */




# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 26 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 30 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4



typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;


typedef __loff_t loff_t;




typedef __ino_t ino_t;
# 59 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;
# 97 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __pid_t pid_t;





typedef __id_t id_t;
# 114 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;




# 1 "/usr/include/x86_64-linux-gnu/bits/types/clock_t.h" 1 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 5 "/usr/include/x86_64-linux-gnu/bits/types/clock_t.h" 2 3 4

/* Returned by `clock'.  */
typedef __clock_t clock_t;
# 127 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/types/clockid_t.h" 1 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 5 "/usr/include/x86_64-linux-gnu/bits/types/clockid_t.h" 2 3 4

/* Clock ID used in clock and timer functions.  */
typedef __clockid_t clockid_t;
# 129 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/time_t.h" 1 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 5 "/usr/include/x86_64-linux-gnu/bits/types/time_t.h" 2 3 4

/* Returned by `time'.  */



typedef __time_t time_t;
# 130 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/timer_t.h" 1 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 5 "/usr/include/x86_64-linux-gnu/bits/types/timer_t.h" 2 3 4

/* Timer ID returned by `timer_create'.  */
typedef __timer_t timer_t;
# 131 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 144 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 1 3 4
/* Copyright (C) 1989-2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */






/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */
# 46 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */
# 86 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 111 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 159 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 235 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 387 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* A null pointer constant.  */
# 145 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4


/* Old compatibility names for C types.  */
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;


/* These size-specific names are used by some of the inet code.  */

# 1 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h" 1 3 4
/* Define intN_t types.
   Copyright (C) 2017-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 156 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4

/* These were defined by ISO C without the first `_'.  */
typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;


typedef int register_t __attribute__ ((__mode__ (__word__)));




/* Some code from BIND tests this macro to see if the types above are
   defined.  */




/* In BSD <sys/types.h> is expected to define BYTE_ORDER.  */
# 1 "/usr/include/endian.h" 1 3 4
/* Copyright (C) 1992-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */




# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 22 "/usr/include/endian.h" 2 3 4

/* Get the definitions of __*_ENDIAN, __BYTE_ORDER, and __FLOAT_WORD_ORDER.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/endian.h" 1 3 4
/* Endian macros for string.h functions
   Copyright (C) 1992-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */




/* Definitions for byte order, according to significance of bytes,
   from low addresses to high addresses.  The value is what you get by
   putting '4' in the most significant byte, '3' in the second most
   significant byte, '2' in the second least significant byte, and '1'
   in the least significant byte, and then writing down one digit for
   each byte, starting with the byte at the lowest address at the left,
   and proceeding to the byte with the highest address at the right.  */





/* This file defines `__BYTE_ORDER' for the particular machine.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/endianness.h" 1 3 4







/* i386/x86_64 are little-endian.  */
# 36 "/usr/include/x86_64-linux-gnu/bits/endian.h" 2 3 4

/* Some machines may need to use a different endianness for floating point
   values.  */
# 25 "/usr/include/endian.h" 2 3 4
# 34 "/usr/include/endian.h" 3 4
/* Conversion interfaces.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 1 3 4
/* Macros and inline functions to swap the order of bytes in integer values.
   Copyright (C) 1997-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 26 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 27 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 28 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 2 3 4

/* Swap bytes in 16-bit value.  */



static __inline __uint16_t
__bswap_16 (__uint16_t __bsx)
{

  return __builtin_bswap16 (__bsx);



}

/* Swap bytes in 32-bit value.  */




static __inline __uint32_t
__bswap_32 (__uint32_t __bsx)
{

  return __builtin_bswap32 (__bsx);



}

/* Swap bytes in 64-bit value.  */
# 69 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
__extension__ static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{

  return __builtin_bswap64 (__bsx);



}
# 36 "/usr/include/endian.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/uintn-identity.h" 1 3 4
/* Inline functions to return unsigned integer values unchanged.
   Copyright (C) 2017-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 26 "/usr/include/x86_64-linux-gnu/bits/uintn-identity.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 27 "/usr/include/x86_64-linux-gnu/bits/uintn-identity.h" 2 3 4

/* These inline functions are to ensure the appropriate type
   conversions and associated diagnostics from macros that convert to
   a given endianness.  */

static __inline __uint16_t
__uint16_identity (__uint16_t __x)
{
  return __x;
}

static __inline __uint32_t
__uint32_identity (__uint32_t __x)
{
  return __x;
}

static __inline __uint64_t
__uint64_identity (__uint64_t __x)
{
  return __x;
}
# 37 "/usr/include/endian.h" 2 3 4
# 177 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4

/* It also defines `fd_set' and the FD_* macros for `select'.  */
# 1 "/usr/include/x86_64-linux-gnu/sys/select.h" 1 3 4
/* `fd_set' type and related macros, and `select'/`pselect' declarations.
   Copyright (C) 1996-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*	POSIX 1003.1g: 6.2 Select from File Descriptor Sets <sys/select.h>  */




# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 25 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4

/* Get definition of needed basic types.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 28 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4

/* Get __FD_* definitions.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/select.h" 1 3 4
/* Copyright (C) 1997-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */






/* We don't use `memset' because this would require a prototype and
   the array isn't too big.  */
# 31 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4

/* Get sigset_t.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/types/sigset_t.h" 1 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h" 1 3 4




typedef struct
{
  unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
} __sigset_t;
# 5 "/usr/include/x86_64-linux-gnu/bits/types/sigset_t.h" 2 3 4

/* A set of signals to be blocked, unblocked, or waited for.  */
typedef __sigset_t sigset_t;
# 34 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4

/* Get definition of timer specification structures.  */

# 1 "/usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h" 1 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 5 "/usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h" 2 3 4

/* A time value that is accurate to the nearest
   microsecond but also has a range of years.  */
struct timeval
{




  __time_t tv_sec; /* Seconds.  */
  __suseconds_t tv_usec; /* Microseconds.  */

};
# 38 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h" 1 3 4
/* NB: Include guard matches what <linux/time.h> uses.  */



# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 6 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/endian.h" 1 3 4
/* Endian macros for string.h functions
   Copyright (C) 1992-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
# 7 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h" 2 3 4


/* POSIX.1b structure for a time value.  This is like a `struct timeval' but
   has nanoseconds instead of microseconds.  */
struct timespec
{



  __time_t tv_sec; /* Seconds.  */




  __syscall_slong_t tv_nsec; /* Nanoseconds.  */
# 31 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h" 3 4
};
# 40 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4



typedef __suseconds_t suseconds_t;




/* The fd_set member is required to be an array of longs.  */
typedef long int __fd_mask;

/* Some versions of <linux/posix_types.h> define this macros.  */

/* It's easier to assume 8-bit bytes than to get CHAR_BIT.  */




/* fd_set for select and pselect.  */
typedef struct
  {
    /* XPG4.2 requires this member name.  Otherwise avoid the name
       from the global namespace.  */




    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];


  } fd_set;

/* Maximum number of file descriptors in `fd_set'.  */



/* Sometimes the fd_set member is assumed to have this type.  */
typedef __fd_mask fd_mask;

/* Number of bits per word of `fd_set' (some code assumes this is 32).  */




/* Access macros for `fd_set'.  */








/* Check the first NFDS descriptors each in READFDS (if not NULL) for read
   readiness, in WRITEFDS (if not NULL) for write readiness, and in EXCEPTFDS
   (if not NULL) for exceptional conditions.  If TIMEOUT is not NULL, time out
   after waiting the interval specified therein.  Returns the number of ready
   descriptors, or -1 for errors.

   This function is a cancellation point and therefore not marked with
   __THROW.  */

extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
# 120 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
/* Same as above only that the TIMEOUT value is given with higher
   resolution and a sigmask which is been set temporarily.  This version
   should be used.

   This function is a cancellation point and therefore not marked with
   __THROW.  */

extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);
# 148 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
/* Define some inlines helping to catch common problems.  */





# 180 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4





typedef __blksize_t blksize_t;



/* Types from the Large File Support interface.  */


typedef __blkcnt_t blkcnt_t; /* Type to count number of disk blocks.  */



typedef __fsblkcnt_t fsblkcnt_t; /* Type to count file system blocks.  */



typedef __fsfilcnt_t fsfilcnt_t; /* Type to count file system inodes.  */
# 225 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
/* Now add the thread types.  */

# 1 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 1 3 4
/* Declaration of common pthread types for all architectures.
   Copyright (C) 2017-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */




/* For internal mutex and condition variable definitions.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 1 3 4
/* Common threading primitives definitions for both POSIX and C11.
   Copyright (C) 2017-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */




/* Arch-specific definitions.  Each architecture must define the following
   macros to define the expected sizes of pthread data types:

   __SIZEOF_PTHREAD_ATTR_T        - size of pthread_attr_t.
   __SIZEOF_PTHREAD_MUTEX_T       - size of pthread_mutex_t.
   __SIZEOF_PTHREAD_MUTEXATTR_T   - size of pthread_mutexattr_t.
   __SIZEOF_PTHREAD_COND_T        - size of pthread_cond_t.
   __SIZEOF_PTHREAD_CONDATTR_T    - size of pthread_condattr_t.
   __SIZEOF_PTHREAD_RWLOCK_T      - size of pthread_rwlock_t.
   __SIZEOF_PTHREAD_RWLOCKATTR_T  - size of pthread_rwlockattr_t.
   __SIZEOF_PTHREAD_BARRIER_T     - size of pthread_barrier_t.
   __SIZEOF_PTHREAD_BARRIERATTR_T - size of pthread_barrierattr_t.

   The additional macro defines any constraint for the lock alignment
   inside the thread structures:

   __LOCK_ALIGNMENT - for internal lock/futex usage.

   Same idea but for the once locking primitive:

   __ONCE_ALIGNMENT - for pthread_once_t/once_flag definition.  */

# 1 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h" 1 3 4
/* Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */




# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
/* Determine the wordsize from the preprocessor defines.  */
# 13 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
/* Both x86-64 and x32 use the 64-bit system call interface.  */
# 22 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h" 2 3 4
# 45 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h" 1 3 4
/* Monotonically increasing wide counters (at least 62 bits).
   Copyright (C) 2016-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */




/* Counter that is monotonically increasing (by less than 2**31 per
   increment), with a single writer, and an arbitrary number of
   readers.  */
typedef union
{
  __extension__ unsigned long long int __value64;
  struct
  {
    unsigned int __low;
    unsigned int __high;
  } __value32;
} __atomic_wide_counter;
# 47 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 2 3 4


/* Common definition of pthread_mutex_t. */

typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;

typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;

/* Arch-specific mutex definitions.  A generic implementation is provided
   by sysdeps/nptl/bits/struct_mutex.h.  If required, an architecture
   can override it by defining:

   1. struct __pthread_mutex_s (used on both pthread_mutex_t and mtx_t
      definition).  It should contains at least the internal members
      defined in the generic version.

   2. __LOCK_ALIGNMENT for any extra attribute for internal lock used with
      atomic operations.

   3. The macro __PTHREAD_MUTEX_INITIALIZER used for static initialization.
      It should initialize the mutex internal flag.  */

# 1 "/usr/include/x86_64-linux-gnu/bits/struct_mutex.h" 1 3 4
/* x86 internal mutex struct definitions.
   Copyright (C) 2019-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */




struct __pthread_mutex_s
{
  int __lock;
  unsigned int __count;
  int __owner;

  unsigned int __nusers;

  /* KIND must stay at this position in the structure to maintain
     binary compatibility with static initializers.  */
  int __kind;

  short __spins;
  short __elision;
  __pthread_list_t __list;
# 53 "/usr/include/x86_64-linux-gnu/bits/struct_mutex.h" 3 4
};
# 77 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 2 3 4

/* Arch-sepecific read-write lock definitions.  A generic implementation is
   provided by struct_rwlock.h.  If required, an architecture can override it
   by defining:

   1. struct __pthread_rwlock_arch_t (used on pthread_rwlock_t definition).
      It should contain at least the internal members defined in the
      generic version.

   2. The macro __PTHREAD_RWLOCK_INITIALIZER used for static initialization.
      It should initialize the rwlock internal type.  */

# 1 "/usr/include/x86_64-linux-gnu/bits/struct_rwlock.h" 1 3 4
/* x86 internal rwlock struct definitions.
   Copyright (C) 2019-2022 Free Software Foundation, Inc.

   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */




struct __pthread_rwlock_arch_t
{
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;

  int __cur_writer;
  int __shared;
  signed char __rwelision;




  unsigned char __pad1[7];


  unsigned long int __pad2;
  /* FLAGS must stay at this position in the structure to maintain
     binary compatibility.  */
  unsigned int __flags;
# 55 "/usr/include/x86_64-linux-gnu/bits/struct_rwlock.h" 3 4
};
# 90 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 2 3 4


/* Common definition of pthread_cond_t. */

struct __pthread_cond_s
{
  __atomic_wide_counter __wseq;
  __atomic_wide_counter __g1_start;
  unsigned int __g_refs[2] ;
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};

typedef unsigned int __tss_t;
typedef unsigned long int __thrd_t;

typedef struct
{
  int __data ;
} __once_flag;
# 24 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 2 3 4

/* Thread identifiers.  The structure of the attribute type is not
   exposed on purpose.  */
typedef unsigned long int pthread_t;


/* Data structures for mutex handling.  The structure of the attribute
   type is not exposed on purpose.  */
typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;


/* Data structure for condition variable handling.  The structure of
   the attribute type is not exposed on purpose.  */
typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;


/* Keys for thread-specific data */
typedef unsigned int pthread_key_t;


/* Once-only execution */
typedef int pthread_once_t;


union pthread_attr_t
{
  char __size[56];
  long int __align;
};

typedef union pthread_attr_t pthread_attr_t;




typedef union
{
  struct __pthread_mutex_s __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;


typedef union
{
  struct __pthread_cond_s __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;



/* Data structure for reader-writer lock variable handling.  The
   structure of the attribute type is deliberately not exposed.  */
typedef union
{
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;

typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;




/* POSIX spinlock data type.  */
typedef volatile int pthread_spinlock_t;


/* POSIX barriers data type.  The structure of the type is
   deliberately not exposed.  */
typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;
# 228 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4



# 396 "/usr/include/stdlib.h" 2 3 4

/* These are the functions that actually do things.  The `random', `srandom',
   `initstate' and `setstate' functions are those from BSD Unices.
   The `rand' and `srand' functions are required by the ANSI standard.
   We provide both interfaces to the same random number generator.  */
/* Return a random long integer between 0 and 2^31-1 inclusive.  */
extern long int random (void) __attribute__ ((__nothrow__ , __leaf__));

/* Seed the random number generator with the given number.  */
extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));

/* Initialize the random number generator to use state buffer STATEBUF,
   of length STATELEN, and seed it with SEED.  Optimal lengths are 8, 16,
   32, 64, 128 and 256, the bigger the better; values less than 8 will
   cause an error and values greater than 256 will be rounded down.  */
extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

/* Switch the random number generator to state buffer STATEBUF,
   which should have been previously initialized by `initstate'.  */
extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



/* Reentrant versions of the `random' family of functions.
   These functions all use the following data structure to contain
   state, rather than global state variables.  */

struct random_data
  {
    int32_t *fptr; /* Front pointer.  */
    int32_t *rptr; /* Rear pointer.  */
    int32_t *state; /* Array of state values.  */
    int rand_type; /* Type of random number generator.  */
    int rand_deg; /* Degree of random number generator.  */
    int rand_sep; /* Distance between front and rear.  */
    int32_t *end_ptr; /* Pointer behind state table.  */
  };

extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));

extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




/* Return a random integer between 0 and RAND_MAX inclusive.  */
extern int rand (void) __attribute__ ((__nothrow__ , __leaf__));
/* Seed the random number generator with the given number.  */
extern void srand (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));


/* Reentrant interface according to POSIX.1.  */
extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__ , __leaf__));




/* System V style 48-bit random number generator functions.  */

/* Return non-negative, double-precision floating-point value in [0.0,1.0).  */
extern double drand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

/* Return non-negative, long integer in [0,2^31).  */
extern long int lrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

/* Return signed, long integers in [-2^31,2^31).  */
extern long int mrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

/* Seed random number generator.  */
extern void srand48 (long int __seedval) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


/* Data structure for communication with thread safe versions.  This
   type is to be regarded as opaque.  It's only exported because users
   have to allocate objects of this type.  */
struct drand48_data
  {
    unsigned short int __x[3]; /* Current state.  */
    unsigned short int __old_x[3]; /* Old state.  */
    unsigned short int __c; /* Additive const. in congruential formula.  */
    unsigned short int __init; /* Flag for initializing.  */
    __extension__ unsigned long long int __a; /* Factor in congruential
						   formula.  */
  };

/* Return non-negative, double-precision floating-point value in [0.0,1.0).  */
extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

/* Return non-negative, long integer in [0,2^31).  */
extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

/* Return signed, long integers in [-2^31,2^31).  */
extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

/* Seed random number generator.  */
extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



/* Allocate SIZE bytes of memory.  */
extern void *malloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__))
     __attribute__ ((__alloc_size__ (1))) ;
/* Allocate NMEMB elements of SIZE bytes each, all initialized to 0.  */
extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (1, 2))) ;

/* Re-allocate the previously allocated block
   in PTR, making the new block SIZE bytes long.  */
/* __attribute_malloc__ is not used, because if realloc returns
   the same pointer that was passed to it, aliasing needs to be allowed
   between objects pointed by the old and new pointers.  */
extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__)) __attribute__ ((__alloc_size__ (2)));

/* Free a block allocated by `malloc', `realloc' or `calloc'.  */
extern void free (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));


/* Re-allocate the previously allocated block in PTR, making the new
   block large enough for NMEMB elements of SIZE bytes each.  */
/* __attribute_malloc__ is not used, because if reallocarray returns
   the same pointer that was passed to it, aliasing needs to be allowed
   between objects pointed by the old and new pointers.  */
extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__))
     __attribute__ ((__alloc_size__ (2, 3)))
    __attribute__ ((__malloc__ (__builtin_free, 1)));

/* Add reallocarray as its own deallocator.  */
extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__ (reallocarray, 1)));



# 1 "/usr/include/alloca.h" 1 3 4
/* Copyright (C) 1992-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */




# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 22 "/usr/include/alloca.h" 2 3 4


# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 1 3 4
/* Copyright (C) 1989-2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */






/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */
# 46 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */
# 86 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 111 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 159 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 235 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 387 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* A null pointer constant.  */
# 25 "/usr/include/alloca.h" 2 3 4



/* Remove any previous definition.  */


/* Allocate a block that will be freed when the calling function exits.  */
extern void *alloca (size_t __size) __attribute__ ((__nothrow__ , __leaf__));






# 575 "/usr/include/stdlib.h" 2 3 4




/* Allocate SIZE bytes on a page boundary.  The storage cannot be freed.  */
extern void *valloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__))
     __attribute__ ((__alloc_size__ (1))) ;



/* Allocate memory of SIZE bytes with an alignment of ALIGNMENT.  */
extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;



/* ISO C variant of aligned allocation.  */
extern void *aligned_alloc (size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_align__ (1)))
     __attribute__ ((__alloc_size__ (2))) ;


/* Abort execution and generate a core-dump.  */
extern void abort (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));


/* Register a function to be called when `exit' is called.  */
extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


/* Register a function to be called when `quick_exit' is called.  */




extern int at_quick_exit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));




/* Register a function to be called with the status
   given to `exit' and the given argument.  */
extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


/* Call all functions registered with `atexit' and `on_exit',
   in the reverse of the order in which they were registered,
   perform stdio cleanup, and terminate program execution with STATUS.  */
extern void exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));


/* Call all functions registered with `at_quick_exit' in the reverse
   of the order in which they were registered and terminate program
   execution with STATUS.  */
extern void quick_exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));



/* Terminate the program with STATUS without calling any of the
   functions registered with `atexit' or `on_exit'.  */
extern void _Exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));



/* Return the value of envariable NAME, or NULL if it doesn't exist.  */
extern char *getenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 651 "/usr/include/stdlib.h" 3 4
/* The SVID says this is in <stdio.h>, but this seems a better place.	*/
/* Put STRING, which is of the form "NAME=VALUE", in the environment.
   If there is no `=', remove NAME from the environment.  */
extern int putenv (char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



/* Set NAME to VALUE in the environment.
   If REPLACE is nonzero, overwrite an existing value.  */
extern int setenv (const char *__name, const char *__value, int __replace)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

/* Remove the variable NAME from the environment.  */
extern int unsetenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



/* The `clearenv' was planned to be added to POSIX.1 but probably
   never made it.  Nevertheless the POSIX.9 standard (POSIX bindings
   for Fortran 77) requires this function.  */
extern int clearenv (void) __attribute__ ((__nothrow__ , __leaf__));





/* Generate a unique temporary file name from TEMPLATE.
   The last six characters of TEMPLATE must be "XXXXXX";
   they are replaced with a string that makes the file name unique.
   Always returns TEMPLATE, it's either a temporary file name or a null
   string if it cannot get a unique file name.  */
extern char *mktemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



/* Generate a unique temporary file name from TEMPLATE.
   The last six characters of TEMPLATE must be "XXXXXX";
   they are replaced with a string that makes the filename unique.
   Returns a file descriptor open on the file for reading and writing,
   or -1 if it cannot create a uniquely-named file.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */

extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
# 710 "/usr/include/stdlib.h" 3 4
/* Similar to mkstemp, but the template can have a suffix after the
   XXXXXX.  The length of the suffix is specified in the second
   parameter.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */

extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
# 733 "/usr/include/stdlib.h" 3 4
/* Create a unique temporary directory from TEMPLATE.
   The last six characters of TEMPLATE must be "XXXXXX";
   they are replaced with a string that makes the directory name unique.
   Returns TEMPLATE, or a null pointer if it cannot get a unique name.
   The directory is created mode 700.  */
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 787 "/usr/include/stdlib.h" 3 4
/* Execute the given line as a shell command.

   This function is a cancellation point and therefore not marked with
   __THROW.  */
extern int system (const char *__command) ;
# 803 "/usr/include/stdlib.h" 3 4
/* Return the canonical absolute name of file NAME.  If RESOLVED is
   null, the result is malloc'd; otherwise, if the canonical name is
   PATH_MAX chars or more, returns null with `errno' set to
   ENAMETOOLONG; if the name fits in fewer than PATH_MAX chars,
   returns the name in RESOLVED.  */
extern char *realpath (const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__ , __leaf__)) ;



/* Shorthand for type of comparison functions.  */


typedef int (*__compar_fn_t) (const void *, const void *);
# 826 "/usr/include/stdlib.h" 3 4
/* Do a binary search for KEY in BASE, which consists of NMEMB elements
   of SIZE bytes each, using COMPAR to perform the comparisons.  */
extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;





/* Sort NMEMB elements of BASE, of SIZE bytes each,
   using COMPAR to perform the comparisons.  */
extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));







/* Return the absolute value of X.  */
extern int abs (int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;


__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;



/* Return the `div_t', `ldiv_t' or `lldiv_t' representation
   of the value of NUMER over DENOM. */
/* GCC may have built-ins for these someday.  */
extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;


__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;





/* Convert floating point numbers to strings.  The returned values are
   valid only until another call to the same function.  */

/* Convert VALUE to a string with NDIGIT digits and return a pointer to
   this.  Set *DECPT with the position of the decimal character and *SIGN
   with the sign of the number.  */
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;

/* Convert VALUE to a string rounded to NDIGIT decimal digits.  Set *DECPT
   with the position of the decimal character and *SIGN with the sign of
   the number.  */
extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;

/* If possible convert VALUE to a string with NDIGIT significant digits.
   Otherwise use exponential representation.  The resulting string will
   be written to BUF.  */
extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;



/* Long double versions of above functions.  */
extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;


/* Reentrant version of the functions above which provide their own
   buffers.  */
extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));

extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));



/* Return the length of the multibyte character
   in S, which is no longer than N.  */
extern int mblen (const char *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
/* Return the length of the given multibyte character,
   putting its `wchar_t' representation in *PWC.  */
extern int mbtowc (wchar_t *__restrict __pwc,
     const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
/* Put the multibyte character represented
   by WCHAR in S, returning its length.  */
extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__ , __leaf__));


/* Convert a multibyte string to a wide char string.  */
extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__read_only__, 2)));
/* Convert a wide char string to multibyte string.  */
extern size_t wcstombs (char *__restrict __s,
   const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 1, 3)))
  __attribute__ ((__access__ (__read_only__, 2)));


/* Determine whether the string value of RESPONSE matches the affirmation
   or negative response expression as specified by the LC_MESSAGES category
   in the program's current locale.  Returns 1 if affirmative, 0 if
   negative, and -1 if not matching.  */
extern int rpmatch (const char *__response) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;




/* Parse comma separated suboption from *OPTIONP and match against
   strings in TOKENS.  If found return index and set *VALUEP to
   optional value introduced by an equal sign.  If the suboption is
   not part of TOKENS return in *VALUEP beginning of unknown
   suboption.  On exit *OPTIONP is set to the beginning of the next
   token or at the terminating NUL character.  */
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3))) ;



/* X/Open pseudo terminal handling.  */
# 1010 "/usr/include/stdlib.h" 3 4
/* Put the 1 minute, 5 minute and 15 minute load averages into the first
   NELEM elements of LOADAVG.  Return the number written (never more than
   three, but may be less than NELEM), or -1 if an error occurred.  */
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 1023 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/stdlib-float.h" 1 3 4
/* Floating-point inline functions for stdlib.h.
   Copyright (C) 2012-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 1024 "/usr/include/stdlib.h" 2 3 4

/* Define some macros helping to catch buffer overflows.  */




# 1 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 1 3 4
/* Macros to control TS 18661-3 glibc features on x86.
   Copyright (C) 2017-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 1031 "/usr/include/stdlib.h" 2 3 4





# 18 "/home/anton/revenant/game/headers/strings.h" 2 3 4
# 1 "/usr/include/stdio.h" 1 3 4
/* Define ISO C stdio on top of C++ iostreams.
   Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.19 Input/output	<stdio.h>
 */
# 19 "/home/anton/revenant/game/headers/strings.h" 2 3 4
# 1 "/usr/include/string.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.21 String handling	<string.h>
 */
# 20 "/home/anton/revenant/game/headers/strings.h" 2 3 4

# 1 "/usr/include/math.h" 1 3 4
/* Declarations for math functions.
   Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.12 Mathematics	<math.h>
 */





# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
/* Handle feature test macros at the start of a header.
   Copyright (C) 2016-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* This header is internal to glibc and should not be included outside
   of glibc headers.  Headers including it must define
   __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION first.  This header
   cannot have multiple include guards because ISO C feature test
   macros depend on the definition of the macro when an affected
   header is included, not when the first system header is
   included.  */







# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 34 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 2 3 4

/* ISO/IEC TR 24731-2:2010 defines the __STDC_WANT_LIB_EXT2__
   macro.  */
# 45 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
/* ISO/IEC TS 18661-1:2014 defines the __STDC_WANT_IEC_60559_BFP_EXT__
   macro.  Most but not all symbols enabled by that macro in TS
   18661-1 are enabled unconditionally in C2X.  In C2X, the symbols in
   Annex F still require a new feature test macro
   __STDC_WANT_IEC_60559_EXT__ instead (C2X does not define
   __STDC_WANT_IEC_60559_BFP_EXT__), while a few features from TS
   18661-1 are not included in C2X (and thus should depend on
   __STDC_WANT_IEC_60559_BFP_EXT__ even when C2X features are
   enabled).

   __GLIBC_USE (IEC_60559_BFP_EXT) controls those features from TS
   18661-1 not included in C2X.

   __GLIBC_USE (IEC_60559_BFP_EXT_C2X) controls those features from TS
   18661-1 that are also included in C2X (with no feature test macro
   required in C2X).

   __GLIBC_USE (IEC_60559_EXT) controls those features from TS 18661-1
   that are included in C2X but conditional on
   __STDC_WANT_IEC_60559_EXT__.  (There are currently no features
   conditional on __STDC_WANT_IEC_60559_EXT__ that are not in TS
   18661-1.)  */
# 86 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
/* ISO/IEC TS 18661-4:2015 defines the
   __STDC_WANT_IEC_60559_FUNCS_EXT__ macro.  Other than the reduction
   functions, the symbols from this TS are enabled unconditionally in
   C2X.  */
# 103 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
/* ISO/IEC TS 18661-3:2015 defines the
   __STDC_WANT_IEC_60559_TYPES_EXT__ macro.  */
# 28 "/usr/include/math.h" 2 3 4








/* Get definitions of __intmax_t and __uintmax_t.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 38 "/usr/include/math.h" 2 3 4

/* Get machine-dependent vector math functions declarations.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/math-vector.h" 1 3 4
/* Platform-specific SIMD declarations of math functions.
   Copyright (C) 2014-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */






/* Get default empty definitions for simd declarations.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/libm-simd-decl-stubs.h" 1 3 4
/* Empty definitions required for __MATHCALL_VEC unfolding in mathcalls.h.
   Copyright (C) 2014-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */






/* Needed definitions could be generated with:
   for func in $(grep __MATHCALL_VEC math/bits/mathcalls.h |		 sed -r "s|__MATHCALL_VEC.?\(||; s|,.*||"); do
o
     echo "#define __DECL_SIMD_${func}";
     echo "#define __DECL_SIMD_${func}f";
     echo "#define __DECL_SIMD_${func}l";
   done
 */
# 26 "/usr/include/x86_64-linux-gnu/bits/math-vector.h" 2 3 4
# 41 "/usr/include/math.h" 2 3 4

/* Gather machine dependent type support.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 1 3 4
/* Macros to control TS 18661-3 glibc features on x86.
   Copyright (C) 2017-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 44 "/usr/include/math.h" 2 3 4

/* Value returned on overflow.  With IEEE 754 floating point, this is
   +Infinity, otherwise the largest representable positive value.  */
# 89 "/usr/include/math.h" 3 4
/* IEEE positive infinity.  */






/* IEEE Not A Number.  */
# 151 "/usr/include/math.h" 3 4
/* Get __GLIBC_FLT_EVAL_METHOD.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/flt-eval-method.h" 1 3 4
/* Define __GLIBC_FLT_EVAL_METHOD.  x86 version.
   Copyright (C) 2016-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 153 "/usr/include/math.h" 2 3 4


/* Define the following typedefs.

    float_t	floating-point type at least as wide as `float' used
		to evaluate `float' expressions
    double_t	floating-point type at least as wide as `double' used
		to evaluate `double' expressions
*/

typedef float float_t;
typedef double double_t;
# 194 "/usr/include/math.h" 3 4
/* Define macros for the return values of ilogb and llogb, based on
   __FP_LOGB0_IS_MIN and __FP_LOGBNAN_IS_MIN.

    FP_ILOGB0	Expands to a value returned by `ilogb (0.0)'.
    FP_ILOGBNAN	Expands to a value returned by `ilogb (NAN)'.
    FP_LLOGB0	Expands to a value returned by `llogb (0.0)'.
    FP_LLOGBNAN	Expands to a value returned by `llogb (NAN)'.

*/

# 1 "/usr/include/x86_64-linux-gnu/bits/fp-logb.h" 1 3 4
/* Define __FP_LOGB0_IS_MIN and __FP_LOGBNAN_IS_MIN.  x86 version.
   Copyright (C) 2016-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 205 "/usr/include/math.h" 2 3 4
# 235 "/usr/include/math.h" 3 4
/* Get the architecture specific values describing the floating-point
   evaluation.  The following symbols will get defined:

    FP_FAST_FMA
    FP_FAST_FMAF
    FP_FAST_FMAL
		If defined it indicates that the `fma' function
		generally executes about as fast as a multiply and an add.
		This macro is defined only iff the `fma' function is
		implemented directly with a hardware multiply-add instructions.
*/

# 1 "/usr/include/x86_64-linux-gnu/bits/fp-fast.h" 1 3 4
/* Define FP_FAST_* macros.
   Copyright (C) 2016-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */







/* The GCC 4.6 compiler will define __FP_FAST_FMA{,F,L} if the fma{,f,l}
   builtins are supported.  */
# 248 "/usr/include/math.h" 2 3 4
# 271 "/usr/include/math.h" 3 4
/* The file <bits/mathcalls.h> contains the prototypes for all the
   actual math functions.  These macros are used for those prototypes,
   so we can easily declare each function as both `name' and `__name',
   and can declare the float versions `namef' and `__namef'.  */
# 300 "/usr/include/math.h" 3 4
/* Ignore the alias by default.  The alias is only useful with
   redirections.  */
# 312 "/usr/include/math.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/mathcalls-helper-functions.h" 1 3 4
/* Prototype declarations for math classification macros helpers.
   Copyright (C) 2017-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* Classify given number.  */
extern int __fpclassify (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));

/* Test for negative number.  */
extern int __signbit (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));

/* Return 0 if VALUE is finite or NaN, +1 if it
   is +Infinity, -1 if it is -Infinity.  */
extern int __isinf (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));

/* Return nonzero if VALUE is finite and not NaN.  Used by isfinite macro.  */
extern int __finite (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));

/* Return nonzero if VALUE is not a number.  */
extern int __isnan (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));

/* Test equality.  */
extern int __iseqsig (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));

/* Test for signaling NaN.  */
extern int __issignaling (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
# 313 "/usr/include/math.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 1 3 4
/* Prototype declarations for math functions; helper file for <math.h>.
   Copyright (C) 1996-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* NOTE: Because of the special way this file is used by <math.h>, this
   file must NOT be protected from multiple inclusion as header files
   usually are.

   This file provides prototype declarations for the math functions.
   Most functions are declared using the macro:

   __MATHCALL (NAME,[_r], (ARGS...));

   This means there is a function `NAME' returning `double' and a function
   `NAMEf' returning `float'.  Each place `_Mdouble_' appears in the
   prototype, that is actually `double' in the prototype for `NAME' and
   `float' in the prototype for `NAMEf'.  Reentrant variant functions are
   called `NAME_r' and `NAMEf_r'.

   Functions returning other types like `int' are declared using the macro:

   __MATHDECL (TYPE, NAME,[_r], (ARGS...));

   This is just like __MATHCALL but for a function returning `TYPE'
   instead of `_Mdouble_'.  In all of these cases, there is still
   both a `NAME' and a `NAMEf' that takes `float' arguments.

   Note that there must be no whitespace before the argument passed for
   NAME, to make token pasting work with -traditional.  */






/* Trigonometric functions.  */

/* Arc cosine of X.  */
 extern double acos (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __acos (double __x) __attribute__ ((__nothrow__ , __leaf__));
/* Arc sine of X.  */
 extern double asin (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __asin (double __x) __attribute__ ((__nothrow__ , __leaf__));
/* Arc tangent of X.  */
 extern double atan (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atan (double __x) __attribute__ ((__nothrow__ , __leaf__));
/* Arc tangent of Y/X.  */
 extern double atan2 (double __y, double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atan2 (double __y, double __x) __attribute__ ((__nothrow__ , __leaf__));

/* Cosine of X.  */
 extern double cos (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cos (double __x) __attribute__ ((__nothrow__ , __leaf__));
/* Sine of X.  */
 extern double sin (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sin (double __x) __attribute__ ((__nothrow__ , __leaf__));
/* Tangent of X.  */
 extern double tan (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __tan (double __x) __attribute__ ((__nothrow__ , __leaf__));

/* Hyperbolic functions.  */

/* Hyperbolic cosine of X.  */
 extern double cosh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cosh (double __x) __attribute__ ((__nothrow__ , __leaf__));
/* Hyperbolic sine of X.  */
 extern double sinh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sinh (double __x) __attribute__ ((__nothrow__ , __leaf__));
/* Hyperbolic tangent of X.  */
 extern double tanh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __tanh (double __x) __attribute__ ((__nothrow__ , __leaf__));
# 84 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
/* Hyperbolic arc cosine of X.  */
 extern double acosh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __acosh (double __x) __attribute__ ((__nothrow__ , __leaf__));
/* Hyperbolic arc sine of X.  */
 extern double asinh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __asinh (double __x) __attribute__ ((__nothrow__ , __leaf__));
/* Hyperbolic arc tangent of X.  */
 extern double atanh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atanh (double __x) __attribute__ ((__nothrow__ , __leaf__));


/* Exponential and logarithmic functions.  */

/* Exponential function of X.  */
 extern double exp (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __exp (double __x) __attribute__ ((__nothrow__ , __leaf__));

/* Break VALUE into a normalized fraction and an integral power of 2.  */
extern double frexp (double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern double __frexp (double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));

/* X times (two to the EXP power).  */
extern double ldexp (double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern double __ldexp (double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));

/* Natural logarithm of X.  */
 extern double log (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log (double __x) __attribute__ ((__nothrow__ , __leaf__));

/* Base-ten logarithm of X.  */
 extern double log10 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log10 (double __x) __attribute__ ((__nothrow__ , __leaf__));

/* Break VALUE into integral and fractional parts.  */
extern double modf (double __x, double *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern double __modf (double __x, double *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));







/* Return exp(X) - 1.  */
 extern double expm1 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __expm1 (double __x) __attribute__ ((__nothrow__ , __leaf__));

/* Return log(1 + X).  */
 extern double log1p (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log1p (double __x) __attribute__ ((__nothrow__ , __leaf__));

/* Return the base 2 signed integral exponent of X.  */
extern double logb (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __logb (double __x) __attribute__ ((__nothrow__ , __leaf__));



/* Compute base-2 exponential of X.  */
 extern double exp2 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __exp2 (double __x) __attribute__ ((__nothrow__ , __leaf__));

/* Compute base-2 logarithm of X.  */
 extern double log2 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log2 (double __x) __attribute__ ((__nothrow__ , __leaf__));



/* Power functions.  */

/* Return X to the Y power.  */
 extern double pow (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __pow (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));

/* Return the square root of X.  */
extern double sqrt (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sqrt (double __x) __attribute__ ((__nothrow__ , __leaf__));


/* Return `sqrt(X*X + Y*Y)'.  */
 extern double hypot (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __hypot (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));



/* Return the cube root of X.  */
 extern double cbrt (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cbrt (double __x) __attribute__ ((__nothrow__ , __leaf__));



/* Nearest integer, absolute value, and remainder functions.  */

/* Smallest integral value not less than X.  */
extern double ceil (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __ceil (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

/* Absolute value of X.  */
extern double fabs (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fabs (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

/* Largest integer not greater than X.  */
extern double floor (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __floor (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

/* Floating-point modulo remainder of X/Y.  */
extern double fmod (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __fmod (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));






/* Return 0 if VALUE is finite or NaN, +1 if it
   is +Infinity, -1 if it is -Infinity.  */
extern int isinf (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));



/* Return nonzero if VALUE is finite and not NaN.  */
extern int finite (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));

/* Return the remainder of X/Y.  */
extern double drem (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __drem (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));


/* Return the fractional part of X after dividing out `ilogb (X)'.  */
extern double significand (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __significand (double __x) __attribute__ ((__nothrow__ , __leaf__));





/* Return X with its signed changed to Y's.  */
extern double copysign (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __copysign (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



/* Return representation of qNaN for double type.  */
extern double nan (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern double __nan (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
# 212 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
/* Return nonzero if VALUE is not a number.  */
extern int isnan (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));




/* Bessel functions.  */
extern double j0 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __j0 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double j1 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __j1 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double jn (int, double) __attribute__ ((__nothrow__ , __leaf__)); extern double __jn (int, double) __attribute__ ((__nothrow__ , __leaf__));
extern double y0 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __y0 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double y1 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __y1 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double yn (int, double) __attribute__ ((__nothrow__ , __leaf__)); extern double __yn (int, double) __attribute__ ((__nothrow__ , __leaf__));




/* Error and gamma functions.  */
 extern double erf (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __erf (double) __attribute__ ((__nothrow__ , __leaf__));
 extern double erfc (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __erfc (double) __attribute__ ((__nothrow__ , __leaf__));
extern double lgamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __lgamma (double) __attribute__ ((__nothrow__ , __leaf__));



/* True gamma function.  */
extern double tgamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __tgamma (double) __attribute__ ((__nothrow__ , __leaf__));




/* Obsolete alias for `lgamma'.  */
extern double gamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __gamma (double) __attribute__ ((__nothrow__ , __leaf__));




/* Reentrant version of lgamma.  This function uses the global variable
   `signgam'.  The reentrant version instead takes a pointer and stores
   the value through it.  */
extern double lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern double __lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));




/* Return the integer nearest X in the direction of the
   prevailing rounding mode.  */
extern double rint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __rint (double __x) __attribute__ ((__nothrow__ , __leaf__));

/* Return X + epsilon if X < Y, X - epsilon if X > Y.  */
extern double nextafter (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __nextafter (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));

extern double nexttoward (double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __nexttoward (double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
# 274 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
/* Return the remainder of integer divison X / Y with infinite precision.  */
extern double remainder (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __remainder (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));


/* Return X times (2 to the Nth power).  */
extern double scalbn (double __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalbn (double __x, int __n) __attribute__ ((__nothrow__ , __leaf__));


/* Return the binary exponent of X, which must be nonzero.  */
extern int ilogb (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogb (double __x) __attribute__ ((__nothrow__ , __leaf__));
# 292 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
/* Return X times (2 to the Nth power).  */
extern double scalbln (double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalbln (double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));

/* Round X to integral value in floating-point format using current
   rounding direction, but do not raise inexact exception.  */
extern double nearbyint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __nearbyint (double __x) __attribute__ ((__nothrow__ , __leaf__));

/* Round X to nearest integral value, rounding halfway cases away from
   zero.  */
extern double round (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __round (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

/* Round X to the integral value in floating-point format nearest but
   not larger in magnitude.  */
extern double trunc (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __trunc (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

/* Compute remainder of X and Y and put in *QUO a value with sign of x/y
   and magnitude congruent `mod 2^n' to the magnitude of the integral
   quotient x/y, with n >= 3.  */
extern double remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern double __remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));


/* Conversion functions.  */

/* Round X to nearest integral value according to current rounding
   direction.  */
extern long int lrint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrint (double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrint (double __x) __attribute__ ((__nothrow__ , __leaf__));

/* Round X to nearest integral value, rounding halfway cases away from
   zero.  */
extern long int lround (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lround (double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llround (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llround (double __x) __attribute__ ((__nothrow__ , __leaf__));


/* Return positive difference between X and Y.  */
extern double fdim (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __fdim (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));


/* Return maximum numeric value from X and Y.  */
extern double fmax (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmax (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

/* Return minimum numeric value from X and Y.  */
extern double fmin (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmin (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


/* Multiply-add function computed as a ternary operation.  */
extern double fma (double __x, double __y, double __z) __attribute__ ((__nothrow__ , __leaf__)); extern double __fma (double __x, double __y, double __z) __attribute__ ((__nothrow__ , __leaf__));
# 434 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
/* Return X times (2 to the Nth power).  */
extern double scalb (double __x, double __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalb (double __x, double __n) __attribute__ ((__nothrow__ , __leaf__));
# 314 "/usr/include/math.h" 2 3 4
# 322 "/usr/include/math.h" 3 4
/* Include the file of declarations again, this time using `float'
   instead of `double' and appending f to each function name.  */





# 1 "/usr/include/x86_64-linux-gnu/bits/mathcalls-helper-functions.h" 1 3 4
/* Prototype declarations for math classification macros helpers.
   Copyright (C) 2017-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* Classify given number.  */
extern int __fpclassifyf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));

/* Test for negative number.  */
extern int __signbitf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));

/* Return 0 if VALUE is finite or NaN, +1 if it
   is +Infinity, -1 if it is -Infinity.  */
extern int __isinff (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));

/* Return nonzero if VALUE is finite and not NaN.  Used by isfinite macro.  */
extern int __finitef (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));

/* Return nonzero if VALUE is not a number.  */
extern int __isnanf (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));

/* Test equality.  */
extern int __iseqsigf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));

/* Test for signaling NaN.  */
extern int __issignalingf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
# 330 "/usr/include/math.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 1 3 4
/* Prototype declarations for math functions; helper file for <math.h>.
   Copyright (C) 1996-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* NOTE: Because of the special way this file is used by <math.h>, this
   file must NOT be protected from multiple inclusion as header files
   usually are.

   This file provides prototype declarations for the math functions.
   Most functions are declared using the macro:

   __MATHCALL (NAME,[_r], (ARGS...));

   This means there is a function `NAME' returning `double' and a function
   `NAMEf' returning `float'.  Each place `_Mdouble_' appears in the
   prototype, that is actually `double' in the prototype for `NAME' and
   `float' in the prototype for `NAMEf'.  Reentrant variant functions are
   called `NAME_r' and `NAMEf_r'.

   Functions returning other types like `int' are declared using the macro:

   __MATHDECL (TYPE, NAME,[_r], (ARGS...));

   This is just like __MATHCALL but for a function returning `TYPE'
   instead of `_Mdouble_'.  In all of these cases, there is still
   both a `NAME' and a `NAMEf' that takes `float' arguments.

   Note that there must be no whitespace before the argument passed for
   NAME, to make token pasting work with -traditional.  */






/* Trigonometric functions.  */

/* Arc cosine of X.  */
 extern float acosf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __acosf (float __x) __attribute__ ((__nothrow__ , __leaf__));
/* Arc sine of X.  */
 extern float asinf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __asinf (float __x) __attribute__ ((__nothrow__ , __leaf__));
/* Arc tangent of X.  */
 extern float atanf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atanf (float __x) __attribute__ ((__nothrow__ , __leaf__));
/* Arc tangent of Y/X.  */
 extern float atan2f (float __y, float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atan2f (float __y, float __x) __attribute__ ((__nothrow__ , __leaf__));

/* Cosine of X.  */
 extern float cosf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __cosf (float __x) __attribute__ ((__nothrow__ , __leaf__));
/* Sine of X.  */
 extern float sinf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sinf (float __x) __attribute__ ((__nothrow__ , __leaf__));
/* Tangent of X.  */
 extern float tanf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __tanf (float __x) __attribute__ ((__nothrow__ , __leaf__));

/* Hyperbolic functions.  */

/* Hyperbolic cosine of X.  */
 extern float coshf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __coshf (float __x) __attribute__ ((__nothrow__ , __leaf__));
/* Hyperbolic sine of X.  */
 extern float sinhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sinhf (float __x) __attribute__ ((__nothrow__ , __leaf__));
/* Hyperbolic tangent of X.  */
 extern float tanhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __tanhf (float __x) __attribute__ ((__nothrow__ , __leaf__));
# 84 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
/* Hyperbolic arc cosine of X.  */
 extern float acoshf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __acoshf (float __x) __attribute__ ((__nothrow__ , __leaf__));
/* Hyperbolic arc sine of X.  */
 extern float asinhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __asinhf (float __x) __attribute__ ((__nothrow__ , __leaf__));
/* Hyperbolic arc tangent of X.  */
 extern float atanhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atanhf (float __x) __attribute__ ((__nothrow__ , __leaf__));


/* Exponential and logarithmic functions.  */

/* Exponential function of X.  */
 extern float expf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __expf (float __x) __attribute__ ((__nothrow__ , __leaf__));

/* Break VALUE into a normalized fraction and an integral power of 2.  */
extern float frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern float __frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));

/* X times (two to the EXP power).  */
extern float ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern float __ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));

/* Natural logarithm of X.  */
 extern float logf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __logf (float __x) __attribute__ ((__nothrow__ , __leaf__));

/* Base-ten logarithm of X.  */
 extern float log10f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log10f (float __x) __attribute__ ((__nothrow__ , __leaf__));

/* Break VALUE into integral and fractional parts.  */
extern float modff (float __x, float *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern float __modff (float __x, float *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));







/* Return exp(X) - 1.  */
 extern float expm1f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __expm1f (float __x) __attribute__ ((__nothrow__ , __leaf__));

/* Return log(1 + X).  */
 extern float log1pf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log1pf (float __x) __attribute__ ((__nothrow__ , __leaf__));

/* Return the base 2 signed integral exponent of X.  */
extern float logbf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __logbf (float __x) __attribute__ ((__nothrow__ , __leaf__));



/* Compute base-2 exponential of X.  */
 extern float exp2f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __exp2f (float __x) __attribute__ ((__nothrow__ , __leaf__));

/* Compute base-2 logarithm of X.  */
 extern float log2f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log2f (float __x) __attribute__ ((__nothrow__ , __leaf__));



/* Power functions.  */

/* Return X to the Y power.  */
 extern float powf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __powf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));

/* Return the square root of X.  */
extern float sqrtf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sqrtf (float __x) __attribute__ ((__nothrow__ , __leaf__));


/* Return `sqrt(X*X + Y*Y)'.  */
 extern float hypotf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __hypotf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));



/* Return the cube root of X.  */
 extern float cbrtf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __cbrtf (float __x) __attribute__ ((__nothrow__ , __leaf__));



/* Nearest integer, absolute value, and remainder functions.  */

/* Smallest integral value not less than X.  */
extern float ceilf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __ceilf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

/* Absolute value of X.  */
extern float fabsf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fabsf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

/* Largest integer not greater than X.  */
extern float floorf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __floorf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

/* Floating-point modulo remainder of X/Y.  */
extern float fmodf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __fmodf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));






/* Return 0 if VALUE is finite or NaN, +1 if it
   is +Infinity, -1 if it is -Infinity.  */
extern int isinff (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));



/* Return nonzero if VALUE is finite and not NaN.  */
extern int finitef (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));

/* Return the remainder of X/Y.  */
extern float dremf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __dremf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));


/* Return the fractional part of X after dividing out `ilogb (X)'.  */
extern float significandf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __significandf (float __x) __attribute__ ((__nothrow__ , __leaf__));





/* Return X with its signed changed to Y's.  */
extern float copysignf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __copysignf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



/* Return representation of qNaN for double type.  */
extern float nanf (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern float __nanf (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
# 212 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
/* Return nonzero if VALUE is not a number.  */
extern int isnanf (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));




/* Bessel functions.  */
extern float j0f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __j0f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float j1f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __j1f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float jnf (int, float) __attribute__ ((__nothrow__ , __leaf__)); extern float __jnf (int, float) __attribute__ ((__nothrow__ , __leaf__));
extern float y0f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __y0f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float y1f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __y1f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float ynf (int, float) __attribute__ ((__nothrow__ , __leaf__)); extern float __ynf (int, float) __attribute__ ((__nothrow__ , __leaf__));




/* Error and gamma functions.  */
 extern float erff (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __erff (float) __attribute__ ((__nothrow__ , __leaf__));
 extern float erfcf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __erfcf (float) __attribute__ ((__nothrow__ , __leaf__));
extern float lgammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __lgammaf (float) __attribute__ ((__nothrow__ , __leaf__));



/* True gamma function.  */
extern float tgammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __tgammaf (float) __attribute__ ((__nothrow__ , __leaf__));




/* Obsolete alias for `lgamma'.  */
extern float gammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __gammaf (float) __attribute__ ((__nothrow__ , __leaf__));




/* Reentrant version of lgamma.  This function uses the global variable
   `signgam'.  The reentrant version instead takes a pointer and stores
   the value through it.  */
extern float lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern float __lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));




/* Return the integer nearest X in the direction of the
   prevailing rounding mode.  */
extern float rintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __rintf (float __x) __attribute__ ((__nothrow__ , __leaf__));

/* Return X + epsilon if X < Y, X - epsilon if X > Y.  */
extern float nextafterf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __nextafterf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));

extern float nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
# 274 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
/* Return the remainder of integer divison X / Y with infinite precision.  */
extern float remainderf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __remainderf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));


/* Return X times (2 to the Nth power).  */
extern float scalbnf (float __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalbnf (float __x, int __n) __attribute__ ((__nothrow__ , __leaf__));


/* Return the binary exponent of X, which must be nonzero.  */
extern int ilogbf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbf (float __x) __attribute__ ((__nothrow__ , __leaf__));
# 292 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
/* Return X times (2 to the Nth power).  */
extern float scalblnf (float __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalblnf (float __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));

/* Round X to integral value in floating-point format using current
   rounding direction, but do not raise inexact exception.  */
extern float nearbyintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __nearbyintf (float __x) __attribute__ ((__nothrow__ , __leaf__));

/* Round X to nearest integral value, rounding halfway cases away from
   zero.  */
extern float roundf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __roundf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

/* Round X to the integral value in floating-point format nearest but
   not larger in magnitude.  */
extern float truncf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __truncf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

/* Compute remainder of X and Y and put in *QUO a value with sign of x/y
   and magnitude congruent `mod 2^n' to the magnitude of the integral
   quotient x/y, with n >= 3.  */
extern float remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern float __remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));


/* Conversion functions.  */

/* Round X to nearest integral value according to current rounding
   direction.  */
extern long int lrintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintf (float __x) __attribute__ ((__nothrow__ , __leaf__));

/* Round X to nearest integral value, rounding halfway cases away from
   zero.  */
extern long int lroundf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundf (float __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundf (float __x) __attribute__ ((__nothrow__ , __leaf__));


/* Return positive difference between X and Y.  */
extern float fdimf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __fdimf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));


/* Return maximum numeric value from X and Y.  */
extern float fmaxf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fmaxf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

/* Return minimum numeric value from X and Y.  */
extern float fminf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fminf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


/* Multiply-add function computed as a ternary operation.  */
extern float fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__ , __leaf__)); extern float __fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__ , __leaf__));
# 434 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
/* Return X times (2 to the Nth power).  */
extern float scalbf (float __x, float __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalbf (float __x, float __n) __attribute__ ((__nothrow__ , __leaf__));
# 331 "/usr/include/math.h" 2 3 4
# 390 "/usr/include/math.h" 3 4
/* Include the file of declarations again, this time using `long double'
   instead of `double' and appending l to each function name.  */






# 1 "/usr/include/x86_64-linux-gnu/bits/mathcalls-helper-functions.h" 1 3 4
/* Prototype declarations for math classification macros helpers.
   Copyright (C) 2017-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* Classify given number.  */
extern int __fpclassifyl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));

/* Test for negative number.  */
extern int __signbitl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));

/* Return 0 if VALUE is finite or NaN, +1 if it
   is +Infinity, -1 if it is -Infinity.  */
extern int __isinfl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));

/* Return nonzero if VALUE is finite and not NaN.  Used by isfinite macro.  */
extern int __finitel (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));

/* Return nonzero if VALUE is not a number.  */
extern int __isnanl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));

/* Test equality.  */
extern int __iseqsigl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));

/* Test for signaling NaN.  */
extern int __issignalingl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
# 399 "/usr/include/math.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 1 3 4
/* Prototype declarations for math functions; helper file for <math.h>.
   Copyright (C) 1996-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* NOTE: Because of the special way this file is used by <math.h>, this
   file must NOT be protected from multiple inclusion as header files
   usually are.

   This file provides prototype declarations for the math functions.
   Most functions are declared using the macro:

   __MATHCALL (NAME,[_r], (ARGS...));

   This means there is a function `NAME' returning `double' and a function
   `NAMEf' returning `float'.  Each place `_Mdouble_' appears in the
   prototype, that is actually `double' in the prototype for `NAME' and
   `float' in the prototype for `NAMEf'.  Reentrant variant functions are
   called `NAME_r' and `NAMEf_r'.

   Functions returning other types like `int' are declared using the macro:

   __MATHDECL (TYPE, NAME,[_r], (ARGS...));

   This is just like __MATHCALL but for a function returning `TYPE'
   instead of `_Mdouble_'.  In all of these cases, there is still
   both a `NAME' and a `NAMEf' that takes `float' arguments.

   Note that there must be no whitespace before the argument passed for
   NAME, to make token pasting work with -traditional.  */






/* Trigonometric functions.  */

/* Arc cosine of X.  */
 extern long double acosl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __acosl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
/* Arc sine of X.  */
 extern long double asinl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __asinl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
/* Arc tangent of X.  */
 extern long double atanl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atanl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
/* Arc tangent of Y/X.  */
 extern long double atan2l (long double __y, long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atan2l (long double __y, long double __x) __attribute__ ((__nothrow__ , __leaf__));

/* Cosine of X.  */
 extern long double cosl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __cosl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
/* Sine of X.  */
 extern long double sinl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sinl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
/* Tangent of X.  */
 extern long double tanl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tanl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

/* Hyperbolic functions.  */

/* Hyperbolic cosine of X.  */
 extern long double coshl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __coshl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
/* Hyperbolic sine of X.  */
 extern long double sinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
/* Hyperbolic tangent of X.  */
 extern long double tanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
# 84 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
/* Hyperbolic arc cosine of X.  */
 extern long double acoshl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __acoshl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
/* Hyperbolic arc sine of X.  */
 extern long double asinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __asinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
/* Hyperbolic arc tangent of X.  */
 extern long double atanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


/* Exponential and logarithmic functions.  */

/* Exponential function of X.  */
 extern long double expl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __expl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

/* Break VALUE into a normalized fraction and an integral power of 2.  */
extern long double frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern long double __frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));

/* X times (two to the EXP power).  */
extern long double ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern long double __ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));

/* Natural logarithm of X.  */
 extern long double logl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __logl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

/* Base-ten logarithm of X.  */
 extern long double log10l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log10l (long double __x) __attribute__ ((__nothrow__ , __leaf__));

/* Break VALUE into integral and fractional parts.  */
extern long double modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern long double __modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));







/* Return exp(X) - 1.  */
 extern long double expm1l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __expm1l (long double __x) __attribute__ ((__nothrow__ , __leaf__));

/* Return log(1 + X).  */
 extern long double log1pl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log1pl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

/* Return the base 2 signed integral exponent of X.  */
extern long double logbl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __logbl (long double __x) __attribute__ ((__nothrow__ , __leaf__));



/* Compute base-2 exponential of X.  */
 extern long double exp2l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __exp2l (long double __x) __attribute__ ((__nothrow__ , __leaf__));

/* Compute base-2 logarithm of X.  */
 extern long double log2l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log2l (long double __x) __attribute__ ((__nothrow__ , __leaf__));



/* Power functions.  */

/* Return X to the Y power.  */
 extern long double powl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __powl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));

/* Return the square root of X.  */
extern long double sqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


/* Return `sqrt(X*X + Y*Y)'.  */
 extern long double hypotl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __hypotl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));



/* Return the cube root of X.  */
 extern long double cbrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __cbrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));



/* Nearest integer, absolute value, and remainder functions.  */

/* Smallest integral value not less than X.  */
extern long double ceill (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __ceill (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

/* Absolute value of X.  */
extern long double fabsl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fabsl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

/* Largest integer not greater than X.  */
extern long double floorl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __floorl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

/* Floating-point modulo remainder of X/Y.  */
extern long double fmodl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fmodl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));






/* Return 0 if VALUE is finite or NaN, +1 if it
   is +Infinity, -1 if it is -Infinity.  */
extern int isinfl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));



/* Return nonzero if VALUE is finite and not NaN.  */
extern int finitel (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));

/* Return the remainder of X/Y.  */
extern long double dreml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __dreml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));


/* Return the fractional part of X after dividing out `ilogb (X)'.  */
extern long double significandl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __significandl (long double __x) __attribute__ ((__nothrow__ , __leaf__));





/* Return X with its signed changed to Y's.  */
extern long double copysignl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __copysignl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



/* Return representation of qNaN for double type.  */
extern long double nanl (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nanl (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
# 212 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
/* Return nonzero if VALUE is not a number.  */
extern int isnanl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));




/* Bessel functions.  */
extern long double j0l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __j0l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double j1l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __j1l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double jnl (int, long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __jnl (int, long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double y0l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __y0l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double y1l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __y1l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double ynl (int, long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __ynl (int, long double) __attribute__ ((__nothrow__ , __leaf__));




/* Error and gamma functions.  */
 extern long double erfl (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __erfl (long double) __attribute__ ((__nothrow__ , __leaf__));
 extern long double erfcl (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __erfcl (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double lgammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __lgammal (long double) __attribute__ ((__nothrow__ , __leaf__));



/* True gamma function.  */
extern long double tgammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tgammal (long double) __attribute__ ((__nothrow__ , __leaf__));




/* Obsolete alias for `lgamma'.  */
extern long double gammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __gammal (long double) __attribute__ ((__nothrow__ , __leaf__));




/* Reentrant version of lgamma.  This function uses the global variable
   `signgam'.  The reentrant version instead takes a pointer and stores
   the value through it.  */
extern long double lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern long double __lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));




/* Return the integer nearest X in the direction of the
   prevailing rounding mode.  */
extern long double rintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __rintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

/* Return X + epsilon if X < Y, X - epsilon if X > Y.  */
extern long double nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));

extern long double nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
# 274 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
/* Return the remainder of integer divison X / Y with infinite precision.  */
extern long double remainderl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __remainderl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));


/* Return X times (2 to the Nth power).  */
extern long double scalbnl (long double __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalbnl (long double __x, int __n) __attribute__ ((__nothrow__ , __leaf__));


/* Return the binary exponent of X, which must be nonzero.  */
extern int ilogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
# 292 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
/* Return X times (2 to the Nth power).  */
extern long double scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));

/* Round X to integral value in floating-point format using current
   rounding direction, but do not raise inexact exception.  */
extern long double nearbyintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nearbyintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

/* Round X to nearest integral value, rounding halfway cases away from
   zero.  */
extern long double roundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __roundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

/* Round X to the integral value in floating-point format nearest but
   not larger in magnitude.  */
extern long double truncl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __truncl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

/* Compute remainder of X and Y and put in *QUO a value with sign of x/y
   and magnitude congruent `mod 2^n' to the magnitude of the integral
   quotient x/y, with n >= 3.  */
extern long double remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern long double __remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));


/* Conversion functions.  */

/* Round X to nearest integral value according to current rounding
   direction.  */
extern long int lrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

/* Round X to nearest integral value, rounding halfway cases away from
   zero.  */
extern long int lroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


/* Return positive difference between X and Y.  */
extern long double fdiml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fdiml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));


/* Return maximum numeric value from X and Y.  */
extern long double fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

/* Return minimum numeric value from X and Y.  */
extern long double fminl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fminl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


/* Multiply-add function computed as a ternary operation.  */
extern long double fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__));
# 434 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
/* Return X times (2 to the Nth power).  */
extern long double scalbl (long double __x, long double __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalbl (long double __x, long double __n) __attribute__ ((__nothrow__ , __leaf__));
# 400 "/usr/include/math.h" 2 3 4
# 421 "/usr/include/math.h" 3 4
/* Include the file of declarations for _FloatN and _FloatNx
   types.  */
# 481 "/usr/include/math.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/mathcalls-helper-functions.h" 1 3 4
/* Prototype declarations for math classification macros helpers.
   Copyright (C) 2017-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* Classify given number.  */
extern int __fpclassifyf128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));

/* Test for negative number.  */
extern int __signbitf128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));

/* Return 0 if VALUE is finite or NaN, +1 if it
   is +Infinity, -1 if it is -Infinity.  */
extern int __isinff128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));

/* Return nonzero if VALUE is finite and not NaN.  Used by isfinite macro.  */
extern int __finitef128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));

/* Return nonzero if VALUE is not a number.  */
extern int __isnanf128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));

/* Test equality.  */
extern int __iseqsigf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));

/* Test for signaling NaN.  */
extern int __issignalingf128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
# 482 "/usr/include/math.h" 2 3 4
# 549 "/usr/include/math.h" 3 4
/* Declare functions returning a narrower type.  */
# 853 "/usr/include/math.h" 3 4
/* This variable is used by `gamma' and `lgamma'.  */
extern int signgam;
# 866 "/usr/include/math.h" 3 4
/* Depending on the type of TG_ARG, call an appropriately suffixed
   version of FUNC with arguments (including parentheses) ARGS.
   Suffixed functions may not exist for long double if it has the same
   format as double, or for other types with the same format as float,
   double or long double.  The behavior is undefined if the argument
   does not have a real floating type.  The definition may use a
   conditional expression, so all suffixed versions of FUNC must
   return the same type (FUNC may include a cast if necessary rather
   than being a single identifier).  */
# 930 "/usr/include/math.h" 3 4
/* ISO C99 defines some generic macros which work on any data type.  */


/* All floating-point numbers can be put in one of these categories.  */
enum
  {
    FP_NAN =

      0,
    FP_INFINITE =

      1,
    FP_ZERO =

      2,
    FP_SUBNORMAL =

      3,
    FP_NORMAL =

      4
  };

/* GCC bug 66462 means we cannot use the math builtins with -fsignaling-nan,
   so disable builtins if this is enabled.  When fixed in a newer GCC,
   the __SUPPORT_SNAN__ check may be skipped for those versions.  */

/* Return number of classification appropriate for X.  */



     /* The check for __cplusplus allows the use of the builtin, even
	when optimization for size is on.  This is provided for
	libstdc++, only to let its configure test work when it is built
	with -Os.  No further use of this definition of fpclassify is
	expected in C++ mode, since libstdc++ provides its own version
	of fpclassify in cmath (which undefines fpclassify).  */






/* Return nonzero value if sign of X is negative.  */
# 991 "/usr/include/math.h" 3 4
/* Return nonzero value if X is not +-Inf or NaN.  */







/* Return nonzero value if X is neither zero, subnormal, Inf, nor NaN.  */







/* Return nonzero value if X is a NaN.  We could use `fpclassify' but
   we already have this functions `__isnan' and it is faster.  */







/* Return nonzero value if X is positive or negative infinity.  */
# 1034 "/usr/include/math.h" 3 4
/* Bitmasks for the math_errhandling macro.  */



/* By default all math functions support both errno and exception handling
   (except for soft floating point implementations which may only support
   errno handling).  If errno handling is disabled, exceptions are still
   supported by GLIBC.  Set math_errhandling to 0 with -ffast-math (this is
   nonconforming but it is more useful than leaving it undefined).  */
# 1144 "/usr/include/math.h" 3 4
/* Some useful constants.  */
# 1161 "/usr/include/math.h" 3 4
/* GNU extension to provide float constants with similar names.  */
# 1178 "/usr/include/math.h" 3 4
/* The above constants are not adequate for computation using `long double's.
   Therefore we provide as an extension constants with similar names as a
   GNU extension.  Provide enough digits for the 128-bit IEEE quad.  */
# 1299 "/usr/include/math.h" 3 4
/* ISO C99 defines some macros to compare number while taking care for
   unordered numbers.  Many FPUs provide special instructions to support
   these operations.  Generic support in GCC for these as builtins went
   in 2.97, but not all cpus added their patterns until 3.1.  Therefore
   we enable the builtins from 3.1 onwards and use a generic implementation
   othwerwise.  */
# 1423 "/usr/include/math.h" 3 4

# 22 "/home/anton/revenant/game/headers/strings.h" 2 3 4
# 1 "/usr/include/inttypes.h" 1 3 4
/* Copyright (C) 1997-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 *	ISO C99: 7.8 Format conversion of integer types	<inttypes.h>
 */




# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 26 "/usr/include/inttypes.h" 2 3 4
/* Get the type definitions.  */


/* Get a definition for wchar_t.  But we must not define wchar_t itself.  */




typedef int __gwchar_t;
# 51 "/usr/include/inttypes.h" 3 4
/* Macros for printing format specifiers.  */

/* Decimal notation.  */
# 85 "/usr/include/inttypes.h" 3 4
/* Octal notation.  */
# 101 "/usr/include/inttypes.h" 3 4
/* Unsigned integers.  */
# 117 "/usr/include/inttypes.h" 3 4
/* lowercase hexadecimal notation.  */
# 133 "/usr/include/inttypes.h" 3 4
/* UPPERCASE hexadecimal notation.  */
# 150 "/usr/include/inttypes.h" 3 4
/* Macros for printing `intmax_t' and `uintmax_t'.  */
# 159 "/usr/include/inttypes.h" 3 4
/* Macros for printing `intptr_t' and `uintptr_t'.  */
# 168 "/usr/include/inttypes.h" 3 4
/* Macros for scanning format specifiers.  */

/* Signed decimal notation.  */
# 186 "/usr/include/inttypes.h" 3 4
/* Signed decimal notation.  */
# 202 "/usr/include/inttypes.h" 3 4
/* Unsigned decimal notation.  */
# 218 "/usr/include/inttypes.h" 3 4
/* Octal notation.  */
# 234 "/usr/include/inttypes.h" 3 4
/* Hexadecimal notation.  */
# 251 "/usr/include/inttypes.h" 3 4
/* Macros for scanning `intmax_t' and `uintmax_t'.  */






/* Macros for scaning `intptr_t' and `uintptr_t'.  */











/* We have to define the `uintmax_t' type using `ldiv_t'.  */
typedef struct
  {
    long int quot; /* Quotient.  */
    long int rem; /* Remainder.  */
  } imaxdiv_t;
# 289 "/usr/include/inttypes.h" 3 4
/* Compute absolute value of N.  */
extern intmax_t imaxabs (intmax_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

/* Return the `imaxdiv_t' representation of the value of NUMER over DENOM. */
extern imaxdiv_t imaxdiv (intmax_t __numer, intmax_t __denom)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

/* Like `strtol' but convert to `intmax_t'.  */
extern intmax_t strtoimax (const char *__restrict __nptr,
      char **__restrict __endptr, int __base) __attribute__ ((__nothrow__ , __leaf__));

/* Like `strtoul' but convert to `uintmax_t'.  */
extern uintmax_t strtoumax (const char *__restrict __nptr,
       char ** __restrict __endptr, int __base) __attribute__ ((__nothrow__ , __leaf__));

/* Like `wcstol' but convert to `intmax_t'.  */
extern intmax_t wcstoimax (const __gwchar_t *__restrict __nptr,
      __gwchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__));

/* Like `wcstoul' but convert to `uintmax_t'.  */
extern uintmax_t wcstoumax (const __gwchar_t *__restrict __nptr,
       __gwchar_t ** __restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__));


# 23 "/home/anton/revenant/game/headers/strings.h" 2 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stdarg.h" 1 3 4
/* Copyright (C) 1989-2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.15  Variable arguments  <stdarg.h>
 */
# 36 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stdarg.h" 3 4
/* Define __gnuc_va_list.  */






/* Define the standard macros for the user,
   if this invocation was from the user program.  */
# 56 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stdarg.h" 3 4
/* Define va_list, if desired, from __gnuc_va_list. */
/* We deliberately do not define va_list when called from
   stdio.h, because ANSI C says that stdio.h is not supposed to define
   va_list.  stdio.h needs to have access to that data type, 
   but must not use that name.  It should use the name __gnuc_va_list,
   which is safe because it is reserved for the implementation.  */
# 86 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stdarg.h" 3 4
/* The macro _VA_LIST_ is the same thing used by this file in Ultrix.
   But on BSD NET2 we must not test or define or undef it.
   (Note that the comments in NET 2's ansi.h
   are incorrect for _VA_LIST_--see stdio.h!)  */

/* The macro _VA_LIST_DEFINED is used in Windows NT 3.5  */
# 24 "/home/anton/revenant/game/headers/strings.h" 2 3 4



char *s_create_text(char *arg);
char *s_create_text_const( const char *arg);
char *s_merge_text(char *first_arg,char *second_arg);
int s_only_whitespace(char *bfr);
int s_char_count(char *string, char *character);
uint64_t s_uint_from_string(int argcount, ...);
/*Working with unitialized but still validly malloced chars has proven to be a tedious nightmare. Attempting to ensure that the memory has been initalized e.g by using calloc or memset has proven futile. Manually setting the entire string empty space works, however */
# 463 "/usr/include/string.h" 2 3 4

/* Set N bytes of S to 0.  The compiler will not delete a call to this
   function, even if S is dead after the call.  */
extern void explicit_bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));

/* Return the next DELIM-delimited token from *STRINGP,
   terminating it with a '\0', and update *STRINGP to point past it.  */
extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



/* Return a string describing the meaning of the signal number in SIG.  */
extern char *strsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));
# 488 "/usr/include/string.h" 3 4
/* Copy SRC to DEST, returning the address of the terminating '\0' in DEST.  */
extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

/* Copy no more than N characters of SRC to DEST, returning the address of
   the last character written into DEST.  */
extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
# 539 "/usr/include/string.h" 3 4

# 22 "/home/anton/revenant/game/headers/u_hash.h" 2
# 1 "/home/anton/revenant/game/headers/item.h" 1

# 1 "/home/anton/revenant/game/headers/item.h"
/*This file is part of Revenant.

Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Revenant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */





# 1 "/usr/include/stdlib.h" 1 3 4

# 1 "/usr/include/stdlib.h" 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   Copyright The GNU Toolchain Authors.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.20 General utilities	<stdlib.h>
 */
# 20 "/home/anton/revenant/game/headers/item.h" 2
# 1 "/home/anton/revenant/game/headers/strings.h" 1

# 1 "/home/anton/revenant/game/headers/strings.h"
/*This file is part of Revnant.

Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Revenant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */
# 21 "/home/anton/revenant/game/headers/item.h" 2
# 1 "/home/anton/revenant/game/headers/modifier.h" 1
/*This file is part of Revenant.

Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Revenant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */




# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/float.h" 1 3 4

# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/float.h" 3 4
/* Copyright (C) 2002-2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  5.2.4.2.2  Characteristics of floating types <float.h>
 */
# 19 "/home/anton/revenant/game/headers/modifier.h" 2

# 19 "/home/anton/revenant/game/headers/modifier.h"
typedef struct Material_Modifiers{
  float base_weight_modifier;
  float value_modifier;
  float armor_modifier;
  float dmg_modifier;
}Material_Modifier;

typedef struct Variant_Modifiers{
  float weight_modifier;
  float value_modifier;
  float stats_modifier;
}Variant_Modifier;

extern const Material_Modifier material_modifiers[];

extern Variant_Modifier variant_modifiers[];

extern Variant_Modifier itemslot_modifiers[];

extern const char* handed_modifier[];


extern const char* material_name_modifier[];

extern const char *quality_name_modifier[];

extern const char *armorslot_name_modifier[];

extern const char *mele_weapon_name_modifier[];

extern const char *weapon_representations[];

extern const char *equipment_type_modifier[];
# 22 "/home/anton/revenant/game/headers/item.h" 2
# 1 "/usr/include/inttypes.h" 1 3 4

# 1 "/usr/include/inttypes.h" 3 4
/* Copyright (C) 1997-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 *	ISO C99: 7.8 Format conversion of integer types	<inttypes.h>
 */
# 23 "/home/anton/revenant/game/headers/item.h" 2

# 1 "/usr/include/stdio.h" 1 3 4
/* Define ISO C stdio on top of C++ iostreams.
   Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.19 Input/output	<stdio.h>
 */
# 25 "/home/anton/revenant/game/headers/item.h" 2
# 1 "/usr/include/curses.h" 1 3 4
/****************************************************************************
 * Copyright 2018-2020,2021 Thomas E. Dickey                                *
 * Copyright 1998-2016,2017 Free Software Foundation, Inc.                  *
 *                                                                          *
 * Permission is hereby granted, free of charge, to any person obtaining a  *
 * copy of this software and associated documentation files (the            *
 * "Software"), to deal in the Software without restriction, including      *
 * without limitation the rights to use, copy, modify, merge, publish,      *
 * distribute, distribute with modifications, sublicense, and/or sell       *
 * copies of the Software, and to permit persons to whom the Software is    *
 * furnished to do so, subject to the following conditions:                 *
 *                                                                          *
 * The above copyright notice and this permission notice shall be included  *
 * in all copies or substantial portions of the Software.                   *
 *                                                                          *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *
 * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *
 *                                                                          *
 * Except as contained in this notice, the name(s) of the above copyright   *
 * holders shall not be used in advertising or otherwise to promote the     *
 * sale, use or other dealings in this Software without prior written       *
 * authorization.                                                           *
 ****************************************************************************/

/****************************************************************************
 *  Author: Zeyd M. Ben-Halim <zmbenhal@netcom.com> 1992,1995               *
 *     and: Eric S. Raymond <esr@snark.thyrsus.com>                         *
 *     and: Thomas E. Dickey                        1996-on                 *
 ****************************************************************************/

/* $Id: curses.h.in,v 1.277 2021/09/24 16:07:37 tom Exp $ */




/*
 The symbols beginning NCURSES_ or USE_ are configuration choices.
 A few of the former can be overridden by applications at compile-time.
 Most of the others correspond to configure-script options (or checks
 by the configure-script for features of the system on which it is built).

 These symbols can be overridden by applications at compile-time:
 NCURSES_NOMACROS suppresses macro definitions in favor of functions
 NCURSES_WATTR_MACROS suppresses wattr_* macro definitions
 NCURSES_WIDECHAR is an alternative for declaring wide-character functions.

 These symbols are used only when building ncurses:
 NCURSES_ATTR_T
 NCURSES_FIELD_INTERNALS
 NCURSES_INTERNALS

 These symbols are set by the configure script:
 NCURSES_ENABLE_STDBOOL_H
 NCURSES_EXPANDED
 NCURSES_EXT_COLORS
 NCURSES_EXT_FUNCS
 NCURSES_EXT_PUTWIN
 NCURSES_NO_PADDING
 NCURSES_OSPEED_COMPAT
 NCURSES_PATHSEP
 NCURSES_REENTRANT
 */




/* These are defined only in curses.h, and are used for conditional compiles */




/* This is defined in more than one ncurses header, for identification */



/*
 * Identify the mouse encoding version.
 */


/*
 * Definitions to facilitate DLL's.
 */
# 1 "/usr/include/ncurses_dll.h" 1 3 4
/****************************************************************************
 * Copyright 2018,2020 Thomas E. Dickey                                     *
 * Copyright 2009,2014 Free Software Foundation, Inc.                       *
 *                                                                          *
 * Permission is hereby granted, free of charge, to any person obtaining a  *
 * copy of this software and associated documentation files (the            *
 * "Software"), to deal in the Software without restriction, including      *
 * without limitation the rights to use, copy, modify, merge, publish,      *
 * distribute, distribute with modifications, sublicense, and/or sell       *
 * copies of the Software, and to permit persons to whom the Software is    *
 * furnished to do so, subject to the following conditions:                 *
 *                                                                          *
 * The above copyright notice and this permission notice shall be included  *
 * in all copies or substantial portions of the Software.                   *
 *                                                                          *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *
 * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *
 *                                                                          *
 * Except as contained in this notice, the name(s) of the above copyright   *
 * holders shall not be used in advertising or otherwise to promote the     *
 * sale, use or other dealings in this Software without prior written       *
 * authorization.                                                           *
 ****************************************************************************/
/* $Id: ncurses_dll.h.in,v 1.17 2020/09/05 17:58:47 juergen Exp $ */




/*
 * MinGW gcc (unlike MSYS2 and Cygwin) should define _WIN32 and possibly _WIN64.
 */
# 64 "/usr/include/ncurses_dll.h" 3 4
/*
 * For reentrant code, we map the various global variables into SCREEN by
 * using functions to access them.
 */
# 81 "/usr/include/ncurses_dll.h" 3 4
/*
 * These symbols hide dllimport/dllexport, for compilers which care about it.
 */
# 90 "/usr/include/curses.h" 2 3 4

/*
 * Extra headers.
 */
# 107 "/usr/include/curses.h" 3 4
/*
 * User-definable tweak to disable the include of <stdbool.h>.
 */




/*
 * NCURSES_ATTR_T is used to quiet compiler warnings when building ncurses
 * configured using --disable-macros.
 */




/*
 * Expands to 'const' if ncurses is configured using --enable-const.  Note that
 * doing so makes it incompatible with other implementations of X/Open Curses.
 */






/*
 * The standard type used for color values, and for color-pairs.  The latter
 * allows the curses library to enumerate the combinations of foreground and
 * background colors used by an application, and is normally the product of the
 * total foreground and background colors.
 *
 * X/Open uses "short" for both of these types, ultimately because they are
 * numbers from the SVr4 terminal database, which uses 16-bit signed values.
 */






/*
 * Definitions used to make WINDOW and similar structs opaque.
 */







/*
 * Definition used to optionally suppress wattr* macros to help with the
 * transition from ncurses5 to ncurses6 by allowing the header files to
 * be shared across development packages for ncursesw in both ABIs.
 */




/*
 * The reentrant code relies on the opaque setting, but adds features.
 */




/*
 * In certain environments, we must work around linker problems for data
 */





/*
 * Control whether bindings for interop support are added.
 */



/*
 * The internal type used for window dimensions.
 */



/*
 * Control whether tparm() supports varargs or fixed-parameter list.
 */



/*
 * Control type used for tparm's arguments.  While X/Open equates long and
 * char* values, this is not always workable for 64-bit platforms.
 */



/*
 * Control whether ncurses uses wcwidth() for checking width of line-drawing
 * characters.
 */



/*
 * NCURSES_CH_T is used in building the library, but not used otherwise in
 * this header file, since that would make the normal/wide-character versions
 * of the header incompatible.
 */




typedef unsigned chtype;
typedef unsigned mmask_t;





/*
 * We need FILE, etc.  Include this before checking any feature symbols.
 */
# 1 "/usr/include/stdio.h" 1 3 4
/* Define ISO C stdio on top of C++ iostreams.
   Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.19 Input/output	<stdio.h>
 */
# 233 "/usr/include/curses.h" 2 3 4

/*
 * With XPG4, you must define _XOPEN_SOURCE_EXTENDED, it is redundant (or
 * conflicting) when _XOPEN_SOURCE is 500 or greater.  If NCURSES_WIDECHAR is
 * not already defined, e.g., if the platform relies upon nonstandard feature
 * test macros, define it at this point if the standard feature test macros
 * indicate that it should be defined.
 */
# 249 "/usr/include/curses.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stdarg.h" 1 3 4
/* Copyright (C) 1989-2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.15  Variable arguments  <stdarg.h>
 */
# 250 "/usr/include/curses.h" 2 3 4




/* X/Open and SVr4 specify that curses implements 'bool'.  However, C++ may also
 * implement it.  If so, we must use the C++ compiler's type to avoid conflict
 * with other interfaces.
 *
 * A further complication is that <stdbool.h> may declare 'bool' to be a
 * different type, such as an enum which is not necessarily compatible with
 * C++.  If we have <stdbool.h>, make 'bool' a macro, so users may #undef it.
 * Otherwise, let it remain a typedef to avoid conflicts with other #define's.
 * In either case, make a typedef for NCURSES_BOOL which can be used if needed
 * from either C or C++.
 */







typedef unsigned char NCURSES_BOOL;
# 282 "/usr/include/curses.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stdbool.h" 1 3 4
/* Copyright (C) 1998-2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.16  Boolean type and values  <stdbool.h>
 */
# 49 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stdbool.h" 3 4
/* Signal that all the definitions are present.  */
# 283 "/usr/include/curses.h" 2 3 4
/* use whatever the C compiler decides bool really is */
# 302 "/usr/include/curses.h" 3 4
/*
 * X/Open attributes.  In the ncurses implementation, they are identical to the
 * A_ attributes.
 */
# 328 "/usr/include/curses.h" 3 4
/* colors */
# 338 "/usr/include/curses.h" 3 4
/* line graphics */





extern chtype acs_map[];




/* VT100 symbols begin here */
# 368 "/usr/include/curses.h" 3 4
/* Teletype 5410v1 symbols begin here */







/*
 * These aren't documented, but a lot of System Vs have them anyway
 * (you can spot pprryyzz{{||}} in a lot of AT&T terminfo strings).
 * The ACS_names may not match AT&T's, our source didn't know them.
 */
# 389 "/usr/include/curses.h" 3 4
/*
 * Line drawing ACS names are of the form ACS_trbl, where t is the top, r
 * is the right, b is the bottom, and l is the left.  t, r, b, and l might
 * be B (blank), S (single), D (double), or T (thick).  The subset defined
 * here only uses B and S.
 */
# 413 "/usr/include/curses.h" 3 4
/* values for the _flags member */
# 422 "/usr/include/curses.h" 3 4
/*
 * this value is used in the firstchar and lastchar fields to mark
 * unchanged lines
 */


/*
 * this value is used in the oldindex field to mark lines created by insertions
 * and scrolls.
 */







typedef struct screen SCREEN;


typedef struct _win_st WINDOW;

typedef chtype attr_t; /* ...must be at least as wide as chtype */
# 489 "/usr/include/curses.h" 3 4
struct ldat;

struct _win_st
{
 short _cury, _curx; /* current cursor position */

 /* window location and size */
 short _maxy, _maxx; /* maximums of x and y, NOT window size */
 short _begy, _begx; /* screen coords of upper-left-hand corner */

 short _flags; /* window state flags */

 /* attribute tracking */
 attr_t _attrs; /* current attribute for non-space character */
 chtype _bkgd; /* current background char/attribute pair */

 /* option values set by user */
 _Bool _notimeout; /* no time out on function-key entry? */
 _Bool _clear; /* consider all data in the window invalid? */
 _Bool _leaveok; /* OK to not reset cursor on exit? */
 _Bool _scroll; /* OK to scroll this window? */
 _Bool _idlok; /* OK to use insert/delete line? */
 _Bool _idcok; /* OK to use insert/delete char? */
 _Bool _immed; /* window in immed mode? (not yet used) */
 _Bool _sync; /* window in sync mode? */
 _Bool _use_keypad; /* process function keys into KEY_ symbols? */
 int _delay; /* 0 = nodelay, <0 = blocking, >0 = delay */

 struct ldat *_line; /* the actual line data */

 /* global screen state */
 short _regtop; /* top line of scrolling region */
 short _regbottom; /* bottom line of scrolling region */

 /* these are used only if this is a sub-window */
 int _parx; /* x coordinate of this window in parent */
 int _pary; /* y coordinate of this window in parent */
 WINDOW *_parent; /* pointer to parent if a sub-window */

 /* these are used only if this is a pad */
 struct pdat
 {
     short _pad_y, _pad_x;
     short _pad_top, _pad_left;
     short _pad_bottom, _pad_right;
 } _pad;

 short _yoffset; /* real begy is _begy + _yoffset */







};


/*
 * GCC (and some other compilers) define '__attribute__'; we're using this
 * macro to alert the compiler to flag inconsistencies in printf/scanf-like
 * function calls.  Just in case '__attribute__' isn't defined, make a dummy.
 * Old versions of G++ do not accept it anyway, at least not consistently with
 * GCC.
 */




/*
 * We cannot define these in ncurses_cfg.h, since they require parameters to be
 * passed (that is non-portable).
 */
# 593 "/usr/include/curses.h" 3 4
/*
 * Curses uses a helper function.  Define our type for this to simplify
 * extending it for the sp-funcs feature.
 */
typedef int (*NCURSES_OUTC)(int);

/*
 * Function prototypes.  This is the complete X/Open Curses list of required
 * functions.  Those marked `generated' will have sources generated from the
 * macro definitions later in this file, in order to satisfy XPG4.2
 * requirements.
 */

extern int addch (const chtype); /* generated */
extern int addchnstr (const chtype *, int); /* generated */
extern int addchstr (const chtype *); /* generated */
extern int addnstr (const char *, int); /* generated */
extern int addstr (const char *); /* generated */
extern int attroff (int); /* generated */
extern int attron (int); /* generated */
extern int attrset (int); /* generated */
extern int attr_get (attr_t *, short *, void *); /* generated */
extern int attr_off (attr_t, void *); /* generated */
extern int attr_on (attr_t, void *); /* generated */
extern int attr_set (attr_t, short, void *); /* generated */
extern int baudrate (void); /* implemented */
extern int beep (void); /* implemented */
extern int bkgd (chtype); /* generated */
extern void bkgdset (chtype); /* generated */
extern int border (chtype,chtype,chtype,chtype,chtype,chtype,chtype,chtype); /* generated */
extern int box (WINDOW *, chtype, chtype); /* generated */
extern _Bool can_change_color (void); /* implemented */
extern int cbreak (void); /* implemented */
extern int chgat (int, attr_t, short, const void *); /* generated */
extern int clear (void); /* generated */
extern int clearok (WINDOW *,_Bool); /* implemented */
extern int clrtobot (void); /* generated */
extern int clrtoeol (void); /* generated */
extern int color_content (short,short*,short*,short*); /* implemented */
extern int color_set (short,void*); /* generated */
extern int COLOR_PAIR (int); /* generated */
extern int copywin (const WINDOW*,WINDOW*,int,int,int,int,int,int,int); /* implemented */
extern int curs_set (int); /* implemented */
extern int def_prog_mode (void); /* implemented */
extern int def_shell_mode (void); /* implemented */
extern int delay_output (int); /* implemented */
extern int delch (void); /* generated */
extern void delscreen (SCREEN *); /* implemented */
extern int delwin (WINDOW *); /* implemented */
extern int deleteln (void); /* generated */
extern WINDOW * derwin (WINDOW *,int,int,int,int); /* implemented */
extern int doupdate (void); /* implemented */
extern WINDOW * dupwin (WINDOW *); /* implemented */
extern int echo (void); /* implemented */
extern int echochar (const chtype); /* generated */
extern int erase (void); /* generated */
extern int endwin (void); /* implemented */
extern char erasechar (void); /* implemented */
extern void filter (void); /* implemented */
extern int flash (void); /* implemented */
extern int flushinp (void); /* implemented */
extern chtype getbkgd (WINDOW *); /* generated */
extern int getch (void); /* generated */
extern int getnstr (char *, int); /* generated */
extern int getstr (char *); /* generated */
extern WINDOW * getwin (FILE *); /* implemented */
extern int halfdelay (int); /* implemented */
extern _Bool has_colors (void); /* implemented */
extern _Bool has_ic (void); /* implemented */
extern _Bool has_il (void); /* implemented */
extern int hline (chtype, int); /* generated */
extern void idcok (WINDOW *, _Bool); /* implemented */
extern int idlok (WINDOW *, _Bool); /* implemented */
extern void immedok (WINDOW *, _Bool); /* implemented */
extern chtype inch (void); /* generated */
extern int inchnstr (chtype *, int); /* generated */
extern int inchstr (chtype *); /* generated */
extern WINDOW * initscr (void); /* implemented */
extern int init_color (short,short,short,short); /* implemented */
extern int init_pair (short,short,short); /* implemented */
extern int innstr (char *, int); /* generated */
extern int insch (chtype); /* generated */
extern int insdelln (int); /* generated */
extern int insertln (void); /* generated */
extern int insnstr (const char *, int); /* generated */
extern int insstr (const char *); /* generated */
extern int instr (char *); /* generated */
extern int intrflush (WINDOW *,_Bool); /* implemented */
extern _Bool isendwin (void); /* implemented */
extern _Bool is_linetouched (WINDOW *,int); /* implemented */
extern _Bool is_wintouched (WINDOW *); /* implemented */
extern const char * keyname (int); /* implemented */
extern int keypad (WINDOW *,_Bool); /* implemented */
extern char killchar (void); /* implemented */
extern int leaveok (WINDOW *,_Bool); /* implemented */
extern char * longname (void); /* implemented */
extern int meta (WINDOW *,_Bool); /* implemented */
extern int move (int, int); /* generated */
extern int mvaddch (int, int, const chtype); /* generated */
extern int mvaddchnstr (int, int, const chtype *, int); /* generated */
extern int mvaddchstr (int, int, const chtype *); /* generated */
extern int mvaddnstr (int, int, const char *, int); /* generated */
extern int mvaddstr (int, int, const char *); /* generated */
extern int mvchgat (int, int, int, attr_t, short, const void *); /* generated */
extern int mvcur (int,int,int,int); /* implemented */
extern int mvdelch (int, int); /* generated */
extern int mvderwin (WINDOW *, int, int); /* implemented */
extern int mvgetch (int, int); /* generated */
extern int mvgetnstr (int, int, char *, int); /* generated */
extern int mvgetstr (int, int, char *); /* generated */
extern int mvhline (int, int, chtype, int); /* generated */
extern chtype mvinch (int, int); /* generated */
extern int mvinchnstr (int, int, chtype *, int); /* generated */
extern int mvinchstr (int, int, chtype *); /* generated */
extern int mvinnstr (int, int, char *, int); /* generated */
extern int mvinsch (int, int, chtype); /* generated */
extern int mvinsnstr (int, int, const char *, int); /* generated */
extern int mvinsstr (int, int, const char *); /* generated */
extern int mvinstr (int, int, char *); /* generated */
extern int mvprintw (int,int, const char *,...) /* implemented */
  __attribute__((format(printf,3,4)));
extern int mvscanw (int,int, const char *,...) /* implemented */
  __attribute__((format(scanf,3,4)));
extern int mvvline (int, int, chtype, int); /* generated */
extern int mvwaddch (WINDOW *, int, int, const chtype); /* generated */
extern int mvwaddchnstr (WINDOW *, int, int, const chtype *, int);/* generated */
extern int mvwaddchstr (WINDOW *, int, int, const chtype *); /* generated */
extern int mvwaddnstr (WINDOW *, int, int, const char *, int); /* generated */
extern int mvwaddstr (WINDOW *, int, int, const char *); /* generated */
extern int mvwchgat (WINDOW *, int, int, int, attr_t, short, const void *);/* generated */
extern int mvwdelch (WINDOW *, int, int); /* generated */
extern int mvwgetch (WINDOW *, int, int); /* generated */
extern int mvwgetnstr (WINDOW *, int, int, char *, int); /* generated */
extern int mvwgetstr (WINDOW *, int, int, char *); /* generated */
extern int mvwhline (WINDOW *, int, int, chtype, int); /* generated */
extern int mvwin (WINDOW *,int,int); /* implemented */
extern chtype mvwinch (WINDOW *, int, int); /* generated */
extern int mvwinchnstr (WINDOW *, int, int, chtype *, int); /* generated */
extern int mvwinchstr (WINDOW *, int, int, chtype *); /* generated */
extern int mvwinnstr (WINDOW *, int, int, char *, int); /* generated */
extern int mvwinsch (WINDOW *, int, int, chtype); /* generated */
extern int mvwinsnstr (WINDOW *, int, int, const char *, int); /* generated */
extern int mvwinsstr (WINDOW *, int, int, const char *); /* generated */
extern int mvwinstr (WINDOW *, int, int, char *); /* generated */
extern int mvwprintw (WINDOW*,int,int, const char *,...) /* implemented */
  __attribute__((format(printf,4,5)));
extern int mvwscanw (WINDOW *,int,int, const char *,...) /* implemented */
  __attribute__((format(scanf,4,5)));
extern int mvwvline (WINDOW *,int, int, chtype, int); /* generated */
extern int napms (int); /* implemented */
extern WINDOW * newpad (int,int); /* implemented */
extern SCREEN * newterm (const char *,FILE *,FILE *); /* implemented */
extern WINDOW * newwin (int,int,int,int); /* implemented */
extern int nl (void); /* implemented */
extern int nocbreak (void); /* implemented */
extern int nodelay (WINDOW *,_Bool); /* implemented */
extern int noecho (void); /* implemented */
extern int nonl (void); /* implemented */
extern void noqiflush (void); /* implemented */
extern int noraw (void); /* implemented */
extern int notimeout (WINDOW *,_Bool); /* implemented */
extern int overlay (const WINDOW*,WINDOW *); /* implemented */
extern int overwrite (const WINDOW*,WINDOW *); /* implemented */
extern int pair_content (short,short*,short*); /* implemented */
extern int PAIR_NUMBER (int); /* generated */
extern int pechochar (WINDOW *, const chtype); /* implemented */
extern int pnoutrefresh (WINDOW*,int,int,int,int,int,int);/* implemented */
extern int prefresh (WINDOW *,int,int,int,int,int,int); /* implemented */
extern int printw (const char *,...) /* implemented */
  __attribute__((format(printf,1,2)));
extern int putwin (WINDOW *, FILE *); /* implemented */
extern void qiflush (void); /* implemented */
extern int raw (void); /* implemented */
extern int redrawwin (WINDOW *); /* generated */
extern int refresh (void); /* generated */
extern int resetty (void); /* implemented */
extern int reset_prog_mode (void); /* implemented */
extern int reset_shell_mode (void); /* implemented */
extern int ripoffline (int, int (*)(WINDOW *, int)); /* implemented */
extern int savetty (void); /* implemented */
extern int scanw (const char *,...) /* implemented */
  __attribute__((format(scanf,1,2)));
extern int scr_dump (const char *); /* implemented */
extern int scr_init (const char *); /* implemented */
extern int scrl (int); /* generated */
extern int scroll (WINDOW *); /* generated */
extern int scrollok (WINDOW *,_Bool); /* implemented */
extern int scr_restore (const char *); /* implemented */
extern int scr_set (const char *); /* implemented */
extern int setscrreg (int,int); /* generated */
extern SCREEN * set_term (SCREEN *); /* implemented */
extern int slk_attroff (const chtype); /* implemented */
extern int slk_attr_off (const attr_t, void *); /* generated:WIDEC */
extern int slk_attron (const chtype); /* implemented */
extern int slk_attr_on (attr_t,void*); /* generated:WIDEC */
extern int slk_attrset (const chtype); /* implemented */
extern attr_t slk_attr (void); /* implemented */
extern int slk_attr_set (const attr_t,short,void*); /* implemented */
extern int slk_clear (void); /* implemented */
extern int slk_color (short); /* implemented */
extern int slk_init (int); /* implemented */
extern char * slk_label (int); /* implemented */
extern int slk_noutrefresh (void); /* implemented */
extern int slk_refresh (void); /* implemented */
extern int slk_restore (void); /* implemented */
extern int slk_set (int,const char *,int); /* implemented */
extern int slk_touch (void); /* implemented */
extern int standout (void); /* generated */
extern int standend (void); /* generated */
extern int start_color (void); /* implemented */
extern WINDOW * subpad (WINDOW *, int, int, int, int); /* implemented */
extern WINDOW * subwin (WINDOW *, int, int, int, int); /* implemented */
extern int syncok (WINDOW *, _Bool); /* implemented */
extern chtype termattrs (void); /* implemented */
extern char * termname (void); /* implemented */
extern void timeout (int); /* generated */
extern int touchline (WINDOW *, int, int); /* generated */
extern int touchwin (WINDOW *); /* generated */
extern int typeahead (int); /* implemented */
extern int ungetch (int); /* implemented */
extern int untouchwin (WINDOW *); /* generated */
extern void use_env (_Bool); /* implemented */
extern void use_tioctl (_Bool); /* implemented */
extern int vidattr (chtype); /* implemented */
extern int vidputs (chtype, NCURSES_OUTC); /* implemented */
extern int vline (chtype, int); /* generated */
extern int vwprintw (WINDOW *, const char *, va_list) __attribute__((deprecated)) /* implemented */
  __attribute__((format(printf,2,0)));
extern int vw_printw (WINDOW *, const char *, va_list) /* implemented */
  __attribute__((format(printf,2,0)));
extern int vwscanw (WINDOW *, const char *, va_list) __attribute__((deprecated)) /* implemented */
  __attribute__((format(scanf,2,0)));
extern int vw_scanw (WINDOW *, const char *, va_list) /* implemented */
  __attribute__((format(scanf,2,0)));
extern int waddch (WINDOW *, const chtype); /* implemented */
extern int waddchnstr (WINDOW *,const chtype *,int); /* implemented */
extern int waddchstr (WINDOW *,const chtype *); /* generated */
extern int waddnstr (WINDOW *,const char *,int); /* implemented */
extern int waddstr (WINDOW *,const char *); /* generated */
extern int wattron (WINDOW *, int); /* generated */
extern int wattroff (WINDOW *, int); /* generated */
extern int wattrset (WINDOW *, int); /* generated */
extern int wattr_get (WINDOW *, attr_t *, short *, void *); /* generated */
extern int wattr_on (WINDOW *, attr_t, void *); /* implemented */
extern int wattr_off (WINDOW *, attr_t, void *); /* implemented */
extern int wattr_set (WINDOW *, attr_t, short, void *); /* generated */
extern int wbkgd (WINDOW *, chtype); /* implemented */
extern void wbkgdset (WINDOW *,chtype); /* implemented */
extern int wborder (WINDOW *,chtype,chtype,chtype,chtype,chtype,chtype,chtype,chtype); /* implemented */
extern int wchgat (WINDOW *, int, attr_t, short, const void *);/* implemented */
extern int wclear (WINDOW *); /* implemented */
extern int wclrtobot (WINDOW *); /* implemented */
extern int wclrtoeol (WINDOW *); /* implemented */
extern int wcolor_set (WINDOW*,short,void*); /* implemented */
extern void wcursyncup (WINDOW *); /* implemented */
extern int wdelch (WINDOW *); /* implemented */
extern int wdeleteln (WINDOW *); /* generated */
extern int wechochar (WINDOW *, const chtype); /* implemented */
extern int werase (WINDOW *); /* implemented */
extern int wgetch (WINDOW *); /* implemented */
extern int wgetnstr (WINDOW *,char *,int); /* implemented */
extern int wgetstr (WINDOW *, char *); /* generated */
extern int whline (WINDOW *, chtype, int); /* implemented */
extern chtype winch (WINDOW *); /* implemented */
extern int winchnstr (WINDOW *, chtype *, int); /* implemented */
extern int winchstr (WINDOW *, chtype *); /* generated */
extern int winnstr (WINDOW *, char *, int); /* implemented */
extern int winsch (WINDOW *, chtype); /* implemented */
extern int winsdelln (WINDOW *,int); /* implemented */
extern int winsertln (WINDOW *); /* generated */
extern int winsnstr (WINDOW *, const char *,int); /* implemented */
extern int winsstr (WINDOW *, const char *); /* generated */
extern int winstr (WINDOW *, char *); /* generated */
extern int wmove (WINDOW *,int,int); /* implemented */
extern int wnoutrefresh (WINDOW *); /* implemented */
extern int wprintw (WINDOW *, const char *,...) /* implemented */
  __attribute__((format(printf,2,3)));
extern int wredrawln (WINDOW *,int,int); /* implemented */
extern int wrefresh (WINDOW *); /* implemented */
extern int wscanw (WINDOW *, const char *,...) /* implemented */
  __attribute__((format(scanf,2,3)));
extern int wscrl (WINDOW *,int); /* implemented */
extern int wsetscrreg (WINDOW *,int,int); /* implemented */
extern int wstandout (WINDOW *); /* generated */
extern int wstandend (WINDOW *); /* generated */
extern void wsyncdown (WINDOW *); /* implemented */
extern void wsyncup (WINDOW *); /* implemented */
extern void wtimeout (WINDOW *,int); /* implemented */
extern int wtouchln (WINDOW *,int,int,int); /* implemented */
extern int wvline (WINDOW *,chtype,int); /* implemented */

/*
 * These are also declared in <term.h>:
 */
extern int tigetflag (const char *); /* implemented */
extern int tigetnum (const char *); /* implemented */
extern char * tigetstr (const char *); /* implemented */
extern int putp (const char *); /* implemented */


extern char * tparm (const char *, ...); /* special */




extern char * tiparm (const char *, ...); /* special */

/*
 * These functions are not in X/Open, but we use them in macro definitions:
 */
extern int getattrs (const WINDOW *); /* generated */
extern int getcurx (const WINDOW *); /* generated */
extern int getcury (const WINDOW *); /* generated */
extern int getbegx (const WINDOW *); /* generated */
extern int getbegy (const WINDOW *); /* generated */
extern int getmaxx (const WINDOW *); /* generated */
extern int getmaxy (const WINDOW *); /* generated */
extern int getparx (const WINDOW *); /* generated */
extern int getpary (const WINDOW *); /* generated */

/*
 * vid_attr() was implemented originally based on a draft of X/Open curses.
 */




/*
 * These functions are extensions - not in X/Open Curses.
 */



typedef int (*NCURSES_WINDOW_CB)(WINDOW *, void *);
typedef int (*NCURSES_SCREEN_CB)(SCREEN *, void *);
extern _Bool is_term_resized (int, int);
extern char * keybound (int, int);
extern const char * curses_version (void);
extern int alloc_pair (int, int);
extern int assume_default_colors (int, int);
extern int define_key (const char *, int);
extern int extended_color_content(int, int *, int *, int *);
extern int extended_pair_content(int, int *, int *);
extern int extended_slk_color(int);
extern int find_pair (int, int);
extern int free_pair (int);
extern int get_escdelay (void);
extern int init_extended_color(int, int, int, int);
extern int init_extended_pair(int, int, int);
extern int key_defined (const char *);
extern int keyok (int, _Bool);
extern void reset_color_pairs (void);
extern int resize_term (int, int);
extern int resizeterm (int, int);
extern int set_escdelay (int);
extern int set_tabsize (int);
extern int use_default_colors (void);
extern int use_extended_names (_Bool);
extern int use_legacy_coding (int);
extern int use_screen (SCREEN *, NCURSES_SCREEN_CB, void *);
extern int use_window (WINDOW *, NCURSES_WINDOW_CB, void *);
extern int wresize (WINDOW *, int, int);
extern void nofilter(void);

/*
 * These extensions provide access to information stored in the WINDOW even
 * when NCURSES_OPAQUE is set:
 */
extern WINDOW * wgetparent (const WINDOW *); /* generated */
extern _Bool is_cleared (const WINDOW *); /* generated */
extern _Bool is_idcok (const WINDOW *); /* generated */
extern _Bool is_idlok (const WINDOW *); /* generated */
extern _Bool is_immedok (const WINDOW *); /* generated */
extern _Bool is_keypad (const WINDOW *); /* generated */
extern _Bool is_leaveok (const WINDOW *); /* generated */
extern _Bool is_nodelay (const WINDOW *); /* generated */
extern _Bool is_notimeout (const WINDOW *); /* generated */
extern _Bool is_pad (const WINDOW *); /* generated */
extern _Bool is_scrollok (const WINDOW *); /* generated */
extern _Bool is_subwin (const WINDOW *); /* generated */
extern _Bool is_syncok (const WINDOW *); /* generated */
extern int wgetdelay (const WINDOW *); /* generated */
extern int wgetscrreg (const WINDOW *, int *, int *); /* generated */





/*
 * Extra extension-functions, which pass a SCREEN pointer rather than using
 * a global variable SP.
 */





/* Define the sp-funcs helper function */

typedef int (*NCURSES_OUTC_sp)(SCREEN*, int);

extern SCREEN * new_prescr (void); /* implemented:SP_FUNC */

extern int baudrate_sp (SCREEN*); /* implemented:SP_FUNC */
extern int beep_sp (SCREEN*); /* implemented:SP_FUNC */
extern _Bool can_change_color_sp (SCREEN*); /* implemented:SP_FUNC */
extern int cbreak_sp (SCREEN*); /* implemented:SP_FUNC */
extern int curs_set_sp (SCREEN*, int); /* implemented:SP_FUNC */
extern int color_content_sp (SCREEN*, short, short*, short*, short*); /* implemented:SP_FUNC */
extern int def_prog_mode_sp (SCREEN*); /* implemented:SP_FUNC */
extern int def_shell_mode_sp (SCREEN*); /* implemented:SP_FUNC */
extern int delay_output_sp (SCREEN*, int); /* implemented:SP_FUNC */
extern int doupdate_sp (SCREEN*); /* implemented:SP_FUNC */
extern int echo_sp (SCREEN*); /* implemented:SP_FUNC */
extern int endwin_sp (SCREEN*); /* implemented:SP_FUNC */
extern char erasechar_sp (SCREEN*);/* implemented:SP_FUNC */
extern void filter_sp (SCREEN*); /* implemented:SP_FUNC */
extern int flash_sp (SCREEN*); /* implemented:SP_FUNC */
extern int flushinp_sp (SCREEN*); /* implemented:SP_FUNC */
extern WINDOW * getwin_sp (SCREEN*, FILE *); /* implemented:SP_FUNC */
extern int halfdelay_sp (SCREEN*, int); /* implemented:SP_FUNC */
extern _Bool has_colors_sp (SCREEN*); /* implemented:SP_FUNC */
extern _Bool has_ic_sp (SCREEN*); /* implemented:SP_FUNC */
extern _Bool has_il_sp (SCREEN*); /* implemented:SP_FUNC */
extern int init_color_sp (SCREEN*, short, short, short, short); /* implemented:SP_FUNC */
extern int init_pair_sp (SCREEN*, short, short, short); /* implemented:SP_FUNC */
extern int intrflush_sp (SCREEN*, WINDOW*, _Bool); /* implemented:SP_FUNC */
extern _Bool isendwin_sp (SCREEN*); /* implemented:SP_FUNC */
extern const char * keyname_sp (SCREEN*, int); /* implemented:SP_FUNC */
extern char killchar_sp (SCREEN*); /* implemented:SP_FUNC */
extern char * longname_sp (SCREEN*); /* implemented:SP_FUNC */
extern int mvcur_sp (SCREEN*, int, int, int, int); /* implemented:SP_FUNC */
extern int napms_sp (SCREEN*, int); /* implemented:SP_FUNC */
extern WINDOW * newpad_sp (SCREEN*, int, int); /* implemented:SP_FUNC */
extern SCREEN * newterm_sp (SCREEN*, const char *, FILE *, FILE *); /* implemented:SP_FUNC */
extern WINDOW * newwin_sp (SCREEN*, int, int, int, int); /* implemented:SP_FUNC */
extern int nl_sp (SCREEN*); /* implemented:SP_FUNC */
extern int nocbreak_sp (SCREEN*); /* implemented:SP_FUNC */
extern int noecho_sp (SCREEN*); /* implemented:SP_FUNC */
extern int nonl_sp (SCREEN*); /* implemented:SP_FUNC */
extern void noqiflush_sp (SCREEN*); /* implemented:SP_FUNC */
extern int noraw_sp (SCREEN*); /* implemented:SP_FUNC */
extern int pair_content_sp (SCREEN*, short, short*, short*); /* implemented:SP_FUNC */
extern void qiflush_sp (SCREEN*); /* implemented:SP_FUNC */
extern int raw_sp (SCREEN*); /* implemented:SP_FUNC */
extern int reset_prog_mode_sp (SCREEN*); /* implemented:SP_FUNC */
extern int reset_shell_mode_sp (SCREEN*); /* implemented:SP_FUNC */
extern int resetty_sp (SCREEN*); /* implemented:SP_FUNC */
extern int ripoffline_sp (SCREEN*, int, int (*)(WINDOW *, int)); /* implemented:SP_FUNC */
extern int savetty_sp (SCREEN*); /* implemented:SP_FUNC */
extern int scr_init_sp (SCREEN*, const char *); /* implemented:SP_FUNC */
extern int scr_restore_sp (SCREEN*, const char *); /* implemented:SP_FUNC */
extern int scr_set_sp (SCREEN*, const char *); /* implemented:SP_FUNC */
extern int slk_attroff_sp (SCREEN*, const chtype); /* implemented:SP_FUNC */
extern int slk_attron_sp (SCREEN*, const chtype); /* implemented:SP_FUNC */
extern int slk_attrset_sp (SCREEN*, const chtype); /* implemented:SP_FUNC */
extern attr_t slk_attr_sp (SCREEN*); /* implemented:SP_FUNC */
extern int slk_attr_set_sp (SCREEN*, const attr_t, short, void*); /* implemented:SP_FUNC */
extern int slk_clear_sp (SCREEN*); /* implemented:SP_FUNC */
extern int slk_color_sp (SCREEN*, short); /* implemented:SP_FUNC */
extern int slk_init_sp (SCREEN*, int); /* implemented:SP_FUNC */
extern char * slk_label_sp (SCREEN*, int); /* implemented:SP_FUNC */
extern int slk_noutrefresh_sp (SCREEN*); /* implemented:SP_FUNC */
extern int slk_refresh_sp (SCREEN*); /* implemented:SP_FUNC */
extern int slk_restore_sp (SCREEN*); /* implemented:SP_FUNC */
extern int slk_set_sp (SCREEN*, int, const char *, int); /* implemented:SP_FUNC */
extern int slk_touch_sp (SCREEN*); /* implemented:SP_FUNC */
extern int start_color_sp (SCREEN*); /* implemented:SP_FUNC */
extern chtype termattrs_sp (SCREEN*); /* implemented:SP_FUNC */
extern char * termname_sp (SCREEN*); /* implemented:SP_FUNC */
extern int typeahead_sp (SCREEN*, int); /* implemented:SP_FUNC */
extern int ungetch_sp (SCREEN*, int); /* implemented:SP_FUNC */
extern void use_env_sp (SCREEN*, _Bool); /* implemented:SP_FUNC */
extern void use_tioctl_sp (SCREEN*, _Bool); /* implemented:SP_FUNC */
extern int vidattr_sp (SCREEN*, chtype); /* implemented:SP_FUNC */
extern int vidputs_sp (SCREEN*, chtype, NCURSES_OUTC_sp); /* implemented:SP_FUNC */

extern char * keybound_sp (SCREEN*, int, int); /* implemented:EXT_SP_FUNC */
extern int alloc_pair_sp (SCREEN*, int, int); /* implemented:EXT_SP_FUNC */
extern int assume_default_colors_sp (SCREEN*, int, int); /* implemented:EXT_SP_FUNC */
extern int define_key_sp (SCREEN*, const char *, int); /* implemented:EXT_SP_FUNC */
extern int extended_color_content_sp (SCREEN*, int, int *, int *, int *); /* implemented:EXT_SP_FUNC */
extern int extended_pair_content_sp (SCREEN*, int, int *, int *); /* implemented:EXT_SP_FUNC */
extern int extended_slk_color_sp (SCREEN*, int); /* implemented:EXT_SP_FUNC */
extern int get_escdelay_sp (SCREEN*); /* implemented:EXT_SP_FUNC */
extern int find_pair_sp (SCREEN*, int, int); /* implemented:EXT_SP_FUNC */
extern int free_pair_sp (SCREEN*, int); /* implemented:EXT_SP_FUNC */
extern int init_extended_color_sp (SCREEN*, int, int, int, int); /* implemented:EXT_SP_FUNC */
extern int init_extended_pair_sp (SCREEN*, int, int, int); /* implemented:EXT_SP_FUNC */
extern _Bool is_term_resized_sp (SCREEN*, int, int); /* implemented:EXT_SP_FUNC */
extern int key_defined_sp (SCREEN*, const char *); /* implemented:EXT_SP_FUNC */
extern int keyok_sp (SCREEN*, int, _Bool); /* implemented:EXT_SP_FUNC */
extern void nofilter_sp (SCREEN*); /* implemented */ /* implemented:EXT_SP_FUNC */
extern void reset_color_pairs_sp (SCREEN*); /* implemented:EXT_SP_FUNC */
extern int resize_term_sp (SCREEN*, int, int); /* implemented:EXT_SP_FUNC */
extern int resizeterm_sp (SCREEN*, int, int); /* implemented:EXT_SP_FUNC */
extern int set_escdelay_sp (SCREEN*, int); /* implemented:EXT_SP_FUNC */
extern int set_tabsize_sp (SCREEN*, int); /* implemented:EXT_SP_FUNC */
extern int use_default_colors_sp (SCREEN*); /* implemented:EXT_SP_FUNC */
extern int use_legacy_coding_sp (SCREEN*, int); /* implemented:EXT_SP_FUNC */
# 1101 "/usr/include/curses.h" 3 4
/* attributes */
# 1130 "/usr/include/curses.h" 3 4
/*
 * Most of the pseudo functions are macros that either provide compatibility
 * with older versions of curses, or provide inline functionality to improve
 * performance.
 */

/*
 * These pseudo functions are always implemented as macros:
 */
# 1165 "/usr/include/curses.h" 3 4
/*
 * These miscellaneous pseudo functions are provided for compatibility:
 */
# 1181 "/usr/include/curses.h" 3 4
/* It seems older SYSV curses versions define these */
# 1241 "/usr/include/curses.h" 3 4
/*
 * These apply to the first 256 color pairs.
 */



/*
 * pseudo functions for standard screen
 */
# 1296 "/usr/include/curses.h" 3 4
/*
 * mv functions
 */
# 1342 "/usr/include/curses.h" 3 4
/*
 * Some wide-character functions can be implemented without the extensions.
 */
# 1395 "/usr/include/curses.h" 3 4
/*
 * X/Open curses deprecates SVr4 vwprintw/vwscanw, which are supposed to use
 * varargs.h.  It adds new calls vw_printw/vw_scanw, which are supposed to
 * use POSIX stdarg.h.  The ncurses versions of vwprintw/vwscanw already
 * use stdarg.h, so...
 */
/* define vw_printw		vwprintw */
/* define vw_scanw		vwscanw */

/*
 * Export fallback function for use in C++ binding.
 */





/*
 * These macros are extensions - not in X/Open Curses.
 */
# 1435 "/usr/include/curses.h" 3 4
/*
 * X/Open says this returns a bool; SVr4 also checked for out-of-range line.
 * The macro provides compatibility:
 */




/*
 * Public variables.
 *
 * Notes:
 *	a. ESCDELAY was an undocumented feature under AIX curses.
 *	   It gives the ESC expire time in milliseconds.
 *	b. ttytype is needed for backward compatibility
 */
# 1477 "/usr/include/curses.h" 3 4
extern WINDOW * curscr;
extern WINDOW * newscr;
extern WINDOW * stdscr;
extern char ttytype[];
extern int COLORS;
extern int COLOR_PAIRS;
extern int COLS;
extern int ESCDELAY;
extern int LINES;
extern int TABSIZE;



/*
 * Pseudo-character tokens outside ASCII range.  The curses wgetch() function
 * will return any given one of these only if the corresponding k- capability
 * is defined in your terminal's terminfo entry.
 *
 * Some keys (KEY_A1, etc) are arranged like this:
 *	a1     up    a3
 *	left   b2    right
 *	c1     down  c3
 *
 * A few key codes do not depend upon the terminfo entry.
 */





/*
 * These definitions were generated by ./MKkey_defs.sh ../../include/Caps ../../include/Caps-ncurses
 */
# 1604 "/usr/include/curses.h" 3 4
/* $Id: curses.wide,v 1.51 2021/05/22 20:28:29 tom Exp $ */
/*
 * vile:cmode:
 * This file is part of ncurses, designed to be appended after curses.h.in
 * (see that file for the relevant copyright).
 */
# 1918 "/usr/include/curses.h" 3 4
/* $Id: curses.tail,v 1.26 2021/03/20 15:49:25 tom Exp $ */
/*
 * vile:cmode:
 * This file is part of ncurses, designed to be appended after curses.h.in
 * (see that file for the relevant copyright).
 */

/* mouse interface */
# 1940 "/usr/include/curses.h" 3 4
/* event masks */
# 1965 "/usr/include/curses.h" 3 4
/*
 * In 32 bits the version-1 scheme does not provide enough space for a 5th
 * button, unless we choose to change the ABI by omitting the reserved-events.
 */
# 1998 "/usr/include/curses.h" 3 4
/* macros to extract single event-bits from masks */







typedef struct
{
    short id; /* ID to distinguish multiple devices */
    int x, y, z; /* event coordinates (character-cell) */
    mmask_t bstate; /* button state bits */
}
MEVENT;

extern _Bool has_mouse(void);
extern int getmouse (MEVENT *);
extern int ungetmouse (MEVENT *);
extern mmask_t mousemask (mmask_t, mmask_t *);
extern _Bool wenclose (const WINDOW *, int, int);
extern int mouseinterval (int);
extern _Bool wmouse_trafo (const WINDOW*, int*, int*, _Bool);
extern _Bool mouse_trafo (int*, int*, _Bool); /* generated */


extern _Bool has_mouse_sp (SCREEN*);
extern int getmouse_sp (SCREEN*, MEVENT *);
extern int ungetmouse_sp (SCREEN*,MEVENT *);
extern mmask_t mousemask_sp (SCREEN*, mmask_t, mmask_t *);
extern int mouseinterval_sp (SCREEN*, int);






/* other non-XSI functions */

extern int mcprint (char *, int); /* direct data to printer */
extern int has_key (int); /* do we have given key? */


extern int has_key_sp (SCREEN*, int); /* do we have given key? */
extern int mcprint_sp (SCREEN*, char *, int); /* direct data to printer */


/* Debugging : use with libncurses_g.a */

extern void _tracef (const char *, ...) __attribute__((format(printf,1,2)));
extern char * _traceattr (attr_t);
extern char * _traceattr2 (int, chtype);
extern char * _tracechar (int);
extern char * _tracechtype (chtype);
extern char * _tracechtype2 (int, chtype);
# 2062 "/usr/include/curses.h" 3 4
extern void trace (const unsigned) __attribute__((deprecated));
extern unsigned curses_trace (const unsigned);

/* trace masks */
# 2094 "/usr/include/curses.h" 3 4
extern void exit_curses (int);

# 1 "/usr/include/unctrl.h" 1 3 4
/****************************************************************************
 * Copyright 2020 Thomas E. Dickey                                          *
 * Copyright 1998-2001,2009 Free Software Foundation, Inc.                  *
 *                                                                          *
 * Permission is hereby granted, free of charge, to any person obtaining a  *
 * copy of this software and associated documentation files (the            *
 * "Software"), to deal in the Software without restriction, including      *
 * without limitation the rights to use, copy, modify, merge, publish,      *
 * distribute, distribute with modifications, sublicense, and/or sell       *
 * copies of the Software, and to permit persons to whom the Software is    *
 * furnished to do so, subject to the following conditions:                 *
 *                                                                          *
 * The above copyright notice and this permission notice shall be included  *
 * in all copies or substantial portions of the Software.                   *
 *                                                                          *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *
 * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *
 *                                                                          *
 * Except as contained in this notice, the name(s) of the above copyright   *
 * holders shall not be used in advertising or otherwise to promote the     *
 * sale, use or other dealings in this Software without prior written       *
 * authorization.                                                           *
 ****************************************************************************/

/****************************************************************************
 *  Author: Zeyd M. Ben-Halim <zmbenhal@netcom.com> 1992,1995               *
 *     and: Eric S. Raymond <esr@snark.thyrsus.com>                         *
 ****************************************************************************/

/*
 * unctrl.h
 *
 * Display a printable version of a control character.
 * Control characters are displayed in caret notation (^x), DELETE is displayed
 * as ^?. Printable characters are displayed as is.
 */

/* $Id: unctrl.h.in,v 1.12 2020/02/02 23:34:34 tom Exp $ */
# 55 "/usr/include/unctrl.h" 3 4
# 1 "/usr/include/curses.h" 1 3 4
/****************************************************************************
 * Copyright 2018-2020,2021 Thomas E. Dickey                                *
 * Copyright 1998-2016,2017 Free Software Foundation, Inc.                  *
 *                                                                          *
 * Permission is hereby granted, free of charge, to any person obtaining a  *
 * copy of this software and associated documentation files (the            *
 * "Software"), to deal in the Software without restriction, including      *
 * without limitation the rights to use, copy, modify, merge, publish,      *
 * distribute, distribute with modifications, sublicense, and/or sell       *
 * copies of the Software, and to permit persons to whom the Software is    *
 * furnished to do so, subject to the following conditions:                 *
 *                                                                          *
 * The above copyright notice and this permission notice shall be included  *
 * in all copies or substantial portions of the Software.                   *
 *                                                                          *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *
 * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *
 *                                                                          *
 * Except as contained in this notice, the name(s) of the above copyright   *
 * holders shall not be used in advertising or otherwise to promote the     *
 * sale, use or other dealings in this Software without prior written       *
 * authorization.                                                           *
 ****************************************************************************/

/****************************************************************************
 *  Author: Zeyd M. Ben-Halim <zmbenhal@netcom.com> 1992,1995               *
 *     and: Eric S. Raymond <esr@snark.thyrsus.com>                         *
 *     and: Thomas E. Dickey                        1996-on                 *
 ****************************************************************************/

/* $Id: curses.h.in,v 1.277 2021/09/24 16:07:37 tom Exp $ */
# 56 "/usr/include/unctrl.h" 2 3 4


 const char * unctrl (chtype);


 const char * unctrl_sp (SCREEN*, chtype);
# 2097 "/usr/include/curses.h" 2 3 4
# 26 "/home/anton/revenant/game/headers/item.h" 2
# 45 "/home/anton/revenant/game/headers/item.h"

# 45 "/home/anton/revenant/game/headers/item.h"
typedef enum Material{carbon_fiber,plastic,clay,leather,gold,silver,custom,granite,marble,flint,iron,bronze,steel,mithril,adamantite,runite,titanium,laser,plasma,matterbane}Material;
typedef enum Variant{one_hand, two_hand}Variant;
typedef enum Weapon_Group{mele,ranged}Weapon_Group;
typedef enum Type{normal,magical}Type;
typedef enum Quality_Level{poor,adequate,good,great,excellent,masterful,epic,legendary,artefact}Quality_Level;
//typedef enum Enchantment_Level{low,medium,high,very_high,epic,legendary,artefact}Enchantment_Level;

typedef enum Worn_In{head_slot,neck_slot,finger_slot,torso_slot,legs_slot,back_slot,mainhand_slot,offhand_slot, feet_slot}Worn_in;
typedef enum Item_Kind{reagent,consumable,weapon,armor}Item_Kind;
typedef enum Reagent_Kind{cooking,smithing,fishing,herb,computer}Reagent_Kind;
typedef enum Weapon_Kind{sword,mace,axe}Weapon_Kind;
typedef enum {helmet, hat, mask, chestplate,robe,chainmail,leggings, trousers, ring,boots }Equipment_Kind;
typedef enum {very_light, light, medium, heavy,very_heavy}Equipment_Classification;
typedef struct{
  int id;
  Reagent_Kind reagent_kind;
}Reagent;
typedef struct{
  int id;
  int hp_change;
  float weight;
}Consumable;
typedef struct Armor{
  Quality_Level quality;
  uint64_t armor;
  Worn_in slot; //in which item slot will the item be worn in
  Material material;
  uint16_t skill;
  Equipment_Kind armor_type;
  Equipment_Classification weight_classification;
}Armor;

typedef struct Weapon{
  Quality_Level quality;
  Variant variant;
  Material material;
  Weapon_Group group;
  uint64_t dmg;
  Weapon_Kind kind;
  Worn_in slot;
}Weapon;

typedef union Equipment{
  Armor *armor;
  Weapon *weapon;
}Equipment;


typedef struct Item{
  int id;
  void *item_specific_info;
  char *representation;
  char *standing_on;
  uint32_t value;
  Item_Kind kind;
  float weight;
  uint8_t quest_item; //an unsigned int to specify if an item is a quest item and an id to specify
  uint8_t quest_id; //which quest it belongs to.
}Item;

typedef struct Item_Holder{ //a struct for an item and how many of that item currently is in the inventory
  Item *item;
  int amount;
}Item_Holder;


Item_Holder *i_make_item_holder(Item *item, unsigned amount);
void i_swap_pointers(Item_Holder *i,Item_Holder *j);

Item *i_make_mele_weapon(Quality_Level q, Material material, Variant v,Weapon_Kind weapon_kind);

Item *i_make_consumable(char *name, char *description,uint32_t healing, uint32_t value, float weight, uint16_t skill);

Armor *i_gen_armor(Quality_Level q, Material material,Equipment_Kind armor_type);
Consumable *i_gen_consumable(uint32_t healing, uint32_t value, float weight, uint16_t skill);

Reagent *i_gen_reagent(Variant variant,float weight,uint32_t value,Reagent_Kind kind);

Weapon *i_gen_weapon(Quality_Level q,Variant variant,Material material,Weapon_Group group,Weapon_Kind k);
Item *i_make_armor(Quality_Level q, Material material, Equipment_Kind armor_type);
Consumable *i_create_consumable(char *name, char *description);

Item *i_create_item(char *name, char *description,Item_Kind kind);

char *i_mele_weapon_name(Quality_Level q, Material material, Variant v, Weapon_Kind kind);
char *i_consumable_name();
char *i_reagent_name();
char *i_material_name(Material material);
char *i_variant_name(Variant v);
char *i_quality_name(Quality_Level q);
Item *i_make_weapon(Quality_Level q, Material material, Variant v);


void i_free_reagent(Item_Holder *item);
void i_free_consumable(Item_Holder *item);
Item *i_copy_item(Item_Holder *item);



extern void (*copy_item_handler[5])(Item *i);


extern void (*i_print_item_name_handler[3])(Item *i);

extern inline void i_derive_item_name(Item *i,char *bfr);

void i_print_reagent_name(Item *i, WINDOW *inv_screen,int x, int y);
void i_print_consumable_name(Item *i, WINDOW *inv_screen,int x, int y);
void i_print_equippable_name(Item *i, WINDOW *inv_screen,int x, int y);







/*if the items are of a different type, we can trivially conlclude that they are not the same*/
# 171 "/home/anton/revenant/game/headers/item.h"
extern Item_Holder* (*i_item_holder_copy_handler[4])(Item_Holder *source_item,Item_Holder *target_item);
extern void (*i_free_item_handler[4])(Item_Holder *item);
Item_Holder *i_copy_reagent(Item_Holder *source_item,Item_Holder *target_item);

Item_Holder *i_copy_consumable(Item_Holder *source_item,Item_Holder *target_item);

Item_Holder *i_copy_weapon(Item_Holder *source_item,Item_Holder *target_item);

Item_Holder *i_copy_armor(Item_Holder *source_item,Item_Holder *target_item);
//Item_Holder *i_readin_reagent(char *reagent_file_path);
# 23 "/home/anton/revenant/game/headers/u_hash.h" 2
# 1 "/home/anton/revenant/game/headers/rng.h" 1
/*This file is part of Revenant.
Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
Revenant  is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */


# 1 "/usr/include/stdlib.h" 1 3 4

# 1 "/usr/include/stdlib.h" 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   Copyright The GNU Toolchain Authors.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.20 General utilities	<stdlib.h>
 */
# 14 "/home/anton/revenant/game/headers/rng.h" 2
# 1 "/usr/include/time.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.23 Date and time	<time.h>
 */




# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 26 "/usr/include/time.h" 2 3 4



# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 1 3 4
/* Copyright (C) 1989-2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */






/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */
# 46 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */
# 86 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 111 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 159 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 235 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 387 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
/* A null pointer constant.  */
# 30 "/usr/include/time.h" 2 3 4

/* This defines CLOCKS_PER_SEC, which is the number of processor clock
   ticks per second, and possibly a number of other constants.   */
# 1 "/usr/include/x86_64-linux-gnu/bits/time.h" 1 3 4
/* System-dependent timing definitions.  Linux version.
   Copyright (C) 1996-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <time.h> instead.
 */




# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 27 "/usr/include/x86_64-linux-gnu/bits/time.h" 2 3 4

/* ISO/IEC 9899:1999 7.23.1: Components of time
   The macro `CLOCKS_PER_SEC' is an expression with type `clock_t' that is
   the number per second of the value returned by the `clock' function.  */
/* CAE XSH, Issue 4, Version 2: <time.h>
   The value of CLOCKS_PER_SEC is required to be 1 million on all
   XSI-conformant systems. */
# 45 "/usr/include/x86_64-linux-gnu/bits/time.h" 3 4
/* Identifier for system-wide realtime clock.  */

/* Monotonic system-wide clock.  */

/* High-resolution timer from the CPU.  */

/* Thread-specific CPU-time clock.  */

/* Monotonic system-wide clock, not adjusted for frequency scaling.  */

/* Identifier for system-wide realtime clock, updated only on ticks.  */

/* Monotonic system-wide clock, updated only on ticks.  */

/* Monotonic system-wide clock that includes time spent in suspension.  */

/* Like CLOCK_REALTIME but also wakes suspended system.  */

/* Like CLOCK_BOOTTIME but also wakes suspended system.  */

/* Like CLOCK_REALTIME but in International Atomic Time.  */


/* Flag to indicate time is absolute.  */
# 34 "/usr/include/time.h" 2 3 4

/* Many of the typedefs and structs whose official home is this header
   may also need to be defined by other headers.  */


# 1 "/usr/include/x86_64-linux-gnu/bits/types/struct_tm.h" 1 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 5 "/usr/include/x86_64-linux-gnu/bits/types/struct_tm.h" 2 3 4

/* ISO C `broken-down time' structure.  */
struct tm
{
  int tm_sec; /* Seconds.	[0-60] (1 leap second) */
  int tm_min; /* Minutes.	[0-59] */
  int tm_hour; /* Hours.	[0-23] */
  int tm_mday; /* Day.		[1-31] */
  int tm_mon; /* Month.	[0-11] */
  int tm_year; /* Year	- 1900.  */
  int tm_wday; /* Day of week.	[0-6] */
  int tm_yday; /* Days in year.[0-365]	*/
  int tm_isdst; /* DST.		[-1/0/1]*/


  long int tm_gmtoff; /* Seconds east of UTC.  */
  const char *tm_zone; /* Timezone abbreviation.  */




};
# 40 "/usr/include/time.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h" 1 3 4
/* NB: Include guard matches what <linux/time.h> uses.  */
# 43 "/usr/include/time.h" 2 3 4





# 1 "/usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h" 1 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 5 "/usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h" 1 3 4
/* NB: Include guard matches what <linux/time.h> uses.  */
# 6 "/usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h" 2 3 4

/* POSIX.1b structure for timer start values and intervals.  */
struct itimerspec
  {
    struct timespec it_interval;
    struct timespec it_value;
  };
# 49 "/usr/include/time.h" 2 3 4
struct sigevent;
# 60 "/usr/include/time.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 1 3 4
/* Definition of locale_t.
   Copyright (C) 2017-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
# 61 "/usr/include/time.h" 2 3 4



/* Time base values for timespec_get.  */





/* Time used by the program so far (user time + system time).
   The result / CLOCKS_PER_SEC is program time in seconds.  */
extern clock_t clock (void) __attribute__ ((__nothrow__ , __leaf__));


/* Return the current time and put it in *TIMER if TIMER is not NULL.  */
extern time_t time (time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));

/* Return the difference between TIME1 and TIME0.  */
extern double difftime (time_t __time1, time_t __time0)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

/* Return the `time_t' representation of TP and normalize TP.  */
extern time_t mktime (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
# 97 "/usr/include/time.h" 3 4
/* Format TP into S according to FORMAT.
   Write no more than MAXSIZE characters and return the number
   of characters written, or 0 if it would exceed MAXSIZE.  */
extern size_t strftime (char *__restrict __s, size_t __maxsize,
   const char *__restrict __format,
   const struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));
# 113 "/usr/include/time.h" 3 4
/* Similar to the two functions above but take the information from
   the provided locale and not the global locale.  */

extern size_t strftime_l (char *__restrict __s, size_t __maxsize,
     const char *__restrict __format,
     const struct tm *__restrict __tp,
     locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
# 130 "/usr/include/time.h" 3 4
/* Return the `struct tm' representation of *TIMER
   in Universal Coordinated Time (aka Greenwich Mean Time).  */
extern struct tm *gmtime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));

/* Return the `struct tm' representation
   of *TIMER in the local timezone.  */
extern struct tm *localtime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
# 152 "/usr/include/time.h" 3 4
/* Return the `struct tm' representation of *TIMER in UTC,
   using *TP to store the result.  */
extern struct tm *gmtime_r (const time_t *__restrict __timer,
       struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));

/* Return the `struct tm' representation of *TIMER in local time,
   using *TP to store the result.  */
extern struct tm *localtime_r (const time_t *__restrict __timer,
          struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));
# 177 "/usr/include/time.h" 3 4
/* Return a string of the form "Day Mon dd hh:mm:ss yyyy\n"
   that is the representation of TP in this format.  */
extern char *asctime (const struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));

/* Equivalent to `asctime (localtime (timer))'.  */

extern char *ctime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
# 193 "/usr/include/time.h" 3 4
/* Reentrant versions of the above functions.  */

/* Return in BUF a string of the form "Day Mon dd hh:mm:ss yyyy\n"
   that is the representation of TP in this format.  */
extern char *asctime_r (const struct tm *__restrict __tp,
   char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));

/* Equivalent to `asctime_r (localtime_r (timer, *TMP*), buf)'.  */

extern char *ctime_r (const time_t *__restrict __timer,
        char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
# 216 "/usr/include/time.h" 3 4
/* Defined in localtime.c.  */
extern char *__tzname[2]; /* Current timezone names.  */
extern int __daylight; /* If daylight-saving time is ever in use.  */
extern long int __timezone; /* Seconds west of UTC.  */



/* Same as above.  */
extern char *tzname[2];

/* Set time conversion information from the TZ environment variable.
   If TZ is not defined, a locale-dependent default is used.  */
extern void tzset (void) __attribute__ ((__nothrow__ , __leaf__));



extern int daylight;
extern long int timezone;



/* Nonzero if YEAR is a leap year (every 4 years,
   except every 100th isn't, and every 400th is).  */





/* Miscellaneous functions many Unices inherited from the public domain
   localtime package.  These are included only for compatibility.  */


/* Like `mktime', but for TP represents Universal Time, not local time.  */
extern time_t timegm (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
/* Another name for `mktime'.  */
extern time_t timelocal (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
# 261 "/usr/include/time.h" 3 4
/* Return the number of days in YEAR.  */
extern int dysize (int __year) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));





/* Pause execution for a number of nanoseconds.

   This function is a cancellation point and therefore not marked with
   __THROW.  */
extern int nanosleep (const struct timespec *__requested_time,
        struct timespec *__remaining);

/* Get resolution of clock CLOCK_ID.  */
extern int clock_getres (clockid_t __clock_id, struct timespec *__res) __attribute__ ((__nothrow__ , __leaf__));

/* Get current value of clock CLOCK_ID and store it in TP.  */
extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp) __attribute__ ((__nothrow__ , __leaf__));

/* Set clock CLOCK_ID to value TP.  */
extern int clock_settime (clockid_t __clock_id, const struct timespec *__tp)
     __attribute__ ((__nothrow__ , __leaf__));
# 306 "/usr/include/time.h" 3 4
/* High-resolution sleep with the specified clock.

   This function is a cancellation point and therefore not marked with
   __THROW.  */

extern int clock_nanosleep (clockid_t __clock_id, int __flags,
       const struct timespec *__req,
       struct timespec *__rem);
# 325 "/usr/include/time.h" 3 4
/* Return clock ID for CPU-time clock.  */
extern int clock_getcpuclockid (pid_t __pid, clockid_t *__clock_id) __attribute__ ((__nothrow__ , __leaf__));



/* Create new per-process timer using CLOCK_ID.  */
extern int timer_create (clockid_t __clock_id,
    struct sigevent *__restrict __evp,
    timer_t *__restrict __timerid) __attribute__ ((__nothrow__ , __leaf__));

/* Delete timer TIMERID.  */
extern int timer_delete (timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));

/* Set timer TIMERID to VALUE, returning old value in OVALUE.  */

extern int timer_settime (timer_t __timerid, int __flags,
     const struct itimerspec *__restrict __value,
     struct itimerspec *__restrict __ovalue) __attribute__ ((__nothrow__ , __leaf__));

/* Get current value of timer TIMERID and store it in VALUE.  */
extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
     __attribute__ ((__nothrow__ , __leaf__));
# 363 "/usr/include/time.h" 3 4
/* Get expiration overrun for timer TIMERID.  */
extern int timer_getoverrun (timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));





/* Set TS to calendar time based in time base BASE.  */
extern int timespec_get (struct timespec *__ts, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 440 "/usr/include/time.h" 3 4

# 15 "/home/anton/revenant/game/headers/rng.h" 2




# 18 "/home/anton/revenant/game/headers/rng.h"
/*An implementation of a 32-bit mersienne twister. It will work on 64+ bit systems however, it only guarantees 32 bits of randomness, so pseudo-randomness is probably worse on 32+ bit systems*/
# 32 "/home/anton/revenant/game/headers/rng.h"
/* Imitates die rolls, using the mersenne twister under the hood*. Arguement for upper value range is given as  limit+1 since the function for ensuring the value is in the given range
is [min,max( and therefore use max+1 to ensure that we could also potentially generate the max value */
# 46 "/home/anton/revenant/game/headers/rng.h"
typedef struct{
  int *mt;
  int index;
  int lower_mask;
  int upper_mask;
}Mersienne_Twister;

void rng_seed_mt(int seed, Mersienne_Twister *twister);

int rng_extract_number(Mersienne_Twister *twister);

void rng_twist(Mersienne_Twister *twister);

Mersienne_Twister *rng_generate_twister();
# 24 "/home/anton/revenant/game/headers/u_hash.h" 2
# 1 "/home/anton/revenant/game/headers/strings.h" 1
/*This file is part of Revnant.

Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Revenant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */
# 25 "/home/anton/revenant/game/headers/u_hash.h" 2
# 38 "/home/anton/revenant/game/headers/u_hash.h"
//Just a highly specialized structure that holds a reference to an item and how much weight there is to be subtracted from the player's
//carry weight and a flag that indicated if we deleted it from inventory 
typedef struct Item_Weight{
  Item *item;
  float weight_loss;
  int deleted;
}Item_Weight;

typedef struct Entry{
  Item_Holder *item_holder;
  struct Entry *next_entry;
}Entry;



typedef struct Entry_Pairs{ // If a lookup with modification is ever needed, we will need parent-child anyways so might as well have functions return exactly that
  Entry *parent;
  Entry *child;
  unsigned long long offset;
}Entry_Pairs;

typedef struct U_Hashtable{
  int size;
  int item_count;
  Entry **entries;
  unsigned long long a;
  unsigned long long b;
  int money;
}U_Hashtable;

unsigned long long u_hash(int char_count,U_Hashtable *table,char *strings, ...);

U_Hashtable *u_initialize_hashtable(int initial_size,Mersienne_Twister *twister);

void u_add_item(Item_Holder *item, int amount,U_Hashtable *table);

Item_Weight u_remove_item(Item_Holder *item, int amount, U_Hashtable *table,int free_item_if_removed);


char *u_readin_char(char *file_path, char *variable);







//#define U_DECIDE_FILEPATH(item)({char *file_path; item->kind == reagent ? (file_path = malloc(sizeof(char) * strlen("/usr/lib/revenant_files/item_files/reagent_files/") +5); sprintf(file_path,"/usr/lib/revenant_files/item_files/reagent_files/%d",item->id);) :(file_path = malloc(sizeof(char) * strlen("/usr/lib/revenant_files/item_files/reagent_files/") +5); sprintf(file_path,"/usr/lib/revenant_files/item_files/reagent_files/%d",item->id);) file_path;  })
# 16 "src/u_hash.c" 2
# 1 "/home/anton/revenant/game/headers/screen_constants.h" 1
/*This file is part of Revenant.
Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
Revenant  is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */
# 17 "src/u_hash.c" 2
unsigned long long u_hash(int char_count,U_Hashtable *table, char *strings, ...){
  return((table->a * s_uint_from_string(char_count,strings) + table->b) % 18446744073709551615ULL) % table->size;
}

U_Hashtable *u_initialize_hashtable(int initial_size,Mersienne_Twister *twister){
  U_Hashtable *table = malloc(sizeof(U_Hashtable));
  table->size = initial_size;
  table->item_count = 0;
  table->entries = malloc(sizeof(Entry *) * initial_size);
  for(int i = 0; i < initial_size; i++){
    table->entries[i] = 
# 27 "src/u_hash.c" 3 4
                       ((void *)0)
# 27 "src/u_hash.c"
                           ;
  }
  table->a = (rng_extract_number(twister) % (18446744073709551615ULL -1) + 1);
  table->b = (rng_extract_number(twister) % (18446744073709551615ULL -0) + 0);
  return table;
}

void u_add_item(Item_Holder *item, int amount,U_Hashtable *table){
  unsigned long long index = item->item->kind != weapon && item->item->kind != armor ? ({unsigned long long hash; char *filepath = (item->item->kind == reagent ? (({char *file_path; file_path = malloc(sizeof(char) * strlen("/usr/lib/revenant_files/item_files/reagent_files/") +5); sprintf(file_path,"/usr/lib/revenant_files/item_files/reagent_files/%d",item->item->id); file_path;})) : (({char *file_path; file_path = malloc(sizeof(char) * strlen("/usr/lib/revenant_files/item_files/reagent_files/") +5); sprintf(file_path,"/usr/lib/revenant_files/item_files/consumable_files/%d",item->item->id); file_path;}))); hash = ir_hash_string(filepath, "name",table); free(filepath); hash;}) : item->item->kind == weapon ? ({unsigned long long hash; hash = u_hash(2,table, quality_name_modifier[((struct Weapon*)item->item->item_specific_info)->quality] , material_name_modifier[((struct Weapon*)item->item->item_specific_info)->material] , handed_modifier[((struct Weapon*)item->item->item_specific_info)->variant], mele_weapon_name_modifier[((struct Weapon*)item->item->item_specific_info)->kind] ); hash;}) : ({unsigned long long hash; hash = u_hash(1, table,quality_name_modifier[((struct Armor*)item->item->item_specific_info)->quality]); hash;});
  // printf(" on add index is: %llu ",index);
    //Item already present in inventory 
//Maybe delete item at this point, maybe not since we might not use it after adding to inventory??

  //It's very important that we put parenthesis around the two last conditions because otherwise the logical short circuiting of the first statement won't kick into effect for
  // some reason, thus checking the second condition, potentially accessing a null pointer value, which woud cause a segmentation fault
  //Zero, in the case of strcmp means "True"


  if(table->entries[index] != 
# 45 "src/u_hash.c" 3 4
                             ((void *)0) 
# 45 "src/u_hash.c"
                                  && (table->entries[index]->item_holder->item->kind == item->item->kind && (table->entries[index]->item_holder->item->kind != item->item->kind ? 1 : item->item->kind == weapon || item->item->kind == armor ? item->item->kind == weapon ? ({int is_equal = 0; const char *source_item_holder_quality = quality_name_modifier[((struct Weapon *)table->entries[index]->item_holder->item->item_specific_info)->quality]; const char *source_item_holder_material = material_name_modifier[((struct Weapon *)table->entries[index]->item_holder->item->item_specific_info)->material]; const char *source_item_holder_handed_modifier = handed_modifier[((struct Weapon *)table->entries[index]->item_holder->item->item_specific_info)->variant]; const char *source_item_holder_kind_modifier = mele_weapon_name_modifier[((struct Weapon *)table->entries[index]->item_holder->item->item_specific_info)->kind]; const char *target_item_holder_quality = quality_name_modifier[((struct Weapon *)item->item->item_specific_info)->quality]; const char *target_item_holder_material = material_name_modifier[((struct Weapon *)item->item->item_specific_info)->material]; const char *target_item_holder_handed_modifier = handed_modifier[((struct Weapon *)item->item->item_specific_info)->variant]; const char *target_item_holder_kind_modifier = mele_weapon_name_modifier[((struct Weapon *)item->item->item_specific_info)->kind]; is_equal = (strcmp(source_item_holder_quality,target_item_holder_quality) | strcmp(source_item_holder_material, target_item_holder_material) | strcmp(source_item_holder_handed_modifier,target_item_holder_handed_modifier) | strcmp(source_item_holder_kind_modifier,target_item_holder_kind_modifier)); is_equal;}) : ({int is_equal; const char *source_item_holder_quality = quality_name_modifier[((struct Armor *)table->entries[index]->item_holder->item->item_specific_info)->quality]; const char *source_item_holder_material = material_name_modifier[((struct Armor *)table->entries[index]->item_holder->item->item_specific_info)->material]; const char *source_item_holder_armor_type = equipment_type_modifier[((struct Armor *)table->entries[index]->item_holder->item->item_specific_info)->armor_type]; char *target_item_holder_quality = quality_name_modifier[((struct Armor *)item->item->item_specific_info)->quality]; const char *target_item_holder_material = material_name_modifier[((struct Armor *)item->item->item_specific_info)->material]; const char *target_item_holder_armor_type = equipment_type_modifier[((struct Armor *)item->item->item_specific_info)->armor_type]; is_equal = (strcmp(source_item_holder_quality,target_item_holder_quality) | strcmp(source_item_holder_material,target_item_holder_material) | strcmp(source_item_holder_armor_type,target_item_holder_armor_type) ); is_equal;}) : table->entries[index]->item_holder->item->kind == item->item->kind && table->entries[index]->item_holder->item->id == item->item->id ? 0 : 1) == 0)){
     table->entries[index]->item_holder->amount += amount;
  }

  else if(table->entries[index] == 
# 49 "src/u_hash.c" 3 4
                                  ((void *)0)
# 49 "src/u_hash.c"
                                      ){
     table->entries[index] = malloc(sizeof(Entry));
     table->entries[index]->item_holder = item;
     table->entries[index]->next_entry = 
# 52 "src/u_hash.c" 3 4
                                        ((void *)0)
# 52 "src/u_hash.c"
                                            ;
     table->item_count++;
     //printf("%s", "Second case, \n");
  }
  //   else it must be that table->entries[index] != NULL && (table->entries[index]->item_holder->item->kind == item->item->kind && HAS_SAME_NAME_TRIVIAL(table->entries[index]->item_holder, item) == 0)  
   else{
     //      printf("%s", "Third case of u_add_item ");
    if(table->entries[index]->next_entry == 
# 59 "src/u_hash.c" 3 4
                                           ((void *)0)
# 59 "src/u_hash.c"
                                               ){
      //printf("%s", " and next entry is null ");
      table->entries[index]->next_entry = malloc(sizeof(Entry));
      table->entries[index]->next_entry->item_holder = item;
      table->entries[index]->next_entry->next_entry = 
# 63 "src/u_hash.c" 3 4
                                                     ((void *)0)
# 63 "src/u_hash.c"
                                                         ;
      table->item_count++;
      return;

    }

    Entry *current_entry = table->entries[index]->next_entry;
    while(current_entry->next_entry != 
# 70 "src/u_hash.c" 3 4
                                      ((void *)0)
# 70 "src/u_hash.c"
                                          ){
      if((current_entry->item_holder->item->kind != item->item->kind ? 1 : item->item->kind == weapon || item->item->kind == armor ? item->item->kind == weapon ? ({int is_equal = 0; const char *source_item_holder_quality = quality_name_modifier[((struct Weapon *)current_entry->item_holder->item->item_specific_info)->quality]; const char *source_item_holder_material = material_name_modifier[((struct Weapon *)current_entry->item_holder->item->item_specific_info)->material]; const char *source_item_holder_handed_modifier = handed_modifier[((struct Weapon *)current_entry->item_holder->item->item_specific_info)->variant]; const char *source_item_holder_kind_modifier = mele_weapon_name_modifier[((struct Weapon *)current_entry->item_holder->item->item_specific_info)->kind]; const char *target_item_holder_quality = quality_name_modifier[((struct Weapon *)item->item->item_specific_info)->quality]; const char *target_item_holder_material = material_name_modifier[((struct Weapon *)item->item->item_specific_info)->material]; const char *target_item_holder_handed_modifier = handed_modifier[((struct Weapon *)item->item->item_specific_info)->variant]; const char *target_item_holder_kind_modifier = mele_weapon_name_modifier[((struct Weapon *)item->item->item_specific_info)->kind]; is_equal = (strcmp(source_item_holder_quality,target_item_holder_quality) | strcmp(source_item_holder_material, target_item_holder_material) | strcmp(source_item_holder_handed_modifier,target_item_holder_handed_modifier) | strcmp(source_item_holder_kind_modifier,target_item_holder_kind_modifier)); is_equal;}) : ({int is_equal; const char *source_item_holder_quality = quality_name_modifier[((struct Armor *)current_entry->item_holder->item->item_specific_info)->quality]; const char *source_item_holder_material = material_name_modifier[((struct Armor *)current_entry->item_holder->item->item_specific_info)->material]; const char *source_item_holder_armor_type = equipment_type_modifier[((struct Armor *)current_entry->item_holder->item->item_specific_info)->armor_type]; char *target_item_holder_quality = quality_name_modifier[((struct Armor *)item->item->item_specific_info)->quality]; const char *target_item_holder_material = material_name_modifier[((struct Armor *)item->item->item_specific_info)->material]; const char *target_item_holder_armor_type = equipment_type_modifier[((struct Armor *)item->item->item_specific_info)->armor_type]; is_equal = (strcmp(source_item_holder_quality,target_item_holder_quality) | strcmp(source_item_holder_material,target_item_holder_material) | strcmp(source_item_holder_armor_type,target_item_holder_armor_type) ); is_equal;}) : current_entry->item_holder->item->kind == item->item->kind && current_entry->item_holder->item->id == item->item->id ? 0 : 1) == 0){
 current_entry->item_holder->amount += amount;
 return;
      }
      current_entry = current_entry->next_entry;
    }
    current_entry->next_entry = malloc(sizeof(Entry));
    current_entry->next_entry->item_holder = item;
    current_entry->next_entry->next_entry = 
# 79 "src/u_hash.c" 3 4
                                           ((void *)0)
# 79 "src/u_hash.c"
                                               ;
    //printf("called a item count incr");
    table->item_count++;
  }
}


Item_Weight u_remove_item(Item_Holder *item, int amount, U_Hashtable *table, int free_item_if_removed){
  unsigned long long index = item->item->kind != weapon && item->item->kind != armor ? ({unsigned long long hash; char *filepath = (item->item->kind == reagent ? (({char *file_path; file_path = malloc(sizeof(char) * strlen("/usr/lib/revenant_files/item_files/reagent_files/") +5); sprintf(file_path,"/usr/lib/revenant_files/item_files/reagent_files/%d",item->item->id); file_path;})) : (({char *file_path; file_path = malloc(sizeof(char) * strlen("/usr/lib/revenant_files/item_files/reagent_files/") +5); sprintf(file_path,"/usr/lib/revenant_files/item_files/consumable_files/%d",item->item->id); file_path;}))); hash = ir_hash_string(filepath, "name",table); free(filepath); hash;}) : item->item->kind == weapon ? ({unsigned long long hash; hash = u_hash(2,table, quality_name_modifier[((struct Weapon*)item->item->item_specific_info)->quality] , material_name_modifier[((struct Weapon*)item->item->item_specific_info)->material] , handed_modifier[((struct Weapon*)item->item->item_specific_info)->variant], mele_weapon_name_modifier[((struct Weapon*)item->item->item_specific_info)->kind] ); hash;}) : ({unsigned long long hash; hash = u_hash(1, table,quality_name_modifier[((struct Armor*)item->item->item_specific_info)->quality]); hash;});
  //  printf(" On removal, index is: %llu ",index);
  // if(((struct Weapon *)item->item->item_specific_info)->material == bronze){
  //printf("%s%llu", " " , index);
  //}
  Item_Weight item_weight;
  // If the item we are looking for is at the top-level, then assert if we are removing all occurences of the items and act correspondingly
  // Unsure why but we have to wrap the HAS_SAME_NAME_TRIVIAL macro in parenthesis in this case, but not for item insert for it to actually return a value

  if(table->entries[index] != 
# 96 "src/u_hash.c" 3 4
                             ((void *)0) 
# 96 "src/u_hash.c"
                                  && (table->entries[index]->item_holder->item->kind == item->item->kind && (table->entries[index]->item_holder->item->kind != item->item->kind ? 1 : item->item->kind == weapon || item->item->kind == armor ? item->item->kind == weapon ? ({int is_equal = 0; const char *source_item_holder_quality = quality_name_modifier[((struct Weapon *)table->entries[index]->item_holder->item->item_specific_info)->quality]; const char *source_item_holder_material = material_name_modifier[((struct Weapon *)table->entries[index]->item_holder->item->item_specific_info)->material]; const char *source_item_holder_handed_modifier = handed_modifier[((struct Weapon *)table->entries[index]->item_holder->item->item_specific_info)->variant]; const char *source_item_holder_kind_modifier = mele_weapon_name_modifier[((struct Weapon *)table->entries[index]->item_holder->item->item_specific_info)->kind]; const char *target_item_holder_quality = quality_name_modifier[((struct Weapon *)item->item->item_specific_info)->quality]; const char *target_item_holder_material = material_name_modifier[((struct Weapon *)item->item->item_specific_info)->material]; const char *target_item_holder_handed_modifier = handed_modifier[((struct Weapon *)item->item->item_specific_info)->variant]; const char *target_item_holder_kind_modifier = mele_weapon_name_modifier[((struct Weapon *)item->item->item_specific_info)->kind]; is_equal = (strcmp(source_item_holder_quality,target_item_holder_quality) | strcmp(source_item_holder_material, target_item_holder_material) | strcmp(source_item_holder_handed_modifier,target_item_holder_handed_modifier) | strcmp(source_item_holder_kind_modifier,target_item_holder_kind_modifier)); is_equal;}) : ({int is_equal; const char *source_item_holder_quality = quality_name_modifier[((struct Armor *)table->entries[index]->item_holder->item->item_specific_info)->quality]; const char *source_item_holder_material = material_name_modifier[((struct Armor *)table->entries[index]->item_holder->item->item_specific_info)->material]; const char *source_item_holder_armor_type = equipment_type_modifier[((struct Armor *)table->entries[index]->item_holder->item->item_specific_info)->armor_type]; char *target_item_holder_quality = quality_name_modifier[((struct Armor *)item->item->item_specific_info)->quality]; const char *target_item_holder_material = material_name_modifier[((struct Armor *)item->item->item_specific_info)->material]; const char *target_item_holder_armor_type = equipment_type_modifier[((struct Armor *)item->item->item_specific_info)->armor_type]; is_equal = (strcmp(source_item_holder_quality,target_item_holder_quality) | strcmp(source_item_holder_material,target_item_holder_material) | strcmp(source_item_holder_armor_type,target_item_holder_armor_type) ); is_equal;}) : table->entries[index]->item_holder->item->kind == item->item->kind && table->entries[index]->item_holder->item->id == item->item->id ? 0 : 1) == 0)){
    // printf("%s", " first case ");
    if(amount >= table->entries[index]->item_holder->amount){
      table->item_count--;
      if(free_item_if_removed == 0){
 i_free_item(table->entries[index]->item_holder->item);
 free(table->entries[index]->item_holder);
 table->entries[index]->item_holder = 
# 103 "src/u_hash.c" 3 4
                                     ((void *)0)
# 103 "src/u_hash.c"
                                         ;
 free(table->entries[index]);
 table->entries[index] = 
# 105 "src/u_hash.c" 3 4
                        ((void *)0)
# 105 "src/u_hash.c"
                            ;
      }
      else{
      item_weight.item = table->entries[index]->item_holder->item;
      item_weight.weight_loss = (table->entries[index]->item_holder->amount * table->entries[index]->item_holder->item->weight);
      item_weight.deleted = 1;
      table->entries[index]->item_holder->amount = 0;
      //printf("NULL 1 here");
      Entry *tmp = table->entries[index];
      Entry *replacement = table->entries[index]->next_entry;
      table->entries[index] = replacement;
      free(tmp);
      return item_weight;
      }
    }
    else{
      table->entries[index]->item_holder->amount -= amount;
      item_weight.item = table->entries[index]->item_holder->item;
      item_weight.weight_loss = (amount * table->entries[index]->item_holder->item->weight);
      item_weight.deleted = 0;
      return item_weight;
    }
  }





  // If the item was not found at the top-level, start the search in the chained sequence of items and act accordingly, depending on whether we remove all occurences of said item
  //strcmp returns 0 iff the strings are equal, otherwise it returns a nonzero value, so we have to check if the return value is nonzero to see if we have to go through the Entry
  //chain
  else if(table->entries[index] != 
# 136 "src/u_hash.c" 3 4
                                  ((void *)0) 
# 136 "src/u_hash.c"
                                       && (table->entries[index]->item_holder->item->kind == item->item->kind && (table->entries[index]->item_holder->item->kind != item->item->kind ? 1 : item->item->kind == weapon || item->item->kind == armor ? item->item->kind == weapon ? ({int is_equal = 0; const char *source_item_holder_quality = quality_name_modifier[((struct Weapon *)table->entries[index]->item_holder->item->item_specific_info)->quality]; const char *source_item_holder_material = material_name_modifier[((struct Weapon *)table->entries[index]->item_holder->item->item_specific_info)->material]; const char *source_item_holder_handed_modifier = handed_modifier[((struct Weapon *)table->entries[index]->item_holder->item->item_specific_info)->variant]; const char *source_item_holder_kind_modifier = mele_weapon_name_modifier[((struct Weapon *)table->entries[index]->item_holder->item->item_specific_info)->kind]; const char *target_item_holder_quality = quality_name_modifier[((struct Weapon *)item->item->item_specific_info)->quality]; const char *target_item_holder_material = material_name_modifier[((struct Weapon *)item->item->item_specific_info)->material]; const char *target_item_holder_handed_modifier = handed_modifier[((struct Weapon *)item->item->item_specific_info)->variant]; const char *target_item_holder_kind_modifier = mele_weapon_name_modifier[((struct Weapon *)item->item->item_specific_info)->kind]; is_equal = (strcmp(source_item_holder_quality,target_item_holder_quality) | strcmp(source_item_holder_material, target_item_holder_material) | strcmp(source_item_holder_handed_modifier,target_item_holder_handed_modifier) | strcmp(source_item_holder_kind_modifier,target_item_holder_kind_modifier)); is_equal;}) : ({int is_equal; const char *source_item_holder_quality = quality_name_modifier[((struct Armor *)table->entries[index]->item_holder->item->item_specific_info)->quality]; const char *source_item_holder_material = material_name_modifier[((struct Armor *)table->entries[index]->item_holder->item->item_specific_info)->material]; const char *source_item_holder_armor_type = equipment_type_modifier[((struct Armor *)table->entries[index]->item_holder->item->item_specific_info)->armor_type]; char *target_item_holder_quality = quality_name_modifier[((struct Armor *)item->item->item_specific_info)->quality]; const char *target_item_holder_material = material_name_modifier[((struct Armor *)item->item->item_specific_info)->material]; const char *target_item_holder_armor_type = equipment_type_modifier[((struct Armor *)item->item->item_specific_info)->armor_type]; is_equal = (strcmp(source_item_holder_quality,target_item_holder_quality) | strcmp(source_item_holder_material,target_item_holder_material) | strcmp(source_item_holder_armor_type,target_item_holder_armor_type) ); is_equal;}) : table->entries[index]->item_holder->item->kind == item->item->kind && table->entries[index]->item_holder->item->id == item->item->id ? 0 : 1) != 0)){
    //    int i = HAS_SAME_NAME_TRIVIAL(table->entries[index]->item_holder, item);
    //    printf("%s%d", " second case of removal", i);
    //    printf("%s",material_name_modifier[((struct Weapon *)table->entries[index]->item_holder->item->item_specific_info)->material]);
    Entry *previous_entry = table->entries[index];
    Entry *current_entry = table->entries[index]->next_entry;
    //Edge case of when the immedediately next entry was the item we were looking for
    if(current_entry->item_holder->item->kind == item->item->kind && (current_entry->item_holder->item->kind != item->item->kind ? 1 : item->item->kind == weapon || item->item->kind == armor ? item->item->kind == weapon ? ({int is_equal = 0; const char *source_item_holder_quality = quality_name_modifier[((struct Weapon *)current_entry->item_holder->item->item_specific_info)->quality]; const char *source_item_holder_material = material_name_modifier[((struct Weapon *)current_entry->item_holder->item->item_specific_info)->material]; const char *source_item_holder_handed_modifier = handed_modifier[((struct Weapon *)current_entry->item_holder->item->item_specific_info)->variant]; const char *source_item_holder_kind_modifier = mele_weapon_name_modifier[((struct Weapon *)current_entry->item_holder->item->item_specific_info)->kind]; const char *target_item_holder_quality = quality_name_modifier[((struct Weapon *)item->item->item_specific_info)->quality]; const char *target_item_holder_material = material_name_modifier[((struct Weapon *)item->item->item_specific_info)->material]; const char *target_item_holder_handed_modifier = handed_modifier[((struct Weapon *)item->item->item_specific_info)->variant]; const char *target_item_holder_kind_modifier = mele_weapon_name_modifier[((struct Weapon *)item->item->item_specific_info)->kind]; is_equal = (strcmp(source_item_holder_quality,target_item_holder_quality) | strcmp(source_item_holder_material, target_item_holder_material) | strcmp(source_item_holder_handed_modifier,target_item_holder_handed_modifier) | strcmp(source_item_holder_kind_modifier,target_item_holder_kind_modifier)); is_equal;}) : ({int is_equal; const char *source_item_holder_quality = quality_name_modifier[((struct Armor *)current_entry->item_holder->item->item_specific_info)->quality]; const char *source_item_holder_material = material_name_modifier[((struct Armor *)current_entry->item_holder->item->item_specific_info)->material]; const char *source_item_holder_armor_type = equipment_type_modifier[((struct Armor *)current_entry->item_holder->item->item_specific_info)->armor_type]; char *target_item_holder_quality = quality_name_modifier[((struct Armor *)item->item->item_specific_info)->quality]; const char *target_item_holder_material = material_name_modifier[((struct Armor *)item->item->item_specific_info)->material]; const char *target_item_holder_armor_type = equipment_type_modifier[((struct Armor *)item->item->item_specific_info)->armor_type]; is_equal = (strcmp(source_item_holder_quality,target_item_holder_quality) | strcmp(source_item_holder_material,target_item_holder_material) | strcmp(source_item_holder_armor_type,target_item_holder_armor_type) ); is_equal;}) : current_entry->item_holder->item->kind == item->item->kind && current_entry->item_holder->item->id == item->item->id ? 0 : 1) == 0){
       if(amount >= current_entry->item_holder->amount){
  table->item_count--;
      if(free_item_if_removed == 0){
 (*i_free_item_handler[current_entry->item_holder->current_entry->item_holder->kind])(current_entry->item_holder); free(current_entry->item_holder); current_entry->item_holder = 
# 147 "src/u_hash.c" 3 4
((void *)0)
# 147 "src/u_hash.c"
;;
 free(current_entry);
 current_entry = 
# 149 "src/u_hash.c" 3 4
                ((void *)0)
# 149 "src/u_hash.c"
                    ;
      }
      else{
      item_weight.item = current_entry->item_holder->item;
      item_weight.weight_loss = (current_entry->item_holder->amount * current_entry->item_holder->item->weight);
      item_weight.deleted = 1;

      current_entry->item_holder->amount = 0;
      //      printf("NULL 2 here");
      Entry *replacement = current_entry->next_entry;
      previous_entry->next_entry = replacement;
      return item_weight;
      }
    }
    else{
      current_entry->item_holder->amount -= amount;
      item_weight.item = current_entry->item_holder->item;
      item_weight.weight_loss = (amount * current_entry->item_holder->item->weight);
      item_weight.deleted = 0;
      return item_weight;
     }
    }
    else{
    while(current_entry != 
# 172 "src/u_hash.c" 3 4
                          ((void *)0)
# 172 "src/u_hash.c"
                              ){
      //printf("material of weapon: %d,",((Weapon *)current_entry->item_holder->item->item_specific_info)->material);
      //  printf("%s", " checking ");
      if(current_entry->item_holder->item->kind == item->item->kind && (current_entry->item_holder->item->kind != item->item->kind ? 1 : item->item->kind == weapon || item->item->kind == armor ? item->item->kind == weapon ? ({int is_equal = 0; const char *source_item_holder_quality = quality_name_modifier[((struct Weapon *)current_entry->item_holder->item->item_specific_info)->quality]; const char *source_item_holder_material = material_name_modifier[((struct Weapon *)current_entry->item_holder->item->item_specific_info)->material]; const char *source_item_holder_handed_modifier = handed_modifier[((struct Weapon *)current_entry->item_holder->item->item_specific_info)->variant]; const char *source_item_holder_kind_modifier = mele_weapon_name_modifier[((struct Weapon *)current_entry->item_holder->item->item_specific_info)->kind]; const char *target_item_holder_quality = quality_name_modifier[((struct Weapon *)item->item->item_specific_info)->quality]; const char *target_item_holder_material = material_name_modifier[((struct Weapon *)item->item->item_specific_info)->material]; const char *target_item_holder_handed_modifier = handed_modifier[((struct Weapon *)item->item->item_specific_info)->variant]; const char *target_item_holder_kind_modifier = mele_weapon_name_modifier[((struct Weapon *)item->item->item_specific_info)->kind]; is_equal = (strcmp(source_item_holder_quality,target_item_holder_quality) | strcmp(source_item_holder_material, target_item_holder_material) | strcmp(source_item_holder_handed_modifier,target_item_holder_handed_modifier) | strcmp(source_item_holder_kind_modifier,target_item_holder_kind_modifier)); is_equal;}) : ({int is_equal; const char *source_item_holder_quality = quality_name_modifier[((struct Armor *)current_entry->item_holder->item->item_specific_info)->quality]; const char *source_item_holder_material = material_name_modifier[((struct Armor *)current_entry->item_holder->item->item_specific_info)->material]; const char *source_item_holder_armor_type = equipment_type_modifier[((struct Armor *)current_entry->item_holder->item->item_specific_info)->armor_type]; char *target_item_holder_quality = quality_name_modifier[((struct Armor *)item->item->item_specific_info)->quality]; const char *target_item_holder_material = material_name_modifier[((struct Armor *)item->item->item_specific_info)->material]; const char *target_item_holder_armor_type = equipment_type_modifier[((struct Armor *)item->item->item_specific_info)->armor_type]; is_equal = (strcmp(source_item_holder_quality,target_item_holder_quality) | strcmp(source_item_holder_material,target_item_holder_material) | strcmp(source_item_holder_armor_type,target_item_holder_armor_type) ); is_equal;}) : current_entry->item_holder->item->kind == item->item->kind && current_entry->item_holder->item->id == item->item->id ? 0 : 1) == 0){
 //	printf("%s", " found item to remove ");
 if(amount >= current_entry->item_holder->amount){
   table->item_count--;
    if(free_item_if_removed == 0){
 i_free_item(current_entry->item_holder->item);
 free(current_entry->item_holder);
 current_entry->item_holder = 
# 182 "src/u_hash.c" 3 4
                             ((void *)0)
# 182 "src/u_hash.c"
                                 ;
 free(current_entry);
 current_entry = 
# 184 "src/u_hash.c" 3 4
                ((void *)0)
# 184 "src/u_hash.c"
                    ;
      }
      else{
      item_weight.item = current_entry->item_holder->item;
      item_weight.weight_loss = (current_entry->item_holder->amount * current_entry->item_holder->item->weight);
      item_weight.deleted = 1;
      current_entry->item_holder->amount = 0;
      Entry *replacement = current_entry->next_entry;
      previous_entry->next_entry = replacement;
      return item_weight;
      }
 }
      else{
 //printf("fell though here 2");
 table->entries[index]->item_holder->amount -= amount;
 item_weight.item = table->entries[index]->item_holder->item;
 item_weight.weight_loss = (amount * current_entry->item_holder->item->weight);
 item_weight.deleted = 0;
 return item_weight;
       }
      }
      previous_entry = current_entry;
      current_entry = current_entry->next_entry;
      }
    }

  }
  //printf("fell though here 3");
    // A safety guard more than anything else, if all else fails, we found no item and we stand to lose no weight 
  item_weight.weight_loss = 0;
  item_weight.item = 
# 214 "src/u_hash.c" 3 4
                    ((void *)0)
# 214 "src/u_hash.c"
                        ;
  return item_weight;

}





/*
char *faku(){
  char *val = malloc(sizeof(char));
  return val;
}
*/



char *faku(){
  char *val = "abc";
  return val;
}
