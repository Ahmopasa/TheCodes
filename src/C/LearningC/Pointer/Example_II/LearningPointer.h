#include<stdlib.h>
#include<stdio.h>

inline void memory_changer(int *p, int *pp)
{
    p = (int*)realloc(p, 1 * sizeof(int));
	p[0] = 111;
	p[1] = 222;
	p[2] = 333;
	p[3] = 444;
	p[4] = 555;
	p[5] = 666;
	printf_s("After reallocating a: \n");
	for (int i = 0; i < 6; i++)
	{
		printf_s("%d. index: %d\n", i, p[i]);
	}

	pp = (int*)realloc(pp, 2*sizeof(int));
	for (int i = 0; i < 8; i++)
	{
		printf_s("Please enter new %d. index: ", i);
		scanf("%8d", &pp[i]);
	}

	for (int i = 0; i < 8; i++)
	{
		printf_s("\n%d. index: %d\n", i, pp[i]);

	}
}