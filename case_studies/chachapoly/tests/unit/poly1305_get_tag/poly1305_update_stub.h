#ifndef POLY1305_UPDATE_STUB_H
#define POLY1305_UPDATE_STUB_H

#include "poly1305.h"

void update_block(size_t leftover,size_t m,size_t bytes, unsigned char expected_buffer[POLY1305_BLOCK_SIZE]);
void poly1305_update(struct poly1305_context *ctx, const unsigned char *m, size_t bytes);

#endif
