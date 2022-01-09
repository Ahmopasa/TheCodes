/*************** A DATA PLACE TO INCLUDE LIBRARIES *******************************/
#ifndef DATA_H
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

/*************** A DATA PLACE TO DEFINE MACROS ***********************************/
#define LeapStatus(y) ((y) % 4 == 0 && ((y) % 100 != 0) || (y) % 400 == 0)
#define DATA_H

/*************** A DATA PLACE TO DEFINE VARIEBLES ********************************/
typedef struct student {

	char month[15];
	char name[20];
	char surname[20];
	char city[20];

	int ID;
	int day;
	int year;
	double averageScore;

}student;

/*************** A DATA PLACE TO DEFINE UTILITY FUNCTIONS ************************/
#define _randy 	srand((unsigned int)(time(NULL)));

/* FUNCTION USED TO SORT THE LIST */
static int cmp_student_name(const void* source_1, const void* source_2);
static int cmp_student_surname(const void* source_1, const void* source_2);
static int cmp_student_ID(const void* source_1, const void* source_2);
static int cmp_student_Average(const void* source_1, const void* source_2);
static int cmp_student(const void* source_1, const void* source_2);

/* FUNCTION USED TO CREATE THE LIST */
int CreateList(student* personelInfo, int total_student);
int ShowList(student* personelInfo, int total_student);
int WriteToFile(student* personelInfo, int total_student);
void EmptyList(student* personelInfo, int total_student);

/*************** A DATA PLACE TO GET NAMES & SURNAMES & CITY NAMES ********************/
static const char* getName(void);
static const char* getSurname(void);
static const char* getCity(void);

/*************** A DATA PLACE TO GET CALENDER DATES ***********************************/





#endif

