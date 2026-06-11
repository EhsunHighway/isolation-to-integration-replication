#ifndef CHACHA_IVSETUP_H
#define CHACHA_IVSETUP_H

#include "chacha.h"
#include "chacha_helpers.h"

void
chacha_ivsetup(struct chacha_ctx *x, const unsigned char *iv, const unsigned char *counter);

#endif