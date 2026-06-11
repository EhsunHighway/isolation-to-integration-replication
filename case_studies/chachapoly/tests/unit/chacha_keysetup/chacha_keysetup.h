#ifndef CHACHA_KEYSETUP_H
#define CHACHA_KEYSETUP_H

#include "chacha.h"
#include "chacha_helpers.h"
#include "chacha_constants.h"

void
chacha_keysetup(struct chacha_ctx *x,const unsigned char *k,uint32_t kbits);

#endif