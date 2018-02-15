#include "bst.h"

#include <stdio.h>
#include <assert.h>

void test_insert_and_retrive()
{
    BST* bst = BST_create();

    assert(BST_is_in_tree(bst, 10) == false);
    assert(BST_is_in_tree(bst, 0) == false);
    assert(BST_is_in_tree(bst, 5) == false);
    assert(BST_is_in_tree(bst, -69) == false);
    assert(BST_is_in_tree(bst, 1e6) == false);

    BST_insert(bst, 10);
    BST_insert(bst, 0);
    BST_insert(bst, 5);
    BST_insert(bst, -69);
    BST_insert(bst, 1e6);
    
    assert(BST_is_in_tree(bst, 10) == true);
    assert(BST_is_in_tree(bst, 0) == true);
    assert(BST_is_in_tree(bst, 5) == true);
    assert(BST_is_in_tree(bst, -69) == true);
    assert(BST_is_in_tree(bst, 1e6) == true);

    BST_destroy(bst);
}

void test_memleeks()
{
    BST* bst = BST_create();
    BST_insert(bst, 5);
    BST_destroy(bst);
}

void test_get_min()
{
    BST* bst = BST_create();
    BST_insert(bst, 10);
    BST_insert(bst, 0);
    BST_insert(bst, 5);
    BST_insert(bst, -69);
    BST_insert(bst, 1e6);
    
    assert(BST_get_min(bst) == -69);

    BST_destroy(bst);
}

void test_get_max()
{
    BST* bst = BST_create();
    BST_insert(bst, 10);
    BST_insert(bst, 0);
    BST_insert(bst, 5);
    BST_insert(bst, -69);
    BST_insert(bst, 1e6);
    
    assert(BST_get_max(bst) == 1e6);

    BST_destroy(bst);
}

void test_delete_value_not_in_tree()
{
    BST* bst = BST_create();
    BST_insert(bst, 10);
    BST_insert(bst, 0);
    BST_insert(bst, 5);
    BST_insert(bst, -69);
    BST_insert(bst, 1e6);
    
    BST_delete_value(bst, 807);

    assert(BST_is_in_tree(bst, 807) == false);

    assert(BST_is_in_tree(bst, 10) == true);
    assert(BST_is_in_tree(bst, 0) == true);
    assert(BST_is_in_tree(bst, 5) == true);
    assert(BST_is_in_tree(bst, -69) == true);
    assert(BST_is_in_tree(bst, 1e6) == true);

    BST_destroy(bst);
}

void test_delete_value_leaf()
{
    BST* bst = BST_create();
    BST_insert(bst, 10);
    BST_insert(bst, 0);
    BST_insert(bst, 5);
    BST_insert(bst, -69);
    BST_insert(bst, 1e6);
    
    BST_delete_value(bst, 1e6);

    assert(BST_is_in_tree(bst, 1e6) == false);

    assert(BST_is_in_tree(bst, 10) == true);
    assert(BST_is_in_tree(bst, 0) == true);
    assert(BST_is_in_tree(bst, 5) == true);
    assert(BST_is_in_tree(bst, -69) == true);

    BST_destroy(bst);
}

void test_delete_value_one_child()
{
    BST* bst = BST_create();
    BST_insert(bst, 10);
    BST_insert(bst, 0);
    BST_insert(bst, 5);
    BST_insert(bst, 6);
    BST_insert(bst, -69);
    BST_insert(bst, 1e6);
    
    BST_delete_value(bst, 5);

    assert(BST_is_in_tree(bst, 5) == false);
    
    assert(BST_is_in_tree(bst, 10) == true);
    assert(BST_is_in_tree(bst, 0) == true);
    assert(BST_is_in_tree(bst, 6) == true);
    assert(BST_is_in_tree(bst, -69) == true);
    assert(BST_is_in_tree(bst, 1e6) == true);

    BST_destroy(bst);
}

void test_delete_value_two_children()
{
    BST* bst = BST_create();
    BST_insert(bst, 10);
    BST_insert(bst, 0);
    BST_insert(bst, 5);
    BST_insert(bst, 6);
    BST_insert(bst, -69);
    BST_insert(bst, 1e6);

    BST_delete_value(bst, 0);

    assert(BST_is_in_tree(bst, 0) == false);
    
    assert(BST_is_in_tree(bst, 10) == true);
    assert(BST_is_in_tree(bst, 5) == true);
    assert(BST_is_in_tree(bst, 6) == true);
    assert(BST_is_in_tree(bst, -69) == true);
    assert(BST_is_in_tree(bst, 1e6) == true);

    BST_destroy(bst);
}

