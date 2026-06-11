#include "U8TO32_stub.h"

uint32_t return_r_0;
uint32_t return_r_1;
uint32_t return_r_2;
uint32_t return_r_3;
uint32_t return_r_4;
uint32_t return_pad_0;
uint32_t return_pad_1;
uint32_t return_pad_2;
uint32_t return_pad_3;

uint32_t return_h_0[20];

static int f;
static int call_count = 0;

void set_U8T032_init(const uint32_t set_r[5], const uint32_t set_pad[4], int flag){
    return_r_0 = set_r[0];
    return_r_1 = set_r[1];
    return_r_2 = set_r[2];
    return_r_3 = set_r[3];
    return_r_4 = set_r[4];
    return_pad_0 = set_pad[0];
    return_pad_1 = set_pad[1];
    return_pad_2 = set_pad[2];
    return_pad_3 = set_pad[3];
    flag = f;
}

void set_U8T032_blocks(const uint32_t set_h[20], int flag) {
    for (int i = 0; i < 20; i++) {
        return_h_0[i] = set_h[i];
    }
    f = flag;
}    

uint32_t U8TO32(const unsigned char *p) {
    if (f == 0) {
        switch (call_count++) {
            case 0:
                return return_r_0;
            case 1:
                return return_r_1;
            case 2:
                return return_r_2;
            case 3:
                return return_r_3;
            case 4:
                return return_r_4;
            case 5:
                return return_pad_0;
            case 6:
                return return_pad_1;
            case 7:
                return return_pad_2;
            case 8:
                return return_pad_3;
            default:
                return 0;  // Default case if call_count exceeds expectations
        }
    } else {
        if (call_count < 20) {
            return return_h_0[call_count++];
        }
    }
    return 0;
}

void reset_U8TO32_call_count(void) {
    call_count = 0;  // Reset the call count to zero
}