#include "remove_element.h"

bool remove_element(ord_set *a_set, int element) {
    if (a_set->_overflow) return false;
    int where = bin_search(a_set, a_set->_last + 1, element);
    if (where >= 0) {
        for (int k = where; k < a_set->_last; k++) {
            a_set->_set_elements[k] = a_set->_set_elements[k + 1];
        }
        a_set->_last--;
        return true;
    } else {
        return false;
    }
}

