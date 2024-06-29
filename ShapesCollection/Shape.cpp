#include "Shape.h"
#include <assert.h>

const Shape::Point& Shape::getPointAtIndex(size_t idx) const
{
    if (idx >= pointsCount)
        throw std::invalid_argument("Invalid index");
    return points[idx];
}

void Shape::copyFrom(const Shape& other)
{
    points = new Point[other.pointsCount];
    for (size_t i = 0; i < other.pointsCount; i++)
    {
        points[i] = other.points[i];
    }
    pointsCount = other.pointsCount;
}

void Shape::moveFrom(Shape&& other)
{
    points = other.points;
    pointsCount = other.pointsCount;
    other.pointsCount = 0;
    other.points = nullptr;
}

void Shape::free()
{
    delete[]points;
    points = nullptr;
    pointsCount = 0;
}

Shape::Shape(size_t pointsCount)
{
    this->pointsCount = pointsCount;
    points = new Point[pointsCount];
}

Shape::Shape(const Shape& other)
{
    copyFrom(other);
}

Shape& Shape::operator=(const Shape& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
   }
    return *this;
}

Shape::Shape(Shape&& other) noexcept
{
    moveFrom(std::move(other));
}

Shape& Shape::operator=(Shape&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Shape::~Shape()
{
    free();
}

void Shape::setPoint(size_t pointIdx, int x, int y)
{
    if (pointIdx >= pointsCount)
        throw std::exception("Invalid point index!");
    points[pointIdx] = Point(x, y);
}


double Shape::getPer() const
{
    assert(pointsCount >= 3);

    double per = 0;
    for (size_t i = 0; i < pointsCount-1; i++)
    {
        per += points[i].getDist(points[i + 1]);
    }
    return  per += points[pointsCount-1].getDist(points[0]);

}

