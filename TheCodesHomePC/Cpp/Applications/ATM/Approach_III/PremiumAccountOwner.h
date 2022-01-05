#ifndef __PREMIUM_ACCOUNT_OWNER_H__
#define __PREMIUM_ACCOUNT_OWNER_H__

#include "AccountOwner.h"

class PremiumAccountOwner final : public AccountOwner
{
public:
	// Constructors
	PremiumAccountOwner(const std::string& tempName = "NoNameYet", const std::string& tempSurname = "NoSurnameYet", const std::string& tempAddress = "NoAddressYet", const unsigned int& tempBalance = 0, const unsigned int& tempPINCode = 0)
    : AccountOwner{ tempName, tempSurname, tempAddress, tempBalance, tempPINCode}
    {
        if (tempBalance >= 1'000'000)
        {
            setAccountVipStatus(true);
        }
    }

    //Copt Constructor
    PremiumAccountOwner(const PremiumAccountOwner& other) : AccountOwner{other}
    {

    }
	
	//Deconstructor
	~PremiumAccountOwner()
    {
        
    }

	//User Interface Functions
    void saveAccountInfo(void) const override {} // TODO: Implementation of saveAccountInfo method will be done in the future.
};

#endif //__PREMIUM_ACCOUNT_OWNER_H__
