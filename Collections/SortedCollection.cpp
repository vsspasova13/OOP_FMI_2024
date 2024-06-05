#include "SortedCollection.h"

int SortedCollection::lowerBound(int x) const
{
    int left = 0;
    int right = size - 1;
    int indexToReturn = size;

    while (left <= right)
    {
        int mid = left + (right - left / 2);
        if (data[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
            indexToReturn = mid;
        }
    }
    return indexToReturn;
}

int SortedCollection::upperBound(int x) const
{
    int left = 0;
    int right = size - 1;
    int indexToReturn = size;

    while (left <= right)
    {
        int mid = left + (right - left / 2);
        if (data[mid] <= x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
            indexToReturn = mid;
        }
    }
    return indexToReturn;
}

void SortedCollection::add(int el)
{
    if (size == capacity)
    {
        resize(capacity * 2);
    }
    int indx = size;
    while (indx > 0 && data[indx-1] > el)
    {
        data[indx] = data[indx - 1];
        --indx;
    }
    data[indx] = el;
    size++;
}

void SortedCollection::remove(int el)
{
    int inx = lowerBound(el);
    if (inx == size)
        return;
    for (int i = inx; i < size-1; i++)
    {
        data[i] = data[i + 1];
    }
    size--;
}

bool SortedCollection::contains(int el) const
{
    return lowerBound(el) != size;
}

unsigned SortedCollection::count(int el) const
{
    int left = lowerBound(el);
    if (left == size)
        return 0;
    int right = upperBound(el);
    return right - left;
}
