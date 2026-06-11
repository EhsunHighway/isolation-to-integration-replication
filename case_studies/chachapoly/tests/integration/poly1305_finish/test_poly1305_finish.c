#include "poly1305.h"
#include <stdbool.h>
#include <stdio.h>
#include "U32TO8.h"
#include "poly1305_init.h"
#include "poly1305_blocks.h"
#include "poly1305_finish.h"

void test_poly1305_finish(struct poly1305_context *st, unsigned char mac[16], struct poly1305_context *expected, unsigned char expected_mac[16]) {
    poly1305_finish(st, mac);

    bool passed = true;

    for (int i = 0; i < 5; i++) {
        if (st->r[i] != expected->r[i]) {
            passed = false;
        }
        if (st->h[i] != expected->h[i]) {
            passed = false;
        }
    }
    for (int i = 0; i < 16; i++) {
        if (mac[i] != expected_mac[i]) {
            passed = false;
        }
    }
    if (passed) {
        printf("\nTest passed.\n");
    } else {
        printf("\nTest failed.\n");
        // exit(1); // use this for mutation analysis
    }
}

void test_1() {

    printf("\nTest 1: \n");
    struct poly1305_context st1;
    unsigned char key1[32] = {
            0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
            0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
            0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97,
            0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f
    };
    poly1305_init(&st1, key1);

    // Expected state after blocks
    struct poly1305_context expected1;
    // Manually setting the expected values from the expected test outcome
    expected1.r[0] = 0;
    expected1.r[1] = 0;
    expected1.r[2] = 0;
    expected1.r[3] = 0;
    expected1.r[4] = 0;

    expected1.h[0] = 0;
    expected1.h[1] = 0;
    expected1.h[2] = 0;
    expected1.h[3] = 0;
    expected1.h[4] = 0;

    expected1.pad[0] = 0;
    expected1.pad[1] = 0;
    expected1.pad[2] = 0;
    expected1.pad[3] = 0;

    expected1.leftover = 0;
    expected1.final = 0;

    unsigned char mac1[16];

    unsigned char expected_mac1[16] = {144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159};

    test_poly1305_finish(&st1, mac1, &expected1, expected_mac1);

}

void test_2() {

    printf("\nTest 2: \n");
    struct poly1305_context st2;
    unsigned char key2[32] = {
            0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
            0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
            0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97,
            0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f
    };
    poly1305_init(&st2, key2);
    st2.leftover = 1;
    // Expected state after blocks
    struct poly1305_context expected2;
    // Manually setting the expected values from the expected test outcome
    expected2.r[0] = 0;
    expected2.r[1] = 0;
    expected2.r[2] = 0;
    expected2.r[3] = 0;
    expected2.r[4] = 0;

    expected2.h[0] = 0;
    expected2.h[1] = 0;
    expected2.h[2] = 0;
    expected2.h[3] = 0;
    expected2.h[4] = 0;

    expected2.pad[0] = 0;
    expected2.pad[1] = 0;
    expected2.pad[2] = 0;
    expected2.pad[3] = 0;

    expected2.leftover = 0;
    expected2.final = 0;


    unsigned char mac2[16];


    unsigned char expected_mac2[16] = {174, 1, 165, 71, 26, 140, 47, 210, 164, 22, 186, 92, 47, 161, 68, 231};

    test_poly1305_finish(&st2, mac2, &expected2, expected_mac2);
}

int main(){
    printf("\nUnit test for poly1305_finish() with stub: \n");
    test_1();
    test_2();

}
