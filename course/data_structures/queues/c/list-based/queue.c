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
        exit(QUEUE_EXIT_FAILED_ALLOCATION);
    }

    #ifdef QUEUE_MEMTEST_ON
         printf("Allocated:  %ld\n", (long int) retval);
    #endif

    return retval;
}

// CONSTRUCTOR, DESTRUCTOR
// *****************

Queue* Queue_create()
{
    Queue* queue = allocate(sizeof(Queue));

    queue->head = QUEUE_NULLPTR;
    queue->tail = QUEUE_NULLPTR;

    return queue;
}

void Queue_destory(Queue* queue)
{
    if(!Queue_empty(queue))
    {
        Queue_node* current;
        Queue_node* next = queue->head;

        while(next != QUEUE_NULLPTR)
        {
            current = next;
            next = current->next;

            free(current);
            #ifdef QUEUE_MEMTEST_ON
                printf("Removed node: %ld\n", (long int) current);
            #endif
        }
    }

    free(queue);
    #ifdef QUEUE_MEMTEST_ON
        printf("Removed queue: %ld\n", (long int) queue);
    #endif
}

// FUNCTIONS
// *****************

void Queue_enqueue(Queue* queue, Queue_element_t value)
{
    Queue_node* newNode = allocate(sizeof(Queue_node));

    newNode->value = value;
    newNode->next = QUEUE_NULLPTR;

    if(Queue_empty(queue))
        queue->head = newNode;
    else
        queue->tail->next = newNode;

    queue->tail = newNode;
}

Queue_element_t Queue_dequeue(Queue* queue)
{
    if(Queue_empty(queue))
    {
        fprintf( stderr, "Attempt to dequeue from empty queue\n");
        exit(QUEUE_EXIT_EMPTY_DEQUEUE_ATTEMPT);
    }

    Queue_node* dequeued_node = queue->head;

    Queue_element_t retval = dequeued_node->value;
    queue->head = dequeued_node->next;

    free(dequeued_node);
    #ifdef QUEUE_MEMTEST_ON
        printf("Removed node: %ld\n", (long int) dequeued_node);
    #endif

    return retval;
}

bool Queue_empty(Queue* queue)
{
    return (queue->head == QUEUE_NULLPTR);
}