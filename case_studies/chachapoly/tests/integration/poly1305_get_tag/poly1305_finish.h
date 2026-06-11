#ifndef POLY1305_FINISH_H
#define POLY1305_FINISH_H

#include "poly1305.h"
#include "U32TO8.h"
#include "poly1305_blocks.h"

void poly1305_finish(struct poly1305_context *ctx, unsigned char mac[16]);

#endif