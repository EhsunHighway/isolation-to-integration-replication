#include "contains_number.h"
#include "ord_set.h"
#include "init_set_array.h"
#include "free_memory.h"

void test_contains_number(ord_set *set, int element, bool expected) {
    bool result = contains_number(set, element);

    if (result != expected) {
        printf("Test Failed.\n");
        // exit(1); // use this for mutation analysis
    } else {
        printf("Test Passed.\n");
    }
    free_memory(set);
}

void test_1(){
    ord_set set;
    int initial_elements[6] = {1, 2, 3, 4, 5, 6};
    init_set_array(&set, initial_elements, 6);
    test_contains_number(&set, 6, true);
}

int main() {
    // Unit test for contains_number()
    printf("\nUnit test for contains_number():\n");
    //Test 1
    test_1();

}