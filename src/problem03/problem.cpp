/*
Problem page link:
https://projecteuler.net/problem=3

dax 2023-06-25 09:38:55
*/
#include "problem.h"
#include <cmath>

bool Solution::is_prime(unsigned long number)
{
	unsigned root = std::sqrt(number);

	for(unsigned i = 2; i <= root; ++i)
	{
		if(number % i == 0) return false;
	}

	return true;
}

unsigned Solution::largest_prime_factor(unsigned long number)
{
	unsigned i = 2;

	while(!is_prime(number))
	{
		if(number % i == 0)
		{
			number /= i;
			continue;
		}

		do
		{
			++i;
		}
		while(!is_prime(i));
	}

	return number;
}


void Solution::answer()
{
	std::cout << "The answer is: " << largest_prime_factor(600851475143) << std::endl;
}
