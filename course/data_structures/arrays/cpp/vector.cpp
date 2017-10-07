#pragma region Utilities

template <typename T> void Vector<T>::resize(int desiredCapacity)
{
    T* old = data;

    data = new T[desiredCapacity];

    for(int i = 0; i <= endIndex(); i++)
        data[i]=old[i];

    delete[] old;

    capacity = desiredCapacity;
}

template <typename T> int Vector<T>::endIndex()
{
    return (size - 1);
}

#pragma endregion

#pragma region Create and destroy

template <typename T> Vector<T>::Vector() : Vector(16)
{

}

template <typename T> Vector<T>::Vector(int desiredCapacity)
{
    auto toNearestGreaterBinaryPower= [](int desiredCapacity) -> int
    {
        int actualCapacity = abs(desiredCapacity);

        actualCapacity--;
        actualCapacity |= actualCapacity >> 1;
        actualCapacity |= actualCapacity >> 2;
        actualCapacity |= actualCapacity >> 4;
        actualCapacity |= actualCapacity >> 8;
        actualCapacity |= actualCapacity >> 16;
        actualCapacity++;

        return actualCapacity;
    };

    capacity = toNearestGreaterBinaryPower(desiredCapacity);

    data = new T[capacity];
}

template <typename T> Vector<T>::~Vector()
{
    delete[] data;
}

#pragma endregion

#pragma region Getters & setters

template <typename T> void Vector<T>::runIndexChecks(int index)
{
    if (index < 0)
        throw std::out_of_range("Negative index access attempt");


    if ( index > endIndex() )
        throw std::invalid_argument("Out of bounds access attempt");
}

template <typename T> T Vector<T>::at(int index)
{
    runIndexChecks(index);

    return data[index];
}

template <typename T> void Vector<T>::update_at(int index, T value)
{
    runIndexChecks(index);

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
    for(int i = index; i < endIndex(); i++)
        update_at(i, at(i + 1));

    size--;

    if(size <= capacity / VECTOR_SHRINK_TRIGGER)
        resize(capacity / VECTOR_GROWTH_FACTOR);
}

template <typename T> void Vector<T>::insert_at(int index, T value)
{
    size++;

    if(capacity == 0)
        resize(1);
    else if(size == capacity)
        resize(capacity * VECTOR_GROWTH_FACTOR);

    for(int i = endIndex(); i > index; i--)
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
    int retval = at(endIndex());
    delete_at(endIndex());
    return retval;
}

template <typename T> void Vector<T>::push(T value)
{
    insert_at(endIndex()+1, value);
}


template <typename T> void Vector<T>::prepend(T value)
{
    insert_at(0, value);
}

template <typename T> int Vector<T>::find(T value)
{
    for(int i = 0; i <= endIndex(); i++)
        if (at(i) == value) return i;

    return -1;
}

#pragma endregion

#pragma region Advanced
template <typename T> void Vector<T>::remove(T value)
{
    auto isExistNextValidItem = [&](int searchIndex) -> int
    {
        for(int i = searchIndex + 1; i <= endIndex(); i++)
            if (at(i) != value)
                return i;

        return -1;
    };

    int copyingIndex = 0;

    for (int nextValidItemIndex = -1;
        (nextValidItemIndex = isExistNextValidItem(nextValidItemIndex)) != -1;
         copyingIndex++)
        update_at(copyingIndex, at(nextValidItemIndex));

    // bookkeeping
    size = copyingIndex;
}
#pragma endregion
