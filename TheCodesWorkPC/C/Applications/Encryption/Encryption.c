#include "Encryption.h"

int main() {

	int fibonacci_series_lenght = 128;
	unsigned long *pointer_fibonacci_series = malloc(fibonacci_series_lenght * sizeof(int));
	if (pointer_fibonacci_series == NULL) {
		printf_s("%s", "Error, occured. The memory could not be allocated.\n");
		exit(1);
	}
	unsigned long a = 0, b = 1; // first elements of fibonacci series.

	for (int i = 0; i <= fibonacci_series_lenght; i++)
	{
		if (i < 2) {
			pointer_fibonacci_series[i] = i;
		}
		else {
			pointer_fibonacci_series[i] = a + b;
			a = b;
			b = pointer_fibonacci_series[i];
		}
	}

	for (int i = 0; i < fibonacci_series_lenght; i++)
	{
		printf_s("%d. elements of the series = %lu\n", i + 1, pointer_fibonacci_series[i]);
	}


	char static_string_name[46];
	printf_s("%s", "Please, enter your string below: ");
	scanf_s("%46s", static_string_name, (unsigned)_countof(static_string_name));

	printf_s("\nThis is the version before encryption of '%s'\n", static_string_name);

	unsigned long *first_entry_decimal = malloc(5 * sizeof(unsigned long));

	for (int i = 0; i < 46; i++)
	{
		first_entry_decimal[i] = static_string_name[i];
	}

	int lenght_string_enterd = strlen(static_string_name);

	lenght_string_enterd++;

	encrypter(first_entry_decimal, pointer_fibonacci_series, lenght_string_enterd);

	return 0;
}


