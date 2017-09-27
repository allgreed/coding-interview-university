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

// @size [bytes]
void* reallocate(int* pointer, int size)
{
    void* retval = realloc(pointer, size);

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

void Vector__resize(Vector* vector, int desiredCapacity)
{
    vector->data = reallocate(vector->data, desiredCapacity * sizeof(int));
    vector->capacity = desiredCapacity;
}

void Vector__expand(Vector* vector)
{
    Vector__resize(vector, Vector_capacity(vector) * 2);
}

void Vector__shrink(Vector* vector)
{
    Vector__resize(vector, Vector_capacity(vector) / 2);
}

int* Vector__index(Vector* vector, int index)
{
    return (vector->data + index);
}

void Vector__runIndexChecks(Vector* vector,int index)
{
    // Negative index
    if (index < 0)
        exit(3);

    // Out of bounds access
    if ( index >= vector->size )
        exit(2);
}

void Vector__set(Vector* vector, int index, int value)
{
    *(Vector__index(vector, index)) = value;
}

int Vector__get(Vector* vector, int index)
{
    return *(Vector__index(vector, index));
}

void Vector__inc(Vector* vector)
{
    vector->size++;

    if(Vector_size(vector) == Vector_capacity(vector))
        Vector__expand(vector);
}

void Vector__dec(Vector* vector)
{
    vector->size--;

    if(Vector_size(vector) <= Vector_capacity(vector) / 4)
        Vector__shrink(vector);
}

// ****************************
// Basic operations
// ****************************

int Vector_at(Vector* vector, int index)
{
    Vector__runIndexChecks(vector, index);

    return *(Vector__index(vector, index));
}

void Vector_update(Vector* vector,int index, int value)
{
    Vector__runIndexChecks(vector, index);

    Vector__set(vector, index, value);
}

void Vector_push(Vector* vector, int item)
{
    Vector__inc(vector);
    Vector__set(vector, vector->size-1, item);
}

int Vector_pop(Vector* vector)
{
    int retval = Vector__get(vector, vector->size-1);
    Vector__dec(vector);
    return retval;
}

void Vector_insert(Vector* vector, int index, int value)
{
    Vector__inc(vector);

    for(int i = Vector_size(vector); i > index; i--)
        Vector__set(vector, i, Vector__get(vector, i - 1));

    Vector__set(vector, index, value);
}

void Vector_delete(Vector* vector, int index)
{
    for(int i = index; i < Vector_size(vector) - 1; i++)
        Vector__set(vector, i, Vector__get(vector, i + 1));

    Vector__dec(vector);
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

void Vector_prepend(Vector* vector, int value)
{
    Vector_insert(vector, 0, value);
}

int Vector_find(Vector* vector, int value)
{
    for(int i = 0; i < Vector_size(vector); i++)
        if (Vector__get(vector, i) == value) return i;

    return -1;
}

void Vector_remove(Vector* vector, int value)
{
    int removedItems = 0;

    for(int i = 0; i < (Vector_size(vector) - removedItems); i++)
    {
        if (Vector_at(vector, i) == value)
        {
            removedItems++;
            Vector__dec(vector);
        }

        Vector__set(vector, i, Vector__get(vector, i + removedItems));
    }

    Vector__dec(vector);
}
