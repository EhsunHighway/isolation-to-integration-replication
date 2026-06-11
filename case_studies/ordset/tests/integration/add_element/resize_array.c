#include "resize_array.h"

void resize_array(ord_set *a_set) {
    int new_size = a_set->_set_size + MIN_SET_SIZE;

    if (a_set->_resized_times >= MAX_ACCEPTED_RESIZES || a_set->_set_size >= MAX_SET_SIZE) {
        a_set->_overflow = true;
        return;
    }

    if (new_size > MAX_SET_SIZE) {
        new_size = MAX_SET_SIZE;
    }

    int *new_elements = (int *) realloc(a_set->_set_elements, new_size * sizeof(int));
    if (new_elements == NULL) {
        printf("Memory allocation for new set failed");
        exit(1);
    }

    a_set->_set_elements = new_elements;
    a_set->_set_size = new_size;
    a_set->_resized_times++;
}
