#include <stdexcept>

template <typename T>
ListNode<T>::ListNode(T value, ListNode* next) : value(value), next(next) {}

template <typename T>
ListNode<T>::ListNode(ListNode* next) : next(next) {}

template <typename T>
ListNode<T>::ListNode() {}



#pragma region Constructors, destructor, assignemt operators

template <typename T>
List<T>::List()
 : _size(0),  _last(nullptr)
{
    _first = new ListNode<T>(nullptr); //front sentinel
    // allocate last sentinel
}

template <typename T>
List<T>::~List()
{
    delete _first;
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
    ListNode<T>* node = _first;

    for(int i = -1; i < index ; i++)
        node = node->next;

    return node;

    // return tail pointer if requested end
}

#pragma endregion

#pragma region Basic operations

template <typename T>
void List<T>::insert(int index, T value)
{
    ListNode<T>* previous = nodeAt(index - 1);
    ListNode<T>* newNode = new ListNode<T>(value, previous->next);
    previous->next = newNode;
    _size++;

    // move tail-pointer if inserted at tail
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

#pragma endregion
