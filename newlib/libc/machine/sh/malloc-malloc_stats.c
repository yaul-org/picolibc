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

#include "tlsf-malloc.h"

struct mem_stats {
  size_t total_used;
  size_t total_free;
};

static void _tlsf_walker(void *ptr, size_t size, int used, void *user);

void malloc_stats(void)
{
    assert(__tlsf != NULL);

    pool_t const pool = tlsf_get_pool(__tlsf);

    struct mem_stats mem_stats = {
        .total_used = 0,
        .total_free = 0,
    };

    tlsf_walk_pool(pool, _tlsf_walker, &mem_stats);

    const size_t local_max_total_mem = mem_stats.total_used + mem_stats.total_free;

    fprintf(stderr, "max system bytes = %10zu\n"
                    "system bytes     = %10zu\n"
                    "in use bytes     = %10zu\n",
            local_max_total_mem,
            mem_stats.total_free,
            mem_stats.total_used);
}

static void _tlsf_walker(void *ptr, size_t size, int used, void *user)
{
    struct mem_stats * const mem_stats = user;

    if (used) {
        mem_stats->total_used += size;
    } else {
        mem_stats->total_free += size;
    }
}
