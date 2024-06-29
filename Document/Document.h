#pragma once
#include "/УНИ/2 сем/ООП/za izpit/MyString/MyString.h"

struct Comment
{
	MyString text = "okayy";
	MyString author = "Vili";

	void print()const;
};

class Document
{
	MyString content = "abcd";
	Comment comments[100];
	size_t commentsCount;

public:
	void display()const;
	void addComment(const Comment& c);
	void setContent(const MyString& str);

};

