#include <iostream>
#include <string>

class Myclass
{
    public:
    Myclass()=default;
    Myclass(int age, std::string name = "NoName") : age{age}, name{name}
    {
        std::cout << "Parameterized Ctor was called.\n";
    }

    void print(void)
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age : " << age << std::endl;
    }
    Myclass& operator=(const Myclass& tempObj);
    
    private:
    int age{18};
    std::string name{"NoName"};
};