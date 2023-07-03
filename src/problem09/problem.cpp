/*
Problem page link:
https://projecteuler.net/problem=9

dax 2023-07-01 15:39:11
*/
#include "problem.h"

void Solution::answer()
{
	for(unsigned a = 1; a < 333; ++a)
		for(unsigned b = a + 1, c = 1000 - a - b; 1000 - a - b > b; ++b, c = 1000 - a - b)
			if(a * a + b * b == c * c)
				std::cout << "The answer is: " << a * b * c << std::endl;
}
