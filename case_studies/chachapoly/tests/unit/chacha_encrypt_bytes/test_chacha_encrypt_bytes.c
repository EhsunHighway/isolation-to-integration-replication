#include <stdio.h>
#include <stdbool.h>
#include "chacha.h"
#include "chacha_encrypt_bytes.h"
#include "chacha_helpers.h"

// Test function for chacha_encrypt_bytes
void test_chacha_encrypt_bytes(struct chacha_ctx *x, const unsigned char *m, unsigned char *c, uint32_t bytes, const unsigned char *expected) {
    // Encrypt the message
    chacha_encrypt_bytes(x, m, c, bytes);
    // Compare the cipher output with the expected output
    bool failed = false;
    for (uint32_t i = 0; i < bytes; i++) {
        if (c[i] != expected[i]) {
            failed = true;  // Set failed to true if any mismatch is found
            break;  // Exit loop on first mismatch for efficiency
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
    printf("\nTest 1: \n");
    struct chacha_ctx x1 = {
            .input = {
                    0x0, 0x0, 0x0, 0x0,
                    0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
                    0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
                    0x0, 0x7, 0x43424140, 0x47464544
            }
    };

    unsigned char message[] = "Test message!";
    unsigned char cipher[64];  // Allocate enough space for the cipher text
    unsigned char expected1[64] = {
            0x3b, 0xca, 0x64, 0xb2, 0x85, 0x35, 0xd1, 0x33,
            0x66, 0xd9, 0x7f, 0xb2, 0x17, 0x16
    };

    // Call the test function
    test_chacha_encrypt_bytes(&x1, message, cipher, sizeof(message), expected1);
}

// Test 2
void test_2() {
    printf("\nTest 2: \n");
    struct chacha_ctx x2 = {
            .input = {
                    0x0, 0x0, 0x0, 0x0,
                    0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
                    0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
                    0x0, 0x7, 0x43424140, 0x47464544
            }
    };

    unsigned char message2[] = {};
    unsigned char cipher[64];  // Allocate enough space for the cipher text
    unsigned char expected2[64] = {
            0x2e, 0xc1, 0x78, 0xb2, 0xcd, 0x3d, 0xc6, 0x60,
            0x61, 0xdd, 0x6b, 0xa3, 0x16, 0x7b, 0xf5, 0xd7,
            0x2c, 0x31, 0x2c, 0x21, 0x3f, 0x98
    };

    // Call the test function
    test_chacha_encrypt_bytes(&x2, message2, cipher, sizeof(message2), expected2);
}

// Test 3
void test_3() {
    printf("\nTest 3: Index 12 ctx overflow\n");
    struct chacha_ctx x3 = {
            .input = {
                    0x0, 0x0, 0x0, 0x0,
                    0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
                    0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
                    0xFFFFFFFF, 0x7, 0x43424140, 0x47464544
            }
    };

    unsigned char message3[] = "Test message!";
    unsigned char cipher3[64];  // Allocate enough space for the cipher text

    // Initial print to observe the actual cipher output
    // After the first run, update the expected3 array based on the actual output
    unsigned char expected3[64] = {
            // Update this array after running the test once
            0xbd, 0x69, 0xf6, 0xbe, 0xcc, 0xd7, 0xe4, 0x99,
            0x8b, 0x40, 0xec, 0x45, 0x5d, 0xde  // Placeholder values for now
    };

    // Call the test function
    test_chacha_encrypt_bytes(&x3, message3, cipher3, sizeof(message3), expected3);
}

// Test 4
void test_4() {
    printf("\nTest 4: message with more than 64 bytes\n");
    struct chacha_ctx x4 = {
            .input = {
                    0x0, 0x0, 0x0, 0x0,
                    0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
                    0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
                    0xFFFFFFFF, 0x7, 0x43424140, 0x47464544
            }
    };

    unsigned char message4[] = "Test message! Try to have a message with 65 bytes! One extra char.";

    unsigned char cipher4[64];  // Allocate enough space for the cipher text

    // Initial print to observe the actual cipher output
    // After the first run, update the expected4 array based on the actual output
    unsigned char expected4[] = {
            0xbd, 0x69, 0xf6, 0xbe, 0xcc, 0xd7, 0xe4, 0x99,
            0x8b, 0x40, 0xec, 0x45, 0x5d, 0xfe, 0x70, 0x6d,
            0x25, 0xa5, 0xd4, 0x66, 0x13, 0x7e, 0x46, 0xab,
            0xf0, 0xc2, 0x9b, 0xcb, 0x4f, 0xdb, 0xfa, 0xc7,
            0xca, 0xe2, 0x2c, 0xd2, 0x79, 0xde, 0xd6, 0x7e,
            0x2e, 0x16, 0x15, 0x3a, 0xde, 0x14, 0x26, 0xe0,
            0x41, 0xd2, 0x15, 0x0d, 0x76, 0xca, 0x24, 0x4e,
            0x59, 0xd6, 0x63, 0xc0, 0x7a, 0x71, 0x62, 0x3c,
            0x57, 0x80, 0x7b
    };

    // Call the test function
    test_chacha_encrypt_bytes(&x4, message4, cipher4, sizeof(message4), expected4);
}

// Test 5
void test_5() {
    printf("\nTest 5: message with size 64 bytes \n");
        // Code that uses memcpy
        printf("Using memcpy for Test 5\n");
        struct chacha_ctx x5 = {
                .input = {
                        0x0, 0x0, 0x0, 0x0,
                        0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
                        0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
                        0x0, 0x7, 0x43424140, 0x47464544
                }
        };

    unsigned char message5[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+[]{}|;:',.<>/?";
        unsigned char cipher5[64];  // Allocate enough space for the cipher text
        unsigned char expected5[64] = {
            0x3b, 0xca, 0x64, 0xb2, 0x85, 0x35, 0xd1, 0x33,
            0x66, 0xd9, 0x7f, 0xb2, 0x17, 0x16
    };

        // Call the test function
        test_chacha_encrypt_bytes(&x5, message5, cipher5, sizeof(message5), expected5);
}

int main() {
    // Run the tests
    printf("\nUnit test for chacha_encrypt_bytes():\n");

    // Test 1
    test_1();

    // Test 2
    test_2();

    // Test 3
    test_3();

    // Test 4
    test_4();

    // Test 5
    test_5();

    return 0;
}
