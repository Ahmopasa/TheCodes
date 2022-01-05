#ifndef LEARNINGLINKEDLIST_H
#define LEARNINGLINKEDLIST_H
/**************************A PLACE TO INCLUDE LIBS.**************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**************************A PLACE TO DEFINE MACROS**************************/
#define _CRT_SECURE_NO_WARNINGS
#define PRIVATE static
#define PUBLIC

/**************************A PLACE TO DECLARE GLOBAL FUNCTIONS**************************/
PUBLIC void SaveLinkedList(void* voidPtr);
PUBLIC void ShowLinkedList(void* voidPtr);
PUBLIC void* AddBeforeTheFirstNode(void** voidPtr, int total_amount);
PUBLIC void* AddAfterTheLastNode(void** voidPtr, int total_amount);
PUBLIC void* AddNewNodesBetweenTwo(void** voidPtr, int position_X, int total_amount);
PUBLIC void* RemoveNodesBetweenTwo(void** voidPtr, int position_X, int position_Y);
#endif
