#pragma once
#include <iostream>
#include <exception>

template<typename T>
class Optional
{
	T* data;

	void moveFrom(Optional&& other);
	void copyFrom(const Optional& other);
	void free();

public:
	Optional();
	Optional(const T& obj);

	Optional(const Optional<T>& other);
	Optional(Optional<T>&& other)noexcept;

	Optional<T>& operator=(const Optional<T>& other);
	Optional<T>& operator=(Optional<T>&& other)noexcept;

	bool containsData()const;
	const T& getData()const;
	void setData(const T& el);
	void clear();

	~Optional();
};

template<typename T>
void Optional<T>::moveFrom(Optional<T>&& other)
{
	data = other.data;
	other.data = nullptr;
}

template<typename T>
void Optional<T>::copyFrom(const Optional& other)
{
	if (other.containsData())
		data = other.data;
	else
		data = nullptr;
}

template<typename T>
void Optional<T>::free()
{
	delete data;
}

template<typename T>
Optional<T>::Optional()
{
	data = nullptr;
}

template<typename T>
Optional<T>::Optional(const T& obj)
{
	data = nullptr;
	setData(obj);
}

template<typename T>
Optional<T>::Optional(const Optional<T>& other)
{
	copyFrom(other);
}

template<typename T>
Optional<T>::Optional(Optional<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
Optional<T>& Optional<T>::operator=(const Optional<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);

	}
	return *this;
}

template<typename T>
inline Optional<T>& Optional<T>::operator=(Optional<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
bool Optional<T>::containsData() const
{
	return data!=nullptr;
}

template<typename T>
const T& Optional<T>::getData() const
{
	if (!containsData())
		throw std::exception("No data");
	return *data;
}

template<typename T>
void Optional<T>::setData(const T& el)
{
	delete data;
	data = new T(el);
}

template<typename T>
void Optional<T>::clear()
{
	free();
	data = nullptr;
}

template<typename T>
inline Optional<T>::~Optional()
{
	free();
}
