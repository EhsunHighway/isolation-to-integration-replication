#!/bin/bash

mutate element_at.c --cmd "clang -c MUTANT -I ."
analyze_mutants element_at.c "gcc -o test test_element_at.c element_at.c -I . && ./test" --verbose
