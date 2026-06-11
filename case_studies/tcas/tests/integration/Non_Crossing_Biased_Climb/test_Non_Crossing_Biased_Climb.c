#include "Non_Crossing_Biased_Climb.h"
#include "initialize.h"
#include "tcas.h"



void test_Non_Crossing_Biased_Climb(bool expected){
    initialize();
    bool result = Non_Crossing_Biased_Climb();

    if (result == expected){
        printf("Test passed.\n");
    } else {
        printf("Test failed.\n");
        // exit(1); // use this for mutation analysis
    }
}

void test_1() {
    printf("Test 1: \n");

    // upward_preferred = 1
    Climb_Inhibit = 1;
    Down_Separation = 0;

    //Own_Below_Threat = 0
    Own_Tracked_Alt = 1;
    Other_Tracked_Alt = 0;

    // ALIM = 400
    Alt_Layer_Value = 0;

    test_Non_Crossing_Biased_Climb(1);
}

void test_2() {
    printf("Test 2: \n");

    // upward_preferred = 1
    Climb_Inhibit = 1;
    Down_Separation = 309;

    //Own_Below_Threat = 1
    Own_Tracked_Alt = 1;
    Other_Tracked_Alt = 0;

    // ALIM = 400
    Alt_Layer_Value = 0;

    test_Non_Crossing_Biased_Climb(0);
}

void test_3() {
    printf("Test 3: \n");

    // upward_preferred = 1
    Climb_Inhibit = 1;
    Up_Separation = 302;
    Down_Separation = 400;

    //Own_Below_Threat = 1
    Own_Tracked_Alt = 0;
    Other_Tracked_Alt = 1;

    // ALIM = 400
    Alt_Layer_Value = 0;

    test_Non_Crossing_Biased_Climb(0);
}



// void test_4() {
//     printf("Test 4: \n");

//     // upward_preferred = 0
//     Climb_Inhibit = 0;
//     Up_Separation = 400;
//     Down_Separation = 100;
//     Cur_Vertical_Sep = 300;

//     //Own_Above_Threat = 1
//     Own_Tracked_Alt = 1;
//     Other_Tracked_Alt = 0;

//     // ALIM = 400
//     Alt_Layer_Value = 0;

//     test_Non_Crossing_Biased_Climb(1);
// }

void test_4() {
    printf("Test 4: \n");

    // upward_preferred = 0
    Climb_Inhibit = 0;
    Up_Separation = 400;
    Down_Separation = 5000;
    Cur_Vertical_Sep = 300;

    //Own_Above_Threat = 0
    Own_Tracked_Alt = 0;
    Other_Tracked_Alt = 1;

    // ALIM = 400
    Alt_Layer_Value = 0;

    test_Non_Crossing_Biased_Climb(0);
}

// void test_6() {
//     printf("Test 6: \n");

//     // upward_preferred = 0
//     Climb_Inhibit = 0;
//     Down_Separation = 5000;
//     Up_Separation = 400;
//     Cur_Vertical_Sep = 209;

//     //Own_Above_Threat = 1
//     Own_Tracked_Alt = 1;
//     Other_Tracked_Alt = 0;

//     // ALIM = 400
//     Alt_Layer_Value = 0;

//     test_Non_Crossing_Biased_Climb(0);
// }

void test_5() {
    printf("Test 5: \n");

    // upward_preferred = 0
    Climb_Inhibit = 0;
    Down_Separation = 5000;
    Up_Separation = 399;
    Cur_Vertical_Sep = 300;

    //Own_Above_Threat = 1
    Own_Tracked_Alt = 1;
    Other_Tracked_Alt = 0;

    // ALIM = 400
    Alt_Layer_Value = 0;

    test_Non_Crossing_Biased_Climb(0);
}

// void test_8() {
//     printf("Test 8: \n");

//     // upward_preferred = 0
//     Climb_Inhibit = 0;
//     Down_Separation = 5000;
//     Up_Separation = 399;
//     Cur_Vertical_Sep = 300;

//     //Own_Below_Threat = 1
//     Own_Tracked_Alt = 0;
//     Other_Tracked_Alt = 1;

//     // ALIM = 400
//     Alt_Layer_Value = 0;

//     test_Non_Crossing_Biased_Climb(0);
// }

int main(){
    printf("Integration test for Non_Crossing_Biased_Climb(): \n");
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();


}
