/*
Problem page link:
https://projecteuler.net/problem=6

dax 2023-06-25 15:32:40
*/
#include "problem.h"

void Solution::answer()
{
	std::cout << "The answer is: " << sum_square_difference(100) << std::endl;
}

unsigned long Solution::sum_square_difference(unsigned limit)
{
	unsigned long square_sum{}, sum_square{};

	for(unsigned i = 1; i <= limit; ++i)
	{
		square_sum += i * i;
		sum_square += i;
	}

	sum_square *= sum_square;
	return sum_square - square_sum;
}
