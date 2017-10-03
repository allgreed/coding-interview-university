#pragma once

// Warning: this library may throw
#include <stdexcept>

const int VECTOR_DEFAULT_CAPACITY = 16;
const int VECTOR_GROWTH_FACTOR = 2;
const int VECTOR_SHRINK_TRIGGER = 4;

template <typename T>
class Vector
{
protected:
    int capacity;
    int size = 0;
    T* data = nullptr;

protected:
    void runIndexChecks(int index);
    void resize(int desiredCapacity);
    int endIndex();

    void _dec();
    void _inc();

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
