#include "binary_search.h"

#include <stdio.h>
#include <assert.h>

// Test declarations
void test_even_array()
{
    int arr[] = {1, 3, 5, 7};
    int result = search(arr, 4, 1);

    assert(result == 0);
}

void test_odd_array()
{
    int arr[] = {1, 3, 5};
    int result = search(arr, 4, 1);

    assert(result == 0);
}

// test odd, even array, containing negatives
// test odd, even arrays, containing negatives, positives and 0

int main()
{
    test_even_array();
    test_odd_array();

    printf("All tests passed!\n");
    return 0;
}
