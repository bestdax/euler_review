#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler05, smallest_multiple)
{
	EXPECT_EQ(solution.smallest_multiple(10), 2520);
}

TEST(euler05, gcd)
{
	EXPECT_EQ(dax::gcd(8, 12), 4);
}

TEST(euler05, lcm)
{
	EXPECT_EQ(dax::lcm(8, 12), 24);
}
