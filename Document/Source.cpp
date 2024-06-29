#pragma once
#include <iostream>
#include "Document.h"

class Viewer
{
public:
    void view(const Document& doc)const
    {
        doc.display();
    }
};

class Commenter :public Viewer
{
public:
    void addComment(Document& doc, const Comment& com)
    {
        doc.addComment(com);
    }
};

class Editor :public Commenter
{
public:
    void edit(Document& doc, const MyString& newCont)
    {
        doc.setContent(newCont);
    }
};


int main()
{
    Document d;
    Viewer v;
    v.view(d);

    Commenter c;
    Comment comm;
    c.addComment(d, comm);
    c.view(d);

    Editor e;
    e.edit(d, "qwertyuiop");
    e.view(d);
}
