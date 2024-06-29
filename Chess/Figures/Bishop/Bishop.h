#pragma once
#include "../FigureBase/Figure.h"

class Bishop:public Figure
{

public:
	Bishop(bool isWhite);
	bool canBeMoved(size_t currX, size_t currY, size_t destX, size_t destY)const override;
	void print()const override;
};

