// Warning: this library may throw
#include <stdexcept>

#include <algorithm>

#pragma region

template <typename T>
Queue<T>::Queue_node::Queue_node(T value) : value(value), next(nullptr) {}

template <typename T>
Queue<T>::Queue_node::Queue_node(Queue_node* pointer) : next(pointer) {}

#pragma endregion

// todo: delete after dev
#include <iostream>

#pragma region Constructors, assigments, destructor

template <typename T>
Queue<T>::Queue() : head(nullptr), tail(nullptr) {}


template <typename T>
Queue<T>::~Queue()
{
    Queue_node dummyThis = Queue_node(head);
    Queue_node* current = &dummyThis;

    for(Queue_node* next = head; next != nullptr; delete current)
        traverse(current, next);
}

template <typename T>
Queue<T>::Queue(const Queue<T>& rhs) : Queue()
{
    *this = rhs;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rhs)
{
    Queue_node* next = head, * rhs_next = rhs.head;

    Queue_node dummyThis = Queue_node(next);
    Queue_node dummyRhs = Queue_node(rhs_next);

    Queue_node* current = &dummyThis, * rhs_current = &dummyRhs;

    for(; (next != nullptr) && (rhs_next != nullptr); current->value = rhs_current->value)
        traverse(current, rhs_current, next, rhs_next);

    if(next == rhs_next) {}
    else if (rhs_next == nullptr)
    {
        for(tail = current; next != nullptr; delete current)
            traverse(current, next);

        tail->next = nullptr;

        if (tail == &dummyThis)
        {
            head = nullptr;
            tail = nullptr;
        }
    }
    else
        for(; rhs_next != nullptr; enqueue(rhs_current->value))
            traverse(rhs_current, rhs_next);

    return *this;
}

template <typename T>
Queue<T>::Queue(Queue<T>&& rhs) : Queue()
{
    *this = std::move(rhs);
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue<T>&& rhs)
{
    std::swap(rhs.tail, tail);
    std::swap(rhs.head, head);
    return *this;
}

#pragma endregion

#pragma region Operations

template <typename T>
void Queue<T>::enqueue(T value)
{
    auto newNode = new Queue_node(value);

    if(empty())
        head = newNode;
    else
        tail->next = newNode;

    tail = newNode;
}

template <typename T>
T Queue<T>::dequeue()
{
    if(empty())
        throw std::runtime_error("Dequeue attempt on empty queue");

    T retval = head->value;

    Queue_node* dequeued_node = head;
    head = dequeued_node->next;
    delete dequeued_node;

    return retval;
}

template <typename T>
bool Queue<T>::empty()
{
    return (head == nullptr);
}

#pragma endregion

#pragma region Operators

template <typename T>
bool Queue<T>::operator==(const Queue<T>& rhs)
{
    Queue_node* current = head;
    Queue_node* rhs_current = rhs.head;

    for(;(current != nullptr) && (rhs_current != nullptr); traverse(current, rhs_current))
        if (current->value != rhs_current->value)
            return false;

    if(current != rhs_current)
        return false;

    return true;
}

template <typename T>
bool Queue<T>::operator!=(const Queue<T>& rhs)
{
    return !(*this == rhs);
}

#pragma endregion