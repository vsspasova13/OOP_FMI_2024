#pragma once
#include "../FigureBase/Figure.h"

class Queen :public Figure
{
public:
	Queen(bool isWhite);
	bool canBeMoved(size_t currX, size_t currY, size_t destX, size_t destY)const override;
	void print()const override;
};
