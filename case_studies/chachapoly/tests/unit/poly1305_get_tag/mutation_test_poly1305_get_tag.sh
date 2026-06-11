#!/bin/bash

# Mutate the test file (assuming 'mutate' tool is available)
mutate poly1305_get_tag.c --cmd "clang -c MUTANT -I ."

# Analyze the mutants
analyze_mutants poly1305_get_tag.c "gcc -o test test_poly1305_get_tag_with_stub.c poly1305_get_tag.c poly1305_init_stub.c poly1305_update_stub.c poly1305_finish_stub.c -I . && ./test" --verbose