#include "poly1305.h"
#include <stdbool.h>
#include <stdio.h>
#include "poly1305_blocks.h"
#include "U8TO32_stub.h"

void test_poly1305_blocks(struct poly1305_context *st, const unsigned char *m, size_t bytes, struct poly1305_context *expected) {
    reset_U8TO32_call_count();
    poly1305_blocks(st, m, bytes);


    bool passed = true;

    for (int i = 0; i < 5; i++) {
        if (st->h[i] != expected->h[i]) {
            passed = false;
        }
    }

    if (passed) {
        printf("Test passed.\n");
    } else {
        printf("Test failed.\n");
        // exit(1); // use this for mutation analysis
    }
}

void test_1() {
    printf("\nTest 1: \n");
    struct poly1305_context st1;

    st1.r[0] = 58884480;
    st1.r[1] = 27353344;
    st1.r[2] = 9994360;
    st1.r[3] = 36711978;
    st1.r[4] = 1019533;

    st1.h[0] = 0;
    st1.h[1] = 0;
    st1.h[2] = 0;
    st1.h[3] = 0;
    st1.h[4] = 0;

    st1.pad[0] = 2475856272;
    st1.pad[1] = 2543228308;
    st1.pad[2] = 2610600344;
    st1.pad[3] = 2677972380;

    st1.leftover = 0;
    st1.final = 0;
    // Expected state after blocks
    struct poly1305_context expected1;
    expected1.h[0] = 13003413;
    expected1.h[1] = 23676800;
    expected1.h[2] = 48098290;
    expected1.h[3] = 48886350;
    expected1.h[4] = 56133780;

    unsigned char message2[] = {"Hello world! We are testing this to have a block more than 16 bits"};

    uint32_t set_h1[] = {1819043144, 1998614380, 1819438967, 539059308, 543512352, 543519329, 1936028704,
                         1852404851, 1948280686, 1936287860, 544175136, 1986095136, 1629513078, 1818370145,
                         1801678700, 1919905056, 1948280178, 1851877492, 909189230, 1768038454};
    set_U8T032_blocks(set_h1, 1);
    test_poly1305_blocks(&st1, message2, 67, &expected1);

}

// Test 2
void test_2() {
    printf("\nTest 2: \n");
    struct poly1305_context st2;
    unsigned char key2[32] = {
            0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
            0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
            0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97,
            0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f
    };

    // Initialize the context with the key
//    poly1305_init(&st2, key2);
    st2.final = 1;
    // Manually setting the expected values from the expected test outcome
    st2.r[0] = 0;
    st2.r[1] = 0;
    st2.r[2] = 0;
    st2.r[3] = 0;
    st2.r[4] = 0;

    st2.h[0] = 0;
    st2.h[1] = 0;
    st2.h[2] = 0;
    st2.h[3] = 0;
    st2.h[4] = 0;

    st2.pad[0] = 0;
    st2.pad[1] = 0;
    st2.pad[2] = 0;
    st2.pad[3] = 0;

    st2.leftover = 0;
    st2.final = 0;
    // Expected state after blocks
    struct poly1305_context expected2;
    expected2.h[0] = 0;
    expected2.h[1] = 0;
    expected2.h[2] = 0;
    expected2.h[3] = 0;
    expected2.h[4] = 0;

    unsigned char message2[16] = {0};

    uint32_t set_h2[20] = {0};
    set_U8T032_blocks(set_h2, 1);

    test_poly1305_blocks(&st2, message2, 16, &expected2);
}


int main() {
    printf("\nUnit test for poly1305_blocks(): \n");
    // test_1();
    // test_2();

    return 0;
}
