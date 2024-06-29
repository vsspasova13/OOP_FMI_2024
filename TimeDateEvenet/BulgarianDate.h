#pragma once

class BulgarianDate
{
	unsigned MAX_DAYS[12]
	{ 31,28,31,30,31,30,31,31,30,31,30,31 };
	unsigned day = 1;
	unsigned month = 1;
	unsigned year = 1;

	bool isLeapYear()const;
	void validateDate();

	bool isDateValid = true;
	mutable bool isModified = true;
	mutable int dayOfWeek = -1;

public:
	BulgarianDate() = default;
	BulgarianDate(unsigned d, unsigned m, unsigned y);
	unsigned getDay()const;
	unsigned getMonth()const;
	unsigned getYear()const;

	void setDay(unsigned d);
	void setMonth(unsigned m);
	void setYear(unsigned y);

	void print()const;
	void goToNextDay();
	int getDayOfWeek()const;

	bool good()const;
	void clear();

};

int compareBulgarianDates(const BulgarianDate& lhs, const BulgarianDate& rhs);