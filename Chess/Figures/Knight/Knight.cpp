#include "Knight.h"

Knight::Knight(bool isWhite):Figure(isWhite)
{
}

bool Knight::canBeMoved(size_t currX, size_t currY, size_t destX, size_t destY) const
{
   /* return (abs((int)currX-(int)destX)==2 && abs((int)currY - (int)destY) == 1)||
    (abs((int)currX - (int)destX) == 1 && abs((int)currY - (int)destY) == 2);*/
    static int xMove[] = { 1,1,-1,-1,2,-2,2,-2 };
    static int yMove[] = { 2,-2,2,-2,1,1,-1,-1 };

    for (size_t i = 0; i < 8; i++)
    {
        if (currX + xMove[i] == destX && currY + yMove[i] == destY)return true;
    }
    return false;

}

void Knight::print() const
{
    if (getIsWhite())
        std::cout << 'K';
    else
        std::cout << 'k';
}
