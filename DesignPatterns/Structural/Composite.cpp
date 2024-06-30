#include "../../Vector/Vector.hpp"
#include "../../PolymorphicPtr/Polymorphic_Ptr.hpp"
#include <iostream>

class FileSystemEnity
{
public:
	virtual size_t getSize()const = 0;
	virtual ~FileSystemEnity() = default;
};

class File :public FileSystemEnity
{
	size_t size = 0;
public:
	size_t getSize() const {
		return size;
	}
};

class Directory :public FileSystemEnity
{
	Vector<Polymorphic_Ptr<FileSystemEnity>> children;
public:
	size_t getSize()const override
	{
		size_t size = 0;
		for (size_t i = 0; i < children.getSize(); i++)
		{
			size += children[i]->getSize();
		}
		return size;
	}
};
