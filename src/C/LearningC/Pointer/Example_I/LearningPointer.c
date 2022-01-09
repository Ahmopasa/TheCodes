#include "LearningPointer.h"

int main() {
	
	int value = 100;
	int *pointer = &value;

	printf_s("*pointer(%%d): %d\n", *pointer);
	printf_s("*pointer(%%p): %p\n", *pointer);
	printf_s("&pointer: %d\n", &pointer);
	printf_s("value: %d\n", value);
	printf_s("&value: %d\n", &value);
	
	value_changer(pointer);

	printf_s("\n\nNew *pointer(%%d): %d\n", *pointer);
	printf_s("*New pointer(%%p): %p\n", *pointer);
	printf_s("New &pointer: %d\n", &pointer);
	printf_s("New value: %d\n", value);
	printf_s("New &value: %d\n", &value);

	return 0;
}