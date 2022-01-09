#ifndef _CAR_H_
#define _CAR_H_

#include "Wheel.h"
#include "Engine.h"

#include <vector>
#include <iostream>
#include <memory>

class Car{
    public:
    Car(int radius)
    {
        std::cout << "[A CAR OBJECT HAS BEEN CREATED.]\n";

        for (size_t i = 0; i < wheels.size(); i++)
        {
            wheels.at(i).setId(i);
            wheels.at(i).setRadius(radius);
        }
    }

    bool virtual initializeEngine() = 0;
    bool virtual driveTheCar() = 0;
    bool virtual rotateTheCar() = 0;
    bool virtual stopEngine() = 0;

    void showEngineStatus()
    {
        std::cout << *engine;
    }

    void showWheelStatus()
    {
        for (auto& singleWheel : wheels)
        {
            std::cout << singleWheel;
        } 
    }

    private:
    std::unique_ptr<Engine> engine{ std::make_unique<Engine>() };
    std::vector<Wheel> wheels{ 4 };
};
#endif 