#pragma once

// *******************************
// Warning: this library may throw
// *******************************

template <typename T>
class List
{
protected:
    template <typename _T>
    struct ListNode
    {
        _T value;
        ListNode* next;

        ListNode(_T value, ListNode* next) : value(value), next(next) {}
        ListNode(ListNode* next) : next(next) {}
        ListNode() {}
    };

    protected:
        int _size;
        ListNode<T>* frontSentinel;
        ListNode<T>* backSentinel;
        ListNode<T>* last;

    protected:
        int endIndex();
        ListNode<T>* nodeAt(int index);
        ListNode<T>* nodeBefore(int index);
        void nodeEraseAfter(ListNode<T>* preErased);

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
        T operator[](int i);

        // Advanced
        void reverse();
        void remove_value(T value);
        // todo: overload operator == for equality comparison
};

// For truly type agnostic templates
#include "list.cpp"

