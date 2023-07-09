/*
Problem page link:
https://projecteuler.net/problem=11

dax 2023-07-09 16:46:53
*/
#include "problem.h"

unsigned long Solution::largest_product_in_grid()
{
	unsigned long max_product{};

	for(unsigned row = 0; row < 20; ++row)
		for(unsigned col = 0; col < 20; ++col)
		{
			unsigned n = 0;
			unsigned long horizontal_product{1};
			unsigned long vertical_product{1};
			unsigned long diagonal_product{1};
			unsigned long backdiagonal_product{1};

			while(n < 4)
			{
				if(col < 17)
					horizontal_product *= grid[row][col + n];

				if(row < 17)
					vertical_product *= grid[row + n][col];

				if(col < 17 && row < 17)
					diagonal_product *= grid[row + n][col + 1];

				if(col > 2 && row < 17)
					backdiagonal_product *= grid[row + n][col - n];

				max_product = std::max(max_product, horizontal_product);
				max_product = std::max(max_product, vertical_product);
				max_product = std::max(max_product, diagonal_product);
				max_product = std::max(max_product, backdiagonal_product);
				++n;
			}
		}

	return max_product;
}

void Solution::answer()
{
	std::cout << "The answer is: " << largest_product_in_grid() << std::endl;
}
