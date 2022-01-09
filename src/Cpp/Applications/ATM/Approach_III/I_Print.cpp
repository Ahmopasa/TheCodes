#include "I_Print.h"

std::ostream& operator<<(std::ostream& os, const I_Print& object)
{
    object.print(os);

    return os;
}

void printClassInfo(const I_Print& object)
{
    std::cout << object << std::endl;
}