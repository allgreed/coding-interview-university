#pragma region Public functions

template <typename T>
void HashTable<T>::add(std::string key, T value)
{
    _hash_map[key] = value;
}

template <typename T>
bool HashTable<T>::exists(std::string key) const
{
    auto it = _hash_map.find(key);
    return not(it == _hash_map.end());
}

template <typename T>
T HashTable<T>::get(std::string key) const
{
    return _hash_map.at(key);
}

template <typename T>
void HashTable<T>::remove(std::string key)
{
    _hash_map.erase(key);
}

#pragma endregion
