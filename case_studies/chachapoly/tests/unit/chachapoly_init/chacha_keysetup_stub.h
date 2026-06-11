#ifndef CHACHA_KEYSETUP_STUB_H
#define CHACHA_KEYSETUP_STUB_H

#include "chacha.h"

void set_key_inputs(uint32_t inputs[12]);
void
chacha_keysetup(struct chacha_ctx *x,const unsigned char *k,uint32_t kbits);

#endif
