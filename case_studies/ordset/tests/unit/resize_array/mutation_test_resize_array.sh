#!/bin/bash

mutate resize_array.c --cmd "clang -c MUTANT -I ."
analyze_mutants resize_array.c "gcc -o test test_resize_array.c def_set_size.c free_memory.c init_set_array.c ord_set.c realloc_failure.c resize_array.c -I . && ./test" --verbose
