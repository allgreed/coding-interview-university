#pragma once

// move this inside Queue
template <typename T>
struct Queue_node
{
    T value;
    Queue_node<T>* next;

    // move this to implementation
    Queue_node(T value) : value(value), next(nullptr) {}
    Queue_node(Queue_node<T>* pointer) : next(pointer) {}
};

template <typename T>
class Queue
{
    protected:
        Queue_node<T>* head;
        Queue_node<T>* tail;

    protected:
        // redo this to something more general -> variadic templates
        void traverse(Queue_node<T>*& nodePointer)
        {
            nodePointer = nodePointer->next;
        }
        void traverse(Queue_node<T>*& nodePointer, Queue_node<T>*& anotherNodePointer)
        {
            nodePointer = nodePointer->next;
            anotherNodePointer = anotherNodePointer->next;
        }
        void traverse(Queue_node<T>*& nodePointer, Queue_node<T>*& anotherNodePointer, Queue_node<T>*& nextanotherNodePointer, Queue_node<T>*& moaranotherNodePointer)
        {
            nodePointer = nodePointer->next;
            anotherNodePointer = anotherNodePointer->next;
            nextanotherNodePointer = nextanotherNodePointer->next;
            moaranotherNodePointer = moaranotherNodePointer->next;
        }

    public:
        Queue();
        ~Queue();
        Queue(const Queue<T>& rhs);
        Queue<T>& operator=(const Queue<T>& rhs);
        // move constructor
        // move assignemnt operator

        void enqueue(T value);
        T dequeue();
        bool empty();

        bool operator==(const Queue<T>& rhs);
        bool operator!=(const Queue<T>& rhs);
};

// Only if class is using generic templates
#include "queue.cpp"
