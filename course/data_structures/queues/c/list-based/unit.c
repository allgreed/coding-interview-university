#include "queue.h"

#include <stdio.h>
#include <assert.h>

void enqueue_dequeue_test()
{
    Queue* queue = Queue_create();

    Queue_enqueue(queue, 1000000);
    Queue_enqueue(queue, 0);
    Queue_enqueue(queue, -5);

    assert(Queue_dequeue(queue) == 1000000);
    assert(Queue_dequeue(queue) == 0);
    assert(Queue_dequeue(queue) == -5);

    Queue_destory(queue);
}

void empty_test()
{
    Queue* queue = Queue_create();

    assert(Queue_empty(queue) == true);

    Queue_enqueue(queue, 3);
    Queue_enqueue(queue, -69);

    assert(Queue_empty(queue) == false);

    Queue_dequeue(queue);

    assert(Queue_empty(queue) == false);

    Queue_dequeue(queue);

    assert(Queue_empty(queue) == true);

    Queue_destory(queue);
}

void memleak_test()
{
    Queue* queue = Queue_create();

    Queue_enqueue(queue, 1000000);
    Queue_enqueue(queue, 0);
    Queue_enqueue(queue, -5);

    Queue_destory(queue);
}

int main()
{
    enqueue_dequeue_test();
    printf("\n");

    empty_test();
    printf("\n");

    memleak_test();
    printf("\n");

    printf("All tests passed!\n");
    return 0;
}
