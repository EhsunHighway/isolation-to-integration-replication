#!/bin/bash

# Mutate the test file (assuming 'mutate' tool is available)
mutate chachapoly_init.c --cmd "clang -c MUTANT -I ."

# Analyze the mutants
analyze_mutants chachapoly_init.c "gcc -o test test_chachapoly_init.c chacha_keysetup_stub.c chachapoly_init.c -I . && ./test" --verbose