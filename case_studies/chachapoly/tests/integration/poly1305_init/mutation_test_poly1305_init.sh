#!/bin/bash

# Mutate the test file (assuming 'mutate' tool is available)
mutate poly1305_init.c --cmd "clang -c MUTANT -I ."

# Analyze the mutants
analyze_mutants poly1305_init.c "gcc -o test test_poly1305_init.c poly1305_init.c U8TO32.c -I . && ./test" --verbose

mutate U8TO32.c --cmd "clang -c MUTANT -I ."
analyze_mutants U8TO32.c "gcc -o test test_poly1305_init.c poly1305_init.c U8TO32.c -I . && ./test" --verbose --prefix "U8TO32"
