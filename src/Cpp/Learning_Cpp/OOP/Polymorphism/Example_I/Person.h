#pragma once
#include <iostream>
#include <string>

class Person{
    public:
    /* Ctor and Dtor */
    // Default Ctor
    Person() = default;
    // Param. Ctor
    Person(int age, const std::string& name, const std::string& surname, const std::string& address){
        m_age = age;
        m_name = name;
        m_surname = surname;
        m_address = address;

        std::cout << "Person::Person() was called.\n";
    }

    // Overloaded << Opr.
    friend std::ostream& operator<<(std::ostream& os, const Person& obj){
        os << "# Information Table #\n";
        os << "Age     : " << obj.m_age << "\n";
        os << "Name    : " << obj.m_name << "\n";
        os << "Surname : " << obj.m_surname << "\n";
        os << "Address : " << obj.m_address << "\n";

        return os;
    }

    /* Getters and Setters */
    const unsigned int getAge() const
    {
        return m_age;
    }
    const std::string& getName() const
    {
        return m_name;
    }
    const std::string& getSurname() const
    {
        return m_surname;
    }
    const std::string& getAddress() const
    {
        return m_address;
    }

    private:
    unsigned int m_age{};
    std::string m_name{"noName"};
    std::string m_surname{"noSurname"};
    std::string m_address{"noAddress"};
};

