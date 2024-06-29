#include "Rectangle.h"

Rectangle::Rectangle(int x1, int y1, int x3, int y3):Shape(4)
{
    setPoint(0, x1, y1);
    setPoint(1, x1, y3);
    setPoint(2, x3, y3);
    setPoint(3, x3, y1);

}

double Rectangle::getArea() const
{
    const Shape::Point& p0 = getPointAtIndex(0);
    const Shape::Point& p1 = getPointAtIndex(1);
    const Shape::Point& p3 = getPointAtIndex(3);

    return (p0.getDist(p1)) * (p0.getDist(p3));
}

bool Rectangle::isPointIn(int x, int y) const
{
    Shape::Point p(x, y);
    return (p.x >= getPointAtIndex(0).x) && p.x <= getPointAtIndex(3).x
        && p.y <= getPointAtIndex(0).y && p.y >= getPointAtIndex(3).y;
}

Shape* Rectangle::clone() const
{
    return new Rectangle(*this);
}

bool Rectangle::intersectWith(Shape* shape)
{
    return shape->intersectWith(this);
}

bool Rectangle::intersectWithCircle(Circle* c)
{
    std::cout << "Rectangle + Circle" << std::endl;
    return true;
}

bool Rectangle::intersectWithTriangle(Triangle* t)
{
    std::cout << "Rectangle + Triangle" << std::endl;
    return true;
}

bool Rectangle::intersectWithRectangle(Rectangle* r)
{
    std::cout << "Rectangle + Rectangle" << std::endl;
    return true;
}
