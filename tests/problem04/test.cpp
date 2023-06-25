#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler04, is_palindrome)
{
	EXPECT_TRUE(solution.is_palindrome(1001));
	EXPECT_TRUE(solution.is_palindrome(20033002));
	EXPECT_TRUE(solution.is_palindrome(100121001));
	EXPECT_TRUE(solution.is_palindrome(1992991));
	EXPECT_FALSE(solution.is_palindrome(10012300));
	EXPECT_FALSE(solution.is_palindrome(101230));
	EXPECT_FALSE(solution.is_palindrome(10045400));
}

TEST(euler04, largest_prlindrome_of_product)
{
	EXPECT_EQ(solution.largest_palindrome_of_product(2), 9009);
}
