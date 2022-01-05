#ifndef __ATM_H__
#define __ATM_H__

#include <string>
#include <vector>
#include <fstream>

class ATM
{
public:
    // Getter & Setter Functions
	const unsigned int& getBalance(void) const { return ATMBalanceAmount; }
	void setBalance(const unsigned int& tempBalance) { this->ATMBalanceAmount = tempBalance; }

    //User Interface Functions
	void saveInfo(void) const
	{
        try
        {
            std::ofstream fileHandler{};
            fileHandler.open("ATM_BALANCE");
            if(fileHandler.is_open())
            {
                fileHandler << this->getBalance() << std::endl;
                fileHandler.close();
            }
            else
            {
                throw std::invalid_argument("ATM_BALANCE WAS NOT FOUND TO SAVE.\n");
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
	}
    void readInfo(void)
    {
        try
        {
            std::ifstream fileHandler{};
            fileHandler.open("ATM_BALANCE");
            if (fileHandler.is_open())
            {
                std::string tempString{};
                std::vector<std::string> tempStringVector;
                while(fileHandler.good())
                {
                    std::getline(fileHandler, tempString);
                    tempStringVector.push_back(tempString);
                }
                fileHandler.close();

                this->ATMBalanceAmount = std::stoi(tempStringVector.at(0));
            }
            else
            {
                throw std::invalid_argument("ATM_BALANCE WAS NOT FOUND TO READ FROM.\n");
            }            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

private:
	unsigned int ATMBalanceAmount{};
};

#endif // __ATM_H__