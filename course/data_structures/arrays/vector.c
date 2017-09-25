#include <stdio.h>
#include <stdlib.h>

// Convert this to enum
/*
Exit codes:
0 - OK
1 - failed malloc
2 - out of bounds array access
*/

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
// Vector implementation
// ****************************

typedef struct
{
    int capacity;
    int size;
    int* tab;
} Vector;

Vector* Vector_init(int size)
{
    // Creates vector container
    Vector* vector = allocate(sizeof(Vector));

    // Default parameters
    vector->tab = allocate(sizeof(int) * size);
    vector->capacity = size;
    vector->size = 0;

    return vector;
}

Vector* Vector_init_default()
{
    const int SIZE = 16;
    return Vector_init(SIZE);
}

void Vector_destroy(Vector* vector)
{
    free(vector->tab);
    free(vector);
}

void _Vector_resize(Vector* vector)
{

}

int* _Vector_index(Vector* vector, int index)
{
    return (vector->tab + index);
}

int Vector_at(Vector* vector, int index)
{
    if (( index >= vector->size ) || ( index < 0 ))
        exit(2);

    return *(_Vector_index(vector, index));
}

void Vector_set(Vector* vector, int index, int value)
{
    if (index < 0)
        exit(2);

    // if out of capacity -> resize
    // Pointer by reference, not by value?

    *(_Vector_index(vector, index)) = value;

    vector->size = index + 1;
}

// ****************************
// Main
// ****************************

int main()
{
    Vector* vector = Vector_init_default();

    Vector_set(vector, 5, 8);
    printf("%d\n", Vector_at(vector, 5));

    Vector_destroy(vector);
    return 0;
}
