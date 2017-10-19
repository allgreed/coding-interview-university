#ifndef PROJECT_QUEUE_H
#define PROJECT_QUEUE_H

#include <stdbool.h>

// OPTIONS
// *****************

#ifndef QUEUE_MEMTEST_ON
    // This is used for logging every allocation and deallocation
    #define QUEUE_MEMTEST_ON
#endif

// TYPES
// *****************

// poor man's template
typedef int Queue_element_t;

typedef struct Queue_node
{
    Queue_element_t value;
    struct Queue_node* next;
} Queue_node;

typedef struct Queue
{
    Queue_node* head;
    Queue_node* tail;
} Queue;

// CONSTS
// *****************

extern const int QUEUE_EXIT_FAILED_ALLOCATION;
extern const int QUEUE_EXIT_EMPTY_DEQUEUE_ATTEMPT;

extern Queue_node* const QUEUE_NULLPTR;

// FUNCTIONS
// *****************

Queue* Queue_create();
void Queue_destory(Queue* queue);

void Queue_enqueue(Queue* queue, Queue_element_t value);
Queue_element_t Queue_dequeue(Queue* queue);
bool Queue_empty(Queue* queue);

#endif  // PROJECT_QUEUE_H
