#include <iostream>
#include "Interval.h"

namespace
{
	bool isPrime(int x)
	{
		if (x < 2)return false;
		double temp = sqrt(x);
		for (int i = 2; i <= temp; i++)
		{
			if (x % i == 0)return false;
		}
		return true;
	}
	int reverse(int n)
	{
		int rev = 0;
		while (n != 0)
		{
			rev = rev * 10 + n % 10;
			n /= 10;
		}
		return rev;
	}
	bool isPalidrome(int x)
	{
		return x == reverse(x);
	}

	bool isPowerOfTwo(int n)
	{
		if (n < 0)
			return false;
		return(n & n - 1) == 0;
	}
}


Interval::Interval():Interval(0,0)
{
}

Interval::Interval(int a, int b)
{
	setA(a);
	setB(b);
}

void Interval::setA(int a)
{
	if (a > this->b)
		a = this->b;
	this->a = a;
}

void Interval::setB(int b)
{
if (b > this->a)
		b = this->a;
	this->b = b;
}

int Interval::getA() const
{
	return this->a;
}

int Interval::getB() const
{
	return this->b;
}

int Interval::getLength() const
{
	return b - a + 1;
}

bool Interval::isInInterval(int num) const
{
	return a<=num && num<=b;
}

unsigned Interval::getCount(bool(*pred)(int)) const
{
	unsigned count = 0;
	for (int i = a; i <-b; i++)
	{
		if (pred(i))
			count++;
	}
}

unsigned Interval::getPrimesCount() const
{
	return getCount(isPrime);
}

unsigned Interval::getPalindromeCount() const
{
	return getCount(isPalidrome);
}

unsigned Interval::getCountOfPowerOfTwo() const
{
	return getCount(isPowerOfTwo);
}

bool Interval::isSubInterval(const Interval& other) const
{
	return a >= other.a && b <= other.b;
}

Interval intersectInt(const Interval& lhs, const Interval& rhs)
{
	int newA = std::max(lhs.getA(), rhs.getA());
	int newB = std::min(lhs.getB(), rhs.getB());
	if (newA > newB)
		std::cout << "Error";
	return Interval(newA, newB);
}
