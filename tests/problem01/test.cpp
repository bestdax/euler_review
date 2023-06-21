#include <gtest/gtest.h>
#include "problem.h"

Solution s;

TEST(euler01, sum)
{
	EXPECT_EQ(s.sum_of_multiples(10), 23);
}
