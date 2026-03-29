/*-
 * CC BY-SA 3.0 <https://en.wikipedia.org/wiki/Xorshift>
 */

#include <stdint.h>

int rand_r(unsigned int *seed)
{
    /* Algorithm "xor" from p. 4 of Marsaglia, "Xorshift RNGs" */
    __uint32_t x = (__uint32_t)*seed;

    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;

    *seed = x;

    return x;
}
