#pragma once

class StringPool
{
private:
	struct StringRecord
	{
		char* str = nullptr;
		unsigned refCount = 0;
	};
	StringRecord* stringRecords;
	size_t stringsCount = 0; 
	size_t stringsCapacity = 0;

	unsigned allocatedNewString(const char* str);
	void resize(size_t newCap);
	int findAllAllocatedStrings(const char* str)const;
	void removeRecord(unsigned index);

public:
	StringPool();
	const char* getAllocatedStrings(const char* str);
	void releaseString(const char* str);
	StringPool(const StringPool& other)=delete;
	StringPool& operator=(const StringPool& other)=delete;
	~StringPool();

};

