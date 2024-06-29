#include "Transformer.hpp"

TT
class ChangeAtTransformer :public Transformer<T,N>
{
private:
	T el;
	size_t index = 0;

public:
	ChangeAtTransformer(size_t ind, const T& el);
	Tuple<T, N>& transform(Tuple<T, N>& tuple)const override;
	Transformer<T, N>* clone()const override;
};

TT
ChangeAtTransformer<T, N>::ChangeAtTransformer(size_t ind, const T& el) :Transformer<T,N>(), index(ind), el(el) {};

TT
Tuple<T, N>& ChangeAtTransformer<T, N>::transform(Tuple<T, N>& tuple)const
{
	if (index >= tuple.getSize())
		return tuple;
	tuple[index] = el;
	return tuple;
}

TT
Transformer<T, N>* ChangeAtTransformer<T, N>::clone()const
{
	return new ChangeAtTransformer(*this);
}
