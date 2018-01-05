#include "binary_search.h"

static int _search(int* arr, size_t start, size_t end, int value)
{
    if (start == end)
        return arr[start] == value ? start : -1;

    int middle = (start + end) / 2;

    return 
        (value <= arr[middle]) 
        ? _search(arr, start, middle, value)
        : _search(arr, middle, end, value);
}

int search(int *arr, size_t length, int value)
{
    return _search(arr, 0, length - 1, value);
}

