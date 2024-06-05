#pragma once
#include "PureNumbersCollection.h"
#include "Collection.cpp"

enum CollectionType
{
	NORMAL_COLLECTION,
	SORTED_COLLECTION
};

class Set:public Collection
{
	PureNumbersCollection* collection;

public:
	Set(CollectionType);
	Set(const Set&) = delete;
	Set& operator=(const Set&) = delete;

	void add(int)override;
	void remove(int)override;
	bool contains(int el)const override;
	unsigned count(int el)const override;

	~Set();

};

