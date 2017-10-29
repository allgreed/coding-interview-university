#include <stdexcept>
#include <cstring>
#include <algorithm>

// delete after dev
#include <iostream>

#pragma region Constructors, destructor, move & copy assignemnts

template <typename T>
Queue<T>::Queue() : Queue(Queue<T>::DEFAULT_SIZE) {}

template <typename T>
Queue<T>::Queue(int desired_size) :
    _begin_index(0),
    _size(0),
    _capacity(desired_size)
{
    _data = new T[desired_size];
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] _data;
}

// template <typename T>
// copy ass

// template <typename T>
// copy cons

template <typename T>
Queue<T>& Queue<T>::operator=(Queue<T>&& rhs)
{
    std::swap(_begin_index, rhs._begin_index);
    std::swap(_size, rhs._size);
    std::swap(_capacity, rhs._capacity);
    std::swap(_data, rhs._data);
    return *this;
}

template <typename T>
Queue<T>::Queue(Queue<T>&& rhs) : _data(nullptr)
{
    *this = std::move(rhs);
}

#pragma endregion

#pragma region Public implementation

template <typename T>
void Queue<T>::enqueue(T value)
{
    if(full())
        throw std::runtime_error("Enqueue attempt on full queue");

    int writeIndex = (_begin_index + _size) % _capacity;
    _data[writeIndex] = value;
    _size++;
}

template <typename T>
T Queue<T>::dequeue()
{
    if(empty())
        throw std::runtime_error("Dequeue attempt on empty queue");

    auto retval = _data[_begin_index];
    _begin_index = (_begin_index + 1) % _capacity;
    _size--;
    return retval;
}

template <typename T>
bool Queue<T>::empty()
{
    return (_size == 0);
}

template <typename T>
bool Queue<T>::full()
{
    return (_size == _capacity);
}

#pragma endregion

#pragma region Comparison operators

template <typename T>
bool Queue<T>::operator==(const Queue<T>& rhs)
{
    // queue is considered equal to another queue if:
    // - sizes are equal
    // - capacities are equal
    // - all elements are equal

    if(_size != rhs._size)
        return false;

    if (_capacity != rhs._capacity)
        return false;

    for(int i = 0; i < _size; i++)
        if ( _data[(_begin_index + i) % _capacity] != rhs._data[(rhs._begin_index + i) % _capacity] )
            return false;

    return true;
}

template <typename T>
bool Queue<T>::operator!=(const Queue<T>& rhs)
{
    return !( *this == rhs );
}

#pragma endregion