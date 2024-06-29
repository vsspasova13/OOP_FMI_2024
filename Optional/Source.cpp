#include <iostream>
#include "Optional.hpp"

int main()
{
	Optional<int> d; 

	d.setData(3);
	std::cout << d.getData() << std::endl;
	d.clear();

	std::cout << d.containsData() << std::endl;

}