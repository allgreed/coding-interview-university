#include <stdexcept>
#include <cstring>
#include <algorithm>
#include <type_traits>

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

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rhs)
{
    if (_capacity != rhs._capacity)
    {
        _capacity = rhs._capacity;

        delete[] _data;
        _data = new T[_capacity];
    }

    _begin_index = 0;
    _size = rhs._size;

    if (empty())
        return *this;

    int first_chunk_element_count = std::min(rhs._size, rhs._capacity - rhs._begin_index);
    std::memcpy(_data, rhs._data + rhs._begin_index, sizeof(T) * first_chunk_element_count);

    int second_chunk_element_count = rhs._size - first_chunk_element_count;
    std::memcpy(_data + first_chunk_element_count, rhs._data, sizeof(T) * second_chunk_element_count);

    return *this;
}

template <typename T>
Queue<T>::Queue(const Queue<T>& rhs) : _capacity(-1), _data(nullptr)
{
    *this = rhs;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue<T>&& rhs)
{
    _begin_index = rhs._begin_index;
    _size = rhs._size;
    _capacity = rhs._capacity;
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

/* queue is considered equal to another queue if:
    - sizes are equal
    - capacities are equal
    - all elements are equal 
*/

template <typename T>
bool Queue<T>::operator==(const Queue<T>& rhs)
{

    if(_size != rhs._size or _capacity != rhs._capacity)
        return false;

    int uncompared_size = _size, lhs_cmp_ptr = _begin_index, rhs_cmp_ptr = rhs._begin_index;

    constexpr bool is_detailed_comparison_required =
        std::is_compound<T>::value and
        not std::is_pointer<T>::value; // and
        // has comparison operator implemented ;

    while(uncompared_size > 0)
    {
        int size_to_compare = is_detailed_comparison_required ?
            1 :
            std::min({uncompared_size, _capacity - lhs_cmp_ptr, _capacity - rhs_cmp_ptr});

        if(is_detailed_comparison_required)
        {
            if ( _data[(lhs_cmp_ptr) % _capacity] != rhs._data[(rhs_cmp_ptr) % _capacity] )
                return false;
        }
        else
            if(std::memcmp(_data + lhs_cmp_ptr, rhs._data + rhs_cmp_ptr, size_to_compare * sizeof(T)) != 0)
                return false;

        lhs_cmp_ptr = (lhs_cmp_ptr + size_to_compare) % _capacity;
        rhs_cmp_ptr = (rhs_cmp_ptr + size_to_compare) % _capacity;
        uncompared_size -= size_to_compare;
    }

    return true;
}

template <typename T>
bool Queue<T>::operator!=(const Queue<T>& rhs)
{
    return not (*this == rhs);
}

#pragma endregion
