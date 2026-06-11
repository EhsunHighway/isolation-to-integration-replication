#!/bin/bash

mutate union_sets.c --cmd "clang -c MUTANT -I ."
analyze_mutants union_sets.c "gcc -o test test_union_sets.c add_element_stub.c malloc_failure.c ord_set.c union_sets.c -I . && ./test" --verbose
