#!/bin/bash

# Mutate the test file (assuming 'mutate' tool is available)
mutate chacha_keysetup.c --cmd "clang -c MUTANT -I ."

# Analyze the mutants
analyze_mutants chacha_keysetup.c "gcc -o test chacha_keysetup.c test_chacha_keysetup.c -I . && ./test" --verbose