#!/bin/bash

# Mutate the test file (assuming 'mutate' tool is available)
mutate chacha_ivsetup.c --cmd "clang -c MUTANT -I ."

# Analyze the mutants
analyze_mutants chacha_ivsetup.c "gcc -o test chacha_ivsetup.c test_chacha_ivsetup.c -I . && ./test"