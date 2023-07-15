/*
Problem page link:
https://projecteuler.net/problem=16

dax 2023-07-15 09:14:42
*/
#include "problem.h"
#include "sint.h"

void Solution::answer()
{
	std::cout << "The answer is: " << sint(2).power(1000).digit_sum() << std::endl;
}

