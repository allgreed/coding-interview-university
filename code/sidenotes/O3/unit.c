#include "O3.h"

#include <stdio.h>
#include <assert.h>

void single_test()
{
    return_t sample = wraeck_havock();

    printf("%d %d %d\n", sample.i, sample.j, sample.k);

    assert(sample.i == 2);
    assert(sample.j == 1);
    assert(sample.k == 0);
}

int main()
{
    single_test();

    printf("All tests passed!\n");
    return 0;
}

