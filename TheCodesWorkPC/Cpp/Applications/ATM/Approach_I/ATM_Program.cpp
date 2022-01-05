//===================== # HEADER FILES # =====================
#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include <algorithm>
#include <array>
#include <stdlib.h>  
#include <time.h>   
#include <chrono>
#include <thread>
#include <random>
#include "ATM_Program.h"

//===================== # STATIC VARIABLES # =====================
static std::mt19937 myRandom{ std::random_device{}() };
static std::uniform_int_distribution<> list{ 0, 80 };
static const char* PinCodeListPath = "D://Projects//Programming//C_And_Cpp//Cpp//ATM_With_Cpp_I//Accounts//PIN_CODE_LIST";

//===================== # STATIC FUNCTIONS # =====================
static void sleep(void)
{
	std::this_thread::sleep_for(std::chrono::seconds(3));
}

static void IgnoreBuffer(void)
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static std::unique_ptr<ATM> ReadAtmInfo(void)
{
	std::ifstream fileHandler{};
	fileHandler.open("D://Projects//Programming//C_And_Cpp//Cpp//ATM_With_Cpp_I//ATM//ATM_BALANCE");
	if (fileHandler.good())
	{
		std::string tempString;
		std::vector<std::string> tempStringVector;
		while (fileHandler.good())
		{
			std::getline(fileHandler, tempString);
			tempStringVector.push_back(tempString);
		}
		fileHandler.close();

		std::unique_ptr<ATM> host = std::make_unique<ATM>();
		host->setATMBalanceAmount(static_cast<unsigned int>(std::stoi(tempStringVector[0])));

		return host;
	}
	else
	{
		std::cout << "ATM_BALANCE could not be found. Program is exiting.\n"; 
		sleep();
		exit(EXIT_FAILURE);
	}
}

static std::unique_ptr<ATM> SaveAtmInfo(std::unique_ptr<ATM> host)
{
	std::ofstream fileHandler{};
	if (fileHandler.good())
	{
		fileHandler.open("D://Projects//Programming//C_And_Cpp//Cpp//ATM_With_Cpp_I//ATM//ATM_BALANCE");
		fileHandler << host->getATMBalanceAmount() << "\n";
		fileHandler.close();

		return host;
	}
	else
	{
		std::cout << "ATM_BALANCE could not be found. Program is exiting.\n"; 
		sleep();
		exit(EXIT_FAILURE);
	}
}

static std::string getName()
{
	static std::array<std::string, 80> nameList
	{
		"AHMET", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ELIZABETH", "AHMET", "ELLEN", "ELLEN", "ELLEN", "EPIPHANY", "EPPIE", "ETTA", "EULA", "FOREST", "FORD", "FOSTER", "FOX",
		"FOREST", "FORD", "FOSTER", "FOX", "EPIPHANY", "EPPIE", "ETTA", "EULA", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "EULA",
		"AHMET", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ELIZABETH", "AHMET", "ELLEN", "ELLEN", "ELLEN", "EPIPHANY", "EPPIE", "ETTA", "EULA", "FOREST", "FORD", "FOSTER", "FOX",
		"FOREST", "FORD", "FOSTER", "FOX", "EPIPHANY", "EPPIE", "ETTA", "EULA", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "EULA",
	};

	
	return nameList.at( static_cast<size_t>(list(myRandom)) );
}

static std::string getSurname()
{
	static std::array<std::string, 80> surnameList
	{
		"JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON",
		"JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON",	"GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ"	,  "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA",
		"JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON",
		"WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON", "JOHNSON", "ABBESTEGE", "WILSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS",
		"WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON", "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE",
	};

	return surnameList.at( static_cast<size_t>(list(myRandom)) );
} 

static std::string getAddress()
{
	static std::array<std::string, 80> addressList
	{
		"Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Colorado",
		"Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Louisiana", "Maine", "Maryland", "Massachusetts",
		"Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware",
		"Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Louisiana", "Maine", "Maryland", "Massachusetts", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware",
		"Florida", "Georgia", "Hawaii", "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida"
	};

	return addressList.at( static_cast<size_t>(list(myRandom)) );
} 

