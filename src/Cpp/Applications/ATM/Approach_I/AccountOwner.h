//===================== # HEADER GUARDS # ===================
#ifndef __ACCOUNT_OWNER_H__
#define __ACCOUNT_OWNER_H__

//===================== # HEADER FILES # =====================
#include <string>

//===================== # CLASS DEFINITONS # ==================
class AccountOwner
{
public:
	constexpr bool getAccountVipStatus() const
	{
		return m_AccountVipStatus;
	}

	void setAccountVipStatus(bool tempVipStatus)
	{
		m_AccountVipStatus = tempVipStatus;
	}

	constexpr unsigned int getBalance() const
	{
		return m_AccountBalance;
	}

	void setBalance(unsigned int tempBalance)
	{
		m_AccountBalance = tempBalance;
	}

	constexpr unsigned int getAccountPINCode() const
	{
		return m_AccountPINCode;
	}

	void setAccountPINCode(unsigned int tempPINCode)
	{
		m_AccountPINCode = tempPINCode;
	}

	constexpr const std::string& getName(void) const
	{
		return m_Name;
	}
	void setName(const std::string& tempName)
	{
		m_Name = tempName;
	}

	constexpr const std::string& getSurname() const
	{
		return m_Surname;
	}

	void setSurname(const std::string& tempSurname)
	{
		m_Surname = tempSurname;
	}

	constexpr const std::string& getAddress() const
	{
		return m_Address;
	}

	void setAddress(const std::string& tempAddress)
	{
		m_Address = tempAddress;
	}

	AccountOwner(void) = default;
	AccountOwner(const std::string& tempName, const std::string& tempSurname, const std::string& tempAddress, unsigned int tempBalance, unsigned int tempPINCode, bool tempVipStatus = false) : m_AccountVipStatus{ tempVipStatus }, 
																																																m_AccountBalance{ tempBalance }, m_AccountPINCode{tempPINCode},
																																																m_Name{ tempName }, m_Surname{ tempSurname }, m_Address{ tempAddress }
																																																{}

private:
	bool m_AccountVipStatus{ 0 };

	unsigned int m_AccountBalance{ 0 };
	unsigned int m_AccountPINCode{ 0 };

	std::string m_Name{ "NoName" };
	std::string m_Surname{ "NoSurname" };
	std::string m_Address{ "NoAddress" };
};

#endif