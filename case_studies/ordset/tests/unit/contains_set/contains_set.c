#include "contains_set.h"

bool contains_set(ord_set *a_set, ord_set *subset) {
    for (int n = 0; n < subset->_last + 1; n++) {
        int k = element_at(subset, n);
        if (bin_search(a_set, a_set->_last + 1, k) < 0) {
            return false;
        }
    }
    return true;
}

