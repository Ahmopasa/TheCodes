#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "Data.h"

/*************** A DATA PLACE TO DEFINE UTILITY FUNCTIONS******************************/

/*************** A DATA PLACE TO SORT LIST *********************************************/
static int cmp_student_name(const void* source_1, const void* source_2)
{
	const student* indexPtr1 = (const student*)source_1;
	const student* indexPtr2 = (const student*)source_2;

	return strcmp(indexPtr1->name, indexPtr2->name);
}

static int cmp_student_surname(const void* source_1, const void* source_2)
{
	const student* indexPtr1 = (const student*)source_1;
	const student* indexPtr2 = (const student*)source_2;

	return strcmp(indexPtr1->surname, indexPtr2->surname);
}

static int cmp_student_ID(const void* source_1, const void* source_2)
{
	const student* indexPtr1 = (const student*)source_1;
	const student* indexPtr2 = (const student*)source_2;

	return (int)(indexPtr1->ID - indexPtr2->ID);
}

static int cmp_student_Average(const void* source_1, const void* source_2)
{
	const student* indexPtr1 = (const student*)source_1;
	const student* indexPtr2 = (const student*)source_2;

	return (int)(indexPtr1->averageScore - indexPtr2->averageScore);
}

static int cmp_student(const void* source_1, const void* source_2)
{

	int cmp_result = cmp_student_Average(source_1, source_2);
	if (cmp_result)
		return cmp_result;

	cmp_result = cmp_student_ID(source_1, source_2);
	if (cmp_result)
		return cmp_result;

	cmp_result = cmp_student_name(source_1, source_2);
	if (cmp_result)
		return cmp_result;

	cmp_result = cmp_student_surname(source_1, source_2);
	if (cmp_result)
		return cmp_result;

	return 0;
}
/*************** A DATA PLACE TO CREATE LIST *********************************************/
int CreateList(student* personelInfo, int  total_student)
{
	_randy;
	static const int daytabs[][13] = {
						{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
						{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	};

	static const char* const pmons[] = { "","Ocak","Subat","Mart","Nisan","Mayis","Haziran","Temmuz","Agustos","Eylul","Ekim","Kasim","Aralik" };

	int check_leap_year;

	int counter = 0;
	for (int i = 0; i < total_student; i++)
	{
		strcpy(personelInfo[i].name, getName());
		strcpy(personelInfo[i].surname, getSurname());
		strcpy(personelInfo[i].city, getCity());
		personelInfo[i].averageScore = ((double)rand() * (100. - 0.)) / (double)RAND_MAX + 0.;
		personelInfo[i].ID = rand() % 10000 + 9000;
		personelInfo[i].year = rand() % (2020 - 1989 + 1) + 1989;
		check_leap_year = LeapStatus(personelInfo[i].year);
		strcpy(personelInfo[i].month, pmons[rand() % 12 + 1]);
		personelInfo[i].day = daytabs[check_leap_year][rand() % 12 + 1];
		counter++;
	}
	if (counter == (total_student - 1))
	{
		return 1;
	}
	else
		return 0;
}

/*************** A DATA PLACE TO SHOW LIST *********************************************/
int ShowList(student* personelInfo, int total_student)
{
	int counter = 0;
	for (int i = 0; i < total_student; i++)
	{
		printf("%d.) %5d %.2lf %10s %10s %15s %d %10s %d\n", i,personelInfo[i].ID, personelInfo[i].averageScore, personelInfo[i].name, personelInfo[i].surname, personelInfo->city, personelInfo->day, personelInfo->month, personelInfo->year);
		counter++;

	}
	if (counter == (total_student - 1))
	{
		return 1;
	}
	else
		return 0;
}
/*************** A DATA PLACE TO WRITE LIST TO FILE *************************************/
int WriteToFile(student* personelInfo, int total_student)
{
	int counter = 0;
	FILE* fp = fopen("ExamScoreTable.txt", "w");
	if (!fp)
	{
		puts("File could not be opened\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < total_student; i++)
	{
		fprintf(fp, "%d.) %d %.2lf %s %s %s %d %s %d\n", i+1, personelInfo[i].ID, personelInfo[i].averageScore, personelInfo[i].name, personelInfo[i].surname, personelInfo->city, personelInfo->day, personelInfo->month, personelInfo->year);
		counter++;
	}
	fclose(fp);

	if (counter == (total_student - 1))
	{
		return 1;
	}
	else
		return 0;
}

/*************** A DATA PLACE TO MAKE LIST EMPTY ***************************************/
void EmptyList(student* personelInfo, int total_student)
{
	void* free_personelInfo = (void*)personelInfo;
	free(free_personelInfo);

}


/*************** A DATA PLACE TO GET NAMES & SURNAMES & CITY NAMES ********************/
static const char* getName(void)
{
	static const char* nameList[] = { "AHMET", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ELIZABETH", "AHMET", "ELLEN", "ELLEN", "ELLEN", "EPIPHANY", "EPPIE", "ETTA", "EULA", "FOREST", "FORD", "FOSTER", "FOX",
										"FOREST", "FORD", "FOSTER", "FOX", "EPIPHANY", "EPPIE", "ETTA", "EULA", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "EULA",
										"AHMET", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ELIZABETH", "AHMET", "ELLEN", "ELLEN", "ELLEN", "EPIPHANY", "EPPIE", "ETTA", "EULA", "FOREST", "FORD", "FOSTER", "FOX",
										"FOREST", "FORD", "FOSTER", "FOX", "EPIPHANY", "EPPIE", "ETTA", "EULA", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "EULA",
	};

	return nameList[rand() % 80];
}

static const char* getSurname(void)
{
	static const char* surnameList[] = { "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON",
												  "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON",	"GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ"	,  "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA",
												  "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON",
												  "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON", "JOHNSON", "ABBESTEGE", "WILSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS",
												  "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON", "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE",
	};

	return surnameList[rand() % 80];
}

static const char* getCity(void)
{
	
	static const char* cityList[] = { "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Colorado",
										 "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Louisiana", "Maine", "Maryland", "Massachusetts",
										 "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware",
										 "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Louisiana", "Maine", "Maryland", "Massachusetts", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", 
										 "Florida", "Georgia", "Hawaii", "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida"
	};

	return cityList[rand() % 80];
}

/*************** A DATA PLACE TO GET CALENDERDATES ****************************************/

















