#include "Cow.h"
#include <iostream>

Cow::Cow() :Animal(AnimalType::Cow)
{
}

void Cow::roar() const
{
    std::cout << "Moo Moo";
}

Animal* Cow::clone() const
{
    Animal* newObj = new (std::nothrow) Cow(*this);
    return newObj;
}