#include <iostream>
#include "Farm.h"
#include "AnimalFactory.h"


void Farm::free()
{
	for (int i = 0; i < animalsCount; i++)
	{
		delete[]animals[i];
	}
	delete[]animals;
}

void Farm::copyFrom(const Farm& other)
{
	capacity = other.capacity;
	animalsCount = other.animalsCount;
	animals = new Animal * [capacity];

	for (int i = 0; i < animalsCount; i++)
	{
		Animal* cloned = other.animals[i]->clone();
		if (cloned)
			animals[i] = cloned;
	}


}

void Farm::moveFrom(Farm&& other)
{
	animalsCount = other.animalsCount;
	other.animalsCount = 0;

	capacity = other.capacity;
	other.capacity = 0;

	animals = other.animals;
	other.animals = nullptr;

}

void Farm::resize()
{
	Animal** newCollection = new Animal * [capacity *= 2];
	for (int i = 0; i < animalsCount; i++)
	{
		newCollection[i] = animals[i];
	}
	delete[]animals;
	animals = newCollection;

}

Farm::Farm()
{
	capacity = 8;
	animalsCount = 0;
	animals = new Animal * [capacity];
}

Farm::Farm(const Farm& other)
{
	copyFrom(other);
}

Farm Farm::operator=(const Farm& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Farm::~Farm()
{
	free();
}

Farm::Farm(Farm&& other) noexcept
{
	moveFrom(std::move(other));
}

Farm Farm::operator=(Farm&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void Farm::addAnimal(const Animal& animal)
{
	if (animalsCount == capacity)
		resize();
	animals[animalsCount++] = animal.clone();


}

void Farm::addAnimal(AnimalType type)
{
	if (animalsCount == capacity)
		resize();
	animals[animalsCount++] = getAnimal(type);
}

void Farm::roarAll() const
{
	for (int i = 0; i < animalsCount; i++)
	{
		animals[i]->roar(); std::cout << std::endl;
	}

}

AnimalType Farm::getTypeByIndex(int index) const
{
	return AnimalType();
}
