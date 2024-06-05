#pragma once
#include "Collection.h"
class DynamicCollection:public Collection
{
protected:
	int* data = nullptr;
	size_t capacity=0;
	size_t size=0;

	void free();
	void copyFrom(const DynamicCollection& other);
	void moveFrom(DynamicCollection&& other);

	void resize(size_t newCap);
	DynamicCollection(size_t cap);

public:
	DynamicCollection();
	DynamicCollection(const DynamicCollection& other);
	DynamicCollection& operator=(const DynamicCollection& other);
	DynamicCollection(DynamicCollection&& other)noexcept;
	DynamicCollection& operator=(DynamicCollection&& other)noexcept;
	~DynamicCollection();

};

