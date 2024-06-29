#pragma once
#include <iostream>

class Circle;
class Triangle;
class Rectangle;

class Shape
{
protected:
	struct Point
	{
		int x;
		int y;
		Point() :x(0), y(0) {};
		Point(int x, int y) :x(x), y(y) {};
		double getDist(const Point& other)const
		{
			int dx = x - other.x;
			int dy = y - other.y;
			return sqrt(dx * dx + dy * dy);
		}
	};
	const Point& getPointAtIndex(size_t idx)const;
private:
	Point* points;
	size_t pointsCount;

	void copyFrom(const Shape& other);
	void moveFrom(Shape&& other);
	void free();

public:
	Shape(size_t pointsCount);
	Shape(const Shape& other);
	Shape& operator=(const Shape& other);
	Shape(Shape&& other)noexcept;
	Shape& operator=(Shape&& other)noexcept;
	virtual ~Shape();

	void setPoint(size_t pointIdx, int x, int y);

	virtual double getArea()const = 0;
	virtual double getPer()const;
	virtual bool isPointIn(int x, int y)const = 0;

	virtual Shape* clone()const=0;

	virtual bool intersectWithCircle(Circle* c) =0;
	virtual bool intersectWithRectangle(Rectangle* rect) =0;
	virtual bool intersectWithTriangle(Triangle* tr)=0;
	virtual bool intersectWith(Shape* shape)=0;


};

