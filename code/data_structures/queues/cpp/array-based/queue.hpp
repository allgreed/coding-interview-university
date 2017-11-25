#pragma once
// Warning: this library may throw

template <typename T>
class Queue
{
    protected:
        static constexpr int DEFAULT_SIZE = 5;

    protected:
        int _begin_index;
        int _size;
        int _capacity;
        T* _data;

    public:
        Queue(int desired_size);
        Queue();
        ~Queue();
        Queue(const Queue<T>& rhs);
        Queue(Queue<T>&& rhs);
        Queue<T>& operator=(const Queue<T>& rhs);
        Queue<T>& operator=(Queue<T>&& rhs);

        void enqueue(T value);
        T dequeue();
        bool empty();
        bool full();

        bool operator==(const Queue<T>& rhs);
        bool operator!=(const Queue<T>& rhs);
};

#include "queue.cpp"