class ValidateInput
{
public:
	void operator()(unsigned int& input)
	{
		while (true)
		{
			std::cout << "Numeric Input: ";
			std::cin >> input;
			if (std::cin.fail() || input < 1)
			{
				std::cin.clear();
				IgnoreBuffer();
				continue;
			}
			break;
		}
	}

	void operator()(std::string& input)
	{
		while (true)
		{
			std::cout << "String Input: ";
			std::cin >> input;
			std::cin.clear();
			IgnoreBuffer();

			if (!std::cin.fail() && std::find_if(input.begin(), input.end(), [](char c) { return !std::isalpha(c); }) == input.end())
			{
				break;
			}
			else
			{
				continue;
			}
		}
	}
};

//===================== # FUNCTION DEFINITIONS # =================
std::unique_ptr<AccountOwner> CreateAccount(void)
{
	CLEAR
	std::cout << "INSIDE OF std::unique_ptr<AccountOwner> CreateAccount(void)\n";
	while (true)
	{
		std::cout << "How would you like to create an account for the customer?\n";
		std::cout << "With random values     :  2\n";
		std::cout << "With specific values   :  3\n";
		std::cout << "Back To The Main Menu  :  4\n";

		bool customerAccountVipStatus;
		unsigned int customerAccountBalance{};
		unsigned int customerAccountPINCode{};
		std::string customerName{};
		std::string customerSurame{};
		std::string customerAddress{};
		
		unsigned int choice_CreateAccount{};
		ValidateInput{}(choice_CreateAccount);
		switch (choice_CreateAccount)
		{
			case 2:
			{
				std::cout << "INSIDE OF std::unique_ptr<AccountOwner> CreateAccount(void) /// case : 1 \n";
				std::uniform_int_distribution<> balance{ 0, 10000000 };
				std::uniform_int_distribution<> pinCode{ 1000, 9999 };
				customerName = getName();
				customerSurame = getSurname();
				customerAddress = getAddress();
				customerAccountBalance = static_cast<unsigned int>( balance(myRandom));
				customerAccountPINCode = static_cast<unsigned int>( pinCode(myRandom));
				customerAccountVipStatus = (customerAccountBalance >= 1'000'000) ? true : false;

				std::fstream fileHandler{};
				std::string tempString{};
				std::vector<std::string> tempStringVector{};
				fileHandler.open("D://Projects//Programming//C_And_Cpp//Cpp//ATM_With_Cpp_I//Accounts//PIN_CODE_LIST", std::ios::in);
				if (fileHandler.is_open())
				{
					while (fileHandler.good())
					{
						std::getline(fileHandler, tempString);
						tempStringVector.push_back((tempString));
					}
					fileHandler.close();
				}
				else
				{
					std::cout << "PIN_CODE_LIST could not be found/opened. Program is exiting.\n"; 
					sleep();
					exit(EXIT_FAILURE);
				}
				
				if (!tempStringVector.empty())
				{
					std::vector<std::string>::iterator it = std::find(tempStringVector.begin(), tempStringVector.end(), std::to_string(customerAccountPINCode));
					if (it != tempStringVector.end())
					{
						std::cout << "Such PIN CODE was choosen before. Please, try entering a different one...\n";
						break;
					}
				}
				
				std::unique_ptr<AccountOwner> customerPtr = std::make_unique<AccountOwner>(customerName, customerSurame, customerAddress, customerAccountBalance, customerAccountPINCode, customerAccountVipStatus);

				tempStringVector.push_back(std::to_string(customerAccountPINCode));

				if (!tempStringVector.empty())
				{
					for (std::vector<std::string>::iterator it = tempStringVector.begin(); it != tempStringVector.end(); ++it)
					{
						if (*it == "")
						{
							tempStringVector.erase(it);
							it = tempStringVector.begin();
						}
					}

					std::sort(tempStringVector.begin(), tempStringVector.end(), [](const std::string& Lhs, const std::string& Rhs) mutable
						{
							int iLhs = std::stoi(Lhs);
							int iRhs = std::stoi(Rhs);
							return iLhs < iRhs;
						});
				}

				fileHandler.open("D://Projects//Programming//C_And_Cpp//Cpp//ATM_With_Cpp_I//Accounts//PIN_CODE_LIST", std::ios::out);
				if (fileHandler.good())
				{
					for(const std::string& index : tempStringVector)
						fileHandler << index << "\n";

					fileHandler.close();
				}
				else
				{
					std::cout << "PIN_CODE_LIST could not be found. Program is exiting.\n"; 
					sleep();
					exit(EXIT_FAILURE);
				}

				return SaveAccountInfo(std::move(customerPtr));
			}
			case 3:
			{
				CLEAR
				std::cout << "INSIDE OF std::unique_ptr<AccountOwner> CreateAccount(void) /// case : 2 \n";
				std::cout << "Please, specify these values;\n";

				std::cout << "Name    : "; ValidateInput{}(customerName);
				std::cout << "Surname : "; ValidateInput{}(customerSurame);
				std::cout << "Address : "; ValidateInput{}(customerAddress);
				std::cout << "Balance : "; ValidateInput{}(customerAccountBalance);
				std::cout << "PIN Code:	"; ValidateInput{}(customerAccountPINCode);

				customerAccountVipStatus = (customerAccountBalance >= 1'000'000) ? true : false;

				std::fstream fileHandler{};
				std::string tempString{};
				std::vector<std::string> tempStringVector{};
				fileHandler.open("D://Projects//Programming//C_And_Cpp//Cpp//ATM_With_Cpp_I//Accounts//PIN_CODE_LIST", std::ios::in);
				if (fileHandler.good())
				{
					while (fileHandler.good())
					{
						std::getline(fileHandler, tempString);
						tempStringVector.emplace_back(tempString);
					}
					fileHandler.close();
				}
				else
				{
					std::cout << "PIN_CODE_LIST could not be found/opened. Program is exiting.\n"; 
					sleep();
					exit(EXIT_FAILURE);
				}
				
				std::sort(tempStringVector.begin(), tempStringVector.end());

				std::vector<std::string>::iterator it = std::find(tempStringVector.begin(), tempStringVector.end(), std::to_string(customerAccountPINCode));
				if(it != tempStringVector.end())
				{
					std::cout << "Such PIN CODE was choosen before. Please, try entering a different one...\n";
					break;
				}

				std::unique_ptr<AccountOwner> customerPtr = std::make_unique<AccountOwner>(customerName, customerSurame, customerAddress, customerAccountBalance, customerAccountPINCode, customerAccountVipStatus);
				
				fileHandler.open("D://Projects//Programming//C_And_Cpp//Cpp//ATM_With_Cpp_I//Accounts//PIN_CODE_LIST", std::ios::app);
				if (fileHandler.good())
				{
					fileHandler << customerPtr->getAccountPINCode() << "\n";
					fileHandler.close();
				}
				else
				{
					std::cout << "PIN_CODE_LIST could not be found. Program is exiting.\n"; 
					sleep();
					exit(EXIT_FAILURE);
				}

				return SaveAccountInfo(std::move(customerPtr));
			}
			case 4:
			{
				CLEAR
				std::cout << "INSIDE OF std::unique_ptr<AccountOwner> CreateAccount(void) /// case : 3 \n";
				std::cout << "Returning To The Main Menu..." << std::endl;
				sleep();
				break;
			}
			default:
			{
				continue;
			}
		}
		break;
	}

	return nullptr;
}

