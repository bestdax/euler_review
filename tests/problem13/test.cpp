#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler13, str_add)
{
	EXPECT_STREQ(solution.strnum_add(std::string("123"), std::string("999")).c_str(), "1122");
	EXPECT_STREQ(solution.strnum_add(std::string(""), std::string("999")).c_str(), "999");
	EXPECT_STREQ(solution.strnum_add(std::string("999"), std::string("")).c_str(), "999");
}
