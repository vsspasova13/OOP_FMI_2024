#include "DynamicSet.h"

void DynamicSet::copyFrom(const DynamicSet& other)
{
	bucketsCount = other.bucketsCount;
	N = other.N;
	buckets = new uint8_t[other.bucketsCount];
	for (int i = 0; i < other.bucketsCount; i++)
	{
		buckets[i] = other.buckets[i];
	}
}

void DynamicSet::free()
{
	delete[]buckets;
	buckets = nullptr;
	bucketsCount = N = 0;
}

DynamicSet::DynamicSet(unsigned n)
{
	bucketsCount = n / elInBuckets + 1;
	buckets = new uint8_t[bucketsCount]{ 0 };
	N = n;
}

unsigned DynamicSet::getBucketIndex(size_t n)const
{
	return n / elInBuckets;
}

DynamicSet::DynamicSet(const DynamicSet& other)
{
	copyFrom(other);
}

DynamicSet DynamicSet::operator=(const DynamicSet& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

DynamicSet::~DynamicSet()
{
	free();
}

void DynamicSet::add(unsigned n)
{
	if (n > N)
		throw std::invalid_argument("Num is bigger than N");

	size_t bucInd = getBucketIndex(n);
	size_t bitInd = n % elInBuckets;

	unsigned mask = 1 << bitInd;
	buckets[bucInd] |= mask;
}

void DynamicSet::remove(unsigned n)
{
	if (n > N)
		throw std::invalid_argument("Num is bigger than N");

	size_t bucInd = getBucketIndex(n);
	size_t bitInd = n % elInBuckets;

	unsigned mask = ~(1 << bitInd);
	buckets[bucInd] &= mask;
}

bool DynamicSet::contains(unsigned n)const
{
	if (n > N)
		throw std::invalid_argument("Num is bigger than N");

	size_t bucInd = getBucketIndex(n);
	size_t bitInd = n % elInBuckets;

	unsigned mask = 1 << bitInd;
	return buckets[bucInd] & mask;
}

unsigned DynamicSet::getN()const
{
	return N;
}

void DynamicSet::print()const
{
	std::cout << "{";
	for (int i = 0; i < N; i++)
	{
		if (contains(i))
			std::cout << i << " ";
	}
	std::cout << "}" << std::endl;
}

void DynamicSet::removeAll()
{
	for (int i = 0; i < bucketsCount; i++)
	{
		buckets[i] = 0;
	}
}

DynamicSet UnionOfSets(const DynamicSet& lhs, const DynamicSet& rhs)
{
	size_t num = lhs.N > lhs.N ? lhs.N : rhs.N;
	DynamicSet res(num);
	unsigned minBuck = lhs.bucketsCount > lhs.bucketsCount ? lhs.bucketsCount : rhs.bucketsCount;
	for (int i = 0; i < minBuck; i++)
	{
		res.buckets[i] = lhs.buckets[i] | rhs.buckets[i];
	}
	const DynamicSet& biggerN = lhs.bucketsCount > rhs.bucketsCount ? lhs : rhs;

	for (int i = minBuck; i < biggerN.bucketsCount; i++)
	{
		res.buckets[i] = biggerN.buckets[i];
	}
	return res;
}

DynamicSet IntersectionOfSets(const DynamicSet& lhs, const DynamicSet& rhs)
{
	size_t num = lhs.N < lhs.N ? lhs.N : rhs.N;
	DynamicSet res(num);

	unsigned minBuck=lhs.bucketsCount < lhs.bucketsCount ? lhs.bucketsCount : rhs.bucketsCount;
	for (int i = 0; i < minBuck; i++)
	{
		res.buckets[i] = lhs.buckets[i] & rhs.buckets[i];
	}
	return res;
}