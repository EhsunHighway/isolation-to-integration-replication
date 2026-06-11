#include "U8TO32.c"
#include <stdio.h>

void test_U8TO32(const unsigned char *p, uint32_t expected)
{
    uint32_t f = U8TO32(p);
    printf("%u\n", f);
    if (f == expected){
        printf("Test passed.");
    } else {
        printf("Test failed.");
        // exit(1); // use this for mutation analysis
    }
}

void test_1(){
    printf("Test 1: \n");

    unsigned char key1[32] = {
            0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
            0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
            0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97,
            0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f
    };

    uint32_t expected = 2206368128;
    test_U8TO32(&key1[0], expected);
}

int main(){
    printf("Unit test U8TO32(): \n");
    test_1();
}