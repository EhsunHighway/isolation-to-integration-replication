#include "realloc_failure.h"
#include "resize_array.h"
#include "init_set_array.h"
#include "free_memory.h"

// Unit test for resize_array()
void test_resize_array(ord_set *set, int expected_new_size, int expected_resized_times, bool expected_overflow) {
    resize_array(set);

    bool passed = true;

    if (set->_set_size != expected_new_size ||
        set->_resized_times != expected_resized_times ||
        set->_overflow != expected_overflow) {
        passed = false;
    }

    if (passed) {
        printf("Test Passed.\n");
    } else {
        printf("Test Failed.\n");
        // exit(1); // use this for mutation analysis
    }
    free_memory(set);
}

// Test 1: Normal resize
void test_1(){
    // Test 1:
    ord_set set1;
    int initial_elements1[] = {1, 2, 3, 4};
    init_set_array(&set1, initial_elements1, 4);
    test_resize_array(&set1, 8, 1, false);
}

// Test 2: Resize that causes overflow
void test_2(){
    ord_set set2;
    int initial_elements2[] = {1, 2, 3, 4, 5, 6, 7, 8};
    init_set_array(&set2, initial_elements2, 8);
    set2._resized_times = 2; // Already resized twice
    test_resize_array(&set2, 8, 2, true); // No resize, just set overflow
}

// Test 3: Resize at max size
void test_3(){
    ord_set set3;
    int initial_elements3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    init_set_array(&set3, initial_elements3, 16);
    test_resize_array(&set3, 16, 0, true); // Should not resize, just set overflow
}

// Test 4: new_size > MAX_SET_SIZE condition
void test_4(){
    ord_set my_set;
    my_set._set_elements = (int *)malloc(16 * sizeof(int));
    my_set._set_size = 16;
    my_set._resized_times = 0;
    my_set._overflow = false;
    my_set._set_size = MAX_SET_SIZE - MIN_SET_SIZE + 1;
    test_resize_array(&my_set, MAX_SET_SIZE, 1, false);
}

// Test 5: Malloc Failure
void test_5(){
    ord_set set5;
    int initial_elements5[] = {1, 2, 3, 4};
    init_set_array(&set5, initial_elements5, 4);

    enable_test_realloc(1,1);
    resize_array(&set5);
    bool passed = true;

    if (set5._set_size != 8 ||
        set5._resized_times != 1 ||
        set5._overflow != false) {
        passed = false;
    }

    if (passed) {
        printf("Test Passed.\n");
    } else {
        printf("Test Failed.\n");
        // exit(1); // use this for mutation analysis
    }
    enable_test_realloc(0, -1);

    free_memory(&set5);
}

int main(){
    printf("\nUnit test for resize_array():\n");
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
}