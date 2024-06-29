#include "King.h"

King::King(bool isWhite):Figure(isWhite)
{
}

bool King::canBeMoved(size_t currX, size_t currY, size_t destX, size_t destY) const
{
    return abs((int)currX - (int)destX) <=1 &&  abs((int)currY - (int)destY) <= 1;
}

void King::print() const
{
    if (getIsWhite())
        std::cout << "%";
    else
        std::cout << "$";
}
