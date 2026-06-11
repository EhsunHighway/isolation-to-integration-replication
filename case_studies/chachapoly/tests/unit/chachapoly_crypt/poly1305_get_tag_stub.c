#include "poly1305_get_tag_stub.h"


unsigned char expected_tag_0[4];
unsigned char expected_tag_1[4];
unsigned char expected_tag_2[4];
unsigned char expected_tag_3[4];

void set_tag(const unsigned char set_tag[4][4]){
    for (int i = 0; i < 4; i++) {
        expected_tag_0[i] = set_tag[0][i];
        expected_tag_1[i] = set_tag[1][i];
        expected_tag_2[i] = set_tag[2][i];
        expected_tag_3[i] = set_tag[3][i];
    }
}


void poly1305_get_tag(unsigned char *poly_key, const void *ad,
                             int ad_len, const void *ct, int ct_len, unsigned char *tag)
{
        for (int i = 0; i < 4; i++) {
            tag[i] = expected_tag_0[i];
            tag[i + 4] = expected_tag_1[i];
            tag[i + 8] = expected_tag_2[i];
            tag[i + 12] = expected_tag_3[i];
        }
}