std::unique_ptr<AccountOwner> ReadAccountInfo(unsigned int& pinCode)
{
	std::cout << "INSIDE OF std::unique_ptr<AccountOwner> ReadAccountInfo(unsigned int& pinCode)\n";
	unsigned int remainingTry{2};
	while (remainingTry > 0)
	{
		std::ifstream fileHandler{};
		std::string path = "D://Projects//Programming//C_And_Cpp//Cpp//ATM_With_Cpp_I//Accounts//" + std::to_string(pinCode);
		fileHandler.open(path);
		if (fileHandler.is_open())
		{
			std::string tempString;
			std::vector<std::string> tempStringVector;
			while (fileHandler.good())
			{
				std::getline(fileHandler, tempString);
				tempStringVector.push_back(tempString);
			}
			fileHandler.close();

			std::unique_ptr<AccountOwner> customer = std::make_unique<AccountOwner>();
			customer->setName(tempStringVector[0]);
			customer->setSurname(tempStringVector[1]);
			customer->setAddress(tempStringVector[2]);
			customer->setBalance(static_cast<unsigned int>(std::stoi(tempStringVector[3])));
			customer->setAccountPINCode(pinCode);
			customer->setAccountVipStatus(static_cast<bool>(std::stoi(tempStringVector[4])));

			return customer;
		}
		else
		{
			std::cout << "Such _" << pinCode << "_ Pin Code could not be found.\n";
			std::cout << "Please, choose one below to proceed further;\n";
			std::cout << "[2] : To Create A New Account.\n";
			std::cout << "[3] : To Enter A Pin Code Again.\n";
			std::cout << "[4] : To Exit.\n";
			std::cout << "[ You can try entering [" << remainingTry << "] more times...]\n";

			while (true)
			{
				unsigned int choice_ReadAccountInfo{ 0 };
				ValidateInput{}(choice_ReadAccountInfo);
				switch (choice_ReadAccountInfo)
				{
					case 2:
					{
						return CreateAccount();
					}
					case 3:
					{
						--remainingTry;
						CLEAR
						break;
					}
					case 4:
					{
						CLEAR std::cout << "No account were created. Program is exiting by request.";
						sleep();
						exit(EXIT_SUCCESS);
					}
					default:
					{
						continue;
					}
				}
				break;
			}
		}
		ValidateInput{}(pinCode);
	}

	CLEAR 
	std::cout << "Too Many Failed Entries. Program is exiting.\n";
	sleep();
	exit(EXIT_FAILURE);
}


