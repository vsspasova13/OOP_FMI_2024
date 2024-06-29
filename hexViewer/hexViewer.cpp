#include <iostream>
#include <fstream>
#include <iomanip>

constexpr int HEX_ARRAY_SIZE = 3;

struct HexViewerFile
{
	unsigned char* data;
	size_t dataSize;
};

size_t getFileSize(std::ifstream& ifs)
{
	size_t curr = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	size_t size = ifs.tellg();
	ifs.seekg(curr, std::ios::beg);
	return size;
}

HexViewerFile init(const char* fileName)
{
	std::ifstream ifs(fileName, std::ios::in | std::ios::binary);
	HexViewerFile file;

	if (!ifs.is_open())
	{
		file.data = nullptr;
		file.dataSize = 0;
		return file;
	}

	file.dataSize = getFileSize(ifs);
	file.data = new unsigned char[file.dataSize];
	ifs.read((char*)file.data, file.dataSize);
	ifs.close();
	return file;
}

void freeHexViewerFile(HexViewerFile& file)
{
	delete[] file.data;
	file.dataSize = 0;
}

void saveHexViewerFile(const HexViewerFile& file, const char* fileName)
{
	std::ofstream ofs(fileName, std::ios::out | std::ios::binary);
	if (!ofs.is_open())
		return;
	ofs.write((const char*)file.data, file.dataSize);
	ofs.close();
}

bool isValidByte(char ch)
{
	return (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z');
}
bool isLetter(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
void getHexValue(char byte, char hex[HEX_ARRAY_SIZE])
{
	int quotient = byte / 16;
	int remainder = byte % 16;
	hex[0] = quotient > 9 ? (quotient - 10 + 'A') : (quotient + '0');
	hex[1] = remainder > 9 ? (remainder - 10 + 'A') : (remainder + '0');
	hex[2] = '\0';
}

void print(const HexViewerFile& file)
{
	/*for (size_t i = 0; i < file.dataSize; i++)
	{
		if (isValidByte(file.data[i]))
		{
			char hexValue[HEX_ARRAY_SIZE];
			getHexValue(file.data[i], hexValue);
			std::cout << hexValue;
		}
		else
		{ std::cout << ".."; }
			
	}*/
	for (size_t i = 0; i < file.dataSize; i++) {
		std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)file.data[i] << ' ';
	}
	std::cout << std::endl;

	for (size_t i = 0; i < file.dataSize; i++)
	{
		if (isLetter(file.data[i])) {
			std::cout << file.data[i] << "  ";
		}
		else {
			std::cout << ".. ";
		}
	}
}

void modify(HexViewerFile& file, unsigned idx, char val)
{
	if (idx >= file.dataSize)
		return;
	file.data[idx] = val;
}

int main()
{
	HexViewerFile myFile = init("myFile.dat");
	print(myFile);
	modify(myFile, 0, 'a');
	saveHexViewerFile(myFile, "myFile.dat");
	std::cout << std::endl;
	print(myFile);
	freeHexViewerFile(myFile);
}
