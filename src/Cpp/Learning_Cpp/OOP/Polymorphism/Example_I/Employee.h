#pragma once
#include "Person.h"

class Employee : public Person {
public:
    /* Ctor and Dtor */
    // Default Ctor
    Employee() = default;
    // Param. Ctor
    Employee(int age, const unsigned int ID, const unsigned int PW, const std::string& name, const std::string& surname, const std::string& address) 
            : Person(age, name, surname, address)
    {
        m_ID = ID;
        m_PW = PW;
        std::cout << "Employee::Employee() was called.\n";
    }

    // Overloaded << Opr.
    friend std::ostream& operator<<(std::ostream& os, const Employee& obj){
        os << "# Information Table #\n";
        os << "Age     : " << obj.getAge() << "\n";
        os << "ID      : " << obj.m_ID << "\n";
        os << "PW      : " << obj.m_PW << "\n";
        os << "Name    : " << obj.getName() << "\n";
        os << "Surname : " << obj.getSurname() << "\n";
        os << "Address : " << obj.getAddress() << "\n";

        return os;
    }

    /* Getters and Setters */
    unsigned int& getID()
    {
        return m_ID;
    }
    unsigned int& getPW()
    {
        return m_PW;
    }
private:
    unsigned int m_ID{};
    unsigned int m_PW{};
};