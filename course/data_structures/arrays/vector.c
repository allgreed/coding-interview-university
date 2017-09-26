#include "vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ****************************
// Utility
// ****************************

// @size [bytes]
void* allocate(int size)
{
    void* retval = malloc(size);

    if (retval == NULL)
        exit(1);
    else
        return retval;
}

int toNearestGreaterBinaryPower(int input)
{

}

// ****************************
// Create and destroy
// ****************************

Vector* Vector_init_default()
{
    const int SIZE = 16;
    return Vector_init_of_size(SIZE);
}

Vector* Vector_init_of_size(int size)
{
    // Creates vector container
    Vector* vector = allocate(sizeof(Vector));

    // Default parameters
    vector->data = allocate(sizeof(int) * size);
    vector->capacity = size;
    vector->size = 0;

    return vector;
}

void Vector_destroy(Vector* vector)
{
    free(vector->data);
    free(vector);
}

// ****************************
// Private utilities
// ****************************

void Vector__resize(Vector* vector)
{

}


int* Vector__index(Vector* vector, int index)
{
    return (vector->data + index);
}

void negativeIndexCheck(int index)
{
    if (index < 0)
        exit(3);
}

bool isOutOfBounds(Vector* vector ,int number)
{

}

// ****************************
// Basic operations
// ****************************


int Vector_at(Vector* vector, int index)
{
    negativeIndexCheck(index);

    if (( index >= vector->size ))
        exit(2);

    return *(Vector__index(vector, index));
}

void Vector_set(Vector* vector, int index, int value)
{
    negativeIndexCheck(index);

    // if out of capacity -> resize
    // Pointer by reference, not by value?

    *(Vector__index(vector, index)) = value;

    vector->size = index + 1;
}
