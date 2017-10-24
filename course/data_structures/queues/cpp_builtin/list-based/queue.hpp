#pragma once

#include <list>
#include <queue>

template <typename T>
class Queue
{
    protected:
        std::queue<T, std::list<T>> _queue;

    public:
        void enqueue(T value);
        T dequeue();
        bool empty();
};

#include "queue.cpp"
