#include "Singleton.h"

Singleton* Singleton::s_pInstance = 0;

Singleton* Singleton::Instance()
{
	if (s_pInstance == 0)
	{
		s_pInstance = new Singleton();

		return s_pInstance;
	}
	
	return s_pInstance;
}

int Singleton::getValue()
{
	return value;
}

void Singleton::setValue(int tempValue)
{
	value = tempValue;
}

Singleton::Singleton()
{
	value = 100;
}
