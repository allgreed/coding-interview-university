#pragma once

// Warning: this library may throw
#include <stdexcept>

#include <iostream>

extern const int VECTOR_DEFAULT_CAPACITY;
extern const int VECTOR_GROWTH_FACTOR;
extern const int VECTOR_SHRINK_TRIGGER;

// todo: Add a const to disable sanity checks
// todo: retval in pop ??? -> maybe add unsafeAt
// todo: redo max_index & end
// todo: Try to refactor throwing messages to be dynamic

// todo: Add an exception test for index ch
// todo: Refactor this with a testing framework

// todo: get rid of this awfull extern consts
// todo: how to allow template'ing and seperate header from implementation

template <typename T>
class Vector
{
protected:
    int capacity = 16;
    int size = 0;
    T* data = nullptr;
    
protected:
    int _toNearestGreaterBinaryPower(int desiredCapacity);

    void _runIndexChecks(int index);
    int _maxIndex();

    void _dec();
    void _inc();

    // resize
public:
    Vector();
    Vector(int desiredCapacity);
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
