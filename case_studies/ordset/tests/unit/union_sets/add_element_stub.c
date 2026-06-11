#include "add_element_stub.h"

static ord_set set_added_element;

void set_with_added_element(int *a_set, int last_index) {
    set_added_element._set_elements = a_set;
    set_added_element._last = last_index;
}

void add_element(ord_set *a_set, int element) {
    a_set->_set_elements = set_added_element._set_elements;
    a_set->_last = set_added_element._last;
}
