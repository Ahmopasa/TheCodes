#ifndef HEADER_H
#define HEADER_H
/*A PLACE TO DEFINE MACROS*/
#define check_leap(year) ((year) % 4 == 0 && ((year) % 100 != 0 || (year) % 400 == 0))
#define _CRT_SECURE_NO_WARNINGS

/*A PLACE TO INCLUDE LIBS.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/*A PLACE TO DECLARE GLOBAL VARIABLES*/
typedef struct
{
	int day;
	int year;
	char month[15];
}date;
typedef struct
{
	int ID;
	double average;
	char name[20];
	char surname[20];
	char city[20];
}student;
typedef struct
{
	date calender;
	student index;
}_counter;

/*A PLACE TO DECLARE NON-GLOBAL FUNCTIONS*/
static void getDate(_counter* my_class, int total_size);
static const char* getCity();
static const char* getSurname();
static const char* getName();

/*A PLACE TO DECLARE GLOBAL FUNCTIONS*/
void CreateNodes(_counter*, int);
void ShoWNodes(_counter*, int);
void SaveNodes(_counter*, int);
#endif
