#include "vector.h"

// IO
#include <stdio.h>
#include <assert.h>

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

    vector->data[0] = 6;
    vector->data[1] = 7;
    vector->data[2] = 8;
    vector->data[3] = 9;
    vector->data[4] = 10;
    vector->size = 5;

    assert(Vector_at(vector, 0) == 6);
    assert(Vector_at(vector, 1) == 7);
    assert(Vector_at(vector, 2) == 8);
    assert(Vector_at(vector, 3) == 9);
    assert(Vector_at(vector, 4) == 10);

    Vector_destroy(vector);
}

void getterTest()
{
    Vector* vector = Vector_init_default();

    assert(Vector_size(vector) == vector->size);
    assert(Vector_capacity(vector) == vector->capacity);
    assert(Vector_isEmpty(vector) == true);

    Vector_destroy(vector);
}

int main()
{
    creationTest();
    AtTest();
    getterTest();

    printf("All tests passed!\n");
    return 0;
}

    // Vector_set(vector, 5, 8);
    // assert(Vector_at(vector, 5) == 8);
// 