#!/bin/bash

# Mutate the test file (assuming 'mutate' tool is available)
mutate poly1305_init.c --cmd "clang -c MUTANT -I ."

# Analyze the mutants
analyze_mutants poly1305_init.c "gcc -o test test_poly1305_init.c poly1305_init.c U8TO32_stub.c -I . && ./test" --verbose