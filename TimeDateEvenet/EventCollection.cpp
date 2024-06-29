#include "EventCollection.h"

EventCollection EventCollection::eventsOnDate(const BulgarianDate& date) const
{
    EventCollection res;
    for (size_t i = 0; i < size; i++)
    {
        if (compareBulgarianDates(date, events[i].getDate()) == 0)
            res.addEvent(events[i]);
    }
    return res;
}

int EventCollection::findEventByName(const char* name) const
{
    
    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(name, events[i].getName()) == 0)
            return i;
    }
    return -1;
}

void EventCollection::reverse()
{
}

bool EventCollection::addEvent(const Event& event)
{
    if (size >= 30)
        return false;
    events[size] = event;
    size++;
    return true;
}

EventCollection EventCollection::maxEvents(const BulgarianDate& date) const
{
    EventCollection sameDate = eventsOnDate(date);
    for (size_t i = 0; i < size-1; i++)
    {
        size_t minInd = i;
        for (size_t j = i+1; j < size; j++)
        {
            if(sameDate.events[minInd].getEndTime().compare(sameDate.events[j].getEndTime())==1)
            {minInd=j;}
        }
        if (minInd != i)
        {
            std::swap(sameDate.events[minInd], sameDate.events[i]);
        }
    }

    EventCollection res;
    res.addEvent(sameDate.events[0]);
    for (size_t i = 0; i < sameDate.size; i++)
    {
        if (sameDate.events[i].getStartTime().compare(sameDate.events[res.size - 1].getEndTime()) >= 0) {
            res.addEvent(sameDate.events[i]);
        }
    }
    return res;
}

bool EventCollection::removeEvent(const char* name)
{
    int idx = findEventByName(name);
    if (idx == -1)
        return false;
    events[idx] = events[size - 1];
    size--;
    return true;
}

void EventCollection::print() const
{
    for (size_t i = 0; i < size; i++) {
        std::cout << events[i].getName() << std::endl;
    }
}
