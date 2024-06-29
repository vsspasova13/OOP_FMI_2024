#pragma once
#include <iostream>

constexpr unsigned SECONDS_IN_HOUR = 3600;
constexpr unsigned SECONDS_IN_MIN = 60;
constexpr unsigned DAY_SECONDS = 24 * 3600;

class Time
{
private:
	unsigned secondsFromMidnight = 0;
	bool validateAndSet(unsigned lowerBound, unsigned upperBound, unsigned newValue, unsigned oldValue, unsigned multiplier);

public:
	Time()=default;
	Time(unsigned h, unsigned m, unsigned s);

	unsigned getHours()const;
	unsigned getMin()const;
	unsigned getSec()const;

	bool setHours(unsigned hours);
	bool setMin(unsigned min);
	bool setSec(unsigned sec);

	int compare(const Time& other) const;
	void tick();
	void serialize(std::ostream& os) const;

};

int compareTimes(const Time& lhs, const Time& rhs);

