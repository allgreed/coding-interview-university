#pragma once

// Warning: this library may throw
#include <stdexcept>

// Can I move this to List -> protected ?
// Friend class ??? -> and move all public to protected / private
template <typename T>
class ListNode
{
protected:
    T value;
    ListNode* next;
protected:

public:
    // constructor
    // destrcutor
    // copy constructor
    // move constructor
    // copy assignment operator
    // move assignemnt operator
};

template <typename T>
class List
{
protected:
    int _size;
    ListNode<T>* _last;
    ListNode<T>* _first;
    // Since size is kept track of sentinel at the beginning is pointless
    // Therefore "sentinel" refers to the end sentinel
    ListNode<T>* _sentinel;
protected:
    int endIndex();
public:
    List();
    ~List();
    // copy constructor
    // move constructor
    // copy assignment operator
    // move assignemnt operator

    // Basic operations
    void insert(int index, T value);
    T at(int index);

    // void erase(int index);
    // int size();

    // // Derived
    // void push_front(T value);
    // T pop_front();
    // void push_back(T value);
    // T pop_back();

    // bool empty();
    // T back();
    // T front();
    // T value_n_from_end(int reverseIndex);

    // // Advanced
    // void reverse();
    // void remove_value(T value);
};

// For truly type agnostic templates
#include "list.cpp"

