#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler08, product_of_series)
{
	EXPECT_EQ(solution.product_of_series(4), 5832);
}

