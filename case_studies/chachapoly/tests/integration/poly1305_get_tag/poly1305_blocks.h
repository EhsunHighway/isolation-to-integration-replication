#ifndef POLY1305_BLOCKS_H
#define POLY1305_BLOCKS_H

#include "poly1305.h"
#include "U8TO32.h"

void poly1305_blocks(struct poly1305_context *st, const unsigned char *m, size_t bytes);

#endif
