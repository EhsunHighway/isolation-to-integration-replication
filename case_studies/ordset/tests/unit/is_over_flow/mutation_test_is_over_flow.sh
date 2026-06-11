#!/bin/bash

mutate is_over_flow.c --cmd "clang -c MUTANT -I ."
analyze_mutants is_over_flow.c "gcc -o test test_is_over_flow.c is_over_flow.c ord_set.c -I . && ./test" --verbose
