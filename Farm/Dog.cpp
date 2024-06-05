#include "Dog.h"
#include <iostream>

Dog::Dog():Animal(AnimalType::Dog)
{
}

void Dog::roar() const
{
    std::cout << "Bow Bow";
}

Animal* Dog::clone() const
{
    Animal* newObj = new (std::nothrow) Dog(*this);
    return newObj;
}
