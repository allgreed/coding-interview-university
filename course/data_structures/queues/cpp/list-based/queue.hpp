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
        // redo this to something more general -> variadic templates
        void traverse(Queue_node*& nodePointer)
        {
            nodePointer = nodePointer->next;
        }
        void traverse(Queue_node*& nodePointer, Queue_node*& anotherNodePointer)
        {
            nodePointer = nodePointer->next;
            anotherNodePointer = anotherNodePointer->next;
        }
        void traverse(Queue_node*& nodePointer, Queue_node*& anotherNodePointer, Queue_node*& nextanotherNodePointer, Queue_node*& moaranotherNodePointer)
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
        Queue(Queue<T>&& rhs);
        Queue<T>& operator=(Queue<T>&& rhs);

        void enqueue(T value);
        T dequeue();
        bool empty();

        bool operator==(const Queue<T>& rhs);
        bool operator!=(const Queue<T>& rhs);
};

// Only if class is using generic templates
#include "queue.cpp"
