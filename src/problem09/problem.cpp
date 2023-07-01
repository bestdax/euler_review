/*
Problem page link:
https://projecteuler.net/problem=9

dax 2023-07-01 15:39:11
*/
#include "problem.h"

void Solution::answer()
{
	for(unsigned a = 1; a < 333; ++a)
		for(unsigned b = a + 1; 1000 - a - b > b; ++b)
			if(a * a + b * b == (1000 - a - b) * (1000 - a - b))
				std::cout << "The answer is: " << a * b * (1000 - a - b) << std::endl;
}
