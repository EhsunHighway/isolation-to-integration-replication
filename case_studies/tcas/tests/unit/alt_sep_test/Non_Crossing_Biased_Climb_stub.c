#include "Non_Crossing_Biased_Climb_stub.h"

static bool return_value;

void set_Biased_Climb(bool r){
    return_value = r;
}

bool Non_Crossing_Biased_Climb()
{
    return return_value;
}