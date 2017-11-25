#ifndef PROJECT_QUEUE_H
#define PROJECT_QUEUE_H

#include <stdbool.h>

// TYPES
// *****************

// poor man's template
typedef int Queue_element_t;

typedef struct Queue
{
    int read_index;
    int write_index;
    int capacity;
    Queue_element_t* data;
} Queue;

#define QUEUE_DEFAULT_SIZE 5

// CONSTS
// *****************

typedef enum
{
    OK,
    FAILED_ALLOCATION,
    EMPTY_DEQUEUE_ATTEMPT,
    FULL_ENQUEUE_ATTEMPT
} QUEUE_EXIT_CODES;


// FUNCTIONS
// *****************

Queue* Queue_create_of_size(int size);
Queue* Queue_create();
void Queue_destory(Queue* queue);

void Queue_enqueue(Queue* queue, Queue_element_t value);
Queue_element_t Queue_dequeue(Queue* queue);
bool Queue_empty(Queue* queue);
bool Queue_full(Queue* queue);

#endif  // PROJECT_QUEUE_H
