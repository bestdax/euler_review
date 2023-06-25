/*
Problem page link:
https://projecteuler.net/problem=7

dax 2023-06-25 16:28:31
*/
#include "problem.h"
#include "numeric.h"

void Solution::answer()
{
	std::cout << "The answer is: " << nth_prime(10001) << std::endl;
}

unsigned long Solution::nth_prime(unsigned n)
{
	unsigned count{}, i{1};

	while(count < n)
	{
		++i;

		if(dax::is_prime(i)) ++count;
	}

	return i;
}
