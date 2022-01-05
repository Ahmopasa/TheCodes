#ifndef ATM_H_
#define ATM_H_

#ifdef __cplusplus

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class ATM
{
private:
	unsigned int ATMBalanceAmount;

public:
	ATM();
	~ATM();

	const unsigned int& getATMBalanceAmount(void) const;
	void setATMBalanceAmount(const unsigned int&);
};

class AccountOwner : public ATM
{
private:
	std::string Name;
	std::string Surname;
	std::string Address;

	unsigned int AccountBalance;
	unsigned int AccountPINCode;

	bool AccountVipStatus;

public:
	static int AccountTransactionCounter;

public:
	const std::string& getName(void) const;
	void setName(const std::string&);

	const std::string& getSurname(void) const;
	void setSurname(const std::string&);

	const std::string& getAddress(void) const;
	void setAddress(const std::string&);

	const unsigned int& getBalance(void) const;
	void setBalance(const unsigned int&);

	const unsigned int& getAccountPINCode(void) const; 
	void setAccountPINCode(const unsigned int&);

	const bool& getAccountVipStatus(void) const;
	void setAccountVipStatus(const bool&);

	AccountOwner(void);
	AccountOwner(std::string& tempName, std::string& tempSurname, std::string& tempAddress, unsigned int& tempBalance, unsigned int& tempPINCode, bool tempVipStatus = false);
	AccountOwner(const AccountOwner&);
	~AccountOwner();
};

void CheckAccountInfo(const std::vector<AccountOwner>&);
void DepositCurrency(std::vector<AccountOwner>&);
void WithdrawCurrency(std::vector<AccountOwner>&);
std::vector<AccountOwner>& CreateAccount(std::vector<AccountOwner>&);
void ChangeAccountInfo(std::vector<AccountOwner>&); 
void SaveAccountInfo(const std::vector<AccountOwner>&);
void UserScreen(void);
std::vector<AccountOwner>& ReadAccountInfo(const int&, std::vector<AccountOwner>&);

#endif

#ifdef __cplusplus	
extern "C" {
#endif // __cplusplus

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <errno.h>

typedef struct AccountOwner
{
	char Name[10];
	char Surname[10];
	char Address[10];

	unsigned int Balance;
	unsigned int AccountPINCode;
	unsigned int AccountVipStatus;
}AccountOwner;

void ReadAccountInfo(const int, AccountOwner*);
void ChangeAccountInfo(AccountOwner*);
void CheckAccountInfo(const AccountOwner*);
void DepositCurrency(AccountOwner*);
void WithdrawCurrency(AccountOwner*);
void SaveAccountInfo(const AccountOwner*);
void ui_screen(void);

#ifdef __cplusplus
}
#endif // __cplusplus

 
#endif // ATM_H_