#ifndef CHACHAPOLY_CRYPT_H
#define CHACHAPOLY_CRYPT_H

#include "chachapoly.h"
#include "poly1305_get_tag_stub.h"
#include "memcmp_eq_stub.h"
#include "chacha_ivsetup_stub.h"
#include "chacha_encrypt_bytes_stub.h"

int chachapoly_crypt(struct chachapoly_ctx *ctx, const void *nonce,
                     const void *ad, int ad_len, void *input, int input_len,
                     void *output, void *tag, int tag_len, int encrypt);

#endif //CHACHAPOLY_CRYPT_H
