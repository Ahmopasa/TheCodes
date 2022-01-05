#define _CRT_SECURE_NO_WARNINGS

#include "Data.h"


int main() {
	//int total_students;
	//check_total_students: printf("Welcome to the system.\nPlease, enter the total size of students: ");
	//if (!(scanf("%d", &total_students) && total_students >= 0))
	//	goto check_total_students;

	//student* personelInfo = (student*)malloc(3 * sizeof(student));
	//if (!personelInfo)
	//{
	//	puts("List, could not be created. Exiting...");
	//	exit(EXIT_FAILURE);
	//}
	student personelInfo[3] = { 0 };

	system("cls");
	printf("List have been created, but it is empty.\n\n");
	CreateList(personelInfo, 3);
	ShowList(personelInfo, 3);
	WriteToFile(personelInfo, 3);

}
