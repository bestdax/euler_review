#pragma once
#include <iostream>
#include <string>
#include <map>

class Solution
{
public:
	std::string say_number(unsigned n);
	Solution();
	unsigned count(unsigned n);

	void answer();
private:
	std::map<unsigned, std::string> num_to_words;


};
