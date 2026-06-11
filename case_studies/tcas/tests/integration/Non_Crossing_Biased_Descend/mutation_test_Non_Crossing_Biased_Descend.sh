#!/bin/bash

mutate Non_Crossing_Biased_Descend.c --cmd "clang -c MUTANT -I ."
analyze_mutants Non_Crossing_Biased_Descend.c "gcc -o test Non_Crossing_Biased_Descend.c Own_Below_Threat.c Own_Above_Threat.c  ALIM.c initialize.c test_Non_Crossing_Biased_Descend.c  Inhibit_Biased_Climb.c -I . && ./test" --verbose

mutate Own_Below_Threat.c --cmd "clang -c MUTANT -I ."
analyze_mutants Own_Below_Threat.c "gcc -o test Non_Crossing_Biased_Descend.c Own_Below_Threat.c Own_Above_Threat.c  ALIM.c initialize.c test_Non_Crossing_Biased_Descend.c  Inhibit_Biased_Climb.c -I . && ./test" --verbose --prefix "Own_Below_Threat"

mutate Own_Above_Threat.c --cmd "clang -c MUTANT -I ."
analyze_mutants Own_Above_Threat.c "gcc -o test Non_Crossing_Biased_Descend.c Own_Below_Threat.c Own_Above_Threat.c  ALIM.c initialize.c test_Non_Crossing_Biased_Descend.c  Inhibit_Biased_Climb.c -I . && ./test" --verbose --prefix "Own_Above_Threat"

mutate ALIM.c --cmd "clang -c MUTANT -I ."
analyze_mutants ALIM.c "gcc -o test Non_Crossing_Biased_Descend.c Own_Below_Threat.c Own_Above_Threat.c  ALIM.c initialize.c test_Non_Crossing_Biased_Descend.c  Inhibit_Biased_Climb.c -I . && ./test" --verbose --prefix "ALIM"


mutate Inhibit_Biased_Climb.c --cmd "clang -c MUTANT -I ."
analyze_mutants Inhibit_Biased_Climb.c "gcc -o test Non_Crossing_Biased_Descend.c Own_Below_Threat.c Own_Above_Threat.c  ALIM.c initialize.c test_Non_Crossing_Biased_Descend.c  Inhibit_Biased_Climb.c -I . && ./test" --verbose --prefix "Inhibit_Biased_Climb"

