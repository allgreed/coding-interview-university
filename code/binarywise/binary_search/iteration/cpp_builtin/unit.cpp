#include "binary_search.hpp"
#include "gtest/gtest.h"

TEST(BinarySearch, test_positives_even)
{
    std::vector<int> vector = { 1, 3, 5, 7 };
    
    EXPECT_NO_THROW(search(vector, 1));
    std::size_t result = search(vector, 1);

    EXPECT_EQ(result, 0);
}

TEST(BinarySearch, test_positives_odd)
{
    std::vector<int> vector = { 1, 3, 5 };

    EXPECT_NO_THROW(search(vector, 1););
    std::size_t result = search(vector, 1);

    EXPECT_EQ(result, 0);
}

TEST(BinarySearch, test_negatvies_even)
{
    std::vector<int> vector = { -50, -30, -20, -10, -5, -1 };

    EXPECT_NO_THROW(search(vector, -20););
    std::size_t result = search(vector, -20);

    EXPECT_EQ(result, 2);
}

TEST(BinarySearch, test_negatvies_odd)
{
    std::vector<int> vector = { -50, -30, -10, -5, -1 };

    EXPECT_NO_THROW(search(vector, -1););
    std::size_t result = search(vector, -1);

    EXPECT_EQ(result, 4);
}

TEST(BinarySearch, test_mixed_odd)
{
    std::vector<int> vector = { -1, 0, 5, 7 };

    EXPECT_NO_THROW(search(vector, 7););
    std::size_t result = search(vector, 7);

    EXPECT_EQ(result, 3);
}

TEST(BinarySearch, test_mixed_even)
{
    std::vector<int> vector = { -3, -1, 0, 5, 7 };

    EXPECT_NO_THROW(search(vector, 0););
    std::size_t result = search(vector, 0);

    EXPECT_EQ(result, 2);
}

TEST(BinarySearch, test_not_exist_in_range)
{
    std::vector<int> vector = { 1, 3, 5, 7 };

    EXPECT_THROW(search(vector, 4), SearchValueNotFound);
}

TEST(BinarySearch, test_not_exist_higher)
{
    std::vector<int> vector = { 1, 3, 5, 7 };

    EXPECT_THROW(search(vector, 100000), SearchValueNotFound);
}

TEST(BinarySearch, test_not_exist)
{
    std::vector<int> vector = { 1, 3, 5, 7 };

    EXPECT_THROW(search(vector, -69), SearchValueNotFound);
}

TEST(BinarySearch, test_different_type)
{
    std::vector<double> vector = { -3.2, -1.3, 0.3, 5.2, 7.2 };

    EXPECT_NO_THROW(search(vector, 0.3));
    std::size_t result = search(vector, 0.3);

    EXPECT_EQ(result, 2);
}

TEST(BinarySearch, test_truncatonation)
{
    std::vector<int> vector = { 1, 3 };

    EXPECT_NO_THROW(search(vector, 3));
    std::size_t result = search(vector, 3);

    EXPECT_EQ(result, 1);
}
