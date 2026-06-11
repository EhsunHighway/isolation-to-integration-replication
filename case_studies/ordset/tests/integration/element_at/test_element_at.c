#include "element_at.h"
#include "init_set_array.h"
#include "free_memory.h"


void test_element_at(ord_set *a_set, int where, int expected) {
    int result = element_at(a_set, where);

    if (result == expected) {
        printf("Test passed. ");
    } else {
        printf("Test failed. ");
        // exit(1); // use this for mutation analysis
    }
    free_memory(a_set);
}

void test_1(){
    ord_set set1;
    int elements1[] = {1,2,3,4,5,6};
    init_set_array(&set1, elements1, 6);
    test_element_at(&set1, 5, 6);
}

void test_2(){
    ord_set set2;
    int elements2[] = {1,2,3,4,5,6};
    init_set_array(&set2, elements2, 6);
    test_element_at(&set2, 6, -1);
}

void test_3(){
    ord_set set3;
    int elements3[] = {1,2,3,4,5,6};
    init_set_array(&set3, elements3, 6);
    test_element_at(&set3, -1, -1);
}

int main() {
    printf("Unit test for element_at(): \n");
    test_1();
    test_2();
    test_3();
}