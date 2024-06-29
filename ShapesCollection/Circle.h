#pragma once
#include "Shape.h"
class Circle:public Shape
{
	double radius;

public:
	Circle(int x, int y, double radius);

	 double getArea()const override;
	 double getPer()const override;
	 bool isPointIn(int x, int y)const override;

	 Circle* clone()const override;

	 bool intersectWithCircle(Circle* c) override;
	 bool intersectWithRectangle(Rectangle* rect) override;
	 bool intersectWithTriangle(Triangle* tr)override;
	 bool intersectWith(Shape* shape)override;
};

