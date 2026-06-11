#!/bin/bash

# Mutate the test file (assuming 'mutate' tool is available)
mutate poly1305_update.c --cmd "clang -c MUTANT -I ."

# Analyze the mutants
analyze_mutants poly1305_update.c "gcc -o test test_poly1305_update.c poly1305_update.c poly1305_init.c poly1305_blocks_stub.c U8TO32.c -I . && ./test" --verbose