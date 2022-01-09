#include "Toyota.h"
#include "ToyotaCorolla.h"

void driveTheCar(Car& theCar)
{
    std::cout << "\n************************************************************\n";
    theCar.initializeEngine();
    theCar.showEngineStatus();
    theCar.showWheelStatus();
    theCar.driveTheCar();
    theCar.rotateTheCar();
    theCar.stopEngine();
    std::cout << "\n************************************************************\n";
}

int main()
{
    

    
    Toyota myToyota{};
    driveTheCar(myToyota);

    ToyotaCorolla myCorolla{};
    driveTheCar(myCorolla);

}