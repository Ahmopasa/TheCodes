#include <iostream>
#include "Patient.h"

int main()
{

	std::cout << "Welcome To The Hospital Registration System\n";
	std::cout << "Here, you will be able to register new people to get the treatment they need.\n";

	Patient patientOne{};

	patientOne.ShowPatientInformation();

	return 0;
}