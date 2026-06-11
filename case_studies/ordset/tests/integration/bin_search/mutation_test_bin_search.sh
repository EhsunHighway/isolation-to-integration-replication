#!/bin/bash

mutate bin_search.c --cmd "clang -c MUTANT -I ."
analyze_mutants bin_search.c "gcc -o test test_bin_search.c bin_search.c -I . && ./test" --verbose
