/*-
 * Copyright (c) 2012-2026 Israel Jacquez <mrkotfw@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef _SYS_CDEFS_H_
#define _SYS_CDEFS_H_

#include <sys/_cdefs.h>
#include <machine/_cdefs.h>

/* Introduced in C99, the identifier __func__ is implicitly declared by the
 * translator as if, immediately following the opening brace of each function
 * definition, the declaration:
 *
 *   static const char __func__[] = "function-name";
 *
 * appeared, where function-name is the name of the lexically-enclosing
 * function. This name is the unadorned name of the function. As an extension,
 * at file (or, in C++, namespace scope), __func__ evaluates to the empty
 * string. */
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ < 199901)
#undef __func__
#define __func__ ((const char *)0)
#endif /* !__func__ */

#ifndef __function_name
#if defined(__cplusplus) && defined(__GNUC__)
/* Use g++'s demangled names in C++ */
#define __function_name __PRETTY_FUNCTION__
#else
#define __function_name __func__
#endif
#endif /* !__function_name */

/* Prior to C++17 the register storage class specifier was deprecated; in C++17
 * it has been removed. */
#if (__cplusplus - 0) >= 201703L
#ifndef __register
#define __register
#endif /* !__register */
#else
#ifndef __register
#define __register register
#endif /* !__register */
#endif

#ifndef __noreturn
#define __noreturn _Noreturn
#endif /* !__noreturn */

#ifndef __no_reorder
#define __no_reorder __attribute__ ((no_reorder))
#endif /* !__no_reorder */

#ifndef __constructor
#define __constructor __attribute__ ((constructor))
#endif /* !__constructor */

#ifndef __constructor_with_priority
#define __constructor_with_priority(p) __attribute__ ((constructor(p)))
#endif /* !__constructor_with_priority */

#ifndef __destructor
#define __destructor __attribute__ ((destructor))
#endif /* !__destructor */

#ifndef __destructor_with_priority
#define __destructor_with_priority(p) __attribute__ ((destructor(p)))
#endif /* !__destructor_with_priority */

#endif /* _SYS_CDEFS_H_ */
