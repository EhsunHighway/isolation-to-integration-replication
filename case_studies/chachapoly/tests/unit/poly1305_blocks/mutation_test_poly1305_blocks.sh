#!/bin/bash

# Mutate the test file (assuming 'mutate' tool is available)
mutate poly1305_blocks.c --cmd "clang -c MUTANT -I ."

# Analyze the mutants
analyze_mutants poly1305_blocks.c "gcc -o test test_poly1305_blocks.c poly1305_blocks.c U8TO32_stub.c -I . && ./test" --verbose