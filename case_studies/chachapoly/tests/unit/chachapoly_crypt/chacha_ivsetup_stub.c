#include "chacha_ivsetup_stub.h"

uint32_t expected_indices[4];

void set_iv_inputs(uint32_t inputs[4]) {
    for(int i = 0; i < 4; i++)
        expected_indices[i] = inputs[i];
}

void
chacha_ivsetup(struct chacha_ctx *x, const unsigned char *iv, const unsigned char *counter)
{
    uint32_t *input_ptr = x->input + 12;
    uint32_t *expected_ptr = expected_indices;

    for(int i = 0; i < 4; i++)
        *(input_ptr + i) = *(expected_ptr + i);
}