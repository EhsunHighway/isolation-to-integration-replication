#include "malloc_failure.h"
#include "ord_set.h"
#include "union_sets.h"
#include "add_element.h"
#include "init_set_array.h"

void test_union_sets(ord_set *a_set, ord_set *b_set, ord_set *expected_result) {
    ord_set result_set = union_sets(a_set, b_set);

    bool passed = true;
    printf("Result Set Size: %d, Expected Size: %d\n", result_set._set_size, expected_result->_set_size);

    for (int i = 0; i < expected_result->_last + 1; i++) {
        if (i > result_set._last || result_set._set_elements[i] != expected_result->_set_elements[i]) {
            printf("Mismatch at index %d: Result %d, Expected %d\n", i, (i <= result_set._last) ? result_set._set_elements[i] : -1, expected_result->_set_elements[i]);
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
}

// Test 1
void test_1() {
    printf("Test 1: ");
    ord_set set1_a;
    int elements1_a[] = {1, 2, 3};
    init_set_array(&set1_a, elements1_a, 3);

    ord_set set1_b;
    int elements1_b[] = {4, 5, 6};
    init_set_array(&set1_b, elements1_b, 3);

    ord_set expected_set1;
    int expected_elements1[] = {1, 2, 3, 4, 5, 6};
    init_set_array(&expected_set1, expected_elements1, 6);

    test_union_sets(&set1_a, &set1_b, &expected_set1);
}

// Test 2
void test_2() {
    printf("Test 2: ");
    ord_set set2_a;
    int elements2_a[] = {1, 2, 3, 7};
    init_set_array(&set2_a, elements2_a, 4);

    ord_set set2_b;
    int elements2_b[] = {3, 4, 5, 6};
    init_set_array(&set2_b, elements2_b, 4);

    ord_set expected_set2;
    int expected_elements2[] = {1, 2, 3, 4, 5, 6, 7};
    init_set_array(&expected_set2, expected_elements2, 7);

    test_union_sets(&set2_a, &set2_b, &expected_set2);
}

// Test 3
void test_3() {
    printf("Test 3: union_sets with malloc failure\n");
    // exit(1); // use this for mutation analysis

    // Prepare the input sets
    ord_set set_a;
    int elements_a[] = {1, 2, 3};
    init_set_array(&set_a, elements_a, 3);

    ord_set set_b;
    int elements_b[] = {4, 5, 6};
    init_set_array(&set_b, elements_b, 3);

    // Set up expected result for no malloc failure
    ord_set expected_result_no_failure;
    int expected_elements_no_failure[] = {1, 2, 3, 4, 5, 6};
    init_set_array(&expected_result_no_failure, expected_elements_no_failure, 6);

    // Simulate malloc failure during the union_sets call
    enable_test_malloc(1, 1);  // Fail on the first malloc call

    // Call union_sets and check result
    ord_set result_set = union_sets(&set_a, &set_b);

    // Check if the result is as expected when malloc fails
    if (result_set._set_size == 0 && result_set._last == -1) {
        printf("Test Passed: malloc failure handled correctly.\n");
        // exit(1); // use this for mutation analysis
    } else {
        printf("Test Failed: malloc failure not handled correctly.\n");
        // exit(1); // use this for mutation analysis
    }

    // Reset malloc behavior
    enable_test_malloc(0, -1);
}


int main() {
    // Unit test for union_sets()
    printf("\nUnit test for union_sets() with add_element_stub():\n");

    // Run the tests without malloc failure simulation
    test_1();
    test_2();

    // Run your tests with malloc failure simulation
    test_3();


    return 0;
}
