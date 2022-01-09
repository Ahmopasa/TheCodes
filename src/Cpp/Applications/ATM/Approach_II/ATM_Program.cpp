#include "ATM_Program.h"

#include <vector>
#include <iostream>
#include <string>

ATM_Program* ATM_Program::s_pInstance = nullptr;

ATM_Program* ATM_Program::Instance(const int& userID)
{
	if (s_pInstance == nullptr)
	{
		std::cout << "A Brand New ATM_Program Will Be Allocated!" << std::endl;
		s_pInstance = new ATM_Program(userID);

		return s_pInstance;
	}
	
	return s_pInstance;
}

void ATM_Program::whoIs(void) const
{
	m_HandlerPtr->print(std::cout);
}

std::unique_ptr<AccountOwner>& ATM_Program::getHandlerPtr(void)
{
	return m_HandlerPtr;
}

bool ATM_Program::isRdy(void) const
{
	return m_isRdy;
}

void ATM_Program::processDeposit(const unsigned int& amount)
{
	unsigned int amountInAccount{ m_HandlerPtr->getBalance() };
	std::cout << "Total of [" << amountInAccount << "] will be deposited to your current account.\n";
	m_HandlerPtr->setBalance(amount + amountInAccount);
	std::cout << "Total of [" << amountInAccount << "] exists in your current account.\n";

	unsigned int amountInATM{ m_AtmHandlerPtr->getBalance() };
	m_AtmHandlerPtr->setBalance( amount + amountInATM);
	m_AtmHandlerPtr->saveInfo();
}

void ATM_Program::processWithdraw(const unsigned int& amount)
{
	unsigned int amountInAccount{ m_HandlerPtr->getBalance() };
	std::cout << "Total of [" << amountInAccount << "] will be withdrawn from your current account.\n";
	m_HandlerPtr->setBalance(amountInAccount - amount);
	std::cout << "Total of [" << amountInAccount << "] exists in your current account.\n";

	unsigned int amountInATM{ m_AtmHandlerPtr->getBalance() };
	m_AtmHandlerPtr->setBalance(amountInATM -  amount);
	m_AtmHandlerPtr->saveInfo();
}

ATM_Program::ATM_Program(const int& userID)
{
	std::ifstream fileHandler{};
	fileHandler.open(std::to_string(userID));
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

		if (std::stoi(tempStringVector.at(4)) == 0)
		{
			m_HandlerPtr = std::make_unique<NormalAccountOwner>();
			m_isRdy = true;
			m_HandlerPtr->readInfo();

		}
		else if (std::stoi(tempStringVector.at(4)) == 1)
		{
			m_HandlerPtr = std::make_unique<PremiumAccountOwner>();
			m_isRdy = true;
			m_HandlerPtr->readInfo();
		}
		else
		{
			std::cout << "Such VIP Status Was Found for " << userID << "\n. EXITING!."; std::exit(2);
		}

		m_AtmHandlerPtr = std::make_unique<ATM>();
		m_AtmHandlerPtr->readInfo();
	}
	else
	{
		std::cout << userID << " WAS NOT FOUND.\n";
		m_isRdy = false;
	}   
}
