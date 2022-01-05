#include "LearningPointer.h"

int main() {

	int *a = (int*)malloc(5 * sizeof(int));

	for (int i = 0; i < 20; i++)
	{
		a[i] = 999 * i;
	}

	for (int i = 0; i < 20; i++)
	{
		printf_s("%d. index: %d\n", i, a[i]);
	}

	int *b = malloc(3 * sizeof(int));

	for (int i = 0; i < 12; i++)
	{
		printf_s("Please enter %d. index: ", i);
		scanf_s("%12d", &b[i]);
	}

	for (int i = 0; i < 12; i++)
	{
		printf_s("\n%d. index: %d\n", i, b[i]);

	}

	memory_changer(a, b);

	return 0;
}