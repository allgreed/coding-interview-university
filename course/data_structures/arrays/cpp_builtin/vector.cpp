#pragma region Create and destroy

template <typename T> Vector<T>::Vector() : Vector(16)
{

}

template <typename T> Vector<T>::Vector(int desiredCapacity)
{
    vector.reserve(desiredCapacity);
}

template <typename T> Vector<T>::~Vector()
{

}

#pragma endregion

#pragma region Getters & setters

template <typename T> T Vector<T>::at(int index)
{
    return vector[index];
}

template <typename T> void Vector<T>::update_at(int index, T value)
{
    vector[index] = value;
}

template <typename T> int Vector<T>::whatSize()
{
    return vector.size();
}

template <typename T> int Vector<T>::whatCapacity()
{
    return vector.capacity();
}

#pragma endregion

#pragma region Basic operations

template <typename T> void Vector<T>::delete_at(int index)
{
    vector.erase(vector.begin()+index);
}

template <typename T> void Vector<T>::insert_at(int index, T value)
{
    vector.insert(vector.begin()+index, value);
}

#pragma endregion

#pragma region Derived

template <typename T> bool Vector<T>::isEmpty()
{
    return vector.empty();
}

template <typename T> T Vector<T>::pop()
{
    T retval = vector.back();
    vector.pop_back();
    return retval;
}

template <typename T> void Vector<T>::push(T value)
{
    vector.push_back(value);
}


template <typename T> void Vector<T>::prepend(T value)
{
    vector.insert(vector.begin(), value);
}

#include<iostream>

template <typename T> int Vector<T>::find(T value)
{
    std::vector<int>::iterator searchIterator = std::find(vector.begin(), vector.end()+1, value);

    if (searchIterator != vector.end()+1)
        return std::distance(vector.begin(), searchIterator);
    else
        return -1;
}

#pragma endregion

#pragma region Advanced
template <typename T> void Vector<T>::remove(T value)
{
    vector.erase(std::remove(vector.begin(), vector.end(), value), vector.end());
}
#pragma endregion
