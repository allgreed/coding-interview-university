#include "vector.hpp"

// ****************************
// Utility
// ****************************

// @size [bytes]
// void* reallocate(int* pointer, int size)
// {
//     void* retval = realloc(pointer, size);

//     if (retval == NULL)
//     {
//         fprintf( stderr, "Failed allocation with realloc\n");
//         exit(VECTOR_EXIT_FAILED_ALLOCATION);
//     }
//     else
//         return retval;
// }

template <typename T> int Vector<T>::_toNearestGreaterBinaryPower(int desiredCapacity)
{
    int actualCapacity = abs(desiredCapacity);

    if(actualCapacity == 0)
        return 1;

    actualCapacity--;
    actualCapacity |= actualCapacity >> 1;
    actualCapacity |= actualCapacity >> 2;
    actualCapacity |= actualCapacity >> 4;
    actualCapacity |= actualCapacity >> 8;
    actualCapacity |= actualCapacity >> 16;
    actualCapacity++;

    return actualCapacity;
}

template <typename T> int Vector<T>::_maxIndex()
{
    return (size - 1);
}

template <typename T> void Vector<T>::_inc()
{
    size++;

//     if(Vector_size(vector) == Vector_capacity(vector))
//         Vector__expand(vector);
}

template <typename T> void Vector<T>::_dec()
{
    size--;

//     if(Vector_size(vector) <= Vector_capacity(vector) / VECTOR_SHRINK_TRIGGER)
//         Vector__shrink(vector);
}

// ****************************
// Private utilities
// ****************************

// void Vector__resize(Vector* vector, int desiredCapacity)
// {
//     vector->data = reallocate(vector->data, desiredCapacity * sizeof(int));
//     vector->capacity = desiredCapacity;
// }

// void Vector__expand(Vector* vector)
// {
//     Vector__resize(vector, Vector_capacity(vector) * VECTOR_GROWTH_FACTOR);
// }

// void Vector__shrink(Vector* vector)
// {
//     Vector__resize(vector, Vector_capacity(vector) / VECTOR_GROWTH_FACTOR);
// }

// }

#pragma region Create and destroy

template <typename T> Vector<T>::Vector()
{
    data = new T[capacity];
}

template <typename T> Vector<T>::Vector(int desiredCapacity)
{
    capacity = _toNearestGreaterBinaryPower(desiredCapacity);
    Vector();
}

template <typename T> Vector<T>::~Vector()
{
    delete[] data;
}

#pragma endregion

#pragma region Getters & setters

template <typename T> void Vector<T>::_runIndexChecks(int index)
{
    if (index < 0)
    {
        std::cerr << "ERR: Negative index access attempt: index was " << index << std::endl;
        throw std::out_of_range("Negative index access attempt");
    }

    if ( index > _maxIndex() )
    {
        std::cerr << "ERR: Out of bounds access attempt"
        << ", max: "  << _maxIndex()
        << ", was: " << index << std::endl;
        throw std::invalid_argument("Out of bounds access attempt");
    }
}

template <typename T> T Vector<T>::at(int index)
{
    _runIndexChecks(index);

    return data[index];
}

template <typename T> void Vector<T>::update_at(int index, T value)
{
    _runIndexChecks(index);

    data[index] = value;
}

template <typename T> int Vector<T>::whatSize()
{
    return size;
}

template <typename T> int Vector<T>::whatCapacity()
{
    return capacity;
}

#pragma endregion

#pragma region Basic operations

template <typename T> void Vector<T>::delete_at(int index)
{
    for(int i = index; i < _maxIndex(); i++)
        update_at(i, at(i + 1));

    _dec();
}

template <typename T> void Vector<T>::insert_at(int index, T value)
{
    _inc();

    for(int i = _maxIndex(); i > index; i--)
        update_at(i, at(i - 1));

    update_at(index, value);
}

#pragma endregion

#pragma region Derived

template <typename T> bool Vector<T>::isEmpty()
{
    return (size == 0);
}

template <typename T> T Vector<T>::pop()
{
    int retval = at(_maxIndex());
    delete_at(_maxIndex());
    return retval;
}

template <typename T> void Vector<T>::push(T value)
{
    insert_at(_maxIndex()+1, value);
}


template <typename T> void Vector<T>::prepend(T value)
{
    insert_at(0, value);
}

template <typename T> int Vector<T>::find(T value)
{
    for(int i = 0; i <= _maxIndex(); i++)
        if (at(i) == value) return i;

    return -1;
}

#pragma endregion

#pragma region Advanced
template <typename T> void Vector<T>::remove(T value)
{
    int removedItems = 0;
    int copyingIndex = 0;
    int searchIndex=0;
    int nextValidItemIndex = 0;

    auto nd_find = [&removedItems, this, value, &nextValidItemIndex, &searchIndex]() -> int
    {
        for(int i = searchIndex; i <= _maxIndex(); i++)
        {
            if (at(i) != value)
            {
                nextValidItemIndex = i;
                searchIndex = nextValidItemIndex + 1;
                return i;
            }

            removedItems++;
        }

        return -1;
    };

    while(nd_find() != -1)
    {
        update_at(copyingIndex, at(nextValidItemIndex));
        copyingIndex++;
    }

    // bookkeeping
    size -= removedItems;
}
#pragma endregion


template class Vector<int>;
