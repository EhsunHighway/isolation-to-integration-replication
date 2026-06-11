#include "chachapoly_init.h"

int chachapoly_init(struct chachapoly_ctx *ctx, const void *key, int key_len)
{
    if (key_len != 128 && key_len != 256) {
        return -1;
    }

    memset(ctx, 0, sizeof(*ctx));
    chacha_keysetup(&ctx->cha_ctx, key, key_len);
    return CHACHAPOLY_OK;
}