#include "poly1305_finish_stub.h"

unsigned char expected_mac_0[4];
unsigned char expected_mac_1[4];
unsigned char expected_mac_2[4];
unsigned char expected_mac_3[4];

void set_mac(const unsigned char set_mac[4][4]){
    for (int i = 0; i < 4; i++) {
        expected_mac_0[i] = set_mac[0][i];
        expected_mac_1[i] = set_mac[1][i];
        expected_mac_2[i] = set_mac[2][i];
        expected_mac_3[i] = set_mac[3][i];
    }
}

void poly1305_finish(struct poly1305_context *st, unsigned char mac[16]) {
    for (int i = 0; i < 4; i++) {
        mac[i] = expected_mac_0[i];
        mac[i + 4] = expected_mac_1[i];
        mac[i + 8] = expected_mac_2[i];
        mac[i + 12] = expected_mac_3[i];
    }
}

// Pointer arithmetic version

//void poly1305_finish(struct poly1305_context *st, unsigned char mac[16]) {
//    unsigned char *mac_ptr = mac;                  // Pointer to the start of the mac array
//    unsigned char *expected_ptr = &expected_mac[0][0]; // Pointer to the start of expected_mac
//
//    for (int i = 0; i < 4; i++) {
//        *(mac_ptr + i) = *(expected_ptr + i);
//        *(mac_ptr + i + 4) = *(expected_ptr + i + 4);
//        *(mac_ptr + i + 8) = *(expected_ptr + i + 8);
//        *(mac_ptr + i + 12) = *(expected_ptr + i + 12);
//    }
//}
