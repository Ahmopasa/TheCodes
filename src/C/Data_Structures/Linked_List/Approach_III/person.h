#pragma once

#include "date.h"


typedef struct Person{
	int m_no;
	char m_name[20];
	char m_fname[20];
	char m_town[20];
	Date m_date;
}Person;

//----------------------------------------------------------------------------------------------------------

Person *set_random_person(Person *p);
void	print_person(FILE *f, const Person *p);

int cmp_person(const Person *p1, const Person *p2);
int cmp_person_name(const Person *p1, const Person *p2);
int cmp_person_fname(const Person *p1, const Person *p2);
int cmp_person_no(const Person *p1, const Person *p2);
int cmp_person_town(const Person *p1, const Person *p2);
int cmp_person_date(const Person *p1, const Person *p2);
//----------------------------------------------------------------------------------------------------------
