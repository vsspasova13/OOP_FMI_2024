#pragma once
#include "../../ConfigEnums/ConfigEnums.h"
#include <iostream>
#include <cmath>

class Figure
{
	bool isWhite;

public:
	Figure(bool isWhite) :isWhite(isWhite) {};

	virtual bool canBeMoved(size_t currX, size_t currY, size_t destX, size_t destY)const = 0;
	virtual void print()const = 0;

	bool getIsWhite()const { return isWhite; }

	virtual ~Figure() = default;
};

