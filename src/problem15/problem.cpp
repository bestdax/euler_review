/*
Problem page link:
https://projecteuler.net/problem=15

dax 2023-07-11 12:18:38
*/
#include "problem.h"

unsigned long Solution::factorial(unsigned n)
{
	unsigned long f{1};

	for(unsigned i = 0; i <= n; ++i)
	{
		if(i != 0) f *= i;
	}

	return f;
}
unsigned long Solution::combination(unsigned n, unsigned k)
{
	unsigned long result{1};
	unsigned j = k;

	for(unsigned i = n; i > k; --i)
	{
		result *= i;

		while(result % j == 0)
		{
			result /= j;
			--j;
		}
	}

	return result;
}

void Solution::answer()
{
	std::cout << "The answer is: " << combination(40, 20) << std::endl;
}
