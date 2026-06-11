#include "def_set_size.h"
#include "ord_set.h"

void test_def_set_size(int n, int expected) {
    if (def_set_size(n) == expected) {
        printf("Test Passed.\n");
    } else {
        printf("Test failed.\n");
        // exit(1); // use this for mutation analysis
    }
}

// test 1
void test_1() {
    test_def_set_size(3, 4);
}

// test 2
void test_2() {
    test_def_set_size(4, 4);
}

// test 3
void test_3() {
    test_def_set_size(16, 16);
}

// test 4
void test_4() {
    test_def_set_size(17, 16);
}

// test 5
void test_5() {
    test_def_set_size(5, 8);
}

// test 6
void test_6() {
    test_def_set_size(6, 8);
}

// test 7
void test_7() {
    test_def_set_size(8, 8);
}

int main(){
    // Unit test for def_set_size()
    printf("Unit test for def_set_size(size):\n");
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
    test_7();

}

