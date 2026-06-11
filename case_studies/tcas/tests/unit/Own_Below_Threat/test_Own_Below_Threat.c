#include "Own_Below_Threat.h"
#include <stdio.h>
#include <stdlib.h>
void test_Own_Below_Threat(int expected) {
    if (Own_Below_Threat() == expected) printf("Test 1 Passed\n");
    else {
      printf("Test 1 Failed\n");
      exit(1);
    }
}

void test_1() {
    Own_Tracked_Alt = 1000;
    Other_Tracked_Alt = 2000;
    test_Own_Below_Threat(1);
}

int main(void) {
  test_1();
  return 0;
}