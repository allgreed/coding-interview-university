#include "binary_search.h"

int search(int *arr, size_t length, int value)
{
    int start = 0;
    int end = length - 1;
    
    while(start != end)
    {
        int middle = (start + end) / 2;
        value <= arr[middle] ? (end = middle) : (start = middle + 1);
    }

    return arr[start] == value ? start : -1;
}
