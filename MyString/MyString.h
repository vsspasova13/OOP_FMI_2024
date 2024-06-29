#pragma once
#include <fstream>

class MyString
{
	char* data;
	size_t size;
	size_t allocatedSize;

	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other);
	void free();

	void resize(unsigned newAllocSize);
	explicit MyString(size_t length);

public:
	MyString();
	MyString(const char* data);

	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	MyString(MyString&& other)noexcept;
	MyString& operator=(MyString&& other)noexcept;
	~MyString();

	const char* c_str()const;
	size_t length()const;
	size_t getCapacity()const;

	MyString& operator+=(const MyString& other);

	char& operator[](int idx);
	const char& operator[](int idx)const;

	friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
	friend std::ifstream& operator>>(std::ifstream& ifs, MyString& obj);
	friend MyString operator+(const MyString& lhs, const MyString& rhs);

};

bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);
