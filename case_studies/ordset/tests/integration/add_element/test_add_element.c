#include "ord_set.h"
#include "add_element.h"
#include "init_set_array.h"

void test_add_element(ord_set *set, const int element, const int *expected, int expected_num_elmnt) {
    add_element(set, element);

    bool passed = true;

    if (set->_last + 1 != expected_num_elmnt) {
        passed = false;
    } else {
        // Check if the elements in the set are as expected
        for (int i = 0; i < expected_num_elmnt; ++i) {
            if (i >= set->_set_size || set->_set_elements[i] != expected[i]) {
                passed = false;
                break;
            }
        }
    }
    if (passed) {
        printf("Test Passed.\n");
    } else {
        printf("Test Failed.\n");
        // exit(1); // use this for mutation analysis
    }
}

// Test 1
void test_1(){
    printf("\nTest 1:\n");
    ord_set set1;
    int initial_elements1[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    init_set_array(&set1, initial_elements1, 8);
    int expected_elements1[9] = {1, 2, 3, 4, 5, 6,7, 8, 9};
    test_add_element(&set1, 9, expected_elements1, 9);
}

// Test 2
void test_2(){
    printf("\nTest 2:\n");
    ord_set set2;
    int initial_elements2[6] = {1, 2, 3, 4, 5, 6};
    init_set_array(&set2, initial_elements2, 6);
    set2._overflow = true;
    int expected_elements2[6] = {1, 2, 3, 4, 5, 6};
    test_add_element(&set2, 7, expected_elements2, 6);
}

// Test 3
void test_3(){
    printf("\nTest 3:\n");
    ord_set set3;
    int initial_elements3[6] = {1, 2, 3, 4, 5, 6};
    init_set_array(&set3, initial_elements3, 6);
    int expected_elements3[6] = {1, 2, 3, 4, 5, 6};
    test_add_element(&set3, 6, expected_elements3, 6);
}

// Test 4
void test_4(){
    printf("\nTest 4:\n");
    ord_set set4;
    int initial_elements4[4] = {1, 2, 3, 4};
    init_set_array(&set4, initial_elements4, 4);
    int expected_elements4[] = {1, 2, 3, 4, 5};
    test_add_element(&set4, 5, expected_elements4, 5);
}

// Test 5
void test_5(){
    printf("\nTest 5:\n");
    ord_set set5;
    int initial_elements5[] = {1, 2, 3, 5, 6, 7, 8, 9, 10 ,11, 12, 13};
    init_set_array(&set5, initial_elements5, 12);
    set5._resized_times = 2;
    int expected_elements5[] = {1, 2, 3, 5, 6, 7, 8, 9, 10 ,11, 12, 13};
    test_add_element(&set5, 14, expected_elements5,12);
}

// Test 6
void test_6(){
    printf("\nTest 6:\n");
    ord_set set6;
    int initial_elements6[] = {1, 2, 3, 4, 5, 6, 7, 8,9, 10 ,11, 12,13};
    init_set_array(&set6, initial_elements6, 13);
    int expected_elements6[] = {1, 2, 3, 4, 5, 6, 7, 8,9, 10 ,11, 12, 13,14};
    test_add_element(&set6, 14, expected_elements6,14);
}

int main() {
    // Unit test for add_element()
    printf("\nUnit test for add_element() with stubs:\n");


    // Test 1
    test_1();

    // Test 2
    test_2();

    // Test 3
    test_3();

    // Test 4
    // test_4();

    //Test 5
    test_5();

    //Test 6
    test_6();

    return 0;
}
