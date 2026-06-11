#include "make_a_free_slot.h"

int make_a_free_slot(ord_set *a_set, int element) {
    int where = a_set->_last + 1;

    while ((where - 1 >= 0) && (a_set->_set_elements[where-1] > element)) {
        a_set->_set_elements[where] = a_set->_set_elements[where-1];
        where--;
    }
    return where;
}