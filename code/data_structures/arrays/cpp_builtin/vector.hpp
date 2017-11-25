#pragma once

// Warning: this library may throw
#include <stdexcept>

#include <vector>
#include <algorithm>

template <typename T>
class Vector
{
protected:
    std::vector<T> vector;

public:
    Vector(int desiredCapacity);
    Vector();
    ~Vector();

    // Basic getters-setters
    int whatSize();
    int whatCapacity();

    T at(int index);
    void update_at(int index, T value);

    // Basic operations
    void delete_at(int index);
    void insert_at(int index, T value);

    // Derived
    bool isEmpty();
    T pop();
    void push(T value);
    void prepend(T value);
    int find(T value);

    // Advanced
    void remove(T value);
};

#include "vector.cpp"
