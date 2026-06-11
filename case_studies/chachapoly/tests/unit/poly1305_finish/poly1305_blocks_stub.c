#include "poly1305_blocks_stub.h"

uint32_t return_h0, return_h1, return_h2, return_h3, return_h4;

void set_the_block(uint32_t h0, uint32_t h1, uint32_t h2, uint32_t h3, uint32_t h4) {
    return_h0 = h0;
    return_h1 = h1;
    return_h2 = h2;
    return_h3 = h3;
    return_h4 = h4;
}

void poly1305_blocks(struct poly1305_context *st, const unsigned char *m, size_t bytes) {
    st->h[0] = return_h0;
    st->h[1] = return_h1;
    st->h[2] = return_h2;
    st->h[3] = return_h3;
    st->h[4] = return_h4;
}
