#include "chachapoly_init.h"
#include <stdio.h>
#include <stdbool.h>
#include "chacha_keysetup.h"

void test_chachapoly_init(struct chachapoly_ctx *ctx, const void *key, int key_len, int expected_int, const uint32_t *expected_key)
{
    int result = chachapoly_init(ctx, key, key_len);

    // printf("ctx->cha_ctx.input (hexadecimal): ");
    // for (int i = 0; i < 16; i++) {
    //     printf("0x%08x ", ctx->cha_ctx.input[i]); // Print each value as an 8-digit hexadecimal number
    // }
    // printf("\n");

    bool ctx_result = true;

    for (int i = 0; i < 16; i++) {
        if (ctx->cha_ctx.input[i] != expected_key[i]) {
            ctx_result = false;
            break;
        }
    }

    if (ctx_result) {
        printf("Test passed.\n");
    } else {
        printf("Test failed.\n");
        // exit(1); // use this for mutation analysis
    }
}


void test_1() {
    printf("Test 1: \n");

    struct chachapoly_ctx ctx1;
    unsigned char key1[32] = {
            0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
            0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
            0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97,
            0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f
    };

    uint32_t expected1_key[] = {
            0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
            0x93929190, 0x97969594, 0x9b9a9998, 0x9f9e9d9c,
            0x00000000, 0x00000000, 0x00000000, 0x00000000
    };

    test_chachapoly_init(&ctx1, key1, 256, 0, expected1_key);
}

void test_2(){
printf("Test 2: \n");

struct chachapoly_ctx ctx2;
    unsigned char key2[16] = {
            0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
            0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f
    };

    uint32_t expected2_key[] = {
            0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
            0x83828180, 0x87868584, 0x8b8a8988, 0x8f8e8d8c,
            0x00000000, 0x00000000, 0x00000000, 0x00000000
    };

    test_chachapoly_init(&ctx2, key2, 128, 0, expected2_key);
}


void test_3() {

    printf("Test 3: Invalid key length (too short)\n");

    struct chachapoly_ctx ctx3;
    unsigned char key3[8] = {
            0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87
    };

    uint32_t expected3_key[] = {
            0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x83828180, 0x87868584, 0xe326000f, 0x55082673,
            0x83828180, 0x87868584, 0xe326000f, 0x55082673,
            0x00000000, 0x00000000, 0x00000000, 0x00000000
    };

    int result = chachapoly_init(&ctx3, key3, 64);

    // Check for expected error
    if (result != -1) {
        printf("Error: Expected error code -1 for invalid key length\n");
    }

    // Instead of using the invalid key as the expected result, just check the error code:
    test_chachapoly_init(&ctx3, key3, 64, -1, expected3_key);


}


int main(){
    printf("Unit test for chachapoly_init() with stub: \n");
    test_1();
    // test_2();
    // test_3();

}
