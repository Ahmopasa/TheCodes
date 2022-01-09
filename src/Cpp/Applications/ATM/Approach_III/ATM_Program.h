#ifndef __ATM_PROGRAM_H__
#define __ATM_PROGRAM_H__

#include <memory>
#include <iostream>

#include "PremiumAccountOwner.h"
#include "NormalAccountOwner.h"
#include "ATM.h"

class ATMProgram {
public: 
    void UserScreen(void); 

private:
    std::unique_ptr<AccountOwner> DepositCurrency(std::unique_ptr<AccountOwner> tempAccountOwnerPtr); 
    std::unique_ptr<AccountOwner> WithdrawCurrency(std::unique_ptr<AccountOwner> tempAccountOwnerPtr); // TODO: Implementation of WithdrawCurrency method will be done in the future.
    std::unique_ptr<AccountOwner> ChangeAccountInfo(std::unique_ptr<AccountOwner> tempAccountOwnerPtr); // TODO: Implementation of ChangeAccountInfo method will be done in the future.
    void SaveAccountInfo(std::unique_ptr<AccountOwner> tempAccountOwnerPtr);
    std::unique_ptr<AccountOwner> CheckAccountInfo(std::unique_ptr<AccountOwner> tempAccountOwnerPtr);
    std::unique_ptr<AccountOwner> FindAccount(unsigned int tempPinCode); 
private:

    std::unique_ptr<AccountOwner> host;
 };

#endif // __ATM_PROGRAM_H__