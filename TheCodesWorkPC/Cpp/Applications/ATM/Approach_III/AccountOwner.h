#ifndef __ACCOUNT_OWNER_H__
#define __ACCOUNT_OWNER_H__

#include "I_Print.h"

#include <string>

class AccountOwner : public I_Print
{
public:
	// Constructors
	AccountOwner(const std::string& tempName = "NoNameYet", const std::string& tempSurname = "NoSurnameYet", const std::string& tempAddress = "NoAddressYet", const unsigned int& tempBalance = 0, const unsigned int& tempPINCode = 0, const bool tempVipStatus = false)
	: Name{ tempName }, Surname{ tempSurname }, Address{ tempAddress }, AccountBalance{ tempBalance }, AccountPINCode{ tempPINCode }, AccountVipStatus{ tempVipStatus } 
	{

	}
	
	// Copy Constructors
	AccountOwner(const AccountOwner& tempObj) : Name{tempObj.Name}, Surname{tempObj.Surname}, Address{tempObj.Address}, AccountBalance{tempObj.AccountBalance}, AccountPINCode{tempObj.AccountPINCode}, AccountVipStatus{tempObj.AccountVipStatus} 
	{

	}
	
	//Deconstructor
	virtual ~AccountOwner()
	{
		
	}

	// Getter & Setter Functions
	const std::string& getName(void) const { return Name; }
	void setName(const std::string& tempName) { this->Name = tempName; }

	const std::string& getSurname(void) const { return Surname; }
	void setSurname(const std::string& tempSurname) { this->Surname = tempSurname; }

	const std::string& getAddress(void) const { return Address; }
	void setAddress(const std::string& tempAddress) { this->Address = tempAddress; }

	const unsigned int& getBalance(void) const { return AccountBalance; }
	void setBalance(const unsigned int& tempBalance) { this->AccountBalance = tempBalance; }

	const unsigned int& getAccountPINCode(void) const { return AccountPINCode; }
	void setAccountPINCode(const unsigned int& tempPINCode) { this->AccountPINCode = tempPINCode; }

	const bool& getAccountVipStatus(void) const { return AccountVipStatus; }
	void setAccountVipStatus(const bool& tempVipStatus) { this->AccountVipStatus = tempVipStatus; }

	//User Interface Functions
	virtual void saveAccountInfo(void) const = 0;

	void print(std::ostream& os) const override
	{
		std::cout << "#######################################" << std::endl;
		os << "Name      : " << getName() << std::endl;
		os << "Surname   : " << getSurname() << std::endl;
		os << "Address   : " << getAddress() << std::endl;
		os << "Balance   : " << getBalance() << std::endl;
		os << "PIN Code  : " << getAccountPINCode() << std::endl;
		os << "VIP Status: " << getAccountVipStatus() << std::endl;
		std::cout << "#######################################" << std::endl;
	}

private:
	std::string Name{ "NoName" };
	std::string Surname{ "NoSurname" };
	std::string Address{ "NoAddress" };

	unsigned int AccountBalance{ 0 };
	unsigned int AccountPINCode{ 0 };

	bool AccountVipStatus{ 0 };
};

#endif // __ACCOUNT_OWNER_H__