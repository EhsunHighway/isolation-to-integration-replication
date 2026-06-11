#ifndef CHACHA_ENCRYPT_BYTES_H
#define CHACHA_ENCRYPT_BYTES_H

#include "chacha.h"
#include "chacha_quarterround.h"

void chacha_encrypt_bytes(struct chacha_ctx *x, const unsigned char *m,
                          unsigned char *c, uint32_t bytes);
#endif