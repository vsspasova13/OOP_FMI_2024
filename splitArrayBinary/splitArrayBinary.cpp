#include <iostream>
#include <fstream>

size_t getFileSize(std::ifstream& ifs)
{
	size_t curr = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	size_t size = ifs.tellg();
	ifs.seekg(curr, std::ios::beg);
	return size;
}

int* fillArray(std::ifstream& ifs, size_t& size)
{
	size = getFileSize(ifs) / sizeof(int);
	int* arr = new int[size];
	ifs.read((char*)arr, size * sizeof(int));
	return arr;
}

size_t countOfEvenNumbers(const int* arr, size_t arrSize)
{
	int res = 0;
	for (size_t i = 0; i < arrSize; i++)
	{
		if (arr[i] % 2 == 0)
			res++;
	}
	return res;
}

void splitArray(const int* arr, size_t size, int* even, int* odd)
{

	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0)
		{
			*even = arr[i];
			++even;
		}
		else
		{
			*odd = arr[i];
			++odd;
		}
	}
}

bool saveArrayToFile(const char* fileName, const int* arr, size_t size)
{
	std::ofstream ofs(fileName, std::ios::out | std::ios::binary);
	if (!ofs.is_open())
		return false;
	ofs.write((const char*)arr, size * sizeof(int));
	ofs.close();
	return true;
}

bool splitArrays(const char* fileName, const char* oddFile, const char* evenFile)
{
	std::ifstream ifs(fileName, std::ios::in | std::ios::binary);
	if (!ifs.is_open())
		return false;
	size_t size;
	int* arr = fillArray(ifs, size);
	ifs.close();
	
	int evenSize = countOfEvenNumbers(arr, size);
	int oddSize = size - evenSize;
	int* even = new int[evenSize];
	int* odd = new int[oddSize];

	splitArray(arr, size, even, odd);
	bool res = saveArrayToFile(oddFile, odd, oddSize) && saveArrayToFile(evenFile, even, evenSize);

	delete[] odd;
	delete[] even;
	delete[] arr;

	return res;

}

int main()
{
	std::cout << "Hello World!\n";
}
