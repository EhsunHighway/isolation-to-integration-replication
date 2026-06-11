#!/bin/bash

mutate are_equals.c --cmd "clang -c MUTANT -I ."
analyze_mutants are_equals.c "gcc -o test test_are_equals.c are_equals.c def_set_size.c element_at_stub.c init_set_array.c is_empty_stub.c -I . && ./test" --verbose
