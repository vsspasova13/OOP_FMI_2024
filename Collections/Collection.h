#pragma once
class Collection
{
public:
	virtual void add(int n) = 0;
	virtual void remove(int n) = 0;
	virtual unsigned count(int n)const = 0;
	virtual bool contains(int n)const = 0;

	virtual ~Collection()=default;

};

