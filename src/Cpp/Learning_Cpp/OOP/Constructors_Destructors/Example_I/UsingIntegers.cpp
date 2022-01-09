#include <iostream>

class SimpleClass
{

private:
	int x;
	int y;

public:

	SimpleClass(); 
	SimpleClass(const int, const int);
	SimpleClass(const SimpleClass&);
	SimpleClass& operator = (const SimpleClass&);

	~SimpleClass();


	void PlayClassMembers(int, int);
	int getValueX() const;
	int getValueY() const;

	void setValueX(int);
	void setValueY(int);



};

SimpleClass::SimpleClass()
{
	puts("Default Constructor was called. All parameters set to 0.");

	x = 0;
	y = 0;
}


SimpleClass::SimpleClass(const int value_1, const int value_2)
{
	std::cout << "Constructor that takes two parameters was called, which: " << value_1 << " and " << value_2 << std::endl;

	x = value_1;
	y = value_2;
}


	SimpleClass::SimpleClass(const SimpleClass & sampleClass)
	{
		printf("Copy constructor was called.\n");

		x = sampleClass.x;
		y = sampleClass.y;
	}

	SimpleClass& SimpleClass::operator=(const SimpleClass & sampleClass)
	{
		puts("Copy constructor called using operator overloading.");

		x = sampleClass.getValueX();
		y = sampleClass.getValueY();

		return *this;
	}






SimpleClass::~SimpleClass()
{
	puts("Deconstructor was called.");
}

void SimpleClass::PlayClassMembers(int value_1, int value_2)
{
	x = value_1;
		y = value_2;
}

int SimpleClass::getValueX() const
{
	return x;
}

int SimpleClass::getValueY() const
{
	return y;
}

void SimpleClass::setValueX(int value_1)
{
	x = value_1;
}

void SimpleClass::setValueY(int value_2)
{
	y = value_2;
}


int main()
{
	puts("*********************************************************");
	puts("Declaring student_1"); SimpleClass student_1;
	puts("*********************************************************");
	puts("Declaring student_2"); SimpleClass student_2(99, 100);
	puts("*********************************************************");
	printf("value of x of student_1: %d\n", student_1.getValueX());
	printf("value of y of student_1: %d\n", student_1.getValueY());
	printf("value of x of student_2: %d\n", student_2.getValueX());
	printf("value of y of student_2: %d\n", student_2.getValueY());

	puts("#########################################################");
	
	puts("Initialising student_3"); SimpleClass student_3 = student_1;
	puts("*********************************************************");
	puts("Declaring student_4"); SimpleClass student_4;
	puts("*********************************************************");
	puts("Assiging student_2 to student_4"); student_4 = student_2;
	puts("*********************************************************");
	printf("value of x of student_3: %d\n", student_3.getValueX());
	printf("value of y of student_3: %d\n", student_3.getValueY());
	printf("value of x of student_4: %d\n", student_4.getValueX());
	printf("value of y of student_4: %d\n", student_4.getValueY());
	puts("*********************************************************");

	student_4.PlayClassMembers(31, 32);
	printf("value of x of student_1 after changing student_4: %d\n", student_1.getValueX());
	printf("value of y of student_1 after changing student_4: %d\n", student_1.getValueY());
	printf("value of x of student_2 after changing student_4: %d\n", student_2.getValueX());
	printf("value of y of student_2 after changing student_4: %d\n", student_2.getValueY());
	printf("value of x of student_3 after changing student_4: %d\n", student_3.getValueX());
	printf("value of y of student_3 after changing student_4: %d\n", student_3.getValueY());
	printf("value of x of student_4 after changing student_4: %d\n", student_4.getValueX());
	printf("value of y of student_4 after changing student_4: %d\n", student_4.getValueY());
	puts("*********************************************************");


}