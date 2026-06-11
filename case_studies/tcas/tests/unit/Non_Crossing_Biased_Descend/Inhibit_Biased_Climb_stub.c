#include "Inhibit_Biased_Climb_stub.h"

static int return_value;

void set_Biased_climb(int r){
    return_value = r;
}

int Inhibit_Biased_Climb ()
{
    return return_value;
}