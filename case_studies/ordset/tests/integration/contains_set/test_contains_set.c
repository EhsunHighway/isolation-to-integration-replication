#include "ord_set.h"
#include "contains_set.h"
#include "init_set_array.h"

void test_contains_set(ord_set *a_set, ord_set *s_set, bool expected){
    bool result = contains_set(a_set, s_set);

    if (result == expected){
        printf("Test passed. \n");
    } else {
        printf("Test failed. \n");
        // exit(1); // use this for mutation analysis
    }
}

// Test 1
void test_1(){
    printf("Test 1: ");
    ord_set set1;
    int elements1[] = {1, 2, 3, 7, 8, 9, 10, 11};
    init_set_array(&set1, elements1, 8);

    ord_set s_set1;
    int s_elements[] = {2, 3, 7};
    init_set_array(&s_set1, s_elements, 3);

    test_contains_set(&set1, &s_set1, true);
}

//Test 2
void test_2(){
    printf("Test 2: ");
    ord_set set2;
    int elements2[] = {1, 2, 3, 7, 8 , 9, 10, 11, 8};
    init_set_array(&set2, elements2, 9);

    ord_set s_set2;
    int s_elements[] = { 6, 132, 144, 155};
    init_set_array(&s_set2, s_elements, 4);

    test_contains_set(&set2, &s_set2, false);
}

int main(){
    printf("Unit test for contains_set() with stubs: \n");
    test_1();
    test_2();
}


