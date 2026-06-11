#include "are_equals.h"

int are_equals(ord_set *a_set, ord_set *set_to_compare) {
    if (a_set->_last != set_to_compare->_last) {
        return a_set->_last - set_to_compare->_last;
    }

    if (is_empty(a_set) && is_empty(set_to_compare)) {
        return 0;
    }

    for (int n = 0; n <= a_set->_last; n++) {
        int element_a = element_at(a_set, n);
        int element_b = element_at(set_to_compare, n);
        if (element_a != element_b) {
            return 1;
        }
    }

    return 0;
}
