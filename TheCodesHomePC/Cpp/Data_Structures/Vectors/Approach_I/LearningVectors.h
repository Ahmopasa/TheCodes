#ifndef LEARNINGVECTORS_H
#define LEARNINGVECTORS_H
//#define DebugMessages // Used to activate debugging messages. ( Make it uncomment )

/******************************* A Place To Define Related Macros ******************************/
#ifdef  DebugMessages
#define DebugMessage_CallingConstructor std::cout << "Constructor was Called!" << std::endl
#define DebugMessage_CallingDeconstructor std::cout << "Deconstruction was Called!" << std::endl
#else
#define DebugMessage_CallingConstructor
#define DebugMessage_CallingDeconstructor
#endif

/******************************* A Place To Define Related Libraries ***************************/
#include <iostream>
#include <fstream>
#include <time.h>
#include <ctype.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

/******************************* A Place To Define Global Variables *****************************/

/*
#  Has two Constructor # 
-> Default Constructor: Initialise members randomly based on pre-saved values.
-> Overloaded Constructor: A variable for every member should be passed.
*/
class Person {
public:
	Person();

	Person(std::string&, std::string&, std::string&, std::string&, std::string&, std::string&, std::string&, std::string&);

	int getID()const; 

	double getAverage()const;

	std::string getName()const;

	std::string getSurname()const; 

	std::string getCity()const; 

	int getDay()const;
	std::string getMonth()const;
	int getYear()const;

private:
	int ID;
	int day;
	int year;

	double average;

	std::string name;
	std::string surname;
	std::string city;
	std::string month;

private:
	void setID(std::string&);
	void setAverage(std::string&);
	void setName(std::string&);
	void setSurname(std::string&);
	void setCity(std::string&);
	void setDates(std::string&, std::string&, std::string&);
};

/******************************* A Place To Declare Global Functions *******************************/
//An object is being created based on random values per member.
void fillVectorRandomly(std::vector<Person>&, const int&); 

//An object is being created based on the values saved in the respective text files. 
void fillVectorViaText(std::vector<Person>&); 

void showVector(const std::vector<Person>&);

void saveVector(const std::vector<Person>&);

void copyVector(const std::vector<Person>&, std::vector<Person>&);

//Sort the vector according to the elements' ID values using std::sort.
void sortVectorByID(std::vector<Person>&); 

//Sort the vector according to the elements' Average values using std::sort.
void sortVectorByAverage(std::vector<Person>&); 

//Sort the vector according to the elements' Name values using std::sort.
void sortVectorByName(std::vector<Person>&); 

//Sort the vector according to the elements' Surname values using std::sort.
void sortVectorBySurname(std::vector<Person>&); 

//Sort the vector according to the elements' City values using std::sort.
void sortVectorByCity(std::vector<Person>&); 

//Sort the vector according to the elements' Day values using std::sort.
void sortVectorByDay(std::vector<Person>&); 

//Sort the vector according to the elements' Month values using std::sort.
void sortVectorByMonth(std::vector<Person>&); 

//Sort the vector according to the elements' Year values using std::sort.
void sortVectorByYear(std::vector<Person>&); 

// Sort the vector according to the elements' ID, then Average, then Name, then Surname, etc... using std::sort.
void sortVectorByDetail(std::vector<Person>&); 

#endif // !LEARNINGVECTORS_H
