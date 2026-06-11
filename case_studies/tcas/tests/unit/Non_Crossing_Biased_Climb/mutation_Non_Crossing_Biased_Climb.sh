#!/bin/bash

mutate Non_Crossing_Biased_Climb.c --cmd "clang -c MUTANT -I ."
analyze_mutants Non_Crossing_Biased_Climb.c "gcc -o test Non_Crossing_Biased_Climb.c Own_Below_Threat_stub.c Own_Above_Threat_stub.c  ALIM.c initialize.c test_Non_Crossing_Biased_Climb.c  Inhibit_Biased_Climb_stub.c -I . && ./test" --verbose