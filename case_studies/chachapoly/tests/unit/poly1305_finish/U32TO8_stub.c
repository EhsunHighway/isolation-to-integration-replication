#include "U32TO8_stub.h"

unsigned char expected_p_0[4];
unsigned char expected_p_1[4];
unsigned char expected_p_2[4];
unsigned char expected_p_3[4];

static int call_count = 0;  // Counter to track the number of calls

void set_U32T08(const unsigned char set_p[4][4]) {
    for (int i = 0; i < 4; i++) {
        expected_p_0[i] = set_p[0][i];
        expected_p_1[i] = set_p[1][i];
        expected_p_2[i] = set_p[2][i];
        expected_p_3[i] = set_p[3][i];
    }
}

void U32TO8(unsigned char *p, uint32_t v)
{

    switch (call_count++) {
        case 0:
            for (int i = 0; i < 4; i++) p[i] = expected_p_0[i];
            break;
        case 1:
            for (int i = 0; i < 4; i++) p[i] = expected_p_1[i];
            break;
        case 2:
            for (int i = 0; i < 4; i++) p[i] = expected_p_2[i];
            break;
        case 3:
            for (int i = 0; i < 4; i++) p[i] = expected_p_3[i];
            break;
        default:
            return;
    }
}

void reset_U32TO8_call_count(void) {
    call_count = 0;  // Reset the call count to zero
}