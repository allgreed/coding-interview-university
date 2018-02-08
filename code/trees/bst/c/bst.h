#ifndef PROJECT_BST_H
#define PROJECT_BST_H

#include <stdbool.h>
//#include <stddef.h>

// *****************
// CONSTS
// *****************

//static const size_t HASHTABLE_DEFAULT_SIZE = 10;

// *****************
// EXIT CODES
// *****************

typedef enum
{
    BST_EXIT_OK = 0,
    BST_EXIT_FAILED_ALLOCATION,
} BST_EXIT_CODES;

// *****************
// TYPES
// *****************

// poor man's template
typedef int BST_value_t;

// *****************
// STRUCTURES
// *****************

typedef struct BST_Node
{
    struct BST_Node* parent;
    struct BST_Node* smaller;
    struct BST_Node* greater;
    BST_value_t value;
} BST_Node;

typedef struct BST
{
   BST_Node* root; 
} BST;

// *****************
// CONSTRUCTOR, DESTRUCTOR
// *****************

BST* BST_create();
void BST_destroy(BST*);

// *****************
// FUNCTIONS
// *****************

void BST_insert(BST*, BST_value_t);
bool BST_is_in_tree(BST*, BST_value_t);

BST_value_t BST_get_min(BST*);
BST_value_t BST_get_max(BST*);

#endif  // PROJECT_BST_H
