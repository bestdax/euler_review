/*
Problem page link:
https://projecteuler.net/problem=10

dax 2023-07-03 17:27:53
*/
#include "problem.h"
#include "numeric.h"
#include <vector>
#include <cmath>
#include "timer.h"

unsigned long Solution::sum_of_primes(unsigned long limit)
{
	unsigned long sum{};

	for(unsigned long i = 2; i < limit; ++i)
	{
		if(dax::is_prime(i)) sum += i;
	}

	return sum;
}

unsigned long Solution::sieve_of_eratos(unsigned long limit)
{
	std::vector<bool> status(limit, true);
	unsigned long sum{};
	unsigned root = std::sqrt(limit);

	for(unsigned long i = 2; i < root; ++i)
	{
		if(status[i])
		{
			unsigned long times = 2;

			while(times * i < limit)
			{
				status[i * times] = false;
				++times;
			}
		}
	}

	for(unsigned long i = 2; i < limit; ++i)
	{
		if(status[i]) sum += i;
	}

	return sum;
}

unsigned long Solution::sieve_of_euler(unsigned long limit)
{
	std::vector<bool> status(limit, true);
	unsigned long sum{};
	std::vector<unsigned long> primes;

	for(unsigned long i = 2; i < limit; ++i)
	{
		if(status[i])
		{
			primes.push_back(i);
			sum += i;
		}

		for(auto p : primes)
		{
			unsigned long n = p * i;

			if(n < limit) status[n] = false;
			else break;

			if(i % p == 0) break;
		}
	}

	return sum;
}

void Solution::answer()
{
	{
		Timer t;
		std::cout << "The answer is (is_prime): " << sum_of_primes(2'000'000) << std::endl;
	}
	{
		Timer t;
		std::cout << "The answer is (Eratos): " << sieve_of_eratos(2'000'000) << std::endl;
	}
	{
		Timer t;
		std::cout << "The answer is (Euler): " << sieve_of_euler(2'000'000) << std::endl;
	}
}
