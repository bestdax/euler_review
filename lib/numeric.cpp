#include "numeric.h"
#include <cmath>

bool dax::is_prime(unsigned long number)
{
	unsigned root = std::sqrt(number);

	for(unsigned i = 2; i <= root; ++i)
	{
		if(number % i == 0) return false;
	}

	return true;
}
