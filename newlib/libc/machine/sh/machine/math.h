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

#ifndef	_MACHMATH_H_
#define	_MACHMATH_H_

#include <sys/cdefs.h>
#include <sys/_types.h>

/* Shamelessly stolen from:
 *   https://stackoverflow.com/a/73484677/604033 */
#if !defined(__cplusplus)
#ifndef min
#define __DEFINE_MIN(name, T)                                                  \
    static inline T name(T a, T b) { return (a < b) ? a : b; }

// clang-format off
__DEFINE_MIN(min_bool, _Bool)
__DEFINE_MIN(min_char, char)
__DEFINE_MIN(min_schar, signed char)
__DEFINE_MIN(min_uchar, unsigned char)
__DEFINE_MIN(min_short, short)
__DEFINE_MIN(min_ushort, unsigned short)
__DEFINE_MIN(min_int, int)
__DEFINE_MIN(min_uint, unsigned)
__DEFINE_MIN(min_long, long)
__DEFINE_MIN(min_ulong, unsigned long)
__DEFINE_MIN(min_llong, long long)
__DEFINE_MIN(min_ullong, unsigned long long)
// clang-format on

#undef __DEFINE_MIN

#define min(a, b)                                                              \
    __generic(((a) < (b)) ? (a) : (b),                                         \
             _Bool: min_bool,                                                  \
              char: min_char,                                                  \
       signed char: min_schar,                                                 \
     unsigned char: min_uchar,                                                 \
             short: min_short,                                                 \
    unsigned short: min_ushort,                                                \
               int: min_int,                                                   \
          unsigned: min_uint,                                                  \
              long: min_long,                                                  \
     unsigned long: min_ulong,                                                 \
         long long: min_llong,                                                 \
unsigned long long: min_ullong,                                                \
         default: "bad type for min")(a, b)
#endif /* !min */

#ifndef max
#define __DEFINE_MAX(name, T)                                                  \
    static inline T name(T a, T b) { return (a > b) ? a : b; }

// clang-format off
__DEFINE_MAX(max_bool, _Bool)
__DEFINE_MAX(max_char, char)
__DEFINE_MAX(max_schar, signed char)
__DEFINE_MAX(max_uchar, unsigned char)
__DEFINE_MAX(max_short, short)
__DEFINE_MAX(max_ushort, unsigned short)
__DEFINE_MAX(max_int, int)
__DEFINE_MAX(max_uint, unsigned)
__DEFINE_MAX(max_long, long)
__DEFINE_MAX(max_ulong, unsigned long)
__DEFINE_MAX(max_llong, long long)
__DEFINE_MAX(max_ullong, unsigned long long)
// clang-format on

#undef __DEFINE_MAX

#define max(a, b)                                                              \
    __generic(((a) > (b)) ? (a) : (b),                                         \
             _Bool: max_bool,                                                  \
              char: max_char,                                                  \
       signed char: max_schar,                                                 \
     unsigned char: max_uchar,                                                 \
             short: max_short,                                                 \
    unsigned short: max_ushort,                                                \
               int: max_int,                                                   \
          unsigned: max_uint,                                                  \
              long: max_long,                                                  \
     unsigned long: max_ulong,                                                 \
         long long: max_llong,                                                 \
unsigned long long: max_ullong,                                                \
         default: "bad type for max")(a, b)
#endif /* !max */

#ifndef sign
#define __DEFINE_SIGN(name, T)                                                 \
    static inline T name(T x) { return (x < 0) ? -1 : 1; }

// clang-format off
__DEFINE_SIGN(sign_char, char)
__DEFINE_SIGN(sign_schar, signed char)
__DEFINE_SIGN(sign_short, short)
__DEFINE_SIGN(sign_int, int)
__DEFINE_SIGN(sign_long, long)
__DEFINE_SIGN(sign_llong, long long)
// clang-format on

#undef __DEFINE_SIGN
#define sign(x)                                                                \
    __generic(((x) < 0) ? -1 : 1,                                              \
              char: sign_char,                                                 \
       signed char: sign_schar,                                                \
             short: sign_short,                                                \
               int: sign_int,                                                  \
              long: sign_long,                                                 \
         long long: sign_llong,                                                \
         default: "bad type for sign")(x)
#endif /* !sign */

#ifndef clamp
#define clamp(x, y, z)                                                         \
    __extension__ ({                                                           \
       __typeof__ (x) _x = (x);                                                \
       __typeof__ (y) _y = (y);                                                \
       __typeof__ (z) _z = (z);                                                \
       (_x <= _y) ? _y : ((_x >= _z) ? _z : _x);                               \
    })
#endif /* !clamp */

#ifndef abs
#define __DEFINE_ABS(name, T)                                                  \
    static inline T name(T a) { return (a < 0) ? -a : 0; }

// clang-format off
__DEFINE_ABS(abs_char, char)
__DEFINE_ABS(abs_schar, signed char)
__DEFINE_ABS(abs_short, short)
__DEFINE_ABS(abs_int, int)
__DEFINE_ABS(abs_long, long)
__DEFINE_ABS(abs_llong, long long)
// clang-format on

#undef __DEFINE_ABS

#define abs(a)                                                                 \
    __generic(((a) < 0) ? -(a) : (a),                                          \
              char: abs_char,                                                  \
       signed char: abs_schar,                                                 \
             short: abs_short,                                                 \
               int: abs_int,                                                   \
              long: abs_long,                                                  \
         long long: abs_llong,                                                 \
         default: "bad type for abs")(a)
#endif /* !abs */
#endif /* !__cplusplus */

__always_inline static __int32_t mul(__int32_t a, __int32_t b)
{
    __uint32_t mach;
    __int32_t out;

    __asm__ volatile ("\tdmuls.l %[a], %[b]\n"
                      "\tsts mach, %[mach]\n"
                      "\tsts macl, %[out]\n"
                      "\txtrct %[mach], %[out]\n"
                      /* Output */
                      : [mach] "=&r" (mach),
                        [out] "=&r" (out)
                      /* Input */
                      : [a] "r" (a),
                        [b] "r" (b)
                      : "mach", "macl");

    return out;
}

__always_inline static __int32_t mul_low(__int32_t a, __int32_t b)
{
    __int32_t out;

    __asm__ volatile ("\tdmuls.l %[a], %[b]\n"
                      "\tsts macl, %[out]\n"
                      /* Output */
                      : [out] "=&r" (out)
                      /* Input */
                      : [a] "r" (a),
                        [b] "r" (b)
                      : "macl");

    return out;
}

__always_inline static __int32_t mul_high(__int32_t a, __int32_t b)
{
    __int16_t out;

    // clang-format off
    __asm__ volatile ("\tdmuls.l %[a], %[b]\n"
                      "\tsts mach, %[out]\n"
                      /* Output */
                      : [out] "=&r" (out)
                      /* Input */
                      : [a] "r" (a),
                        [b] "r" (b)
                      : "mach");
    // clang-format on

    return out;
}

#endif	/* _MACHMATH_H_ */
