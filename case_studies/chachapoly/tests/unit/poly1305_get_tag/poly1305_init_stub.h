#ifndef POLY1305_INIT_STUB_H
#define POLY1305_INIT_STUB_H

#include "poly1305.h"

void set_ctx(uint32_t set_r[5], uint32_t set_pad[4]);
void poly1305_init(struct poly1305_context *ctx, const unsigned char key[32]);
#endif