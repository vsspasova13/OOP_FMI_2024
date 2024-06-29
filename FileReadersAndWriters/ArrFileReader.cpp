#include "ArrFileReader.h"
#include <fstream>

int ArrFileReader::getCharCount(std::ifstream& ifs, char ch)
{
    size_t curr = ifs.tellg();
    if (!ifs.is_open())
    {
        return -1;
    }
    int count = 0;
    while (true)
    {
        char curr = ifs.get();
        if (ifs.eof())
        {
            break;
        }
        if (curr == ch)
        {
            count++;
        }
    }

    ifs.close();
    ifs.seekg(curr);
    return count;
}

ArrFileReader::ArrFileReader(const MyString& filePath):FileReader(filePath)
{
}

int* ArrFileReader::read(size_t& size) const
{
    std::ifstream ifs(filePath.c_str());

    if (!ifs.is_open())
        throw std::exception("Couldn't open the file");
    size = getCharCount(ifs, ',') + 1;
    int* arr = new int[size];
    ifs.ignore();

    for (size_t i = 0; i < size; i++)
    {
        ifs >> arr[i];
    }
    ifs.close();
}
