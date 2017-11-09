#include <stdexcept>

// todo: delete after dev
#include <iostream>

#pragma region Privates

template <typename T>
long long unsigned HashTable<T>::compute_initial_hash(std::string key)
{
    // todo: do some real hashing here
    // todo: redo this to universal hashing method
    return 0;
}

template <typename T>
std::size_t HashTable<T>::compute_probing_index(long long unsigned hash_digest, std::size_t trial)
{
    // linear probing
    return (hash_digest + trial) % _capacity;
}

template <typename T>
std::size_t HashTable<T>::find_index_for(std::string key)
{
    // todo: parametrize this
    bool is_insertion = true;

    long long unsigned hash_digest = compute_initial_hash(key);

    for(size_t trial = 0; trial < _capacity; trial++)
    {
        size_t target_index = compute_probing_index(hash_digest, trial);

        if (_data[target_index].state == State::empty
        or (is_insertion and (_data[target_index].state == State::deleted))
        or (_data[target_index].key == key))
            return target_index;
    }

    throw std::range_error("Index non-existent");
}

#pragma endregion

#pragma region Constructors, destructor, assignment operators

template <typename T>
HashTable<T>::HashTable(size_t desired_capacity) : _size(0)
{
    // todo: this should be rounded to the nearest power of 2
    // todo: shall it?
    // todo: if not -> move this to initializer list
    _capacity = desired_capacity;

    _data = new Element[_capacity];
}

template <typename T>
HashTable<T>::HashTable() : HashTable(Default_size) {}

template <typename T>
HashTable<T>::~HashTable()
{
    delete[] _data;
}

template <typename T>
HashTable<T>::HashTable(const HashTable<T>& rhs)
{

}

template <typename T>
HashTable<T>& HashTable<T>::operator=(const HashTable<T>& rhs)
{

}

template <typename T>
HashTable<T>::HashTable(HashTable<T>&& rhs)
{

}

template <typename T>
HashTable<T>& HashTable<T>::operator=(HashTable<T>&& rhs)
{

}

#pragma endregion

#pragma region Public functions

template <typename T>
void HashTable<T>::add(std::string key, T value)
{
    if (_size == _capacity)
        throw std::runtime_error("Insertion attempt on full table");

    size_t target_index = find_index_for(key);

    if(not (_data[target_index].state == State::occupied))
    {
        _data[target_index].key = key;
        _size++;
    }

    _data[target_index].value = value;
    _data[target_index].state = State::occupied;
}

template <typename T>
bool HashTable<T>::exists(std::string key)
{
    // size_t target_index;

    // try
    // {
    //     target_index = find_index_for(key);
    // }
    // catch(std::range_error& exception)
    // {
    //     return false;
    // }

    // return _data[target_index].state != State::empty;
}

template <typename T>
T HashTable<T>::get(std::string key)
{
    size_t target_index;

    try
    {
        target_index = find_index_for(key);
    }
    catch(std::range_error& exception)
    {
        throw std::runtime_error("Non-existing key dereference attempt");
    }

    if (_data[target_index].state == State::empty)
        throw std::runtime_error("Non-existing key dereference attempt");

    return _data[target_index].value;
}

template <typename T>
void HashTable<T>::remove(std::string key)
{
    // try
    // {
    //     target_index = find_index_for(key);

    //     //todo: delete if not empty
    // }
    // catch(std::range_error& exception) {}
}

#pragma endregion
