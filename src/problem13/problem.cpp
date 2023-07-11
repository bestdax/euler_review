/*
Problem page link:
https://projecteuler.net/problem=13

dax 2023-07-10 16:17:41
*/
#include "problem.h"
#include <numeric>

std::string Solution::strnum_add(std::string num1, std::string num2)
{
	auto len = std::max(num1.size(), num2.size());
	bool carry = false;
	std::string sum{};

	for(unsigned i = 0; i < len; ++i)
	{
		char n1 = i < num1.size() ? *(num1.rbegin() + i) : '0';
		char n2 = i < num2.size() ? *(num2.rbegin() + i) : '0';
		char n = n1 + n2 - '0';

		if(carry)
		{
			++n;
			carry = false;
		}

		if(n > '9')
		{
			n -= 10;
			carry = true;
		}

		sum.insert(0, 1, n);
	}

	if(carry) sum.insert(0, 1, '1');

	return sum;
}
std::string Solution::sum()
{
	std::string result;

	for(auto n : numbers)
	{
		result = strnum_add(result, n);
	}

	return result.substr(0, 10);
}
void Solution::answer()
{
	std::cout << "The answer is: " << sum() << std::endl;
}
