#define _CRT_SECURE_NO_WARNINGS

#include "person.h"
#include "nutility.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


Person *set_random_person(Person *p)
{
	p->m_no = rand() % 1000;
	strcpy(p->m_name, random_name());
	strcpy(p->m_fname, random_fname());
	strcpy(p->m_town, random_town());
	set_random_date(&p->m_date);
}
//----------------------------------------------------------------------------------------------------------

void print_person(FILE *f, const Person *p)
{
	fprintf(f, "%-5d  %-16s %-20s %-16s  ", p->m_no, p->m_name, p->m_fname, p->m_town);
	print_date(f, &p->m_date);
}

//----------------------------------------------------------------------------------------------------------

int cmp_person_name(const Person *p1, const Person *p2)
{
	return strcmp(p1->m_name, p2->m_name);
}

//----------------------------------------------------------------------------------------------------------

int cmp_person_fname(const Person *p1, const Person *p2)
{
	return strcmp(p1->m_fname, p2->m_fname);
}

//----------------------------------------------------------------------------------------------------------

int cmp_person_town(const Person *p1, const Person *p2)
{
	return strcmp(p1->m_town, p2->m_town);
}

int cmp_person_no(const Person *p1, const Person *p2)
{
	return p1->m_no - p2->m_no;
}

//----------------------------------------------------------------------------------------------------------

int cmp_person_date(const Person *p1, const Person *p2)
{
	return cmp_date(&p1->m_date, &p2->m_date);
}

//----------------------------------------------------------------------------------------------------------

int cmp_person(const Person *p1, const Person *p2)
{
	if (p1->m_no != p2->m_no)
		return p1->m_no - p2->m_no;

	int cmp_result = strcmp(p1->m_fname, p2->m_fname);
	if (cmp_result)
		return cmp_result;
	
	cmp_result = strcmp(p1->m_name, p2->m_name);
	if (cmp_result)
		return cmp_result;

	cmp_result = strcmp(p1->m_town, p2->m_town);
	if (cmp_result)
		return cmp_result;

	return cmp_date(&p1->m_date, &p2->m_date);
}
//----------------------------------------------------------------------------------------------------------
