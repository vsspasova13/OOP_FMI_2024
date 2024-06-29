#include <iostream>
#define TT template<typename T, size_t N>

TT
class Tuple
{
private:
	T data[N];

public:
	const size_t getSize()const;
	const T& operator[](int index)const;
	T& operator[](int index);
	void print()const;

};

TT
const size_t Tuple<T, N>::getSize() const
{
	return N;
}

TT
const T& Tuple<T, N>::operator[](int index)const
{
	return this->data[index];
}

TT
 T& Tuple<T, N>::operator[](int index)
{
	return this->data[index];
}

TT
void Tuple<T, N>::print()const
{
	std::cout << "[ ";
	for (size_t i = 0; i < N; i++)
	{
		std::cout << this->data[i] << " ";
	}
	std::cout << "]" << std::endl;
}