#include <stdexcept>

template <typename T>
ListNode<T>::ListNode(T value, ListNode* next) : value(value), next(next) {}

template <typename T>
ListNode<T>::ListNode(ListNode* next) : next(next) {}

template <typename T>
ListNode<T>::ListNode() {}



#pragma region Constructors, destructor, assignemt operators

template <typename T>
List<T>::List() : _size(0)
{
    backSentinel = new ListNode<T>();
    frontSentinel = new ListNode<T>(backSentinel);
    last = frontSentinel;
}

template <typename T>
List<T>::~List()
{
    // iterate through all nodes and destroy them

    delete frontSentinel;
    delete backSentinel;
}

#pragma endregion

#pragma region Private

template <typename T>
int List<T>::endIndex()
{
    return _size - 1;
}

template <typename T>
ListNode<T>* List<T>::nodeAt(int index)
{
    if (index == endIndex())
        return last;

    ListNode<T>* node = frontSentinel;

    for(int i = -1; i < index ; i++)
        node = node->next;

    return node;
}

template <typename T>
ListNode<T>* List<T>::nodeBefore(int index)
{
    return nodeAt(index - 1);
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
T List<T>::at(int index)
{
    if (index < 0)
        throw std::out_of_range("Negative index access attempt");

    if ( index > endIndex() )
        throw std::invalid_argument("Out of bounds access attempt");

    return nodeAt(index)->value;
}

template <typename T>
int List<T>::size()
{
    return _size;
}

template <typename T>
T List<T>::erase(int index)
{
    ListNode<T>* preErased = nodeBefore(index);
    ListNode<T>* erasedNode = preErased->next;

    T valueOfDeleted = erasedNode->value;
    preErased->next = erasedNode->next;

    delete erasedNode;

    // bookkeeping
    if (index == endIndex())
        last = preErased;
    _size--;

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

#pragma endregion