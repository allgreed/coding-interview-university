#include "binary_search.hpp"
#include "gtest/gtest.h"

TEST(BinarySearch, test_positives_even)
{
    int arr[] = { 1, 3, 5, 7 };
    
    EXPECT_NO_THROW(search(arr, 4, 1));
    std::size_t result = search(arr, 4, 1);

    EXPECT_EQ(result, 0);
}

TEST(BinarySearch, test_positives_odd)
{
    int arr[] = { 1, 3, 5 };

    EXPECT_NO_THROW(search(arr, 4, 1););
    std::size_t result = search(arr, 4, 1);

    EXPECT_EQ(result, 0);
}

TEST(BinarySearch, test_negatvies_even)
{
    int arr[] = { -50, -30, -20, -10, -5, -1 };

    EXPECT_NO_THROW(search(arr, 6, -20););
    std::size_t result = search(arr, 6, -20);

    EXPECT_EQ(result, 2);
}

TEST(BinarySearch, test_negatvies_odd)
{
    int arr[] = { -50, -30, -10, -5, -1 };

    EXPECT_NO_THROW(search(arr, 5, -1););
    std::size_t result = search(arr, 5, -1);

    EXPECT_EQ(result, 4);
}

TEST(BinarySearch, test_mixed_odd)
{
    int arr[] = { -1, 0, 5, 7 };

    EXPECT_NO_THROW(search(arr, 4, 7););
    std::size_t result = search(arr, 4, 7);

    EXPECT_EQ(result, 3);
}

TEST(BinarySearch, test_mixed_even)
{
    int arr[] = { -3, -1, 0, 5, 7 };

    EXPECT_NO_THROW(search(arr, 5, 0););
    std::size_t result = search(arr, 5, 0);

    EXPECT_EQ(result, 2);
}

TEST(BinarySearch, test_not_exist)
{
    int arr[] = { 1, 3, 5, 7 };

    EXPECT_THROW(search(arr, 4, -69), SearchValueNotFound);
}

TEST(BinarySearch, test_different_type)
{
    double arr[] = { -3.2, -1.3, 0.3, 5.2, 7.2 };

    EXPECT_NO_THROW(search(arr, 5, 0.3));
    std::size_t result = search(arr, 5, 0.3);

    EXPECT_EQ(result, 2);
}
