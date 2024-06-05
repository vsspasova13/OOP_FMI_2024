#pragma once
#include "Animal.h"

class Farm
{
	Animal** animals;
	size_t animalsCount;
	size_t capacity;

	void free();
	void copyFrom(const Farm& other);
	void moveFrom(Farm&& other);
	void resize();

public:
	Farm();
	Farm(const Farm& other);
	Farm operator=(const Farm& other);
	~Farm();

	Farm(Farm&& other)noexcept;
	Farm operator=(Farm&& other)noexcept;

	void addAnimal(const Animal& animal);
	void addAnimal(AnimalType type);
	void roarAll()const;

	AnimalType getTypeByIndex(int index)const;
};

