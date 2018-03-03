#pragma once

#include <cstddef>

#include <stdexcept>
// Warning: this library may throw
// Do the exceptions here
    //BST_EMPTY_TREE_DEREFERNCE_ATTEMPT,

template <typename T>
class BST
{
    private:
        struct Node
        {
            struct Node* parent;
            struct Node* lesser;
            struct Node* greater;
            T value;
        };
        
    private:
       Node* root; 

    public:
        BST();
        ~BST();
        //BST(const BST<T>& rhs);
        //BST<T>& operator=(const BST<T>& rhs);
        //BST(BST<T>&& rhs);
        //BST<T>& operator=(BST<T>&& rhs);

    public:   
    // implement equal, non equal

    public:
        void insert(T);
        bool is_in_tree(T);
        void delete_value(T);

    public:
        //T get_min();
        //T get_max();
        //T get_succesor(T);
        //size_t get_height();
        //size_t get_node_count();
            //do this on string stream
        //void print_values();
            // break encapsulation in tests? 
        //bool is_binary_search_tree();

};

#include "bst.cpp"
