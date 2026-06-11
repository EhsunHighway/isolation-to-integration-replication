#include "contains_number.h"

bool contains_number(ord_set *a_set, int n) {
    return bin_search(a_set, a_set->_last + 1, n) >= 0;
}

