#include "def_set_size_stub.h"

static int set_size;

void set_array_size(int size){
    set_size = size;
}

int def_set_size(int size) {
    return set_size;
}

