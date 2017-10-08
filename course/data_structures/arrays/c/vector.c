#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

// ****************************
// Utility
// ****************************

// @size [bytes]
void* allocate(int size)
{
    void* retval = malloc(size);

    if (retval == NULL)
    {
        fprintf( stderr, "Failed allocation with malloc\n");
        exit(VECTOR_EXIT_FAILED_ALLOCATION);
    }
    else
        return retval;
}

// @size [bytes]
void* reallocate(int* pointer, int size)
{
    void* retval = realloc(pointer, size);

    if (retval == NULL)
    {
        fprintf( stderr, "Failed allocation with realloc\n");
        exit(VECTOR_EXIT_FAILED_ALLOCATION);
    }
    else
        return retval;
}

int toNearestGreaterBinaryPower(int input)
{
    input = abs(input);

    if(input == 0)
        return 1;

    input--;
    input |= input >> 1;
    input |= input >> 2;
    input |= input >> 4;
    input |= input >> 8;
    input |= input >> 16;
    input++;

    return input;
}

// ****************************
// Create and destroy
// ****************************

Vector* Vector_init_default()
{
    const int SIZE = VECTOR_DEFAULT_CAPACITY;
    return Vector_init_of_size(SIZE);
}

Vector* Vector_init_of_size(int size)
{
    size = toNearestGreaterBinaryPower(size);

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
    Vector__resize(vector, Vector_capacity(vector) * VECTOR_GROWTH_FACTOR);
}

void Vector__shrink(Vector* vector)
{
    Vector__resize(vector, Vector_capacity(vector) / VECTOR_GROWTH_FACTOR);
}

int* Vector__index(Vector* vector, int index)
{
    return (vector->data + index);
}

bool Vector__isIndexWithinBounds(Vector* vector, int index)
{
    return (index < vector->size);
}

void Vector__runIndexChecks(Vector* vector,int index)
{
    // Negative index
    if (index < 0)
    {
        fprintf( stderr, "Negative index access attempt: %d\n", index);
        exit(VECTOR_EXIT_NEGATIVE_INDEX);
    }

    // Out of bounds access
    if ( !Vector__isIndexWithinBounds(vector, index) )
    {
        fprintf( stderr, "Out of bounds index access attempt: %d\n", index);
        exit(VECTOR_EXIT_OUT_OF_BOUNDS);
    }

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

    if(Vector_size(vector) <= Vector_capacity(vector) / VECTOR_SHRINK_TRIGGER)
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

    for(int i = 0; i < Vector_size(vector) - removedItems; i++)
    {

        while (Vector__isIndexWithinBounds(vector, i+removedItems) &&
        (Vector__get(vector, i+removedItems) == value) )
        {
            removedItems++;
        }

        // Handling remove item tail
        if(!Vector__isIndexWithinBounds(vector, i+removedItems))
            break;

        Vector__set(vector, i, Vector__get(vector, i + removedItems));
    }

    for(int i = 0; i < removedItems; i++)
        Vector__dec(vector);
}

void Vector_push(Vector* vector, int item)
{
    Vector_insert(vector, Vector_size(vector), item);
}

int Vector_pop(Vector* vector)
{
    int retval = Vector__get(vector, Vector_size(vector) - 1);
    Vector_delete(vector, Vector_size(vector) - 1);
    return retval;
}
