#!/bin/bash

mutate contains_set.c --cmd "clang -c MUTANT -I ."
analyze_mutants contains_set.c "gcc -o test test_contains_set.c bin_search.c contains_set.c def_set_size.c element_at.c free_memory.c init_set_array.c remove_element.c -I . && ./test" --verbose
