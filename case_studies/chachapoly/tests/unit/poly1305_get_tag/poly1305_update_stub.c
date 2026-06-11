#include "poly1305_update_stub.h"

size_t expected_leftover;
size_t m_offset;
size_t expected_bytes;
unsigned char expected_buffer[16];

void set_expected_values(size_t leftover, size_t offset, size_t bytes, unsigned char buffer[16]) {
    expected_leftover = leftover;
    m_offset = offset;
    expected_bytes = bytes;
    for (int i = 0; i < 16; i++) {
        expected_buffer[i] = buffer[i];
    }
}

void poly1305_update(struct poly1305_context *ctx, const unsigned char *m, size_t bytes) {
    ctx->leftover = expected_leftover;
    m += m_offset;
    bytes = expected_bytes;
    for (int i = 0; i < 16; i++) {
        ctx->buffer[i] = expected_buffer[i];
    }
}
