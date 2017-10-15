#include <algorithm>

#pragma region Basic operations

template <typename T>
void List<T>::insert(int index, T value)
{
    _list.insert(std::next(_list.begin(), index) ,value);
}

template <typename T>
T List<T>::at(int index) const
{
    return *(std::next(_list.begin(), index));
}

template <typename T>
int List<T>::size() const
{
    return _list.size();
}

template <typename T>
void List<T>::erase(int index)
{
    _list.erase(std::next(_list.begin(), index));
}

#pragma endregion

#pragma region Derived

template <typename T>
void List<T>::push_front(T value)
{
    _list.push_front(value);
}

template <typename T>
T List<T>::pop_front()
{
    T tmp = _list.front();
    _list.pop_front();
    return tmp;
}

template <typename T>
void List<T>::push_back(T value)
{
    _list.push_back(value);
}

template <typename T>
T List<T>::pop_back()
{
    T tmp = _list.back();
    _list.pop_back();
    return tmp;
}

template <typename T>
bool List<T>::empty() const
{
    return _list.empty();
}

template <typename T>
T List<T>::back()
{
    return _list.back();
}

template <typename T>
T List<T>::front()
{
    return _list.front();
}

template <typename T>
T List<T>::value_n_from_end(int reverseIndex)
{
    return *(std::next(_list.rbegin(), reverseIndex));
}

#pragma endregion

#pragma region Advanced

template <typename T>
void List<T>::reverse()
{
    _list.reverse();
}

// todo: delete after dev
#include <iostream>

template <typename T>
void List<T>::remove_value(T value)
{
    // do pokminienia jutro ;)
    auto element = std::find(_list.begin(), std::next(_list.end(), 1), value);

    if (element != std::next(_list.end(), 1))
        _list.erase(element);
}

#pragma endregion