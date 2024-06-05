#include "Cat.h"
#include <iostream>

Cat::Cat():Animal(AnimalType::Cat)
{
}

void Cat::roar() const
{
    std::cout << "Meow Meow";
}

Animal* Cat::clone() const
{
    Animal* newObj = new (std::nothrow) Cat(*this);
    return newObj;
}
