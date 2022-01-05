#ifndef _MATH_H
#include <math.h>
#endif // _MATH_H

#ifndef _STDLIB_H
#include <stdlib.h>
#endif // !_STDLIB_H

#ifndef _STDIO_H
#include <stdio.h>
#endif // !_STDIO_H

#ifndef _TIME_H
#include <time.h>
#endif // !_TIME_H

#define TOP_LEVEL 100

// It is a function that waits for X second where X is determined by the user.
inline void sleep_time(double second)
{
	clock_t start = clock();
	while (((double)clock() - start) / CLOCKS_PER_SEC - second)
	; // null statement
}

// It let us procude a random number every-time we compile the program.
inline void my_random() 
{
	srand((unsigned)time(NULL));
}

//Create an one-dimension array
inline int* createArrayD(int size)
{
	my_random();
	int* myArray = (int*)malloc(size * sizeof(int*));
	if (myArray == NULL)
	{
		printf("Memory could not be allocated!\n");
		exit(1);
	}
	else
	{	
		for (int i = 0; i < size; i++)
		{
			myArray[i] = rand() % TOP_LEVEL;
		}
		return myArray;
	}
}

//To print to the console an one dimension array filled with random numbers using array-decay feature.
inline void printArrayD(const int* source, int size) 
{
	for (int i = 0; i < size; i++)
	{
		printf("%d. element = %d\n", i, source[i]);
	}
}

//To print to the console an one dimension array filled with random numbers using pointer arithmatic feature.
inline void printArrayD_(const int* source, int size)
{
	while (size--)
    {
		printf("%d. index = %d\n", size, *source++);
	}
}

//Average Calculation for Single Array
inline double averageD(const int* source, int size) 
{
	printf("Inside of average Function\n");
	int counter = size;
	int counter2 = size;

	int total = 0;
	while (counter--) {
		total += *source++;
	}
	printf("Total = %d\n", total);

	double average = (double)total / size;
	printf("Average = %lf\n", average);
	return average;
}

//Standard Deviation Calculation for Single Array
inline void stdDeviationD(const float* source, int size, double average) 
{
	double sum_sqr = 0;
	for (int i = 0; i < size; i++)
	{
		sum_sqr += (source[i] - average) * (source[i] - average);
	}

	printf("Std. Devi. = %lf\n", sqrt(sum_sqr / size));

}

//Free an one-dimension array
inline void freeArrayD(int* source)
{
    free(source);
	source = NULL;
}

//Create an two-dimension array
inline int** createArrayDD(int row, int colomn)
{
    my_random();
	int** myArray = (int**)malloc(row * sizeof(int*));
	if (myArray == NULL)
	{
		printf("Memory could not be allocated!\n");
		exit(1);
	}
	else
	{
		for (int i = 0; i < row; i++)
		{
			myArray[i] = (int*)malloc(colomn * sizeof(int));
			if (myArray[i] == NULL)
			{
				printf("Memory could not be allocated!\n");
				exit(1);
			}
		}
		
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < colomn; j++)
			{
				myArray[i][j] = rand() % TOP_LEVEL;
			}
		}
		return myArray;
	}
}

//To print to the console a two dimension array filled with random numbers using pointer arithmatic feature.
inline void printArrayDD(const int** source, int row, int colomn)
{
	int counter = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < colomn; j++)
		{
			printf("%d. index = %d\n", counter, source[i][j]);
			counter++;
		}
	}
}

//Average Calculation for Double Array
inline double averageDD(const float** source, int size) 
{
	double average = 0.0;

		   for (int i = 0; i < size; i++)
		   {
			   average += source[i][1];
		   }
		   return (const double)(average/size);
}

//Standard Deviation Calculation for Double Array
inline double stdDeviationDD(const float** source, int size, const double average) 
{
	double StdDev = 0.0;
	for (int i = 0; i < size; i++)
	{
		StdDev += pow(source[i][1] - average, 2);
	}

	return sqrt(StdDev / size);
}

// Free a two-dimension array
inline void freeArrayDD(int** source, int row) 
{
	for (int i = 0; i < row; i++)
	{
		free(source[i]);
		source[i] = NULL;
	}
	free(source);
	source = NULL;
}