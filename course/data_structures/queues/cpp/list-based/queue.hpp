#pragma once

template <typename T>
class Queue
{
    protected:
        struct Queue_node
        {
            T value;
            Queue_node* next;

            Queue_node(T value);
            Queue_node(Queue_node* pointer);
        };

    protected:
        Queue_node* head;
        Queue_node* tail;

    protected:
        void traverse(Queue_node*& nodePointer);
        template <typename... args_t> void traverse(Queue_node*& nodePointer, args_t&... args);

    public:
        Queue();
        ~Queue();
        Queue(const Queue<T>& rhs);
        Queue<T>& operator=(const Queue<T>& rhs);
        Queue(Queue<T>&& rhs);
        Queue<T>& operator=(Queue<T>&& rhs);

        void enqueue(T value);
        T dequeue();
        bool empty();

        bool operator==(const Queue<T>& rhs);
        bool operator!=(const Queue<T>& rhs);
};

#include "queue.cpp"
