#include "Queen.h"

Queen::Queen(bool isWhite) :Figure(isWhite)
{
}

bool Queen::canBeMoved(size_t currX, size_t currY, size_t destX, size_t destY) const
{
	return (abs((int)currX - (int)destX) == abs((int)currY - (int)destY)) ||
		(currX == destX) ||
		(currY == destY);

}

void Queen::print() const
{
	if (getIsWhite())
		std::cout << 'Q';
	else
		std::cout << 'q';
}
