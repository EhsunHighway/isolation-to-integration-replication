#include "make_a_free_slot.h"

void test_make_a_free_slot(ord_set *a_set, int element, int expected){
    int result = make_a_free_slot(a_set, element);

    if (result == expected){
        printf("Test passed.\n");
    } else {
        printf("Test failed.\n");
        // exit(1); // use this for mutation analysis
    }
}

void test_1(){
    ord_set set1;
    int elements1[] = {1,2,3,4,5,7};
    init_set_array(&set1, elements1,6);
    test_make_a_free_slot(&set1, 6, 5);
}

void test_2(){
    ord_set set2;
    int elements2[1];
    init_set_array(&set2, elements2,4);
    set2._last = -1;
    test_make_a_free_slot(&set2, 1, 0);
}

int main(){
    printf("Unit test for make_a_free_slot(): \n");
    test_1();
    test_2();

    return 0;
}