#include "poly1305_init.h"

void poly1305_init(struct poly1305_context *ctx, const unsigned char key[32]) {
    // Initialize the context based on the key
    ctx->r[0] = (U8TO32(&key[0])) & 0x3ffffff;
    ctx->r[1] = (U8TO32(&key[3]) >> 2) & 0x3ffff03;
    ctx->r[2] = (U8TO32(&key[6]) >> 4) & 0x3ffc0ff;
    ctx->r[3] = (U8TO32(&key[9]) >> 6) & 0x3f03fff;
    ctx->r[4] = (U8TO32(&key[12]) >> 8) & 0x00fffff;

    ctx->h[0] = 0;
    ctx->h[1] = 0;
    ctx->h[2] = 0;
    ctx->h[3] = 0;
    ctx->h[4] = 0;

    ctx->pad[0] = U8TO32(&key[16]);
    ctx->pad[1] = U8TO32(&key[20]);
    ctx->pad[2] = U8TO32(&key[24]);
    ctx->pad[3] = U8TO32(&key[28]);

    ctx->leftover = 0;
    ctx->final = 0;
}
