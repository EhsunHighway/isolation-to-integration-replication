#include "alt_sep_test.h"
#include "tcas.h"
#include "initialize.h"


void test_alt_sep_test(int expected)
{
    // reset_count();
    // reset_count_Above();
        initialize();

    int result = alt_sep_test();

    if (result == expected){
        printf("Test passed.\n");
    } else {
        printf("Test failed.\n");
        // exit(1); // use this for mutation analysis
    }
}

void test_1() {
    printf("Test 1: \n");

    // enabled = 1
    High_Confidence = 1;
    Own_Tracked_Alt_Rate = 600;
    Cur_Vertical_Sep = 601;

    // tcas_equipped = 1
    Other_Capability = 1;

    //intent_not_known = 1
    Two_of_Three_Reports_Valid = 1;
    Other_RAC = 0;


    //descend = 1
    // need_upward_RA = 1;
    Down_Separation = 1000;
    Up_Separation = 400;

    //Own_Above_Threat = 1
    Own_Tracked_Alt = 1;
    Other_Tracked_Alt = 0;

    // ALIM = 400
    Alt_Layer_Value = 0;

    // down RA
    test_alt_sep_test(2);
}


void test_4() {
    printf("Test 4: \n");

    // enabled = 1
    High_Confidence = 1;
    Own_Tracked_Alt_Rate = 600;
    Cur_Vertical_Sep = 601;

    // tcas_equipped = 1
    Other_Capability = 1;

    //intent_not_known = 1
    Two_of_Three_Reports_Valid = 1;
    Other_RAC = 0;

    //climb ==1 
   // upward_preferred = 1
    Climb_Inhibit = 1;
    Down_Separation = 0;

    //Own_Below_Threat = 0
    Own_Tracked_Alt = 0;
    Other_Tracked_Alt = 1;

    // ALIM = 400
    Alt_Layer_Value = 0;

    // upward
    test_alt_sep_test(1);
}

void test_5() {
    printf("Test 5: \n");

    // enabled = 1
    High_Confidence = 1;
    Own_Tracked_Alt_Rate = 600;
    Cur_Vertical_Sep = 601;

    // tcas_equipped = 0
    Other_Capability = 0;

    //intent_not_known = 1
    Two_of_Three_Reports_Valid = 1;
    Other_RAC = 0;

    //descend = 1
    // need_upward_RA = 1;
    Down_Separation = 1000;
    Up_Separation = 400;

    //Own_Above_Threat = 1
    Own_Tracked_Alt = 0;
    Other_Tracked_Alt = 1;

    // ALIM = 400
    Alt_Layer_Value = 0;

    // UPWARD_RA
    test_alt_sep_test(0);
}
void test_2() {
    printf("Test 2: \n");

    // enabled = 0
    High_Confidence = 0;
    Own_Tracked_Alt_Rate = 600;
    Cur_Vertical_Sep = 601;

    // tcas_equipped = 1
    Other_Capability = 1;

    //intent_not_known = 1
    Two_of_Three_Reports_Valid = 1;
    Other_RAC = 0;



    // UNRESOLVED
    test_alt_sep_test(0);
}

void test_3() {
    printf("Test 3: \n");

    // enabled = 1
    High_Confidence = 1;
    Own_Tracked_Alt_Rate = 601;
    Cur_Vertical_Sep = 601;

    // tcas_equipped = 1
    Other_Capability = 1;

    //intent_not_known = 0
    Two_of_Three_Reports_Valid = 0;
    Other_RAC = 1;


    // UNRESOLVED
    test_alt_sep_test(0);
}

void test_6() {
    printf("Test 6: \n");

    // enabled = 1
    High_Confidence = 1;
    Own_Tracked_Alt_Rate = 600;
    Cur_Vertical_Sep = 601;

    // tcas_equipped = 0
    Other_Capability = 0;

    //intent_not_known = 1
    Two_of_Three_Reports_Valid = 1;
    Other_RAC = 1;


    test_alt_sep_test(0);
}

void test_7() {
    printf("Test 7: \n");

    // enabled = 1
    High_Confidence = 1;
    Own_Tracked_Alt_Rate = 600;
    Cur_Vertical_Sep = 601;

    // tcas_equipped = 1
    Other_Capability = 1;

    //intent_not_known = 1
    Two_of_Three_Reports_Valid = 0;
    Other_RAC = 1;

    // // need_upward_RA = 1;
    // set_Biased_Climb(1);
    // set_Below_Threat(1, 0);

    // // need_downward_RA = 1;
    // set_Biased_Descend(1);
    // set_Above_Threat(1, 0);

    // UNRESOLVED
    test_alt_sep_test(0);
}

void test_8() {
    printf("Test 8: \n");

    // enabled = 1
    High_Confidence = 1;
    Own_Tracked_Alt_Rate = 600;
    Cur_Vertical_Sep = 601;

    // tcas_equipped = 0
    Other_Capability = 0;

    //intent_not_known = 1
    Two_of_Three_Reports_Valid = 1;
    Other_RAC = 0;

    // // need_upward_RA = 0;
    // set_Biased_Climb(0);
    // set_Below_Threat(1, 0);

    // // need_downward_RA = 1;
    // set_Biased_Descend(1);
    // set_Above_Threat(1, 0);

    // DOWNWARD_RA
    test_alt_sep_test(2);
}

void test_9() {
    printf("Test 9: \n");

    // enabled = 1
    High_Confidence = 1;
    Own_Tracked_Alt_Rate = 600;
    Cur_Vertical_Sep = 601;

    // tcas_equipped = 0
    Other_Capability = 0;

    //intent_not_known = 1
    Two_of_Three_Reports_Valid = 1;
    Other_RAC = 0;

    // // need_upward_RA = 1;
    // set_Biased_Climb(1);
    // set_Below_Threat(1, 0);

    // // need_downward_RA = 0;
    // set_Biased_Descend(1);
    // set_Above_Threat(0, 0);

    // UPWARD_RA
    test_alt_sep_test(1);
}

void test_10() {
    printf("Test 10: \n");

    // enabled = 1
    High_Confidence = 1;
    Own_Tracked_Alt_Rate = 600;
    Cur_Vertical_Sep = 601;

    // tcas_equipped = 0
    Other_Capability = 0;

    //intent_not_known = 1
    Two_of_Three_Reports_Valid = 1;
    Other_RAC = 0;

    // // need_upward_RA = 0;
    // set_Biased_Climb(1);
    // set_Below_Threat(0, 0);

    // // need_downward_RA = 1;
    // set_Biased_Descend(1);
    // set_Above_Threat(1, 0);

    // DOWNWARD_RA
    test_alt_sep_test(2);
}

void test_11() {
    printf("Test 11: \n");

    // enabled = 1
    High_Confidence = 1;
    Own_Tracked_Alt_Rate = 600;
    Cur_Vertical_Sep = 601;

    // tcas_equipped = 0
    Other_Capability = 0;

    //intent_not_known = 1
    Two_of_Three_Reports_Valid = 1;
    Other_RAC = 0;

    // need_upward_RA = 0;
    // set_Biased_Climb(1);
    // set_Below_Threat(0, 0);

    // // need_downward_RA = 0;
    // set_Biased_Descend(1);
    // set_Above_Threat(0, 0);

    // DOWNWARD_RA
    test_alt_sep_test(0);
}

int main() {
    printf("Integration test for alt_sep_test(): \n");
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
}
