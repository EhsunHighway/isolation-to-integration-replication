#include "memcmp_eq.h"

int memcmp_eq(const void *av, const void *bv, int n)
{
    const unsigned char *a = (const unsigned char*) av;
    const unsigned char *b = (const unsigned char*) bv;
    unsigned char res = 0;
    int i;

    for (i = 0; i < n; i++) {
        res |= *a ^ *b;
        a++;
        b++;
    }

    return res;
}