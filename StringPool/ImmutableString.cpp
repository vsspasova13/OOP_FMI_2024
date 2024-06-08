#include "ImmutableString.h"
StringPool ImmutableString::pool;

void ImmutableString::copyFrom(const ImmutableString& other)
{
	data = pool.getAllocatedStrings(other.data);
}

void ImmutableString::free()
{
	pool.releaseString(data);
	data = nullptr;
}

ImmutableString::ImmutableString(const char* data)
{
	data = pool.getAllocatedStrings(data);
	length = strlen(data);
}

ImmutableString::ImmutableString(const ImmutableString& other)
{
	copyFrom(other);
}

ImmutableString ImmutableString::operator=(const ImmutableString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

ImmutableString::~ImmutableString()
{
	free();
}

size_t ImmutableString::getLength() const
{
	return length;
}

char ImmutableString::operator[](size_t index) const
{
	return data[index];
}

const char* ImmutableString::c_str() const
{
	return data;
}

std::ofstream& operator<<(std::ofstream& ofs, const ImmutableString& str)
{
	return ofs << str.c_str();
}

bool operator==(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator<(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return !(lhs == rhs);
}

bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return (lhs > rhs && lhs == rhs);
}

bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return (lhs < rhs && lhs == rhs);
}

bool operator>(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return !(lhs < rhs);
}


