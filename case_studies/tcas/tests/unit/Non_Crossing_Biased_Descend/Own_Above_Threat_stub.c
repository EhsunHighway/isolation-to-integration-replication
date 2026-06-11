#include "Own_Above_Threat_stub.h"

static bool return_value1;
static bool return_value2;

static int count = 0;

void set_Above_Threat(bool r1, bool r2){
    return_value1 = r1;
    return_value2 = r2;
}

bool Own_Above_Threat()
{
    count++;
    switch (count) {
        case 1:
            return return_value1;
        case 2:
            return return_value2; // Flip the value on the second call (example logic)
        default:
            return 0; // Default safe behavior for unexpected cases
    }
}

void reset_count_Above(){
    count = 0;
}