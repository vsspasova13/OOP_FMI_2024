#include "IntervalCollection.h"
#include <iostream>

IntervalCollection::IntervalCollection(int start, int end)
{
    if (start > end)
        std::swap(start, end);
    this->start = start;
    this->end = end;
    int size = end - start;

    data = new int[size] {0};
}

unsigned IntervalCollection::intervalLength() const
{
    return end-start;
}

void IntervalCollection::add(int el)
{
    if (el > end || el < start)
        return;
    int index = el - start;
    ++data[index];
}

void IntervalCollection::remove(int el)
{
    if (el > end || el < start)
        return;
    int index = el - start;
    --data[index];
}

unsigned IntervalCollection::count(int el) const
{
    if (el > end || el < start)
        return 0;
    int index = el - start;
   return data[index];
}

bool IntervalCollection::contains(int el) const
{
    return count(el)>0;
}
