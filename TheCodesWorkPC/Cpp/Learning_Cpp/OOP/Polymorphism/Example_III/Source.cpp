#include <iostream>

class Human
{
public:
	Human() : m_Feet(2), m_Eyes(2) { printf("Our human being has born with %d feet and %d eyes.\n", m_Feet, m_Eyes); };
	~Human() { printf("Our human being is dead now.\n"); };

	int getFeet() { return m_Feet; }
	int getEyes() { return m_Eyes; }

	virtual void PrintFeatures() { printf("Total Feet: %d\nTotal Eyes: %d\n", m_Feet, m_Eyes); }

private:
	int m_Feet;
	int m_Eyes;
};


class Child : public Human
{
public:
	Child() : m_Job("NoJobYet"), m_Sexuality("Male") { printf("Child has born. It is %s and his/her job is %s.\n", m_Sexuality, m_Job); };
	~Child() { printf("Our child is is dead now.\n"); };

	char* getJobAffinity() { return m_Job; }
	char* getSexAffinity() { return m_Sexuality; }

	void PrintFeatures() { printf("Job Status: %s\nSexual Status: %s\n", m_Job, m_Sexuality); }


private:

	char m_Job[15];
	char m_Sexuality[15];

};


int main()
{
	puts("*****************************************");
	Human* human_1;
	puts("*****************************************");
	Child child_1;
	puts("*****************************************");
	human_1 = &child_1;
	puts("*****************************************");
	human_1->PrintFeatures();
	puts("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	child_1.PrintFeatures();
	puts("#########################################");


	return 0;
}