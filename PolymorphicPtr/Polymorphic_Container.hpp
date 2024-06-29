#include "Polymorphic_Ptr.hpp"
#include "Vector.hpp"

template<typename T>
class Polymorphic_Container
{
	Vector<Polymorphic_Ptr<T>> data;

public:
	void add(T* el);
	Polymorphic_Ptr<T>& operator[](size_t index);
	const Polymorphic_Ptr<T>& operator[](size_t index)const;

	void execute(size_t index, void (*funct)(T* el));
	void execute(size_t index, void (*funct)(const T* el))const;

};

template<typename T>
void Polymorphic_Container<T>::add(T* el)
{
	data.pushBack(el);
}

template<typename T>
Polymorphic_Ptr<T>& Polymorphic_Container<T>::operator[](size_t index)
{
	return data[index];
}

template<typename T>
const Polymorphic_Ptr<T>& Polymorphic_Container<T>::operator[](size_t index) const
{
	return data[index];
}

template<typename T>
void Polymorphic_Container<T>::execute(size_t index, void(*funct)(T* el))
{
	funct(data[index].get());
}

template<typename T>
void Polymorphic_Container<T>::execute(size_t index, void(*funct)(const T* el)) const
{
	funct(data[index].get());
}
