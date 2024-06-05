#include "NormalCollection.h"
#include <iostream>

void NormalCollection::add(int el)
{
    if (size == capacity)
        resize(2 * size);
    data[size++]=el;
    
}

void NormalCollection::remove(int el)
{
    int elIndex = -1;
    for (int i = 0; i < size; i++)
    {
        if (data[i] == el)
        {
            elIndex = i; break;
        }
    }
    if (elIndex != -1)
    {
        std::swap(data[size-1], data[elIndex]);
        size--;
    }
}

bool NormalCollection::contains(int el) const
{
  
    for (int i = 0; i < size; i++)
    {
        if (data[i] == el)
        {
            return true;
        }
    }
    return false;
}

unsigned NormalCollection::count(int el) const
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (data[i] == el)
        {
            count++;
        }
    }
    return count;
}
