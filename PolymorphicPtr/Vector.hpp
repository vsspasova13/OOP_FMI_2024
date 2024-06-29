#pragma once
#include <iostream>

template<class T>
class Vector
{
	T* data;
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const Vector<T>& other);
	void moveFrom(Vector<T>&& other);
	void resize(size_t newCap);

public:
	Vector();
	Vector(const Vector<T>& other);
	Vector<T>& operator=(const Vector<T>& other);
	Vector(Vector<T>&& other)noexcept;
	Vector<T>& operator=(Vector<T>&& other)noexcept;

	void pushBack(T&& obj);
	void pushBack(const T& obj);

	void popBack();

	void insert(size_t index, const T& el);
	void insert(size_t index, T&& el);

	void erase(size_t index);

	void clear();

	const T& operator[](size_t index)const;
	T& operator[](size_t index);

	bool isEmpty()const;
	size_t getSize()const;

	~Vector();
};

template<class T>
void Vector<T>::free()
{
	delete[]data;
	data = nullptr;
}

template<class T>
void Vector<T>::copyFrom(const Vector<T>& other)
{
	data = new T[other.capacity];
	for (size_t i = 0; i < other.capacity; i++)
	{
		data[i] = other.data[i];
	}
	size = other.size;
	capacity = other.capacity;
}

template<class T>
void Vector<T>::moveFrom(Vector<T>&& other)
{
	data = other.data;
	size = other.size;
	capacity = other.capacity;

	other.data = nullptr;
	other.size = other.capacity = 0;
}

template<class T>
void Vector<T>::resize(size_t newCap)
{
	T* temp = new T[newCap];
	for (size_t i = 0; i < capacity; i++)
	{
		temp[i] = std::move(data[i]);
	}
	delete[] data;
	data = temp;
	capacity = newCap;
}

template<class T>
Vector<T>::Vector()
{
	siize = 0;
	capacity = 8;
	data = new T[capacity];
}

template<class T>
Vector<T>::Vector(const Vector<T>& other)
{
	copyFrom(other);
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template<class T>
Vector<T>::Vector(Vector<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<class T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<class T>
void Vector<T>::pushBack(T&& obj)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}
	data[size++] = std::move(obj);
}

template<class T>
void Vector<T>::pushBack(const T& obj)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}
	data[size++] = obj;
}

template<class T>
void Vector<T>::popBack()
{
	if (isEmpty())
		throw std::exception("Vector is empty");
	if (size * 4 == capacity)
		resize(capacity / 2;)
		size--;
}

template<class T>
void Vector<T>::insert(size_t index, const T& el)
{
	if (index >= size)
		throw std::out_of_range("Index is out of range");
	if (size == capacity)
	{
		resize(capacity * 2);
	}
	for (size_t i = size; i > index; i--)
	{
		data[i] = std::move(data[i - 1]);
	}
	data[index] = el;
	size++;

}

template<class T>
void Vector<T>::insert(size_t index, T&& el)
{
	if (index >= size)
		throw std::out_of_range("Index is out of range");
	if (size == capacity)
	{
		resize(capacity * 2);
	}
	for (size_t i = size; i > index; i--)
	{
		data[i] = std::move(data[i - 1]);
	}
	data[index] = std::move(el);
	size++;
}

template<class T>
void Vector<T>::erase(size_t index)
{
	if (index >= size)
		throw std::out_of_range("Index is out of range");

	if (size * 4 == capacity)
	{
		resize(capacity / 2);
	}

	size--;

	for (size_t i = index; i < size; i++)
	{
		data[i] = std::move(data[i + 1]);
	}
}

template<class T>
void Vector<T>::clear()
{
	free();
	size = 0;
	capacity = 8;
	data = new T[capacity];
}

template<class T>
const T& Vector<T>::operator[](size_t index) const
{
	if (index >= size)
		throw std::out_of_range("Index is out of range");
	return data[index];
}

template<class T>
T& Vector<T>::operator[](size_t index)
{
	if (index >= size)
		throw std::out_of_range("Index is out of range");
	return data[index];
}

template<class T>
bool Vector<T>::isEmpty() const
{
	return size == 0;
}

template<class T>
size_t Vector<T>::getSize() const
{
	return size;
}

template<class T>
Vector<T>::~Vector()
{
	free();
}
