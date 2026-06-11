#include "poly1305_init.h"
#include <stdbool.h>
#include <stdio.h>
#include "U8TO32_stub.h"

void test_poly1305_init(struct poly1305_context *ctx, const unsigned char key[32], struct poly1305_context *expected) {
    poly1305_init(ctx, key);

    bool passed = true;

    for (int i = 0; i < 5; i++) {
        if (ctx->r[i] != expected->r[i]) {
            passed = false;
        }
        if (ctx->h[i] != expected->h[i]) {
            passed = false;
        }
    }


    if (ctx->leftover != 0 || ctx->final != 0) {
        passed = false;
    }

    if (passed) {
        printf("\nTest passed.");
    } else {
        printf("\nTest failed.");
        // exit(1); // use this for mutation analysis
    }
}

void test_1() {
    printf("\nTest 1: \n");
    struct poly1305_context ctx1;
    unsigned char key1[32] = {
            0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
            0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
            0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97,
            0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f
    };



    struct poly1305_context expected1;

    // Manually setting the expected values from the expected test outcome
    expected1.r[0] = 58884480;
    expected1.r[1] = 27353344;
    expected1.r[2] = 9994360;
    expected1.r[3] = 36711978;
    expected1.r[4] = 1019533;

    expected1.h[0] = 0;
    expected1.h[1] = 0;
    expected1.h[2] = 0;
    expected1.h[3] = 0;
    expected1.h[4] = 0;

    expected1.pad[0] = 2475856272;
    expected1.pad[1] = 2543228308;
    expected1.pad[2] = 2610600344;
    expected1.pad[3] = 2677972380;

    expected1.leftover = 0;
    expected1.final = 0;

    uint32_t r_values[5] = {2206368128, 2256897155, 2307426182, 2357955209, 2408484236};
    uint32_t pad_values[4] = {2475856272, 2543228308, 2610600344, 2677972380};

    // Call the function with the arrays
    set_U8T032_init(r_values, pad_values, 0);
    test_poly1305_init(&ctx1, key1, &expected1);
}


int main(){
    printf("\nUnit test for poly1305_init() with stub: ");
    test_1();
}
