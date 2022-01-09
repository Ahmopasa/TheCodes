#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PUBLIC

struct linkedList
{
	int ID;
	int day;
	int year;

	double average;
	struct linkedList* nextPtr;

}student;

typedef struct linkedList linkedList;


/*
PUBLIC void* AddBeforeTheNodeX(void** voidPtr, int tip, int tall)
{
	linkedList** head = (linkedList**)(voidPtr);

	fprintf(stdout, "The node will be found via its ID.\n");

	linkedList* first = *head;
	linkedList* index = first->nextPtr;

	if (first == NULL || index == NULL)
		exit(EXIT_FAILURE);

	for (; first != NULL && first->ID != tip; first = first->nextPtr)
		;

	for (; index != NULL && index->ID != tall; index = index->nextPtr)
		;

	fprintf(stdout, "A new node will be added between [%d] and [%d]. nodes.\n", first->ID, index->ID);

	linkedList* newNode = (linkedList*)malloc(sizeof(linkedList));
	if (newNode == NULL)
		exit(EXIT_FAILURE);

	newNode->ID = 999;
	newNode->average = ((double)rand() * (100. - 0.)) / (double)RAND_MAX + 0.;

	newNode->nextPtr = NULL;

	first->nextPtr = newNode;
	newNode->nextPtr = index;
	return (linkedList*)*head;


}
*/


int foo3(int x)
{
	puts("inside of foo2;");

	x += 10;

	return x * x;

}

int foo2(int* x)
{
	puts("inside of foo2;");
	*x *= 2;

	return 0;

}
int main()
{

	int a = 10;
	int b = foo3(a);
	int c = b * 2;

	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);

	foo3(a);
	printf("a = %d\n", a);

	foo2(&a);
	printf("a = %d\n", a);








}