#include "poly1305_update.h"

void
poly1305_update(struct poly1305_context *st, const unsigned char *m, size_t bytes)
{
    size_t i;

    /* handle leftover */
    if (st->leftover) {
        size_t want = (POLY1305_BLOCK_SIZE - st->leftover);
        if (want > bytes)
            want = bytes;
        for (i = 0; i < want; i++)
            st->buffer[st->leftover + i] = m[i];
        bytes -= want;
        m += want;
        st->leftover += want;
        if (st->leftover < POLY1305_BLOCK_SIZE)
            return;
        poly1305_blocks(st, st->buffer, POLY1305_BLOCK_SIZE);
        st->leftover = 0;
    }

    /* process full blocks */
    if (bytes >= POLY1305_BLOCK_SIZE) {
        size_t want = (bytes & ~(POLY1305_BLOCK_SIZE - 1));
        poly1305_blocks(st, m, want);
        m += want;
        bytes -= want;
    }

    /* store leftover */
    if (bytes) {
#if (USE_MEMCPY == 1)
        memcpy(st->buffer + st->leftover, m, bytes);
#else
        for (i = 0; i < bytes; i++)
            st->buffer[st->leftover + i] = m[i];
#endif
        st->leftover += bytes;
    }
}