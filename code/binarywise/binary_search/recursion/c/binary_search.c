#include "binary_search.h"

static search_return_t _search(int* arr, size_t start, size_t end, int value)
{
    if (start == end)
    {
        search_return_t retval;

        retval.index = start;
        retval.return_code = arr[start] == value
            ? RETURN_CODE_OK
            : RETURN_CODE_NOT_FOUND;

        return retval;
    }

    int middle = (start + end) / 2;

    return 
        (value <= arr[middle])
        ? _search(arr, start, middle, value)
        : _search(arr, middle + 1, end, value);
}

search_return_t search(int *arr, size_t length, int value)
{
    return _search(arr, 0, length - 1, value);
}

