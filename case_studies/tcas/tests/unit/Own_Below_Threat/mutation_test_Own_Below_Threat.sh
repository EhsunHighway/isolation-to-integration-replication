#!/bin/bash

mutate Own_Below_Threat.c --cmd "clang -c MUTANT -I ."
analyze_mutants Own_Below_Threat.c "gcc -o test Own_Below_Threat.c  test_Own_Below_Threat.c  -I . && ./test" --verbose