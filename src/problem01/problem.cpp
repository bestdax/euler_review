#include "problem.h"
#include <iostream>

void Solution::answer()
{
	std::cout << "The answer is: " << sum_of_multiples(1000) << std::endl;
}

unsigned Solution::sum_of_multiples(unsigned limit)
{
	unsigned sum{};

	for(unsigned i = 1; i < limit; ++i)
		if(i % 3 == 0 || i % 5 == 0) sum += i;

	return sum;
}
