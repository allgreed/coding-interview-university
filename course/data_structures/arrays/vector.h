#ifndef PROJECT_ARRAY_H
#define PROJECT_ARRAY_H

// #include <assert.h>
// #include <stdbool.h>

const int DEFAULT_CAPACITY = 16;
const int GROWTH_FACTOR = 2;
const int SHRINK_FACTOR = 4;

typedef struct JWImplementationArray {
  int size;
  int capacity;
  int *data;
} JArray;

#endif  // PROJECT_ARRAY_H