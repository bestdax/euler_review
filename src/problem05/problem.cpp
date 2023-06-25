/*
Problem page link:
https://projecteuler.net/problem=5

dax 2023-06-25 15:07:43
*/
#include "problem.h"
#include <numeric>

void Solution::answer()
{
	std::cout << "The answer is: " << smallest_multiple(20) << std::endl;
}

unsigned long Solution::smallest_multiple(unsigned size)
{
	unsigned m[size];
	std::iota(m, m + size, 1);
	auto sm = std::accumulate(m, m + size, 1, std::lcm<unsigned long, unsigned long>);
	return sm;
}

unsigned long dax::gcd(unsigned long a, unsigned long b)
{
	if(a < b)
	{
		auto temp = a;
		a = b;
		b = temp;
	}

	auto r = a % b;

	while(r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}

	return b;
}

unsigned long dax::lcm(unsigned long a, unsigned long b)
{
	return a * b / dax::gcd(a, b);
}
