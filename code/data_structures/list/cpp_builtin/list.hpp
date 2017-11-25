#pragma once

#include <list>

template <typename T>
class List
{
    protected:
        std::list<T> _list;

    public:
        // Basic operations
        void insert(int index, T value);
        T at(int index) const;
        void erase(int index);
        int size() const;

        // Derived
        void push_front(T value);
        T pop_front();
        void push_back(T value);
        T pop_back();
        bool empty() const;
        T back();
        T front();
        T value_n_from_end(int reverseIndex);

        // Advanced
        void reverse();
        void remove_value(T value);
};

// For truly type agnostic templates
#include "list.cpp"
