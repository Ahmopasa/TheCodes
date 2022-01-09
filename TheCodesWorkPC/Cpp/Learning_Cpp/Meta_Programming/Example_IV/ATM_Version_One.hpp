#ifndef ATM_VERSION_ONE_HPP
#define ATM_VERSION_ONE_HPP

#include <iostream>
#include <string>
#include <memory>
#include <type_traits>

namespace versionOne{

    class ATM
    {
    private:
        int m_age{18};
        double m_score{0};
        std::string m_identifier{"NoName"};
    public:
        inline void showMembers(void) const
        {
            std::cout << "Identify => " << m_identifier << std::endl;
            std::cout << "Score    => " << m_score << std::endl;
            std::cout << "Age      => " << m_age << std::endl;
        }
    };

    class ATM_Program
    {
    private:
        int m_totalATMAmount{1};
        ATM m_ATMMachine{};
    public:
        inline void showMembers(void) const
        {
            std::cout << "Total ATM => " << m_totalATMAmount << std::endl;
            std::cout << "An ATM consists of following members;" << std::endl;
            m_ATMMachine.showMembers();
        }
    };

    template<class T>
    void showTemplateFunction(const T& tempClassRef)
    {
        tempClassRef.showMembers();
    }

    template<class T>
    void showMetaFunction(const T& tempClassRef)
    {
        if (std::is_same<T, ATM>::value)
        {
            std::cout << "Type is of ATM" << std::endl; 
            tempClassRef.showMembers();
        }
        else if (std::is_same<T,ATM_Program>::value)
        {
            std::cout << "Type is of ATM_Program" << std::endl; 
            tempClassRef.showMembers();
        }
        else    
            std::cout << "Type is not SUPPORTED, YET." << std::endl;
    }

    template<class T>
    void showTemplateFunction(const std::unique_ptr<T> tempClass)
    {
        tempClass->showMembers();
    }

    template<class T>
    void showMetaFunction(const std::unique_ptr<T> tempClass)
    {
        if (std::is_same<T, ATM>::value)
        {
            std::cout << "Type is of ATM" << std::endl;
            tempClass->showMembers();
        }
        else if (std::is_same<T,ATM_Program>::value)
        {
            std::cout << "Type is of ATM_Program" << std::endl; 
            tempClass->showMembers();
        }
        else    
            std::cout << "Type is not SUPPORTED, YET." << std::endl;
    }
}

#endif