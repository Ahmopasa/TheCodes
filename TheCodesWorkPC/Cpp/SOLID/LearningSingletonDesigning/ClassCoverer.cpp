#include "ClassCoverer.h"
#include "Singleton.h"

#include <iostream>

void ClassCoverer::Init(void)
{
	Singleton* pInstanceOne = Singleton::Instance();
	std::cout << "Value pointed by pInstanceOne: " << pInstanceOne->getValue() << std::endl;

	pInstanceOne->setValue(200);

	std::cout << "Value pointed by pInstanceOne: " << pInstanceOne->getValue() << std::endl;

	Singleton* pInstanceTwo = Singleton::Instance();
	std::cout << "Value pointed by pInstanceTwo: " << pInstanceTwo->getValue() << std::endl;

	pInstanceTwo->setValue(300);
	std::cout << "Value pointed by pInstanceTwo: " << pInstanceTwo->getValue() << std::endl;
}
