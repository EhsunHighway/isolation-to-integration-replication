#!/bin/bash

# Mutate the test file (assuming 'mutate' tool is available)
mutate U32TO8.c --cmd "clang -c MUTANT -I ."

# Analyze the mutants
analyze_mutants U32TO8.c "gcc -o test test_U32TO8.c U32TO8.c -I . && ./test" --verbose