#include <iostream>
#include "Interval.h"

int main()
{
    Interval i(11, 20);
    std::cout << i.getPalindromeCount() << std::endl;
    std::cout << i.getPrimesCount() << std::endl;
    std::cout << i.getCountOfPowerOfTwo() << std::endl;
}