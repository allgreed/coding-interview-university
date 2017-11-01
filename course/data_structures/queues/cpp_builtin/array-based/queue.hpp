#pragma once

#include <boost/circular_buffer.hpp>

template <typename T>
class Queue
{
    // protected:
        // STL structure here

    public:
        Queue();
        Queue(int desired_size);

        void enqueue(T value);
        T dequeue();
        bool empty();
        bool full();
};

#include "queue.cpp"
