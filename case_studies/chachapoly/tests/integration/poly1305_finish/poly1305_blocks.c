#include "poly1305_blocks.h"


void
poly1305_blocks(struct poly1305_context *st, const unsigned char *m, size_t bytes)
{
    const uint32_t hibit = (st->final) ? 0 : (1 << 24); /* 1 << 128 */
    uint32_t r0,r1,r2,r3,r4;
    uint32_t s1,s2,s3,s4;
    uint32_t h0,h1,h2,h3,h4;
    uint64_t d0,d1,d2,d3,d4;
    uint32_t c;

    r0 = st->r[0];
    r1 = st->r[1];
    r2 = st->r[2];
    r3 = st->r[3];
    r4 = st->r[4];

    s1 = r1 * 5;
    s2 = r2 * 5;
    s3 = r3 * 5;
    s4 = r4 * 5;

    h0 = st->h[0];
    h1 = st->h[1];
    h2 = st->h[2];
    h3 = st->h[3];
    h4 = st->h[4];

    while (bytes >= POLY1305_BLOCK_SIZE) {
        /* h += m[i] */
        h0 += (U8TO32(m+ 0)     ) & 0x3ffffff;
        h1 += (U8TO32(m+ 3) >> 2) & 0x3ffffff;
        h2 += (U8TO32(m+ 6) >> 4) & 0x3ffffff;
        h3 += (U8TO32(m+ 9) >> 6) & 0x3ffffff;
        h4 += (U8TO32(m+12) >> 8) | hibit;


        /* h *= r */
        d0 = ((uint64_t)h0 * r0) + ((uint64_t)h1 * s4) + ((uint64_t)h2 * s3) + ((uint64_t)h3 * s2) + ((uint64_t)h4 * s1);
        d1 = ((uint64_t)h0 * r1) + ((uint64_t)h1 * r0) + ((uint64_t)h2 * s4) + ((uint64_t)h3 * s3) + ((uint64_t)h4 * s2);
        d2 = ((uint64_t)h0 * r2) + ((uint64_t)h1 * r1) + ((uint64_t)h2 * r0) + ((uint64_t)h3 * s4) + ((uint64_t)h4 * s3);
        d3 = ((uint64_t)h0 * r3) + ((uint64_t)h1 * r2) + ((uint64_t)h2 * r1) + ((uint64_t)h3 * r0) + ((uint64_t)h4 * s4);
        d4 = ((uint64_t)h0 * r4) + ((uint64_t)h1 * r3) + ((uint64_t)h2 * r2) + ((uint64_t)h3 * r1) + ((uint64_t)h4 * r0);

        /* (partial) h %= p */
        c = (uint32_t)(d0 >> 26); h0 = (uint32_t)d0 & 0x3ffffff;
        d1 += c;      c = (uint32_t)(d1 >> 26); h1 = (uint32_t)d1 & 0x3ffffff;
        d2 += c;      c = (uint32_t)(d2 >> 26); h2 = (uint32_t)d2 & 0x3ffffff;
        d3 += c;      c = (uint32_t)(d3 >> 26); h3 = (uint32_t)d3 & 0x3ffffff;
        d4 += c;      c = (uint32_t)(d4 >> 26); h4 = (uint32_t)d4 & 0x3ffffff;
        h0 += c * 5;  c =           (h0 >> 26); h0 =           h0 & 0x3ffffff;
        h1 += c;

        m += POLY1305_BLOCK_SIZE;
        bytes -= POLY1305_BLOCK_SIZE;
    }

    st->h[0] = h0;
    st->h[1] = h1;
    st->h[2] = h2;
    st->h[3] = h3;
    st->h[4] = h4;
}