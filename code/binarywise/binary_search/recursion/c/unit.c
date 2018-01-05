#include "binary_search.h"

#include <stdio.h>
#include <assert.h>

// Test declarations
void test_even_array()
{
    int arr[] = { 1, 3, 5, 7 };
    int result = search(arr, 4, 1);

    assert(result == 0);
}

void test_odd_array()
{
    int arr[] = { 1, 3, 5 };
    int result = search(arr, 4, 1);

    assert(result == 0);
}

void test_odd_array_negatives_only()
{
    int arr[] = {-50, -30, -20, -10, -5, -1 };
    int result = search(arr, 6, -20);

    assert(result == 2);
}

void test_even_array_negatives_only()
{
    int arr[] = {-50, -30, -10, -5, -1 };
    int result = search(arr, 5, -1);

    assert(result == 4);
}
// test odd, even arrays, containing negatives, positives and 0

int main()
{
    test_even_array();
    test_odd_array();

    printf("All tests passed!\n");
    return 0;
}
