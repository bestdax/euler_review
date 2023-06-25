#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler03, is_prime)
{
	EXPECT_TRUE(solution.is_prime(2));
	EXPECT_TRUE(solution.is_prime(3));
	EXPECT_TRUE(solution.is_prime(5));
	EXPECT_TRUE(solution.is_prime(7));
	EXPECT_TRUE(solution.is_prime(11));
	EXPECT_TRUE(solution.is_prime(37));
	EXPECT_FALSE(solution.is_prime(6));
	EXPECT_FALSE(solution.is_prime(12));
	EXPECT_FALSE(solution.is_prime(15));
	EXPECT_FALSE(solution.is_prime(24));
	EXPECT_FALSE(solution.is_prime(27));
	EXPECT_FALSE(solution.is_prime(49));
}

TEST(euler03, largest_prime_factor)
{
	EXPECT_EQ(solution.largest_prime_factor(13195), 29);
}
