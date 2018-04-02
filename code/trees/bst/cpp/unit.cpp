#include "bst.hpp"
#include "gtest/gtest.h"

TEST(Bst, test_memleeks)
{
    BST<int> bst;
    
    bst.insert(5);
}

TEST(Bst, test_insert_and_retrive)
{
    BST<int> bst;

    EXPECT_FALSE(bst.is_in_tree(10));
    EXPECT_FALSE(bst.is_in_tree(0));
    EXPECT_FALSE(bst.is_in_tree(5));
    EXPECT_FALSE(bst.is_in_tree(-69));
    EXPECT_FALSE(bst.is_in_tree(1e6));

    bst.insert(10);
    EXPECT_TRUE(bst.is_in_tree(10));

    bst.insert(0);
    EXPECT_TRUE(bst.is_in_tree(0));

    bst.insert(5);
    EXPECT_TRUE(bst.is_in_tree(5));

    bst.insert(-69);
    EXPECT_TRUE(bst.is_in_tree(-69));

    bst.insert(1e6);
    EXPECT_TRUE(bst.is_in_tree(1e6));
}

// Test declarations template

//TEST(Bst, TEST_CASE_NAME)
//{
//    BST<int> bst;
//    // Do the setup
//
//    // Do the assertions
//}
