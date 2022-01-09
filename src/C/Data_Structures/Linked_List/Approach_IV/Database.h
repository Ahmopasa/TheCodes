#ifndef DATABASE_H
/**************************A PLACE TO INCLUDE LIBS.**************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

/**************************A PLACE TO DEFINE MACROS**************************/
#define DATABASE_H
#define _CRT_SECURE_NO_WARNINGS
#define PRIVATE static
#define PUBLIC

typedef struct
{
	int ID;
	int day;
	int year;
	double average;
	char month[15];
	char name[20];
	char surname[20];
	char city[20];
}student;

struct LLSTUDENT
{
	student index;
	LLSTUDENT* nextPtr;
};

typedef struct LLSTUDENT LLSTUDENT;

/**************************A PLACE TO DECLARE GLOBAL FUNCTIONS**************************/
PUBLIC void DynamicUserInterfaceTestCode(void);
PUBLIC void SORT_DEEPLY(void* voidPtr, int total_size);
PUBLIC void SORT_DAY(void* voidPtr, int total_size);
PUBLIC void SORT_MONTH(void* voidPtr, int total_size);
PUBLIC void SORT_YEAR(void* voidPtr, int total_size);
PUBLIC void SORT_CITY(void* voidPtr, int total_size);
PUBLIC void SORT_SURNAME(void* voidPtr, int total_size);
PUBLIC void SORT_NAME(void* voidPtr, int total_size);
PUBLIC void SORT_AVERAGE_SCORE(void* voidPtr, int total_size);
PUBLIC void SORT_ID(void* voidPtr, int total_size);
PUBLIC void SaveNodes(void* voidPtr, int total_size);
PUBLIC void ShoWNodes(void* voidPtr, int total_size);
PUBLIC void SortNodes(void* voidPtr, int total_student);
PUBLIC void LinkedListUserInterfaceTestCode(void);
PUBLIC int ShowLinkedListTip(void* Tip);
PUBLIC int ShowLinkedListTall(void** Tall, int total_size);
PUBLIC LLSTUDENT** CreateLinkedListTip(int total_size);
PUBLIC LLSTUDENT** CreateLinkedListTall(int total_size);
PUBLIC void AddNodeAfterLastFromTip(void** voidPtr);
PUBLIC LLSTUDENT** AddNodeBeforeFirstFromTip(void** voidPtr, void** newNode);
PUBLIC void DestroyLinkedList(void** Nodes, int total_size);
#endif


