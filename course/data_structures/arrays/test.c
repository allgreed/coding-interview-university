#include "vector.h"

// IO
#include <stdio.h>
#include <assert.h>
// #include <stdbool.h>

void creationTest()
{
    Vector* vector = NULL;
    vector = Vector_init_default();

    assert(vector != NULL);
    assert(vector->size == 0);
    assert(vector->capacity == 16);

    Vector_destroy(vector);
}

void AtTest()
{
    Vector* vector = Vector_init_default();

    vector->data[5]=8;

    assert(Vector_at(vector, 5) == 8);

    Vector_destroy(vector);
}

int main()
{
    creationTest();
    AtTest();


    printf("All tests passed!\n");
    return 0;
}

    // Vector_set(vector, 5, 8);
    // assert(Vector_at(vector, 5) == 8);
// 