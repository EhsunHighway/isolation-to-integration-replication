#!/bin/bash

mutate is_empty.c --cmd "clang -c MUTANT -I ."
analyze_mutants is_empty.c "gcc -o test test_is_empty.c is_empty.c ord_set.c -I . && ./test" --verbose
