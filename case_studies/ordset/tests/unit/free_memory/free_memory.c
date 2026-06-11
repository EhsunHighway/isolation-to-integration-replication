#include "free_memory.h"

void free_memory(ord_set *a_set) {
    free(a_set->_set_elements);
    a_set->_set_elements = NULL;
}
