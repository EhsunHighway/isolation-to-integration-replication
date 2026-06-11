#!/bin/bash

# Mutate the test file (assuming 'mutate' tool is available)
mutate chachapoly_crypt.c --cmd "clang -c MUTANT -I ."

# Analyze the mutants
analyze_mutants chachapoly_crypt.c "gcc -o test test_chachapoly_crypt.c chachapoly_crypt.c chacha_encrypt_bytes_stub.c chacha_ivsetup_stub.c memcmp_eq_stub.c poly1305_get_tag_stub.c chachapoly_init.c chacha_keysetup.c -I . && ./test" --verbose