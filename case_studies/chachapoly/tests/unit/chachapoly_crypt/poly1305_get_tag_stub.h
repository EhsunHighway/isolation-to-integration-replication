#ifndef POLY1305_GET_TAG_STUB_H
#define POLY1305_GET_TAG_STUB_H

#include <stdint.h>
#include <string.h>
#include "poly1305.h"

void set_tag(const unsigned char set_tag[4][4]);
void poly1305_get_tag(unsigned char *poly_key, const void *ad,
                      int ad_len, const void *ct, int ct_len, unsigned char *tag);

#endif //POLY1305_GET_TAG_H
