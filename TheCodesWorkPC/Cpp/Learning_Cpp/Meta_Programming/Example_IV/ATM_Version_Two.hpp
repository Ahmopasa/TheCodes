#ifndef ATM_VERSION_TWO_HPP
#define ATM_VERSION_TWO_HPP

#include <iostream>
#include <string>
#include <memory>
#include <type_traits>

namespace versionTwo{

    class ATM
    {
    private:
        std::string m_identifier{"AhmetKandemirPehlivanli"};
        int m_CashAmount{100000};
    public:
        void showMembers(void)
        {
            std::cout << "Identifier => " << m_identifier << std::endl; 
            std::cout << "CashAmount => " << m_CashAmount << std::endl;
        }
        void setIdentifier(const std::string& tempIdentifier)
        {
            this->m_identifier = tempIdentifier;
        }
        void setIntValue(const int& cashAmount)
        {
            this->m_CashAmount = cashAmount;
        }
        std::string& getIdentifier(void)
        {
            return this->m_identifier;
        }
        int& getCashAmount(void)
        {
            return this->m_CashAmount;
        }
    };

    class ATM_Program
    {
    private:
        int m_totalATMAmount{};
        ATM m_ATMMachine{};
    public:
        void showMembers(void)
        {
            std::cout << "Total ATM Amount => " << m_totalATMAmount << std::endl;
            std::cout << "ATM Identifier;" << std::endl;
            m_ATMMachine.showMembers();        
        }
        void setIdentifier(const ATM& tempATMObj)
        {
            this->m_ATMMachine = tempATMObj;
        }
        void setIntValue(const int& tempATMAmount)
        {
            this->m_totalATMAmount = tempATMAmount;
        }
        ATM& getIdentifier(void)
        {
            return this->m_ATMMachine;
        }
        int& getCashAmount(void)
        {
            return this->m_totalATMAmount;
        }
    };

    template<class T>
    void showMembers(T& tempClassRef)
    {
        tempClassRef.showMembers();
    }

    template<class T>
    void changeIntValues(T& tempClassRef)
    {
        if(std::is_same<T, ATM>::value)
        {
            tempClassRef.setIntValue(2'000'000);
        }
        else if(std::is_same<T, ATM_Program>::value)    
        {
            tempClassRef.setIntValue(5);
        }
        else
        {
            std::cout << "THE TYPE IS NOT SUPPORTED, YET" << std::endl;
        }
    }
}

#endif