#include "Collection.h"
#include <stdexcept>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

void Collection::copyFrom(const Collection& other)
{
    shapes = new Shape * [other.capacity];
    for (size_t i = 0; i < other.capacity; i++)
    {
        shapes[i] = other.shapes[i]->clone();
    }
    shapesCount = other.shapesCount;
    capacity = other.capacity;
}

void Collection::moveFrom(Collection&& other)
{
    shapes = other.shapes;
    shapesCount = other.shapesCount;
    capacity = other.capacity;

    other.capacity = other.shapesCount = 0;
    other.shapes = nullptr;
}

void Collection::free()
{
    for (size_t i = 0; i < shapesCount; i++)
    {
        delete shapes[i];
    }
    delete[] shapes;
}

void Collection::resize()
{
    Shape** temp = new Shape * [capacity * 2];
    for (size_t i = 0; i < shapesCount; i++)
    {
        temp[i] = shapes[i];
    }
    capacity *= 2;
    delete[]shapes;
    shapes = temp;
}

void Collection::addShape(Shape* shape)
{
    if (shapesCount == capacity)
    {
        resize();
    }
    shapes[shapesCount++] = shape;
}

Collection::Collection()
{
    capacity = 8;
    shapesCount = 0;
    shapes = new Shape * [capacity];

}

Collection::Collection(const Collection& other)
{
    copyFrom(other);
}

Collection::Collection(Collection&& other)
{
    moveFrom(std::move(other));
}

Collection& Collection::operator=(const Collection& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
   }
    return *this;
}

Collection& Collection::operator=(Collection&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}


Collection::~Collection()
{
    free();
}

void Collection::addRectangle(int x1, int y1, int x3, int y3)
{
    Rectangle* r = new Rectangle(x1, y1, x3, y3);
    addShape(r);
}

void Collection::addCircle(int x1, int y1, int r)
{
    Circle* cir = new Circle(x1, y1, r);
    addShape(cir);
}

void Collection::addTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    Triangle* tr = new Triangle(x1, y1, x2, y2, x3, y3);
    addShape(tr);
}

double Collection::getPerByIndex(int idx) const
{
    if (idx >= shapesCount)
    {
        throw std::out_of_range("Index is out of range");
    }
    return shapes[idx]->getPer();
}

double Collection::getAreaByIndex(int idx) const
{

    if (idx >= shapesCount)
    {
        throw std::out_of_range("Index is out of range");
    }
    return shapes[idx]->getArea();
}

bool Collection::getIfPointInByIndex(int idx, int x, int y) const
{

    if (idx >= shapesCount)
    {
        throw std::out_of_range("Index is out of range");
    }
    return shapes[idx]->isPointIn(x, y);
}
