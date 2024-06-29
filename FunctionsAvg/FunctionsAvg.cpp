#include <iostream>
#include <fstream>
#include "IntFunctAvg.hpp"

class NumInFile
{
private:
    int* data = nullptr;
    size_t size = 0;
    bool loaded = false;

    static unsigned getFileSize(std::ifstream& ifs)
    {
        size_t curr = ifs.tellg();
        ifs.seekg(0, std::ios::end);
        size_t s = ifs.tellg();
        ifs.seekg(curr, std::ios::beg);
        return s;
    }

    void load(const char* filePath)
    {
        std::ifstream ifs(filePath);
        if (!ifs.is_open())
        {
            return;
        }
        size = getFileSize(ifs);
        data = new int[size];
        ifs.read((char*)data, size * sizeof(int));
        loaded = true;
        ifs.close();
    }
    void copyFrom(const NumInFile& other)
    {
        size = other.size;
        data = new int[size] {};
        for (size_t i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    void free()
    {
        delete[] data;
    }

public:
    NumInFile(const char* filePath)
    {
        load(filePath);
    }

    int operator()(int x)const
    {
        for (size_t i = 0; i < size; i++)
        {
            if (data[i] == x)
                return x;
        }
        return 0;
    }

    bool good()const
    {
        return loaded;
    }
    NumInFile(const NumInFile& other)
    {
        copyFrom(other);
    }

    NumInFile& operator=(const NumInFile& other)
    {
        if (this != &other)
        {
            free();
            copyFrom(other);
        }
        return *this;
    }

    ~NumInFile()
    {
        free();
    }
};


int main()
{
    char filePath[1024]{};
    std::cin.getline(filePath, 1024);

    NumInFile func(filePath);
    if (func.good())
    {
        std::cout << "Loaded!" << std::endl;
    }
    else
    {
        std::cout << "Invalid file path";
        return 1;
    }

    IntFunctionAverage<NumInFile, int (*)(int)> f(func, 
                                                  [](int x) -> int{return x;} );

    while (true)
    {
        int num = 0;
        std::cin >> num;
        std::cout << "Average: " << f.average(num) << std::endl;
    }
}