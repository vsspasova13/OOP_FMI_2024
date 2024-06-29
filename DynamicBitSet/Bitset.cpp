#include "Bitset.h"

void Bitset::free()
{
    delete[]buckets;
    buckets = nullptr;
    N = 0;
    bucketsCount = 0;
}

void Bitset::copyFrom(const Bitset& other)
{
    N = other.N;
    bucketsCount = other.bucketsCount;
    buckets = new uint8_t[bucketsCount];
    for (int i = 0; i < bucketsCount; i++)
    {
        buckets[i] = other.buckets[i];
    }
}

unsigned Bitset::getBucketIndex(unsigned el) const
{
    return el/elInBucket;
}

Bitset::Bitset(unsigned n)
{
    bucketsCount = n / elInBucket + 1;
    buckets = new uint8_t[bucketsCount]{ 0 };
    this->N = n;
}

Bitset::Bitset(const Bitset& other)
{
    copyFrom(other);
}

Bitset& Bitset::operator=(const Bitset& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Bitset::~Bitset()
{
    free();
}

void Bitset::add(unsigned num)
{
    if (num > N)return;
    int mask = 1 << (num%elInBucket);
    int bucketInd = getBucketIndex(num);
    buckets[bucketInd] |= mask;

}

void Bitset::remove(unsigned num)
{
    if (num > N )return;
    int mask = ~(1 << (num % elInBucket));
    int bucketInd = getBucketIndex(num);
    buckets[bucketInd] &= mask;
}

bool Bitset::contains(unsigned num) const
{   
    if (num > N)return;
    int mask = 1 << (num % elInBucket);
    int bucketInd = getBucketIndex(num);
    return buckets[bucketInd] &= mask;
}

void Bitset::print() const
{
    std::cout << "{";
    for (int i = 0; i < N; i++)
    {
        if (contains(i))std::cout << i << ",";
    }
    std::cout << "}" << std::endl;
}

Bitset unionOfSets(const Bitset& lhs, const Bitset& rhs)
{
    
    int maxN = lhs.N > rhs.N ? lhs.N : rhs.N;
    Bitset res(maxN);
    int minBuckCount = lhs.bucketsCount < rhs.bucketsCount ? lhs.bucketsCount : rhs.bucketsCount;
    for (int i = 0; i < minBuckCount; i++)
    {
        res.buckets[i] = lhs.buckets[i] | rhs.buckets[i];
    }
    const Bitset& bigger = lhs.bucketsCount > rhs.bucketsCount ? lhs : rhs;
    for (size_t i = minBuckCount; i < bigger.bucketsCount; i++)
    {
        res.buckets[i] = bigger.buckets[i];
    }
    return res;

}

Bitset intersectionOfSets(const Bitset& lhs, const Bitset& rhs)
{
    int minN = lhs.N < rhs.N ? lhs.N : rhs.N;
    Bitset res(minN);
    int minBuckCount = lhs.bucketsCount < rhs.bucketsCount ? lhs.bucketsCount : rhs.bucketsCount;

    for (int i = 0; i < minBuckCount; i++)
    {
        res.buckets[i] = lhs.buckets[i] & rhs.buckets[i];
    }
    return res;
}
