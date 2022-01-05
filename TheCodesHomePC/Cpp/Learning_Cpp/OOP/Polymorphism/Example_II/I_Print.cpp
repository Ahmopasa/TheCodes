#include "I_Print.h"

std::ostream& operator<< (std::ostream& os, const I_Print& obj)
{
    DEBUG_MESSAGES_OPERATOR_OVERLOADING
    obj.print(os);

    return os;
}
