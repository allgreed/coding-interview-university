#include "binary_search.h"
#include <stdlib.h>

search_return_t search(int *arr, size_t length, int value)
{
    size_t start = 0;
    size_t end = length - 1;
    
    while(start != end)
    {
        size_t middle = (start + end) / 2;

        value <= arr[middle] 
            ? (end = middle) 
            : (start = middle + 1);
    }

    search_return_t retval;

    retval.index = start;
    retval.return_code = arr[start] == value
        ? RETURN_CODE_OK
        : RETURN_CODE_NOT_FOUND;

    return retval;
}
