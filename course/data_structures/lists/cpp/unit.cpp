#include "list.hpp"
#include "gtest/gtest.h"

TEST(List, Default_parameters)
{
    List<int> list;

    ASSERT_EQ(list.size(), 0);
}

TEST(List, Out_of_bounds_access)
{
    List<int> list;

    ASSERT_THROW(list.at(10), std::invalid_argument);
}

TEST(List, Negative_access)
{
    List<int> list;

    ASSERT_THROW(list.at(-2), std::out_of_range);
}

TEST(List, Get_and_set)
{
    List<int> list;

    list.insert(0, 777);
    EXPECT_EQ(list.at(0), 777);

    list.insert(1, 69);
    EXPECT_EQ(list.at(1), 69);

    list.insert(0, -1000000);
    EXPECT_EQ(list.at(0), -1000000);

    list.insert(2, 0);
    EXPECT_EQ(list.at(2), 0);
}

// TEST(List, TEST_CASE_NAME)
// {
//     List<int> list;
//     // Do the setup

//     // Do the assertions
// }

// -------- PASTE THIS TO TEMPLATE -------

// Test declarations template

// TEST(PROJECT_TO_UPPERCASE, TEST_CASE_NAME)
// {
//     // Do the construction
//     // Do the setup

//     // Do the assertions
//     // Do cleanup (if necessary)
// }
