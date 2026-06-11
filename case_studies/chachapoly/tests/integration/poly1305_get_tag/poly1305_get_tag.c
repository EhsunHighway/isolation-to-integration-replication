#include "poly1305_get_tag.h"

void poly1305_get_tag(unsigned char *poly_key, const void *ad,
                             int ad_len, const void *ct, int ct_len, unsigned char *tag)
{
    struct poly1305_context poly;
    unsigned left_over;
    uint64_t len;
    unsigned char pad[16];

    poly1305_init(&poly, poly_key);
    memset(&pad, 0, sizeof(pad));

    /* associated data and padding */
    poly1305_update(&poly, ad, ad_len);
    left_over = ad_len % 16;
    if (left_over)
        poly1305_update(&poly, pad, 16 - left_over);

    /* payload and padding */
    poly1305_update(&poly, ct, ct_len);
    left_over = ct_len % 16;
    if (left_over)
        poly1305_update(&poly, pad, 16 - left_over);

    /* lengths */
    len = ad_len;
    poly1305_update(&poly, (unsigned char *)&len, 8);
    len = ct_len;
    poly1305_update(&poly, (unsigned char *)&len, 8);


    poly1305_finish(&poly, tag);
}