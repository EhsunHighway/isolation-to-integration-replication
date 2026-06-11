#include "poly1305_init_stub.h"

uint32_t return_r0, return_r1, return_r2, return_r3, return_r4;
uint32_t return_pad0, return_pad1, return_pad2, return_pad3;


void set_ctx(uint32_t set_r[5], uint32_t set_pad[4]){
    return_r0 = set_r[0];
    return_r1 = set_r[1];
    return_r2 = set_r[2];
    return_r3 = set_r[3];
    return_r4 = set_r[4];

    return_pad0 = set_pad[0];
    return_pad1 = set_pad[1];
    return_pad2 = set_pad[2];
    return_pad3 = set_pad[3];
}

void poly1305_init(struct poly1305_context *ctx, const unsigned char key[32]) {
    ctx->r[0] = return_r0;
    ctx->r[1] = return_r1;
    ctx->r[2] = return_r2;
    ctx->r[3] = return_r3;
    ctx->r[4] = return_r4;

    ctx->h[0] = 0;
    ctx->h[1] = 0;
    ctx->h[2] = 0;
    ctx->h[3] = 0;
    ctx->h[4] = 0;

    ctx->pad[0] = return_pad0;
    ctx->pad[1] = return_pad1;
    ctx->pad[2] = return_pad2;
    ctx->pad[3] = return_pad3;

    ctx->leftover = 0;
    ctx->final = 0;
}
