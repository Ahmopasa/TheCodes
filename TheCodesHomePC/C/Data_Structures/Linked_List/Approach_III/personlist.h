#pragma once


struct Person;
typedef struct Person Person;

struct List;
typedef struct List* ListHandle;

ListHandle create_list(void);
void destroy_list(ListHandle);

int get_size(ListHandle);
int isempty(ListHandle);
void push_front(ListHandle, const Person *p);
void pop_front(ListHandle);
void print_list(ListHandle);
void get_first(ListHandle, Person *p);
void make_empty(ListHandle);
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


