#ifndef __I_PRINT_H__
#define __I_PRINT_H__

#include <iostream>

class I_Print
{
public:
    virtual void print(std::ostream& os) const = 0;

private:
    friend std::ostream& operator<<(std::ostream& os, const I_Print& object);
};

#endif // __I_PRINT_H__