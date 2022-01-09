/**************************A PLACE TO INCLUDE LIBS.**************************/
#define _CRT_SECURE_NO_WARNINGS
#include "Database.h"

/**************************A PLACE TO DEFINE MACROS**************************/
#define check_leap(year) ((year) % 4 == 0 && ((year) % 100 != 0 || (year) % 400 == 0))

/********************A PLACE TO DECLARE GLOBAL VARIABLES*********************/
typedef enum SORT
{
	EMPTY, SORT_BY_ID, SORT_BY_SCORE, SORT_BY_NAME, SORT_BY_SURNAME, SORT_BY_CITY, SORT_BY_YEAR, SORT_BY_MONTH, SORT_BY_DAY, SORT_BY_DEEPLY

}SORT;

/**************************A PLACE TO DEFINE NON-GLOBAL FUNCTIONS**************************/
// A Random Name Generator
PRIVATE const char* getName()
{
	static const char* const nameList[80] = { "AHMET", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ELIZABETH", "AHMET", "ELLEN", "ELLEN", "ELLEN", "EPIPHANY", "EPPIE", "ETTA", "EULA", "FOREST", "FORD", "FOSTER", "FOX",
											"FOREST", "FORD", "FOSTER", "FOX", "EPIPHANY", "EPPIE", "ETTA", "EULA", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "EULA",
											"AHMET", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ELIZABETH", "AHMET", "ELLEN", "ELLEN", "ELLEN", "EPIPHANY", "EPPIE", "ETTA", "EULA", "FOREST", "FORD", "FOSTER", "FOX",
											"FOREST", "FORD", "FOSTER", "FOX", "EPIPHANY", "EPPIE", "ETTA", "EULA", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "EULA",
	};

	return nameList[rand() % 80];
}

// A Random Surname Generator
PRIVATE const char* getSurname()
{
	static const char* const surnameList[] = { "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON",
											  "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON",	"GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ"	,  "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA",
											  "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON",
											  "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON", "JOHNSON", "ABBESTEGE", "WILSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS",
											  "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON", "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE",
	};

	return surnameList[rand() % 80];
}

// A Random City Name Generator
PRIVATE const char* getCity()
{
	static const char* const cityList[] = { "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Colorado",
									 "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Louisiana", "Maine", "Maryland", "Massachusetts",
									 "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware",
									 "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Louisiana", "Maine", "Maryland", "Massachusetts", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware",
									 "Florida", "Georgia", "Hawaii", "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida"
	};

	return cityList[rand() % 80];
}

