#include "contains_number_stub.h"

static bool returned_bool;

void does_contain_number(bool b){
    returned_bool = b;
}
bool contains_number(ord_set *a_set, int n) {
    return returned_bool;
}

