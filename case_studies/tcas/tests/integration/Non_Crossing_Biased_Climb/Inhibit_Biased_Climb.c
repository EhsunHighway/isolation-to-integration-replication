#include "Inhibit_Biased_Climb.h"

int Inhibit_Biased_Climb ()
{
    return (Climb_Inhibit ? Up_Separation + NOZCROSS : Up_Separation);
}