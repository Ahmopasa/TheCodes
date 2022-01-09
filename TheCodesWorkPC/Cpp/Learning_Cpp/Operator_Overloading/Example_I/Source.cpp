#include "LearningOV.h"


int main()
{
	std::cout << "##########################################################" << std::endl << std::endl;

	LearningCpp student_1{}; //Constructor was called.
	student_1.showInfo();

	LearningCpp student_2{student_1}; //Copy Constructor was called.
	student_2.showInfo();

	LearningCpp student_3{"Ahmet", 25, 95.6}; //Constructor was called.
	student_3.showInfo();

	LearningCpp student_4; //Constructor was called.
	student_4 = student_3; //Copy Assignment was called
	student_4.showInfo();

	std::cout << "##########################################################" << std::endl;
	std::cout << "##########################################################" << std::endl;

	// std::vector<LearningCpp> myClass;
	// ShowAccount(CreateAccount(myClass));


	// LearningCpp myClass[3]; // Constructor was called 3 times.
	// myClass[0] = student_1; // Copy Assignment was called
	// myClass[1] = student_2; // Copy Assignment was called
	// myClass[2] = student_3; // Copy Assignment was called

	std::cout << "The Address of student_1 : " << &student_1 << std::endl;
	std::cout << "The Address of student_2 : " << &student_2 << std::endl;
	std::cout << "The Address of student_3 : " << &student_3 << std::endl;
	std::cout << "The Address of student_4 : " << &student_4 << std::endl << std::endl;


	LearningCpp myClass[4] = {std::move(student_1), std::move(student_2), std::move(student_3)}; // Move Constructor was called 3 times.
	myClass[3] = std::move(student_4); // Constructor was called, then Move Assignment was called.

	for (size_t i = 0; i < 4; i++)
	{
		std::cout << "The Address of " << i << "th element : " << &myClass[i] << std::endl; 
	}
	

	// LearningCpp myClass[3] = {student_4, student_3, student_2}; // Copy Constructor was called 3 times.

	std::cout << "##########################################################" << std::endl;

	// std::cout << "Comparing of two class;" << std::endl;
	// std::cout << (student_1 == student_3) << std::endl;

	// std::cout << "Concatentate of two class;" << std::endl;
	// std::cout << (student_4 + student_3) << std::endl;

	// std::cout << "Lower Casing a class;" << std::endl;
	// std::cout << -student_3 << std::endl;

	// LearningCpp student_5{};
	// std::cin >> student_5;

	std::cout << "##########################################################" << std::endl;
	std::cout << "COUNTERS\n";
	std::cout << "Constructor : " << LearningCpp::ctrConstructor << std::endl; 
	std::cout << "Copy Constructor : " << LearningCpp::ctrCopyConstructor << std::endl; 
	std::cout << "Copy Assignment : " << LearningCpp::ctrCopyAssignment << std::endl; 
	std::cout << "Move Constructor : " << LearningCpp::ctrMoveConstructor << std::endl; 
	std::cout << "Move Assignment : " << LearningCpp::ctrMoveAssignment << std::endl;
	std::cout << "##########################################################" << std::endl;
	std::cout << "##########################################################" << std::endl << std::endl;


	return 0;
}

