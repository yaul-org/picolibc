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

#include <assert.h>
#include <stdio.h>
#include <stdint.h>

#include "tlsf-malloc.h"

extern char __heap_start[];
extern char __heap_end[];

tlsf_t __tlsf;

__weak_symbol size_t malloc_getpagesize = 128;

__constructor_with_priority(0) static void _malloc_init(void)
{
    if (__tlsf == NULL) {
        __tlsf = tlsf_create_with_pool(__heap_start, __heap_end - __heap_start);
    }
}

__destructor_with_priority(0) static void _malloc_deinit(void)
{
    if (__tlsf != NULL) {
        tlsf_destroy(__tlsf);
    }
}

void *malloc(size_t __size)
{
    assert(__tlsf != NULL);

    return tlsf_malloc(__tlsf, __size);
}
