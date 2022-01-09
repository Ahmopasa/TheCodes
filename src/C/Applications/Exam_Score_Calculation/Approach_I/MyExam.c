#include "MyExam.h"

static void my_random() {
	srand(time(NULL));
}

static double average_score(const int* source, int size) {
	printf("Inside of arrayStdDev Function\n");
	int counter = size;

	int total = 0;
	while (counter--) {
		total += *source++;
	}
	printf("Total = %d\n", total);

	double average = (double)total / size;
	printf("Average = %lf\n", average);
	return average;
}

static void stdDeviation(const float* source, int size, double average) {
	double sum_sqr = 0;
	for (int i = 0; i < size; i++)
	{
		sum_sqr += (source[i] - average) * (source[i] - average);
	}

	printf("Std. Devi. = %lf\n", sqrt(sum_sqr / size));
}

static double averageDD(const float** source, int size) {
	double average = 0.0;

	for (int i = 0; i < size; i++)
	{
		average += source[i][1];
	}
	return (double)average / size;
}

static double stdDeviationDD(const float** source, int size, const double average) {
	double StdDev = 0.0;
	for (int i = 0; i < size; i++)
	{
		StdDev += pow(source[i][1] - average, 2);
	}

	return sqrt(StdDev / size);
}

static void arrayShowD(const int* source, int size) {
	printf("Inside of arrayShowD Function\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d. element = %d\n", i, source[i]);
	}

	/*
	while (size--) {
		printf("%d. index = %d\n", size, *source++);
	}
	*/
}

static int* createArrayD(int size) {
	my_random();
	int* myArray = (int*)malloc(size * sizeof(int));
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

static int** createArrayDD(int row, int colomn) {
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
				//myArray[i][j] = rand() % TOP_LEVEL;
				myArray[i][j] = 0;
			}
		}
		return myArray;
	}
}

static void arrayShowDD(const int** source, int row, int colomn) {
	printf("Inside of arrayShowDD Function\n");
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

static int* freeArrayD(int* source) {
	free(source);
	source = NULL;

	return source;
}

static int** freeArrayDD(int** source, int row) {
	for (int i = 0; i < row; i++)
	{
		free(source[i]);
		source[i] = NULL;
	}
	free(source);
	source = NULL;

	return source;
}

void UI_Screen(int class_size, int exam_amount) {
	my_random();
	const int raw_exam_amount = exam_amount + 2;// The extra 2 was used for Student ID and Average columns.
	int failed_students = 0;

	float** myClass = (float**)createArrayDD(class_size, raw_exam_amount);

	puts("");

	for (int i = 0; i < class_size; i++)
	{
		for (int j = 1; j < raw_exam_amount; j++)
		{
			myClass[i][0] = (float)(rand() % 2000 + 1000); //First column was used to store ID numbers.
			myClass[i][j] = (float)(rand() % 100); // columns between first and last one was used to store grades.
			myClass[i][raw_exam_amount - 1] = 0; // The last columns was used to store average scores.
		}
	}

	for (int i = 0; i < class_size; i++)
	{
		for (int j = 1; j < raw_exam_amount; j++)
		{
			myClass[i][raw_exam_amount - 1] += myClass[i][j];
		}
		myClass[i][raw_exam_amount - 1] /= 2;
		myClass[i][raw_exam_amount - 1] /= exam_amount;	 // So, the last columns will store average score.
	}
/*
	// Below, I try to change the look of output of the graph.
	printf("Student ID  ");
	for (int i = 0; i < exam_amount; i++)
	{
		printf("<Exam %d>   ", i + 1);
	}
	printf("Average");
	puts("");
	for (int i = 0; i < class_size; i++)
	{
		for (int j = 0; j < raw_exam_amount; j++)
		{
			printf("(%06.2f)   ", myClass[i][j]);
		}
		puts("");
	}
*/
	// Below, I found out scores that was less than minimum grade by looking average score columns.
	float TotalAverage = 0.0;
	int minimum_grade = 45;
	for (int i = 0; i < class_size; i++)
	{
		TotalAverage += myClass[i][raw_exam_amount - 1];
		if (myClass[i][raw_exam_amount - 1] < minimum_grade)
		{
			failed_students++;
		}
	}
	puts("");
	printf("Average at the end of the year: %f\n\nTotal Failed Students: %d\n", TotalAverage / class_size, failed_students);
	float** FailedStudents = (float**)createArrayDD(class_size, 2);	//First columns will be used to store ID and the other one for failed student's grades.
	for (int i = 0; i < class_size; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			FailedStudents[i][j] = 0.0;
		}
	}

	for (int i = 0; i < class_size; i++)
	{
		for (int j = 1; j < 2; j++)
		{
			if (myClass[i][raw_exam_amount - 1] < minimum_grade)
			{
				FailedStudents[i][0] = myClass[i][0];
				FailedStudents[i][j] = myClass[i][raw_exam_amount - 1];
			}
		}
	}

	//float** FailedStudentsV2 = (float**)createArrayDD(class_size, 2);
	for (int i = 0, m = 0, n = 0; i < class_size && m < class_size; i++)
	{
		if (FailedStudents[i][1] > 0)
		{
			FailedStudents[m][0] = FailedStudents[i][0];
			FailedStudents[n][1] = FailedStudents[i][1];
			m++;
			n++;
		}
	}
	if (failed_students == 0)
	{
		puts("No student have failed!");
	}
	else
	{
/*		printf("Student ID   Average\n");
		for (int i = 0; i < failed_students; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				printf("(%07.2f)    ", FailedStudents[i][j]);
			}
			puts("");
		} 
*/
		puts("");
		printf("Standard Deviation of Class Failed Students: %lf\n\n", stdDeviationDD(FailedStudents, failed_students, averageDD(FailedStudents, failed_students)));

		if (freeArrayDD((int**)myClass, class_size) == NULL)
		{
			if (freeArrayDD((int**)FailedStudents, class_size) == NULL)
			{
				puts("Memory is FREE!");
			}
		}
	}
}