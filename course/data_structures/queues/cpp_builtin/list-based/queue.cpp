#include <algorithm>

// todo: delete after dev
#include <iostream>

#pragma region Operations

template <typename T>
void Queue<T>::enqueue(T value)
{
    _queue.push(value);
}

template <typename T>
T Queue<T>::dequeue()
{
    T retval = _queue.front();
    _queue.pop();
    return retval;
}

template <typename T>
bool Queue<T>::empty()
{
    return _queue.empty();
}

#pragma endregion
