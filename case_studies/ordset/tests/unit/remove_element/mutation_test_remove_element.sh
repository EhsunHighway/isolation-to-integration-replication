#!/bin/bash

mutate remove_element.c --cmd "clang -c MUTANT -I ."
analyze_mutants remove_element.c "gcc -o test test_remove_element.c bin_search_stub.c def_set_size.c free_memory.c init_set_array.c remove_element.c -I . && ./test" --verbose
