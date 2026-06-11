#!/bin/bash

# Mutate the test file (assuming 'mutate' tool is available)
mutate chachapoly_crypt.c --cmd "clang -c MUTANT -I ."
analyze_mutants chachapoly_crypt.c "gcc -o test test_chachapoly_crypt.c chachapoly_crypt.c chacha_encrypt_bytes.c chacha_ivsetup.c memcmp_eq.c poly1305_blocks.c poly1305_finish.c poly1305_get_tag.c poly1305_update.c U8TO32.c U32TO8.c poly1305_init.c chachapoly_init.c chacha_keysetup.c -I . && ./test" --verbose --timeout 10


mutate poly1305_get_tag.c --cmd "clang -c MUTANT -I ."
analyze_mutants poly1305_get_tag.c "gcc -o test test_chachapoly_crypt.c chachapoly_crypt.c chacha_encrypt_bytes.c chacha_ivsetup.c memcmp_eq.c poly1305_blocks.c poly1305_finish.c poly1305_get_tag.c poly1305_update.c U8TO32.c U32TO8.c poly1305_init.c chachapoly_init.c chacha_keysetup.c -I . && ./test" --verbose --timeout 10 --prefix "poly1305_get_tag"

mutate memcmp_eq.c --cmd "clang -c MUTANT -I ."
analyze_mutants memcmp_eq.c "gcc -o test test_chachapoly_crypt.c chachapoly_crypt.c chacha_encrypt_bytes.c chacha_ivsetup.c memcmp_eq.c poly1305_blocks.c poly1305_finish.c poly1305_get_tag.c poly1305_update.c U8TO32.c U32TO8.c poly1305_init.c chachapoly_init.c chacha_keysetup.c -I . && ./test" --verbose --timeout 10 --prefix "memcmp_eq"

mutate chacha_ivsetup.c --cmd "clang -c MUTANT -I ."
analyze_mutants chacha_ivsetup.c "gcc -o test test_chachapoly_crypt.c chachapoly_crypt.c chacha_encrypt_bytes.c chacha_ivsetup.c memcmp_eq.c poly1305_blocks.c poly1305_finish.c poly1305_get_tag.c poly1305_update.c U8TO32.c U32TO8.c poly1305_init.c chachapoly_init.c chacha_keysetup.c -I . && ./test" --verbose --timeout 10  --prefix "chacha_ivsetup"

mutate chacha_encrypt_bytes.c --cmd "clang -c MUTANT -I ."
analyze_mutants chacha_encrypt_bytes.c "gcc -o test test_chachapoly_crypt.c chachapoly_crypt.c chacha_encrypt_bytes.c chacha_ivsetup.c memcmp_eq.c poly1305_blocks.c poly1305_finish.c poly1305_get_tag.c poly1305_update.c U8TO32.c U32TO8.c poly1305_init.c chachapoly_init.c chacha_keysetup.c -I . && ./test" --verbose --timeout 10  --prefix "chacha_encrypt_bytes"

mutate poly1305_finish.c --cmd "clang -c MUTANT -I ."
analyze_mutants poly1305_finish.c "gcc -o test test_chachapoly_crypt.c chachapoly_crypt.c chacha_encrypt_bytes.c chacha_ivsetup.c memcmp_eq.c poly1305_blocks.c poly1305_finish.c poly1305_get_tag.c poly1305_update.c U8TO32.c U32TO8.c poly1305_init.c chachapoly_init.c chacha_keysetup.c -I . && ./test" --verbose --timeout 10  --prefix "poly1305_finish"

mutate poly1305_init.c --cmd "clang -c MUTANT -I ."
analyze_mutants poly1305_init.c "gcc -o test test_chachapoly_crypt.c chachapoly_crypt.c chacha_encrypt_bytes.c chacha_ivsetup.c memcmp_eq.c poly1305_blocks.c poly1305_finish.c poly1305_get_tag.c poly1305_update.c U8TO32.c U32TO8.c poly1305_init.c chachapoly_init.c chacha_keysetup.c -I . && ./test" --verbose --timeout 10  --prefix "poly1305_init"

mutate poly1305_update.c --cmd "clang -c MUTANT -I ."
analyze_mutants poly1305_update.c "gcc -o test test_chachapoly_crypt.c chachapoly_crypt.c chacha_encrypt_bytes.c chacha_ivsetup.c memcmp_eq.c poly1305_blocks.c poly1305_finish.c poly1305_get_tag.c poly1305_update.c U8TO32.c U32TO8.c poly1305_init.c chachapoly_init.c chacha_keysetup.c -I . && ./test" --verbose --timeout 10  --prefix "poly1305_update"

mutate U8TO32.c --cmd "clang -c MUTANT -I ."
analyze_mutants U8TO32.c "gcc -o test test_chachapoly_crypt.c chachapoly_crypt.c chacha_encrypt_bytes.c chacha_ivsetup.c memcmp_eq.c poly1305_blocks.c poly1305_finish.c poly1305_get_tag.c poly1305_update.c U8TO32.c U32TO8.c poly1305_init.c chachapoly_init.c chacha_keysetup.c -I . && ./test" --verbose --timeout 10  --prefix "U8TO32"

mutate U32TO8.c --cmd "clang -c MUTANT -I ."
analyze_mutants U32TO8.c "gcc -o test test_chachapoly_crypt.c chachapoly_crypt.c chacha_encrypt_bytes.c chacha_ivsetup.c memcmp_eq.c poly1305_blocks.c poly1305_finish.c poly1305_get_tag.c poly1305_update.c U8TO32.c U32TO8.c poly1305_init.c chachapoly_init.c chacha_keysetup.c -I . && ./test" --verbose --timeout 10  --prefix "U32TO8"

mutate poly1305_blocks.c --cmd "clang -c MUTANT -I ."
analyze_mutants poly1305_blocks.c "gcc -o test test_chachapoly_crypt.c chachapoly_crypt.c chacha_encrypt_bytes.c chacha_ivsetup.c memcmp_eq.c poly1305_blocks.c poly1305_finish.c poly1305_get_tag.c poly1305_update.c U8TO32.c U32TO8.c poly1305_init.c chachapoly_init.c chacha_keysetup.c -I . && ./test" --verbose --timeout 10  --prefix "poly1305_blocks"

mutate chachapoly_init.c --cmd "clang -c MUTANT -I ."
analyze_mutants chachapoly_init.c "gcc -o test test_chachapoly_crypt.c chachapoly_crypt.c chacha_encrypt_bytes.c chacha_ivsetup.c memcmp_eq.c poly1305_blocks.c poly1305_finish.c poly1305_get_tag.c poly1305_update.c U8TO32.c U32TO8.c poly1305_init.c chachapoly_init.c chacha_keysetup.c -I . && ./test" --verbose --timeout 10  --prefix "chachapoly_init"

mutate chacha_keysetup.c --cmd "clang -c MUTANT -I ."
analyze_mutants chacha_keysetup.c "gcc -o test test_chachapoly_crypt.c chachapoly_crypt.c chacha_encrypt_bytes.c chacha_ivsetup.c memcmp_eq.c poly1305_blocks.c poly1305_finish.c poly1305_get_tag.c poly1305_update.c U8TO32.c U32TO8.c poly1305_init.c chachapoly_init.c chacha_keysetup.c -I . && ./test" --verbose --timeout 10  --prefix "chacha_keysetup"