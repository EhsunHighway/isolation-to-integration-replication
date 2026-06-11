#!/bin/bash

mutate contains_number.c --cmd "clang -c MUTANT -I ."
analyze_mutants contains_number.c "gcc -o test test_contains_number.c bin_search_stub.c contains_number.c ord_set.c -I . && ./test" --verbose
