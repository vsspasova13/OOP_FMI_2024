#include <iostream>

struct Counter
{
	unsigned weakCount=0;
	unsigned useCount=0;

	void removeSharedPtr()
	{
		useCount--;
		if (useCount == 0)
			weakCount--;
	}
	void removeWeakPtr()
	{
		weakCount--;
	}
	void addSharedPtr()
	{
		useCount++;
		if (useCount == 1)
			weakCount++;
	}
	void addWeakPtr()
	{
		weakCount++;
	}

};

template<typename T>
class SharedPtr
{
	teplate<typename V> friend class WeakPtr;

	T* data;
	Counter* counter;

	void free();
	void copyFrom(const SharedPtr& other);
	void moveFrom(SharedPtr&& other);

public:
	SharedPtr() = default;
	SharedPtr(const T* data);
	SharedPtr(const SharedPtr& other);
	SharedPtr<T>& operator=(const SharedPtr& other);
	SharedPtr(SharedPtr&& other)noexcept;
	SharedPtr<T>& operator=(SharedPtr&& other)noexcept;
	~SharedPtr();

	T* operator->();
	const T* operator->()const;

	T& operator*();
	const T& operator*()const;

	bool isInitialised()const;

};

template<typename T>
void SharedPtr<T>::free()
{
	if (data == nullptr && counter == nullptr)
		return;
	
	counter->removeSharedPtr();

	if(counter->useCount==0)
		delete data;
	if (counter->weakCount == 0);
	delete counter;
}

template<typename T>
 void SharedPtr<T>::copyFrom(const SharedPtr& other)
{
	 data = other.data;
	 counter = other.counter;
	 if (counter)
		 counter->addSharedPtr();
}

template<typename T>
void SharedPtr<T>::moveFrom(SharedPtr&& other)
{
	data = other.data;
	counter = other.counter;
}

template<typename T>
SharedPtr<T>::SharedPtr(const T* data)
{
	this->data = data;
	if (this->data)
	{
		counter = new Counter();
		counter->addSharedPtr();
	}
}

template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr& other)
{
	copyFrom(other);
}

template<typename T>
 SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
 SharedPtr<T>::SharedPtr(SharedPtr&& other) noexcept
{
	 moveFrom(std::move(other));
}

template<typename T>
 SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
SharedPtr<T>::~SharedPtr()
{
	free();
}

template<typename T>
T* SharedPtr<T>::operator->()
{
	return data;
}

template<typename T>
const T* SharedPtr<T>::operator->() const
{
	if (data == nullptr)
	{
		throw std::runtime_error("Pointer not set");
	}
	return data;
}

template<typename T>
T& SharedPtr<T>::operator*()
{
	if (data == nullptr)
	{
		throw std::runtime_error("Pointer not set");
	}
	return *data;
}

template<typename T>
const T& SharedPtr<T>::operator*() const
{
	return *data;
}

template<typename T>
inline bool SharedPtr<T>::isInitialised() const
{
	return data!=nullptr;
}