void UserScreen(void)
{
	std::cout << "Welcome to the ATM Machine. Please, enter your name and PIN code to proceed.\n";
	std::cout << "< If your PIN CODE is not reachable, please press 9999. >\n";

	while (true)
	{
		unsigned int pinCode{};
		ValidateInput{}(pinCode);

		while (true)
		{
			CLEAR
			std::unique_ptr<AccountOwner> customer{};
			if (pinCode == 9999)
			{
				while (true)
				{
					std::cout << "Would you like to create a new account, or search for if you have already one?\n";
					std::cout << "To Create A New Account  : 2\n";
					std::cout << "To Search For An Account : 3\n";
					std::cout << "To Exit                  : 4\n";
					unsigned int choice_UserScreen{};
					ValidateInput{}(choice_UserScreen);
					switch (choice_UserScreen)
					{
						case 2:
						{
							CLEAR
							customer = CreateAccount();
							if (customer)
							{
								pinCode = static_cast<int>(customer->getAccountPINCode()); 
							}
							
							break;
						}
						case 3:
						{
							CLEAR
							customer = FindLostAccount();
							if (customer)
							{
								pinCode = static_cast<int>(customer->getAccountPINCode());
							}
			
							break;
						}
						case 4:
						{
							CLEAR
							std::cout << "Exiting from the program by request.\n";
							sleep();
							exit(EXIT_SUCCESS);
						}
						default:
						{
							continue;
						}
					}
					break;
				}
			}
			else 
			{
				customer = ReadAccountInfo(pinCode);
			}

			if(customer)
			{
				pinCode = customer->getAccountPINCode();
				std::cout << "Welcome => " << customer->getName() << "!\n";
				std::cout << "\nWhat would you like to do?\n";
				std::cout << "To Change Account Info.    : 2\n";
				std::cout << "To Withdraw Cash           : 3\n";
				std::cout << "To Deposit Cash            : 4\n";
				std::cout << "To See Account Information : 5\n";
				std::cout << "To Exit                    : 6\n";
				
				unsigned int customerChoice_UserScreen{};
				ValidateInput{}(customerChoice_UserScreen);
				switch (customerChoice_UserScreen)
				{
					case 2:
					{
						CLEAR ChangeAccountInfo(pinCode); break;
					}
					case 3:
					{
						CLEAR WithdrawCurrency(std::move(customer)); break;
					}
					case 4:
					{
						CLEAR DepositCurrency(std::move(customer)); break;
					}
					case 5:
					{
						CLEAR CheckAccountInfo(std::move(customer)); break;
					}
					case 6:
					{
						std::cout << "Exiting from the program by request.\n";
						sleep();
						exit(EXIT_SUCCESS);
					}
					default:
					{
						continue;
					}
				}
			}
		}
	}
}

