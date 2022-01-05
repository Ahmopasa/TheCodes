#ifndef __ATM_PROGRAM_H__
#define __ATM_PROGRAM_H__

#ifdef _WIN32
    #define CLEAR system("cls"); 
#else
    #define CLEAR system("clear");
#endif

#include <memory>

#include "PremiumAccountOwner.h"
#include "NormalAccountOwner.h"
#include "ATM.h"

class ATM_Program {
public: 
    static ATM_Program* Instance(const int& userID);

    void whoIs(void) const;
    bool isRdy(void) const;

    void processDeposit(const unsigned int& amount);
    void processWithdraw(const unsigned int& amount);

    std::unique_ptr<AccountOwner>& getHandlerPtr(void);
private:
    ATM_Program(const int& userID = 9999);

private:
    static ATM_Program* s_pInstance;

    bool m_isRdy{};
    std::unique_ptr<AccountOwner> m_HandlerPtr{};
    std::unique_ptr<ATM> m_AtmHandlerPtr{};
 };

#endif // __ATM_PROGRAM_H__