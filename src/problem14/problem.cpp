/*
Problem page link:
https://projecteuler.net/problem=14

dax 2023-07-11 10:10:25
*/
#include "problem.h"

unsigned Solution::sequence_count(unsigned n)
{
	unsigned count = 1;

	while(n != 1)
	{
		if(n % 2 == 0) n /= 2;
		else n = n * 3 + 1;

		++count;
	}

	return count;
}
void Solution::answer()
{
	unsigned m = 0;
	unsigned target;

	for(unsigned i = 1; i < 1'000'000; ++i)
	{
		auto count = sequence_count(i);

		if(count > m)
		{
			m = count;
			target = i;
		}
	}

	std::cout << "The answer is: " << target << std::endl;
}
