#pragma once
#include "FileWriter.h"

class CSVFileWriter:FileWriter
{
public:
	CSVFileWriter(const MyString& filePath);
	void write(const int* arr, size_t size)const override;
};

