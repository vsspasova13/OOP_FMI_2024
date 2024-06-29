#pragma once
#include "Shape.h"
class Collection
{
private:
	Shape** shapes;
	size_t shapesCount;
	size_t capacity;

	void copyFrom(const Collection& other);
	void moveFrom(Collection&& other);
	void free();
	void resize();

	void addShape(Shape* shape);

public:
	Collection();
	Collection(const Collection& other);
	Collection(Collection&& other);
	Collection& operator=(const Collection& other);
	Collection& operator=(Collection&& other)noexcept;
	~Collection();

	void addRectangle(int x1, int y1, int x3, int y3);
	void addCircle(int x1, int y1, int r);
	void addTriangle(int x1, int y1, int x2, int y2, int x3, int y3);

	double getPerByIndex(int idx)const;
	double getAreaByIndex(int idx)const;
	bool getIfPointInByIndex(int idx, int x, int y)const;

};

