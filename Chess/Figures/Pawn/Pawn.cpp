#include "Pawn.h"

Pawn::Pawn(bool isWhite):Figure(isWhite)
{
}

bool Pawn::canBeMoved(size_t currX, size_t currY, size_t destX, size_t destY) const
{
	if (getIsWhite())
		return currY - 1 == destY && abs((int)currX - (int)destX) <= 1;
	else
		return currY + 1 == destY && abs((int)currX - (int)destX) <= 1;
}

void Pawn::print() const
{
	if (getIsWhite())
		std::cout << 'P';
	else
		std::cout << 'p';
}
