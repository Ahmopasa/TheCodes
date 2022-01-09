#ifndef _TOYOTA_COROLLA_H_
#define _TOYOTA_COROLLA_H_

#include "Toyota.h"

class ToyotaCorolla : public Toyota
{
public:
    ToyotaCorolla(int radius = 21) : Toyota(radius) 
    {
        std::cout << "[A TOYOTA COROLLA OBJECT HAS BEEN CREATED.]\n";
    }

    bool virtual initializeEngine()
    {
        std::cout << "* The engine of Toyota Corolla has started.\n";

        return 2;
    }

    bool virtual driveTheCar()
    {
        std::cout << "* The engine of Toyota Corolla has been runing with 3000 RPM.\n";

        return 2;
    }

    bool virtual rotateTheCar()
    {
        std::cout << "* The Toyota Corolla car is turning right with 45 degree.\n";

        return 2;
    }

    bool virtual stopEngine()
    {
        std::cout << "* The engine of Toyota Corolla has just stopped.\n";

        return 2;
    }

    void openSunroof()
    {
        std::cout << "* The sunroof of Toyota Corolla has been opened.\n";
    }

};

#endif