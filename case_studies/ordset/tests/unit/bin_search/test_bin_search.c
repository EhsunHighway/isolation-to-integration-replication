#include "bin_search.h"

void test_bin_search(ord_set *a_set, int num_of_element, int element, int expected){
    int result = bin_search(a_set, num_of_element, element);

    if (result == expected){
        printf("Test passed. \n");
    } else {
        printf("Test failed. \n");
        // exit(1); // use this for mutation analysis
    }
}

// Test 1
void test_1() {
    printf("Test 1: ");
    ord_set set1;
    int initial_elements1[] = {1, 2, 3, 4};
    int initial_size1 = sizeof(initial_elements1);

    init_set_array(&set1, initial_elements1, initial_size1);
    test_bin_search(&set1, 4, 4, 3);
}

// Test 2
void test_2(){
    printf("Test 2: ");
    ord_set set2;
    int initial_elements2[] = {1, 2, 3, 4};
    int initial_size2 = sizeof(initial_elements2);

    init_set_array(&set2, initial_elements2, initial_size2);
    test_bin_search(&set2, 4, 1, 0);
}

// Test 3
void test_3(){
    printf("Test 3: ");
    ord_set set3;
    int initial_elements3[] = {1, 2, 3, 4};
    int initial_size3 = sizeof(initial_elements3);

    init_set_array(&set3, initial_elements3, initial_size3);
    test_bin_search(&set3, 0,  1, -1);
}

// Test 4
void test_4(){
    printf("Test 4: ");
    ord_set set4;
    int initial_elements4[] = {1, 2, 3, 4};
    int initial_size4 = sizeof(initial_elements4);

    init_set_array(&set4, initial_elements4, initial_size4);
    test_bin_search(&set4, 4,  5, -1);
}

// Test 5
void test_5(){
    printf("Test 5: ");
    ord_set set5;
    int initial_elements5[] = {1, 2, 3, 5};
    int initial_size5 = sizeof(initial_elements5);

    init_set_array(&set5, initial_elements5, initial_size5);
    test_bin_search(&set5, 4,  4, -1);
}

int main(){
    printf("Unit test for bin_search():\n");
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();

    return 0;
}


