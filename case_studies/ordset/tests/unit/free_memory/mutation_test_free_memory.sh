#!/bin/bash

mutate free_memory.c --cmd "clang -c MUTANT -I ."
analyze_mutants free_memory.c "gcc -o test test_free_memory.c free_memory.c ord_set.c -I . && ./test" --verbose
