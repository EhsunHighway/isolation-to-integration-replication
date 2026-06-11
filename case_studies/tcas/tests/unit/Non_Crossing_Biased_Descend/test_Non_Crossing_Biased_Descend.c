#include "Non_Crossing_Biased_Descend.h"
#include "tcas.h"
#include "Inhibit_Biased_Climb_stub.h"
#include "Own_Below_Threat_stub.h"
#include "initialize.h"
#include "Own_Above_Threat_stub.h"

void test_Non_Crossing_Biased_Descend(bool expected){
    reset_count_Above();
    reset_count();
    initialize();
    bool result = Non_Crossing_Biased_Descend();

    if (result == expected){
        printf("Test passed.\n");
    } else {
        printf("Test failed.\n");
        // exit(1); // use this for mutation analysis
    }
}

void test_1() {
    printf("Test 1: \n");
    Down_Separation = 400;
    Cur_Vertical_Sep = 300;
    set_Biased_climb(401);
    set_Below_Threat(1, 0);
    Alt_Layer_Value = 0;
    test_Non_Crossing_Biased_Descend(1);
}

void test_2() {
    printf("Test 2: \n");
    Down_Separation = 400;
    Cur_Vertical_Sep = 300;
    set_Biased_climb(401);
    set_Below_Threat(0, 0);
    Alt_Layer_Value = 0;
    test_Non_Crossing_Biased_Descend(0);
}

void test_3() {
    printf("Test 3: \n");
    Down_Separation = 400;
    Cur_Vertical_Sep = 299;
    set_Biased_climb(401);
    set_Below_Threat(1, 0);
    Alt_Layer_Value = 0;
    test_Non_Crossing_Biased_Descend(0);
}

void test_4() {
    printf("Test 4: \n");
    Down_Separation = 399;
    Cur_Vertical_Sep = 300;
    set_Biased_climb(401);
    set_Below_Threat(1, 0);
    Alt_Layer_Value = 0;
    test_Non_Crossing_Biased_Descend(0);
}

void test_5() {
    printf("Test 5: \n");
    Down_Separation = 399;
    Up_Separation = 400;
    set_Biased_climb(298);
    set_Above_Threat(0, 0);
    Alt_Layer_Value = 0;
    test_Non_Crossing_Biased_Descend(1);
}

void test_6() {
    printf("Test 6: \n");
    Down_Separation = 399;
    Up_Separation = 400;
    set_Biased_climb(298);
    set_Above_Threat(1, 1);
    Alt_Layer_Value = 0;
    test_Non_Crossing_Biased_Descend(1);
}

void test_7() {
    printf("Test 7: \n");
    Down_Separation = 399;
    Up_Separation = 400;
    set_Biased_climb(298);
    set_Above_Threat(1, 0);
    Alt_Layer_Value = 0;
    test_Non_Crossing_Biased_Descend(1);
}

// void test_8() {
//     printf("Test 8: \n");
//     Down_Separation = 399;
//     Up_Separation = 399;
//     set_Biased_climb(298);
//     set_Above_Threat(1, 1);
//     Alt_Layer_Value = 0;
//     test_Non_Crossing_Biased_Descend(0);
// }

int main(){
    printf("Unit test for Non_Crossing_Biased_Descend() with stubs: \n");
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
    test_7();
}