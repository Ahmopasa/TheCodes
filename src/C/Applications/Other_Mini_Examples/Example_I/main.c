#include <string.h>
#include <stdio.h>

typedef struct myCollage {

	char name[31];
	char surname[31];
	int ID;
	int Fee;


}school;

int main() {

	char temp_name[30] = { 0 };
	school* student = (school*)malloc(1 * sizeof(school));

	if (student == NULL)
	{
		puts("FAILED"); exit(1);
	}
	printf("Enter student information.\n\n");
	for (int i = 0; i < 1; ++i)
	{
		printf("Name: ");
		if (scanf("%s", student[i].name)) {
			printf("Surname: ");
			if (scanf("%s", student[i].surname)) {
				printf("ID: ");
				if (scanf("%d", &student[i].ID)) {
					printf("Fee: ");
					if (scanf("%d", &student[i].Fee))
						strcpy(temp_name, student[i].name);
				}
			}
		}
	}
	printf("Displaying Information:\n");
	for (int i = 0; i < 1; ++i)
		printf("Name: %s\nSurname: %s\nID: %d\nFee: %d\n", student[i].name, student[i].surname, student[i].ID, student[i].Fee);
	for (int i = 0; i < 1; ++i)
	{
		FILE* studentTracker = fopen(temp_name,"w+");
		fprintf(studentTracker, "Name: %s\nSurname: %s\nID: %d\nFee: %d\n\n", student[i].name, student[i].surname, student[i].ID, student[i].Fee);
		fclose(studentTracker);
	}

	return 0;
}