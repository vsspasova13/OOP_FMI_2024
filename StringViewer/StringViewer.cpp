#include <iostream>
#include "StringViewer.h"

StringViewer::StringViewer(const char* begin, const char* end):begin(begin), end(end)
{
}

StringViewer::StringViewer(const char* str):StringViewer(str, str+strlen(str))
{
}

StringViewer::StringViewer(const MyString& str):StringViewer(str.c_str())
{
}

size_t StringViewer::length() const
{
    return end-begin;
}

char StringViewer::operator[](size_t ind) const
{
    return begin[ind];
}

StringViewer StringViewer::substtr(size_t from, size_t length)
{
if(begin+from+length>end)
throw std::length_error("Error, Substr out of range");

return StringViewer(begin + from, begin + from + length);

}

std::ostream& operator<<(std::ostream& os, const StringViewer& strView)
{
    const char* iter = strView.begin;

    while (iter != strView.end)
    {
        os << *iter;
        iter++;

    }
    return os;
}
