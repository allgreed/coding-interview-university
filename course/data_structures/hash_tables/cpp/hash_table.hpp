#pragma once
// Warning: this library may throw

#include <string>

// constants
constexpr size_t DEFAULT_SIZE = 10;

// typedef struct HashTable_locator
// {
//     bool is_valid;
//     size_t to_index;
// } HashTable_locator;

// typedef enum
// {
//     HASHTABLE_ELEM_EMPTY,
//     HASHTABLE_ELEM_DELETED,
//     HASHTABLE_ELEM_OCCUPIED
// } HASHTABLE_ELEM_STATE;

// struct _element
// {
//     T value;
//     std::string key;
//     // HASHTABLE_ELEM_STATE state;
// };

template <typename T>
class HashTable
{
    protected:


    protected:
        // HashTable_element* data;
        size_t _capacity;
        size_t _size;

    protected:

    public:
        HashTable();
        ~HashTable();
        HashTable(const HashTable<T>& rhs);
        HashTable<T>& operator=(const HashTable<T>& rhs);
        HashTable(HashTable<T>&& rhs);
        HashTable<T>& operator=(HashTable<T>&& rhs);

    public:
        void add(std::string key, T value);
        bool exists(std::string key);
        T get(std::string key);
        void remove(std::string key);
};

#include "hash_table.cpp"
