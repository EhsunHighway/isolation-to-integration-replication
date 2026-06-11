#include "element_at_stub.h"

int *stub_values = NULL;
int stub_index = 0;
int num_values = 0;

void set_element_at_results(int *preset_values, int num_of_values) {
    stub_values = preset_values;
    num_values = num_of_values;
    stub_index = 0;
}


int element_at(ord_set *a_set, int where) {
    int value = stub_values[stub_index];

    stub_index++;

    if (stub_index >= num_values) {
        stub_index = 0;
    }

    return value;
}

