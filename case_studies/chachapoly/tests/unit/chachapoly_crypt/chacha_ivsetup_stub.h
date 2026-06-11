#ifndef CHACHA_IVSETUP_STUB_H
#define CHACHA_IVSETUP_STUB_H

#include "chacha.h"
#include "chacha_helpers.h"

void set_iv_inputs(uint32_t inputs[4]);
void
chacha_ivsetup(struct chacha_ctx *x, const unsigned char *iv, const unsigned char *counter);


#endif