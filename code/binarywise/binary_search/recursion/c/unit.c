#include "binary_search.h"

#include <stdio.h>
#include <assert.h>

void test_even_array()
{
    int arr[] = { 1, 3, 5, 7 };
    search_return_t result = search(arr, 4, 1);

    assert(result.return_code == RETURN_CODE_OK);
    assert(result.index == 0);
}

void test_odd_array()
{
    int arr[] = { 1, 3, 5 };
    search_return_t result = search(arr, 4, 1);

    assert(result.return_code == RETURN_CODE_OK);
    assert(result.index == 0);
}

void test_even_array_negatives_only()
{
    int arr[] = { -50, -30, -20, -10, -5, -1 };
    search_return_t result = search(arr, 6, -20);

    assert(result.return_code == RETURN_CODE_OK);
    assert(result.index == 2);
}

void test_odd_array_negatives_only()
{
    int arr[] = { -50, -30, -10, -5, -1 };
    search_return_t result = search(arr, 5, -1);

    assert(result.return_code == RETURN_CODE_OK);
    assert(result.index == 4);
}

void test_even_every_number()
{
    int arr[] = { -1, 0, 5, 7 };
    search_return_t result = search(arr, 4, 7);

    assert(result.return_code == RETURN_CODE_OK);
    assert(result.index == 3);
}

void test_odd_every_number()
{
    int arr[] = { -3, -1, 0, 5, 7 };
    search_return_t result = search(arr, 5, 0);

    assert(result.return_code == RETURN_CODE_OK);
    assert(result.index == 2);
}

void test_non_existing()
{
    int arr[] = { 1, 3, 5, 7 };
    search_return_t result = search(arr, 4, -69);

    assert(result.return_code == RETURN_CODE_NOT_FOUND);
}

int main()
{
    test_even_array();
    test_odd_array();

    test_even_array_negatives_only();
    test_odd_array_negatives_only();

    test_odd_every_number();
    test_even_every_number();

    test_non_existing();

    printf("All tests passed!\n");
    return 0;
}

