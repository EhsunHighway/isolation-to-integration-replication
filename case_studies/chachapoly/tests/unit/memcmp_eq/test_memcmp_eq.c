#include "memcmp_eq.h"
#include <stdio.h>

void test_memcmp_eq(const void *a, const void *b, int n, int expected)
{
    int result = memcmp_eq(a,b,n);

    if (result == expected)
        printf("\nTest passed.");
    else
        printf("\nTest failed.");
        // exit(1); // use this for mutation analysis
}

void test_1(){
    printf("\nTest 1:");
    char str1[] = "hello";
    char str2[] = "hello";
    int expected1 = 0;
    test_memcmp_eq(str1,str2,5,expected1);
}


int main() {
    printf("\nUnit test for memcmp_eq(): \n");
    test_1();


    return 0;
}
