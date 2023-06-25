/*
Problem page link:
https://projecteuler.net/problem=2

dax 2023-06-25 08:36:33
*/
#include "problem.h"

unsigned long Solution::sum_of_even_fib(unsigned long limit)
{
	unsigned long sum{};
	unsigned long a = 0, b = 1, c = 0;

	while(c < limit)
	{
		if(c % 2 == 0) sum += c;

		c = a + b;
		a = b;
		b = c;
	}

	return sum;
}

void Solution::answer()
{
	std::cout << "The answer is: " << sum_of_even_fib(4'000'000) << std::endl;
}
