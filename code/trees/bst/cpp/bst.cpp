// delete after dev
#include <iostream>

// import what's needed for the implementation

#pragma region Constructors, destructor 

template <typename T>
BST<T>::BST(Node* root) 
:
    node_count(0),
    sentinel(new Sentinel)
{
    //if (root != nullptr)
    //{
    //    sentinel->next = root;
    //}
}

template <typename T>
BST<T>::~BST()
{
    // BFS traversal + deletion while traversing
}

#pragma endregion

#pragma region Basic methods

template <typename T>
void BST<T>::insert(T value)
{
    Node* insertion_node = find_closest(value);
    
    if (insertion_node == sentinel)
    {
        sentinel->next = new Node(value, insertion_node, sentinel);
    } 
    else
    {
        value < insertion_node->value
            ? insertion_node->lesser 
            : insertion_node->greater = new Node(value, insertion_node, sentinel); 
    }

    std::cout << insertion_node->value << std::endl;

    node_count++;
}

template <typename T>
bool BST<T>::is_in_tree(T target)
{
    Node* node_candidate = find_closest(target);

    return (node_candidate != sentinel) && (node_candidate->value == target);
}

template <typename T>
void BST<T>::delete_value(T)
{

}

#pragma endregion

#pragma region Advanced methods



#pragma endregion

#pragma region Private methods

//template <typename T>


#pragma endregion
