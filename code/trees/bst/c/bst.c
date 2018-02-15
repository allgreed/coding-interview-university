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

static inline void BST_free(BST_Node* start_node)
{
    if (start_node == NULL)
        return;

    BST_free(start_node->lesser);
    BST_free(start_node->greater);
    free(start_node);
}

void BST_destroy(BST* bst)
{
    if (bst->root != NULL)
        BST_free(bst->root);
    
    free(bst);
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
    // CAUTION! For the purpose of this excercise not checking if has succesor -> is >= max basically
    
    BST_Node* target_node = BST_find_nearest_node(bst, value);

    if (target_node->greater == NULL)
    {
        // Starting from the node itself, instead of the parent for succesors of nodes not in tree
        BST_Node* succesor_candidate = target_node; 

        while(succesor_candidate->value <= value)
            succesor_candidate = succesor_candidate->parent;

        return succesor_candidate->value;
    }
    else
    {
        BST subtree = { .root = target_node->greater };
        return BST_get_min(&subtree);
    }
}

static size_t BST_get_height_wrapper(BST_Node* node)
{
    if (node == NULL)
        return 0;

    size_t left_height = BST_get_height_wrapper(node->greater);
    size_t right_height = BST_get_height_wrapper(node->lesser);

    return 1 + (left_height > right_height
                     ? left_height
                     : right_height);
}

static size_t BST_get_node_count_wrapper(BST_Node* node)
{
    if (node == NULL)
        return 0;

    return 1 + BST_get_node_count_wrapper(node->greater) + BST_get_node_count_wrapper(node->lesser);
 
}

static void BST_print_values_wrapper(BST_Node* node)
{
    if (node == NULL)
        return;

    BST_print_values_wrapper(node->lesser);
    printf("%d ", node->value);
    BST_print_values_wrapper(node->greater);
}

bool is_binary_search_tree(BST* bst)
{
    //if it's a single node tree -> it's True
    
    // check for tree invariant (lower < value < bigger)
    // return this-invariant && lower-invariant && bigger-invariant
}

// *****************
// RECURSION WRAPPERS
// *****************

size_t BST_get_height(BST* bst)
{
    return BST_get_height_wrapper(bst->root);
}

size_t BST_get_node_count(BST* bst)
{
    return BST_get_node_count_wrapper(bst->root);
}

void BST_print_values(BST* bst)
{
   BST_print_values_wrapper(bst->root);
   printf("\n");
}
