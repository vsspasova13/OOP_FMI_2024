#include <iostream>
#include "UniquePtr.h"

void UniquePtr::free()
{
    delete ptr;
}

void UniquePtr::moveFrom(UniquePtr&& other) noexcept
{
    ptr = other.ptr;
    other.ptr = nullptr;
}

UniquePtr::UniquePtr(A* ptr):ptr(ptr)
{

}

UniquePtr::UniquePtr(UniquePtr&& other) noexcept
{
    moveFrom(std::move(other));
}

UniquePtr& UniquePtr::operator=(UniquePtr&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

UniquePtr::~UniquePtr()
{
    free();
}

const A& UniquePtr::operator*() const
{
    return *ptr;
}

A& UniquePtr::operator*()
{
    return *ptr;
}
