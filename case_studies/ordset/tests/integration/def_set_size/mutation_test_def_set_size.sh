#!/bin/bash

mutate def_set_size.c --cmd "clang -c MUTANT -I ."
analyze_mutants def_set_size.c "gcc -o test test_def_set_size.c def_set_size.c -I . && ./test" --verbose
