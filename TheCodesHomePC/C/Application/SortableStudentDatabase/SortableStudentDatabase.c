#include "SortableStudentDatabase.h"

int main() {

	int total_class_size = 0;
	lower_class_size: printf("Total Size of Class: ");
	if (scanf("%d", &total_class_size) && total_class_size >= 0);
	student* index = (student*)malloc(total_class_size * sizeof(student));
	if (!index)
	{
		printf("Not Enough Memory for %d Student.\n", total_class_size);
		goto lower_class_size;
	}
	printf("Enough Memory for %d Student.\n", total_class_size);

	int minimum_grade = 0;
	check_minimum_grade: printf("Minimum Grade To Pass The Lesson: ");
	if (!(scanf("%d", &minimum_grade) && minimum_grade >= 0))
		goto check_minimum_grade;

	static const char nameList[][20] = { "AHMET", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ELIZABETH", "AHMET", "ELLEN", "ELLEN", "ELLEN", "EPIPHANY", "EPPIE", "ETTA", "EULA", "FOREST", "FORD", "FOSTER", "FOX",
										       "FOREST", "FORD", "FOSTER", "FOX", "EPIPHANY", "EPPIE", "ETTA", "EULA", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "EULA",
										       "AHMET", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ELIZABETH", "AHMET", "ELLEN", "ELLEN", "ELLEN", "EPIPHANY", "EPPIE", "ETTA", "EULA", "FOREST", "FORD", "FOSTER", "FOX",
										       "FOREST", "FORD", "FOSTER", "FOX", "EPIPHANY", "EPPIE", "ETTA", "EULA", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "EULA", 
	};

	static const char surnameList[][20] = { "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON",
												  "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON",	"GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ"	,  "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA",
												  "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON",
												  "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON", "JOHNSON", "ABBESTEGE", "WILSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS",
												  "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON", "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE",
	};

	puts("Filling the exam score table...");
	//int counter;
	srand((unsigned int	)time(NULL));
	for (int i = 0; i < total_class_size; i++)
	{
		
		strcpy(index[i].name, nameList[rand() % 80]);
		strcpy(index[i].surname, surnameList[rand() % 80]);
		index[i].ID = rand() % 10;
		index[i].averageScore = rand() % 101;
		
	}

	puts("Exam Score Table B4 Sorting...");
	for (int i = 0; i < total_class_size;i++)
	{
		printf("(%.6d) %-10s %-10s Score: %6.4lf\n", index[i].ID, index[i].name, index[i].surname, index[i].averageScore);
	}
	puts("***************************************************************************");
	puts("Exam Score Table is being written to the ExamScore.text file B4 Sorting...");
	FILE* fp = fopen("ExamScoreTable.text", "w+");
	if (!fp)
	{
		puts("File couldn't be opened.");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < total_class_size; i++)
	{
		fprintf(fp, "(%.6d) %-10s %-10s Score: %6.4lf\n", index[i].ID, index[i].name, index[i].surname, index[i].averageScore);
	}
	fclose(fp);

	puts("Exam Score Table After Sorting by Name...");
	qsort(index, total_class_size, sizeof(*index), &cmp_student_name);
	for (int i = 0; i < total_class_size; i++)
	{
		printf("(%.6d) %-10s %-10s Score: %6.4lf\n", index[i].ID, index[i].name, index[i].surname, index[i].averageScore);
	}
	puts("***************************************************************************");
	puts("Exam Score Table After Sorting by Surname...");
	qsort(index, total_class_size, sizeof(*index), &cmp_student_surname);
	for (int i = 0; i < total_class_size; i++)
	{
		printf("(%.6d) %-10s %-10s Score: %6.4lf\n", index[i].ID, index[i].name, index[i].surname, index[i].averageScore);
	}
	puts("***************************************************************************");
	puts("Exam Score Table After Sorting by ID...");
	qsort(index, total_class_size, sizeof(*index), &cmp_student_ID);
	for (int i = 0; i < total_class_size; i++)
	{
		printf("(%.6d) %-10s %-10s Score: %6.4lf\n", index[i].ID, index[i].name, index[i].surname, index[i].averageScore);
	}
	puts("***************************************************************************");
	puts("Exam Score Table After Sorting by Average Score...");
	qsort(index, total_class_size, sizeof(*index), &cmp_student_Average);
	for (int i = 0; i < total_class_size; i++)
	{
		printf("(%.6d) %-10s %-10s Score: %6.4lf\n", index[i].ID, index[i].name, index[i].surname, index[i].averageScore);
	}
	puts("***************************************************************************");
	puts("Exam Score Table After Sorting by Generally...");
	qsort(index, total_class_size, sizeof(*index), &cmp_student);
	for (int i = 0; i < total_class_size; i++)
	{
		printf("(%.6d) %-10s %-10s Score: %6.4lf\n", index[i].ID, index[i].name, index[i].surname, index[i].averageScore);
	}

	free(index);
	index = NULL;
}