#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler07, nth_prime)
{
	EXPECT_EQ(solution.nth_prime(1), 2);
	EXPECT_EQ(solution.nth_prime(2), 3);
	EXPECT_EQ(solution.nth_prime(3), 5);
	EXPECT_EQ(solution.nth_prime(4), 7);
	EXPECT_EQ(solution.nth_prime(5), 11);
	EXPECT_EQ(solution.nth_prime(6), 13);
}
