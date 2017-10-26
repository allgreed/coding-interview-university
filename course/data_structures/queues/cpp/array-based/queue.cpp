#include <stdexcept>
#include <cstring>

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

// template <typename T>
// move ass

// template <typename T>
// move cons


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
    // reeeefactor when done!

    struct Chunk_map
    {
        T* begin;
        int size;

        // Chunk_map(T* ptr, int size) : begin(ptr), size(size) {};
    };

    struct Chunked_data_array_map
    {
        Chunk_map main;
        Chunk_map rest;

        Chunked_data_array_map(T* data_array, int size, int begin_index)
        {
            // create two chunks
        }
    };

    if(_size != rhs._size)
        return false;

    return (bool) !std::memcmp(this->_data + _begin_index, rhs._data + rhs._begin_index, sizeof(T) * _size);

    // compare two buffers if buffers wrap around

    // auto lhs_chunked = Chunked_data_array_map(this->_data, _size, _begin_index);
    // auto rhs_chunked = Chunked_data_array_map(rhs._data, rhs._size, rhs._begin_index);
    // compare memory by maps
    // return compare result
}

template <typename T>
bool Queue<T>::operator!=(const Queue<T>& rhs)
{
    return !( *this == rhs );
}

#pragma endregion