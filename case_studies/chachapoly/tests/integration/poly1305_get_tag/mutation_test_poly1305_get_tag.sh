#!/bin/bash

# Mutate the test file (assuming 'mutate' tool is available)
mutate poly1305_get_tag.c --cmd "clang -c MUTANT -I ."

# Analyze the mutants
analyze_mutants poly1305_get_tag.c "gcc -o test test_poly1305_get_tag.c poly1305_blocks.c poly1305_get_tag.c poly1305_init.c U32TO8.c U8TO32.c poly1305_update.c poly1305_finish.c -I . && ./test" --verbose

# Mutate the test file (assuming 'mutate' tool is available)
mutate poly1305_init.c --cmd "clang -c MUTANT -I ."
analyze_mutants poly1305_init.c "gcc -o test test_poly1305_get_tag.c poly1305_blocks.c poly1305_get_tag.c poly1305_init.c U32TO8.c U8TO32.c poly1305_update.c poly1305_finish.c -I . && ./test" --verbose --prefix "poly1305_init"

# Mutate the test file (assuming 'mutate' tool is available)
mutate poly1305_update.c --cmd "clang -c MUTANT -I ."
analyze_mutants poly1305_update.c "gcc -o test test_poly1305_get_tag.c poly1305_blocks.c poly1305_get_tag.c poly1305_init.c U32TO8.c U8TO32.c poly1305_update.c poly1305_finish.c -I . && ./test" --verbose --prefix "poly1305_update"

# Mutate the test file (assuming 'mutate' tool is available)
mutate poly1305_finish.c --cmd "clang -c MUTANT -I ."
analyze_mutants poly1305_finish.c "gcc -o test test_poly1305_get_tag.c poly1305_blocks.c poly1305_get_tag.c poly1305_init.c U32TO8.c U8TO32.c poly1305_update.c poly1305_finish.c -I . && ./test" --verbose --prefix "poly1305_finish"

# Mutate the test file (assuming 'mutate' tool is available)
mutate poly1305_blocks.c --cmd "clang -c MUTANT -I ."
analyze_mutants poly1305_blocks.c "gcc -o test test_poly1305_get_tag.c poly1305_blocks.c poly1305_get_tag.c poly1305_init.c U32TO8.c U8TO32.c poly1305_update.c poly1305_finish.c -I . && ./test" --verbose --prefix "poly1305_blocks"


# Mutate the test file (assuming 'mutate' tool is available)
mutate U32TO8.c --cmd "clang -c MUTANT -I ."
analyze_mutants U32TO8.c "gcc -o test test_poly1305_get_tag.c poly1305_blocks.c poly1305_get_tag.c poly1305_init.c U32TO8.c U8TO32.c poly1305_update.c poly1305_finish.c -I . && ./test" --verbose --prefix "U32TO8"


# Mutate the test file (assuming 'mutate' tool is available)
mutate U8TO32.c --cmd "clang -c MUTANT -I ."
analyze_mutants U8TO32.c "gcc -o test test_poly1305_get_tag.c poly1305_blocks.c poly1305_get_tag.c poly1305_init.c U32TO8.c U8TO32.c poly1305_update.c poly1305_finish.c -I . && ./test" --verbose --prefix "U8TO32"