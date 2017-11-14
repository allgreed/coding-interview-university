#pragma once

#include <unordered_map>
#include <string>

template <typename T>
class HashTable
{
    protected:
        std::unordered_map<std::string, T> _hash_map;

    public:
        HashTable() = default;
        void add(std::string key, T value);
        bool exists(std::string key) const;
        T get(std::string key) const;
        void remove(std::string key);
};

#include "hash_table.cpp"
