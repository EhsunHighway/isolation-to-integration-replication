#include "U32TO8.h"
#include <stdio.h>

void test_U32TO8(unsigned char *p, uint32_t v, const unsigned char *expected)
{
    // Call U32TO8 for a single uint32_t value
    U32TO8(p, v);

    // Print the resulting bytes
    printf("Resulting bytes:\n");
    for (int i = 0; i < 4; i++) {
        printf("%u ", p[i]);
    }
    printf("\n");

    // Compare with expected
    int passed = 1;
    for (int i = 0; i < 4; i++) {
        if (p[i] != expected[i]) {
            passed = 0;
            break;
        }
    }

    if (passed) {
        printf("Test passed.\n");
    } else {
        printf("Test failed.\n");
        // exit(1); // use this for mutation analysis
    }
}

void test_1(){
    printf("Test 1: \n");

    unsigned char mac[4]; // Space for a single uint32_t converted to 4 bytes
    uint32_t v = 6496736; // A single uint32_t value

    // Expected output for the single uint32_t (6496736 in bytes)
    unsigned char expected1[4] = {
            224, 33, 99, 0   // Expected byte representation of 6496736
    };

    // Run the test
    test_U32TO8(mac, v, expected1);
}

int main(){
    printf("Unit test U32TO8: \n");
    // test_1();
}
