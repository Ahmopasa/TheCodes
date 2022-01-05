#include<stdlib.h>
#include<stdio.h>

inline void value_changer(int *p)
{
    printf_s("\n\n*p: %d\n", *p);
	*p = 200;
	printf_s("*p++: %d\n", *p);
}