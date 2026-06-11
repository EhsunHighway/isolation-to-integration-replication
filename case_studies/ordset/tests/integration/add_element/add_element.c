#include "add_element.h"

void add_element(ord_set *a_set, int element) {
    if (is_over_flow(a_set)) {
        printf("Overflow: Cannot add element %d, set is in overflow state.\n", element);
        return;
    }

    if (contains_number(a_set, element)) {
        printf("Element %d is already in the set.\n", element);
        return;
    }

    if (a_set->_last + 1 >= a_set->_set_size) {
        resize_array(a_set);

        if (is_over_flow(a_set)) {
            printf("Overflow: Cannot add element %d, set is in overflow state after resizing.\n", element);
            return;
        }
    }
    int i = make_a_free_slot(a_set, element);
    a_set->_set_elements[i] = element;
    a_set->_last++;
}