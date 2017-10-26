#include "queue.hpp"
#include "gtest/gtest.h"

TEST(Queue, Enqueue_dequeue)
{
    Queue<int> queue;
    queue.enqueue(1000000);
    queue.enqueue(0);
    queue.enqueue(-5);

    EXPECT_EQ(queue.dequeue(), 1000000);
    EXPECT_EQ(queue.dequeue(), 0);
    EXPECT_EQ(queue.dequeue(), -5);
}

TEST(Queue, Empty)
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

TEST(Queue, Full)
{
    Queue<int> queue(3);
    EXPECT_FALSE(queue.full());

    queue.enqueue(3);
    queue.enqueue(-69);
    queue.enqueue(8);

    EXPECT_TRUE(queue.full());
}

TEST(Queue, Circulation)
{
    Queue<int> queue;

    queue.enqueue(3);
    queue.enqueue(-69);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    queue.dequeue();
    queue.dequeue();
    queue.enqueue(4);
    queue.enqueue(5);

    queue.dequeue();
    queue.enqueue(6);

    queue.dequeue();
    queue.enqueue(7);

    EXPECT_EQ(queue.dequeue(), 3);
}

TEST(Queue, Negative_index_thorw)
{
    EXPECT_THROW(Queue<int> queue(-8), std::bad_array_new_length);
}

TEST(Queue, Empty_dequeue_thorw)
{
    Queue<int> queue;
    EXPECT_THROW(queue.dequeue(), std::runtime_error);
}

TEST(Queue, Full_enqueue_thorw)
{
    Queue<int> queue(1);
    queue.enqueue(5);

    EXPECT_THROW(queue.enqueue(5), std::runtime_error);
}

TEST(Queue, Equality_operator)
{
    Queue<int> reference_queue;
    Queue<int> queue;

    EXPECT_TRUE(queue == reference_queue);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    reference_queue.enqueue(1);
    reference_queue.enqueue(2);
    reference_queue.enqueue(3);

    EXPECT_TRUE(queue == reference_queue);

    reference_queue.dequeue();

    EXPECT_FALSE(queue == reference_queue);

    reference_queue.enqueue(8);

    EXPECT_FALSE(queue == reference_queue);
}

TEST(Queue, Inequality_operator)
{
    Queue<int> reference_queue;
    Queue<int> queue;

    EXPECT_FALSE(queue != reference_queue);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    reference_queue.enqueue(1);
    reference_queue.enqueue(2);
    reference_queue.enqueue(3);

    EXPECT_FALSE(queue != reference_queue);

    reference_queue.dequeue();

    EXPECT_TRUE(queue != reference_queue);

    reference_queue.enqueue(8);

    EXPECT_TRUE(queue != reference_queue);
}

TEST(Queue, Equality_operator_circular_neq)
{
    Queue<int> reference_queue;
    Queue<int> queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(7);

    reference_queue.enqueue(7);
    reference_queue.enqueue(8);
    reference_queue.enqueue(9);
    reference_queue.dequeue();
    reference_queue.dequeue();
    reference_queue.dequeue();

    reference_queue.enqueue(4);
    reference_queue.enqueue(5);
    reference_queue.enqueue(6);

    EXPECT_FALSE(queue == reference_queue);
}

TEST(Queue, Equality_operator_circular_eq)
{
    Queue<int> reference_queue;
    Queue<int> queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);

    reference_queue.enqueue(7);
    reference_queue.enqueue(8);
    reference_queue.enqueue(9);
    reference_queue.dequeue();
    reference_queue.dequeue();
    reference_queue.dequeue();

    reference_queue.enqueue(4);
    reference_queue.enqueue(5);
    reference_queue.enqueue(6);

    EXPECT_TRUE(queue == reference_queue);
}

    // wrapp the buffer over in one, and not wrapp in second -> improve this test

// TEST(Queue, copy_constructor)
// {
//     Queue<int> reference_queue;

//     reference_queue.enqueue(3);
//     reference_queue.enqueue(4);
//     reference_queue.enqueue(5);

//     Queue<int> queue = reference_queue;

//     EXPECT_TRUE(queue == reference_queue);
// }

// TEST(Queue, copy_assignment)
// {
//     Queue<int> queue;
//     Queue<int> same_reference_queue;
//     Queue<int> smaller_reference_queue;
//     Queue<int> bigger_reference_queue;

//     queue.enqueue(1);
//     queue.enqueue(2);
//     queue.enqueue(3);

//     same_reference_queue.enqueue(4);
//     same_reference_queue.enqueue(5);
//     same_reference_queue.enqueue(6);

//     smaller_reference_queue.enqueue(7);
//     smaller_reference_queue.enqueue(8);

//     bigger_reference_queue.enqueue(9);
//     bigger_reference_queue.enqueue(10);
//     bigger_reference_queue.enqueue(11);
//     bigger_reference_queue.enqueue(12);

//     queue = same_reference_queue;
//     EXPECT_TRUE(queue == same_reference_queue);

//     queue = smaller_reference_queue;
//     EXPECT_TRUE(queue == smaller_reference_queue);

//     queue = bigger_reference_queue;
//     EXPECT_TRUE(queue == bigger_reference_queue);
// }

// TEST(Queue, copy_assignment_from_empty)
// {
//     Queue<int> queue;
//     Queue<int> empty_reference_queue;
//     Queue<int> smaller_reference_queue;
//     Queue<int> bigger_reference_queue;

//     smaller_reference_queue.enqueue(7);
//     smaller_reference_queue.enqueue(8);

//     bigger_reference_queue.enqueue(9);
//     bigger_reference_queue.enqueue(10);
//     bigger_reference_queue.enqueue(11);
//     bigger_reference_queue.enqueue(12);

//     queue = empty_reference_queue;
//     EXPECT_TRUE(queue == empty_reference_queue);

//     bigger_reference_queue = queue;
//     EXPECT_TRUE(queue == bigger_reference_queue);

//     queue = smaller_reference_queue;
//     EXPECT_TRUE(queue == smaller_reference_queue);
// }

// TEST(Queue, move_assignment)
// {
//     Queue<int> queue;
//     Queue<int> reference_queue;
//     Queue<int> disposable_queue;

//     reference_queue.enqueue(-100);
//     reference_queue.enqueue(100);

//     disposable_queue = reference_queue;

//     queue = std::move(disposable_queue);

//     EXPECT_TRUE(queue == reference_queue);
// }

// TEST(Queue, move_constructor)
// {
//     Queue<int> reference_queue;
//     Queue<int> disposable_queue;

//     reference_queue.enqueue(-100);
//     reference_queue.enqueue(100);

//     disposable_queue = reference_queue;

//     Queue<int> queue = std::move(disposable_queue);

//     EXPECT_TRUE(queue == reference_queue);
// }
