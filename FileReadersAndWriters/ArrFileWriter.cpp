#include "ArrFileWriter.h"
#include <fstream>

ArrFileWriter::ArrFileWriter(const MyString& filePath):FileWriter(filePath)
{
}

void ArrFileWriter::write(const int* arr, size_t size) const
{
	std::ofstream ofs(filePath.c_str());

	if (!ofs.is_open())
		throw std::exception("Couldn't open the file");

	ofs << "[";
	for (size_t i = 0; i < size; i++)
	{
		ofs << arr[i];
		if (i != size - 1)
			ofs << ", ";
	}
	ofs << "]";
	ofs.close();
}
