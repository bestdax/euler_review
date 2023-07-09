#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler12, nth_triangle_number)
{
	EXPECT_EQ(solution.nth_triangle_number(1), 1);
	EXPECT_EQ(solution.nth_triangle_number(2), 3);
	EXPECT_EQ(solution.nth_triangle_number(3), 6);
	EXPECT_EQ(solution.nth_triangle_number(4), 10);
	EXPECT_EQ(solution.nth_triangle_number(5), 15);
	EXPECT_EQ(solution.nth_triangle_number(6), 21);
	EXPECT_EQ(solution.nth_triangle_number(7), 28);
}

TEST(euler12, factor_count)
{
	EXPECT_EQ(solution.factor_count(1), 1);
	EXPECT_EQ(solution.factor_count(3), 2);
	EXPECT_EQ(solution.factor_count(6), 4);
	EXPECT_EQ(solution.factor_count(10), 4);
	EXPECT_EQ(solution.factor_count(15), 4);
	EXPECT_EQ(solution.factor_count(21), 4);
	EXPECT_EQ(solution.factor_count(28), 6);
}
