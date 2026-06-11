#include "ord_set.h"
#include "init_set_array.h"
#include "remove_element.h"
#include "free_memory.h"

void test_remove_element(ord_set *set, int element, bool expected, const int *expected_set) {
    bool result = remove_element(set, element);

    bool set_mismatch = false;
    for (int i = 0; i <= set->_last; i++) {
        if (expected_set[i] != set->_set_elements[i]) {
            printf("\nTest Failed (Element mismatch at index %d).\n", i);
            // exit(1); // use this for mutation analysis
            set_mismatch = true;
            break;
        }
    }

    if (result != expected) {
        printf("\nTest Failed (Result mismatch).\n");
        // exit(1); // use this for mutation analysis
    } else if (!set_mismatch) {
        printf("\nTest Passed.\n");
    }
    free_memory(set);
}

//Test 1
void test_1(){
    printf("\nTest 1: ");
    ord_set set1;
    int initial_elements1[6] = {1, 2, 3, 4, 5, 6};
    init_set_array(&set1, initial_elements1, 6);
    test_remove_element(&set1, 4, true, (int[]){1,2,3,5,6});
}

//Test 2
void test_2(){
    printf("\nTest 2: ");
    ord_set set2;
    int initial_elements2[6] = {1, 2, 3, 4, 5, 6};
    init_set_array(&set2, initial_elements2, 6);
    set2._overflow = true;
    test_remove_element(&set2, 6, false, (int[]){1,2, 3, 4, 5, 6});
}

//Test 3
void test_3(){
    printf("\nTest 3: ");
    ord_set set3;
    int initial_elements3[6] = {1, 2, 3, 4, 5, 6};
    init_set_array(&set3, initial_elements3, 6);
    test_remove_element(&set3, 7, false, (int[]){1,2,3,4,5,6});
}

int main() {
    // Unit test for remove_element()
    printf("\nUnit test for remove_element():\n");

    //Test 1
    test_1();

    //Test 2
    test_2();

    //Test 3
    test_3();
}