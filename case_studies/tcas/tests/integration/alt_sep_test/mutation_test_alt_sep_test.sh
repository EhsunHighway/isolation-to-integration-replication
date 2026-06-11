#!/bin/bash

mutate alt_sep_test.c --cmd "clang -c MUTANT -I ."
analyze_mutants alt_sep_test.c "gcc -o test alt_sep_test.c Non_Crossing_Biased_Climb.c Non_Crossing_Biased_Descend.c initialize.c Own_Below_Threat.c Own_Above_Threat.c ALIM.c Inhibit_Biased_Climb.c  test_alt_sep_test.c  -I . && ./test" --verbose

mutate Non_Crossing_Biased_Climb.c --cmd "clang -c MUTANT -I ."
analyze_mutants Non_Crossing_Biased_Climb.c "gcc -o test alt_sep_test.c Non_Crossing_Biased_Climb.c Non_Crossing_Biased_Descend.c initialize.c Own_Below_Threat.c Own_Above_Threat.c ALIM.c Inhibit_Biased_Climb.c  test_alt_sep_test.c  -I . && ./test" --verbose --prefix "Non_Crossing_Biased_Climb"

mutate Non_Crossing_Biased_Descend.c --cmd "clang -c MUTANT -I ."
analyze_mutants Non_Crossing_Biased_Descend.c "gcc -o test alt_sep_test.c Non_Crossing_Biased_Climb.c Non_Crossing_Biased_Descend.c initialize.c Own_Below_Threat.c Own_Above_Threat.c ALIM.c Inhibit_Biased_Climb.c  test_alt_sep_test.c  -I . && ./test" --verbose --prefix "Non_Crossing_Biased_Descend"

mutate Own_Below_Threat.c --cmd "clang -c MUTANT -I ."
analyze_mutants Own_Below_Threat.c "gcc -o test alt_sep_test.c Non_Crossing_Biased_Climb.c Non_Crossing_Biased_Descend.c Own_Below_Threat.c initialize.c Own_Above_Threat.c ALIM.c Inhibit_Biased_Climb.c  test_alt_sep_test.c  -I . && ./test" --verbose --prefix "Own_Below_Threat"

mutate Own_Above_Threat.c --cmd "clang -c MUTANT -I ."
analyze_mutants Own_Above_Threat.c "gcc -o test alt_sep_test.c Non_Crossing_Biased_Climb.c Non_Crossing_Biased_Descend.c Own_Below_Threat.c initialize.c Own_Above_Threat.c ALIM.c Inhibit_Biased_Climb.c  test_alt_sep_test.c  -I . && ./test" --verbose --prefix "Own_Above_Threat"

mutate ALIM.c --cmd "clang -c MUTANT -I ."
analyze_mutants ALIM.c "gcc -o test alt_sep_test.c Non_Crossing_Biased_Climb.c Non_Crossing_Biased_Descend.c Own_Below_Threat.c Own_Above_Threat.c initialize.c ALIM.c Inhibit_Biased_Climb.c  test_alt_sep_test.c  -I . && ./test" --verbose --prefix "ALIM"

mutate Inhibit_Biased_Climb.c --cmd "clang -c MUTANT -I ."
analyze_mutants Inhibit_Biased_Climb.c "gcc -o test alt_sep_test.c Non_Crossing_Biased_Climb.c Non_Crossing_Biased_Descend.c Own_Below_Threat.c initialize.c Own_Above_Threat.c ALIM.c Inhibit_Biased_Climb.c  test_alt_sep_test.c  -I . && ./test" --verbose --prefix "Inhibit_Biased_Climb"