#pragma once
#include <string>
#include <iostream>
#include <tuple>

class sint
{
private:
	char sign;
	std::string number;
public:
	sint();
	sint(std::string strnum);
	sint(const char* strnum);
	sint(long long n);
	sint(int n);
	friend std::ostream& operator<<(std::ostream& os, const sint& s);
public:
	friend bool operator==(const sint& lhs, const sint& rhs);
	friend bool operator!=(const sint& lhs, const sint& rhs);
	friend bool operator<(const sint& lhs, const sint& rhs);
	friend bool operator>(const sint& lhs, const sint& rhs);
	friend bool operator<=(const sint& lhs, const sint& rhs);
	friend bool operator>=(const sint& lhs, const sint& rhs);
public:
	static std::string strnum_add(const std::string num1, const std::string num2);
	static std::string strnum_sub(const std::string num1, const std::string num2);
	friend sint operator+(const sint& lhs, const sint& rhs);
	friend sint operator-(const sint& lhs, const sint& rhs);
	sint& operator-();
	sint& operator++();
	sint operator++(int);
	sint& operator--();
	sint operator--(int);
	sint& operator+=(const sint& other);
	sint& operator-=(const sint& other);
	friend sint operator*(const sint& lhs, const sint& rhs);
	friend sint operator/(const sint& lhs, const sint& rhs);
	sint& operator*=(const sint& other);
	sint& operator/=(const sint& other);
	friend sint operator%(const sint& lhs, const sint& rhs);
	static std::tuple<sint, sint> divid(const sint& lhs, const sint& rhs);
	sint power(const sint& n);
	sint digit_sum();

};
