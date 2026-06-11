#!/bin/bash

mutate contains_set.c --cmd "clang -c MUTANT -I ."
analyze_mutants contains_set.c "gcc -o test test_contains_set.c bin_search_stub.c contains_set.c element_at_stub.c ord_set.c -I . && ./test" --verbose
