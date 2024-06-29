#pragma once
#include <iostream>

class Bitset
{
	uint8_t* buckets = nullptr;
	unsigned bucketsCount = 0;
	unsigned N = 0;
	const unsigned elInBucket = sizeof(uint8_t) * 8;

	void free();
	void copyFrom(const Bitset& other);

	unsigned getBucketIndex(unsigned el)const;
public:
	Bitset(unsigned n);
	Bitset(const Bitset& other);
	Bitset& operator=(const Bitset& other);
	~Bitset();

	void add(unsigned num);
	void remove(unsigned num);
	bool contains(unsigned num)const;
	void print()const;
	friend Bitset unionOfSets(const Bitset& lhs, const Bitset& rhs);
	friend Bitset intersectionOfSets(const Bitset& lhs, const Bitset& rhs);


};

