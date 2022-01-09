#include <stdio.h>

#define total_uye 3

typedef struct StudentInfo {
	int uniqueID;
	char name[100];
	char surname[100];
	int Fee;
	int ID;
	struct StudentInfo* next;
}
student;

int main()
{
	student counter[2] = { 0 };
	puts("Without any loop");
	FILE* index2 = fopen("Merve.txt", "r");
	FILE* index = fopen("Ahmet.txt", "r");
	if(fscanf(index, "Unique ID: %d\n", &counter[0].uniqueID));
	if (counter[0].uniqueID == 942020)
	{
		if(fscanf(index2, "Name: %s\nSurname: %s\nID: %d\nFee: %d", counter[1].name, counter[1].surname, &counter[1].ID, &counter[1].Fee));
		fclose(index2);
	}
	else
	{
		puts("Ids did not matched.");
		fclose(index);
		fclose(index2);
		exit(1);
	}
	printf("Name: %s\nSurname: %s\nID: %d\nFee: %d", counter[1].name, counter[1].surname, counter[1].ID, counter[1].Fee);

	puts("\n\n\nWith loop");
	char fileName[2] = "0";
	int fileNAME = 0;
	printf("String: %s\nInteger: %d\n", fileName, fileNAME);
	student noLoop[total_uye] = { 0 };
	FILE* Loop[total_uye];
	for (int i = 0; i < total_uye; i++)
	{
		Loop[i] = fopen(fileName, "r+");
		if (Loop[i] != NULL)
		{
			printf("%s is open!\n", fileName);
			if (fscanf(Loop[i], "Unique ID: %d\nName: %s\nSurname: %s\nID: %d\nFee: %d", &noLoop[i].uniqueID, noLoop[i].name, noLoop[i].surname, &noLoop[i].ID, &noLoop[i].Fee));
			fileNAME = atoi(fileName);
			fileNAME++;
			_itoa(fileNAME, fileName, 10);
			fclose(Loop[i]);
		}
		else
		{
			printf("Failed to open %s\n", fileName);
		}
	}

	puts("Results\n");
	for (size_t i = 0; i < total_uye; i++)
	{
		printf("%d. Student Info;", i+1);
		printf("Unique ID: %d\n", noLoop[i].uniqueID);
		printf("Name: %s\n", noLoop[i].name);
		printf("Surname: %s\n", noLoop[i].surname);
		printf("ID: %d\n", noLoop[i].ID);
		printf("Free: %d\n", noLoop[i].Fee);
	}

}