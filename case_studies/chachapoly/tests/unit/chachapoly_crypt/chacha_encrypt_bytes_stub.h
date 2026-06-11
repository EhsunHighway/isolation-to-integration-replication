#ifndef CHACHA_ENCRYPT_BYTES_STUB_H
#define CHACHA_ENCRYPT_BYTES_STUB_H

#include "chacha.h"

void set_encrypt(unsigned char *c, uint32_t input[2]);
void chacha_encrypt_bytes(struct chacha_ctx *x, const unsigned char *m,
                          unsigned char *c, uint32_t bytes);


#endif