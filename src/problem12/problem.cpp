/*
Problem page link:
https://projecteuler.net/problem=12

dax 2023-07-09 17:21:16
*/
#include "problem.h"
#include <cmath>

unsigned long Solution::nth_triangle_number(unsigned n)
{
	return n * (n + 1) / 2;
}

unsigned Solution::factor_count(unsigned long number)
{
	unsigned count{};
	unsigned root = std::sqrt(number);

	for(unsigned i = 1; i <= root; ++i)
	{
		if(number % i == 0) ++count;
	}

	count *= 2;

	if(root * root == number) count--;

	return count;
}

unsigned long Solution::triangle_number_with_over_five_hundred_factors()
{
	unsigned count = 1;
	unsigned n = 1;

	while(count < 500)
	{
		count = factor_count(nth_triangle_number(n));
		++n;
	}

	return nth_triangle_number(n - 1);
}

void Solution::answer()
{
	std::cout << "The answer is: " << triangle_number_with_over_five_hundred_factors() << std::endl;
}
