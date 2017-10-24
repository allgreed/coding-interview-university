#include "queue.hpp"
#include "gtest/gtest.h"

#include <stdexcept>

TEST(Queue, enqueue_dequeue)
{
    Queue<int> queue;

    queue.enqueue(1000000);
    queue.enqueue(0);
    queue.enqueue(-5);

    EXPECT_EQ(queue.dequeue(), 1000000);
    EXPECT_EQ(queue.dequeue(), 0);
    EXPECT_EQ(queue.dequeue(), -5);
}

TEST(Queue, empty)
{
    Queue<int> queue;

    EXPECT_TRUE(queue.empty());

    queue.enqueue(3);
    queue.enqueue(-69);

    EXPECT_FALSE(queue.empty());

    queue.dequeue();

    EXPECT_FALSE(queue.empty());

    queue.dequeue();

    EXPECT_TRUE(queue.empty());
}

TEST(Queue, empty_dequeue)
{
    Queue<int> queue;
    EXPECT_THROW(queue.dequeue(), std::runtime_error);
}

TEST(Queue, equality)
{
    Queue<int> reference_queue;
    Queue<int> queue;

    EXPECT_TRUE(queue == reference_queue);

    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    EXPECT_FALSE(queue == reference_queue);

    reference_queue.enqueue(3);
    reference_queue.enqueue(4);
    reference_queue.enqueue(5);

    EXPECT_TRUE(queue == reference_queue);
}

TEST(Queue, copy_constructor)
{
    Queue<int> reference_queue;

    reference_queue.enqueue(3);
    reference_queue.enqueue(4);
    reference_queue.enqueue(5);

    Queue<int> queue = reference_queue;

    EXPECT_TRUE(queue == reference_queue);
}

TEST(Queue, copy_assignment)
{
    Queue<int> queue;
    Queue<int> same_reference_queue;
    Queue<int> smaller_reference_queue;
    Queue<int> bigger_reference_queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    same_reference_queue.enqueue(4);
    same_reference_queue.enqueue(5);
    same_reference_queue.enqueue(6);

    smaller_reference_queue.enqueue(7);
    smaller_reference_queue.enqueue(8);

    bigger_reference_queue.enqueue(9);
    bigger_reference_queue.enqueue(10);
    bigger_reference_queue.enqueue(11);
    bigger_reference_queue.enqueue(12);

    queue = same_reference_queue;
    EXPECT_TRUE(queue == same_reference_queue);

    queue = smaller_reference_queue;
    EXPECT_TRUE(queue == smaller_reference_queue);

    queue = bigger_reference_queue;
    EXPECT_TRUE(queue == bigger_reference_queue);
}

TEST(Queue, copy_assignment_from_empty)
{
    Queue<int> queue;
    Queue<int> empty_reference_queue;
    Queue<int> smaller_reference_queue;
    Queue<int> bigger_reference_queue;

    smaller_reference_queue.enqueue(7);
    smaller_reference_queue.enqueue(8);

    bigger_reference_queue.enqueue(9);
    bigger_reference_queue.enqueue(10);
    bigger_reference_queue.enqueue(11);
    bigger_reference_queue.enqueue(12);

    queue = empty_reference_queue;
    EXPECT_TRUE(queue == empty_reference_queue);

    bigger_reference_queue = queue;
    EXPECT_TRUE(queue == bigger_reference_queue);

    queue = smaller_reference_queue;
    EXPECT_TRUE(queue == smaller_reference_queue);
}

TEST(Queue, move_assignment)
{
    Queue<int> queue;
    Queue<int> reference_queue;
    Queue<int> disposable_queue;

    reference_queue.enqueue(-100);
    reference_queue.enqueue(100);

    disposable_queue = reference_queue;

    queue = std::move(disposable_queue);

    EXPECT_TRUE(queue == reference_queue);
}

TEST(Queue, move_constructor)
{
    Queue<int> reference_queue;
    Queue<int> disposable_queue;

    reference_queue.enqueue(-100);
    reference_queue.enqueue(100);

    disposable_queue = reference_queue;

    Queue<int> queue = std::move(disposable_queue);

    EXPECT_TRUE(queue == reference_queue);
}


// ---------------------

// overload new and delete and somehow propagate it through the code -> log all allocations and deletions ???

// void memleak_test()
// {
//     Queue* queue = Queue_create();

//     Queue_enqueue(queue, 1000000);
//     Queue_enqueue(queue, 0);
//     Queue_enqueue(queue, -5);

//     Queue_destory(queue);
// }

// Test declarations template
// ---------------------

// TEST(Queue, TEST_CASE_NAME)
// {
//     Queue<int> queue;
//     // Do the setup

//     // Do the assertions
// }
