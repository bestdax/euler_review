#pragma once
#include <iostream>

class Solution
{
public:
  void answer();
  unsigned long smallest_multiple(unsigned size);
};

namespace dax{
unsigned long lcm(unsigned long a, unsigned long b);
unsigned long gcd(unsigned long a, unsigned long b);
}
