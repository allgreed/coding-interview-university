#pragma once

// *******************************
// Warning: this library may throw
// *******************************

//todo: Can I move this to List -> protected ?
//todo: Friend class ??? -> and move all public to protected / private
//todo: redo to struct?
//todo: move node methods (eraseNode -> eraseNextNode, to here?)
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
        ListNode<T>* frontSentinel;
        ListNode<T>* backSentinel;
        ListNode<T>* last;

    protected:
        int endIndex();
        ListNode<T>* nodeAt(int index);
        ListNode<T>* nodeBefore(int index);
        void nodeErase(ListNode<T>* preErased);

    public:
        List();
        ~List();
        //todo: copy constructor
        //todo: move constructor
        //todo: copy assignment operator
        //todo: move assignment operator

        // Basic operations
        void insert(int index, T value);
        T at(int index);
        T erase(int index);
        int size();

        // Derived
        void push_front(T value);
        T pop_front();
        void push_back(T value);
        T pop_back();
        bool empty();
        T back();
        T front();
        T value_n_from_end(int reverseIndex);

        // Advanced
        void reverse();
        void remove_value(T value);
};

// For truly type agnostic templates
#include "list.cpp"

