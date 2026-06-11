#!/bin/bash

mutate init_set_array.c --cmd "clang -c MUTANT -I ."
analyze_mutants init_set_array.c "gcc -o test test_init_set_array.c def_set_size.c free_memory.c init_set_array.c malloc_failure.c -I . && ./test" --verbose
