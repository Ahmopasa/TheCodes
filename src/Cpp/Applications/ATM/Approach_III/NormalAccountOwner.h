#ifndef __NORMAL_ACCOUNT_OWNER_H__
#define __NORMAL_ACCOUNT_OWNER_H__

#include "AccountOwner.h"

class NormalAccountOwner final : public AccountOwner
{
public:
	// Constructors
	NormalAccountOwner(const std::string& tempName = "NoNameYet", const std::string& tempSurname = "NoSurnameYet", const std::string& tempAddress = "NoAddressYet", const unsigned int& tempBalance = 0, const unsigned int& tempPINCode = 0, const bool tempVipStatus = false)
    : AccountOwner{ tempName, tempSurname, tempAddress, tempBalance, tempPINCode, tempVipStatus }
    {}
	
    //Copt Constructor
    NormalAccountOwner(const NormalAccountOwner& other) : AccountOwner{other}
    {
        
    }

	//Deconstructor
	~NormalAccountOwner()
    {
        
    }

	//User Interface Functions
    void saveAccountInfo(void) const override {} // TODO: Implementation of saveAccountInfo method will be done in the future.
};

#endif // __NORMAL_ACCOUNT_OWNER_H__