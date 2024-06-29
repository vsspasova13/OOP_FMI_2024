﻿
#include <iostream>
#include "Document.h"

void Document::display()const
{
    std::cout << content << std::endl;
    for (size_t i = 0; i < commentsCount; i++)
    {
        comments[i].print();
    }
}

void Document::addComment(const Comment& c)
{
    if (commentsCount == 100)
        throw std::out_of_range("No more space for comments.");
    comments[commentsCount++] = c;
   
}

void Document::setContent(const MyString& str)
{
    content = str;
}

void Comment::print() const
{
    std::cout << author << ": " << text << std::endl;
}
