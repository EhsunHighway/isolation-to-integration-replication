#include "bin_search.h"

int bin_search(ord_set *a_set, int number_of_element, int x) {
    int i = 0;
    int j = number_of_element - 1;
    int middle;

    if (j < 0) return -1;

    if (a_set->_set_elements[j] < x) return -1;

    while (i < j) {
        middle = (i + j) / 2;

        if (x > a_set->_set_elements[middle]) {
            i = middle + 1;
        } else {
            j = middle; // Element found, return the index
        }
    }
    if (x == a_set->_set_elements[i]) return i;
    return -1; // Element not found
}