// A Random Date Generator (WIP)
PRIVATE void getDate(void* voidPtr, int total_size)
{
	int year;
	int year_leap;
	int counter_date;

	LLSTUDENT* my_class = (LLSTUDENT*)voidPtr;

	static const int daytabs[][13] = {
							{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
							{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	};

	static const char* const pmons[] = { "","Ocak","Subat","Mart","Nisan","Mayis","Haziran","Temmuz","Agustos","Eylul","Ekim","Kasim","Aralik" };

	for (int i = 0; i < total_size; i++)
	{
		year = rand() % (2020 - 1989 + 1) + 1989;
		year_leap = check_leap(year);
		counter_date = rand() % 12 + 1;
		my_class[i].index.year = year;
		strcpy(my_class[i].index.month, pmons[counter_date]);
		my_class[i].index.day = daytabs[year_leap][counter_date];
	}
}

// SORTING FUNCTION BY NAME
PRIVATE int cmp_student_name(const void* voidPtr, const void* _voidPtr)
{
	const LLSTUDENT* source1 = (const LLSTUDENT*)voidPtr;
	const LLSTUDENT* source2	= (const LLSTUDENT*)_voidPtr;
	return strcmp(source1->index.name, source2->index.name);
}

// SORTING FUNCTION BY SURNAME
PRIVATE int cmp_student_surname(const void* voidPtr, const void* _voidPtr)
{
	const LLSTUDENT* source1 = (const LLSTUDENT*)voidPtr;
	const LLSTUDENT* source2 = (const LLSTUDENT*)_voidPtr;
	return strcmp(source1->index.name, source2->index.name);
}

// SORTING FUNCTION BY ID
PRIVATE int cmp_student_ID(const void* voidPtr, const void* _voidPtr)
{
	const LLSTUDENT* source1 = (const LLSTUDENT*)voidPtr;
	const LLSTUDENT* source2 = (const LLSTUDENT*)_voidPtr;
	return (int)(source1->index.ID - source2->index.ID);
}

// SORTING FUNCTION BY AVERAGE SCORE
PRIVATE int cmp_student_Average(const void* voidPtr, const void* _voidPtr)
{
	const LLSTUDENT* source1 = (const LLSTUDENT*)voidPtr;
	const LLSTUDENT* source2 = (const LLSTUDENT*)_voidPtr;
	return (int)(source1->index.average - source2->index.average);
}		   

// SORTING FUNCTION DETAILED.
PRIVATE int cmp_student(const void* voidPtr, const void* _voidPtr)
{
	const LLSTUDENT* source1 = (const LLSTUDENT*)voidPtr;
	const LLSTUDENT* source2 = (const LLSTUDENT*)_voidPtr;

	int cmp_result = cmp_student_Average(source1, source2);
	if (cmp_result)
		return cmp_result;

	cmp_result = cmp_student_ID(source1, source2);
	if (cmp_result)
		return cmp_result;

	cmp_result = cmp_student_name(source1, source2);
	if (cmp_result)
		return cmp_result;

	cmp_result = cmp_student_surname(source1, source2);
	if (cmp_result)
		return cmp_result;

	return 0;
}

// A FUNCTION TO CREATE X TIME LIST.
PRIVATE void* CreateDynamicList(int total_size)
{
	LLSTUDENT* my_class = (LLSTUDENT*)malloc(total_size * sizeof(LLSTUDENT));
	if (!my_class)
	{
		return NULL;
	}
	for (int i = 0; i < total_size; i++)
	{
		my_class[i].index.ID = rand() % 10000 + 9000;
		my_class[i].index.average = ((double)rand() * (100. - 0.)) / (double)RAND_MAX + 0.;
		strcpy(my_class[i].index.name, getName());
		strcpy(my_class[i].index.surname, getSurname());
		strcpy(my_class[i].index.city, getCity());
		getDate(my_class, total_size);
	}

	return my_class;
}

// LOOK-UP TABLE FOR USER SORTING DESIRE
PRIVATE SORT strToEnum(const char* index)
{

	const char SORTING_DESIRE[][8] = { "ID", "SCORE", "NAME", "SURNAME", "CITY", "YEAR", "MONTH", "DAY", "DEEPLY" };
	int databaseWish = (sizeof(SORTING_DESIRE) / sizeof(*SORTING_DESIRE));

	while (databaseWish--) {
		if (!strcmp(index, SORTING_DESIRE[databaseWish]))
			break;
	}

	if (databaseWish == 0) return SORT_BY_ID;
	if (databaseWish == 1) return SORT_BY_SCORE;
	if (databaseWish == 2) return SORT_BY_NAME;
	if (databaseWish == 3) return SORT_BY_SURNAME;
	if (databaseWish == 4) return SORT_BY_CITY;
	if (databaseWish == 5) return SORT_BY_YEAR;
	if (databaseWish == 6) return SORT_BY_MONTH;
	if (databaseWish == 7) return SORT_BY_DAY;
	if (databaseWish == 8) return SORT_BY_DEEPLY;
	else return EMPTY;
}

// A FUNCTION TO CREATE A SINGLE NODE
PRIVATE LLSTUDENT* CreateSingleNode()
{
	static int counter = 0;
	LLSTUDENT* node = (LLSTUDENT*)calloc(1, sizeof(LLSTUDENT));
	if (!node)
	{
		exit(EXIT_FAILURE);
	}

	node->index.average = ((double)rand() * (100. - 0.)) / (double)RAND_MAX + 0.;
	node->index.ID = rand() % 10000 + 9000;
	strcpy(node->index.city, getCity());
	getDate(node, 1);
	strcpy(node->index.name, getName());
	strcpy(node->index.surname, getSurname());
	node->nextPtr = NULL;
	return node;

}

/**************************A PLACE TO DECLARE GLOBAL FUNCTIONS****************************/
// Test UI Function Used for Dynamically Allocated Memories
PUBLIC void DynamicUserInterfaceTestCode(void)
{
	srand((unsigned int)time(NULL));

	int total_student;
	check_my_class_status: printf("Total Amount of Students: ");

	if (scanf("%d", &total_student) && total_student > 0 /*&& total_student <= 45*/)
	{
		clock_t start_dynamic = clock();
		LLSTUDENT* my_class = (LLSTUDENT*)CreateDynamicList(total_student);
		if (!my_class)
			goto check_my_class_status;
		clock_t end_dynamic = clock();
		printf("\n>>>(%f) second passed to create and connect linked list.<<<\n", ((double)end_dynamic - (double)start_dynamic) / CLOCKS_PER_SEC);
		printf("List have been created dynamically. What would you like to do know?\n");
		printf("1- Print The List(w/o sorting & w/o saving)\n");
		printf("2- Print The List(after sorting and saving)\n");
		printf("3- Save the List(w/o sorting and showing)\n");

		int user_choice = 0;
		if (scanf("%d", &user_choice) && user_choice <= 3 && user_choice > 0)
		{
			if (user_choice == 1)
			{
				ShoWNodes(my_class, total_student);
			}
			else if (user_choice == 2)
			{
				SortNodes(my_class, total_student);
				ShoWNodes(my_class, total_student);
			}
			else if (user_choice == 3)
			{
				SaveNodes(my_class, total_student);
			}
		}
		free(my_class);	my_class = NULL; goto exiting;
	}
	else
	{
		exiting: printf("Something was broken. Exiting..\n");
		exit(EXIT_FAILURE);
	}
}

// A FUNCTION TO SORT THE LIST.
PUBLIC void SortNodes(void* voidPtr, int total_student)
{

	LLSTUDENT* my_class = (LLSTUDENT*)voidPtr;

	char user_sort_wish[19];

check_user_sort_wish:printf("How you like to sort the list?\n");
	puts("SORT BY ID");
	puts("SORT BY SCORE");
	puts("SORT BY NAME");
	puts("SORT BY SURNAME");
	puts("SORT BY CITY");
	puts("SORT BY YEAR");
	puts("SORT BY MONTH");
	puts("SORT BY DAY");
	puts("SORT BY DEEPLY");
	printf("Please, type your desire (make sure that you type all cases upper): ");
	scanf_s("%s", user_sort_wish, 8);
	switch (strToEnum(user_sort_wish))
	{
	case SORT_BY_ID: SORT_ID(my_class, total_student); break;
	case SORT_BY_SCORE:	SORT_AVERAGE_SCORE(my_class, total_student); break;
	case SORT_BY_NAME: SORT_NAME(my_class, total_student); break;
	case SORT_BY_SURNAME: SORT_SURNAME(my_class, total_student); break;
	case SORT_BY_CITY: SORT_ID(my_class, total_student); break;
	case SORT_BY_YEAR: SORT_ID(my_class, total_student); break;
	case SORT_BY_MONTH:	SORT_ID(my_class, total_student); break;
	case SORT_BY_DAY: SORT_ID(my_class, total_student); break;
	case SORT_BY_DEEPLY: SORT_DEEPLY(my_class, total_student); break;
	default: printf("Unknown command\n"); goto check_user_sort_wish;
	}

	SaveNodes(my_class, total_student);


}

// A FUNCTION TO PRINT WHOLE LIST.
PUBLIC void ShoWNodes(void* voidPtr, int total_size)
{
	LLSTUDENT* my_class = (LLSTUDENT*)voidPtr;

	puts("*************************************************************");
	puts("ID    AVERAGE NAME       SURNAME    CITY          YEAR MONTH  DAY");

	for (int i = 0; i < total_size; i++)
	{
		printf("%.5d %-7.2lf %-10s %-10s %-13s %d %-7s %d\n", my_class[i].index.ID, my_class[i].index.average, my_class[i].index.name, my_class[i].index.surname, my_class[i].index.city, my_class[i].index.year, my_class[i].index.month, my_class[i].index.day);
	}

	puts("*************************************************************");

}

// A FUNCTION TO SAVE WHOLE LIST TO Results.txt FILE.
PUBLIC void SaveNodes(void* voidPtr, int total_size)
{
	LLSTUDENT* my_class = (LLSTUDENT*)voidPtr;

	FILE* fp = fopen("Results.txt", "w");
	if (!fp)
	{
		exit(EXIT_FAILURE);
	}
	fprintf(fp, "*************************************************************\n");
	fprintf(fp, "ID    AVERAGE NAME       SURNAME    CITY          YEAR MONTH  DAY\n");

	for (int i = 0; i < total_size; i++)
	{
		fprintf(fp, "%.5d %-7.2lf %-10s %-10s %-13s %d %-7s %d\n", my_class[i].index.ID, my_class[i].index.average, my_class[i].index.name, my_class[i].index.surname, my_class[i].index.city, my_class[i].index.year, my_class[i].index.month, my_class[i].index.day);

	}

	fprintf(fp, "*************************************************************\n");

	fclose(fp);
}

//GLOBAL SORTING FUNCTION BY ID
PUBLIC void SORT_ID(void* voidPtr, int total_size)
{
	LLSTUDENT* my_class = (LLSTUDENT*)voidPtr;
	qsort(my_class, total_size, sizeof(*my_class), cmp_student_ID);
}

//GLOBAL SORTING FUNCTION BY AVERAGE SCORE
PUBLIC void SORT_AVERAGE_SCORE(void* voidPtr, int total_size)
{
	LLSTUDENT* my_class = (LLSTUDENT*)voidPtr;
	qsort(my_class, total_size, sizeof(*my_class), cmp_student_Average);
}

//GLOBAL SORTING FUNCTION BY NAME
PUBLIC void SORT_NAME(void* voidPtr, int total_size)
{
	LLSTUDENT* my_class = (LLSTUDENT*)voidPtr;
	qsort(my_class, total_size, sizeof(*my_class), cmp_student_name);
}

//GLOBAL SORTING FUNCTION BY SURNAME
PUBLIC void SORT_SURNAME(void* voidPtr, int total_size)
{
	LLSTUDENT* my_class = (LLSTUDENT*)voidPtr;
	qsort(my_class, total_size, sizeof(*my_class), cmp_student_surname);
}

//GLOBAL SORTING FUNCTION BY CITY
PUBLIC void SORT_CITY(void* voidPtr, int total_size)
{
	LLSTUDENT* my_class = (LLSTUDENT*)voidPtr;
	printf("WIP. SO, SORTING MADE BY ID");
	qsort(my_class, total_size, sizeof(*my_class), cmp_student_ID);
}

//GLOBAL SORTING FUNCTION BY YEAR
PUBLIC void SORT_YEAR(void* voidPtr, int total_size)
{
	LLSTUDENT* my_class = (LLSTUDENT*)voidPtr;
	printf("WIP. SO, SORTING MADE BY ID");
	qsort(my_class, total_size, sizeof(*my_class), cmp_student_ID);
}

//GLOBAL SORTING FUNCTION BY MONTH
PUBLIC void SORT_MONTH(void* voidPtr, int total_size)
{
	LLSTUDENT* my_class = (LLSTUDENT*)voidPtr;
	printf("WIP. SO, SORTING MADE BY ID");
	qsort(my_class, total_size, sizeof(*my_class), cmp_student_ID);
}

//GLOBAL SORTING FUNCTION BY DAY
PUBLIC void SORT_DAY(void* voidPtr, int total_size)
{
	LLSTUDENT* my_class = (LLSTUDENT*)voidPtr;
	printf("WIP. SO, SORTING MADE BY ID");
	qsort(my_class, total_size, sizeof(*my_class), cmp_student_ID);
}

//GLOBAL FUNCTION SORTING DEEPLY
PUBLIC void SORT_DEEPLY(void* voidPtr, int total_size)
{
	LLSTUDENT* my_class = (LLSTUDENT*)voidPtr;
	qsort(my_class, total_size, sizeof(*my_class), cmp_student);
}

// Test UI Function Used for Linked List
PUBLIC void LinkedListUserInterfaceTestCode(void)
{
	srand((unsigned)time(NULL));
	int total_size;;
	printf("Total Size of LL: ");
	scanf("%d", &total_size);

	LLSTUDENT** FirstToLast = CreateLinkedListTip(total_size);
	puts("Before addiny any new node;");
	ShowLinkedListTip(FirstToLast[0]);
	
	AddNodeAfterLastFromTip((void**)FirstToLast[0]);
	ShowLinkedListTip(FirstToLast[0]);

}

// GLOBAL FUNCTION TO SHOW NODES OF LINKED LIST	FROM TIP TO THE TAIL OF THE LIST (5 > 10 > 15 > ... > NULL)
PUBLIC int ShowLinkedListTip(void* voidPtr)
{
	LLSTUDENT* tempPtr = (LLSTUDENT*)voidPtr;

	int counter = 0;
	puts("*************************************************************");
	puts("      ID    AVERAGE NAME       SURNAME    CITY          YEAR MONTH  DAY");
	while (tempPtr != NULL)
	{
		printf("%2d => %.5d %-7.2lf %-10s %-10s %-13s %d %-7s %d\n", counter, tempPtr->index.ID, tempPtr->index.average, tempPtr->index.name, tempPtr->index.surname, tempPtr->index.city, tempPtr->index.year, tempPtr->index.month, tempPtr->index.day); counter++;
		tempPtr = tempPtr->nextPtr;
	}

	printf("\nTotal Size: %d\n\n", counter);
	return counter;
}

// GLOBAL FUNCTION TO SHOW NODES OF LINKED LIST	FROM TAIL TO THE TIP OF THE LIST (NULL< ... 15 < 10 < 5)
PUBLIC int ShowLinkedListTall(void** voidPtr, int total_size)
{
	LLSTUDENT** tempPtr = (LLSTUDENT**)voidPtr;
	int counter = 0;
	puts("*************************************************************");
	puts("     ID    AVERAGE NAME       SURNAME    CITY          YEAR MONTH  DAY");
	for (int i = (total_size - 1); i >= 0; i--)
	{
		printf("%d => %.5d %-7.2lf %-10s %-10s %-13s %d %-7s %d\n", i, tempPtr[i]->index.ID, tempPtr[i]->index.average, tempPtr[i]->index.name, tempPtr[i]->index.surname, tempPtr[i]->index.city, tempPtr[i]->index.year, tempPtr[i]->index.month, tempPtr[i]->index.day); counter++;
	}

	printf("\nTotal Size: %d\n\n", counter);

	return counter;
}

// GLOBAL FUNCTION TO CREATE LINKED LIST FROM TIP TO THE TAIL OF THE LIST (5 > 10 > 15 > ... > NULL)
//PUBLIC LLSTUDENT** CreateLinkedListTip(int total_size)
//{
//	puts("\nA new node always will be added in following style;\nAssume '5' belongs to the first node: 5 > 10 > 15 > 20...\n");
//
//	clock_t start_dynamic = clock();
//	LLSTUDENT* Nodes = (LLSTUDENT*)malloc(total_size * sizeof(LLSTUDENT));
//
//	int i;
//	for (i = 0; Nodes[i].nextPtr != NULL; i++)
//	{
//	   if (i == total_size - 1)
//	   {
//		   Nodes[i].nextPtr = NULL;
//	   }
//	   else
//	   {
//		   Nodes[i].nextPtr = &Nodes[i + 1];
//	   }
//	}
//
//	clock_t end_dynamic = clock();
//
//	printf("\n>>>(%lf) second passed to create and connect linked list.<<<\n", ((double)end_dynamic - start_dynamic) / CLOCKS_PER_SEC);
//	return Nodes;
//}

// GLOBAL FUNCTION TO CREATE LINKED LIST FROM TAIL TO THE TOP OF THE LIST (NULL< ... 15 < 10 < 5)
PUBLIC LLSTUDENT** CreateLinkedListTall(int total_size)
{
	puts("\nA new node always will be added in following style;\nAssume '5' belongs to the first node: ... > 20 > 15 > 10 > 5\n");

	LLSTUDENT** Nodes = (LLSTUDENT**)malloc(total_size * sizeof(LLSTUDENT*));
	for (int i = 0; i < total_size; i++)
	{
		Nodes[i] = CreateSingleNode();
	}

	for (int i = (total_size - 1); i >= 0; i--)
	{
		if (i == 0)
		{
			Nodes[i]->nextPtr = NULL;
		}
		else
		{
			Nodes[i]->nextPtr = Nodes[i - 1];
		}

	}

	return Nodes;
}

// GLOBAL FUNCTION TO ADD A SINGLE NODE TO THE END OF THE LINKED LIST.
PUBLIC void AddNodeAfterLastFromTip(void** voidPtr)
{
	LLSTUDENT** Tip = (LLSTUDENT**)voidPtr;
	int i;
	for (i = 0; Tip[i]->nextPtr != NULL; i++);

	LLSTUDENT* tempNewNode = CreateSingleNode();

	Tip[i]->nextPtr = tempNewNode;
	tempNewNode->nextPtr = NULL;
}

// GLOBAL FUNCTION TO ADD A SINGLE NODE TO THE HEAD OF THE LINKED LIST.
PUBLIC LLSTUDENT** AddNodeBeforeFirstFromTip(void** voidPtr, void** _voidPtr)
{
	LLSTUDENT** Tip = (LLSTUDENT**)voidPtr;
	LLSTUDENT** newNode = (LLSTUDENT**)_voidPtr;

	(*newNode)->nextPtr = Tip[0];

	LLSTUDENT** NewTip = (newNode);

	return NewTip;
}

// GLOBAL FUNCTION TO FREE LINKEDIN LIST.
PUBLIC void DestroyLinkedList(void** voidPtr, int total_size)
{
	LLSTUDENT** Nodes = (LLSTUDENT**)voidPtr;
	for (int i = 0; i < total_size; i++)
	{
		free(Nodes[i]);
		Nodes[i] = NULL;
	}
	free(Nodes);
	Nodes = NULL;
	if (!Nodes)	puts("Memory is free!");
}




