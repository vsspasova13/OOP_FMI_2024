#include "Time.h"
#include <iomanip>

bool Time::validateAndSet(unsigned lowerBound, unsigned upperBound, unsigned newValue, unsigned oldValue, unsigned multiplier)
{
    if (newValue >= lowerBound && newValue <= upperBound)
    {
        (secondsFromMidnight -= (oldValue * multiplier)) += (newValue * multiplier);
        return true;
    }
    else return false;
}

int Time::compare(const Time& other) const {
    unsigned unix = secondsFromMidnight;
    unsigned otherUnix = other.secondsFromMidnight;

    if (unix == otherUnix) {
        return 0;
    }

    return unix < otherUnix ? -1 : 1;
}


Time::Time(unsigned h, unsigned m, unsigned s)
{
    setHours(h);
    setMin(m);
    setSec(s);
}

unsigned Time::getHours() const
{
    return secondsFromMidnight / SECONDS_IN_HOUR;
}

unsigned Time::getMin() const
{
    return (secondsFromMidnight / SECONDS_IN_MIN)%60;
}

unsigned Time::getSec() const
{
    return secondsFromMidnight % 60;
}

bool Time::setHours(unsigned hours)
{
    return validateAndSet(0, 23, hours, getHours(), SECONDS_IN_HOUR);
}

bool Time::setMin(unsigned min)
{
    return validateAndSet(0, 59, min, getMin(), SECONDS_IN_MIN);
}

bool Time::setSec(unsigned sec)
{
return validateAndSet(0, 59, sec, getSec(),1);
}

void Time::tick()
{
    ++secondsFromMidnight %= DAY_SECONDS;
}

void Time::serialize(std::ostream& os) const
{
    using namespace std;
    os << setw(2) << setfill('0') << getHours() << ":"
        << setw(2) << setfill('0') << getMin() << ":"
        << setw(2) << setfill('0') << getSec() << endl;
}

int compareTimes(const Time& lhs, const Time& rhs)
{
    if (lhs.getHours() == rhs.getHours())
    {
        if (lhs.getMin() == rhs.getMin())
        {
            return lhs.getSec() - rhs.getSec();
        }
        else
        {
            return lhs.getMin() - rhs.getMin();
        }
    }
    else return lhs.getHours() - rhs.getHours();
}
