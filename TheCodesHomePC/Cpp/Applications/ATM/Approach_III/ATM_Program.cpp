#include "ATM_Program.h"

#include <limits>
#include <type_traits>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <stdio.h>

// Static Functions --------------------------------
static std::unique_ptr<AccountOwner> CreateAccount(void){ return nullptr; } // TODO #5 : Implementation of CreateAccount method will be done in the future.
 

static void IgnoreBuffer(void)
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Template functions --------------------------------
template<typename T>
void CheckNumericEntry(T& tempPinCode)
{
	try
	{
		if (std::is_same<T, unsigned int>::value)
		{
			std::cout << "NUMERIC INPUT : ";
			while (true)
			{
				std::cin >> tempPinCode;
				std::cin.clear();
				IgnoreBuffer();
				if (std::cin.fail() || tempPinCode < 1)
				{
					std::cout << "Please enter a number mentioned above : ";
					continue;
				}				
				else
				{
					break;
				}
			}
		}
		else if (std::is_same<T,char>::value)
		{
			std::cout << "T == char" << std::endl;

		}
		else if (std::is_same<T,std::string>::value)
		{
			std::cout << "T == std::string" << std::endl;

		}
		else if (std::is_same<T,const char*>::value)
		{
			std::cout << "T == const char*" << std::endl;
		}
		else
		{
			throw std::invalid_argument("OUT OF SCOPE");
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}

// Public Member Functions Definitions --------------------------------
void ATMProgram::UserScreen(void)
{
	// TODO #3 : Inıtialize ATM to see its currency amount.
	std::cout << "<<< WELCOME TO X-BANK >>>\n";
	std::cout << "Here, you can do following operations;\n";
	std::cout << "[1]- Create An Account\n";
	std::cout << "[2]- Deposit Currency\n";
	std::cout << "[3]- Withdraw Currency From Your Account\n";
	std::cout << "[4]- Show Details Of Your Account\n";
	std::cout << "[5]- Change Details Of Your Account\n";
	std::cout << "\nBefore proceed further,\n";
	std::cout << "Either enter your PIN number, or 17091993.\n";

	while (true)
	{
		unsigned int tempPinCode{};
		CheckNumericEntry(tempPinCode);

		try
		{	
			if (tempPinCode == 17091993)
			{
				/* code */
			}
			else if (tempPinCode != 17091993)
			{
				while (true)
				{
					system("clear");
					std::unique_ptr<AccountOwner> account = FindAccount(tempPinCode);
					std::cout << "Welcome Back Dear " << account->getName() << std::endl;
					account = CheckAccountInfo(std::move(account));
					DepositCurrency(std::move(account));
					break;
				}
			}
			else
			{
				throw std::invalid_argument("TOO BIG PIN CODE TO HANDLE");
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}		
		break;
	}
}

// Private Member Function Definitions --------------------------------
std::unique_ptr<AccountOwner> ATMProgram::DepositCurrency(std::unique_ptr<AccountOwner> tempAccountOwnerPtr)
{
	std::cout << "Would You Like to Deposit to Your Account or Other's Account?\n";
	std::cout << "[1]- To My Account\n"; 
	std::cout << "[2]- To Other's Account\n"; 

	while (true)
	{
	unsigned int tempUserChoice{};
	CheckNumericEntry(tempUserChoice);
		try
		{
			if(tempUserChoice == 1)	
			{
				std::cout << "How Much Would You Like to Deposit to Your Account? => ";
				unsigned int tempDepositAmount{};
				CheckNumericEntry(tempDepositAmount);
				tempAccountOwnerPtr->setBalance(tempAccountOwnerPtr->getBalance() + tempDepositAmount);
				std::cout << "Total of [" << tempAccountOwnerPtr->getBalance() << "] Amount has been added to your account Dear " << tempAccountOwnerPtr->getName() << std::endl;
				std::cout << "Total Acount Balance : " << tempAccountOwnerPtr->getBalance() << std::endl;
				SaveAccountInfo(std::move(tempAccountOwnerPtr));
				// TODO #2 : New ATM Balance Will Be Saved.
				break;
			}
			else if(tempUserChoice == 2)
			{
				std::cout << "What Is The ID of the Account You Wish To Deposit To => ";
				break;
			}
			else
			{
				throw std::invalid_argument("PLEASE, CHOOSE [1] / [2] TO PROCEED.");
				continue;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return std::move(tempAccountOwnerPtr);
}

// std::unique_ptr<AccountOwner> WithdrawCurrency(std::unique_ptr<AccountOwner> tempAccountOwnerPtr) {}

// std::unique_ptr<AccountOwner> ChangeAccountInfo(std::unique_ptr<AccountOwner> tempAccountOwnerPtr) {}

void ATMProgram::SaveAccountInfo(std::unique_ptr<AccountOwner> tempAccountOwnerPtr)
{

	std::ofstream fileHandler{};
	try
	{
		if(fileHandler.good())
		{
			fileHandler.open(std::to_string(tempAccountOwnerPtr->getAccountPINCode()));
			fileHandler << tempAccountOwnerPtr->getName() << "\n" << tempAccountOwnerPtr->getSurname() << "\n" << tempAccountOwnerPtr->getAddress() << "\n" << tempAccountOwnerPtr->getBalance() << std::endl;
			fileHandler.close();
		}
		else
		{
			std::string tempErrorStatement = std::to_string(tempAccountOwnerPtr->getAccountPINCode()) + " was not found.\n";
			throw std::invalid_argument(tempErrorStatement);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

std::unique_ptr<AccountOwner> ATMProgram::CheckAccountInfo(std::unique_ptr<AccountOwner> tempAccountOwnerPtr)
{
	std::cout << *tempAccountOwnerPtr << std::endl;

	return std::move(tempAccountOwnerPtr);
}

std::unique_ptr<AccountOwner> ATMProgram::FindAccount(unsigned int tempPinCode)
{
	std::cout << "Finding An Account for " << tempPinCode << std::endl;
	std::ifstream fileHandler{};
	fileHandler.open(std::to_string(tempPinCode));
	if(fileHandler.good())
	{
		std::cout << "Found An Account for " << tempPinCode << std::endl;

		std::string tempString{};
		std::vector<std::string> tempStringVector;
		while (fileHandler.good())
		{
			std::getline(fileHandler, tempString);
			tempStringVector.push_back(tempString);
		}
		fileHandler.close();

		int tempBalance = std::stoi(tempStringVector.at(3));
		try
		{
			if (tempBalance >= 0 && tempBalance < 1'000'000)
			{
				host = std::make_unique<PremiumAccountOwner>( tempStringVector.at(0), tempStringVector.at(1), tempStringVector.at(2), static_cast<unsigned int>(tempBalance), tempPinCode );
			}
			else if (tempBalance >= 1'000'000)
			{
				host = std::make_unique<PremiumAccountOwner>( tempStringVector.at(0), tempStringVector.at(1), tempStringVector.at(2), static_cast<unsigned int>(tempBalance), tempPinCode );
			}
			else
			{
				throw std::invalid_argument("INVALID BALANCE AMOUNT");
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		return std::move(host);
	}
	else
	{
		std::cout << "Pin Code => " << tempPinCode << " could not be found.\n";
		std::cout << "Please, make sure that your have entered your pin code correctly.\n"; 
		while (true)
		{
			std::cout << "[1] - To Enter Once Again\n";
			std::cout << "[2] - Create A New Account\n";
			std::cout << "[3] - Exit\n";
			while (true)
			{
				unsigned int tempChoice{};
				CheckNumericEntry(tempChoice);
				switch (tempChoice)
				{
					case 1:
					{
						system("clear");
						std::cout << "Enter your Pin Code once again.\n" << "Your Old PIN Code was : " << tempPinCode << "\n";
						CheckNumericEntry(tempPinCode);
						FindAccount(tempPinCode);
						break;
					}
					case 2:
					{
						host = CreateAccount(); break;
					}
					case 3:
					{
						system("clear");
						std::cout << "Exiting from the program. Do not forget to pick your credit card.\n" << std::endl; 
						break;
					}
					default:
					{
						continue;
					}
				}	
				break;			
			}
			break;
		}

		return std::move(host);
	}
}



