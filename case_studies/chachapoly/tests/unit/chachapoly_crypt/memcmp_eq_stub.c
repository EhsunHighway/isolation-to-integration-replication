#include "memcmp_eq_stub.h"

int expected_result;

void set_result(int result){
    expected_result = result;
}

int memcmp_eq(const void *av, const void *bv, int n)
{
    return expected_result;
}