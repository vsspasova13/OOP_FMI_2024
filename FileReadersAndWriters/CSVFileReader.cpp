#include "CSVFileReader.h"
#include <fstream>
#include <sstream>


int CSVFileReader::getCharCount(std::ifstream& ifs, char ch)
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

CSVFileReader::CSVFileReader(const MyString& fileName):FileReader(fileName)
{
}

int* CSVFileReader::read(size_t& size) const
{
    std::ifstream ifs(filePath.c_str());
    if (!ifs.is_open())
        throw std::exception("Cannot open the file");
    size = getCharCount(ifs, ',') + 1;
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        ifs >> arr[i];
        ifs.ignore();
    }
    ifs.close();
    return arr;

}
