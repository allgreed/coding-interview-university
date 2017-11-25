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

void full_test()
{
    Queue* queue = Queue_create_of_size(3);

    assert(Queue_full(queue) == false);

    Queue_enqueue(queue, 3);
    Queue_enqueue(queue, -69);
    Queue_enqueue(queue, 8);

    assert(Queue_full(queue) == true);

    Queue_destory(queue);
}

void circulation_test()
{
    Queue* queue = Queue_create_of_size(4);

    Queue_enqueue(queue, 3);
    Queue_enqueue(queue, -69);
    Queue_enqueue(queue, 1);
    Queue_enqueue(queue, 2);

    Queue_dequeue(queue);
    Queue_dequeue(queue);

    Queue_enqueue(queue, 3);

    Queue_enqueue(queue, 4);

    Queue_dequeue(queue);
    Queue_enqueue(queue, 5);

    Queue_dequeue(queue);
    Queue_enqueue(queue, -69);

    assert(Queue_dequeue(queue) == 3);

    Queue_destory(queue);
}

int main()
{
    printf("\n");

    enqueue_dequeue_test();
    empty_test();
    full_test();
    circulation_test();

    printf("All tests passed!\n");
    return 0;
}
