#ifndef _WHEEL_H_
#define _WHEEL_H_

#include <iostream>

class Wheel{
    public:
    Wheel() 
    {
        std::cout << "[WHEEL OBJECTS HAS BEEN CREATED.]\n";
    }
    
    void setRadius(int value)
    {
        m_radius = value;
    }

    void setId(int value)
    {
        m_Id = value;
    }

    friend std::ostream& operator<<(std::ostream& os, const Wheel& wheel)
    {
        return os << "* [ID/Radius] : " << "[" << wheel.m_Id << "/" << wheel.m_radius << "]\n";
    }

    private:
    int m_radius{}; 
    int m_Id{0};
};

#endif