#include <stdlib.h>
#include <stdio.h>

inline int* create_array (int total_passanger)
{
	int *BusName = (int*)malloc(total_passanger * sizeof(int));

	if (BusName == NULL) {
		fprintf_s(stderr, "Error To Allocate!.");
			exit(1);
	}

	for (int i = 0; i < total_passanger; i++)
	{
		printf_s("%s", "Please, enter the code that every passanger has: ");
		scanf("%d", &BusName[i]);
	}
	return BusName;
}

inline void change_array(int* BusName, int total_passanger)
{
	total_passanger += 2;
	
	int *NewBusName = (int*)realloc(BusName, total_passanger * sizeof(int));

	if (NewBusName == NULL) {
		fprintf_s(stderr, "Error To Allocate!.");
		exit(1);
	}

	NewBusName = BusName;
	for (int i = 0; i < total_passanger; i++)
	{
		printf_s("Please, enter the code that every passanger has since %d passanger we have: ", total_passanger);
		scanf("%d", &NewBusName[i]);
	}
}

inline void print_array(int * BusName, int total_passanger)
{
	printf_s("%s", "Number of Passangers are below\n");
	printf_s("%s", "#\tPassanger's Number\n");

	for (int i = 0; i < total_passanger; i++)
	{
		printf_s("%.2d\t%.2d\n", i+1, BusName[i]);
	}
}

inline void free_array(int* BusName)
{
    free(BusName);
    BusName = NULL;
}