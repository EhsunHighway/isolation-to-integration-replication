#ifndef POLY1305_FINISH_STUB_H
#define POLY1305_FINISH_STUB_H

#include "poly1305.h"

void set_mac(const unsigned char set_p[4][4]);
void poly1305_finish(struct poly1305_context *ctx, unsigned char mac[16]);

#endif //POLY1305_FINISH_STUB_H
