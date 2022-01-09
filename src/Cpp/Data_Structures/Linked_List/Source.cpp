////#define _CRT_SECURE_NO_WARNINGS
////#define check_leap(year) ((year) % 4 == 0 && ((year) % 100 != 0 || (year) % 400 == 0))
////
////#include <stdio.h>
////#include <stdlib.h>
////#include <string.h>
////#include <time.h>
////#include <ctype.h>
////
////
////// struct _node {
//////	int ID;
//////	int day;
//////	int year;
//////	double average;
//////	char month[15];
//////	char name[20];
//////	char surname[20];
//////	char city[20];
//////};
//////
////// typedef struct nodes
////// {
//////	 _node index;
//////	 struct nodes* nextPtr;
////// }Node;
////
////
//////// A Random Name Generator
////// const char* getName()
//////{
//////	static const char* const nameList[80] = { "AHMET", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ELIZABETH", "AHMET", "ELLEN", "ELLEN", "ELLEN", "EPIPHANY", "EPPIE", "ETTA", "EULA", "FOREST", "FORD", "FOSTER", "FOX",
//////											"FOREST", "FORD", "FOSTER", "FOX", "EPIPHANY", "EPPIE", "ETTA", "EULA", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "EULA",
//////											"AHMET", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ELIZABETH", "AHMET", "ELLEN", "ELLEN", "ELLEN", "EPIPHANY", "EPPIE", "ETTA", "EULA", "FOREST", "FORD", "FOSTER", "FOX",
//////											"FOREST", "FORD", "FOSTER", "FOX", "EPIPHANY", "EPPIE", "ETTA", "EULA", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "EULA",
//////	};
//////
//////	return nameList[rand() % 80];
//////}
//////
//////// A Random Surname Generator
////// const char* getSurname()
//////{
//////	static const char* const surnameList[] = { "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON",
//////											  "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON",	"GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ"	,  "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA",
//////											  "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON",
//////											  "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON", "JOHNSON", "ABBESTEGE", "WILSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS",
//////											  "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON", "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE",
//////	};
//////
//////	return surnameList[rand() % 80];
//////}
//////
//////// A Random City Name Generator
////// const char* getCity()
//////{
//////	static const char* const cityList[] = { "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Colorado",
//////									 "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Louisiana", "Maine", "Maryland", "Massachusetts",
//////									 "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware",
//////									 "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Louisiana", "Maine", "Maryland", "Massachusetts", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware",
//////									 "Florida", "Georgia", "Hawaii", "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida"
//////	};
//////
//////	return cityList[rand() % 80];
//////}
//////
//////// A Random Date Generator (WIP)
////// void getDate(Node* my_class, int total_size)
////// {
//////	 int year;
//////	 int year_leap;
//////	 int counter_date;
//////
//////	 static const int daytabs[][13] = {
//////							 {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
//////							 {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
//////	 };
//////
//////	 static const char* const pmons[] = { "","Ocak","Subat","Mart","Nisan","Mayis","Haziran","Temmuz","Agustos","Eylul","Ekim","Kasim","Aralik" };
//////
//////	 for (int i = 0; i < total_size; i++)
//////	 {
//////		 year = rand() % (2020 - 1989 + 1) + 1989;
//////		 year_leap = check_leap(year);
//////		 counter_date = rand() % 12 + 1;
//////		 my_class[i]->index.year = year;
//////		 strcpy(my_class[i].index.month, pmons[counter_date]);
//////		 my_class[i].index.day = daytabs[year_leap][counter_date];
//////	 }
////// }
////
//////void printList(struct Node* head)
//////{
//////	puts("*************************************************************");
//////	puts("      ID    AVERAGE NAME       SURNAME    CITY          YEAR MONTH  DAY");
//////	while (head != NULL) {
//////		
//////		printf("%.5d %-7.2lf %-10s %-10s %-13s %d %-7s %d\n", head->ID, head->average, head->name, head->surname, head->city, head->year, head->month, head->day); 
//////		head = head->next;
//////	}
//////	putchar('\n');
//////}
//////
//////Node* CreataNode(void)
//////{
//////	Node* newNode = NULL;
//////	newNode = (Node*)malloc(sizeof(Node));
//////
//////	newNode->average = ((double)rand() * (100. - 0.)) / (double)RAND_MAX + 0.;
//////	newNode->ID = rand() % 10000 + 9000;
//////	strcpy(newNode->city, getCity());
//////	getDate(newNode, 1);
//////	strcpy(newNode->name, getName());
//////	strcpy(newNode->surname, getSurname());
//////	newNode->next = NULL;
//////
//////	return newNode;
//////}
//////
//////Node* CreateList(Node* head, int size)
//////{
//////	Node* cursor = head;
//////
//////	for (int i = 0; i < size; i++)
//////	{
//////		while (cursor->next != NULL)
//////			cursor = cursor->next;
//////
//////		Node* new_node = CreataNode();
//////		cursor->next = new_node;
//////
//////	}
//////
//////
//////	return head;
//////}
////
////typedef struct node {
////	int data;
////	struct node* next;
////}node;
////
////
////node * create(int data, node * next)
////{
////	node* new_node = (node*)malloc(sizeof(node));
////	if (new_node == NULL)
////	{
////		printf("Error creating a new node.\n");
////		exit(0);
////	}
////	new_node->data = data;
////	new_node->next = next;
////
////	return new_node;
////}
////
////node * prepend(node * head, int data)
////{
////	node* new_node = create(data, head);
////	head = new_node;
////	return head;
////}
////
////node* append(node* head, int data)
////{
////	/* go to the last node */
////	node* cursor = head;
////	while (cursor->next != NULL)
////		cursor = cursor->next;
////
////	/* create a new node */
////	node* new_node = create(data, NULL);
////	cursor->next = new_node;
////
////	return head;
////}
////
////
////int count(node* head)
////{
////	node* cursor = head;
////	int c = 0;
////	while (cursor != NULL)
////	{
////		c++;
////		cursor = cursor->next;
////	}
////	return c;
////}
////
////typedef void (*callback)(node* data);
////void  traverse(node * head, callback f)
////{
////	node* cursor = head;
////	while (cursor != NULL)
////	{
////		f(cursor);
////		cursor = cursor->next;
////	}
////}
////
////void display(node* n)
////{
////	if (n != NULL)
////		printf("%d ", n->data);
////}
////
////int main() {
////	callback disp = display;
////
////	node* head = NULL;
////	int data;
////	printf("Please enter a number to append:");
////	scanf("%d", &data);
////	head = append(head, data);
////	traverse(head, disp);
////	display(head);
////
////}
////
////
////
//#include <stdio.h>
//#include <stdlib.h>
//struct node {
//	int data;
//	struct node* next;
//};
//struct node* make_list(void)
//{
//	struct node* list = NULL;
//	int i;
//
//	for (i = 0; i < 2; i++) {
//		struct node* nn = (struct node*)malloc(sizeof(struct node));
//
//		if (nn == NULL)
//			break;
//
//		nn->data = rand() % 101;
//		nn->next = list;
//		list = nn;
//	}
//
//	return list;
//}
//int main(void)
//{
//	struct node* list = make_list();
//	struct node* it, * save;
//
//	for (it = list; it != NULL; it = save) {
//		save = it->next;
//		printf("%d\n", it->data);
//		free(it);
//	}
//
//	return 0;
//}
#include <iostream>
using namespace std;

