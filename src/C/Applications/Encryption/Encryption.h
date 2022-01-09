/*
	- In that program, static array is used.
	- In English longest word has 45 char, the static array has a size of 46 char.
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

inline void *encrypter(unsigned long *first_entry_decimal, unsigned long *pointer_fibonacci_series, int lenght_string_enterd) {

	for (int i = 0; i < lenght_string_enterd; i++)
	{
		printf("%lu\n", first_entry_decimal[i]);
	}

	printf("\nThis is the version after encryption:\n");
	for (int i = 0; i < lenght_string_enterd; i++)
	{
		printf("%lu\n", pointer_fibonacci_series[first_entry_decimal[i]]);
	}

	FILE *saver_fibonacci_series;
	fopen_s(&saver_fibonacci_series, "EncryptionFile.txt", "w+");
	for (int i = 0; i < lenght_string_enterd; i++)
	{
		fprintf(saver_fibonacci_series, "%lu\n", pointer_fibonacci_series[first_entry_decimal[i]]);
	}
	fclose(saver_fibonacci_series);

	printf("File created and printed.\n");

	free(pointer_fibonacci_series);
	free(first_entry_decimal);
	pointer_fibonacci_series = NULL;
	first_entry_decimal = NULL;

	return NULL;
}