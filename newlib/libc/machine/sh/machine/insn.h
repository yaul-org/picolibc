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

#ifndef __MACHINE_INSN_H__
#define	__MACHINE_INSN_H__

#include <sys/cdefs.h>
#include <sys/_types.h>

__always_inline static __uint32_t swapw(__uint32_t _x)
{
    __uint32_t out;

    __asm__ volatile ("swap.w %[in], %[out]\n"
        : [out] "=&r" (out)
        : [in] "r" (_x));

    return out;
}

__always_inline static void clrmac(void)
{
    __asm__ volatile ("clrmac"
                      : /* No outputs */
                      : /* No inputs */
                      : "mach", "macl");
}

__always_inline static void macw(void *a, void *b)
{
    __uint16_t **ap = (__uint16_t **)a;
    __uint16_t **bp = (__uint16_t **)b;

    __asm__ volatile ("mac.w @%[a]+, @%[b]+"
                      : [a] "+&r" (*ap),
                        [b] "+&r" (*bp)
                      : /* No inputs */
                      : "mach", "macl", "memory");
}

__always_inline static void macl(void *a, void *b)
{
    __uint32_t **ap = (__uint32_t **)a;
    __uint32_t **bp = (__uint32_t **)b;

    __asm__ volatile ("mac.l @%[a]+, @%[b]+"
                      : [a] "+&r" (*ap),
                        [b] "+&r" (*bp)
                      : /* No inputs */
                      : "mach", "macl", "memory");
}

__always_inline static __uint32_t sts_mach(void)
{
    __uint32_t out;

    __asm__ volatile ("sts mach, %[out]"
                      : [out] "=r" (out)
                      : /* No inputs */
                      : "0");

    return out;
}

__always_inline static __uint32_t sts_macl(void)
{
    __uint32_t out;

    __asm__ volatile ("sts macl, %[out]"
                      : [out] "=r"(out)
                      : /* No inputs */
                      : "0");

    return out;
}

__always_inline static __uint32_t extsw(const __uint32_t rm)
{
    __uint32_t rn;

    __asm__ volatile ("exts.w %[rm], %[rn]"
                      : [rn] "=&r" (rn)
                      : [rm] "r" (rm));

    return rn;
}

__always_inline static __uint32_t neg(__uint32_t rm)
{
    __uint32_t rn;

    __asm__ volatile ("neg %[rm], %[rn]"
                      : [rn] "=&r" (rn)
                      : [rm] "r" (rm));

    return rn;
}

__always_inline static __uint32_t rotl(__uint32_t rn)
{
    __asm__ volatile ("rotl %[rn]"
                      : [rn] "=&r" (rn)
                      : "0" (rn));

    return rn;
}

__always_inline static __uint32_t rotr(__uint32_t rn)
{
    __asm__ volatile ("rotr %[rn]"
                      : [rn] "=&r" (rn)
                      : "0" (rn));

    return rn;
}

__always_inline static __uint32_t xtrct(__uint32_t rm, __uint32_t rn)
{
    __asm__ volatile ("xtrct %[rm], %[rn]"
                      : [rn] "=&r" (rn)
                      : "0" (rn),
                        [rm] "r" (rm));

    return rn;
}

__always_inline static void nop(void)
{
    __asm__ volatile ("nop"
                      : /* No outputs */
                      : /* No inputs */);
}

#endif /* __MACHINE_INSN_H__ */
