#include <stdexcept>
#include <cmath>

// todo: delete after dev
#include <iostream>

#pragma region Privates

template <typename T>
long long unsigned HashTable<T>::compute_initial_hash(std::string key)
{
    // todo: redo this to universal hashing method

    // pre-hashing
    long long unsigned prehash_digest = 0;
    std::size_t key_length = key.length();

    for (std::size_t i = 0; i < key_length; i++)
        // creates a binary stream out of every char
        // hashing may occur because of long long unsigned overflow
        prehash_digest += ((int) key[i]) << i * sizeof key[i] * 8;

    // via https://courses.csail.mit.edu/6.006/spring11/rec/rec05.pdf
    static constexpr double A = (sqrt(5.0) - 1) / 2;

    // hashing
    std::size_t hash_digest = floor(_capacity * (prehash_digest * A));

    return hash_digest;
}

template <typename T>
std::size_t HashTable<T>::next_probing_index(size_t previosIndex)
{
    // linear probing
    return ++previosIndex % _capacity;
}

template <typename T>
std::size_t HashTable<T>::find_index_for(std::string key, Contractor_t contractor)
{
    // todo: make this resolve at compile time, maybe via templates
    bool is_insertion = contractor == Contractor_t::insertion;

    std::size_t probe_index = compute_initial_hash(key) % _capacity;

    for(std::size_t trial = 0; trial < _capacity; trial++)
    {
        if (_data[probe_index].state == State::empty
        or (is_insertion and (_data[probe_index].state == State::deleted))
        or (_data[probe_index].key == key))
            return probe_index;

        probe_index = next_probing_index(probe_index);
    }

    throw std::range_error("Index non-existent");
}

#pragma endregion

#pragma region Constructors, destructor, assignment operators

template <typename T>
HashTable<T>::HashTable(std::size_t desired_capacity) : _size(0)
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
    // todo: write test
    // todo: implement
}

template <typename T>
HashTable<T>& HashTable<T>::operator=(const HashTable<T>& rhs)
{
    // todo: write test
    // todo: implement
}

template <typename T>
HashTable<T>::HashTable(HashTable<T>&& rhs)
{
    // todo: write test
    // todo: implement
}

template <typename T>
HashTable<T>& HashTable<T>::operator=(HashTable<T>&& rhs)
{
    // todo: write test
    // todo: implement
}

#pragma endregion

#pragma region Public functions

template <typename T>
void HashTable<T>::add(std::string key, T value)
{
    if (_size == _capacity)
        throw std::runtime_error("Insertion attempt on full table");

    std::size_t target_index = find_index_for(key, Contractor_t::insertion);

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
    try
    {
        std::size_t target_index = find_index_for(key);
        return _data[target_index].state == State::occupied;
    }
    catch(std::range_error& exception)
    {
        return false;
    }
}

template <typename T>
T HashTable<T>::get(std::string key)
{
    try
    {
        std::size_t target_index = find_index_for(key);

        if (_data[target_index].state == State::empty)
            throw std::runtime_error("Non-existing key dereference attempt");

        return _data[target_index].value;
    }
    catch(std::range_error& exception)
    {
        throw std::runtime_error("Non-existing key dereference attempt");
    }
}

template <typename T>
void HashTable<T>::remove(std::string key)
{
    try
    {
        std::size_t target_index = find_index_for(key);

        if(_data[target_index].state == State::occupied)
        {
            _size--;
            _data[target_index].state = State::deleted;
        }
    }
    catch(std::range_error& exception) {}
}

#pragma endregion

#pragma region Operators

template <typename T>
bool HashTable<T>::operator== (const HashTable<T>& rhs)
{
    // todo: write test
    // todo: implement
}

template <typename T>
bool HashTable<T>::operator!= (const HashTable<T>& rhs)
{
    // todo: write test
    // todo: implement
}

#pragma endregion