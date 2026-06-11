#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "chacha.h"
#include "chacha_helpers.h"
#include "chacha_ivsetup.h"

// Test function for chacha_keysetup
void test_chacha_ivsetup(struct chacha_ctx *x, const unsigned char *iv, const unsigned char *counter, struct chacha_ctx *expected) {
    chacha_ivsetup(x, iv, counter);

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

// Test 1
void test_1() {
    struct chacha_ctx x1 = {
            .input = {
                    0x0, 0x0, 0x0, 0x0,
                    0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
                    0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
                    0x0, 0x0, 0x0, 0x0
            }
    };

    unsigned char nonce[12] = {
        0x07, 0x00, 0x00, 0x00,
                0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47
    };

    unsigned char counter[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01}; // Example counter

    struct chacha_ctx expected1 = {
            .input = {
                    0x0, 0x0, 0x0, 0x0,
                    0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
                    0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
                    0x0, 0x7, 0x43424140, 0x47464544
            }
    };

    test_chacha_ivsetup(&x1, nonce, counter, &expected1);
}

// Test 2
void test_2() {
    struct chacha_ctx x2 = {
            .input = {
                    0x0, 0x0, 0x0, 0x0,
                    0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
                    0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
                    0x0, 0x0, 0x0, 0x0
            }
    };

    unsigned char nonce2[12] = {
            0x07, 0x00, 0x00, 0x00,
            0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47
    };

    struct chacha_ctx expected2 = {
            .input = {
                    0x0, 0x0, 0x0, 0x0,
                    0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
                    0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
                    0x0, 0x7, 0x43424140, 0x47464544
            }
    };

    test_chacha_ivsetup(&x2, nonce2, NULL, &expected2);
}

int main() {
    printf("Unit test chacha_ivsetup(): \n");
    test_1();
    test_2();
    return 0;
}
