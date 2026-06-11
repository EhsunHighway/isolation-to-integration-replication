#ifndef CHACHA_QUARTERROUND_H
#define CHACHA_QUARTERROUND_H

#include "chacha_helpers.h"
#include "chacha_constants.h"

#define QUARTERROUND(a, b, c, d) \
    a = PLUS(a, b); d = ROTATE(XOR(d, a), 16); \
    c = PLUS(c, d); b = ROTATE(XOR(b, c), 12); \
    a = PLUS(a, b); d = ROTATE(XOR(d, a), 8);  \
    c = PLUS(c, d); b = ROTATE(XOR(b, c), 7);

#endif // CHACHA_QUARTERROUND_H
