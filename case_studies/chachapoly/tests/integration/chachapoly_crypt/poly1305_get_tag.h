#ifndef POLY1305_GET_TAG_H
#define POLY1305_GET_TAG_H

#include <stdint.h>
#include <string.h>
#include "poly1305.h"
#include "poly1305_init.h"
#include "poly1305_update.h"
#include "poly1305_finish.h"

void poly1305_get_tag(unsigned char *poly_key, const void *ad,
                      int ad_len, const void *ct, int ct_len, unsigned char *tag);

#endif //POLY1305_GET_TAG_H
