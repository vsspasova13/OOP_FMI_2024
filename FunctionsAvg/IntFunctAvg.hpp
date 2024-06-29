#pragma once

template <class FunctOne, class FunctTwo>
class IntFunctionAverage
{
private:
	FunctOne first;
	FunctTwo second;

public:
	IntFunctionAverage(const FunctOne& fOne, const FunctTwo& fTwo) :
		first(fOne), second(fTwo) {};
	double average(int x)const
	{
		return (first(x) + second(x)) / 2.0;
	}
};