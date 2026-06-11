#include "is_over_flow.h"

void test_is_over_flow(ord_set *a_set, bool expected){
    bool result = is_over_flow(a_set);
    if (result == expected) {
        printf("Test passed. \n");
    } else {
        printf("Test failed. \n");
        // exit(1); // use this for mutation analysis
    }
}

// Test 1
void test_1(){
    ord_set set1;
    init_set_array(&set1, (int[]){1,2,3,4}, 4);
    set1._overflow = true;
    test_is_over_flow(&set1, true);
}

int main(){
    printf("Unit test is_over_flow(): \n");
    test_1();
}

