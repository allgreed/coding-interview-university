#pragma once

//See https://github.com/PowerSnail/Algorithms-Practices/blob/master/BST.cpp for future reference

#include <cstddef>
#include <stdexcept>

// Warning: this library may throw
// Do the exceptions here
    //BST_EMPTY_TREE_DEREFERNCE_ATTEMPT,

template <typename T>
class BST
{

class Sentinel;

private:
    class Node
    {
        //TODO: Extract this?
        public:
            struct Node* parent;
            struct Node* lesser;
            struct Node* greater;
            T value;

            // Allows for construction of sentinel nodes without worying about node's value
            Node()
            {

            }

            //TODO: Do more methods on nodes?
            //TODO: Be carefull about the parent - it is not assigned
            Node(T value, Node* parent = nullptr, Sentinel* sentinel = nullptr)
            :
                value(value),
                lesser(sentinel),
                greater(sentinel),
                parent(sentinel)
            {

            }
    };

    class Sentinel : public Node
    {
        public:
            Node* next;

            Sentinel() : next(this)
            {
                Node::parent = this;
                Node::lesser = this;
                Node::greater = this;
            }
    };


public:

    BST(Node* root = nullptr);
    ~BST();
    
    //BST(const BST<T>& rhs);
    //BST<T>& operator=(const BST<T>& rhs);
    // node pool ?
    
    //BST(BST<T>&& rhs);
    //BST<T>& operator=(BST<T>&& rhs);
    //
    
    void insert(T);
    bool is_in_tree(T);
    void delete_value(T);

    //T get_min();
    //T get_max();
    //T get_succesor(T);
    //std::size_t get_height();
    //std::size_t get_node_count();
        //do this on string stream
    //void print_values();

    // implement equal, non equal


private:
    //TODO: Remove this
    Node* root = nullptr; 

    std::size_t node_count;
    Sentinel* sentinel;


private:
//    Node* find_closest(T);
    Node* find_closest(T target)
    {
        // TODO: Document this
        // TODO: Move this to implementation
        
        sentinel->value = target;
        Node* candidate = sentinel->next;

        while(candidate->value != target)
        {
            candidate = (target > candidate->value)
                ? candidate->greater
                : candidate->lesser;
        }

        return candidate;
    }
};

#include "bst.cpp"
