#include "Person.h"
#include "Employee.h"
#include <memory>


int main()
{
    std::cout << "/****************************/\n";
    Person mainPerson{};
    std::cout << mainPerson << "\n";
    std::cout << "/****************************/\n";
    Employee mainEmployee{};
    std::cout << mainEmployee << "\n";
    std::cout << "/****************************/\n";
}