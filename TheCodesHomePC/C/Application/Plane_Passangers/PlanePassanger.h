#include <stdlib.h>
#include <stdio.h>

inline int ** create_array(int total_plane, int total_passasnger)
{
	int **TwoDimensionArrayPointer = (int**)malloc(total_plane*sizeof(int*));

	for (int i = 0; i < total_plane; i++)
	{
		TwoDimensionArrayPointer[i] = (int*)malloc(total_passasnger*sizeof(int));
	}

	if (TwoDimensionArrayPointer == NULL) {

		printf("Error to allocate.\n");
		exit(1);
	}

	printf_s("\n\n%d is the number of total plane.\n", total_plane);
	printf_s("%d is the number of total passanger.\n\n", total_passasnger);


	printf_s("%s", "Now, please enter ID numbers for total numbers.\n");

	for (int i = 0; i < total_plane; i++)
	{
		for (int j = 0; j < total_passasnger; j++) {
			printf_s("Please enter %d. passanger that is in the %d. plane: ", j+1, i+1);
			scanf("%d", &TwoDimensionArrayPointer[i][j]);
		}
	}
	
	return TwoDimensionArrayPointer;
}

inline void print_array(int **TwoDimensionArrayPointer, int total_plane, int total_passanger)
{
	for (int i = 0; i < total_plane; i++)
	{
		for (int j = 0; j < total_passanger; j++) {
			printf_s("%d. Plane's %d. Passanger has ID of %d\n", i+1, j+1, TwoDimensionArrayPointer[i][j]);
		}
	}

	printf_s("%d // Before Freein\n\n", **TwoDimensionArrayPointer);
	
	free(TwoDimensionArrayPointer);
	
	printf_s("%d // Before Freeing\n\n", **TwoDimensionArrayPointer);

	TwoDimensionArrayPointer == NULL;

	printf_s("%d // After pointing to NULL\n\n", **TwoDimensionArrayPointer);


	return;
}