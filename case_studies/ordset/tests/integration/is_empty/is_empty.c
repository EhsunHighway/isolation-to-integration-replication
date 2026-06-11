#include "is_empty.h"

bool is_empty(ord_set *a_set) {
    return a_set->_last < 0;
}

