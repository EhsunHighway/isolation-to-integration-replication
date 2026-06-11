#include "chacha_ivsetup.h"

void
chacha_ivsetup(struct chacha_ctx *x, const unsigned char *iv, const unsigned char *counter)
{
    x->input[12] = counter == NULL ? 0 : U8TO32_LITTLE(counter + 0);
    //x->input[13] = counter == NULL ? 0 : U8TO32_LITTLE(counter + 4);
    x->input[13] = U8TO32_LITTLE(iv + 0);
    x->input[14] = U8TO32_LITTLE(iv + 4);
    x->input[15] = U8TO32_LITTLE(iv + 8);
}