// A linked list node
struct Node
{
	int data;
	struct Node* next;
};

//insert a new node in front of the list
void push(struct Node** head, int node_data)
{
	/* 1. create and allocate node */
	struct Node* newNode = new Node;

	/* 2. assign data to node */
	newNode->data = node_data;

	/* 3. set next of new node as head */
	newNode->next = (*head);

	/* 4. move the head to point to the new node */
	(*head) = newNode;
}

//insert new node after a given node
void insertAfter(struct Node* prev_node, int node_data)
{
	/*1. check if the given prev_node is NULL */
	if (prev_node == NULL)
	{
		cout << "the given previous node is required,cannot be NULL"; return;
	}

	/* 2. create and allocate new node */
	struct Node* newNode = new Node;

	/* 3. assign data to the node */
	newNode->data = node_data;

	/* 4. Make next of new node as next of prev_node */
	newNode->next = prev_node->next;

	/* 5. move the next of prev_node as new_node */
	prev_node->next = newNode;
}

/* insert new node at the end of the linked list */
void append(struct Node** head, int node_data)
{
	/* 1. create and allocate node */
	struct Node* newNode = new Node;

	struct Node* last = *head; /* used in step 5*/

	/* 2. assign data to the node */
	newNode->data = node_data;

	/* 3. set next pointer of new node to null as its the last node*/
	newNode->next = NULL;

	/* 4. if list is empty, new node becomes first node */
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = newNode;
	return;
}

// display linked list contents
void displayList(struct Node* node)
{
	//traverse the list to display each node
	while (node != NULL)
	{
		cout << node->data << "-->";
		node = node->next;
	}

	if (node == NULL)
		cout << "null";
}
/* main program for linked list*/
int main()
{
	/* empty list */
	struct Node* head = NULL;

	// Insert 10 at the end.
	append(&head, 10);

	// Insert 20 at the end. 
	append(&head, 20);

	// Insert 40 at the end. 
	append(&head, 40); // 

	// Insert 30 at the beginning. 
	push(&head, 30);

	
	//Insert 50, after 20.
	insertAfter(head->next, 50);

	cout << "Final linked list: " << endl;
	displayList(head);

	return 0;
}