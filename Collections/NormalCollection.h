#pragma once
#include "PureNumbersCollection.h"
class NormalCollection:public PureNumbersCollection
{
public:
	void add(int)override;
	void remove(int)override;
	bool contains(int)const override;
	unsigned count(int)const override;
	

};

