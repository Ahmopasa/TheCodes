#pragma once
#include "Thing.h"

#include <string>

class Human : public Thing
{
public:
	Human() : m_RunCapability{ 1 }, m_Health{ 10 }
	{
		m_Name = "John";

		std::cout << m_Name << " has " << m_Health << " points now. He can run at the speed of " << m_RunCapability << "mph.\n";
	}

	virtual void speak() 
	{
		std::cout << m_Name << " speaks now: " << m_Health << " health points I have and " << m_RunCapability << " points I can speed at.\n";

		m_Health -= m_RunCapability;
	}
	virtual void run()
	{
		std::cout << m_Name << " started running... Currently, he is running at the speed of " << m_RunCapability << "mph.\n";

		m_Health -= m_RunCapability;
	}
	virtual void die()
	{
		std::cout << m_Name << " has " << m_Health << " left before he/she dies...\n";
	}

	int getHealthStatus() { return m_Health; }

private:
	int m_RunCapability;
	int m_Health;
	std::string m_Name;

};