void CheckAccountInfo(std::unique_ptr<AccountOwner> customer)
{
	std::cout << "=============================================" << std::endl;
	std::cout << "Information of customer    :\n";
	std::cout << "Name                       : " << customer->getName() << std::endl;
	std::cout << "Surname                    : " << customer->getSurname() << std::endl;
	std::cout << "Address                    : " << customer->getAddress() << std::endl;
	std::cout << "AccountBalance             : " << customer->getBalance() << std::endl;
	std::cout << "AccountPINCode             : " << customer->getAccountPINCode() << std::endl;
	std::cout << "AccountVipStatus           : " << std::boolalpha << customer->getAccountVipStatus() << std::endl;
	std::cout << "=============================================" << std::endl;
	while (true)
	{
		std::cout << "How Would You Like To Proceed?\n";
		std::cout << "[2] : Back To The Main Menu.\n";
		std::cout << "[3] : To Exit.\n";
		unsigned int choice_CheckAccountInfo{};
		ValidateInput{}(choice_CheckAccountInfo);
		switch (choice_CheckAccountInfo)
		{
			case 2 : 
			{
				std::cout << "Returning To The Main Menu..." << std::endl;
				sleep();
				break;
			}
			case 3 :
			{
				std::cout << "Exiting from the program by request.\n";
				sleep();
				exit(EXIT_SUCCESS);
			}
		}
		break;
	}
}

void DepositCurrency(std::unique_ptr<AccountOwner> customer)
{
	std::unique_ptr<ATM> host = ReadAtmInfo();

	std::cout << "How much TL will you deposit to? : " << std::flush;
	unsigned int depositAmount{};
	ValidateInput{}(depositAmount);

	while (true)
	{
		CLEAR
		std::cout << "Please, choose one below;\n";
		std::cout << "2- To My Own Account.\n";
		std::cout << "3- To Other Account.\n";
		unsigned int userChoice_DepositCurrency{};
		ValidateInput{}(userChoice_DepositCurrency);
		switch (userChoice_DepositCurrency)
		{
			case 2:
			{
				host->setATMBalanceAmount(host->getATMBalanceAmount() + depositAmount);

				customer->setBalance(customer->getBalance() + depositAmount);
				std::cout << "Currently, customer have " << customer->getBalance() << "TL in his/her bank account.\n";
				
				if (customer->getBalance() > 1'000'000)
				{
					customer->setAccountVipStatus(true);
				}

				SaveAccountInfo(std::move(customer));
				SaveAtmInfo(std::move(host));

				break;
			}
			case 3:
			{
				CLEAR
				std::cout << "Please, enter the PIN Code for the targeted account: ";
				unsigned int tempPinCode{};
				ValidateInput{}(tempPinCode);
				std::ifstream fileHandler{};
				fileHandler.open(std::to_string(tempPinCode));
				if (fileHandler.good())
				{
					std::string tempString;
					std::vector<std::string> tempStringVector;
					while (fileHandler.good())
					{
						std::getline(fileHandler, tempString);
						tempStringVector.push_back(tempString);
					}
					fileHandler.close();

					std::unique_ptr<AccountOwner> targetCustomer = std::make_unique<AccountOwner>();
					targetCustomer->setName(tempStringVector[0]);
					targetCustomer->setSurname(tempStringVector[1]);
					targetCustomer->setAddress(tempStringVector[2]);
					targetCustomer->setBalance(static_cast<unsigned int>(std::stoi(tempStringVector[3]) + depositAmount));
					targetCustomer->setAccountPINCode(static_cast<unsigned int>(tempPinCode));
					if (customer->getBalance() > 1'000'000)
					{
						customer->setAccountVipStatus(true);
					}

					host->setATMBalanceAmount(host->getATMBalanceAmount() + depositAmount);
					SaveAtmInfo(std::move(host));

					SaveAccountInfo(std::move(targetCustomer));

					std::cout << "Transaction was completed. Total of [" << depositAmount << "] was deposited to the account owner of [" << tempPinCode << "].\n";
				}
				
				fileHandler.close();

				break;
			}
			default:
			{
				continue;
			}
		}

		break;
	}
	
	while (true)
	{
		std::cout << "How Would You Like To Proceed?\n";
		std::cout << "[2] : Back To The Main Menu.\n";
		std::cout << "[3] : To Exit.\n";
		unsigned int choice_DepositCurrency_Two{};
		ValidateInput{}(choice_DepositCurrency_Two);
		switch (choice_DepositCurrency_Two)
		{
			case 2 : 
			{
				std::cout << "Returning To The Main Menu..." << std::endl;
				sleep();
				break;
			}
			case 3:
			{
				std::cout << "Exiting from the program by request.\n";
				sleep();
				exit(EXIT_SUCCESS);
			}
		}
		break;
	}
}

