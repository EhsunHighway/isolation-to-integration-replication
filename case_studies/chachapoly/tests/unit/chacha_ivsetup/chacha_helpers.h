#ifndef CHACHA_HELPERS_H
#define CHACHA_HELPERS_H

#include <stdint.h>

#if (USE_UNALIGNED == 1)
#define U8TO32_LITTLE(p) (*((uint32_t *)(p)))
#define U32TO8_LITTLE(p, v) (*((uint32_t *)(p)) = (v))
#else
#define U8TO32_LITTLE(p) \
    (((uint32_t)((p)[0])) | ((uint32_t)((p)[1]) << 8) | \
     ((uint32_t)((p)[2]) << 16) | ((uint32_t)((p)[3]) << 24))
#define U32TO8_LITTLE(p, v) \
    do { \
        (p)[0] = U8V((v)); \
        (p)[1] = U8V((v) >> 8); \
        (p)[2] = U8V((v) >> 16); \
        (p)[3] = U8V((v) >> 24); \
    } while (0)
#endif

#endif // CHACHA_HELPERS_H
