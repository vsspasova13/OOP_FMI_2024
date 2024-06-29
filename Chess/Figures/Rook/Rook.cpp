#include "Rook.h"

Rook::Rook(bool isWhite):Figure(isWhite)
{
}

bool Rook::canBeMoved(size_t currX, size_t currY, size_t destX, size_t destY) const
{
    return  (currX == destX) || (currY == destY);
}

void Rook::print() const
{
    if (getIsWhite())
        std::cout << "R";
    else std::cout << "r";
}
