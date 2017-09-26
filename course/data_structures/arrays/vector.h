#ifndef PROJECT_ARRAY_H
#define PROJECT_ARRAY_H

/*
EXIT CODES:
    0 - OK
    1 - failed memory allocation
    2 - out of bounds array access
    3 - negative index array access
*/
// refactor to const int EXIT_CODE_${}

// const int DEFAULT_CAPACITY = 16;
// const int GROWTH_FACTOR = 2;
// const int SHRINK_FACTOR = 4;

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
void Vector_set(Vector* vector, int index, int value);
int Vector_at(Vector* vector, int index);

#endif  // PROJECT_ARRAY_H
