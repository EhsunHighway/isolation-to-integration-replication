#ifndef CHACHAPOLY_INIT_H
#define CHACHAPOLY_INIT_H

#include "chachapoly.h"
#include <assert.h>  // Include assert.h when assertions are enabled
#include "chacha_keysetup.h"

int chachapoly_init(struct chachapoly_ctx *ctx, const void *key, int key_len);


#endif //CHACHAPOLY_INIT_H
