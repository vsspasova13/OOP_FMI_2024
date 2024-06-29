#include "Bishop.h"
#include <cmath>

Bishop::Bishop(bool isWhite):Figure(isWhite)
{
}

bool Bishop::canBeMoved(size_t currX, size_t currY, size_t destX, size_t destY) const
{
    return abs((int)currX-(int)destX)==abs((int)currY-(int)destY);
}

void Bishop::print() const
{
    if (getIsWhite())
        std::cout << "B";
    else std::cout << "b";
}
