#include "U8TO32.h"

uint32_t U8TO32(const unsigned char *p)
{
    return
            (((uint32_t)(p[0] & 0xff)      ) |
             ((uint32_t)(p[1] & 0xff) <<  8) |
             ((uint32_t)(p[2] & 0xff) << 16) |
             ((uint32_t)(p[3] & 0xff) << 24));
}
