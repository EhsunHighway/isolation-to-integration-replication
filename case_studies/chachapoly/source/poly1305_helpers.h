#ifndef POLY1305_HELPERS_H
#define POLY1305_HELPERS_H

#include <stdint.h>

#if (USE_UNALIGNED == 1)
#define U8TO32(p) \
    (*((uint32_t *)(p)))
#define U32TO8(p, v) \
    do { \
      *((uint32_t *)(p)) = v; \
    } while (0)
#else
/* interpret four 8 bit unsigned integers as a 32 bit unsigned integer in little endian */
static uint32_t
U8TO32(const unsigned char *p)
{
    return
            (((uint32_t)(p[0] & 0xff)      ) |
             ((uint32_t)(p[1] & 0xff) <<  8) |
             ((uint32_t)(p[2] & 0xff) << 16) |
             ((uint32_t)(p[3] & 0xff) << 24));
}

/* store a 32 bit unsigned integer as four 8 bit unsigned integers in little endian */
static void
U32TO8(unsigned char *p, uint32_t v)
{
    p[0] = (v      ) & 0xff;
    p[1] = (v >>  8) & 0xff;
    p[2] = (v >> 16) & 0xff;
    p[3] = (v >> 24) & 0xff;
}

#endif

#endif // CHACHA_HELPERS_H
