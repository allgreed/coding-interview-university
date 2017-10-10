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

    EXPECT_EQ(list.size(), 4);
}

TEST(List, Erase)
{
    List<int> list;
    list.insert(0, 567890);
    list.insert(0, 123456);
    list.insert(0, -123456);

    list.erase(0);

    EXPECT_EQ(list.at(1), 567890);
    EXPECT_EQ(list.size(), 2);

    list.erase(1);

    EXPECT_EQ(list.at(0), 123456);
    EXPECT_EQ(list.size(), 1);
}

TEST(List, Front_push_pop)
{
    List<int> list;

    list.push_front(123);
    list.push_front(-123);

    EXPECT_EQ(list.at(0), -123);
    EXPECT_EQ(list.at(1), 123);
    EXPECT_EQ(list.pop_front(), -123);
    EXPECT_EQ(list.pop_front(), 123);
}

TEST(List, Size)
{
    List<int> list;

    EXPECT_EQ(list.size(), 0);

    list.push_front(111);
    list.push_front(222);

    EXPECT_EQ(list.size(), 2);

    list.pop_front();

    EXPECT_EQ(list.size(), 1);
}

TEST(List, Empty)
{
    List<int> list;

    EXPECT_TRUE(list.empty());

    list.insert(0, 498);
    list.insert(0, 0);
    list.insert(0, -49450);

    EXPECT_TRUE(!list.empty());

    list.erase(0);
    list.erase(0);
    list.erase(0);

    EXPECT_TRUE(list.empty());
}

TEST(List, Back_push_pop)
{
    List<int> list;
    list.push_back(456);
    list.push_back(-654);

    EXPECT_EQ(list.at(0), 456);
    EXPECT_EQ(list.at(1), -654);

    EXPECT_EQ(list.pop_back(), -654);
    EXPECT_EQ(list.pop_back(), 456);

    EXPECT_TRUE(list.empty());
}

TEST(List, Back_front_getters)
{
    List<int> list;

    list.push_front(3333);
    list.push_front(2222);
    list.push_front(1111);

    EXPECT_EQ(list.back(), 3333);
    EXPECT_EQ(list.front(), 1111);
}

TEST(List, Reverse_index)
{
    List<int> list;

    list.push_front(6);
    list.push_front(5);
    list.push_front(4);
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    EXPECT_EQ(list.value_n_from_end(2), 4);
    EXPECT_EQ(list.value_n_from_end(1), 5);
    EXPECT_EQ(list.value_n_from_end(0), 6);
}

TEST(List, Reverse)
{
    List<int> list;
    list.push_back(45);
    list.push_back(89);
    list.push_back(-48);
    list.push_back(23);
    list.push_back(0);
    list.push_back(-128);

    list.reverse();

    EXPECT_EQ(list.at(0), -128);
    EXPECT_EQ(list.at(1), 0);
    EXPECT_EQ(list.at(2), 23);
    EXPECT_EQ(list.at(3), -48);
    EXPECT_EQ(list.at(4), 89);
    EXPECT_EQ(list.at(5), 45);

    EXPECT_EQ(list.size(), 6);
}

TEST(List, Remove_value)
{
    List<int> list;
    list.remove_value(1000000);

    list.push_back(-600);
    list.push_back(2);
    list.push_back(1000000);

    list.remove_value(1000000);

    EXPECT_EQ(list.at(0), -600);
    EXPECT_EQ(list.at(1), 2);
    EXPECT_EQ(list.size(), 2);

    list.push_front(5);

    list.remove_value(5);

    EXPECT_EQ(list.at(0), -600);
    EXPECT_EQ(list.at(1), 2);
    EXPECT_EQ(list.size(), 2);
}


// -------- PASTE THIS TO TEMPLATE -------

// #include "gtest/gtest.h"

// Test declarations template

// TEST(PROJECT_TO_UPPERCASE, TEST_CASE_NAME)
// {
//     // Do the construction
//     // Do the setup

//     // Do the assertions
//     // Do cleanup (if necessary)
// }
