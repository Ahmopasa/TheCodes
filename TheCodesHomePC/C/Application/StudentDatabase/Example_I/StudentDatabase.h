#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define check_leap(year) ((year) % 4 == 0 && ((year) % 100 != 0 || (year) % 400 == 0))

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
	//date* calender;
}student;


