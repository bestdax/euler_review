#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler14, sequence_count)
{
  EXPECT_EQ(solution.sequence_count(13), 10);
	
}

