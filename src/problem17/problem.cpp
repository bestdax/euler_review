/*
Problem page link:
https://projecteuler.net/problem=17

dax 2023-07-16 10:24:03
*/
#include "problem.h"

Solution::Solution()
{
	num_to_words[1] = "one";
	num_to_words[2] = "two";
	num_to_words[3] = "three";
	num_to_words[4] = "four";
	num_to_words[5] = "five";
	num_to_words[6] = "six";
	num_to_words[7] = "seven";
	num_to_words[8] = "eight";
	num_to_words[9] = "nine";
	num_to_words[10] = "ten";
	num_to_words[11] = "eleven";
	num_to_words[12] = "twelve";
	num_to_words[13] = "thirteen";
	num_to_words[14] = "fourteen";
	num_to_words[15] = "fifteen";
	num_to_words[16] = "sixteen";
	num_to_words[17] = "seventeen";
	num_to_words[18] = "eighteen";
	num_to_words[19] = "nineteen";
	num_to_words[20] = "twenty";
	num_to_words[30] = "thirty";
	num_to_words[40] = "forty";
	num_to_words[50] = "fifty";
	num_to_words[60] = "sixty";
	num_to_words[70] = "seventy";
	num_to_words[80] = "eighty";
	num_to_words[90] = "ninety";
	num_to_words[100] = "hundred";
	num_to_words[1000] = "thousand";
}

std::string Solution::say_number(unsigned n)
{
	std::string say;
	std::string leading;
	unsigned thousands = n / 1000;
	unsigned hundreds = (n % 1000) / 100;
	unsigned tens = (n % 100) / 10;
	unsigned ones = n % 10;

	if(thousands) say += num_to_words[thousands] + ' ' + num_to_words[1000];

	if(hundreds)
	{
		if(!say.empty()) leading = " ";
		else leading = "";

		say += leading + num_to_words[hundreds] + " " + num_to_words[100];
	}

	if(tens)
	{
		if(!say.empty()) leading = " and ";
		else leading = "";

		if(tens < 2)
		{
			say += leading + num_to_words[n % 100];
			return say;
		}
		else
		{
			say += leading + num_to_words[tens * 10];
		}
	}

	if(ones)
	{
		if(tens) leading = "-";
		else if(!say.empty()) leading = " and ";
		else leading = "";

		say += leading + num_to_words[ones];
	}

	return say;
}

unsigned Solution::count(unsigned n)
{
	unsigned cnt{};

	for(unsigned i = 1; i <= n; ++i)
	{
		std::string num_in_words = say_number(i);

		for(auto c : num_in_words)
			if(std::isalpha(c)) ++cnt;
	}

	return cnt;
}

void Solution::answer()
{
	std::cout << "The answer is: " << count(1000) << std::endl;
}
