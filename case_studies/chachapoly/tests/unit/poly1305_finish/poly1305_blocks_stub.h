#ifndef POLY1305_BLOCKS_STUB_H
#define POLY1305_BLOCKS_STUB_H

#include "poly1305.h"

void set_the_block(uint32_t h0, uint32_t h1, uint32_t h2, uint32_t h3, uint32_t h4);
void poly1305_blocks(struct poly1305_context *st, const unsigned char *m, size_t bytes);

#endif
