#!/bin/bash

# Mutate the test file (assuming 'mutate' tool is available)
mutate U8TO32.c --cmd "clang -c MUTANT -I ."

# Analyze the mutants
analyze_mutants U8TO32.c "gcc -o test test_U8TO32.c U8TO32.c -I . && ./test" --verbose