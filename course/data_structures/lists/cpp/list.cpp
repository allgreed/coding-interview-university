// import what's needed for the implementation

#pragma region Constructors, destructor, assignemt operators

template <typename T>
List<T>::List()
 : _size(0), _first(nullptr), _last(nullptr)
{
    // allocate last sentinel
}

template <typename T>
List<T>::~List()
{

}

#pragma endregion

#pragma region Private

template <typename T>
int List<T>::endIndex()
{
    return _size - 1;
}

#pragma endregion

#pragma region Basic operations

template <typename T>
void List<T>::insert(int index, T value)
{

}

template <typename T>
T List<T>::at(int index)
{
    if (index < 0)
        throw std::out_of_range("Negative index access attempt");

    if ( index > endIndex() )
        throw std::invalid_argument("Out of bounds access attempt");

    ListNode<T>* node = _first;

    for(int i = 0; i < index ; i++)
        node = node->next;

    return node->value;
}

#pragma endregion
