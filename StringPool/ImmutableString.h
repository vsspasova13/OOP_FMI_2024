#pragma once
#include "StringPool.h"
#include <iostream>

class ImmutableString
{
private:
	const char* data;
	size_t length;

	void copyFrom(const ImmutableString& other);
	void free();

	explicit ImmutableString(size_t capacity);
	static StringPool pool;

public:
	ImmutableString(const char* data);
	ImmutableString(const ImmutableString& other);
	ImmutableString operator=(const ImmutableString& other);
	~ImmutableString();

	size_t getLength()const;
	char operator[](size_t index)const;
	const char* c_str()const;
};

std::ofstream& operator<<(std::ofstream& ofs, const ImmutableString& str);

bool operator==(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator<(const ImmutableString& lhs, const ImmutableString& rhs);
