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

#include <machine/insn.h>

#include <stdlib.h>

#define DIVU_IOREGS_BASE (0xFFFFFF00UL)

struct divu_ioregs {
    __uint32_t dvsr;
    __uint32_t dvdnt;
    __uint32_t dvcr;
    __uint32_t vcrdiv;
    __uint32_t dvdnth;
    __uint32_t dvdntl;
};

div_t div(int num, int denom)
{
    volatile struct divu_ioregs * const ioregs =
        (volatile struct divu_ioregs *)DIVU_IOREGS_BASE;

    const __uint32_t dswap = swapw((__uint32_t)num);
    const __uint32_t dh = extsw(dswap);
    const __uint32_t dl = (__uint32_t)num << 16U;

    ioregs->dvsr   = denom;
    ioregs->dvdnth = dh;
    /* Writing to CPU(DVDNTL) starts the operation */
    ioregs->dvdntl = dl;

    const div_t r = {
        .quot = ioregs->dvdntl,
        .rem  = ioregs->dvdnth,
    };

    return r;
}
