#include <iostream>
#include <string>

class Student
{
    public:
    Student()=default;
    void print(void)
    {
        std::cout << *this << std::endl;    
    }
    
    private:
    std::string name{"NoName"};
    int age{18};
    
    private:
    friend std::ostream& operator<<(std::ostream& os, const Student& tempObj)
    {
    os << "\nName: " << tempObj.name << std::endl;
    os << "Age : " << tempObj.age << std::endl;
    
    return os;
    }
};