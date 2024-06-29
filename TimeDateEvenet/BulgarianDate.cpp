#include "BulgarianDate.h"
#include <iostream>

bool BulgarianDate::isLeapYear() const
{
	if (year < 1916)
		return (year % 4) == 0;
	else
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void BulgarianDate::validateDate()
{
	isDateValid = !((month == 0 || month > 12) ||
		(day == 0 || day > MAX_DAYS[month - 1]) ||
		(year == 0) ||
		(year == 1916 && month == 4 && day < 14));
}

BulgarianDate::BulgarianDate(unsigned d, unsigned m, unsigned y)
{
	setDay(d);
	setMonth(m);
	setYear(y);
}

unsigned BulgarianDate::getDay() const
{
	if (!good())return 0;
	return day;
}

unsigned BulgarianDate::getMonth() const
{
	if (!good())return 0;
	return month;
}

unsigned BulgarianDate::getYear() const
{
	if (!good())return 0;
	return year;
}

void BulgarianDate::setDay(unsigned d)
{
	if (!good())return;
	day = d;
	isModified = true;
	validateDate();
}

void BulgarianDate::setMonth(unsigned m)
{
	if (!good())return;
	month = m;
	isModified = true;
	validateDate();
}

void BulgarianDate::setYear(unsigned y)
{
	if (!good())return;
	year=y;
	if (isLeapYear())
	{
		MAX_DAYS[1] = 29;
	}
	else MAX_DAYS[1] = 28;
	isModified = true;
	validateDate();
}

void BulgarianDate::print() const
{
	if (!good())return;
	std::cout << day << "." << month << "." << year << std::endl;
}

void BulgarianDate::goToNextDay()
{
	if (!good())return;

	if (year == 1916 && month == 3 && day == 31)
	{
		day = 14;
		month = 4;
	}
	else
	{
		day++;
		if (day > MAX_DAYS[month - 1])
		{
			day = 1;
			setMonth(month == 12 ? 1 : (month + 1));
			if (month==1)
			{
				setYear(year + 1);
			}
		}
	}
	isModified = true;

}

int BulgarianDate::getDayOfWeek() const
{
	if (!good())return -1;
	if (!isModified)
		return dayOfWeek;
	BulgarianDate d(1, 1, 1);
	int day = 5;

	while (compareBulgarianDates(d, *this) != 0)
	{
		d.goToNextDay();
		day++;
		day %= 7;
	}
	dayOfWeek = day + 1;
	isModified = false;
	return dayOfWeek;
}

bool BulgarianDate::good() const
{
	return isDateValid;
}

void BulgarianDate::clear()
{
	isDateValid = true;
	day = month = year = 1;
}

int compareBulgarianDates(const BulgarianDate& lhs, const BulgarianDate& rhs)
{
	if (lhs.getYear() < rhs.getYear())
	{
		return -1;
	}
	else if (lhs.getYear() > rhs.getYear())
	{
		return 1;
	}
	else
	{ 
		if (lhs.getMonth() < rhs.getMonth())
		{
			return -1;
		}
		else if (lhs.getMonth() > rhs.getMonth())
		{
			return 1;
		}
		else
		{ 
			if (lhs.getDay() < rhs.getDay())
			{
				return -1;
			}
			else if (lhs.getDay() > rhs.getDay())
			{
				return 1;
			}
			else
			{
				return 0; 
			}
		}
	}
}
