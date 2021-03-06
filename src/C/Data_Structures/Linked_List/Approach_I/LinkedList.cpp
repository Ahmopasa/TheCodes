#define _CRT_SECURE_NO_WARNINGS

#define check_leap(year) ((year) % 4 == 0 && ((year) % 100 != 0 || (year) % 400 == 0))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct linkedList {

	int datax;
	int ID;
	int year;
	int day;
	
	double average;
	
	char month[15];
	char name[20];
	char surname[20];
	char city[20];

	struct linkedList* nextPtr;
};

typedef struct linkedList linkedList;

const char* getName()
{
	static const char* const nameList[80] = { "AHMET", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ELIZABETH", "AHMET", "ELLEN", "ELLEN", "ELLEN", "EPIPHANY", "EPPIE", "ETTA", "EULA", "FOREST", "FORD", "FOSTER", "FOX",
											"FOREST", "FORD", "FOSTER", "FOX", "EPIPHANY", "EPPIE", "ETTA", "EULA", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "EULA",
											"AHMET", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ELIZABETH", "AHMET", "ELLEN", "ELLEN", "ELLEN", "EPIPHANY", "EPPIE", "ETTA", "EULA", "FOREST", "FORD", "FOSTER", "FOX",
											"FOREST", "FORD", "FOSTER", "FOX", "EPIPHANY", "EPPIE", "ETTA", "EULA", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "EULA",
	};

	return nameList[rand() % 80];
}

const char* getSurname()
{
	static const char* const surnameList[] = { "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON",
											  "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON",	"GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ"	,  "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA",
											  "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON",
											  "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON", "JOHNSON", "ABBESTEGE", "WILSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS",
											  "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON", "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE",
	};

	return surnameList[rand() % 80];
}

const char* getCity()
{
	static const char* const cityList[] = { "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Colorado",
									 "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Louisiana", "Maine", "Maryland", "Massachusetts",
									 "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware",
									 "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Louisiana", "Maine", "Maryland", "Massachusetts", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware",
									 "Florida", "Georgia", "Hawaii", "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida"
	};

	return cityList[rand() % 80];
}

