#include <stdio.h>
#include <stdbool.h>
#include "chacha.h"
#include "chacha_helpers.h"
#include "chacha_keysetup.h"

// Test function for chacha_keysetup
void test_chacha_keysetup(struct chacha_ctx *x, const unsigned char *k, uint32_t kbits, struct chacha_ctx *expected) {
    chacha_keysetup(x, k, kbits);

    bool failed = false;
    for (int i = 0; i < 16; i++) {
        if (x->input[i] != expected->input[i]) {
            failed = true;  // Set failed to true if any mismatch is found
            printf("Mismatch at index %d: got 0x%x, expected 0x%x\n", i, x->input[i], expected->input[i]);
        }
    }

    if (!failed) {
        printf("\nTest passed.\n");
    } else {
        printf("\nTest failed.\n");
        // exit(1); // use this for mutation analysis
    }
}

void test_1() {
    struct chacha_ctx x1;
    memset(x1.input, 0, sizeof(x1.input));
    unsigned char key1[32] = {
            0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
            0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
            0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97,
            0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f
    };

    struct chacha_ctx expected1 = {
            .input = {
                    0x0, 0x0, 0x0, 0x0,
                    0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
                    0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
                    0x0, 0x0, 0x0, 0x0
            }
    };

    test_chacha_keysetup(&x1, key1, 128, &expected1);
}

// Test 2
void test_2() {
    struct chacha_ctx x2;
        memset(x2.input, 0, sizeof(x2.input));

    unsigned char key2[32] = {
            0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
            0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
            0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97,
            0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f
    };

    struct chacha_ctx expected2 = {
            .input = {
                    0x0, 0x0, 0x0, 0x0,
                    0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
                    0x93929190, 0x97969594, 0x9b9a9998, 0x9f9e9d9c,
                    0x0, 0x0, 0x0, 0x0
            }
    };

    test_chacha_keysetup(&x2, key2, 256, &expected2);
}

int main() {
    printf("Unit test chacha_keysetup(): \n");
    test_1();
    test_2();
    return 0;
}
