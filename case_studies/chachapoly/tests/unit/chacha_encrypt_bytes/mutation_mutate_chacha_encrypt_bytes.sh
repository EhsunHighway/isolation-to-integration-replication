#!/bin/bash

# Mutate the test file (assuming 'mutate' tool is available)
mutate chacha_encrypt_bytes.c --cmd "clang -c MUTANT -I ."

# Analyze the mutants
analyze_mutants chacha_encrypt_bytes.c "gcc -o test chacha_encrypt_bytes.c test_chacha_encrypt_bytes.c -I . && ./test" --verbose