void WithdrawCurrency(std::unique_ptr<AccountOwner> customer)
{
	std::unique_ptr<ATM> host = ReadAtmInfo();

	while (true)
	{
		std::cout << "How much TL will you withdraw from? : " << std::flush;
		unsigned int withdrawAmount{};
		ValidateInput{}(withdrawAmount);

		if ((host->getATMBalanceAmount() >= static_cast<unsigned int>(withdrawAmount)) && (customer->getBalance() >= static_cast<unsigned int>(withdrawAmount)))
		{
			customer->setBalance(customer->getBalance() - withdrawAmount);
			host->setATMBalanceAmount(host->getATMBalanceAmount() - withdrawAmount);
			std::cout << "Currently, customer have " << customer->getBalance() << "TL in his/her bank account.\n";

			break;
		}
		else
		{
			std::cout << "You do not have that much of cash money either in your account or in ATM.\n";
			std::cout << "Cash in Your Account      : " << customer->getBalance() << "\n";
			std::cout << "Cash in ATM               : " << host->getATMBalanceAmount() << "\n";
			std::cout << "Cash you wish to withdraw : " << withdrawAmount << "\n";
			std::cout << "Enter Cash Amount Again   : ";
			continue;
		}
	}

	if (customer->getBalance() <= 1'000'000)
	{
		customer->setAccountVipStatus(false);
	}

	SaveAccountInfo(std::move(customer));
	SaveAtmInfo(std::move(host));

	while (true)
	{
		std::cout << "How Would You Like To Proceed?\n";
		std::cout << "[2] : Back To The Main Menu.\n";
		std::cout << "[3] : To Exit.\n";
		unsigned int choice_WithdrawCurrency{};
		ValidateInput{}(choice_WithdrawCurrency);
		switch (choice_WithdrawCurrency)
		{
			case 2 : 
			{
				std::cout << "Returning To The Main Menu..." << std::endl;
				sleep();
				break;
			}
			case 3:
			{
				std::cout << "Exiting from the program by request.\n";
				sleep();
				exit(EXIT_SUCCESS);
			}
		}
		break;
	}
}

