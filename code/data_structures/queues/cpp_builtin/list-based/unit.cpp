#include "queue.hpp"
#include "gtest/gtest.h"

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
