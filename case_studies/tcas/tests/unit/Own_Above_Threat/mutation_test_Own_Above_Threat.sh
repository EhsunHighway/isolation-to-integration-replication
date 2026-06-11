#!/bin/bash

mutate Own_Above_Threat.c --cmd "clang -c MUTANT -I ."
analyze_mutants Own_Above_Threat.c "gcc -o test Own_Above_Threat.c  test_Own_Above_Threat.c  -I . && ./test" --verbose