#include "MyString.h"

static unsigned nextPowerOfTwo(unsigned n)
{
	n--;
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n++;
	return n;
}

void MyString::copyFrom(const MyString& other)
{
	size = other.size;
	allocatedSize = other.allocatedSize;
	data = new char[allocatedSize];
	strcpy(data,other.data);
}

void MyString::moveFrom(MyString&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	allocatedSize = other.allocatedSize;
	other.allocatedSize = other.size = 0;
}

void MyString::free()
{
	delete[]data;
	data = nullptr;
	size = allocatedSize = 0;
}

void MyString::resize(unsigned newAllocSize)
{
	allocatedSize = newAllocSize;
	char* temp = new char[allocatedSize+1];
	strcpy(temp, data);
	delete[]data;
	data = temp;
}

MyString::MyString(size_t length)
{
	allocatedSize = nextPowerOfTwo(length);
	data = new char[allocatedSize];
	size = 0;
	data[0] = '\0';
}

MyString::MyString():MyString("")
{
}

MyString::MyString(const char* data)
{
	size = strlen(data);
	allocatedSize = nextPowerOfTwo(size);
	this->data = new char[allocatedSize];
	strcpy(this->data, data);
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if(this!=&other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

MyString::MyString(MyString&& other) noexcept
{
	moveFrom(std::move(other));
}

MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

MyString::~MyString()
{
	free();
}

const char* MyString::c_str() const
{
	return data;
}

size_t MyString::length() const
{
	return this->size;
}

size_t MyString::getCapacity() const
{
	return this->allocatedSize-1;
}

MyString& MyString::operator+=(const MyString& other)
{
	
	if(size+other.size>allocatedSize){resize(size + other.size);}
	strncat(data, other.data, other.length());
	size += other.length();
	return *this;
}

char& MyString::operator[](int idx)
{
	return data[idx];
}

const char& MyString::operator[](int idx) const
{
	return data[idx];
}

std::ostream& operator<<(std::ostream& os, const MyString& obj)
{
	return os << obj.data;
}

std::ifstream& operator>>(std::ifstream& ifs, MyString& obj)
{
	char buff[1024];
	ifs >> buff;
	size_t buffStringSize = strlen(buff);
	if (buffStringSize > obj.getCapacity())
		obj.resize(nextPowerOfTwo(buffStringSize));
	strcpy(obj.data, buff);
	obj.size = buffStringSize;
	return ifs;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString res(lhs.length()+rhs.length());
	res += lhs;
	res += rhs;
	return res;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return (strcmp(lhs.c_str(), rhs.c_str()) == 0);
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return !(strcmp(lhs.c_str(), rhs.c_str()) == 0);
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return (strcmp(lhs.c_str(), rhs.c_str()) >= 0);
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return (strcmp(lhs.c_str(), rhs.c_str()) <= 0);
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
	return (strcmp(lhs.c_str(), rhs.c_str()) >0);
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
	return (strcmp(lhs.c_str(), rhs.c_str()) < 0);
}
