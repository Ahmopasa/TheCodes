#ifndef __ATM_H__
#define __ATM_H__

class ATM
{
public:
	ATM() = default;
	~ATM();

	const unsigned int& getATMBalanceAmount(void) const; // TODO: Implementation of getATMBalanceAmount method will be done in the future.
	void setATMBalanceAmount(const unsigned int&); // TODO: Implementation of setATMBalanceAmount method will be done in the future.

private:
	unsigned int ATMBalanceAmount{ 1'000'000 };
};

#endif // __ATM_H__