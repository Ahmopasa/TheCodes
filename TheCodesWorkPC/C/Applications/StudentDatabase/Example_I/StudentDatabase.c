#include "StudentDatabase.h"

int main()
{
	srand((unsigned int)time(NULL));

	static const char nameList[][20] = { "AHMET", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ELIZABETH", "AHMET", "ELLEN", "ELLEN", "ELLEN", "EPIPHANY", "EPPIE", "ETTA", "EULA", "FOREST", "FORD", "FOSTER", "FOX",
											"FOREST", "FORD", "FOSTER", "FOX", "EPIPHANY", "EPPIE", "ETTA", "EULA", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "EULA",
											"AHMET", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ELIZABETH", "AHMET", "ELLEN", "ELLEN", "ELLEN", "EPIPHANY", "EPPIE", "ETTA", "EULA", "FOREST", "FORD", "FOSTER", "FOX",
											"FOREST", "FORD", "FOSTER", "FOX", "EPIPHANY", "EPPIE", "ETTA", "EULA", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "EULA",
	};

	static const char surnameList[][20] = { "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON",
											  "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON",	"GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ"	,  "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA",
											  "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON",
											  "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON", "JOHNSON", "ABBESTEGE", "WILSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS",
											  "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON", "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE",
	};

	static const char cityList[][20] = { "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Colorado",
									 "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Louisiana", "Maine", "Maryland", "Massachusetts",
									 "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware",
									 "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Louisiana", "Maine", "Maryland", "Massachusetts", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware",
									 "Florida", "Georgia", "Hawaii", "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida"
	};

	static const int daytabs[][13] = {
								{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
								{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	};

	static const char* const pmons[] = { "","Ocak","Subat","Mart","Nisan","Mayis","Haziran","Temmuz","Agustos","Eylul","Ekim","Kasim","Aralik" };

	student index[2] = { 0 };
	date calender[2] = { 0 };
	int year;
	int year_leap;

	//puts("*************************************************************");
	//printf("%d %.2lf %s %s from %s came in %d %s %d\n", rand() % 10000 + 9000, ((double)rand() * (100. - 0.)) / (double)RAND_MAX + 0., nameList[counter_name], surnameList[counter_name], cityList[counter_name], daytabs[year_leap][counter_date], pmons[counter_date], year);
	//puts("*************************************************************");

	for (int i = 0; i < 2; i++)
	{
		year = rand() % (2020 - 1989 + 1) + 1989;
		year_leap = check_leap(year);

		index[i].ID = rand() % 10000 + 9000;
		index[i].average = ((double)rand() * (100. - 0.)) / (double)RAND_MAX + 0.;
		strcpy(index[i].name, nameList[rand() % 80]);
		strcpy(index[i].surname, surnameList[rand() % 80]);
		strcpy(index[i].city, cityList[rand() % 80]);
		calender[i].year = year;
		strcpy(calender[i].month, pmons[rand() % 12 + 1]);
		calender[i].day = daytabs[year_leap][rand() % 12 + 1];
	}

	for (int i = 0; i < 2; i++)
	{
		puts("*************************************************************");
		printf("ID: %d\n", index[i].ID);
		printf("Average: %.2lf\n", index[i].average);
		printf("Name: %s\n", index[i].name);
		printf("Surname: %s\n", index[i].surname);
		printf("City: %s\n", index[i].city);
		printf("Year: %d\n", calender[i].year);
		printf("Month: %s\n", calender[i].month);
		printf("Day: %d\n", calender[i].day);
		puts("*************************************************************");
	}
}