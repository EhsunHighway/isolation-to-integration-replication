#include "def_set_size.h"

int def_set_size(int size) {
    if (size <= MIN_SET_SIZE) return MIN_SET_SIZE;
    if (size >= MAX_SET_SIZE) return MAX_SET_SIZE;

    int mod = size / MIN_SET_SIZE;
    if (mod * MIN_SET_SIZE == size) {
        return size;
    } else {
        return (mod + 1) * MIN_SET_SIZE;
    }
}

