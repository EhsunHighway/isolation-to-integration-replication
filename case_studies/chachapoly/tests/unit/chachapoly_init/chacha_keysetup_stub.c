#include "chacha_keysetup_stub.h"

uint32_t expected_inputs[12];

void set_key_inputs(uint32_t inputs[12]) {
    for(int i = 0;i < 12; i++)
        expected_inputs[i] = inputs[i];
}

void
chacha_keysetup(struct chacha_ctx *x,const unsigned char *k,uint32_t kbits)
{
    for(int i = 0;i < 12; i++)
        x->input[i] = expected_inputs[i];
}