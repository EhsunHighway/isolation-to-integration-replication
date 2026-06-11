#include "is_empty.h"

void test_is_empty(ord_set *a_set, bool expected){
    bool result = is_empty(a_set);
    if (result == expected) {
        printf("Test passed. \n");
    } else {
        printf("Test failed. \n");
        // exit(1); // use this for mutation analysis
    }
}

// Test 1
void test_1(){
    printf("Test 1: \n");
    ord_set set1;

    test_is_empty(&set1, true);
}

int main(){
    printf("Unit test is_empty(): \n");
    test_1();
    return 0;
}
