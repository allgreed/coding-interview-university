#pragma once

#include <boost/circular_buffer.hpp>

template <typename T>
class Queue
{
    protected:
        static constexpr int DEFAULT_CAPACITY = 5;

    protected:
        boost::circular_buffer<T> circular_buffer;

    public:
        Queue();
        Queue(int desired_capacity);

        void enqueue(T value);
        T dequeue();
        bool empty();
        bool full();
};

#include "queue.cpp"
