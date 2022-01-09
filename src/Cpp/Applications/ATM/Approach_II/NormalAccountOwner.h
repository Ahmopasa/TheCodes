#ifndef __NORMAL_ACCOUNT_OWNER_H__
#define __NORMAL_ACCOUNT_OWNER_H__

#include "AccountOwner.h"

#include <fstream>
#include <vector>


class NormalAccountOwner final : public AccountOwner
{
public:
	// Constructors
	NormalAccountOwner(const std::string& tempName = "NoNameYet", const std::string& tempSurname = "NoSurnameYet", const std::string& tempAddress = "NoAddressYet", const unsigned int& tempBalance = 0, const unsigned int& tempPINCode = 0, const bool tempVipStatus = false)
    : AccountOwner{ tempName, tempSurname, tempAddress, tempBalance, tempPINCode, tempVipStatus }
    {}
	
    //Copy Constructor
    NormalAccountOwner(const NormalAccountOwner& other) : AccountOwner{other} {}

	//Deconstructor
	~NormalAccountOwner() {}

    //User Interface Functions
    void saveInfo(void) const override
    {
        try
        {
            std::ofstream fileHandler{};
            if(fileHandler.good())
            {
                fileHandler.open(std::to_string(this->getAccountPINCode()));
                fileHandler << this->getName() << "\n" << this->getSurname() << "\n" << this->getAddress() << "\n" << this->getBalance() << "\n" << this->getAccountVipStatus() << std::endl;
                fileHandler.close();
            }
            else
            {
                std::string tempErrorStatement = std::to_string(this->getAccountPINCode()) + " WAS NOT FOUND.\n";
                throw std::invalid_argument(tempErrorStatement);
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void readInfo(void) override
    {
        try
        {
            std::ifstream fileHandler{};
            fileHandler.open(std::to_string(this->getAccountPINCode()));
            if (fileHandler.good())
            {
                std::string tempString{};
                std::vector<std::string> tempStringVector{};
                while (fileHandler.good())
                {
                    std::getline(fileHandler, tempString);
                    tempStringVector.push_back(tempString);
                }
                fileHandler.close();

                this->setName(tempStringVector.at(0));
                this->setSurname(tempStringVector.at(1));
                this->setAddress(tempStringVector.at(2));
                this->setBalance(std::stoi(tempStringVector.at(3)));
                this->setAccountVipStatus(std::stoi(tempStringVector.at(4)));
            }
            else
            {
                std::string tempString = std::to_string(this->getAccountPINCode()) + " WAS NOT FOUND.\n";
                throw std::invalid_argument(tempString);
            }            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

    }
};
#endif // __NORMAL_ACCOUNT_OWNER_H__