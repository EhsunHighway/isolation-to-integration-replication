#include "Inhibit_Biased_Climb.h"
#include <stdio.h>
#include <stdlib.h>

void test_Inhibit_Biased_Climb(int expected) {
    if (Inhibit_Biased_Climb() == expected) {
        printf("Test Passed\n");
    } else {
        printf("Test Failed\n");
        exit(1);
    }
}

void test_1() {
    printf("Test 1: \n");
    Climb_Inhibit = 1;
    Up_Separation = 300;
    test_Inhibit_Biased_Climb(400);
}

void test_2() {
    printf("Test 2: \n");
    Climb_Inhibit = 0;
    Up_Separation = 300;
    test_Inhibit_Biased_Climb(300);
}

int main(void) {
  test_1();
  test_2();
  return 0;
}