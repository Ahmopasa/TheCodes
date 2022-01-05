#include "ATM_Program.h"
#include <algorithm>

/* # TODO LIST #
   - switch-cases where userChoice was used, should be modified to prevent unwanted entries.
   - Deposit / Withdraw functions should be included to the runner function.
*/


static bool isValid(const std::string& input)
{
	return std::find_if(input.begin(), input.end(), [](unsigned char c)
	{
		return std::isalpha(c);
	}) == input.end();
}

static bool isValid(const int& input)
{
	return !std::isdigit(input);
}

static void IgnoreBuffer(void)
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
	int remainingTry{3};
	while (remainingTry > 0)
	{
		std::cout << "Welcome!" << std::endl;
		std::cout << "Please, enter an ID to proceed : ";
		std::string userID{};
		std::cin >> userID;
		if (isValid(userID))
		{
			ATM_Program* pInstance = ATM_Program::Instance(std::stoi(userID));
			if (!pInstance->isRdy())
			{
				CLEAR
				std::cout << "Such account for the PIN Code [" << userID << "] could not be found/opened.\n";
				std::cout << "What would you like to?\n";
				std::cout << "1- Try Again[" << --remainingTry << "].\n";
				std::cout << "2- Exit.\n";
				std::cout << "Choice: ";
				int userChoice{};
				std::cin >> userChoice;
				if (isValid(userChoice))
				{
					std::cout << "Chosen Action: " << userChoice << std::endl;
					switch (userChoice)
					{
						case 1:
						{
							CLEAR
							if (remainingTry == 0)
							{
								std::cout << "You do not have any right left, to try again. Exiting...\n"; std::exit(3);
							}
							continue;	
						}
						case 2:
						{
							std::cout << "Exiting from the program by request...\n" << std::endl; std::exit(4);	
						}
						default:
						{
							std::exit(2);
						}
					}
				}
			}
			else
			{
				CLEAR
				std::cout << "Hello, " << pInstance->getHandlerPtr()->getName() << "  " << pInstance->getHandlerPtr()->getSurname() << std::endl;
				std::cout << "You can do following transactions:" << std::endl;
				std::cout << "1- Withdraw    : " << std::endl;
				std::cout << "2- Deposit     : " << std::endl;
				std::cout << "3- Show Info   : " << std::endl;
				std::cout << "4- Chance Info : " << std::endl;
				std::cout << "5- Exit        : " << std::endl;
				std::cout << "Choice: ";
				int userChoice{};
				std::cin >> userChoice;
				if (isValid(userChoice))
				{
					std::cout << "Chosen Action: " << userChoice << std::endl;
					switch (userChoice)
					{
						case 1:
						{
							std::cout << "How much currency you want to withdraw?" << std::endl;
							unsigned int amount{};
							std::cin >> amount;
							if (isValid(amount))
							{
								pInstance->processWithdraw(amount); break;
							}								
						}
						case 2:
						{
							std::cout << "How much currency you want to deposit?" << std::endl;
							unsigned int amount{};
							std::cin >> amount;
							if (isValid(amount))
							{
								pInstance->processDeposit(amount); break;	
							}							
						}
						case 3:
						{
							pInstance->whoIs(); break;
						}
						case 4:
						{
							std::cout << "Details of your account will be changed in a minute..." << std::endl; break;	
						}
						case 5:
						{
							break;
						}
						default:
						{
							std::exit(2);
						}
					}
				}
			}
		}
		else
		{
			CLEAR
			if (remainingTry == 1)
			{
				std::cout << "You do not have any right left, to try again. Exiting...\n"; std::exit(3);
			}
			
			std::cout << "The entered ID [" << userID << "] is not a valid, contains alphabetical characters. Try Again...\n";
			std::cout << "You have [" << --remainingTry << "] remaining right.\n";
			IgnoreBuffer();
		}

		break;
	}
	
	return 0;
}




