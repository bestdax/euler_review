#include <chrono>
#include <iostream>

class Timer
{
public:
	Timer()
	{
		start = std::clock();
	}
	~Timer()
	{
		auto end = std::clock();
		std::cout << "Running time: " << end - start << std::endl;
	}
	double start;
};
