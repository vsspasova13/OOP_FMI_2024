#pragma once
#include "PureNumbersCollection.h"
class SortedCollection:public PureNumbersCollection
{
	int lowerBound(int x)const;
	int upperBound(int x)const;
public:
	void add(int) override;
	void remove(int)override;
	bool contains(int)const override;
	unsigned count(int)const override;
};

