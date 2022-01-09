#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class SimplePointerClass
{

private:
	char* name;
	int age;


public:

	SimplePointerClass();
	SimplePointerClass(const char*, int);
	SimplePointerClass(const SimplePointerClass&);
	SimplePointerClass& operator = (const SimplePointerClass&);

	~SimplePointerClass();


	void PlayClassMembers(const char*, int);
	char* getName() const;
	int getAge() const;

	void setName(const char*);
	void setAge(int);


};


int main()
{
	puts("**************************************************************");
	puts("student_1 was created with default parameters."); SimplePointerClass student_1;
	puts("**************************************************************");
	puts("student_2 was created with random parameters."); SimplePointerClass student_2 = {"Ahmet", 26};
	puts("**************************************************************");
	printf("parameters of student_1: name is %s and age is %d\n", student_1.getName(), student_1.getAge());
	printf("parameters of student_2: name is %s and age is %d\n", student_2.getName(), student_2.getAge());
	puts("**************************************************************");
	puts("student_3 was created with parameters of student_1."); SimplePointerClass student_3 = student_1;
	puts("**************************************************************");
	puts("student_4 was created with default parameters."); SimplePointerClass student_4;
	puts("parameters of student_2 assigned to student_4"); student_4 = student_2;
	puts("**************************************************************");
	printf("parameters of student_3: name is %s and age is %d\n", student_3.getName(), student_3.getAge());
	printf("parameters of student_4: name is %s and age is %d\n", student_4.getName(), student_4.getAge());
	puts("**************************************************************");
	return 0;
	puts("**************************************************************");
}

SimplePointerClass::SimplePointerClass()
{
	puts("Default constructor was called. Members were set to \"NoName\" and 0, respectively.");
	name = new char[25];
	if (name != nullptr) {
		strcpy(name, "NoName");
		age = 0;
	}
	else
	{
		puts("No enough memory for default construction.");
		exit(1);
	}
}

SimplePointerClass::SimplePointerClass(const char* tempName, int tempAge)
{
	puts("Constructor, that takes two parameter, was called.");
	printf("Parameters set to the following parameters, respectively: %s and %d\n", tempName, tempAge);

	name = new char[25];
	if (name != nullptr) {
		strcpy(name, tempName);
		age = tempAge;
	}
	else
	{
		puts("No enough memory for construction that takes two parameters.");
		exit(1);
	}
}

SimplePointerClass::SimplePointerClass(const SimplePointerClass& tempClass)
{
	puts("Copy constructor was called.");

	name = new char[25];
	if (name != nullptr) {
		strcpy(name, tempClass.name);
		age = tempClass.age;
	}
	else
	{
		puts("No enough memory for copy construction.");
		exit(1);
	}
}

SimplePointerClass& SimplePointerClass::operator = (const SimplePointerClass& tempClass)
{
	puts(" ' = ' operator was overloaded.");

	name = new char[25];
	if (name != nullptr) {
		strcpy(name, tempClass.name);
		age = tempClass.age;
	}
	else
	{
		puts("No enough memory for overloading ' = ' operator.");
		exit(1);
	}

	return *this;
}

SimplePointerClass::~SimplePointerClass()
{
	puts("Deconstructor was called.");

	delete[]name;
}

void SimplePointerClass::PlayClassMembers(const char* tempName, int tempAge)
{
	strcpy(name, tempName);
	age = tempAge;
}

char* SimplePointerClass::getName() const
{
	return name;
}

int SimplePointerClass::getAge() const
{
	return age;
}

void SimplePointerClass::setName(const char* tempName)
{
	strcpy(name, tempName);
}

void SimplePointerClass::setAge(int tempAge)
{
	age = tempAge;
}
