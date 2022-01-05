//===================== # HEADER GUARDS # ===================
#ifndef __ATM_PROGRAM_H__
#define __ATM_PROGRAM_H__

#ifdef _WIN32
    #define CLEAR system("cls");
#else
    #define CLEAR system("clear");
#endif

//===================== # HEADER FILES # =====================
#include <memory>
#include "AccountOwner.h"
#include "ATM.h"

//===================== # FUNCTION DECLERATIONS # ============
std::unique_ptr<AccountOwner> CreateAccount(void);
std::unique_ptr<AccountOwner> ReadAccountInfo(unsigned int&);
void UserScreen(void);
void CheckAccountInfo(std::unique_ptr<AccountOwner>);
void DepositCurrency(std::unique_ptr<AccountOwner>);
void WithdrawCurrency(std::unique_ptr<AccountOwner>);
void ChangeAccountInfo(unsigned int&);
std::unique_ptr<AccountOwner> SaveAccountInfo(std::unique_ptr<AccountOwner>);
std::unique_ptr<AccountOwner> FindLostAccount(void);

#endif
