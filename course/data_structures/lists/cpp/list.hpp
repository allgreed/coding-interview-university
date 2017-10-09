#pragma once

// *******************************
// Warning: this library may throw
// *******************************

//todo: Can I move this to List -> protected ?
//todo: Friend class ??? -> and move all public to protected / private
template <typename T>
class ListNode
{
    public:
        T value;
        ListNode* next;
        ListNode();
        ListNode(ListNode* next);
        ListNode(T value, ListNode* next);
};

template <typename T>
class List
{
    protected:
        int _size;
        ListNode<T>* _first;
        ListNode<T>* _last;
        // Since size is kept track of sentinel at the beginning is pointless
        // Therefore "sentinel" refers to the end sentinel
        ListNode<T>* _sentinel;

    protected:
        int endIndex();
        ListNode<T>* nodeAt(int index);

    public:
        List();
        ~List();
        //todo: copy constructor
        //todo: move constructor
        //todo: copy assignment operator
        //todo: move assignemnt operator

        // Basic operations
        void insert(int index, T value);
        T at(int index);
        // void erase(int index);
        int size();

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

