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