void ChangeAccountInfo(unsigned int& pinCode)
{
	while (true)
	{
		std::unique_ptr<AccountOwner> customer = ReadAccountInfo(pinCode);
		std::cout << "Which piece of information would you like to change?\n";
		std::cout << "To Go to Main Menu: 2\n";
		std::cout << "To Change PIN Code: 3\n";
		std::cout << "To Change Address : 4\n";
		std::cout << "To Change Surname : 5\n";
		std::cout << "To Change Name    : 6\n";
		std::cout << "To Exit           : 7\n";
		unsigned int shallow_choice{};
		ValidateInput{}(shallow_choice);

		switch (shallow_choice)
		{
			case 2:
			{
				break;
			}
			case 3:
			{
				unsigned int tempPinCode{};
				std::string oldPinCode{ std::to_string(customer->getAccountPINCode()) };
				
				std::cout << "Enter the new Pin Code for customer:";
				ValidateInput{}(tempPinCode);

				customer->setAccountPINCode(tempPinCode);
				std::cout << "Your PIN Code has been changed. Your new PIN Code is : " << customer->getAccountPINCode() << std::endl;
				std::cout << "SINCE A YOUR ID HAS CHANGED, YOU NEED TO RESTART THE PROGRAM. EXITING...\n";

				std::fstream fileHandler{};
				fileHandler.open("D://Projects//Programming//C_And_Cpp//Cpp//ATM_With_Cpp_I//Accounts//PIN_CODE_LIST", std::ios::in);
				if (!fileHandler)
				{
					std::cout << "Failed to open " << "PIN_CODE_LIST TO READ FROM IT. Exiting from the program.\n";
					exit(EXIT_FAILURE);
				}
				std::vector<std::string> tempPinCodeStringVector;
				std::string tempString;
				while (fileHandler.good())
				{
					std::getline(fileHandler, tempString);
					tempPinCodeStringVector.push_back(tempString);
				}
				fileHandler.close();

				for (std::vector<std::string>::iterator it{tempPinCodeStringVector.begin()}; it != tempPinCodeStringVector.end(); ++it)
				{
					if (*it == oldPinCode)
					{
						tempPinCodeStringVector.erase(it);
						it = tempPinCodeStringVector.begin();
					}
				}

				tempPinCodeStringVector.push_back(std::to_string(tempPinCode));

				fileHandler.open("D://Projects//Programming//C_And_Cpp//Cpp//ATM_With_Cpp_I//Accounts//PIN_CODE_LIST", std::ios::out);
				if (!fileHandler)
				{
					std::cout << "Failed to open " << "PIN_CODE_LIST TO WRITE TO IT. Exiting from the program.\n";
					exit(EXIT_FAILURE);
				}
				for (std::size_t it = 0; it < tempPinCodeStringVector.size(); it++)
				{
					fileHandler << tempPinCodeStringVector.at(it) << std::endl;
				}
				fileHandler.close();

				std::remove(oldPinCode.c_str());// Deletes the old file.
				SaveAccountInfo(std::move(customer));
				sleep();

				std::exit(EXIT_SUCCESS);
			}
			case 4:
			{
				std::string address;
				std::cout << "Enter the new address for customer.\n";
				ValidateInput{}(address);

				customer->setAddress(address);
				std::cout << "Your address has been changed. Your new address is : " << customer->getAddress() << std::endl;
				SaveAccountInfo(std::move(customer));

				while (true)
				{
					std::cout << "How Would You Like To Proceed?\n";
					std::cout << "[2] : Back To The Previous Menu.\n";
					std::cout << "[3] : To Exit.\n";
					unsigned int deep_choice{};
					ValidateInput{}(deep_choice);
					switch (deep_choice)
					{
						case 2 : 
						{
							std::cout << "Returning To The Main Menu..." << std::endl;
							sleep();
							break;
						}
						case 3:
						{
							std::cout << "Exiting from the program by request.\n";
							sleep();
							exit(EXIT_SUCCESS);
						}
						default:
						{
							CLEAR
							continue;
						}
					}
					break;
				}

				continue;
			}
			case 5:
			{
				std::string surname;
				std::cout << "Enter the new surname for customer.\n";
				ValidateInput{}(surname);

				customer->setSurname(surname);
				std::cout << "Your surname has been changed. Your new surname is : " << customer->getSurname() << std::endl;
				SaveAccountInfo(std::move(customer));

				while (true)
				{
					std::cout << "How Would You Like To Proceed?\n";
					std::cout << "[2] : Back To The Previous Menu.\n";
					std::cout << "[3] : To Exit.\n";
					unsigned int choice{};
					ValidateInput{}(choice);
					switch (choice)
					{
						case 2 : 
						{
							std::cout << "Returning To The Main Menu..." << std::endl;
							sleep();
							break;
						}
						case 3:
						{
							std::cout << "Exiting from the program by request.\n";
							sleep();
							exit(EXIT_SUCCESS);
						}
						default:
						{
							CLEAR
							continue;
						}
					}
					break;
				}

				continue;
			}
		case 6:
			{
				std::string name;
				std::cout << "Enter the new name for customer.\n";
				ValidateInput{}(name);

				customer->setName(name);
				std::cout << "Your name has been changed. Your new name is : " << customer->getName() << std::endl;
				SaveAccountInfo(std::move(customer));

				while (true)
				{
					std::cout << "How Would You Like To Proceed?\n";
					std::cout << "[2] : Back To The Previous Menu.\n";
					std::cout << "[3] : To Exit.\n";
					unsigned int choice{};
					ValidateInput{}(choice);
					switch (choice)
					{
						case 2 : 
						{
							std::cout << "Returning To The Main Menu..." << std::endl;
							sleep();
							break;
						}
						case 3:
						{
							std::cout << "Exiting from the program by request.\n";
							sleep();
							exit(EXIT_SUCCESS);
						}
						default:
						{
							CLEAR
							continue;
						}
					}
					break;
				}

				continue;
			}
			case 7:
			{
				std::cout << "Exiting from the program by request.\n";
				sleep();
				exit(EXIT_SUCCESS);
			}
			default:
			{
				continue;
			}
		}
		break;
	}
}

