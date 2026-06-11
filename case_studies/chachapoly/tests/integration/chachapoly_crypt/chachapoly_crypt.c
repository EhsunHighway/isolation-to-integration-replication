#include "chachapoly_crypt.h"
#include <stdio.h>

int chachapoly_crypt(struct chachapoly_ctx *ctx, const void *nonce,
                     const void *ad, int ad_len, void *input, int input_len,
                     void *output, void *tag, int tag_len, int encrypt)
{
    unsigned char poly_key[CHACHA_BLOCKLEN];
    unsigned char calc_tag[POLY1305_TAGLEN];
    const unsigned char one[4] = { 1, 0, 0, 0 };

    /* initialize keystream and generate poly1305 key */
    memset(poly_key, 0, sizeof(poly_key));
    chacha_ivsetup(&ctx->cha_ctx, nonce, NULL);
    chacha_encrypt_bytes(&ctx->cha_ctx, poly_key, poly_key, sizeof(poly_key));

    /* check tag if decrypting */
    if (encrypt == 0 && tag_len) {
        poly1305_get_tag(poly_key, ad, ad_len, input, input_len, calc_tag);
        if (memcmp_eq(calc_tag, tag, tag_len) != 0) {
            return CHACHAPOLY_INVALID_MAC;
        }
    }

    /* crypt data */
    chacha_ivsetup(&ctx->cha_ctx, nonce, one);
    chacha_encrypt_bytes(&ctx->cha_ctx, (unsigned char *)input,
                         (unsigned char *)output, input_len);

    /* add tag if encrypting */
    if (encrypt && tag_len) {
        poly1305_get_tag(poly_key, ad, ad_len, output, input_len, calc_tag);
        memcpy(tag, calc_tag, tag_len);
    }

    return CHACHAPOLY_OK;
}
