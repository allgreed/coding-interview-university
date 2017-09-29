#include "vector.h"

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

void pushTest()
{
    Vector* vector = Vector_init_default();

    Vector_push(vector, 58);

    assert(Vector_at(vector, 0) == 58);
    assert(Vector_size(vector) == 1);

    Vector_destroy(vector);
}

void popTest()
{
    Vector* vector = Vector_init_default();

    Vector_push(vector, 58);
    int tmp = Vector_pop(vector);

    assert(tmp == 58);
    assert(Vector_isEmpty(vector) == true);

    Vector_destroy(vector);
}

void insertTest()
{
    Vector* vector = Vector_init_default();

    Vector_push(vector, 58);
    Vector_push(vector, 64);
    Vector_push(vector, 4);

    Vector_insert(vector, 1, 105);

    assert(Vector_at(vector, 0) == 58);
    assert(Vector_at(vector, 1) == 105);
    assert(Vector_at(vector, 2) == 64);
    assert(Vector_at(vector, 3) == 4);

    assert(Vector_size(vector) == 4);

    Vector_destroy(vector);
}

void deleteTest()
{
    Vector* vector = Vector_init_default();

    Vector_push(vector, 58);
    Vector_push(vector, 105);
    Vector_push(vector, 64);
    Vector_push(vector, 4);

    Vector_delete(vector, 1);

    assert(Vector_at(vector, 0) == 58);
    assert(Vector_at(vector, 1) == 64);
    assert(Vector_at(vector, 2) == 4);

    assert(Vector_size(vector) == 3);

    Vector_destroy(vector);
}

void prependTest()
{
    Vector* vector = Vector_init_default();

    Vector_push(vector, 64);
    Vector_push(vector, 4);

    Vector_prepend(vector, 58);

    assert(Vector_at(vector, 0) == 58);
    assert(Vector_at(vector, 1) == 64);
    assert(Vector_at(vector, 2) == 4);

    assert(Vector_size(vector) == 3);

    Vector_destroy(vector);
}

void findTest()
{
    Vector* vector = Vector_init_default();

    Vector_push(vector, 64);
    Vector_push(vector, 4);

    assert(Vector_find(vector, 4) == 1);
    assert(Vector_find(vector, 50) == -1);

    Vector_destroy(vector);
}

void resizeTest()
{
    Vector* vector = Vector_init_default();

    for (int i = 0; i < 16; i++)
        Vector_push(vector, 4);

    assert(Vector_capacity(vector) == 32);

    for (int i = 0; i < 12; i++)
        Vector_pop(vector);

    assert(Vector_capacity(vector) == 8);

    Vector_destroy(vector);
}

void removeTest()
{
    Vector* vector = Vector_init_default();

    Vector_push(vector, 7);
    Vector_push(vector, 7);
    Vector_push(vector, 5);
    Vector_push(vector, 4);
    Vector_push(vector, 7);
    Vector_push(vector, 7);
    Vector_push(vector, 3);
    Vector_push(vector, 7);
    Vector_push(vector, 5);
    Vector_push(vector, 7);
    Vector_push(vector, 7);

    Vector_remove(vector, 7);

    assert(Vector_at(vector, 0) == 5);
    assert(Vector_at(vector, 1) == 4);
    assert(Vector_at(vector, 2) == 3);
    assert(Vector_at(vector, 3) == 5);

    assert(Vector_size(vector) == 4);

    Vector_destroy(vector);
}

int main()
{
    creationTest();
    AtTest();
    getterTest();
    pushTest();
    popTest();
    insertTest();
    deleteTest();
    prependTest();
    findTest();
    resizeTest();
    removeTest();

    printf("All tests passed!\n");
    return 0;
}
