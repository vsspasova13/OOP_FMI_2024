#pragma once


class Interval
{
	int a = INT_MIN;
	int b = INT_MAX;

public:
	Interval();
	Interval(int a, int b);
	void setA(int a);
	void setB(int b);
	int getA()const;
	int getB()const;

	int getLength()const;
	bool isInInterval(int num)const;
	unsigned getCount(bool(*pred)(int))const;
	unsigned getPrimesCount()const;
	unsigned getPalindromeCount()const;
	unsigned getCountOfPowerOfTwo()const;
	bool isSubInterval(const Interval& other)const;
};

Interval intersectInt(const Interval& lhs, const Interval& rhs);
