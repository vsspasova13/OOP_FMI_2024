#pragma once
#include "D:\УНИ\2 сем\ООП\osn zad\MyString\MyStringWithMove/MyString.h" 
#include <fstream>

class StringViewer
{
	const char* begin;
	const char* end;

public:
	StringViewer(const char* begin, const char* end);
	StringViewer(const char* str);
	StringViewer(const MyString& str);

	size_t length()const;
	char operator[](size_t ind)const;

	StringViewer substtr(size_t from, size_t length);
	friend std::ostream& operator<<(std::ostream&, const StringViewer& strView);

};

