#pragma once
#include <string>

class Patient
{
public:
	Patient();
	void ShowPatientInformation(void);
private:
	int ID{};
	std::string name{};
	std::string surname{};
	int age{};
	std::string address{};
	int contactNumber{};
};

