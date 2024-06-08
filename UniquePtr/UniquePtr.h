#pragma once

struct A
{
	int a;
	int b;
};

class UniquePtr
{
	A* ptr;

	void free();
	void moveFrom(UniquePtr&& other)noexcept;

public:
	UniquePtr(A* ptr);
	UniquePtr(UniquePtr&& other)noexcept;
	UniquePtr& operator=(UniquePtr&& other)noexcept;
	UniquePtr(const UniquePtr& other)=delete;
	UniquePtr& operator=(const UniquePtr& other)=delete;
	~UniquePtr();

	const A& operator*()const;
	A& operator*();

};

