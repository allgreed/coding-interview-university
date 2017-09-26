#include "vector.h"

#include <stdio.h>

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

void Vector__negativeIndexCheck(int index)
{
    if (index < 0)
        exit(3);
}

void Vector__set(Vector* vector, int index, int value)
{
    Vector__negativeIndexCheck(index);

    *(Vector__index(vector, index)) = value;
}

void Vector__inc(Vector* vector)
{
    // commmit resizing if needed

    vector->size++;
}

void Vector__dec(Vector* vector)
{
    // commmit resizing if needed

    vector->size--;
}

// ****************************
// Basic operations
// ****************************

int Vector_at(Vector* vector, int index)
{
    Vector__negativeIndexCheck(index);

    if (( index >= vector->size ))
        exit(2);

    return *(Vector__index(vector, index));
}

void Vector_push(Vector* vector, int item)
{
    Vector__inc(vector);
    Vector__set(vector, vector->size-1, item);
}

int Vector_pop(Vector* vector)
{
    int retval = Vector_at(vector, vector->size-1);
    Vector__dec(vector);
    return retval;
}

void Vector_insert(Vector* vector, int index, int value)
{
    Vector__inc(vector);

    int* tmp = allocate(sizeof(int) * (vector->size - index));

    for(int i = 0; i < (vector->size - index - 1); i++)
        *(tmp + i) = Vector_at(vector, index + i); 

    Vector__set(vector, index, value);

    for(int i = 0; i < (vector->size - index - 1); i++)
    {
        Vector__set(vector, index+i+1, *(tmp + i));
    }

    free(tmp);
}

void Vector_delete(Vector* vector, int index)
{

}

// ****************************
// Getters
// ****************************

int Vector_size(Vector* vector)
{
    return vector->size;
}

int Vector_capacity(Vector* vector)
{
    return vector->capacity;
}

// ****************************
// Derived
// ****************************

bool Vector_isEmpty(Vector* vector)
{
    return (Vector_size(vector) == 0);
}
