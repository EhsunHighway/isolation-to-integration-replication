#!/bin/bash

mutate make_a_free_slot.c --cmd "clang -c MUTANT -I ."
analyze_mutants make_a_free_slot.c "gcc -o test test_make_a_free_slot.c make_a_free_slot.c ord_set.c -I . && ./test" --verbose
