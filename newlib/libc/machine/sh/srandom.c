/*-
 * CC BY-SA 3.0 <https://en.wikipedia.org/wiki/Xorshift>
 */

#include <stdint.h>

extern __uint32_t _rand_next;

void srandom(unsigned int seed)
{
    _rand_next = seed;
}
