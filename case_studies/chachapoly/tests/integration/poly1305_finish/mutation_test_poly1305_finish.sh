#!/bin/bash

# # Mutate the test file (assuming 'mutate' tool is available)
mutate poly1305_finish.c --cmd "clang -c MUTANT -I ."

# # Analyze the mutants
analyze_mutants poly1305_finish.c "gcc -o test test_poly1305_finish.c poly1305_init.c U32TO8.c poly1305_finish.c U8TO32.c poly1305_blocks.c -I . && ./test" --verbose

# # Mutate the test file (assuming 'mutate' tool is available)
mutate poly1305_blocks.c --cmd "clang -c MUTANT -I ."
# # Analyze the mutants
# analyze_mutants poly1305_blocks.c "gcc -o test test_poly1305_finish.c poly1305_init.c U32TO8.c poly1305_finish.c U8TO32.c poly1305_blocks.c -I . && ./test" --verbose --prefix "poly1305_blocks"

# # Mutate the test file (assuming 'mutate' tool is available)
mutate U32TO8.c --cmd "clang -c MUTANT -I ."
# # Analyze the mutants
# analyze_mutants U32TO8.c "gcc -o test test_poly1305_finish.c poly1305_init.c U32TO8.c poly1305_finish.c U8TO32.c poly1305_blocks.c -I . && ./test" --verbose --prefix "U32TO8"

# # Mutate the test file (assuming 'mutate' tool is available)
mutate U8TO32.c --cmd "clang -c MUTANT -I ."
# # Analyze the mutants
# analyze_mutants U8TO32.c "gcc -o test test_poly1305_finish.c poly1305_init.c U32TO8.c poly1305_finish.c U8TO32.c poly1305_blocks.c -I . && ./test" --verbose --prefix "U8TO32"