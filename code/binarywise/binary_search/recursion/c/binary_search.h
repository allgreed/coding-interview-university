#ifndef PROJECT_BINARY_SEARCH_H
#define PROJECT_BINARY_SEARCH_H

#include <stddef.h>

static const int RETURN_CODE_OK = 0;
static const int RETURN_CODE_NOT_FOUND = -1;

typedef struct search_return_t
{
    size_t index;
    int return_code;
} search_return_t;

search_return_t search(int* arr, size_t length, int value);

#endif  // PROJECT_BINARY_SEARCH_H

