#ifndef PROJECT_ARRAY_H
#define PROJECT_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>

extern const int VECTOR_EXIT_OK;
extern const int VECTOR_EXIT_FAILED_ALLOCATION;
extern const int VECTOR_EXIT_OUT_OF_BOUNDS;
extern const int VECTOR_EXIT_NEGATIVE_INDEX;

extern const int VECTOR_DEFAULT_CAPACITY;
extern const int VECTOR_GROWTH_FACTOR;
extern const int VECTOR_SHRINK_FACTOR;

typedef struct
{
    int capacity;
    int size;
    int* data;
} Vector;

// Create and destroy
Vector* Vector_init_default();
Vector* Vector_init_of_size();
void Vector_destroy(Vector* vector);

// Basic operations
int Vector_at(Vector* vector, int index);
int Vector_pop(Vector* vector);
void Vector_push(Vector* vector, int item);
void Vector_delete(Vector* vector, int index);
void Vector_insert(Vector* vector, int index, int value);

// Getters
int Vector_size(Vector* vector);
int Vector_capacity(Vector* vector);

// Derived
bool Vector_isEmpty(Vector* vector);
void Vector_prepend(Vector* vector, int value);
int Vector_find(Vector* vector, int value);
void Vector_remove(Vector* vector, int value);

#endif  // PROJECT_ARRAY_H
