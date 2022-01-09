#ifndef __ACCOUNT_OWNER_H__
#define __ACCOUNT_OWNER_H__

#include "I_Print.h"

#include <string>


class AccountOwner : public I_Print
{
public:
	// Constructors
	AccountOwner(const std::string& tempName = "NoNameYet", const std::string& tempSurname = "NoSurnameYet", const std::string& tempAddress = "NoAddressYet", const unsigned int& tempBalance = 0, const unsigned int& tempPINCode = 0, const bool tempVipStatus = false)
	: m_Name{ tempName }, m_Surname{ tempSurname }, m_Address{ tempAddress }, m_Balance{ tempBalance }, m_PinCode{ tempPINCode }, m_VipStatus{ tempVipStatus } 
	{

	}
	
	// Copy Constructors
	AccountOwner(const AccountOwner& tempObj) : m_Name{ tempObj.m_Name }, m_Surname{ tempObj.m_Surname }, m_Address{ tempObj.m_Address }, m_Balance{ tempObj.m_Balance }, m_PinCode{ tempObj.m_PinCode }, m_VipStatus{ tempObj.m_VipStatus }
	{

	}
	
	//Deconstructor
	virtual ~AccountOwner()
	{
		
	}

	// Getter & Setter Functions
	const std::string& getName(void) const { return m_Name; }
	void setName(const std::string& tempName) { this->m_Name = tempName; }

	const std::string& getSurname(void) const { return m_Surname; }
	void setSurname(const std::string& tempSurname) { this->m_Surname = tempSurname; }

	const std::string& getAddress(void) const { return m_Address; }
	void setAddress(const std::string& tempAddress) { this->m_Address = tempAddress; }

	const unsigned int& getBalance(void) const { return m_Balance; }
	void setBalance(const unsigned int& tempBalance) { this->m_Balance = tempBalance; }

	const unsigned int& getAccountPINCode(void) const { return m_PinCode; }
	void setAccountPINCode(const unsigned int& tempPINCode) { this->m_PinCode = tempPINCode; }

	const bool& getAccountVipStatus(void) const { return m_VipStatus; }
	void setAccountVipStatus(const bool& tempVipStatus) { this->m_VipStatus = tempVipStatus; }

	//User Interface Functions
	virtual void saveInfo(void) const = 0;
	virtual void readInfo(void) = 0;

	void print(std::ostream& os) const override
	{
		os << "#######################################" << std::endl;
		os << "Name      : " << getName() << std::endl;
		os << "Surname   : " << getSurname() << std::endl;
		os << "Address   : " << getAddress() << std::endl;
		os << "Balance   : " << getBalance() << std::endl;
		os << "PIN Code  : " << getAccountPINCode() << std::endl;
		os << "VIP Status: " << getAccountVipStatus() << std::endl;
		os<< "#######################################" << std::endl;
	}

private:
	std::string m_Name{ "NoName" };
	std::string m_Surname{ "NoSurname" };
	std::string m_Address{ "NoAddress" };

	unsigned int m_Balance{ 0 };
	unsigned int m_PinCode{ 0 };

	bool m_VipStatus{ 0 };
};

#endif // __ACCOUNT_OWNER_H__