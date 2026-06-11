#include "union_sets.h"

ord_set union_sets(const ord_set *a_set, const ord_set *b_set) {
    ord_set result_set;

    int a_set_size = a_set->_last + 1;
    int b_set_size = b_set->_last + 1;
    int max_size = a_set_size + b_set_size;

    result_set._set_elements = (int *)malloc(max_size * sizeof(int));
    if (result_set._set_elements == NULL) {
        // Handle memory allocation failure by returning an empty set
        printf("Memory allocation failed in union_sets.\n");
        result_set._set_size = 0;
        result_set._last = -1;
        return result_set;
    }

    result_set._set_size = max_size;
    result_set._last = -1;

    int last_element1 = 0, last_element2 = 0;

    while (last_element1 < a_set_size && last_element2 < b_set_size) {
        if (a_set->_set_elements[last_element1] < b_set->_set_elements[last_element2]) {
            add_element(&result_set, a_set->_set_elements[last_element1]);
            last_element1++;
            result_set._last++;
        } else if (b_set->_set_elements[last_element2] < a_set->_set_elements[last_element1]) {
            add_element(&result_set, b_set->_set_elements[last_element2]);
            last_element2++;
        } else {
            add_element(&result_set, a_set->_set_elements[last_element1]);
            last_element1++;
            last_element2++;
        }
    }

    while (last_element1 < a_set_size) {
        add_element(&result_set, a_set->_set_elements[last_element1]);
        last_element1++;
    }

    while (last_element2 < b_set_size) {
        add_element(&result_set, b_set->_set_elements[last_element2]);
        last_element2++;
    }

    return result_set;
}