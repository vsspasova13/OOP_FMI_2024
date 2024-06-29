#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>

namespace GlobalConstants
{
    constexpr int FIELD_MAX_SIZE = 30;
    constexpr int MAX_FIELDS_ROW = 10;
    constexpr int ROWS_MAX_SIZE = 300;
    constexpr int BUFFER_SIZE = 1024;
    constexpr char SEP = ',';
}

typedef char Field[GlobalConstants::FIELD_MAX_SIZE];
typedef Field Row[GlobalConstants::MAX_FIELDS_ROW];

struct CsvTable
{
    Row rows[GlobalConstants::ROWS_MAX_SIZE];
    size_t rowsCount = 0;
    size_t collsCount = 0;
};

size_t parseRow(const char* row, Row& rowToReturn)
{
    std::stringstream ss(row);

    size_t currColumnCount = 0;
    while (!ss.eof())
    {
        ss.getline(rowToReturn[currColumnCount], GlobalConstants::FIELD_MAX_SIZE, GlobalConstants::SEP);
    }
    return currColumnCount;
}

CsvTable parseFromFile(std::ifstream& ifs)
{
    CsvTable res;
    char rowStr[GlobalConstants::BUFFER_SIZE];
    while (!ifs.eof())
    {
        ifs.getline(rowStr, GlobalConstants::BUFFER_SIZE, '\n');
        res.collsCount = parseRow(rowStr, res.rows[res.rowsCount++]);
    }
    return res;
}

CsvTable parseFromFile(const char* fileName)
{
    std::ifstream ifs(fileName);
    if (!ifs.is_open())
    {
        std::cout << "Error while opening the file" << std::endl;
        return {};
    }
    return parseFromFile(ifs);
}

void printTable(const CsvTable& table)
{
    for (size_t i = 0; i < table.rowsCount; i++)
    {
        for (size_t j = 0; j < table.collsCount; j++)
        {
            std::cout << table[i][j] << "       ";
        }
        std::cout << std::endl;
    }
}

void saveRowToFile(std::ofstream& ofs, const Row& row, size_t collCount)
{
    for (int i = 0; i < collCount; i++)
    {
        ofs << row[i];
        if (i != collCount - 1)
            ofs<<GlobalConstants::SEP;
    }
}

void saveToFile(std::ofstream& ofs, const CsvTable& table)
{
    for (size_t i = 0; i < table.rowsCount; i++)
    {
        saveRowToFile(ofs, table.rows[i], table.collsCount);
        if (i != table.rowsCount - 1)
            ofs << std::endl;
    }
}

void saveToFile(const char* fileName, const CsvTable& table)
{
    std::ofstream ofs(fileName);
    if (!ofs.is_open())
    {
        std::cout << "Error while opening the file" << std::endl;
        return {};
    }
    saveToFile(ofs, table);
    ofs.close();
}

int getColumnIndex(const CsvTable& table, const char* columnName)
{
    assert(table.collsCount >= 1);
    if (!columnName)
        return -1;
    for (size_t i = 0; i < table.collsCount; i++)
    {
        if (strcmp(columnName, table.rows[0][i]) == 0)
            return i;
    }
    return -1;
}

bool modify(CsvTable& table, const char* columnName, const char* newValues, char sep)
{
    int collInd = getColumnIndex(table, columnName);
    if (collInd == -1)return false;
    std::stringstream ss(newValues);

    int rowInd = 1;
    while (!ss.eof())
    {
        if (rowInd > table.rowsCount)
            break;
        ss.getline(table.rows[rowInd++][collInd], GlobalConstants::FIELD_MAX_SIZE, sep);
    }

    return true;
}

int main()
{
    
	CsvTable myFile = parseFromFile("students.csv");

	printTable(myFile);

	modify(myFile, "Ime", "Katerina|Petya", '|');

	saveToFile("students_new.csv", myFile);
}

