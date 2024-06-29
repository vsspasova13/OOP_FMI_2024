#include <iostream>
#include <exception>

template<typename T>
class MyQueue
{
	T* data;
	size_t capacity;
	size_t size;

	size_t get;
	size_t put;

	void resize();
	void moveFrom(MyQueue<T>&& other);
	void copyFrom(const MyQueue& other);
	void free();

public:
	MyQueue();
	MyQueue(const MyQueue<T>& other);
	MyQueue(MyQueue<T>&& other)noexcept;
	MyQueue<T>& operator=(const MyQueue<T>& other);
	MyQueue<T>& operator=(MyQueue<T>&& other)noexcept;
	~MyQueue();

	void push(const T& obj);
	void push(T&& obj);
	void pop();

	const T& peek()const;
	bool isEmpty()const;
};

template<typename T>
void MyQueue<T>::resize()
{
	T* temp = new T[capacity * 2];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = data[i];
	}
	delete[]data;
	data = temp;
	capacity *= 2;
	get = 0;
	put = size;

}

template<typename T>
void MyQueue<T>::moveFrom(MyQueue<T>&& other)
{
	data = other.data;
	size = other.size;
	capacity = other.capacity;

	other.size = other.capacity = 0;
	other.data = nullptr;

	get = other.get;
	put = other.put;
}

template<typename T>
void MyQueue<T>::copyFrom(const MyQueue& other)
{
	data new T[other.capacity];
	for (size_t i = 0; i < other.capacity; i++)
	{
		data[i] = other.data[i];
	}
	size = other.size;
	capacity = other.capacity;
	get = other.get;
	put = other.put;
}

template<typename T>
void MyQueue<T>::free()
{
	delete[]data;
	data = nullptr;
}

template<typename T>
MyQueue<T>::MyQueue()
{
	size = 0;
	capacity = 4;
	data = new T[capacity];
	get = put = 0;
}

template<typename T>
MyQueue<T>::MyQueue(const MyQueue<T>& other)
{
	copyFrom(other);
}

template<typename T>
MyQueue<T>::MyQueue(MyQueue<T>&& other)
{
	moveFrom(std::move(other));
}

template<typename T>
MyQueue<T>& MyQueue<T>::operator=(const MyQueue<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
MyQueue<T>& MyQueue<T>::operator=(MyQueue<T>&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
MyQueue<T>::~MyQueue()
{
	free();
}

template<typename T>
void MyQueue<T>::push(const T& obj)
{
	if (put == size)
	{
		resize();
	}
	data[put] = obj;
	(++put) %= capacity;
	size++;
}

template<typename T>
void MyQueue<T>::push(T&& obj)
{
	if (put == size)
	{
		resize();
	}
	data[put] = obj;
	(++put) %= capacity;
	size++;
}

template<typename T>
void MyQueue<T>::pop()
{
	if (isEmpty())
		throw std::exception("Queue is empty");
	size--;
	(++get) %= capacity;
}

template<typename T>
const T& MyQueue<T>::peek() const
{
	if (isEmpty())
		throw std::exception("Queue is empty");
	return data[get];
}

template<typename T>
inline bool MyQueue<T>::isEmpty() const
{
	return size==0;
}
