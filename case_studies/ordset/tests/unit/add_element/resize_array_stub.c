#include "resize_array_stub.h"

static int resized_array_resized_times;
static int resized_array_set_size;
static bool resized_array_overflow;
static int resized_array_last;


void set_resize_array(int resized_times, int resized_set_size, bool resized_overflow, int resized_last) {
    resized_array_resized_times = resized_times;
    resized_array_set_size = resized_set_size;
    resized_array_overflow = resized_overflow;
    resized_array_last = resized_last;

}

void resize_array(ord_set *a_set) {
    a_set->_set_size = resized_array_set_size;
    a_set->_resized_times = resized_array_resized_times + 1;
    a_set->_overflow = resized_array_overflow;
    a_set->_last = resized_array_last;
}
