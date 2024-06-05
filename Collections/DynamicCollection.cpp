#include "DynamicCollection.h"
#include <iostream>

void DynamicCollection::free()
{
	delete[]data;
	data = nullptr;
	capacity = size = 0;
}

void DynamicCollection::copyFrom(const DynamicCollection& other)
{
	data = new int[other.capacity];
	for (int i = 0; i < other.capacity; i++)
	{
		data[i] = other.data[i];
	}
	capacity = other.capacity;
	size = other.size;
}

void DynamicCollection::moveFrom(DynamicCollection&& other)
{
	data = other.data;
	capacity = other.capacity;
	size = other.size;
	other.capacity = other.size = 0;
	other.data = nullptr;

}

void DynamicCollection::resize(size_t nCap)
{
	int* newData = new int[nCap];

	for (size_t i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
	capacity = nCap;
}


DynamicCollection::DynamicCollection(size_t cap)
{
	size = 0;
	capacity = cap;

	data = new int[capacity];
}

DynamicCollection::DynamicCollection()
{
	size = 0;
	capacity = 0;
	data = new int[capacity];
}

DynamicCollection::DynamicCollection(const DynamicCollection& other)
{
	copyFrom(other);
}

DynamicCollection& DynamicCollection::operator=(const DynamicCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

DynamicCollection::DynamicCollection(DynamicCollection&& other)noexcept
{
	moveFrom(std::move(other));
}

DynamicCollection& DynamicCollection::operator=(DynamicCollection&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

DynamicCollection::~DynamicCollection()
{
	free();
}
