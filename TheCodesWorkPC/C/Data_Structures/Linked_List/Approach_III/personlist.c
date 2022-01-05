#include "person.h"
#include "personlist.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
	Person per;
	struct Node *pnext;
}Node;

struct List {
	Node *gpfirst;
	int gcount;
};
//----------------------------------------------------------------------------------------------------------

ListHandle create_list(void)
{
	ListHandle h = (ListHandle)malloc(sizeof(*h));
	if (!h) {
		printf("bellek yetersiz\n");
		exit(EXIT_FAILURE);
	}
	h->gcount = 0;
	h->gpfirst = NULL;

	return h;
}
//----------------------------------------------------------------------------------------------------------

void destroy_list(ListHandle h)
{
	make_empty(h);
	free(h);
}
//----------------------------------------------------------------------------------------------------------


static Node* create_node(void)
{
	Node *pnewnode = (Node *)malloc(sizeof(Node));
	
	if (!pnewnode) {
		printf("bellek yetersiz\n");
		exit(EXIT_FAILURE);
	}
	
	return pnewnode;
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

int get_size(ListHandle h)
{
	return h->gcount;
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
int isempty(ListHandle h)
{
	//return h->gcount == 0;
	return h->gpfirst == NULL;
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

void print_list(ListHandle h)
{
	for (Node *p = h->gpfirst; p != NULL; p = p->pnext) {
		print_person(stdout, &p->per);
	}
	printf("\n");
	
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
void push_front(ListHandle h, const Person *p)
{
	Node *pnewnode = create_node();
	pnewnode->per = *p;
	pnewnode->pnext = h->gpfirst;
	h->gpfirst = pnewnode;
	++h->gcount;
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

void pop_front(ListHandle h)
{
	if (isempty(h)) {
		printf("bos liste hatasi\n");
		exit(EXIT_FAILURE);
	}
	Node *ptemp = h->gpfirst;
	h->gpfirst = h->gpfirst->pnext;
	free(ptemp);
	--h->gcount;
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
void get_first(ListHandle h, Person *p)
{
	if (isempty(h)) {
		printf("bos liste hatasi\n");
		exit(EXIT_FAILURE);
	}
	*p = h->gpfirst->per;
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
void make_empty(ListHandle h)
{
	while (!isempty(h))
		pop_front(h);
}










