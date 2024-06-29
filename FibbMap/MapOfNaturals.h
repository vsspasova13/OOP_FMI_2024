#pragma once
#include <iostream>

constexpr int MAX_SIZE = 100;
class MapOfNaturals
{
	int data[MAX_SIZE];
	unsigned size = 0;

public:
	MapOfNaturals()
	{
		for (int i = 0; i < MAX_SIZE; i++)
		{
			data[i] = -1;
		}
	}

	void insert(int key, int val)
	{
		if (key > MAX_SIZE)
		{
			throw::std::out_of_range("Key is out of range");
		}
		data[key] = val;
		size++;
	}
	int get(int key)const
	{
		if (key > MAX_SIZE)
		{
			throw::std::out_of_range("Key is out of range");
		}
		return data[key];
		
	}
	bool containsKey(int key)const
	{
		if (key > MAX_SIZE)
		{
			throw::std::out_of_range("Key is out of range");
		}
		return data[key] != -1;
	}
	bool isEmpty()const
	{
		return size == 0;
	}
};

unsigned fibb(unsigned n)
{
	static MapOfNaturals map;
	if (map.isEmpty())
	{
		map.insert(1, 1);
		map.insert(2, 1);
	}
	if (!map.containsKey(n))
	{
		map.insert(n, fibb(n - 1) + fibb(n - 2));
	}
	return map.get(n);
}

