#include "malloc_failure.h"
#include "init_set_array.h"
#include "free_memory.h"
#include "def_set_size.h"

// Unit test for init_set_array()
void test_init_set_array(ord_set *set, const int *elements, int size, const int *expected, int expected_size) {
    init_set_array(set, elements, size);

    bool passed = true;

    for (int i = 0; i <= set->_last; ++i) {
        if (set->_set_elements[i] != expected[i]) {
            passed = false;
            break;
        }
    }
    if (passed) {
        printf("Test Passed.\n");
    } else {
        printf("Test Failed.\n");
        // exit(1); // use this for mutation analysis
    }
    free_memory(set);
}


// Test 1
void test_1() {
    printf("\nTest 1: \n");
    int elements1[9] = {2, 1, 3, 4, 5, 6, 7, 8, 9};
    ord_set set1;
    int expected1[9] = {2, 1, 3, 4, 5, 6, 7, 8, 9};
    test_init_set_array(&set1, elements1, 9, expected1, 9);
}

// Test 2
void test_2() {
    printf("\nTest 2: \n");
    int elements2[0] = {}; // No elements
    ord_set set2;

    int expected2[0] = {}; // Expected result
    test_init_set_array(&set2, elements2, 0, expected2, 0);
}

// Test 3
void test_3() {
    printf("\nTest 3: \n");
    int elements3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    ord_set set3;

    int expected3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    test_init_set_array(&set3, elements3, 17, expected3, 16);
}

// Test 4
void test_4() {
    printf("\nTest 4: malloc failure \n");
    // exit(1); // use this for mutation analysis

    int elements4[] = {};
    ord_set set4;

    int expected4[0] = {};
    enable_test_malloc(1,1);
    test_init_set_array(&set4, elements4, 0, expected4, 0);
    enable_test_malloc(0,-1);
}

int main(){
    printf("\nIntegration test for init_set_array(ord_set _set , size): \n");
    test_1();
    test_2();
    test_3();
    test_4();
}
