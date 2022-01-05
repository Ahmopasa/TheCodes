#include "Myclass.h"

Myclass& Myclass::operator=(const Myclass& tempObj)
{
    std::cout << "Overloaded operator= was called.\n";
    this->age = tempObj.age;
    this->name = tempObj.name;
    
    return *this;
}