void test_leaf_succesor()
{
    BST* bst = BST_create();
    BST_insert(bst, 10);
    BST_insert(bst, 0);
    BST_insert(bst, 5);
    BST_insert(bst, 6);
    BST_insert(bst, -69);
    BST_insert(bst, 1e6);

    assert(BST_get_succesor(bst,-69) == 0);
    assert(BST_get_succesor(bst, 6) == 10);

    BST_destroy(bst);
}   

void test_right_child_succesor()
{
    BST* bst = BST_create();
    BST_insert(bst, 10);
    BST_insert(bst, 0);
    BST_insert(bst, 5);
    BST_insert(bst, 3);
    BST_insert(bst, 6);
    BST_insert(bst, -69);
    BST_insert(bst, 1e6);

    assert(BST_get_succesor(bst, 0) == 3);

    BST_destroy(bst);
}

void test_get_height()
{
    BST* bst = BST_create();
    BST_insert(bst, 10);
    BST_insert(bst, 0);
    BST_insert(bst, 5);
    BST_insert(bst, 3);
    BST_insert(bst, 6);
    BST_insert(bst, -69);
    BST_insert(bst, 1e6);

    assert(BST_get_height(bst) == 4);

    BST_destroy(bst);
}

void test_near_succesor()
{
    BST* bst = BST_create();
    BST_insert(bst, 10);
    BST_insert(bst, 0);
    BST_insert(bst, 5);
    BST_insert(bst, 3);
    BST_insert(bst, 6);
    BST_insert(bst, -69);
    BST_insert(bst, 1e6);

    assert(BST_get_succesor(bst, 3) == 5);
    assert(BST_get_succesor(bst, -80) == -69);
    assert(BST_get_succesor(bst, 7) == 10);

    BST_destroy(bst);
}

void test_node_count()
{
    BST* bst = BST_create();
    assert(BST_get_node_count(bst) == 0);

    BST_insert(bst, 10);
    assert(BST_get_node_count(bst) == 1);

    BST_insert(bst, 0);
    BST_insert(bst, 5);
    BST_insert(bst, 3);
    BST_insert(bst, 6);
    BST_insert(bst, -69);
    BST_insert(bst, 1e6);

    assert(BST_get_node_count(bst) == 7);

    BST_delete_value(bst, 0);
    assert(BST_get_node_count(bst) == 6);

    BST_delete_value(bst, 0);
    assert(BST_get_node_count(bst) == 6);

    BST_delete_value(bst, 5);
    BST_delete_value(bst, 3);
    BST_delete_value(bst, 6);
    assert(BST_get_node_count(bst) == 3);

    BST_destroy(bst);
}

void test_print_values()
{
    BST* bst = BST_create();

    BST_insert(bst, 10);
    BST_insert(bst, 0);
    BST_insert(bst, 5);
    BST_insert(bst, 3);
    BST_insert(bst, 6);
    BST_insert(bst, -69);
    BST_insert(bst, 1e6);

    BST_print_values(bst);
    // No assert here, just compare the diff visually
    printf("-69 0 3 5 6 10 1000000\n");

    BST_destroy(bst);
}

void test_is_binary_search_tree()
{
    //CAUTION! - This one depends on the implementation
    
    // single node -> true
    
    // manually insert 50, 10 as lower, 100 as higher -> test -> true
    
    // manually insert 50, 10 as higher , 100 as lower -> test -> false
    
    // test tree -> true
}

int main()
{
    test_memleeks();
    test_insert_and_retrive();
    test_get_min();
    test_get_max();
    test_delete_value_not_in_tree();
    test_delete_value_leaf();
    test_delete_value_one_child();
    test_delete_value_two_children();
    test_leaf_succesor();
    test_right_child_succesor();
    test_near_succesor();
    test_get_height();
    test_node_count();
    test_print_values();
    test_is_binary_search_tree();

    printf("All tests passed!\n");
    return 0;
}
