#include "Tuple.hpp"
TT 
class Transformer
{
public:
	Transformer() = default;

	virtual Tuple<T, N>& transform(Tuple<T, N>& tuple)const = 0;
	virtual Transformer<T, N>* clone() const= 0;
	virtual ~Transformer()noexcept = default;

};