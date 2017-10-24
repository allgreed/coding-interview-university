#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

// HELPERS
// *****************

// @size [bytes]
void* allocate(int size)
{
    void* retval = malloc(size);

    if (retval == NULL)
    {
        fprintf( stderr, "Failed allocation with malloc\n");
        exit(FAILED_ALLOCATION);
    }

    return retval;
}

int resolve_circular_index(Queue* queue, int index)
{
    if (index >= queue->capacity)
        index -= (queue->capacity);

    return index;
}

// CONSTRUCTOR, DESTRUCTOR
// *****************

Queue* Queue_create_of_size(int size)
{
    Queue* newQueue = (Queue*) allocate(sizeof(Queue));

    newQueue->capacity = size + 1;
    newQueue->read_index = 0;
    newQueue->write_index = 0;
    newQueue->data = (Queue_element_t*) allocate(sizeof(Queue_element_t) * newQueue->capacity);
}

Queue* Queue_create()
{
    return Queue_create_of_size(QUEUE_DEFAULT_SIZE);
}

void Queue_destory(Queue* queue)
{
    free(queue->data);
    free(queue);
}

// FUNCTIONS
// *****************

void Queue_enqueue(Queue* queue, Queue_element_t value)
{
    if (Queue_full(queue))
    {
        fprintf( stderr, "Enqueue attempt on full queue\n");
        exit(FULL_ENQUEUE_ATTEMPT);
    }

    queue->data[queue->write_index] = value;
    queue->write_index = resolve_circular_index(queue, queue->write_index + 1);
}

Queue_element_t Queue_dequeue(Queue* queue)
{
    if (Queue_empty(queue))
    {
        fprintf( stderr, "Dequeue attempt on empty queue\n");
        exit(EMPTY_DEQUEUE_ATTEMPT);
    }

    Queue_element_t retval = queue->data[queue->read_index];
    queue->read_index = resolve_circular_index(queue, queue->read_index + 1);

    return retval;
}

bool Queue_empty(Queue* queue)
{
    return (queue->read_index == queue->write_index);
}

bool Queue_full(Queue* queue)
{
    int size;

    if (queue->read_index <= queue->write_index)
        size = queue->write_index - queue->read_index;
    else
        size = queue->capacity - queue->read_index + queue->write_index;

    return (size == queue->capacity - 1);
}