void getDate(linkedList* head)
{
	linkedList* first = head;
	int year;
	int year_leap;
	int counter_date;

	static const int daytabs[][13] = {
							{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
							{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	};

	static const char* const pmons[] = { "","Ocak","Subat","Mart","Nisan","Mayis","Haziran","Temmuz","Agustos","Eylul","Ekim","Kasim","Aralik" };


	year = rand() % (2020 - 1989 + 1) + 1989;
	year_leap = check_leap(year);
	counter_date = rand() % 12 + 1;
	first->year = year;
	strcpy(first->month, pmons[counter_date]);
	first->day = daytabs[year_leap][counter_date];

}

int ShowList(linkedList* head)
{
	if (head == NULL)
		exit(EXIT_FAILURE);
	
	linkedList* first = head;
	int counter = 0;
	
	puts("*************************************************************");
	puts(" #    ID   AVERAGE NAME       SURNAME    CITY          YEAR MONTH   DAY");
	for (; first != NULL; first = first->nextPtr, counter++)
		printf("%03d.  %.4d %-7.2lf %-10s %-10s %-13s %d %-7s %d\n", counter, first->ID, first->average, first->name, first->surname, first->city, first->year, first->month, first->day);

	printf("(Total [%d] member exist.)\n\n\n", counter);

	return counter;
}

linkedList* AppendToRight(linkedList** head)
{
		if (*head == NULL)
		{
			*head = (linkedList*)malloc(sizeof(linkedList));
			if (*head == NULL)
				exit(EXIT_FAILURE);
			
			(*head)->datax = rand() % 101;
			(*head)->ID = rand() % 1001 + 101;
			(*head)->average = ((double)rand() * (100. - 0.)) / (double)RAND_MAX + 0.;
			strcpy((*head)->city, getCity());
			getDate(*head);
			strcpy((*head)->name, getName());
			strcpy((*head)->surname, getSurname());
			(*head)->nextPtr = NULL;
			return *head;
		}

		else
		{
			linkedList* first = *head;
			linkedList* newNode = (linkedList*)malloc(sizeof(linkedList));
			if (newNode == NULL)
				exit(EXIT_FAILURE);
			
			newNode->ID = rand() % 1001 + 101;
			newNode->average = ((double)rand() * (100. - 0.)) / (double)RAND_MAX + 0.;
			strcpy(newNode->city, getCity());
			getDate(newNode);
			strcpy(newNode->name, getName());
			strcpy(newNode->surname, getSurname());
			newNode->datax = rand() % 101;
			newNode->nextPtr = NULL;

			for (; first->nextPtr != NULL; first = first->nextPtr)
				;
			
			first->nextPtr = newNode;
			
			return *head;
		}
		return NULL;
}

linkedList* AppendToLeft(linkedList** head)
{
		if (*head == NULL)
		{
			*head = (linkedList*)malloc(sizeof(linkedList));
			if (*head == NULL)
				exit(EXIT_FAILURE);
			
			(*head)->datax = rand() % 101;
			(*head)->ID = rand() % 1001 + 101;
			(*head)->average = ((double)rand() * (100. - 0.)) / (double)RAND_MAX + 0.;
			strcpy((*head)->city, getCity());
			getDate(*head);
			strcpy((*head)->name, getName());
			strcpy((*head)->surname, getSurname());
			(*head)->nextPtr = NULL;
			
			return *head;
		}

		else
		{
			linkedList* newNode = (linkedList*)malloc(sizeof(linkedList));
			if (newNode == NULL)
				exit(EXIT_FAILURE);

			newNode->ID = rand() % 1001 + 101;
			newNode->average = ((double)rand() * (100. - 0.)) / (double)RAND_MAX + 0.;
			strcpy(newNode->city, getCity());
			getDate(newNode);
			strcpy(newNode->name, getName());
			strcpy(newNode->surname, getSurname());
			newNode->datax = rand() % 101;

			newNode->nextPtr = *head;
			
			return newNode;
		}

		return NULL;
}

linkedList* AddAfterTheLastNode(linkedList** head, int total_amount)
{
	fprintf(stdout, "%d new nodes will be added to the list. So, the list will enlarge rightward...\n", total_amount);
	
	linkedList* first = *head;
	int i;
	for (i = 0; i < total_amount; i ++)
		first = AppendToRight(&first);
	
	return first;
}

linkedList* AddBeforeTheFirstNode(linkedList** head, int total_amount)
{
	fprintf(stdout, "%d new nodes will be added to the list. So, the list will enlarge leftward...\n", total_amount);
	
	linkedList* first = *head;
	int i;
	for (i = 0; i < total_amount; i++)
		first = AppendToLeft(&first);
	
	return first;
}

linkedList* AddBeforeTheNodeX(linkedList** head, int tip, int tall)
{
	fprintf(stdout, "The node will be found via its ID.\n");

	linkedList* first = *head;
	linkedList* index = first->nextPtr;
	
	for (;first != NULL && first->ID != tip; first = first->nextPtr)
		;

	for (;index != NULL && index->ID != tall; index = index->nextPtr)
		;

	if (first != NULL && index != NULL)
	{
		fprintf(stdout, "A new node will be added between [%d] and [%d]. nodes.\n", first->ID, index->ID);

		linkedList* newNode = (linkedList*)malloc(sizeof(linkedList));
		if (newNode == NULL)
			exit(EXIT_FAILURE);

		newNode->ID = 999;
		newNode->average = ((double)rand() * (100. - 0.)) / (double)RAND_MAX + 0.;
		strcpy(newNode->city, getCity());
		getDate(newNode);
		strcpy(newNode->name, getName());
		strcpy(newNode->surname, getSurname());
		newNode->datax = rand() % 101;
		newNode->nextPtr = NULL;

		first->nextPtr = newNode;
		newNode->nextPtr = index;

	}

	return *head;
}

linkedList* RemoveBeforeTheNodeX(linkedList** head, int tip)
{
	fprintf(stdout, "The node will be found via its ID.\n");

	linkedList* first = *head;
	linkedList* index = first->nextPtr;
	linkedList* second = index->nextPtr;

	if (first == NULL || index == NULL || second == NULL)
		exit(EXIT_FAILURE);
	
	else
	{
		for (; index != NULL && index->ID != tip; index = index->nextPtr, first = first->nextPtr, second = second->nextPtr)
			;

		fprintf(stdout, "The new node that will be removed has ID of [%d].\n", index->ID);
		first->nextPtr = second;

		index->nextPtr = NULL;
		free(index);

		return *head;
	}

}

int main()
{
	linkedList* first = NULL;
	first = AddAfterTheLastNode(&first, 35);

	ShowList(first);
}