std::unique_ptr<AccountOwner> SaveAccountInfo(std::unique_ptr<AccountOwner> customer)
{
	std::fstream fileHandler{};
	fileHandler.open("D://Projects//Programming//C_And_Cpp//Cpp//ATM_With_Cpp_I//Accounts//" + std::to_string(customer->getAccountPINCode()), std::ios::out);
	if (!fileHandler)
	{
		std::cout << "Failed to open _" << std::to_string(customer->getAccountPINCode()) << "_. Exiting from the program.\n";
		exit(EXIT_FAILURE);
	}
	fileHandler << customer->getName() << "\n" << customer->getSurname() << "\n" << customer->getAddress() << "\n" << customer->getBalance() << "\n" << customer->getAccountVipStatus() << "\n";
	fileHandler.close();
	
	return customer;
}

std::unique_ptr<AccountOwner> FindLostAccount(void)
{
	std::ifstream fileHandler{};

	std::vector<std::string> tempPinCodeStringVector;
	std::vector<std::string> tempStringVector;

	std::string nameComparer{};
	std::string	surnameComparer{};
	std::string addressComparer{};

	fileHandler.open("D://Projects//Programming//C_And_Cpp//Cpp//ATM_With_Cpp_I//Accounts//PIN_CODE_LIST");
	if (fileHandler.good())
	{
		std::string tempString;
		while (fileHandler.good())
		{
			std::getline(fileHandler, tempString);
			tempPinCodeStringVector.push_back(tempString);
		}
		fileHandler.close();
		
		
		std::cout << "Please, enter a name to be searched. " << std::endl;
		ValidateInput{}(nameComparer);
		
		std::cout << "Please, enter a surname to be searched. " << std::endl;
		ValidateInput{}(surnameComparer);

		std::cout << "Please, enter a address to be searched. " << std::endl;
		ValidateInput{}(addressComparer);

		std::size_t i{};
		for (; i < tempPinCodeStringVector.size(); i++)
		{
			fileHandler.open(tempPinCodeStringVector.at(i));
			if(fileHandler.good())
			{
				while (fileHandler.good())
				{
					std::getline(fileHandler, tempString);
					tempStringVector.push_back(tempString);
				}
				fileHandler.close();

				if ( (nameComparer == tempStringVector.at(0)) && (surnameComparer == tempStringVector.at(1)) && (addressComparer == tempStringVector.at(2)) )
				{
					std::cout << "YOUR ACCOUNT HAS BEEN FOUND!!!\nPlease, wait..." << std::flush;
					sleep();
					break;
				}
			}
			else
			{
				std::cout << "YOUR ACCOUNT COULD NOT BE FOUND!!!\nExiting from the program...\n";
				sleep();
				exit(EXIT_SUCCESS);
			}
		}

		CLEAR

		std::unique_ptr<AccountOwner> customer = std::make_unique<AccountOwner>();
		customer->setName(tempStringVector[0]);
		customer->setSurname(tempStringVector[1]);
		customer->setAddress(tempStringVector[2]);
		customer->setBalance(static_cast<unsigned int>(std::stoi(tempStringVector[3])));
		customer->setAccountPINCode(static_cast<unsigned int>(std::stoi(tempPinCodeStringVector.at(i))));
		customer->setAccountVipStatus(static_cast<bool>(std::stoi(tempStringVector[4])));
		return customer;
	}

	std::cout << "PIN_CODE_LIST COULD NOT OPENED!!!\nExiting from the program...\n";
	sleep();
	exit(EXIT_SUCCESS);
}