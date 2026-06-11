#include "Non_Crossing_Biased_Descend_stub.h"

static bool return_value;

void set_Biased_Descend(bool r){
    return_value = r;
}

bool Non_Crossing_Biased_Descend()
{
    return return_value;
}