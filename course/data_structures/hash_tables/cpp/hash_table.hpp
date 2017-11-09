#pragma once
// Warning: this library may throw

#include <string>

template <typename T>
class HashTable
{
    // constants
    protected:
        static constexpr std::size_t Default_size = 10;

    // subclasses and internal structures
    protected:
        enum class State
        {
            empty,
            deleted,
            occupied
        };

        struct Element
        {
            T value;
            std::string key;
            State state = State::empty;
        };

        enum class Caller
        {
            insertion,
            other
        };

    // data members
    protected:
        Element* _data;
        std::size_t _capacity;
        std::size_t _size;

    // private functions
    protected:
        long long unsigned compute_initial_hash(std::string key);
        std::size_t next_probing_index(std::size_t previosIndex);
        template <Caller _caller = Caller::other> std::size_t find_index_for(std::string key);

    // constructing, assigning, destructing
    public:
        HashTable();
        HashTable(std::size_t desired_capacity);
        ~HashTable();
        HashTable(const HashTable<T>& rhs);
        HashTable<T>& operator=(const HashTable<T>& rhs);
        HashTable(HashTable<T>&& rhs);
        HashTable<T>& operator=(HashTable<T>&& rhs);

    // public functions
    public:
        void add(std::string key, T value);
        bool exists(std::string key);
        T get(std::string key);
        void remove(std::string key);

    // operators
    public:
        bool operator== (const HashTable<T>& rhs);
        bool operator!= (const HashTable<T>& rhs);
};

#include "hash_table.cpp"
