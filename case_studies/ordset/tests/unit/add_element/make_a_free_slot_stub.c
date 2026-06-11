#include "make_a_free_slot_stub.h"

static int position;
static int *new_elements;


void set_a_free_slot(int index, int *elements) {
    position = index;
    new_elements = elements;
}

int make_a_free_slot(ord_set *a_set, int element) {
    for (int i=0;i <= a_set->_last;i++)
        a_set->_set_elements[i] = new_elements[i];
    return position;
}
