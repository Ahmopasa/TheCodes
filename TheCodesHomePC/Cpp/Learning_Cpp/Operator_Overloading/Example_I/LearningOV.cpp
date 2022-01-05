#include "LearningOV.h"

void LearningCpp::showInfo()
{
	std::cout << "At the address of " << this << std::endl;
	if (!this->a)
	{
		std::cout << "char*  a is a nullptr" << std::endl;
		std::cout << "int    x => " << x << std::endl;
		std::cout << "double y => " << y << std::endl << std::endl;
	}
	else
	{
		std::cout << "Member Variable a => " << a << std::endl;
		std::cout << "Member Variable x => " << x << std::endl;
		std::cout << "Member Variable y => " << y << std::endl << std::endl;
	}
}

unsigned int LearningCpp::ctrConstructor{};
unsigned int LearningCpp::ctrCopyConstructor{};
unsigned int LearningCpp::ctrCopyAssignment{};
unsigned int LearningCpp::ctrMoveConstructor{};
unsigned int LearningCpp::ctrMoveAssignment{};

std::vector<LearningCpp>&  CreateAccount(std::vector<LearningCpp>& myLessons)
{
	for (size_t i = 0; i < 10;i++)
	{
		LearningCpp lesson1{  };
		myLessons.push_back(lesson1); 
	}

    return myLessons;
}

void ShowAccount(const std::vector<LearningCpp>& myLessons)
{
	for (const auto& temp : myLessons)
	{
		std::cout << temp;
	}
}