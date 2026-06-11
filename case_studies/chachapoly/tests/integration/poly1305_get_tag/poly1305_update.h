#ifndef POLY1305_UPDATE_H
#define POLY1305_UPDATE_H

#include "poly1305.h"
#include "poly1305_blocks.h"

void poly1305_update(struct poly1305_context *ctx, const unsigned char *m, size_t bytes);

#endif
