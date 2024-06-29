#include "Transformer.hpp"

TT
class AllTransformer :public Transformer<T, N>
{
private:
	T* data = nullptr;
	size_t size = 0;

	void copyFrom(const AllTransformer& other);
	void moveFrom(AllTransformer&& other) noexcept;
	void free();

public:
	AllTransformer(const T* data, size_t size);

	AllTransformer(const AllTransformer& other);
	AllTransformer& operator=(const AllTransformer& other);

	AllTransformer(AllTransformer&& other)noexcept;
	AllTransformer& operator=(AllTransformer&& other)noexcept;

	~AllTransformer()noexcept;

	const size_t getSize()const;

	Tuple<T, N>& transform(Tuple<T, N>& tuple)const override;
	Transformer<T, N>* clone()const override;

};

TT
AllTransformer<T, N>::AllTransformer(const T* data, size_t size) : Transformer<T, N>()
{
	if (!data) return;

	this->size = size;

	this->data = new T[this->size];
	for (size_t i = 0; i < getSize(); i++)
		this->data[i] = data[i];
}


TT
AllTransformer<T, N>::AllTransformer(const AllTransformer<T, N>& other) : Transformer<T, N>(other)
{
	copyFrom(other);
}

TT
AllTransformer<T, N>& AllTransformer<T, N>::operator=(const AllTransformer<T, N>& other)
{
	if (this != &other)
	{
		Transformer<T, N>::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

TT
AllTransformer<T, N>::AllTransformer(AllTransformer<T, N>&& other) noexcept : Transformer<T, N>(std::move(other))
{
	moveFrom(std::move(other));
}

TT
AllTransformer<T, N>& AllTransformer<T, N>::operator=(AllTransformer<T, N>&& other) noexcept
{
	if (this != &other)
	{
		Transformer<T, N>::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}

	return *this;
}


TT
void AllTransformer<T, N>::copyFrom(const AllTransformer& other)
{
	this->size = other.size;
	data = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

TT
void AllTransformer<T, N>::moveFrom(AllTransformer&& other)
{
	this->size = other.size;
	this->data = other.data;
	other.size = 0;
	other.data = nullptr;
}

TT
void AllTransformer<T, N>::free()
{
	delete[] data;
	data = nullptr;
	size = 0;
}

TT
const size_t AllTransformer<T, N>::getSize()const
{
	return size;
}

TT
Tuple<T, N>& AllTransformer<T, N>::transform(Tuple<T,N>& tuple)const
{
	for (size_t i = 0; i < getSize(); i++)
	{
		if (i >= this->getSize())return tuple;
		tuple[i] = this->data[i];
	}
	return tuple;
}

TT
Transformer<T, N>* AllTransformer<T, N>::clone() const
{
	return new AllTransformer(*this);
}