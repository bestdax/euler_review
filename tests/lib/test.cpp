#include "gtest/gtest.h"
#include "sint.h"


TEST(sint, init)
{
	sint s1;
	sint s2("111000");
	sint s3("-111000");
	sint s4("0");
	sint s5(234000);
	sint s6(-342342);
	sint s7(0);
	std::cout << "s1 = " << s1 << std::endl;
	std::cout << "s2 = " << s2 << std::endl;
	std::cout << "s3 = " << s3 << std::endl;
	std::cout << "s4 = " << s4 << std::endl;
	std::cout << "s5 = " << s5 << std::endl;
	std::cout << "s6 = " << s6 << std::endl;
	std::cout << "s7 = " << s7 << std::endl;
}

TEST(sint, equal)
{
	EXPECT_TRUE(sint(123) == 123);
	EXPECT_TRUE("123" == sint(123));
	EXPECT_TRUE(-123 == sint(-123));
}

TEST(sint, less)
{
	EXPECT_TRUE(sint(123) < 456);
	EXPECT_TRUE(sint(-123) < 456);
	EXPECT_TRUE(sint(-123) < -23);
	EXPECT_TRUE(0 < 456);
}

TEST(sint, strnum_sub)
{
	EXPECT_STREQ(sint::strnum_sub("123", "35").c_str(), "88");
}

TEST(sint, addition)
{
	EXPECT_EQ("123" + sint(45), 168);
	EXPECT_EQ("-123" + sint(45), -78);
	EXPECT_EQ("99" + sint(-205), -106);
	EXPECT_EQ("-123" + sint(-45), -168);
}

TEST(sint, subtraction)
{
	EXPECT_EQ("123" - sint(45), 78);
	EXPECT_EQ("-123" - sint(45), -168);
	EXPECT_EQ("99" - sint(-205), 304);
	EXPECT_EQ("-123" - sint(-45), -78);
	EXPECT_EQ(0 - sint(-45), 45);
}

TEST(sint, multiply)
{
	EXPECT_EQ(99 * sint(524567), 51932133);
}

TEST(sint, division)
{
	EXPECT_EQ(sint(25789) / 32, 805);
}


TEST(sint, modulus)
{
	EXPECT_EQ(sint(25789) % 32, 29);
}

TEST(sint, power)
{
	EXPECT_EQ(sint(2).power(3), 8);
}

TEST(sint, digit_sum)
{
	EXPECT_EQ(sint(1234).digit_sum(), 10);
}
