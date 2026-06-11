#!/bin/bash

mutate contains_number.c --cmd "clang -c MUTANT -I ."
analyze_mutants contains_number.c "gcc -o test test_contains_number.c bin_search.c contains_number.c def_set_size.c free_memory.c init_set_array.c -I . && ./test" --verbose
