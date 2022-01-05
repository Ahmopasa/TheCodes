#include "Patient.h"
#include <iostream>
#include <string>

Patient::Patient()
{
	std::cout << "Please, enter the name of the patient: ";
	std::getline(std::cin, name);
	std::cout << "Please, enter the surname of the patient: ";
	std::getline(std::cin, surname);
	std::cout << "Please, enter the address of the patient: ";
	std::getline(std::cin, address);
	std::cout << "Please, enter the age of the patient: ";
	std::cin >> age;
	std::cout << "Please, enter the ID of the patient: ";
	std::cin >> ID;
	std::cout << "Please, enter the contact number of the patient: ";
	std::cin >> contactNumber;
}

void Patient::ShowPatientInformation(void)
{
	std::cout << "Name          : " << name << std::endl;
	std::cout << "Surname       : " << surname << std::endl;
	std::cout << "Address       : " << address << std::endl;
	std::cout << "Age           : " << age << std::endl;
	std::cout << "ID            : " << ID << std::endl;
	std::cout << "Contact Number: " << contactNumber << std::endl;
}
