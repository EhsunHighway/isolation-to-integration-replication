#include "init_set_array.h"


void init_set_array(ord_set *a_set, const int *elements, int init_num_elements) {
    a_set->_set_size = def_set_size(init_num_elements);
    a_set->_set_elements = (int *)malloc(a_set->_set_size * sizeof(int));

    if (a_set->_set_elements == NULL) {
        printf("Memory allocation for the set failed. Initialization incomplete.\n");
        a_set->_set_size = 0;
        a_set->_set_elements = NULL;
        a_set->_last = -1;
        return;
    }

    a_set->_last = -1;
    a_set->_resized_times = 0;
    a_set->_overflow = false;

    for (int k = 0; k < init_num_elements && k < a_set->_set_size; k++) {
        a_set->_set_elements[k] = elements[k];
        a_set->_last = k;
    }

    if (init_num_elements > a_set->_set_size) {
        a_set->_overflow = true;
        printf("Array is too big. Only the first %d elements were added.\n", a_set->_set_size);
    }
}

