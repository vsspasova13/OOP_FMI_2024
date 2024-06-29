#include <iostream>
#include <fstream>

template<typename T, typename D>
class Pair
{
	T lhs;
	D rhs;

public:
	Pair() = default;
	Pair(const T& lhs, const D& rhs);

	const T& getLhs()const;
	const D& getRhs()const;

	void setLhs(const T& lh);
	void setRhs(const D& rh);


};

template<typename T, typename D>
 Pair<T, D>::Pair(const T& lhs, const D& rhs):lhs(lhs), rhs(rhs)
{
}

template<typename T, typename D>
const T& Pair<T, D>::getLhs() const
{
	return lhs;
}

template<typename T, typename D>
const D& Pair<T, D>::getRhs() const
{
	return rhs;
}

template<typename T, typename D>
void Pair<T, D>::setLhs(const T& lh)
{
	lhs = lh;
}

template<typename T, typename D>
void Pair<T, D>::setRhs(const D& rh)
{
	rhs = rh;
}

template<typename T, typename D>
std::ofstream& operator<<(std::ofstream& os, const Pair<T, D>& p)
{
	os << p.getLhs() << " " << p.getRhs() << std::endl;
	return os;
}
