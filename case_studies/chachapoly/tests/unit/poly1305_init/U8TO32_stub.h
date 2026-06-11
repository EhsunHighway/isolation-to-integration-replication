#ifndef U8TO32_STUB_H
#define U8TO32_STUB_H

#include "poly1305.h"

void set_U8T032_init(const uint32_t set_r[5], const uint32_t set_pad[4], int flag);
void set_U8T032_blocks(const uint32_t set_r[20], int flag);
void reset_U8TO32_call_count(void);
uint32_t U8TO32(const unsigned char *p);

#endif
