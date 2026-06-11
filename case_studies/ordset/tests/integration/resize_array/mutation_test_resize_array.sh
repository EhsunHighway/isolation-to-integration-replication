#!/bin/bash

mutate resize_array.c --cmd "clang -c MUTANT -I ."
analyze_mutants resize_array.c "gcc -o test test_resize_array.c resize_array.c -I . && ./test" --verbose
