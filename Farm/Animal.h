#pragma once

enum class AnimalType
{
	Cat,
	Dog,
	Cow
};

class Animal
{
private:
	AnimalType type;

public:
	Animal(AnimalType type) : type(type) {};
	virtual void roar()const = 0;
	virtual Animal* clone()const=0;
	virtual ~Animal() = default;

	AnimalType getType()const
	{
		return type;
	}

};

