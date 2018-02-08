#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

// *****************
// HELPERS
// *****************

void* allocate(size_t bytes)
{
    void* retval = malloc(bytes);

    if (retval == NULL)
    {
        fprintf(stderr, "Failed allocation with malloc\n");
        exit(BST_EXIT_FAILED_ALLOCATION);
    }

    return retval;
}

// *****************
// CONSTRUCTOR, DESTRUCTOR
// *****************

BST* BST_create()
{
    BST* retval = allocate(sizeof(BST));

    retval->root = NULL;

    return retval;
}

void BST_destroy(BST* bst)
{
    free(bst);
   //TODO: Implement this 
   // postorder traversal with node deletion
}

// *****************
// PRIVATES
// *****************

BST_Node* BST_Node_create(BST_Node* parent, BST_value_t value)
{
    BST_Node* retval = allocate(sizeof(BST_Node));

    retval->parent = parent;
    retval->smaller = NULL;
    retval->greater = NULL;
    retval->value = value;

    return retval;
}

static inline bool BST_is_tree_empty(BST* bst)
{
    return (bst->root == NULL);
}

static inline BST_Node* BST_find_nearest_node(BST* bst, BST_value_t value)
{
    BST_Node* current = bst->root;
    BST_Node* next = bst->root;

    while(next != NULL)
    {
        current = next;

        // would do initial check twice if put in the while condition
        if (current->value == value)
            break;

        next = (value > current->value)
            ? current->greater
            : current->smaller;
    } 

    return current;
}

// *****************
// FUNCTIONS
// *****************

void BST_insert(BST* bst, BST_value_t value)
{
    if (BST_is_tree_empty(bst))
    {
        bst->root = BST_Node_create(NULL, value);
    }
    else
    {
        BST_Node* insertion_node = BST_find_nearest_node(bst, value);
        BST_Node* node_to_be_inserted = BST_Node_create(insertion_node, value);

        (value > insertion_node->value)
            ? (insertion_node->greater = node_to_be_inserted)
            : (insertion_node->smaller = node_to_be_inserted);
    }
}

bool BST_is_in_tree(BST* bst, BST_value_t value)
{
    BST_Node* value_candidate = BST_find_nearest_node(bst, value);

    if (value_candidate == NULL)
        return false;

    return (value_candidate->value == value)
        ? true
        : false;
}

BST_value_t BST_get_min(BST* bst)
{
    // TODO: code this 
    // if the tree is empty -> exit?


}

BST_value_t BST_get_max(BST* bst)
{
    // TODO: code this 
    // if the tree is empty -> exit?

}

