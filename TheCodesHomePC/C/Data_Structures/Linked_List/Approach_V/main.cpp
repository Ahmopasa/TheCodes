#include "StudentInfo.h"


static const char* getName()
{
	static const char* const nameList[80] = { "AHMET", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ELIZABETH", "AHMET", "ELLEN", "ELLEN", "ELLEN", "EPIPHANY", "EPPIE", "ETTA", "EULA", "FOREST", "FORD", "FOSTER", "FOX",
											"FOREST", "FORD", "FOSTER", "FOX", "EPIPHANY", "EPPIE", "ETTA", "EULA", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "EULA",
											"AHMET", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ELIZABETH", "AHMET", "ELLEN", "ELLEN", "ELLEN", "EPIPHANY", "EPPIE", "ETTA", "EULA", "FOREST", "FORD", "FOSTER", "FOX",
											"FOREST", "FORD", "FOSTER", "FOX", "EPIPHANY", "EPPIE", "ETTA", "EULA", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "EULA",
	};

	return nameList[rand() % 80];
}

static const char* getSurname()
{
	static const char* const surnameList[] = { "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON",
											  "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON",	"GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ"	,  "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA",
											  "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON",
											  "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON", "JOHNSON", "ABBESTEGE", "WILSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS",
											  "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON", "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE",
	};

	return surnameList[rand() % 80];
}

static const char* getCity()
{
	static const char* const cityList[] = { "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Colorado",
									 "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Louisiana", "Maine", "Maryland", "Massachusetts",
									 "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware",
									 "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Louisiana", "Maine", "Maryland", "Massachusetts", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware",
									 "Florida", "Georgia", "Hawaii", "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida"
	};

	return cityList[rand() % 80];
}

static void getDate(_counter* my_class, int total_size)
{
	int year;
	int year_leap;

	static const int daytabs[][13] = {
							{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
							{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	};

	static const char* const pmons[] = { "","Ocak","Subat","Mart","Nisan","Mayis","Haziran","Temmuz","Agustos","Eylul","Ekim","Kasim","Aralik" };

	for (int i = 0; i < total_size; i++)
	{
		year = rand() % (2020 - 1989 + 1) + 1989;
		year_leap = check_leap(year);
		my_class[i].calender.year = year;
		strcpy(my_class[i].calender.month, pmons[rand() % 12 + 1]);
		my_class[i].calender.day = daytabs[year_leap][rand() % 12 + 1];
	}


}
void CreateNodes(_counter* my_class, int total_size)
{

	for (int i = 0; i < total_size; i++)
	{


		my_class[i].index.ID = rand() % 10000 + 9000;
		my_class[i].index.average = ((double)rand() * (100. - 0.)) / (double)RAND_MAX + 0.;
		strcpy(my_class[i].index.name, getName());
		strcpy(my_class[i].index.surname, getSurname());
		strcpy(my_class[i].index.city, getCity());
		getDate(my_class, total_size);


	}

}

void ShoWNodes(_counter* my_class, int total_size)
{
	for (int i = 0; i < total_size; i++)
	{
		puts("*************************************************************");
		printf("ID: %d\n", my_class[i].index.ID);
		printf("Average: %.2lf\n", my_class[i].index.average);
		printf("Name: %s\n", my_class[i].index.name);
		printf("Surname: %s\n", my_class[i].index.surname);
		printf("City: %s\n", my_class[i].index.city);
		printf("Year: %d\n", my_class[i].calender.year);
		printf("Month: %s\n", my_class[i].calender.month);
		printf("Day: %d\n", my_class[i].calender.day);
		puts("*************************************************************");
	}
}

void SaveNodes(_counter* my_class, int total_size)
{
	FILE* fp = fopen("Results.txt", "w");
	if (!fp)
	{
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < total_size; i++)
	{
		fprintf(fp, "*************************************************************\n");
		fprintf(fp, "ID: %d\n", my_class[i].index.ID);
		fprintf(fp, "Average: %.2lf\n", my_class[i].index.average);
		fprintf(fp, "Name: %s\n", my_class[i].index.name);
		fprintf(fp, "Surname: %s\n", my_class[i].index.surname);
		fprintf(fp, "City: %s\n", my_class[i].index.city);
		fprintf(fp, "Year: %d\n", my_class[i].calender.year);
		fprintf(fp, "Month: %s\n", my_class[i].calender.month);
		fprintf(fp, "Day: %d\n", my_class[i].calender.day);
		fprintf(fp, "*************************************************************\n");
	}
	fclose(fp);
}