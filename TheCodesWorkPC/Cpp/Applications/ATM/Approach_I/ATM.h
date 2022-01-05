//===================== # HEADER GUARDS # ===================
#ifndef __ATM_H__
#define __ATM_H__

//===================== # CLASS DEFINITONS # ==================
class ATM
{
public:
	ATM() = default;

	constexpr unsigned int getATMBalanceAmount(void) const
	{
		return ATMBalanceAmount;
	}

	constexpr void setATMBalanceAmount(unsigned int tempBalance)
	{
		ATMBalanceAmount = tempBalance;
	}

private:
	unsigned int ATMBalanceAmount{ 1'000'000 };
};

#endif