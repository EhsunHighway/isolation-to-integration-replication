#!/bin/bash

mutate union_sets.c --cmd "clang -c MUTANT -I ."
analyze_mutants union_sets.c "gcc -o test test_union_sets.c add_element.c bin_search.c contains_number.c def_set_size.c free_memory.c init_set_array.c is_over_flow.c make_a_free_slot.c malloc_failure.c resize_array.c union_sets.c -I . && ./test" --verbose
