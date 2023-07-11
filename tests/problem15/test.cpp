#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler15, factorial)
{
	EXPECT_EQ(solution.factorial(4), 24);
	EXPECT_EQ(solution.factorial(0), 1);
}

TEST(euler15, combination)
{
	EXPECT_EQ(solution.combination(4, 2), 6);
}

TEST(euler15, dp)
{
	EXPECT_EQ(solution.dp(2), 6);
	EXPECT_EQ(solution.dp(3), 20);
}
