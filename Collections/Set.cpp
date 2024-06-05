#include "Set.h"
#include "NormalCollection.h"
#include "SortedCollection.h"

Set::Set(CollectionType type)
{
    if (type == NORMAL_COLLECTION)
        collection = new NormalCollection();
    if (type == SORTED_COLLECTION)
        collection = new SortedCollection();
}

void Set::add(int el)
{
    if (!collection->contains(el))
        collection->add(el);
}

void Set::remove(int el)
{
    collection->remove(el);
}

bool Set::contains(int el) const
{
    return collection->contains(el);
}

unsigned Set::count(int el) const
{
    return collection->count(el);
}

Set::~Set()
{
    delete collection;
}
