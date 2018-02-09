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

static inline BST_Node* BST_Node_create(BST_Node* parent, BST_value_t value)
{
    BST_Node* retval = allocate(sizeof(BST_Node));

    retval->parent = parent;
    retval->lesser = NULL;
    retval->greater = NULL;
    retval->value = value;

    return retval;
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
            : current->lesser;
    } 

    return current;
}


// *****************
// FUNCTIONS
// *****************

void BST_insert(BST* bst, BST_value_t value)
{
    if (bst->root == NULL)
    {
        bst->root = BST_Node_create(NULL, value);
    }
    else
    {
        BST_Node* insertion_node = BST_find_nearest_node(bst, value);
        BST_Node* node_to_be_inserted = BST_Node_create(insertion_node, value);

        *((value < insertion_node->value)
            ? &insertion_node->lesser 
            : &insertion_node->greater) = node_to_be_inserted;
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
    if(bst->root == NULL)
        exit(BST_EMPTY_TREE_DEREFERNCE_ATTEMPT);

    BST_Node* node = bst->root;

    while(node->lesser != NULL)
        node = node->lesser;

    return node->value;
}

BST_value_t BST_get_max(BST* bst)
{
    if(bst->root == NULL)
        exit(BST_EMPTY_TREE_DEREFERNCE_ATTEMPT);

    BST_Node* node = bst->root;

    while(node->greater != NULL)
        node = node->greater;

    return node->value;
}

void BST_delete_value(BST* bst, BST_value_t value)
{
    BST_Node* target_node = BST_find_nearest_node(bst, value);

    if (target_node->value != value)
        return;

    if (target_node->lesser != NULL && target_node->greater != NULL)
    {
        BST subtree = { .root = target_node->lesser };
        target_node->value = BST_get_max(&subtree);
        BST_delete_value(&subtree, target_node->value);
    }
    else
    {
        BST_Node* child = target_node->lesser != NULL
            ? target_node->lesser
            : target_node->greater;

        if (child)
            child->parent = target_node->parent;

        *((target_node->parent->lesser == target_node)
            ? &target_node->parent->lesser 
            : &target_node->parent->greater) = child;

        free(target_node);
    }
}


BST_value_t BST_get_succesor(BST* bst, BST_value_t value)
{
//        BST subtree = { .root = target_node->lesser };
//        BST_value_t new_value = BST_get_max(&subtree);
//        target_node->value = new_value;
//        BST_delete_value(&subtree, new_value);

        // find a value
        // create a subtree
        // do a min of the right subtree
}
