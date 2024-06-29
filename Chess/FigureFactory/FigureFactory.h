#pragma once
#include "../ConfigEnums/ConfigEnums.h"
#include "../Figures/FigureBase/Figure.h"

class FigureFactory
{
public:
	static Figure* createFigure(bool isWhite, FigureType);
};

