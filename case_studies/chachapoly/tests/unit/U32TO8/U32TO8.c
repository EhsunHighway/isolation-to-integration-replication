#include "U32TO8.h"

void U32TO8(unsigned char *p, uint32_t v)
{
    p[0] = (v      ) & 0xff;
    p[1] = (v >>  8) & 0xff;
    p[2] = (v >> 16) & 0xff;
    p[3] = (v >> 24) & 0xff;
}