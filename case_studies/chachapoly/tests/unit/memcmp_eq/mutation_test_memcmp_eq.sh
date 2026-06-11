#!/bin/bash

# Mutate the test file (assuming 'mutate' tool is available)
mutate memcmp_eq.c --cmd "clang -c MUTANT -I ."

# Analyze the mutants
analyze_mutants memcmp_eq.c "gcc -o test test_memcmp_eq.c memcmp_eq.c -I . && ./test" --verbose