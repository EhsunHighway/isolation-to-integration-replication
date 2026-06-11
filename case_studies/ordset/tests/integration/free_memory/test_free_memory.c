#include "free_memory.h"

void test_free_memory(ord_set *a_set){
    free_memory(a_set);

    if (a_set->_set_elements == NULL) {
        printf("Test passed. \n");
    } else {
        printf("Test failed. \n");
        // exit(1); // use this for mutation analysis
    }
}

// Test 1
void test_1(){
    printf("Test 1: \n");
    ord_set set1;
    init_set_array(&set1, (int[]){1,2,3,4}, 4);
    test_free_memory(&set1);
}

int main(){
    test_1();
    return 0;
}