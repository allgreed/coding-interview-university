#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

#pragma region Privates

template <typename T>
HashTable<T>::Hasher::Hasher(std::size_t table_capacity)
    : index_boundry(table_capacity)
{
    // find all primes < index_boundry via sieve of Eratosthenes
    auto* sieve = new bool[index_boundry];

    for (std::size_t i = 0; i < index_boundry; i++)
        sieve[i] = true;

    for (size_t i = 2; i < index_boundry; i++)
    {
        if (sieve[i] == false) continue;
        for(size_t j = i << 1; j < index_boundry; j+=i)
            sieve[j] = false;
    }

    auto* prime_vector = new std::vector<long long unsigned>;

    for (size_t i = 3; i < index_boundry; i++)
        if (sieve[i]) prime_vector->push_back(i);

    delete[] sieve;

    // check all odd numbers >= index_boundry for primality
    long long unsigned prime_candidate = (index_boundry & 1) ? index_boundry : index_boundry - 1;
    bool is_prime = false;

    while(not is_prime)
    {
        is_prime = true;
        prime_candidate += 2;

        for(auto const& value: *prime_vector)
        {
            if(prime_candidate % value == 0)
            {
                is_prime = false;
                break;
            }
        }
    }

    delete prime_vector;
    P = prime_candidate;

    srand(time(nullptr));
    A = std::rand() % P + 1;
    B = std::rand() % P;
}

template <typename T>
inline long long unsigned HashTable<T>::Hasher::compute_initial_hash(std::string key) const
{
    // pre-hashing
    long long unsigned prehash_digest = 0;
    std::size_t key_length = key.length();

    for (std::size_t i = 0; i < key_length; i++)
        prehash_digest += ((int) key[i]) << i * sizeof key[i] * 8;

    // hashing
    long long unsigned hash_digest = (A * prehash_digest + B) % P % index_boundry;

    return hash_digest;
}

template <typename T>
inline std::size_t HashTable<T>::Hasher::next_probing_index(size_t previous_index) const
{
    // linear probing
    return ++previous_index % index_boundry;
}

template <typename T>
template <typename HashTable<T>::Caller _caller>
std::size_t HashTable<T>::resolve_to_index(std::string key) const
{
    std::size_t probe_index = _hasher.compute_initial_hash(key);

    for(std::size_t trial = 0; trial < _capacity; trial++)
    {
        if (_data[probe_index].state == Element::State::empty
        or (_caller == Caller::insertion and _data[probe_index].state == Element::State::deleted)
        or _data[probe_index].key == key)
            return probe_index;

        probe_index = _hasher.next_probing_index(probe_index);
    }

    throw std::range_error("Index non-existent");
}

#pragma endregion

#pragma region Constructors, destructor, assignment operators

template <typename T>
HashTable<T>::HashTable(std::size_t desired_capacity)
    :  _size(0), _capacity(desired_capacity), _hasher(_capacity)
{
    _data = new Element[_capacity];
}

template <typename T>
HashTable<T>::HashTable()
    : HashTable(default_size) 
{
    
}

template <typename T>
HashTable<T>::~HashTable()
{
    delete[] _data;
}

template <typename T>
HashTable<T>::HashTable(const HashTable<T>& rhs)
    : _capacity(0), _data(nullptr)
{
    *this = rhs;
}

template <typename T>
HashTable<T>& HashTable<T>::operator=(const HashTable<T>& rhs)
{
    if (_capacity != rhs._capacity)
    {
        delete[] _data;
        _data = new Element[rhs._capacity];
        _capacity = rhs._capacity;
    }
    else
    {
        for(std::size_t i = 0; i < _capacity; i++)
            _data[i].state = Element::State::empty;
    }

    _hasher = rhs._hasher;
    _size = 0;

    for(std::size_t i = 0; i < _capacity; i++)
        if(rhs._data[i].state == Element::State::occupied)
            add(rhs._data[i].key, rhs._data[i].value);

    return *this;
}

template <typename T>
HashTable<T>::HashTable(HashTable<T>&& rhs)
    : _data(nullptr)
{
    *this = std::move(rhs);
}

template <typename T>
HashTable<T>& HashTable<T>::operator=(HashTable<T>&& rhs)
{
    _size = rhs._size;
    _capacity = rhs._capacity;
    _hasher = rhs._hasher;
    std::swap(_data, rhs._data);

    return *this;
}

#pragma endregion

#pragma region Public functions

template <typename T>
void HashTable<T>::add(std::string key, T value)
{
    if (_size == _capacity)
        throw std::runtime_error("Insertion attempt on full table");

    std::size_t target_index = resolve_to_index<Caller::insertion>(key);

    if(not (_data[target_index].state == Element::State::occupied))
    {
        _data[target_index].key = key;
        _size++;
    }

    _data[target_index].value = value;
    _data[target_index].state = Element::State::occupied;
}

template <typename T>
bool HashTable<T>::exists(std::string key) const
{
    try
    {
        std::size_t target_index = resolve_to_index(key);
        return _data[target_index].state == Element::State::occupied;
    }
    catch(std::range_error& exception)
    {
        return false;
    }
}

template <typename T>
T HashTable<T>::get(std::string key) const
{
    try
    {
        std::size_t target_index = resolve_to_index(key);

        if (_data[target_index].state == Element::State::empty)
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
        std::size_t target_index = resolve_to_index(key);

        if(_data[target_index].state == Element::State::occupied)
        {
            _size--;
            _data[target_index].state = Element::State::deleted;
        }
    }
    catch(std::range_error& exception) {}
}

#pragma endregion

#pragma region Operators

template <typename T>
bool HashTable<T>::operator== (const HashTable<T>& rhs)
{
    if(_capacity != rhs._capacity)
        return false;

    if(_size != rhs._size)
        return false;

    for(std::size_t i = 0; i < _capacity; i++)
    {
        if(_data[i].state == Element::State::occupied)
        {
            try
            {
                if(rhs.get(_data[i].key) != _data[i].value)
                    return false;
            }
            catch (std::runtime_error& exception)
            {
                return false;
            }
        }
    }

    return true;
}

template <typename T>
bool HashTable<T>::operator!= (const HashTable<T>& rhs)
{
    return not (*this == rhs);
}

#pragma endregion
