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

#ifndef __MACHINE_ENDIAN_H__
#define	__MACHINE_ENDIAN_H__

#include <sys/cdefs.h>
#include <sys/_types.h>
#include <machine/_endian.h>

#if _BYTE_ORDER == _LITTLE_ENDIAN
#define	_QUAD_HIGHWORD	1
#define	_QUAD_LOWWORD	0
#else
#define	_QUAD_HIGHWORD	0
#define	_QUAD_LOWWORD	1
#endif

#if __BSD_VISIBLE
#define	LITTLE_ENDIAN	_LITTLE_ENDIAN
#define	BIG_ENDIAN	_BIG_ENDIAN
#define	PDP_ENDIAN	_PDP_ENDIAN
#define	BYTE_ORDER	_BYTE_ORDER
#endif

/* The `__builtin_bswap16()` function that GCC emits does not use the `swap.b`
 * instruction. */
#undef __bswap16
__inline static __uint16_t __bswap16(__uint16_t _x)
{
    __uint32_t out;

    __asm__ volatile ("swap.b %[in], %[out]\n"
                      : [out] "=&r" (out)
                      : [in] "r" (_x));

    return out;
}

/* The `__builtin_bswap32()` function that GCC emits does not use the `swap.w`
 * instruction. */
#undef __bswap32
__inline static __uint32_t __bswap32(__uint32_t _x)
{
    __uint32_t out;
    __uint32_t t0 = 0;
    __uint32_t t1 = 0;

    __asm__ volatile ("swap.b %[in], %[ot0]\n"
                      "swap.w %[it0], %[ot1]\n"
                      "swap.b %[it1], %[out]\n"
                      : [out] "=&r" (out),
                        [ot0] "=r" (t0),
                        [ot1] "=r" (t1)
                      : [in]  "0" "r" (_x),
                        [it0] "1" (t0),
                        [it1] "2" (t1));

    return out;
}

#undef __bswap64
__inline static __uint64_t __bswap64(__uint64_t _x)
{
    const __uint32_t out0 = __bswap32((__uint32_t)_x);
    const __uint32_t out1 = __bswap32((__uint32_t)(_x >> 32U));

    return ((__uint64_t)out1 << 32U) | out0;
}

/* endian(3) - similar to linux <endian.h> */
#if _BYTE_ORDER == _LITTLE_ENDIAN
#define htobe16(_x) __bswap16(_x)
#define htole16(_x) ((__uint16_t)(_x))
#define be16toh(_x) __bswap16(_x)
#define le16toh(_x) ((__uint16_t)(_x))
#define htobe32(_x) __bswap32(_x)
#define htole32(_x) ((__uint32_t)(_x))
#define be32toh(_x) __bswap32(_x)
#define le32toh(_x) ((__uint32_t)(_x))
#define htobe64(_x) __bswap64(_x)
#define htole64(_x) ((__uint64_t)(_x))
#define be64toh(_x) __bswap64(_x)
#define le64toh(_x) ((__uint64_t)(_x))
#else
#define htobe16(_x) ((__uint16_t)(_x))
#define htole16(_x) __bswap16(_x)
#define be16toh(_x) ((__uint16_t)(_x))
#define le16toh(_x) __bswap16(_x)
#define htobe32(_x) ((__uint32_t)(_x))
#define htole32(_x) __bswap32(_x)
#define be32toh(_x) ((__uint32_t)(_x))
#define le32toh(_x) __bswap32(_x)
#define htobe64(_x) ((__uint64_t)(_x))
#define htole64(_x) __bswap64(_x)
#define be64toh(_x) ((__uint64_t)(_x))
#define le64toh(_x) __bswap64(_x)
#endif

#endif /* __MACHINE_ENDIAN_H__ */
