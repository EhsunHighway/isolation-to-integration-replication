#!/bin/bash

mutate add_element.c --cmd "clang -c MUTANT -I ."
analyze_mutants add_element.c "gcc -o test test_add_element.c add_element.c bin_search_stub.c contains_number_stub.c def_set_size.c init_set_array.c is_over_flow.c make_a_free_slot_stub.c resize_array_stub.c -I . && ./test" --verbose
