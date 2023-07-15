#include "sint.h"


sint::sint(): sign('+'), number("") {}

sint::sint(const char* strnum): sint(std::string(strnum)) {}
sint::sint(int n): sint(std::to_string(n)) {}

sint::sint(std::string strnum)
{
	if(strnum[0] == '+' || strnum[0] == '-')
	{
		sign = strnum[0];
		auto num = strnum.substr(1);

		for(auto c : num)
		{
			if(!std::isdigit(c))
				throw "Not Number";
		}

		number = num;
	}
	else
	{
		for(auto c : strnum)
		{
			if(!std::isdigit(c))
				throw "Not Number";
		}

		number = strnum;
		sign = '+';
	}

	if(!number.empty())
	{
		auto pos = number.find_first_not_of('0');

		if(pos != number.npos) number = number.substr(pos);
		else number = "";
	}
}

sint::sint(long long n): sint(std::to_string(n)) {}

std::ostream& operator<<(std::ostream& os, const sint& s)
{
	if(s.sign == '+')
	{
		if(s.number.empty()) os << 0;
		else os << s.number;
	}
	else os << s.sign << s.number;

	return os;
}

bool operator==(const sint& lhs, const sint& rhs)
{
	return lhs.sign == rhs.sign && lhs.number == rhs.number;
}

bool operator!=(const sint& lhs, const sint& rhs)
{
	return lhs.sign != rhs.sign || lhs.number != rhs.number;
}

bool operator<(const sint& lhs, const sint& rhs)
{
	if(lhs.sign == rhs.sign)
	{
		if(lhs.sign == '+')
		{
			if(lhs.number.size() != rhs.number.size()) return lhs.number.size() < rhs.number.size();
			else return lhs.number < rhs.number;
		}
		else
		{
			if(lhs.number.size() != rhs.number.size()) return lhs.number.size() > rhs.number.size();
			else return lhs.number > rhs.number;
		}
	}
	else
	{
		if(lhs.sign == '+') return false;
		else return true;
	}
}

bool operator>(const sint& lhs, const sint& rhs)
{
	return !(lhs < rhs || lhs == rhs);
}

bool operator>=(const sint& lhs, const sint& rhs)
{
	return lhs > rhs || lhs == rhs;
}

bool operator<=(const sint& lhs, const sint& rhs)
{
	return lhs < rhs || lhs == rhs;
}

std::string sint::strnum_add(std::string num1, std::string num2)
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

sint& sint::operator-()
{
	sign = sign == '+' ? '-' : '+';
	return *this;
}

sint operator+(const sint& lhs, const sint& rhs)
{
	if(lhs.sign == rhs.sign)
	{
		if(lhs.sign == '+') return sint(sint::strnum_add(lhs.number, rhs.number));
		else return -sint(sint::strnum_add(lhs.number, rhs.number));
	}
	else
	{
		if(lhs.sign == '+')
		{
			auto rcopy = rhs;
			rcopy.sign = '+';
			return lhs - rcopy;
		}
		else
		{
			auto lcopy = lhs;
			lcopy.sign = '+';
			return rhs - lcopy;
		}
	}
}

sint operator-(const sint& lhs, const sint& rhs)
{
	if(lhs.sign == rhs.sign)
	{
		if(lhs.sign == '+')
		{
			if(lhs >= rhs) return sint(sint::strnum_sub(lhs.number, rhs.number));
			else return -sint(sint::strnum_sub(rhs.number, lhs.number));
		}
		else
		{
			if(lhs >= rhs) return sint(sint::strnum_sub(rhs.number, lhs.number));
			else return -sint(sint::strnum_sub(lhs.number, rhs.number));
		}
	}
	else
	{
		if(lhs.sign == '+')
		{
			auto rcopy = rhs;
			rcopy.sign = '+';
			return lhs + rcopy;
		}
		else
		{
			auto lcopy = lhs;
			lcopy.sign = '+';
			return -(lcopy + rhs);
		}
	}
}

std::string sint::strnum_sub(std::string num1, std::string num2)
{
	auto len = std::max(num1.size(), num2.size());
	bool borrow = false;
	std::string diff{};

	for(unsigned i = 0; i < len; ++i)
	{
		char n1 = i < num1.size() ? *(num1.rbegin() + i) : '0';
		char n2 = i < num2.size() ? *(num2.rbegin() + i) : '0';
		char n = n1 - n2 + '0';

		if(borrow)
		{
			--n;
			borrow = false;
		}

		if(n < '0')
		{
			n += 10;
			borrow = true;
		}

		diff.insert(0, 1, n);
	}

	if(!diff.empty())
	{
		auto pos = diff.find_first_not_of('0');

		if(pos != diff.npos) diff = diff.substr(pos);
		else diff = "";
	}

	return diff;
}

sint& sint::operator++()
{
	*this = *this + 1;
	return *this;
}

sint sint::operator++(int)
{
	auto old = *this;
	*this = *this + 1;
	return old;
}

sint& sint::operator--()
{
	*this = *this - 1;
	return *this;
}

sint sint::operator--(int)
{
	auto old = *this;
	*this = *this - 1;
	return old;
}

sint& sint::operator+=(const sint& other)
{
	*this = *this + other;
	return *this;
}

sint& sint::operator-=(const sint& other)
{
	*this = *this - other;
	return *this;
}

sint operator*(const sint& lhs, const sint& rhs)
{
	sint result;

	for(auto it = rhs.number.crbegin(); it != rhs.number.crend(); ++it)
	{
		sint temp;
		unsigned n = *it - '0';

		for(unsigned i = 0; i < n; ++i)
		{
			temp += lhs;
		}

		unsigned zeros = it - rhs.number.crbegin();

		for(unsigned i = 0; i < zeros; ++i)
			temp.number.push_back('0');

		result += temp;
	}

	if(lhs.sign == rhs.sign) result.sign = '+';
	else result.sign = '-';

	return result;
}

sint& sint::operator*=(const sint& other)
{
	*this = *this * other;
	return *this;
}

sint operator/(const sint& lhs, const sint& rhs)
{
	auto [q, r] = sint::divid(lhs, rhs);
	return q;
}

sint& sint::operator/=(const sint& other)
{
	*this = *this / other;
	return *this;
}

std::tuple<sint, sint> sint::divid(const sint& lhs, const sint& rhs)
{
	auto temp = sint(lhs.number.substr(0, rhs.number.size()));
	auto rcopy = rhs;
	rcopy.sign = '+';
	auto lcopy = lhs;
	lcopy.sign = '+';

	if(lcopy < rcopy) return std::tuple(lhs, sint(0));

	sint result;
	int steps = lhs.number.size()  - rhs.number.size() + 1;

	for(int i = 0; i < steps; ++i)
	{
		result *= 10;

		while(temp > rcopy)
		{
			temp -= rcopy;
			++result;
		}

		if(i != steps - 1)
			temp.number.push_back(lhs.number[rhs.number.size() + i]);
	}

	if(lhs.sign == rhs.sign) result.sign = '+';
	else result.sign = '-';

	return std::tuple(result, temp);
}

sint operator%(const sint& lhs, const sint& rhs)
{
	auto [q, r] = sint::divid(lhs, rhs);
	return r;
}

sint sint::power(const sint& n)
{
	sint p(1);

	for(sint i = 0; i < n; ++i)
		p *= *this;

	return p;
}

sint sint::digit_sum()
{
	sint s;

	for(auto d : number)
	{
		s += d - '0';
	}

	return s;
}
