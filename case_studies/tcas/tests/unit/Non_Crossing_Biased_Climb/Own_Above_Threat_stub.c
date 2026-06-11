#include "Own_Above_Threat_stub.h"

static bool return_value;

void set_Above_Threat(bool r){
    return_value = r;
}

bool Own_Above_Threat()
{
    return return_value;
}
