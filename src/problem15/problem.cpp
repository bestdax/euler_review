/*
Problem page link:
https://projecteuler.net/problem=15

dax 2023-07-11 12:18:38
*/
#include "problem.h"
#include "timer.h"

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

unsigned long Solution::dp(unsigned n)
{
	unsigned long prev[n + 1];
	unsigned long temp[n + 1];

	for(unsigned i = 0; i <= n; ++i)
	{
		prev[i] = 1;
		temp[i] = 1;
	}

	for(unsigned i = 1; i <= n; ++i)
	{
		for(unsigned j = 1; j <= n; ++j)
			temp[j] = temp[j - 1] + prev[j];

		for(unsigned i = 0; i <= n; ++i)
			prev[i] = temp[i];
	}

	return prev[n];
}

void Solution::answer()
{
	{
		Timer t;
		std::cout << "The answer is: " << combination(40, 20) << std::endl;
	}
	{
		Timer t;
		std::cout << "The answer is: " << dp(20) << std::endl;
	}
}
