#include "StringPool.h"
#include <iostream>

unsigned StringPool::allocatedNewString(const char* str)
{
    if (stringsCount == stringsCapacity)
        resize(stringsCapacity * 2);
    unsigned firstFreeIndex = stringsCount++;
    stringRecords[firstFreeIndex].str = new char[std::strlen(str) + 1];
    strcpy(stringRecords[firstFreeIndex].str, str);
    stringRecords[firstFreeIndex].refCount = 0;

    return firstFreeIndex;
}

void StringPool::resize(size_t newCap)
{
    stringsCapacity = newCap;
    StringRecord* newArr = new StringRecord[stringsCapacity];
    for (int i = 0; i < stringsCount; i++)
    {
        newArr[i] = stringRecords[i];
    }
    delete[]stringRecords;
    stringRecords = newArr;
}

int StringPool::findAllAllocatedStrings(const char* str) const
{
    for (int i = 0; i < stringsCount; i++)
    {
        if (strcmp(str, stringRecords[i].str) == 0)
            return i;
    }
    return -1;
}

void StringPool::removeRecord(unsigned index)
{
    std::swap(stringRecords[index], stringRecords[stringsCount-1]);
    delete[]stringRecords[stringsCount - 1].str;
}

StringPool::StringPool()
{
    stringsCapacity = 8;
    stringsCount = 0;
    stringRecords = new StringRecord[stringsCapacity];
}

const char* StringPool::getAllocatedStrings(const char* str)
{
    int index = findAllAllocatedStrings(str);

    if (index != -1)
    {
        stringRecords[index].refCount++;
        std::cout << "String found in cache, ref count:" << stringRecords[index].refCount << std::endl;
   
        return stringRecords[index].str;
    }

    else
    {
        std::cout << "String NOT found in cache. Allocating.." << std::endl;

        unsigned index = allocatedNewString(str);
        stringRecords[index].refCount++;
        return stringRecords[index].str;
    }
}

void StringPool::releaseString(const char* str)
{
    int index = findAllAllocatedStrings(str);

    stringRecords[index].refCount--;
    if (stringRecords[index].refCount == 0)
    {
        std::cout << "Removing record:" << stringRecords[index].str << "(No more refs)" << std::endl;
        removeRecord(index);
    }

}

StringPool::~StringPool()
{
    for (int i = 0; i < stringsCount; i++)
    {
        delete stringRecords[i].str;
    }
    delete[]stringRecords;
}
