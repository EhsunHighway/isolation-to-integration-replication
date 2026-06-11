#include "chacha_encrypt_bytes_stub.h"

unsigned char *expected_c;
uint32_t expected_inputs[2];

void set_encrypt(unsigned char *c, uint32_t input[2]) {
    expected_c = c;
    for(int i = 0; i < 2; i++)
        expected_inputs[i] = expected_inputs[i];
}

void
chacha_encrypt_bytes(struct chacha_ctx *x,const unsigned char *m,unsigned char *c,uint32_t bytes) {
        if (c != NULL && expected_c != NULL) {
            memcpy(c, expected_c, bytes);  // Copy the contents of expected_c to c
        }
}
