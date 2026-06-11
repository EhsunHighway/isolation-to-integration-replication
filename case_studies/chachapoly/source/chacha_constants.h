#ifndef CHACHA_CONSTANTS_H
#define CHACHA_CONSTANTS_H

#define U8C(v) (v##U)
#define U32C(v) (v##U)

#define U8V(v) ((unsigned char)(v) & U8C(0xFF))
#define U32V(v) ((uint32_t)(v) & U32C(0xFFFFFFFF))

#define ROTL32(v, n) (U32V((v) << (n)) | ((v) >> (32 - (n))))

#define ROTATE(v, c) (ROTL32(v, c))
#define XOR(v, w) ((v) ^ (w))
#define PLUS(v, w) (U32V((v) + (w)))
#define PLUSONE(v) (PLUS((v), 1))

static const char sigma[16];
static const char tau[16];

#endif // CHACHA_CONSTANTS_H
