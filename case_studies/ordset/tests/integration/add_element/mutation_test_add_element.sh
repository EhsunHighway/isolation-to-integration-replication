#!/bin/bash

mutate add_element.c --cmd "clang -c MUTANT -I ."
analyze_mutants add_element.c "gcc -o test test_add_element.c add_element.c bin_search.c contains_number.c def_set_size.c init_set_array.c is_over_flow.c make_a_free_slot.c resize_array.c -I . && ./test" --verbose
