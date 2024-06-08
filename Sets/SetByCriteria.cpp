#include "SetByCriteria.h"

void SetByCriteria::fillSet(bool (*incl)(unsigned n))
{
	for (int i = 0; i < getN(); i++)
	{
		if (incl(i))
			add(i);
		else remove(i);
	}
}

SetByCriteria::SetByCriteria(unsigned n, bool (*incl)(unsigned n)):DynamicSet(n)
{
	fillSet(incl);
}

void SetByCriteria::setInclude(bool (*incl)(unsigned n))
{
	fillSet(incl);
}