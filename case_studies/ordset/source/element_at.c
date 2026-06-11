#include "element_at.h"

int element_at(ord_set *a_set, int where) {
    if ((where < 0) || (where > a_set->_last)) {
        printf("Out of bound element: %d\n", where);
        return -1;
    }
    return a_set->_set_elements[where];
}
