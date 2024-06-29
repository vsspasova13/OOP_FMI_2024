#include "Circle.h"
const double PI = 3.141;


Circle::Circle(int x, int y, double radius):Shape(x,y),radius(radius)
{
}

double Circle::getArea() const
{
    return PI * radius*radius;
}

double Circle::getPer() const
{
    return 2 * PI * radius;
}

bool Circle::isPointIn(int x, int y) const
{
    Shape::Point p(x, y);
    return p.getDist(getPointAtIndex(0)) <= radius;
}

Circle* Circle::clone() const
{
    return new Circle(*this);
}

bool Circle::intersectWithCircle(Circle* c)
{
    std::cout << "Circle + Circle" << std::endl;
    return true;
}

bool Circle::intersectWithRectangle(Rectangle* rect)
{
    std::cout << "Circle + Rectangle" << std::endl;
    return true;
}

bool Circle::intersectWithTriangle(Triangle* tr)
{
    std::cout << "Circle + Triangle" << std::endl;
    return true;
}

bool Circle::intersectWith(Shape* shape)
{
    return shape->intersectWith(this);
}
