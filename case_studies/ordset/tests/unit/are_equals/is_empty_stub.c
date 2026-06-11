#include "is_empty_stub.h"

static bool* return_values = NULL;
static int call_count = 0;
static int current_index = 0;

void set_is_empty_return_values(bool* values, int count) {
    return_values = values;
    call_count = count;
    current_index = 0;
}

bool is_empty(ord_set *a_set) {
    if (return_values != NULL && current_index < call_count) {
        return return_values[current_index++];
    }
    return false;
}
