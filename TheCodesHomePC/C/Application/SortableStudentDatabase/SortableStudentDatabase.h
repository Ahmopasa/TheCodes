#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct student {
	char name[20];
	char surname[20];
	int ID;
	double averageScore;
}
student;

inline int cmp_student_name(const student* source_1, const student* source_2)
{
	return strcmp(source_1->name, source_2->name);
}

inline int cmp_student_surname(const student* source_1, const student* source_2)
{
	return strcmp(source_1->surname, source_2->surname);
}

inline int cmp_student_ID(const student* source_1, const student* source_2)
{
	return (int)(source_1->ID - source_2->ID);
}

inline int cmp_student_Average(const student* source_1, const student* source_2)
{
	return (int)(source_1->averageScore - source_2->averageScore);
}

inline int cmp_student(const student* source_1, const student* source_2)
{
	int cmp_result = cmp_student_Average(source_1, source_2);
	if (cmp_result)
		return cmp_result;

	cmp_result = cmp_student_ID(source_1, source_2);
	if (cmp_result)
		return cmp_result;

	cmp_result = cmp_student_name(source_1, source_2);
	if (cmp_result)
		return cmp_result;

	cmp_result = cmp_student_surname(source_1, source_2);
	if (cmp_result)
		return cmp_result;

	return 0;
}

