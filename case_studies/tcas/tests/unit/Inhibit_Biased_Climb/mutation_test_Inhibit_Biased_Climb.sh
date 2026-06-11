#!/bin/bash

mutate Inhibit_Biased_Climb.c --cmd "clang -c MUTANT -I ."
analyze_mutants Inhibit_Biased_Climb.c "gcc -o test Inhibit_Biased_Climb.c  test_Inhibit_Biased_Climb.c  -I . && ./test" --verbose