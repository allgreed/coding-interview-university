#include <stdexcept>

#pragma region Constructors, destructor, assignemt operators

// todo: delete after dev
#include <iostream>

template <typename T>
List<T>::List() : _size(0)
{
    backSentinel = new ListNode<T>;
    frontSentinel = new ListNode<T>(backSentinel);
    last = frontSentinel;
}

template <typename T>
List<T>::~List()
{
    ListNode<T>* next;

    for(ListNode<T>* current = frontSentinel; current != backSentinel; current = next)
    {
        next = current->next;
        delete current;
    }

    delete backSentinel;
}

template <typename T>
List<T>::List(const List<T> &list) : List()
{
    *this = list;
}

template <typename T>
List<T>& List<T>::operator=(const List<T> 
    &list)
{
    if (this != &list)
    {
        int sizeDifference = _size - list.size();
        int commonSize = (sizeDifference < 0) ? _size : list.size();

        ListNode<T>* current = frontSentinel->next;
        for(int i = 0; i < commonSize; i++)
        { 
            current -> value = list.at(i);
            current = current->next;
        }

        if (sizeDifference < 0)
        {
            sizeDifference = -sizeDifference;

            for (int i = 0; i < sizeDifference; i++)
                insert(_size, list.at(_size));
        }
        else if (sizeDifference > 0)
            for(int i = 0; i < sizeDifference; i++)
                erase(endIndex());
    }

    return *this;
}

#pragma endregion

#pragma region Private

template <typename T>
int List<T>::endIndex() const
{
    return _size - 1;
}

template <typename T>
List<T>::ListNode<T>* List<T>::nodeAt(int index) const
{
    if (index == endIndex())
        return last;

    ListNode<T>* node = frontSentinel;

    for(int i = -1; i < index ; i++)
        node = node->next;

    return node;
}

template <typename T>
List<T>::ListNode<T>* List<T>::nodeBefore(int index)
{
    return nodeAt(index - 1);
}

template <typename T>
void List<T>::nodeEraseAfter(ListNode<T>* preErased)
{
    ListNode<T>* erasedNode = preErased->next;
    preErased->next = erasedNode->next;

    delete erasedNode;

    // bookkeeping
    if (erasedNode->next == backSentinel)
        last = preErased;
    _size--;
}

#pragma endregion

#pragma region Basic operations

template <typename T>
void List<T>::insert(int index, T value)
{
    ListNode<T>* previous = nodeBefore(index);
    ListNode<T>* newNode = new ListNode<T>(value, previous->next);
    previous->next = newNode;

    // bookkeeping
    _size++;
    if (endIndex() == index)
        last = newNode;
}

template <typename T>
T List<T>::at(int index) const
{
    if (index < 0)
        throw std::out_of_range("Negative index access attempt");

    if ( index > endIndex() )
        throw std::invalid_argument("Out of bounds access attempt");

    return nodeAt(index)->value;
}

template <typename T>
int List<T>::size() const
{
    return _size;
}

template <typename T>
T List<T>::erase(int index)
{
    ListNode<T>* preErased = nodeBefore(index);

    T valueOfDeleted = preErased->next->value;
    nodeEraseAfter(preErased);

    // adds little time to erasing and simplifies pop implementation
    return valueOfDeleted;
}

#pragma endregion

#pragma region Derived

template <typename T>
void List<T>::push_front(T value)
{
    insert(0, value);
}

template <typename T>
T List<T>::pop_front()
{
    return erase(0);
}

template <typename T>
void List<T>::push_back(T value)
{
    insert(endIndex()+1, value);
}

template <typename T>
T List<T>::pop_back()
{
    return erase(endIndex());
}

template <typename T>
bool List<T>::empty() const
{
    return (_size == 0);
}

template <typename T>
T List<T>::back()
{
    return at(endIndex());
}

template <typename T>
T List<T>::front()
{
    return at(0);
}

template <typename T>
T List<T>::value_n_from_end(int reverseIndex)
{
    return at(endIndex() - reverseIndex);
}

template <typename T>
T List<T>::operator[](int i)
{
    return at(i);
}

#pragma endregion

#pragma region Advanced

template <typename T>
void List<T>::reverse()
{
    // Quit if reverse is not required
    if (_size < 2)
        return;

    // bookkeeping
    last = frontSentinel->next;

    ListNode<T>* current = frontSentinel->next;
    frontSentinel->next = backSentinel;
    
    for(ListNode<T>* next; next != backSentinel; current = next)
    {
        next = current->next;
        current->next = frontSentinel->next;
        frontSentinel->next = current;
    }
}

template <typename T>
void List<T>::remove_value(T value)
{
    backSentinel->value = value;
    ListNode<T>* before;

    for(ListNode<T>* current = frontSentinel; current->value != value; current = current->next)
        before = current;

    if(before->next != backSentinel)
        nodeEraseAfter(before);
}

template <typename T>
bool List<T>::operator==(const List<T>& compared)
{
    if (size() != compared.size())
        return false;

    if (empty() && compared.empty())
        return true;

    for(int i=0; i <= endIndex(); i++)
        if(this->at(i) != compared.at(i))
            return false;

    return true;
}

template <typename T>
bool List<T>::operator!=(const List<T>& compared)
{
    return !(*this == compared); 
}

#pragma endregion