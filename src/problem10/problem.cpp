/*
Problem page link:
https://projecteuler.net/problem=10

dax 2023-07-03 17:27:53
*/
#include "problem.h"
#include "numeric.h"

unsigned long Solution::sum_of_primes(unsigned long limit)
{
	unsigned long sum{};
	for(unsigned long i=2; i < limit; ++i)
	{
	 if(dax::is_prime(i)) sum += i;
	}

	return sum;
}

void Solution::answer()
{
	std::cout << "The answer is: " << sum_of_primes(2'000'000) << std::endl;
}

