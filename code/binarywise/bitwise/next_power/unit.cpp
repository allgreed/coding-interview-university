#include "bitwise.hpp"
#include "gtest/gtest.h"

TEST(Bitwise, test_not_power_of_two)
{
    EXPECT_EQ(next_power_of_two((unsigned int) 5), 8);
}

TEST(Bitwise, test_power_of_two)
{
    EXPECT_EQ(next_power_of_two((unsigned int) 32), 32);
}

