#include "LearningVectors.h"

int main()
{
	std::vector<Person> my_student_list{};

	//fillVectorRandomly(my_student_list, 10);
	//fillVectorViaText(my_student_list);
	//showVector(my_student_list);
	//saveVector(my_student_list);
	sortVectorByDetail(my_student_list);
	//showVector(my_student_list);
	sortVectorByAverage(my_student_list);
	//showVector(my_student_list);

	std::getchar();

}