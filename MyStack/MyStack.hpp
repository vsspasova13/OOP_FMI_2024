#include <iostream>

template <typename T, const unsigned N>
class MyStack
{
private:
	T arr[N];
	size_t size = 0;

public:
	void push(const T& obj);
	void push(T&& obj);

	const T& peek()const;
	void pop();

	bool isEmpty()const;
	bool isFull()const;

};

template<typename T, const unsigned N>
void MyStack<T, N>::push(const T& obj)
{
	if (size >= N)
		return;
	arr[size++] = obj;
}

template<typename T, const unsigned N>
void MyStack<T, N>::push(T&& obj)
{
	if (size >= N)
		return;
	arr[size++] = std::move(obj);
}

template<typename T, const unsigned N>
const T& MyStack<T, N>::peek()const
{
	if (isEmpty())
		throw std::out_of_range("Error, stack is empty");

	return arr[size-1];
}

template<typename T, const unsigned N>
void MyStack<T, N>::pop()
{
	if (isEmpty())
		throw std::out_of_range("Error, stack is empty");
	size--;
}

template<typename T, const unsigned N>
bool MyStack<T,N>::isEmpty()const
{
	return size ==0;
}

template<typename T, const unsigned N>
bool MyStack<T, N>::isFull()const
{
	return size == N;
}