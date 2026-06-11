#include "are_equals.h"
#include "init_set_array.h"
#include "ord_set.h"


void test_are_equals(ord_set *a_set, ord_set *set_to_compare, int expected) {
    int result = are_equals(a_set, set_to_compare);
    if (result == expected) {
        printf("Test passed.\n");
    } else {
        printf("Test failed. Expected %d but got %d.\n", expected, result);
        // exit(1); // use this for mutation analysis
    }
}

// Test 1
void test_1() {
    printf("Test 1: \n");

    ord_set set1;
    int elements1[] = {1, 2, 3, 7};
    init_set_array(&set1, elements1, 4);

    ord_set c_set1;
    int c_elements1[] = {1, 2, 3, 7};
    init_set_array(&c_set1, c_elements1, 4);

    // Run the test
    test_are_equals(&set1, &c_set1, 0);

    // Reset the context after the test
}

// Test 2
void test_2() {
    printf("Test 2: \n");
    ord_set set2;
    int elements2[] = {1, 2, 3, 7};
    init_set_array(&set2, elements2, 4);

    ord_set c_set2;
    int c_elements2[] = {1, 2, 3, 7, 8};
    init_set_array(&c_set2, c_elements2, 5);

    test_are_equals(&set2, &c_set2, -1);  // Different size: |4 - 5| = 1
}

// Test 3
void test_3() {
    printf("Test 3: \n");
    ord_set set3;
    int elements3[] = {};
    init_set_array(&set3, elements3, 0);
    ord_set c_set3;
    int c_elements3[] = {};
    init_set_array(&c_set3, c_elements3, 0);

    test_are_equals(&set3, &c_set3, 0);  // Both empty
}

// Test 4: same size but different elements
void test_4() {
    printf("Test 4: \n");
    ord_set set4;
    int elements4[] = {1, 2, 3, 7};
    init_set_array(&set4, elements4, 4);

    ord_set c_set4;
    int c_elements4[] = {4, 5, 6, 8};
    init_set_array(&c_set4, c_elements4, 4);


    test_are_equals(&set4, &c_set4, 1);  // Expected to fail since elements differ
}

// Test 5
void test_5() {
    printf("Test 5: \n");
    ord_set set5;
    int elements5[] = {};
    init_set_array(&set5, elements5, 0);

    ord_set c_set5;
    int c_elements5[] = {1,2,3};
    init_set_array(&c_set5, c_elements5, 3);

    test_are_equals(&set5, &c_set5, -3);  // Different sizes: _last=-1 vs _last=2, returns -1-2=-3
}



int main() {
    printf("Unit test are_equals with stub: \n");
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    return 0;
}
