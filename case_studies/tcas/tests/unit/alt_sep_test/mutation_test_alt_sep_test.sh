#!/bin/bash

mutate alt_sep_test.c --cmd "clang -c MUTANT -I ."
analyze_mutants alt_sep_test.c "gcc -o test alt_sep_test.c initialize.c Non_Crossing_Biased_Climb_stub.c Non_Crossing_Biased_Descend_stub.c Own_Below_Threat_stub.c Own_Above_Threat_stub.c  test_alt_sep_test.c  -I . && ./test" --verbose