#ifndef _TOYOTA_H_
#define _TOYOTA_H_

#include "Car.h"

class Toyota : public Car
{
public:
    Toyota(int radius = 18) : Car (radius)
    {
        std::cout << "[A TOYOTA OBJECT HAS BEEN CREATED.]\n";
    }

    bool virtual initializeEngine()
    {
        std::cout << "* The engine of Toyota has started.\n";

        return 1;
    }

    bool virtual driveTheCar()
    {
        std::cout << "* The engine of Toyota has been runing with 2000 RPM.\n";

        return 1;
    }

    bool virtual rotateTheCar()
    {
        std::cout << "* The Toyota car is turning right with 30 degree.\n";

        return 1;
    }

    bool virtual stopEngine()
    {
        std::cout << "* The engine of Toyota has just stopped.\n";

        return 1;
    }
};

#endif