#pragma once
// Warning: this library may throw

#include <string>

template <typename T>
class HashTable
{
    protected:
        static constexpr std::size_t default_size = 10;

    protected:
        enum class Caller
        {
            insertion,
            other
        };

        class Hasher
        {
            // hashing constants required for computations
            protected:
                long long unsigned A, B, P;
                std::size_t index_boundry;

            public:
                Hasher(std::size_t table_capacity);
                Hasher() = default;

            public:
                inline long long unsigned compute_initial_hash(std::string key) const;
                inline std::size_t next_probing_index(std::size_t previous_index) const;
        };

        struct Element
        {
            enum class State
            {
                empty,
                deleted,
                occupied
            };

            T value;
            std::string key;
            State state = State::empty;
        };

    protected:
        std::size_t _size;
        std::size_t _capacity;
        Hasher _hasher;
        Element* _data;

    protected:
        template <Caller _caller = Caller::other>
        std::size_t resolve_to_index(std::string key) const;

    public:
        HashTable();
        HashTable(std::size_t desired_capacity);
        ~HashTable();
        HashTable(const HashTable<T>& rhs);
        HashTable<T>& operator=(const HashTable<T>& rhs);
        HashTable(HashTable<T>&& rhs);
        HashTable<T>& operator=(HashTable<T>&& rhs);

    public:
        void add(std::string key, T value);
        bool exists(std::string key) const;
        T get(std::string key) const;
        void remove(std::string key);

    public:
        bool operator== (const HashTable<T>& rhs);
        bool operator!= (const HashTable<T>& rhs);
};

#include "hash_table.cpp"
