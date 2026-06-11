#!/bin/bash

# Mutate the test file (assuming 'mutate' tool is available)
mutate poly1305_update.c --cmd "clang -c MUTANT -I ."

# Analyze the mutants
analyze_mutants poly1305_update.c "gcc -o test test_poly1305_update.c poly1305_update.c poly1305_init.c poly1305_blocks.c U8TO32.c -I . && ./test" --verbose --timeout 3

mutate poly1305_blocks.c --cmd "clang -c MUTANT -I ."
analyze_mutants poly1305_blocks.c "gcc -o test test_poly1305_update.c poly1305_update.c poly1305_init.c poly1305_blocks.c U8TO32.c -I . && ./test" --verbose --timeout 3 --prefix "poly1305_blocks"

mutate U8TO32.c --cmd "clang -c MUTANT -I ."
analyze_mutants U8TO32.c "gcc -o test test_poly1305_update.c poly1305_update.c poly1305_init.c poly1305_blocks.c U8TO32.c -I . && ./test" --verbose --timeout 3 --prefix "U8TO32"
