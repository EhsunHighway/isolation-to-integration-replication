#ifndef POLY1305_INIT_H
#define POLY1305_INIT_H

#include "poly1305.h"
#include "U8TO32.h"

void poly1305_init(struct poly1305_context *ctx, const unsigned char key[32]);

#endif