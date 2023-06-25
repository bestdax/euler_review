/*
Problem page link:
https://projecteuler.net/problem=4

dax 2023-06-25 13:09:25
*/
#include "problem.h"
#include <string>
#include <algorithm>
#include <cmath>

bool Solution::is_palindrome(unsigned long number)
{
	auto number_string = std::to_string(number);
	auto number_string_copy = number_string;
	std::ranges::reverse(number_string_copy);
	return number_string == number_string_copy;
}

unsigned long Solution::largest_palindrome_of_product(unsigned size)
{
	unsigned long max{};

	for(unsigned i = std::pow(10, size - 1); i < std::pow(10, size); ++i)
		for(unsigned j = std::pow(10, size - 1); j < std::pow(10, size); ++j)
		{
			auto number = i * j;

			if(is_palindrome(number) && number > max) max = number;
		}

	return max;
}


void Solution::answer()
{
	std::cout << "The answer is: " << largest_palindrome_of_product(3) << std::endl;
}
