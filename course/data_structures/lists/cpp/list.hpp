#pragma once

// *******************************
// Warning: this library may throw
// *******************************

template <typename T>
class List
{
    protected:
        template<typename _>
        struct ListNode
        {
            T value;
            ListNode* next;

            ListNode(T value, ListNode* next) : value(value), next(next) {}
            ListNode(ListNode* next) : next(next) {}
            ListNode() {}
        };

    protected:
        int _size;
        ListNode<T>* frontSentinel;
        ListNode<T>* backSentinel;
        ListNode<T>* last;

    protected:
        int endIndex() const;
        ListNode<T>* nodeAt(int index) const;
        ListNode<T>* nodeBefore(int index);

        //todo: move this inside node struct -> how to handle templates in function declaration? Ask Patryk
        void nodeEraseAfter(ListNode<T>* preErased);

    public:
        List();
        ~List();

        List(const List<T> &list);
        //todo: copy assignment operator
        //todo: move constructor
        //todo: move assignment operator

        // Basic operations
        void insert(int index, T value);
        T at(int index) const;
        T erase(int index);
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

        T operator[](int i);

        // Advanced
        void reverse();
        void remove_value(T value);

        bool operator==(const List<T>& compared);
        bool operator!=(const List<T>& compared);
};

// For truly type agnostic templates
#include "list.cpp"

