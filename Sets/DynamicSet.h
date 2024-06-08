#pragma once
#include <iostream>

class DynamicSet
{
	uint8_t* buckets = nullptr;
	unsigned bucketsCount = 0;
	unsigned N;
	const unsigned elInBuckets = sizeof(uint8_t) * 8;

	void free();
	void copyFrom(const DynamicSet& other);

	unsigned getBucketIndex(size_t n)const;

public:
	DynamicSet(unsigned n);

	DynamicSet(const DynamicSet& other);
	DynamicSet operator=(const DynamicSet& other);
	~DynamicSet();

	void add(unsigned n);
	bool contains(unsigned n)const;
	void remove(unsigned n);
	unsigned getN()const;
	void print()const;
	void removeAll();
	friend DynamicSet UnionOfSets(const DynamicSet& lhs, const DynamicSet& rhs);
	friend DynamicSet IntersectionOfSets(const DynamicSet& lhs, const DynamicSet& rhs);


};

